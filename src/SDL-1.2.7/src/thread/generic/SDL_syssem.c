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


#ifdef DISABLE_THREADS

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value)
{
	SDL_SetError("SDL not configured with thread support");
	return (SDL_sem *)0;
}

void SDL_DestroySemaphore(SDL_sem *sem)
{
	return;
}

int SDL_SemTryWait(SDL_sem *sem)
{
	SDL_SetError("SDL not configured with thread support");
	return -1;
}

int SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout)
{
	SDL_SetError("SDL not configured with thread support");
	return -1;
}

int SDL_SemWait(SDL_sem *sem)
{
	SDL_SetError("SDL not configured with thread support");
	return -1;
}

Uint32 SDL_SemValue(SDL_sem *sem)
{
	return 0;
}

int SDL_SemPost(SDL_sem *sem)
{
	SDL_SetError("SDL not configured with thread support");
	return -1;
}

#else

struct SDL_semaphore
{
	Uint32 count;
	Uint32 waiters_count;
	SDL_mutex *count_lock;
	SDL_cond *count_nonzero;
};

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value)
{
	SDL_sem *sem;

	sem = (SDL_sem *)malloc(sizeof(*sem));
	if ( ! sem ) {
		SDL_OutOfMemory();
		return(0);
	}
	sem->count = initial_value;
	sem->waiters_count = 0;

	sem->count_lock = SDL_CreateMutex();
	sem->count_nonzero = SDL_CreateCond();
	if ( ! sem->count_lock || ! sem->count_nonzero ) {
		SDL_DestroySemaphore(sem);
		return(0);
	}

	return(sem);
}

/* WARNING:
   You cannot call this function when another thread is using the semaphore.
*/
void SDL_DestroySemaphore(SDL_sem *sem)
{
	if ( sem ) {
		sem->count = 0xFFFFFFFF;
		while ( sem->waiters_count > 0) {
			SDL_CondSignal(sem->count_nonzero);
			SDL_Delay(10);
		}
		SDL_DestroyCond(sem->count_nonzero);
		SDL_mutexP(sem->count_lock);
		SDL_mutexV(sem->count_lock);
		SDL_DestroyMutex(sem->count_lock);
		free(sem);
	}
}

int SDL_SemTryWait(SDL_sem *sem)
{
	int retval;

	if ( ! sem ) {
		SDL_SetError("Passed a NULL semaphore");
		return -1;
	}

	retval = SDL_MUTEX_TIMEDOUT;
	SDL_LockMutex(sem->count_lock);
	if ( sem->count > 0 ) {
		--sem->count;
		retval = 0;
	}
	SDL_UnlockMutex(sem->count_lock);

	return retval;
}

int SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout)
{
	int retval;

	if ( ! sem ) {
		SDL_SetError("Passed a NULL semaphore");
		return -1;
	}

	/* A timeout of 0 is an easy case */
	if ( timeout == 0 ) {
		return SDL_SemTryWait(sem);
	}

	SDL_LockMutex(sem->count_lock);
	++sem->waiters_count;
	retval = 0;
	while ( (sem->count == 0) && (retval != SDL_MUTEX_TIMEDOUT) ) {
		retval = SDL_CondWaitTimeout(sem->count_nonzero,
		                             sem->count_lock, timeout);
	}
	--sem->waiters_count;
	--sem->count;
	SDL_UnlockMutex(sem->count_lock);

	return retval;
}

int SDL_SemWait(SDL_sem *sem)
{
	return SDL_SemWaitTimeout(sem, SDL_MUTEX_MAXWAIT);
}

Uint32 SDL_SemValue(SDL_sem *sem)
{
	Uint32 value;
	
	value = 0;
	if ( sem ) {
		SDL_LockMutex(sem->count_lock);
		value = sem->count;
		SDL_UnlockMutex(sem->count_lock);
	}
	return value;
}

int SDL_SemPost(SDL_sem *sem)
{
	if ( ! sem ) {
		SDL_SetError("Passed a NULL semaphore");
		return -1;
	}

	SDL_LockMutex(sem->count_lock);
	if ( sem->waiters_count > 0 ) {
		SDL_CondSignal(sem->count_nonzero);
	}
	++sem->count;
	SDL_UnlockMutex(sem->count_lock);

	return 0;
}

#endif /* DISABLE_THREADS */
