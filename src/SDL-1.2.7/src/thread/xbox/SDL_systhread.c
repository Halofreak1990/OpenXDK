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
 "@(#) $Id: SDL_systhread.c,v 1.2 2004/10/29 00:09:14 edwardsc Exp $";
#endif

/* XBOX thread management routines for SDL */

#include <stdio.h>
#include <stdlib.h>

#include "SDL_error.h"
#include "SDL_thread.h"
#include "SDL_systhread.h"

#include <xboxkrnl/xboxkrnl.h>
#include <hal/xbox.h>

#define KILLED_HANDLE (HANDLE)-1

static void RunThreadCallback(void *data1, void *data2)
{
	SDL_RunThread(data1);
	NTSTATUS status = 0;
	PsTerminateSystemThread(status);
}

int SDL_SYS_CreateThread(SDL_Thread *thread, void *args)
{
	thread->handle = (HANDLE)XCreateThread(RunThreadCallback, args, NULL);

	if (thread->handle == (HANDLE)-1) {
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
	return ((Uint32)KeGetCurrentThread());
}

void SDL_SYS_WaitThread(SDL_Thread *thread)
{
	if (thread->handle != KILLED_HANDLE)
		NtWaitForSingleObject(thread->handle, FALSE, NULL);

	// Win32 implementation calls CloseHandle - why?
	// CloseHandle(thread->handle);
}

/* WARNING: This function is really a last resort.
 * Threads should be signaled and then exit by themselves.
 * TerminateThread() doesn't perform stack and DLL cleanup.
 */
void SDL_SYS_KillThread(SDL_Thread *thread)
{
	// we can't call PsTerminateSystemThread because it terminate the
	// *current* thread, not a specified one.  So, to try to cope with
	// this situation, we suspend the specified one and mark it as "killed"
	ULONG prevCount;
	NtSuspendThread(thread->handle, &prevCount);
	thread->handle = KILLED_HANDLE;
}
