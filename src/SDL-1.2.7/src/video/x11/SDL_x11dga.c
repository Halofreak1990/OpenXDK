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

/* This is currently only used to enable DGA mouse.
   The new fullscreen code makes it very difficult to handle DGA dynamically.
   There will be a completely separate DGA driver that is fullscreen-only.
*/

#include <stdlib.h>		/* For getenv() */
#include "SDL_video.h"
#include "SDL_cursor_c.h"
#include "SDL_x11dga_c.h"

/* Global for the error handler */
int dga_event, dga_error = -1;

void X11_EnableDGAMouse(_THIS)
{
#ifdef XFREE86_DGAMOUSE
    int dga_major, dga_minor;
    int use_dgamouse;
    const char *env_use_dgamouse;

    /* Check configuration to see if we should use DGA mouse */
#ifdef DEFAULT_DGAMOUSE
    use_dgamouse = 1;
#else
    use_dgamouse = 0;
#endif
    env_use_dgamouse = getenv("SDL_VIDEO_X11_DGAMOUSE");
    if ( env_use_dgamouse ) {
        use_dgamouse = atoi(env_use_dgamouse);
    }
    /* Check for buggy X servers */
    if ( use_dgamouse && BUGGY_XFREE86(==, 4000) ) {
        use_dgamouse = 0;
    }
    /* Only use DGA mouse if the cursor is not showing (in relative mode) */
    if ( use_dgamouse && local_X11 && !(using_dga & DGA_MOUSE) &&
         SDL_NAME(XF86DGAQueryExtension)(SDL_Display, &dga_event, &dga_error) &&
         SDL_NAME(XF86DGAQueryVersion)(SDL_Display, &dga_major, &dga_minor) ) {
	if ( SDL_NAME(XF86DGADirectVideo)(SDL_Display, SDL_Screen, XF86DGADirectMouse) ) {
            using_dga |= DGA_MOUSE;
        }
    }
#endif /* XFREE86_DGAMOUSE */
}

/* Argh.  Glide resets DGA mouse mode when it makes the context current! */
void X11_CheckDGAMouse(_THIS)
{
#ifdef XFREE86_DGAMOUSE
    int flags;

    if ( using_dga & DGA_MOUSE ) {
        SDL_NAME(XF86DGAQueryDirectVideo)(SDL_Display, SDL_Screen, &flags);
        if ( ! (flags & XF86DGADirectMouse) ) {
                SDL_NAME(XF86DGADirectVideo)(SDL_Display,SDL_Screen,XF86DGADirectMouse);
        }
    }
#endif
}

void X11_DisableDGAMouse(_THIS)
{
#ifdef XFREE86_DGAMOUSE
    if ( using_dga & DGA_MOUSE ) {
	SDL_NAME(XF86DGADirectVideo)(SDL_Display, SDL_Screen, 0);
        using_dga &= ~DGA_MOUSE;
    }
#endif /* XFREE86_DGAMOUSE */
}
