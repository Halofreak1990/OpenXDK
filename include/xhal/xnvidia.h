// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xnvidia.h
// *
// * note : XBox NVidia Chip
// *
// ******************************************************************
#ifndef		__XNVIDIA_H__
#define		__XNVIDIA_H__

#ifdef	__cplusplus
extern "C" {
#endif

// ******************************************************************
// * AvSetDisplayMode pixel formats
// ******************************************************************
#define PIXEL_16BITS_555	0x10
#define PIXEL_16BITS_565	0x11
#define PIXEL_32BITS		0x12

// ******************************************************************
// * AvSetDisplayMode resolutions (only 640 is tested)
// ******************************************************************
#define RESOLUTION_640		0x20010101
#define RESOLUTION_720		0x20020101
#define RESOLUTION_800		0x20030101
#define RESOLUTION_1024		0x200B0101

// ******************************************************************
// * NVidia registers base / offsets
// ******************************************************************
#define NV_REGBASE				(0xFD000000)
#define NV_PMC					(0x000000)
#define NV_PFIFO				(0x002000)		
#define NV_FB					(0x100000)		
#define NV_EXTDEV				(0x101000)		
#define	NV_CRTC					(0x600000)		
#define NV_RAMDAC				(0x680000)		
#define NV_FIFO					(0x800000)		

// ******************************************************************
// * CRTC register accessors
// ******************************************************************
#define CRTC_WRITE(a,b)			*((volatile u8*)	(NV_REGBASE + NV_CRTC + (a))) = (b)
#define CRTC_READ(a)			(*((volatile u8*)	(NV_REGBASE + NV_CRTC + (a))))
#define CRTC_WRITEL(a,b)		*((volatile u32*)	(NV_REGBASE + NV_CRTC + (a))) = (b)
#define CRTC_READL(a)			(*((volatile u32*)	(NV_REGBASE + NV_CRTC + (a))))

// ******************************************************************
// * Registers
// ******************************************************************
#define NV_INPUT_STATUS			(0x13DA)
#define NV_CRTC_FB_ADDR			(0x800)				// Display start address
#define NV_CRTC_INDEX			(0x13D4)
#define NV_CRTC_DATA			(0x13D5)
#define NV_CRTC_REGS_LOCK		0x1F
#define NV_CRTC_UNLOCK_VALUE	0x57
#define NV_CRTC_LOCK_VALUE		0x99
#define NV_CRTC_PIXEL			(0x28)

// ******************************************************************
// * Pixel / TV Mode bits
// ******************************************************************
#define NV_TV			0x80			
#define NV_VGA			0x00
#define NV_PAL			0x40
#define NV_NTSC			0x00
#define	NV_VGA			0x00		// format
#define NV_8BPP			0x01
#define	NV_16BPP		0x02
#define NV_32BPP		0x03
#define NV_BPP_MASK		(~0x03)		// 

// ******************************************************************
// * Accessible Functions
// ******************************************************************
void    NVSetScreenAddress(void);
void    NVSetBPP(int mode);
int     XdkSetVideoMode(u32 dwResolution, u32 dwPixelFormat );

#ifdef	__cplusplus
};
#endif

#endif		//__XNVIDIA_H__
