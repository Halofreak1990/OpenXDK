/******************************************************************************/
// *                                                                        * //
// * Proj : GamePad Test Dev Code.                                          * //
// *                                                                        * //
// * Desc : Sample for Open Source XBox Development Kit                     * //
// *                                                                        * //
// * File : main.cpp                                                        * //
// *                                                                        * //
// * Web Home: HomePade OpenXDK: http://sourceforge.net/projects/openxdk/   * //
// *                                                                        * //
// * Author: bkenwright@xbdev.net                                           * //
// *                                                                        * //
/******************************************************************************/
/*                                                                            */    
/*                            XBOX Gamepad                                    */
/*                                                                            */
/******************************************************************************/
/*
    How does this code work?  What lib's does it need?  How would I use it
	in my code?

	Well the aim of the gamepad code was to develop an independent set of 
	code for the openxdk - but because it's lib independent it also works on
	the xdk.

	<1> Include our header file, and the other files which do all the work..
	    later they'll be put into a library
	    e.g. #include "xinput/xinput.h"   // Gamepad input
	    
	<2> Init our gamepad code
	    e.g.
		    stXINPUT xin;
		    xInitInput(&xin);
		You do this ocne at the start of the program, I did it this way as I don't
		like globals, so you need to pass it a stuct called stXINPUT which
		keeps all our usb/gampad information in.

	<3> Get our gamepad information in our main loop e.g:
		stXPAD pad;
		xGetPadInput(&pad, &xin);

	<4> When we've all finished, call xReleaseInput(&xin);

	<Misc> You can also set the rumble effect - still in development
	e.g. xSetPadInput(&pad, &xin);
*/
/******************************************************************************/

#include "xinput/xinput.h"   // Gamepad input

#include <openxdk.h>
#include <stdlib.h>
#include <stdio.h>



// Forward declaration...its at the bottom of the file.
void DataDisplay(void* data);


/******************************************************************************/
/*                                                                            */
/* WinMainCRTStartup (Entry Point)                                            */
/*                                                                            */
/******************************************************************************/
void WinMainCRTStartup()
{
    char  buffer[1024];
    //float last = (float)KeTickCount;
    //int   fps  = 0;

    RtlZeroMemory(buffer, 1024);

    // Currently, this is the only mode supported by xhal.lib
	InitMode( MODE_320x240x32 );

    // Animate up and down
    int y=25, ys=1;

    // XBox software does not typically ever return from its entry point
	stXINPUT xin;
	stXPAD pad;

	xInitInput(&xin);

	// Rumble works :)
	//xSetPadInput(&pad, &xin);

	while(true)
    {
		WaitVBlank();				// Wait for Vertical Blank
        Flip();						// Flip
		Cls();						// Clear screen

		
		// This isn't used, but I thought we could us it later on
		// to do some debugging of performace.
		static int last = (float)KeTickCount;
        int fps  = (int)(1.0f/(((float)KeTickCount - last) / 1000.0f));
        last = (float)KeTickCount;

		// Get our gamepad information
		xGetPadInput(&pad, &xin);

		DataDisplay( (void*)&pad );

		// If we press the 'A' key we'lls tart of a rumble reaction..hehe
		if( pad.keys[0] > 0xD0 )
			xSetPadInput(&pad, &xin);
			
	}

    return;
}// End WinMainCRTStartup(..)

// If you want to test the code in a debug dash setup, I'd recommend using this
// as the screen settup cause the debug dahs to crash, this will responde to
// a rumble when you press the 'A' key.

/*
void WinMainCRTStartup()
{
	stXINPUT xin;
	stXPAD pad;

	// Rumble works :)
	//xSetPadInput(&pad, &xin);
	xInitInput(&xin);

	while(true)
    {
		xGetPadInput(&pad, &xin);

		// If we press the 'A' key we'lls tart of a rumble reaction..hehe
		if( pad.keys[0] > 0xD0 )
			xSetPadInput(&pad, &xin);	
	}// End while loop

    return;
}// End WinMainCRTStartup(..)
*/



/******************************************************************************/
/*                                                                            */
/* DataDisplay(..)                                                            */
/* Small feedback function - dump our gamepad values to the screen so we can  */
/* monitor keypresses in real time.                                           */
/*                                                                            */
/******************************************************************************/
void DataDisplay(void* data)
{
	stXPAD * pPad = (stXPAD *)data;
	long xpos=15;
	long ypos=10;
	long height=12;

	char bufA[1000]; // Large temp char buffer for our text

	sprintf(bufA, "%s",  "GamePad One Information Data: bkenwright@xbdev.net");
	Print(xpos, ypos+=height, bufA);
	ypos+=5;

	//sprintf(bufA, "nothing: 0x%02X", pPad->nothing);
	//Print(bufA, xpos, ypos+=height);
	sprintf(bufA, "structsize: 0x%02X", pPad->structsize);
	Print(xpos, ypos+=height, bufA);

			
	sprintf(bufA, "pad: 0x%02X (1 up 2 down 4 left 8 right)", pPad->pad);
	Print(xpos, ypos+=height, bufA);


	for(int i=0; i<6; i++)
	{
		sprintf(bufA, "keys[%d]: 0x%01X (A B X Y Black White)", i, pPad->keys[i]);
		Print(xpos, ypos+=height, bufA);
	}// End for loop
	
	sprintf(bufA, "trig_left: 0x%02X", pPad->trig_left);
	Print(xpos, ypos+=height, bufA);

	sprintf(bufA, "trig_right: 0x%02X", pPad->trig_right);
	Print( xpos, ypos+=height, bufA);

	sprintf(bufA, "stick_left_x: 0x%02X", pPad->stick_left_x);
	Print(xpos, ypos+=height, bufA);

	sprintf(bufA, "stick_left_y: 0x%02X", pPad->stick_left_y);
	Print( xpos, ypos+=height, bufA);

	sprintf(bufA, "stick_right_x: 0x%02X", pPad->stick_right_x);
	Print(xpos, ypos+=height, bufA);

	sprintf(bufA, "stick_right_y: 0x%02X", pPad->stick_right_y);
	Print(xpos, ypos+=height, bufA);
}// End of DataDisplay(..)




