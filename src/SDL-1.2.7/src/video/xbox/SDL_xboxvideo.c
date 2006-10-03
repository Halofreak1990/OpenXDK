/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2004 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Sam Lantinga
    slouken@libsdl.org
*/

#ifdef SAVE_RCSID
static char rcsid =
 "@(#) $Id$";
#endif

/* 
 * XBOX SDL video driver implementation. A good portion
 * of this was cut-and-pasted from the SDL framebuffer driver
 * and the SDL DGA driver. Hardware surfaces and double buffering
 * (synchronized to vertical blank) are supported.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_video.h"
#include "SDL_mouse.h"
#include "SDL_sysvideo.h"
#include "SDL_pixels_c.h"
#include "SDL_events_c.h"

#include "SDL_xboxvideo.h"
#include "SDL_xboxevents_c.h"
#include "SDL_xboxmouse_c.h"
#include "riva_mmio.h"
#include "riva_regs.h"

#include <hal/xbox.h>
#include <hal/video.h>

#define XBOXVID_DRIVER_NAME "xbox"

/* Initialization/Query functions */
static int XBOX_VideoInit(_THIS, SDL_PixelFormat *vformat);
static SDL_Rect **XBOX_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags);
static SDL_Surface *XBOX_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags);
static int XBOX_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors);
static void XBOX_VideoQuit(_THIS);

/* Hardware surface functions */
static int XBOX_InitHWSurfaces(_THIS, SDL_Surface *screen, char *base, int size);
static void XBOX_FreeHWSurfaces(_THIS);
static int XBOX_AllocHWSurface(_THIS, SDL_Surface *surface);
static int XBOX_LockHWSurface(_THIS, SDL_Surface *surface);
static void XBOX_UnlockHWSurface(_THIS, SDL_Surface *surface);
static void XBOX_FreeHWSurface(_THIS, SDL_Surface *surface);

/* etc. */
static int XBOX_FillHWRect(_THIS, SDL_Surface *dst, SDL_Rect *rect, Uint32 color);
static int XBOX_CheckHWBlit(_THIS, SDL_Surface *src, SDL_Surface *dst);
static int XBOX_HWAccelBlit(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect);
static int XBOX_FlipHWSurface(_THIS, SDL_Surface *surface);
static void XBOX_UpdateRects(_THIS, int numrects, SDL_Rect *rects);

/* XBOX Video functions */
unsigned char* XVideoGetFB(void);
BOOL XVideoSetMode(int width, int height, int bpp, int refresh);

/* Taken from SDL_fbvideo.h */
static __inline__ void XBOX_dst_to_xy(_THIS, SDL_Surface *dst, int *x, int *y)
{
	*x = (long)(((char *)dst->pixels) - ((char *)this->hidden->FbBase))%this->screen->pitch;
	*y = (long)(((char *)dst->pixels) - ((char *)this->hidden->FbBase))/this->screen->pitch;
	if ( dst == this->screen ) {
		*x += this->offset_x;
		*y += this->offset_y;
	}
}

/* XBOX driver bootstrap functions */
static int XBOX_Available(void)
{
	// XBOX always has video available 
	return(1);
}

static void XBOX_DeleteDevice(SDL_VideoDevice *device)
{
	free(device->hidden);
	free(device);
}

static SDL_VideoDevice *XBOX_CreateDevice(int devindex)
{
	SDL_VideoDevice *device;

	/* Initialize all variables that we clean on shutdown */
	device = (SDL_VideoDevice *)malloc(sizeof(SDL_VideoDevice));
	if ( device ) {
		memset(device, 0, (sizeof *device));
		device->hidden = (struct SDL_PrivateVideoData *)malloc((sizeof *device->hidden));
	}
	if ( (device == NULL) || (device->hidden == NULL) ) {
		SDL_OutOfMemory();
		if ( device ) {
			free(device);
		}
		return(0);
	}
	memset(device->hidden, 0, (sizeof *device->hidden));

	/* Set the function pointers */
	device->VideoInit = XBOX_VideoInit;
	device->ListModes = XBOX_ListModes;
	device->SetVideoMode = XBOX_SetVideoMode;
	device->CreateYUVOverlay = NULL;
	device->SetColors = XBOX_SetColors;
	device->UpdateRects = XBOX_UpdateRects;
	device->VideoQuit = XBOX_VideoQuit;
	device->AllocHWSurface = XBOX_AllocHWSurface;
	device->CheckHWBlit = XBOX_CheckHWBlit;
	device->FillHWRect = XBOX_FillHWRect;
	device->SetHWColorKey = NULL;
	device->SetHWAlpha = NULL;
	device->LockHWSurface = XBOX_LockHWSurface;
	device->UnlockHWSurface = XBOX_UnlockHWSurface;
	device->FlipHWSurface = XBOX_FlipHWSurface;
	device->FreeHWSurface = XBOX_FreeHWSurface;
	device->SetCaption = NULL;
	device->SetIcon = NULL;
	device->IconifyWindow = NULL;
	device->GrabInput = NULL;
	device->GetWMInfo = NULL;
	device->InitOSKeymap = XBOX_InitOSKeymap;
	device->PumpEvents = XBOX_PumpEvents;

	device->free = XBOX_DeleteDevice;

	return device;
}

