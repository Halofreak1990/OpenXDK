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

#include "SDL_sysvideo.h"

/* Useful functions and variables from SDL_sysevents.c */

#ifdef __BEOS__		/* The Be event loop runs in a separate thread */
#define MUST_THREAD_EVENTS
#endif

#ifdef WIN32		/* Win32 doesn't allow a separate event thread */
#define CANT_THREAD_EVENTS
#endif

#ifdef macintosh	/* MacOS 7/8 don't support preemptive multi-tasking */
#define CANT_THREAD_EVENTS
#endif
