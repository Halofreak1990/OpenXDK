#include <openxdk/openxdk.h>
#include <hal/io.h>
#include <hal/input.h>
#include <memory.h>

#define XPAD_ANALOG_BUTTON_INTF 0x30

XPAD_INPUT		g_Pads[4];
XPAD_INPUT		g_DefaultPad;

XMOUSE_INPUT	g_Mouse;

/* Has input been inited already? */
BOOL bInputOK = FALSE;
BOOL bInputPolling = FALSE;

/* Stores time and XPAD state */
extern struct xpad_data XPAD_current[4];
extern struct xpad_data XPAD_last[4];

/* Stores Mouse state */
extern struct xmouse_data XMOUSE_current;

void BootStartUSB(void);
void USBGetEvents(void);
void BootStopUSB(void);

int GetKeyboardStroke(XKEYBOARD_STROKE *pStroke);

// the IDT consists of 256 of these guys. They
// hold the information that tells the CPU where
// to jump to when an interrupt occurs
typedef struct 
{
	unsigned short lowOffset;
	unsigned short selector;
	unsigned short type;
	unsigned short highOffset;
} idtDescriptor;

// fetches the current address of the IDT table
// so that we can hook the audio interrupt later
unsigned long getIDTAddress();

// declare our asm interrupt handler (see usbInterrupt.s)
extern void IntHandler1(void);

void XUSBInterrupt(void)
{
	USBGetEvents();
}

void XInput_Init(void)
{
	int i;

	if(bInputOK) {
		return;
	}
	bInputOK = TRUE;
	bInputPolling = FALSE;

	// Zero our pad structures
	for(i=0; i<4; i++)
		memset(&g_Pads[i], 0x00, sizeof(XPAD_INPUT));

	// Zero the mouse data
	memset(&g_Mouse, 0x00, sizeof(XMOUSE_INPUT));

	// Hook the usb interrupt
	{
		// now we need to hook our interrupt handler.
		idtDescriptor *idt = (idtDescriptor *)getIDTAddress();
		unsigned short selector;
		asm volatile("movw %%cs,%0" :"=g"(selector));

		// our interrupt handler is a pointer to our asm routine
		unsigned int interruptRoutine = (unsigned int)IntHandler1;
		// found this interrupt number through trial and error.  ick!
		int intNum = 0x31;
		idt[intNum].selector   = selector;
		idt[intNum].type       = 0x8e00; 
		idt[intNum].lowOffset  = (unsigned short)interruptRoutine;
		idt[intNum].highOffset = (unsigned short)(((unsigned int)interruptRoutine)>>16);

		// and lastly, lets enable the interrupt on the PIC
		IoOutputByte(0x21,(IoInputByte(0x21) & 0xFD));
	}

	// Startup the cromwell usb code
	BootStartUSB();

	// Get the current state of our devices
	XInput_GetEvents();

}

void XInput_Init_Polling(void)
{
	int i;

	if(bInputOK) {
		return;
	}
	bInputOK = TRUE;
	bInputPolling = TRUE;
	
	// Zero our pad structures
	for(i=0; i<4; i++)
		memset(&g_Pads[i], 0x00, sizeof(XPAD_INPUT));

	// Zero the mouse data
	memset(&g_Mouse, 0x00, sizeof(XMOUSE_INPUT));

	// Startup the cromwell usb code
	BootStartUSB();

	// Get the current state of our devices
	XInput_GetEvents();
}

void XInput_Quit(void)
{
	if(!bInputOK)
		return;

	int i;

	// Stop the cromwell usb code
	BootStopUSB();

	// Zero our pad structures
	for(i=0; i<4; i++)
		memset(&g_Pads[i], 0x00, sizeof(XPAD_INPUT));

	// Zero the mouse data
	memset(&g_Mouse, 0x00, sizeof(XMOUSE_INPUT));

	bInputOK = FALSE;
}

