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

/* Allow access to a raw mixing buffer */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "SDL_audio.h"
#include "SDL_mutex.h"
#include "SDL_timer.h"
#include "SDL_audio_c.h"
#include "SDL_xboxaudio.h"
#include <hal/audio.h>

/* Audio driver functions */
static int XBOX_OpenAudio(_THIS, SDL_AudioSpec *spec);
static void XBOX_CloseAudio(_THIS);
static void XBOX_LockAudio(_THIS);
static void XBOX_UnlockAudio(_THIS);

/* Audio driver bootstrap functions */

static int Audio_Available(void)
{
	return(1);
}

static void Audio_DeleteDevice(SDL_AudioDevice *device)
{
	free(device->hidden);
	free(device);
}

static SDL_AudioDevice *Audio_CreateDevice(int devindex)
{
	SDL_AudioDevice *this;

	/* Initialize all variables that we clean on shutdown */
	this = (SDL_AudioDevice *)malloc(sizeof(SDL_AudioDevice));
	if ( this ) {
		memset(this, 0, (sizeof *this));
		this->hidden = (struct SDL_PrivateAudioData *)
				malloc((sizeof *this->hidden));
	}
	if ( (this == NULL) || (this->hidden == NULL) ) {
		SDL_OutOfMemory();
		if ( this ) {
			free(this);
		}
		return(0);
	}
	memset(this->hidden, 0, (sizeof *this->hidden));

	/* Set the function pointers */
	this->OpenAudio = XBOX_OpenAudio;
	this->CloseAudio = XBOX_CloseAudio;
	this->LockAudio = XBOX_LockAudio;
	this->UnlockAudio = XBOX_UnlockAudio;

	this->free = Audio_DeleteDevice;

	return this;
}

AudioBootStrap XBOX_AudioBootstrap = {
	"xbox", "XBOX Audio Driver",
	Audio_Available, Audio_CreateDevice
};

void sdlAudioCallback(void *pac97device, void *data)
{
	SDL_AudioDevice *this = (SDL_AudioDevice *)data;

	/* If audio is quitting, don't do anything */
	if (! this->enabled)
	{
		return;
	}

	memset(this->hidden->fragments[this->hidden->nextFragment].samplesBuffer, this->spec.silence, this->hidden->fragments[this->hidden->nextFragment].sizeOfBuffer);
	if (!this->paused) 
	{
		if (this->convert.needed) 
		{
			this->spec.callback(this->spec.userdata, (Uint8 *)this->convert.buf, this->convert.len);
			SDL_ConvertAudio(&this->convert);
			memcpy(this->hidden->fragments[this->hidden->nextFragment].samplesBuffer, this->convert.buf, this->convert.len_cvt);
			this->hidden->fragments[this->hidden->nextFragment].sizeOfBuffer = this->convert.len_cvt;
		} 
		else 
		{
			this->spec.callback(this->spec.userdata, (Uint8 *)this->hidden->fragments[this->hidden->nextFragment].samplesBuffer, this->hidden->fragments[this->hidden->nextFragment].sizeOfBuffer);
		}
	}
	// now feed something to the audio chip - if we are paused, then it will be silence
	XAudioProvideSamples(this->hidden->fragments[this->hidden->nextFragment].samplesBuffer, this->hidden->fragments[this->hidden->nextFragment].sizeOfBuffer, FALSE);
	this->hidden->nextFragment = (this->hidden->nextFragment+1)%NUM_FRAGMENTS;
}

void XBOX_LockAudio(_THIS)
{
}

void XBOX_UnlockAudio(_THIS)
{
}

void XBOX_CloseAudio(_THIS)
{
	XAudioPause();
}

int XBOX_OpenAudio(_THIS, SDL_AudioSpec *spec)
{
	int i;
	
	spec->format = AUDIO_S16;
	spec->freq = 44100;
	spec->samples = 512;

	/* Update the fragment size as size in bytes */
	SDL_CalculateAudioSpec(spec);

	/* Open the audio device */
	XAudioInit(spec->format & 0xFF, spec->channels, sdlAudioCallback, (void *)this);

	/* Create the sound buffers */
	for ( i = 0; i < NUM_FRAGMENTS; ++i ) 
	{
		memset(&this->hidden->fragments[i], 0, sizeof(this->hidden->fragments[i]));
		this->hidden->fragments[i].samplesBuffer = (unsigned char *)malloc(spec->size);
		memset(this->hidden->fragments[i].samplesBuffer, spec->silence, sizeof(this->hidden->fragments[i].samplesBuffer));
		this->hidden->fragments[i].sizeOfBuffer = spec->size;

		XAudioProvideSamples(this->hidden->fragments[i].samplesBuffer, this->hidden->fragments[i].sizeOfBuffer, FALSE);
	}

	/* Ready to go! */
	this->hidden->nextFragment = 0;

	XAudioPlay();

	return(1);
}
