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

/* XBOX SDL video driver implementation; this is just enough to make an
 *  SDL-based application THINK it's got a working video driver, for
 *  applications that call SDL_Init(SDL_INIT_VIDEO) when they don't need it,
 *  and also for use as a collection of stubs when porting SDL to a new
 *  platform for which you haven't yet written a valid video driver.
 *
 * This is also a great way to determine bottlenecks: if you think that SDL
 *  is a performance problem for a given platform, enable this driver, and
 *  then see if your application runs faster without video overhead.
 *
 * Initial work by Ryan C. Gordon (icculus@linuxgames.com). A good portion
 *  of this was cut-and-pasted from Stephane Peter's work in the AAlib
 *  SDL video driver.  Renamed to "DUMMY" by Sam Lantinga.
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

#include <hal/xbox.h>

#define XBOXVID_DRIVER_NAME "xbox"

/* Initialization/Query functions */
static int XBOX_VideoInit(_THIS, SDL_PixelFormat *vformat);
static SDL_Rect **XBOX_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags);
static SDL_Surface *XBOX_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags);
static int XBOX_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors);
static void XBOX_VideoQuit(_THIS);

/* Hardware surface functions */
static int XBOX_AllocHWSurface(_THIS, SDL_Surface *surface);
static int XBOX_LockHWSurface(_THIS, SDL_Surface *surface);
static void XBOX_UnlockHWSurface(_THIS, SDL_Surface *surface);
static void XBOX_FreeHWSurface(_THIS, SDL_Surface *surface);

/* etc. */
static void XBOX_UpdateRects(_THIS, int numrects, SDL_Rect *rects);

/* XBOX Video functions */
unsigned char* XVideoGetFB(void);
BOOL XVideoSetMode(int width, int height, int bpp, int refresh);

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
	device->CheckHWBlit = NULL;
	device->FillHWRect = NULL;
	device->SetHWColorKey = NULL;
	device->SetHWAlpha = NULL;
	device->LockHWSurface = XBOX_LockHWSurface;
	device->UnlockHWSurface = XBOX_UnlockHWSurface;
	device->FlipHWSurface = NULL;
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


int XBOX_VideoInit(_THIS, SDL_PixelFormat *vformat)
{
	XVideoSetMode(640, 480, 32, 0);
	/* Determine the screen depth (use default 8-bit depth) */
	/* we change this during the SDL_SetVideoMode implementation... */
	vformat->BitsPerPixel = 32;
	vformat->BytesPerPixel = 4;

	/* We're done! */
	return(0);
}

SDL_Rect **XBOX_ListModes(_THIS, SDL_PixelFormat *format, Uint32 flags)
{
   	 return (SDL_Rect **) -1;
}

SDL_Surface *XBOX_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags)
{
	if ( this->hidden->buffer ) {
		free( this->hidden->buffer );
	}

	this->hidden->buffer = malloc(width * height * (bpp / 8));
	if ( ! this->hidden->buffer ) {
		SDL_SetError("Couldn't allocate buffer for requested mode");
		return(NULL);
	}

/* 	printf("Setting mode %dx%d\n", width, height); */

	memset(this->hidden->buffer, 0, width * height * (bpp / 8));

	/* Allocate the new pixel format for the screen */
	if ( ! SDL_ReallocFormat(current, bpp, 0, 0, 0, 0) ) {
		free(this->hidden->buffer);
		this->hidden->buffer = NULL;
		SDL_SetError("Couldn't allocate new pixel format for requested mode");
		return(NULL);
	}

	/* Set up the new mode framebuffer */
	current->flags = flags & SDL_FULLSCREEN;
	this->hidden->w = current->w = width;
	this->hidden->h = current->h = height;
	current->pitch = current->w * (bpp / 8);
	current->pixels = this->hidden->buffer;

	/* We're done */
	return(current);
}

/* We don't actually allow hardware surfaces other than the main one */
static int XBOX_AllocHWSurface(_THIS, SDL_Surface *surface)
{
	return(-1);
}
static void XBOX_FreeHWSurface(_THIS, SDL_Surface *surface)
{
	return;
}

/* We need to wait for vertical retrace on page flipped displays */
static int XBOX_LockHWSurface(_THIS, SDL_Surface *surface)
{
	return(0);
}

static void XBOX_UnlockHWSurface(_THIS, SDL_Surface *surface)
{
	return;
}

static void XBOX_UpdateRects(_THIS, int numrects, SDL_Rect *rects)
{
	// note that this whole function assumes that the physical screen 
	// is in 640x400 mode.  The logical screen is centered in the physical 
	// screen... one of these days I will change this to use the video cards 
	// graphic modes properly! 
	int i, j, k; 
	int xinc, yinc, destinc; 
	
	unsigned char *src = NULL, *dest = NULL;
	
	int SCREEN_WIDTH = 640;       
	int SCREEN_HEIGHT = 480;   
	int SCREEN_PIXELWIDTH = 4;
	           
	// center the screen 
	unsigned char* VIDEO_BUFFER_ADDR = (unsigned char*)XVideoGetFB() + (((SCREEN_HEIGHT - this->screen->h)/2) * (SCREEN_WIDTH * SCREEN_PIXELWIDTH)) + (((SCREEN_WIDTH - this->screen->w)/2) * SCREEN_PIXELWIDTH);        
	
	// These are the values for the incoming image
	xinc = this->screen->format->BytesPerPixel ; 
	yinc = this->screen->pitch ; 
	          
	for (i = 0; i < numrects; ++ i) 
	{ 
		int x = rects[i].x; 
		int y = rects[i].y; 
		int w = rects[i].w; 
		int h = rects[i].h; 
		src = this->screen->pixels + y*yinc + x*xinc; 
		dest = (unsigned char*)VIDEO_BUFFER_ADDR; 
		destinc = SCREEN_WIDTH * SCREEN_PIXELWIDTH; 
		      
		unsigned char *ptrsrc, *ptrdst; 
		for (j = h; j > 0; --j, src += yinc, dest += destinc) 
		{ 
			ptrsrc = src; 
			ptrdst = dest; 
			for (k = w; k > 0; --k) 
			{ 
				unsigned char r, g, b;
				if (this->screen->format->BytesPerPixel == 1)
					SDL_GetRGB(*ptrsrc, this->screen->format, &r, &g, &b); 
				else if (this->screen->format->BytesPerPixel == 2)
					SDL_GetRGB(*(unsigned short *)ptrsrc, this->screen->format, &r, &g, &b); 
				else 
					SDL_GetRGB(*(unsigned int *)ptrsrc, this->screen->format, &r, &g, &b); 
				*ptrdst++ = b; 
				*ptrdst++ = g;
				*ptrdst++ = r;
				*ptrdst++ = 0; ptrsrc += xinc;
			} 
		} 
	}
}

int XBOX_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors)
{
	/* do nothing of note. */
	return(1);
}

/* Note:  If we are terminated, this could be called in the middle of
   another SDL video routine -- notably UpdateRects.
*/
void XBOX_VideoQuit(_THIS)
{
	if (this->screen->pixels != NULL)
	{
		free(this->screen->pixels);
		this->screen->pixels = NULL;
	}
}