VideoBootStrap XBOX_bootstrap = {
	XBOXVID_DRIVER_NAME, "SDL XBOX video driver",
	XBOX_Available, XBOX_CreateDevice
};

static int VideoModeCompareSize(const void *p1, const void *p2)
{
	int diff;
	const SDL_Rect *rect1 = p1;
	const SDL_Rect *rect2 = p2;
	diff =  rect1->w - rect2->w;
	if (diff != 0) return diff;
	diff = rect1->h - rect2->h;
	return diff;
}

int XBOX_VideoInit(_THIS, SDL_PixelFormat *vformat)
{
	/* Setup supported BPP */
	this->hidden->SupportedBPP[0] = 16;
	this->hidden->SupportedBPP[0] = 32;
	
	/* Setup mode list */
	int i, bpp, noOfModes;
	void *p;
	VIDEO_MODE vm;
	for (i = 0; i < NUM_MODELISTS; i++) {
		bpp = this->hidden->SupportedBPP[i];
		p = NULL;
		// How many modes?
		noOfModes = 0;
		while (XVideoListModes(&vm, bpp, 0, &p)) {
			noOfModes++;
		}
		// Allocate space for the modelist and fill it in
		this->hidden->SDL_modelist[i] = (SDL_Rect**)malloc(sizeof(SDL_Rect*) * (noOfModes + 1));
		p = NULL;
		noOfModes = 0;
		while (XVideoListModes(&vm, bpp, 0, &p)) {
			this->hidden->SDL_modelist[i][noOfModes] = malloc(sizeof(SDL_Rect));
			this->hidden->SDL_modelist[i][noOfModes]->x = this->hidden->SDL_modelist[0][0]->y = 0;
			this->hidden->SDL_modelist[i][noOfModes]->w = vm.width;
			this->hidden->SDL_modelist[i][noOfModes]->h = vm.height;
			noOfModes++;
		}
		// Sort list from largest to smallest
		qsort(this->hidden->SDL_modelist[i], noOfModes, sizeof(SDL_Rect*), &VideoModeCompareSize);
		// Terminating entry
		this->hidden->SDL_modelist[i][noOfModes] = NULL;
	}
	
	/* Setup video base for MMIO */
	this->hidden->VideoBase = XVideoGetVideoBase();
	this->hidden->FbBase = NULL;
	
	/* Initialize empty surface list */
	surfaces.next = NULL;
	
	this->hidden->FifoFreeCount = 0;
	RivaRop *Rop = (RivaRop *)(this->hidden->VideoBase + ROP_OFFSET);
	this->hidden->FifoEmptyCount = Rop->FifoFree;
	
	/* No window manager */
	this->info.wm_available = 0;
	/* Hardware surfaces are available */
	this->info.hw_available = 1;
	this->info.video_mem = XVideoVideoMemorySize()/1024;

	/* TODO Video accleration doesn't currently work */
	#if 0
	/* Accelerated color fill */
	this->info.blit_fill = 1;
	/* Accelerated blitting */
	this->info.blit_hw = 1;
	#endif
	
	was_flipped = 0;
	
	/* Create the hardware surface lock mutex */
	hw_lock = SDL_CreateMutex();
	if ( hw_lock == NULL ) {
		SDL_SetError("Unable to create lock mutex");
		XBOX_VideoQuit(this);
		return(-1);
	}
	
	/* Initialize video mode */
	if (! XVideoSetMode(640, 480, 32, 0)) { return -1; }
	vformat->BitsPerPixel = 32;
	vformat->BytesPerPixel = 4;
	vformat->Rmask = 0x00FF0000;
	vformat->Rshift = 8;
	vformat->Rloss = 0;
	vformat->Gmask = 0x0000FF00;
	vformat->Gshift = 16;
	vformat->Gloss = 0;
	vformat->Bmask = 0x000000FF;
	vformat->Bshift = 24;
	vformat->Bloss = 0;
	vformat->Amask = 0x00000000;
	vformat->Ashift = 0;
	vformat->Aloss = 0;
	
	/* We're done! */
	return(0);
}

