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
 "@(#) $Id: SDL_xboxevents.c,v 1.2 2005/05/14 07:28:39 carcharius Exp $";
#endif

/* Being a null driver, there's no event stream. We just define stubs for
   most of the API. */

#include "SDL.h"
#include "SDL_sysevents.h"
#include "SDL_events_c.h"
#include "SDL_xboxvideo.h"
#include "SDL_xboxevents_c.h"

#include <hal/input.h>
#include <hal/xbox.h>


static int lastMouseX = 0;
static int lastMouseY = 0;
static unsigned char prevMouseButtons = 0;

/* The translation table from a Xbox KB scancode to an SDL keysym */
static SDLKey DIK_keymap[256];
static SDL_keysym *TranslateKey(XKEYBOARD_STROKE scancode, SDL_keysym *keysym, int pressed);

static void keyboard_update(void);
static void mouse_update(void);


void XBOX_PumpEvents(_THIS)
{
	XInput_GetEvents();

	mouse_update();
	keyboard_update();
}

void XBOX_InitOSKeymap(_THIS)
{
	int i;

	XInput_Init();
	XSleep(200);

	lastMouseX = 0;
	lastMouseY = 0;
	prevMouseButtons = 0;

	/* Map the DIK scancodes to SDL keysyms */
	for ( i=0; i<256/*SDL_TABLESIZE(DIK_keymap)*/; i++ )
		DIK_keymap[i] = 0;

	/* Defined DIK_* constants */
	DIK_keymap[XKEY_ESCAPE] = SDLK_ESCAPE;
	DIK_keymap[XKEY_1] = SDLK_1;
	DIK_keymap[XKEY_2] = SDLK_2;
	DIK_keymap[XKEY_3] = SDLK_3;
	DIK_keymap[XKEY_4] = SDLK_4;
	DIK_keymap[XKEY_5] = SDLK_5;
	DIK_keymap[XKEY_6] = SDLK_6;
	DIK_keymap[XKEY_7] = SDLK_7;
	DIK_keymap[XKEY_8] = SDLK_8;
	DIK_keymap[XKEY_9] = SDLK_9;
	DIK_keymap[XKEY_0] = SDLK_0;
	DIK_keymap[XKEY_SUBTRACT] = SDLK_MINUS;
	DIK_keymap[XKEY_EQUALS] = SDLK_EQUALS;
	DIK_keymap[XKEY_BACKSPACE] = SDLK_BACKSPACE;
	DIK_keymap[XKEY_TAB] = SDLK_TAB;
	DIK_keymap[XKEY_Q] = SDLK_q;
	DIK_keymap[XKEY_W] = SDLK_w;
	DIK_keymap[XKEY_E] = SDLK_e;
	DIK_keymap[XKEY_R] = SDLK_r;
	DIK_keymap[XKEY_T] = SDLK_t;
	DIK_keymap[XKEY_Y] = SDLK_y;
	DIK_keymap[XKEY_U] = SDLK_u;
	DIK_keymap[XKEY_I] = SDLK_i;
	DIK_keymap[XKEY_O] = SDLK_o;
	DIK_keymap[XKEY_P] = SDLK_p;
	DIK_keymap[XKEY_LBRACE] = SDLK_LEFTBRACKET;
	DIK_keymap[XKEY_RBRACE] = SDLK_RIGHTBRACKET;
	DIK_keymap[XKEY_RETURN] = SDLK_RETURN;
	DIK_keymap[XKEY_LCONTROL] = SDLK_LCTRL;
	DIK_keymap[XKEY_A] = SDLK_a;
	DIK_keymap[XKEY_S] = SDLK_s;
	DIK_keymap[XKEY_D] = SDLK_d;
	DIK_keymap[XKEY_F] = SDLK_f;
	DIK_keymap[XKEY_G] = SDLK_g;
	DIK_keymap[XKEY_H] = SDLK_h;
	DIK_keymap[XKEY_J] = SDLK_j;
	DIK_keymap[XKEY_K] = SDLK_k;
	DIK_keymap[XKEY_L] = SDLK_l;
	DIK_keymap[XKEY_SEMICOLON] = SDLK_SEMICOLON;
	DIK_keymap[XKEY_QUOTE] = SDLK_QUOTE;
	DIK_keymap[XKEY_GRAVE] = SDLK_BACKQUOTE;
	DIK_keymap[XKEY_LSHIFT] = SDLK_LSHIFT;
	DIK_keymap[XKEY_BACKSLASH] = SDLK_BACKSLASH;
	DIK_keymap[XKEY_Z] = SDLK_z;
	DIK_keymap[XKEY_X] = SDLK_x;
	DIK_keymap[XKEY_C] = SDLK_c;
	DIK_keymap[XKEY_V] = SDLK_v;
	DIK_keymap[XKEY_B] = SDLK_b;
	DIK_keymap[XKEY_N] = SDLK_n;
	DIK_keymap[XKEY_M] = SDLK_m;
	DIK_keymap[XKEY_COMMA] = SDLK_COMMA;
	DIK_keymap[XKEY_PERIOD] = SDLK_PERIOD;
	DIK_keymap[XKEY_EQUALS] = SDLK_PLUS;
	DIK_keymap[XKEY_MINUS] = SDLK_MINUS;
	DIK_keymap[XKEY_SLASH] = SDLK_SLASH;
	DIK_keymap[XKEY_RSHIFT] = SDLK_RSHIFT;
	DIK_keymap[XKEY_MULTIPLY] = SDLK_KP_MULTIPLY;
	DIK_keymap[XKEY_LMENU] = SDLK_LALT;
	DIK_keymap[XKEY_SPACE] = SDLK_SPACE;
	DIK_keymap[XKEY_CAPSLOCK] = SDLK_CAPSLOCK;
	DIK_keymap[XKEY_F1] = SDLK_F1;
	DIK_keymap[XKEY_F2] = SDLK_F2;
	DIK_keymap[XKEY_F3] = SDLK_F3;
	DIK_keymap[XKEY_F4] = SDLK_F4;
	DIK_keymap[XKEY_F5] = SDLK_F5;
	DIK_keymap[XKEY_F6] = SDLK_F6;
	DIK_keymap[XKEY_F7] = SDLK_F7;
	DIK_keymap[XKEY_F8] = SDLK_F8;
	DIK_keymap[XKEY_F9] = SDLK_F9;
	DIK_keymap[XKEY_F10] = SDLK_F10;
	DIK_keymap[XKEY_NUMLOCK] = SDLK_NUMLOCK;
	DIK_keymap[XKEY_SCROLL_LOCK] = SDLK_SCROLLOCK;
	DIK_keymap[XKEY_NUMPAD7] = SDLK_KP7;
	DIK_keymap[XKEY_NUMPAD8] = SDLK_KP8;
	DIK_keymap[XKEY_NUMPAD9] = SDLK_KP9;
	DIK_keymap[XKEY_ADD]	   = SDLK_KP_PLUS;
	DIK_keymap[XKEY_SUBTRACT] = SDLK_KP_MINUS;
	DIK_keymap[XKEY_NUMPAD4] = SDLK_KP4;
	DIK_keymap[XKEY_NUMPAD5] = SDLK_KP5;
	DIK_keymap[XKEY_NUMPAD6] = SDLK_KP6;
	DIK_keymap[XKEY_NUMPAD1] = SDLK_KP1;
	DIK_keymap[XKEY_NUMPAD2] = SDLK_KP2;
	DIK_keymap[XKEY_NUMPAD3] = SDLK_KP3;
	DIK_keymap[XKEY_NUMPAD0] = SDLK_KP0;
	DIK_keymap[XKEY_DECIMAL] = SDLK_KP_PERIOD;
	DIK_keymap[XKEY_F11] = SDLK_F11;
	DIK_keymap[XKEY_F12] = SDLK_F12;

	DIK_keymap[XKEY_F13] = SDLK_F13;
	DIK_keymap[XKEY_F14] = SDLK_F14;
	DIK_keymap[XKEY_F15] = SDLK_F15;

	DIK_keymap[XKEY_NUMPADEQUALS] = SDLK_EQUALS;
	DIK_keymap[XKEY_RCONTROL] = SDLK_RCTRL;
	DIK_keymap[XKEY_DIVIDE] = SDLK_KP_DIVIDE;
	DIK_keymap[XKEY_RMENU] = SDLK_RALT;
	DIK_keymap[XKEY_PAUSE] = SDLK_PAUSE;
	DIK_keymap[XKEY_HOME] = SDLK_HOME;
	DIK_keymap[XKEY_UP] = SDLK_UP;
	DIK_keymap[XKEY_PRIOR] = SDLK_PAGEUP;
	DIK_keymap[XKEY_LEFT] = SDLK_LEFT;
	DIK_keymap[XKEY_RIGHT] = SDLK_RIGHT;
	DIK_keymap[XKEY_END] = SDLK_END;
	DIK_keymap[XKEY_DOWN] = SDLK_DOWN;
	DIK_keymap[XKEY_NEXT] = SDLK_PAGEDOWN;
	DIK_keymap[XKEY_INSERT] = SDLK_INSERT;
	DIK_keymap[XKEY_DELETE] = SDLK_DELETE;
	DIK_keymap[XKEY_LWIN] = SDLK_LMETA;
	DIK_keymap[XKEY_RWIN] = SDLK_RMETA;
	DIK_keymap[XKEY_APPS] = SDLK_MENU;
}

