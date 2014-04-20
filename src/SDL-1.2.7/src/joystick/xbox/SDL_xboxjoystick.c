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
 "@(#) $Id: SDL_xboxjoystick.c,v 1.2 2005/05/14 07:28:39 carcharius Exp $";
#endif

/* This is the system specific header for the SDL joystick API */

#include <stdio.h>
#include <memory.h>
#include <malloc.h>

#include "SDL_error.h"
#include "SDL_joystick.h"
#include "SDL_sysjoystick.h"
#include "SDL_joystick_c.h"

#include <xboxkrnl/types.h>
#include <hal/input.h>

#define MAX_PADS     1
#define NUM_AXES     4
#define NUM_HATS     1
#define NUM_BALLS    0
#define NUM_BUTTONS 12


/* The private structure used to keep track of a joystick */
struct joystick_hwdata
{
	XPAD_INPUT* pPad;
	int prevHat;
};

/* Function to scan the system for joysticks.
 * This function should set SDL_numjoysticks to the number of available
 * joysticks.  Joystick 0 should be the system default joystick.
 * It should return 0, or -1 on an unrecoverable fatal error.
 */
int SDL_SYS_JoystickInit(void)
{
	XInput_Init();

	SDL_numjoysticks = 4;

	return(SDL_numjoysticks);
}

/* Function to get the device-dependent name of a joystick */
const char *SDL_SYS_JoystickName(int index)
{
	switch(index)
	{
	case 0: return "Pad 0";
	case 1: return "Pad 1";
	case 2: return "Pad 2";
	case 3: return "Pad 3";
	default: return "Invalid joystick number";
	}
}

/* Function to open a joystick for use.
   The joystick to open is specified by the index field of the joystick.
   This should fill the nbuttons and naxes fields of the joystick structure.
   It returns 0, or -1 if there is an error.
 */
int SDL_SYS_JoystickOpen(SDL_Joystick *joystick)
{
	if(g_Pads[joystick->index].hPresent == 0)
		return -1;

	joystick->hwdata = (struct joystick_hwdata *) malloc(sizeof(*joystick->hwdata));

	joystick->hwdata->pPad = &g_Pads[joystick->index];
	joystick->hwdata->prevHat = 0;

	// LeftStickX, LeftStickY, RightStickX, RightStickY
	joystick->naxes = NUM_AXES;
	// None
	joystick->nballs = NUM_BALLS;
	// A, B, X, Y, Black, White, LeftTrigger, RightTrigger, Start, Back, LeftStick, RightStick, 
	joystick->nbuttons = NUM_BUTTONS;
	// Pad
	joystick->nhats = NUM_HATS;
	
	return(0);
}

/* Function to update the state of a joystick - called as a device poll.
 * This function shouldn't update the joystick structure directly,
 * but instead should call SDL_PrivateJoystick*() to deliver events
 * and update joystick device state.
 */