/*
 * Return a pointer to an array of available screen dimensions for the
 * given format, sorted largest to smallest.  Returns NULL if there are
 * no dimensions available for a particular format, or (SDL_Rect **)-1
 * if any dimension is okay for the given format.
 */
SDL_Rect **XBOX_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags)
{
	// Is BPP supported?
	int i;
	for (i = 0; i < NUM_MODELISTS; i ++) {
		if (format->BitsPerPixel == this->hidden->SupportedBPP[i]) {
			break;
		}
	}
	if (i == NUM_MODELISTS) {
		return NULL;
	} else {
		return this->hidden->SDL_modelist[i];
	}
}

SDL_Surface *XBOX_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags)
{
	Uint32 Rmask, Gmask, Bmask;
	int ScreenSize, SurfaceMemory;
	Uint8 *SurfaceBase;

	if (! XVideoSetMode(width, height, bpp, 0)) {
		SDL_SetError("Error setting video mode");
		return(NULL);
	}

/* 	printf("Setting mode %dx%d\n", width, height); */
	
	switch (bpp) {
		case 16:
			Rmask = 0xF800;
			Gmask = 0x07E0;
			Bmask = 0x001F;
			break;
		case 32:
			Rmask = 0x00FF0000;
			Gmask = 0x0000FF00;
			Bmask = 0x000000FF;
			break;
		default:
			SDL_SetError("Invalid bpp\n");
			return(NULL);
	}

	/* Allocate the new pixel format for the screen */
	if ( ! SDL_ReallocFormat(current, bpp, Rmask, Gmask, Bmask, 0) ) {
		SDL_SetError("Couldn't allocate new pixel format for requested mode");
		return(NULL);
	}

	/* Set up the new mode framebuffer */
	current->flags = SDL_FULLSCREEN | SDL_HWSURFACE;
	current->w = width;
	current->h = height;
	current->pitch = current->w * (bpp / 8);
	
	this->hidden->FbBase = XVideoGetFB();
	this->hidden->VideoMem = XVideoVideoMemorySize();
	ScreenSize = current->pitch * current->h;
	/* Set up double buffering */
	if (flags & SDL_DOUBLEBUF && ScreenSize * 2 <= this->hidden->VideoMem) {
		current->flags |= SDL_DOUBLEBUF;
		this->hidden->flip_page = 0;
		this->hidden->flip_offset[0] = 0;
		this->hidden->flip_offset[1] = ScreenSize;
		this->hidden->flip_address[0] = this->hidden->FbBase;
		this->hidden->flip_address[1] = this->hidden->flip_address[0] + ScreenSize;
	} else {
		this->hidden->flip_page = 0;
		this->hidden->flip_offset[0] = this->hidden->flip_offset[1] = 0;
		this->hidden->flip_address[0] = this->hidden->flip_address[1] = this->hidden->FbBase;
		current->pixels = this->hidden->flip_address[0];
	}
	
	/* Set up surface memory */
	XBOX_FreeHWSurfaces(this);
	if (current->flags & SDL_DOUBLEBUF) {
		SurfaceBase = this->hidden->FbBase + 2 * ScreenSize;
		SurfaceMemory = this->hidden->VideoMem - 2 * ScreenSize;
	} else {
		SurfaceBase = this->hidden->FbBase + ScreenSize;
		SurfaceMemory = this->hidden->VideoMem - ScreenSize;
	}
	XBOX_InitHWSurfaces(this, current, SurfaceBase, SurfaceMemory);
	
	if ((current->flags & SDL_DOUBLEBUF) == SDL_DOUBLEBUF) {
		this->screen = current;
		XBOX_FlipHWSurface(this, current);
		this->screen = NULL;
	}
	
	/* We're done */
	return(current);
}