static SDL_keysym *TranslateKey(XKEYBOARD_STROKE scancode, SDL_keysym *keysym, int pressed)
{
	/* Set the keysym information */

	keysym->mod = KMOD_NONE;

	if(scancode.ucFlags & XKEYBOARD_SHIFT)
		keysym->mod |= KMOD_SHIFT;

	if(scancode.ucFlags & XKEYBOARD_CONTROL)
		keysym->mod |= KMOD_CTRL;

	if(scancode.ucFlags & XKEYBOARD_ALT)
		keysym->mod |= KMOD_ALT;

	keysym->scancode = (unsigned char)scancode.ucKeyCode;
	keysym->sym = DIK_keymap[scancode.ucKeyCode];
	keysym->unicode = scancode.ucAsciiValue;
 
	return(keysym);
}

static void keyboard_update(void)
{
	static SDL_keysym keysym;
	static XKEYBOARD_STROKE keystroke;
	
	if( 0 > XInputGetKeystroke(&keystroke) )
		return;

	if (keystroke.ucKeyCode == 0)
		return;

	if ( keystroke.ucFlags & XKEYBOARD_KEYUP ) {
		SDL_PrivateKeyboard(SDL_RELEASED, TranslateKey(keystroke,&keysym, 1));
	} else {
		SDL_PrivateKeyboard(SDL_PRESSED,  TranslateKey(keystroke,&keysym, 0));
	}
}

