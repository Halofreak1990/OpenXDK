#ifndef HAL_VIDEO_H
#define HAL_VIDEO_H

#include <xboxkrnl/types.h>

// Defines for frame buffer
#define VIDEO_BASE				0xFD000000
#define VIDEO_FRAMEBUFFER			0x03c00000

// Registers
#define PCIO_CRTC_STATUS			0x006013DA

#define PCRTC_START				0x00600800
#define PCRTC_INTR				0x00600100
#define PCRTC_INTR_VBLANK_RESET			0x00000001

#define PCRTC_INTR_EN				0x00600140
#define PCRTC_INTR_EN_VBLANK_DISABLED		0x00000000
#define PCRTC_INTR_EN_VBLANK_ENABLED		0x00000001

#define NV_PMC_INTR_EN_0 0x00000140
#define NV_PMC_INTR_EN_0_INTA_DISABLED 0x00000000
#define NV_PMC_INTR_EN_0_INTA_HARDWARE 0x00000001
#define NV_PMC_INTR_EN_0_INTA_SOFTWARE 0x00000002

// Hardware access macros
#define VIDEOREG(x) (*(volatile unsigned int*)(VIDEO_BASE + (x)))
#define VIDEOREG16(x) (*(volatile unsigned short*)(VIDEO_BASE + (x)))
#define VIDEOREG8(x) (*(volatile unsigned char*)(VIDEO_BASE + (x)))

// Defines for video regions
#define VIDEO_REGION_NTSCM			0x00000100
#define VIDEO_REGION_NTSCJ			0x00000200
#define VIDEO_REGION_PAL			0x00000300

// Defines for pixel formats
#define VIDEO_BPP_16				0x00000011
#define VIDEO_BPP_32				0x00000012

// Defines for video adapter packs
#define VIDEO_ADAPTER_COMPOSITE			0x00000000
#define VIDEO_ADAPTER_RCA			0x00000001
#define VIDEO_ADAPTER_SVIDEO			0x00000002
#define VIDEO_ADAPTER_RGBSCART		0x00000003
#define VIDEO_ADAPTER_HDTV	         	0x00000004
#define VIDEO_ADAPTER_VGA_SOG         		0x00000005

// Defines for video encoder options
#define VIDEO_ENC_GET_SETTINGS		6
#define VIDEO_ENC_VIDEOENABLE		9
#define VIDEO_ENC_FLICKERFILTER		11
#define VIDEO_ENC_SOFTEN_FILTER		14

//Defines for refresh rates
#define REFRESH_50HZ				50
#define REFRESH_60HZ				60
#define REFRESH_DEFAULT				0

// Structure to hold details about a video mode;
typedef struct _VIDEO_MODE
{
	int		width;
	int		height;
	int		bpp;
	int		refresh;
} VIDEO_MODE;


DWORD XVideoGetEncoderSettings(void);
unsigned char* XVideoGetFB(void);
VIDEO_MODE XVideoGetMode(void);

void XVideoSetFlickerFilter(int level);
BOOL XVideoSetMode(int width, int height, int bpp, int refresh);
void XVideoSetSoftenFilter(BOOL enable);
void XVideoSetVideoEnable(BOOL enable);

/*
Lists the video modes available at the given colour depth and refresh rate.
On the first call the argument p must be a pointer to a void pointer
initialized to NULL. This is used internally to maintain context between
successive calls. If a matching video mode is found then XVideoListModes will
return TRUE and the video mode details will be written to the VIDEO_MODE vm
structure. If no matching video mode is found the function will return FALSE.
Repeatedly calling the function allows all matching video modes to be read out.
If a value of 0 is provided for the refresh rate the current refresh rate is used.
If a value of 0 is provided for the bpp a default value of 32bpp is used.
*/ 
BOOLEAN XVideoListModes(VIDEO_MODE *vm, int bpp, int refresh, void **p);

void XVideoWaitForVBlank();
void XVideoSetDisplayStart(unsigned int offset);
unsigned char* XVideoGetVideoBase();
int XVideoVideoMemorySize();

#endif