/* Taken from SDL_fbvideo.c */
static int XBOX_InitHWSurfaces(_THIS, SDL_Surface *screen, char *base, int size)
{
	vidmem_bucket *bucket;

	surfaces_memtotal = size;
	surfaces_memleft = size;

	if ( surfaces_memleft > 0 ) {
		bucket = (vidmem_bucket *)malloc(sizeof(*bucket));
		if ( bucket == NULL ) {
			SDL_OutOfMemory();
			return(-1);
		}
		bucket->prev = &surfaces;
		bucket->used = 0;
		bucket->dirty = 0;
		bucket->base = base;
		bucket->size = size;
		bucket->next = NULL;
	} else {
		bucket = NULL;
	}

	surfaces.prev = NULL;
	surfaces.used = 1;
	surfaces.dirty = 0;
	surfaces.base = screen->pixels;
	surfaces.size = (unsigned int)((long)base - (long)surfaces.base);
	surfaces.next = bucket;
	screen->hwdata = (struct private_hwdata *)&surfaces;
	return(0);
}

/* Taken from SDL_fbvideo.c */
static void XBOX_FreeHWSurfaces(_THIS)
{
	vidmem_bucket *bucket, *freeable;

	bucket = surfaces.next;
	while ( bucket ) {
		freeable = bucket;
		bucket = bucket->next;
		free(freeable);
	}
	surfaces.next = NULL;
}

static void XBOX_WaitForIdle(_THIS)
{
	RivaRop *Rop = (RivaRop *)(this->hidden->VideoBase + ROP_OFFSET);
	while ( (Rop->FifoFree < this->hidden->FifoEmptyCount) ||
	        (*(this->hidden->VideoBase + PGRAPH_OFFSET + 0x00000700) & 0x01) )
		;
}

static __inline__ void XBOX_AddBusySurface(SDL_Surface *surface)
{
	((vidmem_bucket *)surface->hwdata)->dirty = 1;
}

static __inline__ int XBOX_IsSurfaceBusy(SDL_Surface *surface)
{
	return ((vidmem_bucket *)surface->hwdata)->dirty;
}

static __inline__ void XBOX_WaitBusySurfaces(_THIS)
{
	vidmem_bucket *bucket;

	/* Wait for graphic operations to complete */
	XBOX_WaitForIdle(this);

	/* Clear all surface dirty bits */
	for ( bucket=&surfaces; bucket; bucket=bucket->next ) {
		bucket->dirty = 0;
	}
}

/* Taken from SDL_fbvideo.c */
static int XBOX_AllocHWSurface(_THIS, SDL_Surface *surface)
{
	vidmem_bucket *bucket;
	int size;
	int extra;

	/* Temporarily, we only allow surfaces the same width as display.
	Some blitters require the pitch between two hardware surfaces
	to be the same.  Others have interesting alignment restrictions.
	Until someone who knows these details looks at the code...
	*/
	if ( surface->pitch > SDL_VideoSurface->pitch ) {
	SDL_SetError("Surface requested wider than screen");
	return(-1);
	}
	surface->pitch = SDL_VideoSurface->pitch;
	size = surface->h * surface->pitch;
	
	#ifdef XBOX_DEBUG
	fprintf(stderr, "Allocating bucket of %d bytes\n", size);
	#endif

	/* Quick check for available mem */
	if ( size > surfaces_memleft ) {
		SDL_SetError("Not enough video memory");
		return(-1);
	}

	/* Search for an empty bucket big enough */
	for ( bucket=&surfaces; bucket; bucket=bucket->next ) {
		if ( ! bucket->used && (size <= bucket->size) ) {
			break;
		}
	}
	if ( bucket == NULL ) {
		SDL_SetError("Video memory too fragmented");
		return(-1);
	}

	/* Create a new bucket for left-over memory */
	extra = (bucket->size - size);
	if ( extra ) {
		vidmem_bucket *newbucket;

		#ifdef XBOX_DEBUG
		fprintf(stderr, "Adding new free bucket of %d bytes\n", extra);
		#endif
		
		newbucket = (vidmem_bucket *)malloc(sizeof(*newbucket));
		if ( newbucket == NULL ) {
			SDL_OutOfMemory();
			return(-1);
		}
		newbucket->prev = bucket;
		newbucket->used = 0;
		newbucket->base = bucket->base+size;
		newbucket->size = extra;
		newbucket->next = bucket->next;
		if ( bucket->next ) {
			bucket->next->prev = newbucket;
		}
		bucket->next = newbucket;
	}

	/* Set the current bucket values and return it! */
	bucket->used = 1;
	bucket->size = size;
	bucket->dirty = 0;
	#ifdef XBOX_DEBUG
	fprintf(stderr, "Allocated %d bytes at %p\n", bucket->size, bucket->base);
	#endif
	surfaces_memleft -= size;
	surface->flags |= SDL_HWSURFACE;
	surface->pixels = bucket->base;
	surface->hwdata = (struct private_hwdata *)bucket;
	return(0);
}

