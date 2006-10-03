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

#ifndef _SDL_xboxvideo_h
#define _SDL_xboxvideo_h

#include "SDL_mouse.h"
#include "SDL_sysvideo.h"
#include "SDL_mutex.h"

/* This is the structure we use to keep track of video memory. Taken
from SDL_fbvideo.h */
typedef struct vidmem_bucket {
	struct vidmem_bucket *prev;
	int used;
	int dirty;
	char *base;
	unsigned int size;
	struct vidmem_bucket *next;
} vidmem_bucket;

/* Hidden "this" pointer for the video functions */
#define _THIS	SDL_VideoDevice *this

#define NUM_MODELISTS 2

/* Private display data */
struct SDL_PrivateVideoData {
	/* Modelist */
	int SupportedBPP[NUM_MODELISTS];
	SDL_Rect **SDL_modelist[NUM_MODELISTS];
	/* Information for double-buffering */
	int was_flipped;
	int flip_page;
	int flip_offset[2];
	Uint8 *flip_address[2];
	/* Base pointers */
	Uint8 *VideoBase;
	Uint8 *FbBase;
	/* Video memory */
	int VideoMem;
	int FifoFreeCount;
	int FifoEmptyCount;
	/* Memory for hardware surfaces */
	vidmem_bucket surfaces;
	int surfaces_memtotal;
	int surfaces_memleft;
	SDL_mutex *hw_lock;
};

#define surfaces		(this->hidden->surfaces)
#define surfaces_memtotal	(this->hidden->surfaces_memtotal)
#define surfaces_memleft	(this->hidden->surfaces_memleft)
#define hw_lock			(this->hidden->hw_lock)
#define was_flipped             (this->hidden->was_flipped)

#endif /* _SDL_xboxvideo_h */
