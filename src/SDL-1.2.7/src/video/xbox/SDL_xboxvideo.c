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
	
	/* Setup mode list. Modes for each depth should be sorted largest to smallest */
	/* 16bit */
	this->hidden->SDL_modelist[0][0] = malloc(sizeof(SDL_Rect));
	this->hidden->SDL_modelist[0][0]->x = this->hidden->SDL_modelist[0][0]->y = 0;
	this->hidden->SDL_modelist[0][0]->w = 720;
	this->hidden->SDL_modelist[0][0]->h = 480;
	
	this->hidden->SDL_modelist[0][1] = malloc(sizeof(SDL_Rect));
	this->hidden->SDL_modelist[0][1]->x = this->hidden->SDL_modelist[0][1]->y = 0;
	this->hidden->SDL_modelist[0][1]->w = 640;
	this->hidden->SDL_modelist[0][1]->h = 480;
	
	this->hidden->SDL_modelist[0][2] = NULL;
	/* 32bit */
	this->hidden->SDL_modelist[1][0] = malloc(sizeof(SDL_Rect));
	this->hidden->SDL_modelist[1][0]->x = this->hidden->SDL_modelist[0][0]->y = 0;
	this->hidden->SDL_modelist[1][0]->w = 720;
	this->hidden->SDL_modelist[1][0]->h = 480;
	
	this->hidden->SDL_modelist[1][1] = malloc(sizeof(SDL_Rect));
	this->hidden->SDL_modelist[1][1]->x = this->hidden->SDL_modelist[0][1]->y = 0;
	this->hidden->SDL_modelist[1][1]->w = 640;
	this->hidden->SDL_modelist[1][1]->h = 480;
	
	this->hidden->SDL_modelist[1][2] = NULL;
	
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
	if (format->BitsPerPixel == 32) { return(this->hidden->SDL_modelist[1]); }
	if (format->BitsPerPixel == 16) { return(this->hidden->SDL_modelist[0]); }
	return NULL;
}

SDL_Surface *XBOX_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags)
{
	Uint32 Rmask, Gmask, Bmask;

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
	current->pixels = XVideoGetFB();

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
	return;
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
	int i, j;
	/* Free mode lists */
	for (j = 0; j < NUM_MODELISTS; j++) {
		for (i = 0; i < SDL_NUMMODES; i++) {
			if (this->hidden->SDL_modelist[j][i] != NULL) {
				free(this->hidden->SDL_modelist[j][i]);
				this->hidden->SDL_modelist[j][i]=NULL;
			}
		}
	}
	if (this->screen && (this->screen->flags & SDL_HWSURFACE)) {
		/* Direct screen access, no memory buffer */
		this->screen->pixels = NULL;
	}
}