/* Taken from SDL_fbvideo.c */
static void XBOX_FreeHWSurface(_THIS, SDL_Surface *surface)
{
	vidmem_bucket *bucket, *freeable;

	/* Look for the bucket in the current list */
	for ( bucket=&surfaces; bucket; bucket=bucket->next ) {
		if ( bucket == (vidmem_bucket *)surface->hwdata ) {
			break;
		}
	}
	if ( bucket && bucket->used ) {
		/* Add the memory back to the total */
		#ifdef XBOX_DEBUG
		printf("Freeing bucket of %d bytes\n", bucket->size);
		#endif
		surfaces_memleft += bucket->size;

		/* Can we merge the space with surrounding buckets? */
		bucket->used = 0;
		if ( bucket->next && ! bucket->next->used ) {
			#ifdef XBOX_DEBUG
			printf("Merging with next bucket, for %d total bytes\n", bucket->size+bucket->next->size);
			#endif
			freeable = bucket->next;
			bucket->size += bucket->next->size;
			bucket->next = bucket->next->next;
			if ( bucket->next ) {
				bucket->next->prev = bucket;
			}
			free(freeable);
		}
		if ( bucket->prev && ! bucket->prev->used ) {
			#ifdef XBOX_DEBUG
			printf("Merging with previous bucket, for %d total bytes\n", bucket->prev->size+bucket->size);
			#endif
			freeable = bucket;
			bucket->prev->size += bucket->size;
			bucket->prev->next = bucket->next;
			if ( bucket->next ) {
				bucket->next->prev = bucket->prev;
			}
			free(freeable);
		}
	}
	surface->pixels = NULL;
	surface->hwdata = NULL;
}

static __inline__ void XBOX_WaitFlip(_THIS)
{
	if ( was_flipped ) {
		XVideoWaitForVBlank();
		was_flipped = 0;
	}
}

/* We need to wait for vertical retrace on page flipped displays */
static int XBOX_LockHWSurface(_THIS, SDL_Surface *surface)
{
	if ( surface == this->screen ) {
		SDL_mutexP(hw_lock);
		if ( XBOX_IsSurfaceBusy(surface) ) {
			XBOX_WaitBusySurfaces(this);
		}
		XBOX_WaitFlip(this);
	} else {
		if ( XBOX_IsSurfaceBusy(surface) ) {
			XBOX_WaitBusySurfaces(this);
		}
	}
	return(0);
}

static void XBOX_UnlockHWSurface(_THIS, SDL_Surface *surface)
{
	if ( surface == this->screen ) {
		SDL_mutexV(hw_lock);
	}
}

static void XBOX_UpdateRects(_THIS, int numrects, SDL_Rect *rects)
{
	return;
}

int XBOX_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors)
{
	/* do nothing of note. */
	return(1);
}

/* From SDL_fbriva.c */
static int XBOX_FillHWRect(_THIS, SDL_Surface *dst, SDL_Rect *rect, Uint32 color)
{
	int dstX, dstY;
	int dstW, dstH;
	RivaBitmap *Bitmap = (RivaBitmap *)(this->hidden->VideoBase + BITMAP_OFFSET);

	if ( was_flipped && (dst == this->screen) ) {
		XVideoWaitForVBlank();
		was_flipped = 0;
	}

	/* Set up the X/Y base coordinates */
	dstW = rect->w;
	dstH = rect->h;
	XBOX_dst_to_xy(this, dst, &dstX, &dstY);

	/* Adjust for the current rectangle */
	dstX += rect->x;
	dstY += rect->y;

	RIVA_FIFO_FREE(this, Bitmap, 1);
	Bitmap->Color1A = color;

	RIVA_FIFO_FREE(this, Bitmap, 2);
	Bitmap->UnclippedRectangle[0].TopLeft     = (dstX << 16) | dstY; 
	Bitmap->UnclippedRectangle[0].WidthHeight = (dstW << 16) | dstH;


	XBOX_AddBusySurface(dst);
	return(0);
}