void XInput_GetEvents(void)
{
	int pad, button;
	int iLThumbX, iLThumbY, iRThumbX, iRThumbY;
	if (bInputPolling) {
		XUSBInterrupt();
	}

	for(pad=0; pad<4; pad++)
	{
		g_Pads[pad].hPresent = XPAD_current[pad].hPresent;

		if(!g_Pads[pad].hPresent)
		{
			memset(&g_Pads[pad], 0x00, sizeof(XPAD_INPUT));
			continue;
		}

		// Digital buttons - dpad (up, down, left, right), start, back, left thumb, right thumb
		g_Pads[pad].CurrentButtons.usDigitalButtons	= XPAD_current[pad].pad | (XPAD_current[pad].state << 4);

		// Analog buttons
		g_Pads[pad].CurrentButtons.ucAnalogButtons[0]	
			= (XPAD_current[pad].keys[0] > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].keys[0] : 0;		// A
		g_Pads[pad].CurrentButtons.ucAnalogButtons[1]	
			= (XPAD_current[pad].keys[1] > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].keys[1] : 0;		// B
		g_Pads[pad].CurrentButtons.ucAnalogButtons[2]	
			= (XPAD_current[pad].keys[2] > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].keys[2] : 0;		// X
		g_Pads[pad].CurrentButtons.ucAnalogButtons[3]	
			= (XPAD_current[pad].keys[3] > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].keys[3] : 0;		// Y
		g_Pads[pad].CurrentButtons.ucAnalogButtons[4]	
			= (XPAD_current[pad].keys[4] > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].keys[4] : 0;		// Black
		g_Pads[pad].CurrentButtons.ucAnalogButtons[5]	
			= (XPAD_current[pad].keys[5] > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].keys[5] : 0;		// White


		g_Pads[pad].CurrentButtons.ucAnalogButtons[6]	
			= (XPAD_current[pad].trig_left > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].trig_left : 0;	// Left trigger
		g_Pads[pad].CurrentButtons.ucAnalogButtons[7]	
			= (XPAD_current[pad].trig_right > XPAD_ANALOG_BUTTON_INTF) ? XPAD_current[pad].trig_right : 0;	// Right trigger

		// Thumbsticks
		g_Pads[pad].sLThumbX			= XPAD_current[pad].stick_left_x;		// Left stick X
		g_Pads[pad].sLThumbY			= XPAD_current[pad].stick_left_y;		// Left stick Y
		g_Pads[pad].sRThumbX			= XPAD_current[pad].stick_right_x;		// Right stick X
		g_Pads[pad].sRThumbY			= XPAD_current[pad].stick_right_y;		// Right stick Y


		// Track changes for buttons
		g_Pads[pad].PressedButtons.usDigitalButtons =  
			g_Pads[pad].CurrentButtons.usDigitalButtons & (g_Pads[pad].LastButtons.usDigitalButtons ^ g_Pads[pad].CurrentButtons.usDigitalButtons);

		g_Pads[pad].LastButtons.usDigitalButtons =  g_Pads[pad].CurrentButtons.usDigitalButtons;

		for(button=0; button<8; button++)
		{
			g_Pads[pad].PressedButtons.ucAnalogButtons[button] = 
				(g_Pads[pad].CurrentButtons.ucAnalogButtons[button] > XPAD_ANALOG_BUTTON_INTF) & 
				(g_Pads[pad].LastButtons.ucAnalogButtons[button] ^ 
				(g_Pads[pad].CurrentButtons.ucAnalogButtons[button] > XPAD_ANALOG_BUTTON_INTF));

			g_Pads[pad].LastButtons.ucAnalogButtons[button] = (g_Pads[pad].CurrentButtons.ucAnalogButtons[button] > XPAD_ANALOG_BUTTON_INTF);
		}
	}

	//Fill combination gamepad
	memset(&g_DefaultPad, 0x00, sizeof(XPAD_INPUT));

	iLThumbX = iLThumbY = iRThumbX = iRThumbY = 0;

	for(pad=0; pad<4; pad++)
	{
		g_DefaultPad.CurrentButtons.usDigitalButtons |= g_Pads[pad].CurrentButtons.usDigitalButtons;
		g_DefaultPad.LastButtons.usDigitalButtons |= g_Pads[pad].LastButtons.usDigitalButtons;
		g_DefaultPad.PressedButtons.usDigitalButtons |= g_Pads[pad].PressedButtons.usDigitalButtons;

		iLThumbX += g_Pads[pad].sLThumbX;
		iLThumbY += g_Pads[pad].sLThumbY;
		iRThumbX += g_Pads[pad].sRThumbX;
		iRThumbY += g_Pads[pad].sRThumbY;

		for(button=0; button<8; button++)
		{
			if(g_Pads[pad].CurrentButtons.ucAnalogButtons[button] >= g_DefaultPad.CurrentButtons.ucAnalogButtons[button])
			{
				g_DefaultPad.CurrentButtons.ucAnalogButtons[button] = g_Pads[pad].CurrentButtons.ucAnalogButtons[button];
			}

			g_DefaultPad.LastButtons.ucAnalogButtons[button] |= g_Pads[pad].LastButtons.ucAnalogButtons[button];
			g_DefaultPad.PressedButtons.ucAnalogButtons[button] |= g_Pads[pad].PressedButtons.ucAnalogButtons[button];
		}
	}

	g_DefaultPad.sLThumbX = (iLThumbX & 0xffff);
	g_DefaultPad.sLThumbY = (iLThumbY & 0xffff);
	g_DefaultPad.sRThumbX = (iRThumbX & 0xffff);
	g_DefaultPad.sRThumbY = (iRThumbY & 0xffff);

	// Mouse status
	memcpy(&g_Mouse, &XMOUSE_current, sizeof(XMOUSE_INPUT));
}

int XInputGetPadCount(void)
{
	int pad;
	int numpads = 0;

	for(pad=0; pad<4; pad++)
	{
		if(XPAD_current[pad].hPresent)
			numpads++;
	}

	return numpads;
}

int XInputGetKeystroke(XKEYBOARD_STROKE *pStroke)
{
	return GetKeyboardStroke(pStroke);
}

XMOUSE_INPUT XInputGetMouseData(void)
{
	return g_Mouse;
}