void SDL_SYS_JoystickUpdate(SDL_Joystick *joystick)
{
	int b = 0, hat = 0, hatchanged = 0;
	Sint16 nX = 0, nY = 0;
	Sint16 nXR = 0, nYR = 0;

    if( joystick->hwdata->pPad->hPresent )
    {	
		if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_START)
		{
			if (!joystick->buttons[8])
				SDL_PrivateJoystickButton(joystick, (Uint8)8, SDL_PRESSED);
		}
		else
		{
			if (joystick->buttons[8])
				SDL_PrivateJoystickButton(joystick, (Uint8)8, SDL_RELEASED);
		}

		if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_BACK)
		{
			if (!joystick->buttons[9])
				SDL_PrivateJoystickButton(joystick, (Uint8)9, SDL_PRESSED);
		}
		else
		{
			if (joystick->buttons[9])
				SDL_PrivateJoystickButton(joystick, (Uint8)9, SDL_RELEASED);
		}

		if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_LEFT_THUMB)
		{
			if (!joystick->buttons[10])
				SDL_PrivateJoystickButton(joystick, (Uint8)10, SDL_PRESSED);
		}
		else
		{
			if (joystick->buttons[10])
				SDL_PrivateJoystickButton(joystick, (Uint8)10, SDL_RELEASED);
		}

		if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_RIGHT_THUMB)
		{
			if (!joystick->buttons[11])
				SDL_PrivateJoystickButton(joystick, (Uint8)11, SDL_PRESSED);
		}
		else
		{
			if (joystick->buttons[11])
				SDL_PrivateJoystickButton(joystick, (Uint8)11, SDL_RELEASED);
		}

			

        // Get the analog buttons that have been pressed or released since
        // the last call.
        for( b=0; b<8; b++ )
        {
            // Turn the 8-bit polled value into a boolean value
            BOOL bPressed = ( joystick->hwdata->pPad->CurrentButtons.ucAnalogButtons[b] );

			if ( bPressed  ) {
				if ( !joystick->buttons[b] ) {
					SDL_PrivateJoystickButton(joystick, (Uint8)b, SDL_PRESSED);
				}
			} else {
				if ( joystick->buttons[b] ) {
					SDL_PrivateJoystickButton(joystick, (Uint8)b, SDL_RELEASED);
				}
			}


        }
	}
	// do the HATS baby

	hat = SDL_HAT_CENTERED;
	if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_DPAD_DOWN)
		hat|=SDL_HAT_DOWN;
	if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_DPAD_UP)
		hat|=SDL_HAT_UP;
	if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_DPAD_LEFT)
		hat|=SDL_HAT_LEFT;
	if (joystick->hwdata->pPad->CurrentButtons.usDigitalButtons & XPAD_DPAD_RIGHT)
		hat|=SDL_HAT_RIGHT;

	hatchanged = hat ^ joystick->hwdata->prevHat;

	if(hatchanged)
		SDL_PrivateJoystickHat(joystick, 0, hat);

	joystick->hwdata->prevHat = hat;
	
	// Axis - LStick

	if ((joystick->hwdata->pPad->sLThumbX <= -10000) || 
		(joystick->hwdata->pPad->sLThumbX >= 10000))
	{
		if (joystick->hwdata->pPad->sLThumbX < 0)
			joystick->hwdata->pPad->sLThumbX++;
		nX = ((Sint16)joystick->hwdata->pPad->sLThumbX);
	}
	else
		nX = 0;

	if ( nX != joystick->axes[0] ) 
		SDL_PrivateJoystickAxis(joystick, (Uint8)0, (Sint16)nX);

	
	if ((joystick->hwdata->pPad->sLThumbY <= -10000) || 
		(joystick->hwdata->pPad->sLThumbY >= 10000))
	{
		if (joystick->hwdata->pPad->sLThumbY < 0)
			joystick->hwdata->pPad->sLThumbY++;
		nY = -((Sint16)(joystick->hwdata->pPad->sLThumbY));
	}
	else
		nY = 0;

	if ( nY != joystick->axes[1] )
		SDL_PrivateJoystickAxis(joystick, (Uint8)1, (Sint16)nY); 


	// Axis - RStick

	if ((joystick->hwdata->pPad->sRThumbX <= -10000) || 
		(joystick->hwdata->pPad->sRThumbX >= 10000))
	{
		if (joystick->hwdata->pPad->sRThumbX < 0)
			joystick->hwdata->pPad->sRThumbX++;
		nXR = ((Sint16)joystick->hwdata->pPad->sRThumbX);
	}
	else
		nXR = 0;

	if ( nXR != joystick->axes[2] ) 
		SDL_PrivateJoystickAxis(joystick, (Uint8)2, (Sint16)nXR);

	
	if ((joystick->hwdata->pPad->sRThumbY <= -10000) || 
		(joystick->hwdata->pPad->sRThumbY >= 10000))
	{
		if (joystick->hwdata->pPad->sRThumbY < 0)
			joystick->hwdata->pPad->sRThumbY++;
		nYR = -((Sint16)joystick->hwdata->pPad->sRThumbY);
	}
	else
		nYR = 0;

	if ( nYR != joystick->axes[3] )
		SDL_PrivateJoystickAxis(joystick, (Uint8)3, (Sint16)nYR); 
}

/* Function to close a joystick after use */
void SDL_SYS_JoystickClose(SDL_Joystick *joystick)
{
	if (joystick->hwdata != NULL) {
		/* free system specific hardware data */
		free(joystick->hwdata);
	}
	return;
}

/* Function to perform any system-specific joystick related cleanup */
void SDL_SYS_JoystickQuit(void)
{
	XInput_Quit();
}
