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
#define NV_CRTC_INDEX			(0x13D4)
#define NV_CRTC_DATA			(0x13D5)


#define NV_CRTC_REGS_LOCK		0x1F
#define NV_CRTC_UNLOCK_VALUE	0x57
#define NV_CRTC_LOCK_VALUE		0x99
#define NV_CRTC_PIXEL			(0x28)



//
// Pixel + TV mode bits
//
#define NV_TV			0x80			
#define NV_VGA			0x00
#define NV_PAL			0x40
#define NV_NTSC			0x00
#define	NV_VGA			0x00		// format
#define NV_8BPP			0x01
#define	NV_16BPP		0x02
#define NV_32BPP		0x03
#define NV_BPP_MASK		(~0x03)		// 



void NVSetScreenAddress( void );
void NVSetBPP( int mode );



#endif		//__NVIDIA_H__
