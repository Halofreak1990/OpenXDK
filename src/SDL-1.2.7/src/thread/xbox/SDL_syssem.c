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

/* An implementation of semaphores using mutexes and condition variables */

#include <stdlib.h>

#include "SDL_error.h"
#include "SDL_timer.h"
#include "SDL_thread.h"
#include "SDL_systhread_c.h"

#include <xboxkrnl/xboxkrnl.h>

#define WAIT_OBJECT_0 0x00000000
#define INFINITE      0x7FFFFFFF

struct SDL_semaphore
{
	HANDLE id;
	Uint32 volatile count;
};

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value)
{
	SDL_sem *sem;

	sem = (SDL_sem *)malloc(sizeof(*sem));
	if (! sem ) {
		SDL_OutOfMemory();
		return(0);
	}

	NTSTATUS status = NtCreateSemaphore(&sem->id, NULL, initial_value, 32*1024 );

	sem->count = initial_value;
	
	if ( ! sem->id ) {
		SDL_SetError("Couldn't create semaphore");
		free(sem);
		sem = NULL;
	}

	return(sem);
}

/* WARNING:
   You cannot call this function when another thread is using the semaphore.
*/
void SDL_DestroySemaphore(SDL_sem *sem)
{
	if ( sem ) {
		if ( sem->id ) {
			NtClose(sem->id);
			sem->id = 0;
		}
		free(sem);
	}
}



int SDL_SemTryWait(SDL_sem *sem)
{
	return SDL_SemWaitTimeout(sem, 0);
}

int SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout)
{
	int retval;
	LARGE_INTEGER tmp, *milliseconds;

	if ( ! sem ) {
		SDL_SetError("Passed a NULL sem");
		return -1;
	}

	if ( timeout == SDL_MUTEX_MAXWAIT ) {
		milliseconds = NULL;
	} else {
		tmp.QuadPart = timeout;
		milliseconds = &tmp;
	}
	
	switch (NtWaitForSingleObject(sem->id, FALSE, milliseconds)) 
	{
    case WAIT_OBJECT_0:
			--sem->count;
			retval = 0;
			break;
    case WAIT_TIMEOUT:
			retval = SDL_MUTEX_TIMEDOUT;
			break;
    default:
			SDL_SetError("WaitForSingleObject() failed");
			retval = -1;
			break;
	}
	
	return retval;
}

int SDL_SemWait(SDL_sem *sem)
{
	return SDL_SemWaitTimeout(sem, SDL_MUTEX_MAXWAIT);
}

Uint32 SDL_SemValue(SDL_sem *sem)
{
	if ( ! sem ) {
		SDL_SetError("Passed a NULL sem");
		return 0;
	}
	return sem->count;
}

int SDL_SemPost(SDL_sem *sem)
{
	if ( ! sem ) {
		SDL_SetError("Passed a NULL sem");
		return -1;
	}

	/* Increase the counter in the first place, because
	 * after a successful release the semaphore may
	 * immediately get destroyed by another thread which
	 * is waiting for this semaphore.
	 */
	++sem->count;

	NTSTATUS status = NtReleaseSemaphore(sem->id, 1, NULL);
	if (!NT_SUCCESS(status))
	{
		--sem->count;	/* restore */
		SDL_SetError("ReleaseSemaphore() failed");
		return -1;
	}
	return 0;
}
