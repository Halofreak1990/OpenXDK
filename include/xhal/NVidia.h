#ifndef		__NVIDIA_H__
#define		__NVIDIA_H__

//
//
// Massive thanks go to SNK for help with RAW NVidia stuff
//
//

#define NV_REGBASE				(0xFD000000)

// Offsets to registers
#define NV_PMC					(0x000000)
#define NV_PFIFO				(0x002000)		
#define NV_FB					(0x100000)		
#define NV_EXTDEV				(0x101000)		
#define	NV_CRTC					(0x600000)		
#define NV_RAMDAC				(0x680000)		
#define NV_FIFO					(0x800000)		



//
// CRTC register access
//
#define CRTC_WRITE(a,b)			*((volatile u8*)	(NV_REGBASE + NV_CRTC + (a))) = (b)
#define CRTC_READ(a)			(*((volatile u8*)	(NV_REGBASE + NV_CRTC + (a))))
#define CRTC_WRITEL(a,b)		*((volatile u32*)	(NV_REGBASE + NV_CRTC + (a))) = (b)
#define CRTC_READL(a)			(*((volatile u32*)	(NV_REGBASE + NV_CRTC + (a))))





// Registers
#define NV_INPUT_STATUS			(0x13DA)
#define NV_CRTC_FB_ADDR			(0x800)				// Display start address


#endif		//__NVIDIA_H__
