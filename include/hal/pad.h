#ifndef HAL_PAD_H
#define HAL_PAD_H

#include <usb/ohci.h>

// values for the pad (note that they can be OR'd together
#define DPAD_UP       1
#define DPAD_DOWN     2
#define DPAD_LEFT     4
#define DPAD_RIGHT    8

// About this - at the moment it just contains the offset to the ohci memory 
// location (e.g. 0xfed00000...but we will also use this to keep track of
// alocated memory - how many gamepads are plugged in...usb dev drivers etc.
typedef struct 
{
	ohci_t my_ohci;
} XUSBControl;

/******************************************************************************/
/*                                                                            */
/* stXPAD - Gamepad Data Structure                                            */
/* This structure will be filled in by our USB Gamepad - its the data that    */
/* is returned to us when we request a gamepad in on the usb bus.             */
/*                                                                            */
/******************************************************************************/
#pragma pack(1)  // We use this, so our data is packed nice and tight!..no space.
typedef struct
{
	char reserved1;
	unsigned char structsize;
	
	char pad; /* 1 up 2 down 4 left 8 right + bitwise OR combos */
	char reserved2; 
	unsigned char keys[6]; /* A B X Y Black White */
	
	unsigned char trig_left;
	unsigned char trig_right;
	short stick_left_x;
	short stick_left_y;
	short stick_right_x;
	short stick_right_y;

	char padding[0x40];
} XPadState;
#pragma pack()

int XInitInput(XUSBControl *xcontrol);
int XGetPadCount(XUSBControl *xcontrol);
int XGetPadInput(XPadState *padState, XUSBControl *xcontrol, int padNumber);
int XSetPadInput(XPadState *padState, XUSBControl *xcontrol, int padNumber);
int XReleaseInput(XUSBControl *xcontrol);

#endif

