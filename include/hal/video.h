#ifndef HAL_VIDEO_H
#define HAL_VIDEO_H

#include <xboxkrnl/types.h>

// Defines for frame buffer
#define VIDEO_BASE					0xFD000000
#define VIDEO_FRAMEBUFFER			0x03c00000

// Defines for video regions
#define VIDEO_REGION_NTSCM			0x00000100
#define VIDEO_REGION_NTSCJ			0x00000200
#define VIDEO_REGION_PAL			0x00000300

// Defines for pixel formats
#define VIDEO_BPP_16				0x00000011
#define VIDEO_BPP_32				0x00000012

// Defines for video adapter packs
#define VIDEO_ADAPTER_NORMAL		0x00000000
#define VIDEO_ADAPTER_RGBSCART		0x00000003

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

#endif