/* From SDL_fbriva.c */
static int XBOX_CheckHWBlit(_THIS, SDL_Surface *src, SDL_Surface *dst)
{
	int accelerated;

	/* Set initial acceleration on */
	src->flags |= SDL_HWACCEL;

	/* Set the surface attributes */
	if ( (src->flags & SDL_SRCALPHA) == SDL_SRCALPHA ||
		(src->flags & SDL_SRCCOLORKEY) == SDL_SRCCOLORKEY)
	{
		src->flags &= ~SDL_HWACCEL;
	}

	/* Check to see if final surface blit is accelerated */
	accelerated = !!(src->flags & SDL_HWACCEL);
	if ( accelerated ) {
		src->map->hw_blit = XBOX_HWAccelBlit;
	}
	return(accelerated);
}

/* From SDL_fbriva.c */
static int XBOX_HWAccelBlit(SDL_Surface *src, SDL_Rect *srcrect,
                       SDL_Surface *dst, SDL_Rect *dstrect)
{
	SDL_VideoDevice *this = current_video;
	int srcX, srcY;
	int dstX, dstY;
	int dstW, dstH;
	RivaScreenBlt *Blt = (RivaScreenBlt *)(this->hidden->VideoBase + BLT_OFFSET);

	/* FIXME: For now, only blit to display surface */
	if ( dst->pitch != SDL_VideoSurface->pitch ) {
		return(src->map->sw_blit(src, srcrect, dst, dstrect));
	}

	if ( was_flipped && (dst == this->screen) ) {
		XVideoWaitForVBlank();
		was_flipped = 0;
	}

	/* Calculate source and destination base coordinates (in pixels) */
	dstW = dstrect->w;
	dstH = dstrect->h;
	XBOX_dst_to_xy(this, src, &srcX, &srcY);
	XBOX_dst_to_xy(this, dst, &dstX, &dstY);

	/* Adjust for the current blit rectangles */
	srcX += srcrect->x;
	srcY += srcrect->y;
	dstX += dstrect->x;
	dstY += dstrect->y;

	RIVA_FIFO_FREE(this, Blt, 3);
	Blt->TopLeftSrc  = (srcY << 16) | srcX;
	Blt->TopLeftDst  = (dstY << 16) | dstX;
	Blt->WidthHeight = (dstH  << 16) | dstW;

	XBOX_AddBusySurface(src);
	XBOX_AddBusySurface(dst);

	return(0);
}

int XBOX_FlipHWSurface(_THIS, SDL_Surface *surface)
{
	if ( XBOX_IsSurfaceBusy(this->screen) ) {
		XBOX_WaitBusySurfaces(this);
	}
	XBOX_WaitFlip(this);
	XVideoSetDisplayStart(this->hidden->flip_offset[this->hidden->flip_page]);
	was_flipped = 1;
	this->hidden->flip_page=(this->hidden->flip_page + 1) % 2;
	surface->pixels=this->hidden->flip_address[this->hidden->flip_page];
	return(0);
}

/* Note:  If we are terminated, this could be called in the middle of
   another SDL video routine -- notably UpdateRects.
*/
void XBOX_VideoQuit(_THIS)
{
	int i;
	SDL_Rect **p;
	/* Free mode lists */
	for (i = 0; i < NUM_MODELISTS; i++) {
		p = this->hidden->SDL_modelist[i];
		while (*p) {
			free(*p++);
		}
		free(this->hidden->SDL_modelist[i]);
		this->hidden->SDL_modelist[i] = NULL;
	}
	if (this->screen && (this->screen->flags & SDL_HWSURFACE)) {
		/* Direct screen access, no memory buffer */
		this->screen->pixels = NULL;
	}
	
	/* Clean up the memory bucket list */
	XBOX_FreeHWSurfaces(this);
	
	/* Clear the lock mutex */
	if ( hw_lock != NULL ) {
		SDL_DestroyMutex(hw_lock);
		hw_lock = NULL;
	}
	
	XVideoSetDisplayStart(0);
}
