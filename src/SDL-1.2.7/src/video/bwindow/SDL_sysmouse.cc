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

#include <stdlib.h>
#include <string.h>

#include <AppKit.h>
#include <GameKit.h>

#include "SDL_error.h"
#include "SDL_BWin.h"

extern "C" {

#include "SDL_sysmouse_c.h"

/* Convert bits to padded bytes */
#define PADDED_BITS(bits)  ((bits+7)/8)

/* The implementation dependent data for the window manager cursor */
struct WMcursor {
	char *bits;
};

/* Can this be done in the BeOS? */
WMcursor *BE_CreateWMCursor(_THIS,
		Uint8 *data, Uint8 *mask, int w, int h, int hot_x, int hot_y)
{
	WMcursor *cursor;
	int allowed_x;
	int allowed_y;
	int run, pad, i;
	char *cptr;

	allowed_x = 16;	/* BeOS limitation */
	allowed_y = 16;	/* BeOS limitation */
	if ( (w > allowed_x) || (h > allowed_y) ) {
		SDL_SetError("Only cursors of dimension (%dx%d) are allowed",
							allowed_x, allowed_y);
		return(NULL);
	}

	/* Allocate the cursor */
	cursor = (WMcursor *)malloc(sizeof(WMcursor));
	if ( cursor == NULL ) {
		SDL_OutOfMemory();
		return(NULL);
	}
	cursor->bits = (char *)malloc(4+2*((allowed_x/8)*allowed_y));
	if ( cursor->bits == NULL ) {
		free(cursor);
		SDL_OutOfMemory();
		return(NULL);
	}
	cursor->bits[0] = allowed_y;		/* Size of the cursor */
	cursor->bits[1] = 1;			/* Bit depth of cursor */
	cursor->bits[2] = hot_y;
	cursor->bits[3] = hot_x;
	cptr = &cursor->bits[4];

	/* Pad out to the normal cursor size */
	run = PADDED_BITS(w);
	pad = PADDED_BITS(allowed_x)-run;
	for ( i=0; i<h; ++i ) {
		memcpy(cptr, data, run);
		memset(cptr+run, 0, pad);
		data += run;
		cptr += (run+pad);
	}
	for ( ; i<allowed_y; ++i ) {
		memset(cptr, 0, run+pad);
		cptr += (run+pad);
	}
	for ( i=0; i<h; ++i ) {
		/* FIXME: The mask should be OR'd with the data to turn 
		   inverted color pixels black, since inverted color pixels
		   aren't supported under BeOS.
		 */
		memcpy(cptr, mask, run);
		memset(cptr+run, 0, pad);
		mask += run;
		cptr += (run+pad);
	}
	for ( ; i<allowed_y; ++i ) {
		memset(cptr, 0, run+pad);
		cptr += (run+pad);
	}
	return(cursor);
}

int BE_ShowWMCursor(_THIS, WMcursor *cursor)
{
	if ( be_app->Lock() ) {
		if ( cursor == NULL ) {
			if ( SDL_BlankCursor != NULL ) {
				be_app->SetCursor(SDL_BlankCursor->bits);
			}
		} else {
			be_app->SetCursor(cursor->bits);
		}
		be_app->Unlock();
	}
	return(1);
}

void BE_FreeWMCursor(_THIS, WMcursor *cursor)
{
	free(cursor->bits);
	free(cursor);
}

/* Implementation by Christian Bauer <cbauer@student.physik.uni-mainz.de> */
void BE_WarpWMCursor(_THIS, Uint16 x, Uint16 y)
{
	BPoint pt(x, y);
	SDL_Win->Lock();
	SDL_Win->ConvertToScreen(&pt);
	SDL_Win->Unlock();
	set_mouse_position((int32)pt.x, (int32)pt.y);
}

}; /* Extern C */
