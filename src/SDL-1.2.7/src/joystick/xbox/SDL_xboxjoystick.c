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

/* This is the system specific header for the SDL joystick API */

#include <stdio.h>
#include <memory.h>

#include "SDL_error.h"
#include "SDL_joystick.h"
#include "SDL_sysjoystick.h"
#include "SDL_joystick_c.h"
#include <hal/pad.h>

#define MAX_PADS     1
#define NUM_AXES     4
#define NUM_HATS     1
#define NUM_BALLS    0
#define NUM_BUTTONS 12

#define LEFT_X_AXIS   0
#define LEFT_Y_AXIS   1
#define RIGHT_X_AXIS  2
#define RIGHT_Y_AXIS  3

#define PRESS_THRESHOLD 0x10

XUSBControl xcontrol;
XPadState previousStates[MAX_PADS];
/* Function to scan the system for joysticks.
 * This function should set SDL_numjoysticks to the number of available
 * joysticks.  Joystick 0 should be the system default joystick.
 * It should return 0, or -1 on an unrecoverable fatal error.
 */
int SDL_SYS_JoystickInit(void)
{
	int i;
	XInitInput(&xcontrol);
	for (i = 0; i < MAX_PADS; i++)
	{
		memset(&previousStates[i], 0, sizeof(XPadState));
	}
	return XGetPadCount(&xcontrol);
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
	// LeftStickX, LeftStickY, RightStickX, RightStickY
	joystick->naxes = NUM_AXES;
	// None
	joystick->nballs = NUM_BALLS;
	// A, B, X, Y, Black, White, LeftTrigger, RightTrigger, Start, Back, LeftStick, RightStick, 
	joystick->nbuttons = NUM_BUTTONS;
	// Pad
	joystick->nhats = NUM_HATS;
	
	memset(&previousStates[joystick->index], 0, sizeof(XPadState));
	return(0);
}

/* Function to update the state of a joystick - called as a device poll.
 * This function shouldn't update the joystick structure directly,
 * but instead should call SDL_PrivateJoystick*() to deliver events
 * and update joystick device state.
 */
void SDL_SYS_JoystickUpdate(SDL_Joystick *joystick)
{
	XPadState *previous = &previousStates[joystick->index];
	
	XPadState pad;
	int xx = times(NULL);
	XGetPadInput(&pad, &xcontrol, joystick->index);
	
//	if (pad.stick_left_x != previous->stick_left_x)
//		SDL_PrivateJoystickAxis(joystick, LEFT_X_AXIS, pad.stick_left_x);
//	if (pad.stick_left_y != previous->stick_left_y)
//		SDL_PrivateJoystickAxis(joystick, LEFT_Y_AXIS, pad.stick_left_y);
//	if (pad.stick_right_x != previous->stick_right_x)
//		SDL_PrivateJoystickAxis(joystick, RIGHT_X_AXIS, pad.stick_right_x);
//	if (pad.stick_right_y != previous->stick_right_y)
//		SDL_PrivateJoystickAxis(joystick, RIGHT_Y_AXIS, pad.stick_right_y);

	int i;
	for (i = 0; i < 6; i++)
	{
		pad.keys[i] = (pad.keys[i] > PRESS_THRESHOLD ? 1 : 0);
		if (pad.keys[i] != previous->keys[i])
		{
			if (pad.keys[i] == 1)
			{
				SDL_PrivateJoystickButton(joystick, i, SDL_PRESSED);
			}
			else
			{
				SDL_PrivateJoystickButton(joystick, i, SDL_RELEASED);
			}
		}
	}
	pad.trig_left = (pad.trig_left > PRESS_THRESHOLD ? 1 : 0);
	if (pad.trig_left != previous->trig_left)
	{
		if (pad.trig_left == 1)
		{
			SDL_PrivateJoystickButton(joystick, 6, SDL_PRESSED);
		}
		else
		{
			SDL_PrivateJoystickButton(joystick, 6, SDL_RELEASED);
		}
	}

	pad.trig_right = (pad.trig_right > PRESS_THRESHOLD ? 1 : 0);
	if (pad.trig_right != previous->trig_right)
	{
		if (pad.trig_right == 1)
		{
			SDL_PrivateJoystickButton(joystick, 7, SDL_PRESSED);
		}
		else
		{
			SDL_PrivateJoystickButton(joystick, 7, SDL_RELEASED);
		}
	}

	// 8 - start button
	// 9 - back button
	// 10 - left stick press
	// 11 - right stick press

	int hat = SDL_HAT_CENTERED;
	if (pad.pad & DPAD_DOWN)
		hat |= SDL_HAT_DOWN;
	if (pad.pad & DPAD_UP)
		hat |= SDL_HAT_UP;
	if (pad.pad & DPAD_LEFT)
		hat |= SDL_HAT_LEFT;
	if (pad.pad & DPAD_RIGHT)
		hat |= SDL_HAT_RIGHT;
	pad.pad = hat;

	if (pad.pad != previous->pad)
	{
		SDL_PrivateJoystickHat(joystick, 0, pad.pad);
	}

	memcpy(previous, &pad, sizeof(pad));
}

/* Function to close a joystick after use */
void SDL_SYS_JoystickClose(SDL_Joystick *joystick)
{
	return;
}

/* Function to perform any system-specific joystick related cleanup */
void SDL_SYS_JoystickQuit(void)
{
	XReleaseInput(&xcontrol);
}
