// ************************************************************************************
//
//
//								 NVidia.c
//                       First Version by Bigboy
//
//
//
//  Revision		By				Comment
//  --------		--				-------
//	1.0             Bigboy          Basic control of the NVidia hardware								
//  1.1             Bigboy          added support for 16bit screen modes.
//
// ************************************************************************************

#include	<openxdk.h>








// ************************************************************************************
//
//
//
//
// ************************************************************************************

//********************************************************
//
// Name:		NVSetScreenAddress
// Function:   	Set screen address, and do a WaitVBlank()
//
// In:			None
// Out:			None
//
//********************************************************
void NVSetScreenAddress( void )
{
	//while(CRTC_READ(NV_INPUT_STATUS) & 0x08);		// Wait for VBLANK to start

	// swap buffers around
	FrontBuffer ^= BackBuffer;
	BackBuffer ^= FrontBuffer;
	FrontBuffer ^= BackBuffer;

	if (FrontBuffer && BackBuffer)
	{
		CRTC_WRITEL(NV_CRTC_FB_ADDR, FrontBuffer );
	}

	//while(!(CRTC_READ(NV_INPUT_STATUS) & 0x08));	// Wait till start of frame.... Why?

}



//********************************************************
//
// Name:		NVSetBPP
// Function:   	change the screens Bits per pixel
//
// In:			_32BITCOLOUR
//				_16BITCOLOUR
//				_8BITCOLOUR
// Out:			none
//
//********************************************************
void NVSetBPP( int mode )
{
	u8		reg;
	// Unlock extra regs
	CRTC_WRITE(NV_CRTC_INDEX, NV_CRTC_REGS_LOCK);
	CRTC_WRITE(NV_CRTC_DATA, NV_CRTC_UNLOCK_VALUE);
	
		
	CRTC_WRITE(NV_CRTC_INDEX, NV_CRTC_PIXEL);				// Get current
	reg = CRTC_READ(NV_CRTC_DATA);

	// KeepTV and frequ, drop BPP mode
	reg &= NV_BPP_MASK; 
	switch( mode ){
		case _32BITCOLOUR:	reg |= NV_32BPP;	break;
		case _16BITCOLOUR:	reg |= NV_16BPP;	break;
		case _8BITCOLOUR:	reg |= NV_8BPP;		break;
	}
	CRTC_WRITE(NV_CRTC_DATA, reg);

}
