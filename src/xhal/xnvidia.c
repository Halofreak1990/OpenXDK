// ************************************************************************************
//
//
//								 NVidia.c
//                       First Version by Bigboy
//
//
//
// Massive thanks go to SNK for help with RAW NVidia stuff
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
#include "xhal/xnvidia.h"
#include "xhal/xvga_def.h"


u32		_Framebuffer;


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
int	XdkSetVideoMode( u32 dwResolution, u32 dwPixelFormat )
{
	PVOID	vOldFramebuffer;
	u8		*vNewFramebuffer;
	ULONG	TotalSize;
	ULONG	Pitch;
	u32		res;
	u32		pix;

	switch(dwResolution)
	{
	case RES_640X480:		res = RESOLUTION_640;
							Pitch = 640;
							TotalSize = Pitch * 480;
							break;	

	case RES_720X480:		res = RESOLUTION_720;
							Pitch = 720;
							TotalSize = Pitch * 480;
							break;	

	case RES_800X600:		res = RESOLUTION_800;
							Pitch = 800;
							TotalSize = Pitch * 600;
							break;	

	case RES_1024X768:		res = RESOLUTION_1024;
							Pitch = 1024;
							TotalSize = Pitch * 768;
							break;	

	default:				SetLastError(ERROR_INVALID_PARAMETER);
							return FALSE;
	}

	switch(dwPixelFormat)
	{
	case _16BITCOLOUR:		pix = PIXEL_16BITS_555;
							Pitch *= 2;
							TotalSize *= 2;
							break;

	case _32BITCOLOUR:		pix = PIXEL_32BITS;
							Pitch *= 4;
							TotalSize *= 4;
							break;

	default:				SetLastError(ERROR_INVALID_PARAMETER);
							return FALSE;
	}
	
	
	// Allocate a double buffer
	TotalSize *= 2;
	vOldFramebuffer = AvGetSavedDataAddress();

	if (MmQueryAllocationSize(vOldFramebuffer) < (TotalSize + 0x40))
	{
		vNewFramebuffer = MmAllocateContiguousMemoryEx(
			(TotalSize + 0x40),
			0x0000000,
			0xFFFFFFF,
			0,
			0x404
		);

		if (!vNewFramebuffer)
		{
			SetLastError(ERROR_NOT_ENOUGH_MEMORY);
			return FALSE;
		}

		RtlMoveMemory((PVOID) vNewFramebuffer, (PVOID) vOldFramebuffer, 0x40);

		// Wait for vblank start	
		while(CRTC_READ(NV_INPUT_STATUS) & 0x08);

		AvSetSavedDataAddress(vNewFramebuffer);

		MmFreeContiguousMemory(vOldFramebuffer);

		MmPersistContiguousMemory(
			vNewFramebuffer,
			TotalSize + 0x40,
			TRUE
		);

	}
	else
	{
		// Reuse the same buffer
		vNewFramebuffer	= vOldFramebuffer;

		// Wait for vblank start	
		while(CRTC_READ(NV_INPUT_STATUS) & 0x08);
	}

	_FrontBuffer = (u32) (vNewFramebuffer + 0x40);
	_BackBuffer = _FrontBuffer+(TotalSize/2);
	
	FrontBuffer = (u32) MmGetPhysicalAddress(  (void*) _FrontBuffer);
	BackBuffer = FrontBuffer+ (TotalSize / 2);


	RtlZeroMemory( (PVOID) _FrontBuffer, TotalSize);


/*	AvSetDisplayMode(
		(PVOID)NV_REGBASE,
		0,
		(ULONG)res,
		(ULONG)pix,
		(ULONG)Pitch,
		FrontBuffer
	);
*/

	//if (bPAL60)
/*	{
		BYTE	bPixelMode;
	
		// Unlock extra regs
		CRTC_WRITE(NV_CRTC_INDEX, NV_CRTC_REGS_LOCK);
		CRTC_WRITE(NV_CRTC_DATA, NV_CRTC_UNLOCK_VALUE);
		
		// Read the current pixel mode, add the PAL flag and rewrite
		CRTC_WRITE(NV_CRTC_INDEX, NV_CRTC_PIXEL);
		bPixelMode = CRTC_READ(NV_CRTC_DATA);
		bPixelMode &= ~NV_PAL;
		CRTC_WRITE(NV_CRTC_DATA, bPixelMode);
	}
*/
	return TRUE;
}
 