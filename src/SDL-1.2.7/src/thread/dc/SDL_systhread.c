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

    BERO
    bero@geocities.co.jp

    based on generic/SDL_thread.c

    Sam Lantinga
    slouken@libsdl.org
*/

#ifdef SAVE_RCSID
static char rcsid =
 "@(#) $Id$";
#endif

/* Thread management routines for SDL */

#include "SDL_error.h"
#include "SDL_thread.h"
#include "SDL_systhread.h"

#include <kos/thread.h>

#ifdef	DISABLE_THREADS
int SDL_SYS_CreateThread(SDL_Thread *thread, void *args)
{
	SDL_SetError("Threads are not supported on this platform");
	return(-1);
}

void SDL_SYS_SetupThread(void)
{
	return;
}

Uint32 SDL_ThreadID(void)
{
	return(0);
}

void SDL_SYS_WaitThread(SDL_Thread *thread)
{
	return;
}

void SDL_SYS_KillThread(SDL_Thread *thread)
{
	return;
}

#else
int SDL_SYS_CreateThread(SDL_Thread *thread, void *args)
{
	thread->handle = thd_create(SDL_RunThread,args);
	if (thread->handle == NULL) {
		SDL_SetError("Not enough resources to create thread");
		return(-1);
	}
	return(0);
}

void SDL_SYS_SetupThread(void)
{
	return;
}

Uint32 SDL_ThreadID(void)
{
	return (Uint32)thd_get_current();
}

void SDL_SYS_WaitThread(SDL_Thread *thread)
{
	thd_wait(thread->handle);
}

void SDL_SYS_KillThread(SDL_Thread *thread)
{
	thd_destroy(thread->handle);
}
#endif