static void mouse_update(void)
{
	int mouseX, mouseY;
	unsigned char changed;
	XMOUSE_INPUT mouseinput = XInputGetMouseData();

	if(lastMouseX == mouseinput.cX && lastMouseY == mouseinput.cY)
	{
		mouseX = 0;
		mouseY = 0;
	}
	else
	{
		mouseX = mouseinput.cX;
		mouseY = mouseinput.cY;
	}

	if (mouseX||mouseY)
		SDL_PrivateMouseMotion(0,1, mouseX, mouseY);

	changed = mouseinput.ucButtons ^ prevMouseButtons;

	if(changed & XMOUSE_BUTTON_1)
		SDL_PrivateMouseButton( (mouseinput.ucButtons & XMOUSE_BUTTON_1) ? SDL_PRESSED : SDL_RELEASED, 1, 0, 0);

	if(changed & XMOUSE_BUTTON_2)
		SDL_PrivateMouseButton( (mouseinput.ucButtons & XMOUSE_BUTTON_2) ? SDL_PRESSED : SDL_RELEASED, 2, 0, 0);

	if(changed & XMOUSE_BUTTON_3)
		SDL_PrivateMouseButton( (mouseinput.ucButtons & XMOUSE_BUTTON_3) ? SDL_PRESSED : SDL_RELEASED, 3, 0, 0);

	if(changed & XMOUSE_BUTTON_4)
		SDL_PrivateMouseButton( (mouseinput.ucButtons & XMOUSE_BUTTON_4) ? SDL_PRESSED : SDL_RELEASED, 4, 0, 0);

	if(changed & XMOUSE_BUTTON_5)
		SDL_PrivateMouseButton( (mouseinput.ucButtons & XMOUSE_BUTTON_5) ? SDL_PRESSED : SDL_RELEASED, 5, 0, 0);


	prevMouseButtons = mouseinput.ucButtons;
	lastMouseX = mouseinput.cX;
	lastMouseY = mouseinput.cY;

}

/* end of SDL_xboxevents.c ... */

