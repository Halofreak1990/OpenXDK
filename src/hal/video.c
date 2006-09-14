#include <xboxkrnl/xboxkrnl.h>
#include <hal/xbox.h>
#include <hal/video.h>
#include <memory.h>

unsigned char*	_fb;
DWORD			dwEncoderSettings = 0;
VIDEO_MODE		vmCurrent;
int				flickerLevel	= 5;
BOOL			flickerSet		= FALSE;
BOOL			softenFilter	= TRUE;
BOOL			softenSet		= FALSE;

typedef struct _VIDEO_MODE_SETTING
{
	DWORD dwMode;
	int width;
	int height;
	int refresh;
	DWORD dwStandard;
	DWORD dwFlags;
} VIDEO_MODE_SETTING;

VIDEO_MODE_SETTING vidModes[] =
{
 {0x44030307,640,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_COMPOSITE}, //640x480 PAL 50Hz
 {0x44040408,720,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_COMPOSITE}, //720x480 PAL 50Hz
 {0x0401010B,640,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_COMPOSITE}, //640x480 PAL 60Hz
 {0x0402020C,720,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_COMPOSITE}, //720x480 PAL 60Hz
 {0x04010101,640,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_COMPOSITE}, //640x480 NTSCM 60Hz
 {0x04020202,720,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_COMPOSITE}, //720x480 NTSCM 60Hz
 {0x04010103,640,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_COMPOSITE}, //640x480 NTSCJ 60Hz
 {0x04020204,720,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_COMPOSITE}, //720x480 NTSCJ 60Hz

 {0x44030307,640,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_RCA}, //640x480 PAL 50Hz
 {0x44040408,720,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_RCA}, //720x480 PAL 50Hz
 {0x0401010B,640,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_RCA}, //640x480 PAL 60Hz
 {0x0402020C,720,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_RCA}, //720x480 PAL 60Hz
 {0x04010101,640,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_RCA}, //640x480 NTSCM 60Hz
 {0x04020202,720,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_RCA}, //720x480 NTSCM 60Hz
 {0x04010103,640,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_RCA}, //640x480 NTSCJ 60Hz
 {0x04020204,720,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_RCA}, //720x480 NTSCJ 60Hz

 {0x44030307,640,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_SVIDEO}, //640x480 PAL 50Hz
 {0x44040408,720,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_SVIDEO}, //720x480 PAL 50Hz
 {0x0401010B,640,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_SVIDEO}, //640x480 PAL 60Hz
 {0x0402020C,720,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_SVIDEO}, //720x480 PAL 60Hz
 {0x04010101,640,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_SVIDEO}, //640x480 NTSCM 60Hz
 {0x04020202,720,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_SVIDEO}, //720x480 NTSCM 60Hz
 {0x04010103,640,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_SVIDEO}, //640x480 NTSCJ 60Hz
 {0x04020204,720,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_SVIDEO}, //720x480 NTSCJ 60Hz

 {0x60030307,640,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_RGBSCART}, //640x480 PAL 50Hz RGB
 {0x60040408,720,480,50,VIDEO_REGION_PAL,VIDEO_ADAPTER_RGBSCART}, //720x480 PAL 50Hz RGB
 {0x2001010B,640,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_RGBSCART}, //640x480 PAL 60Hz RGB
 {0x2002020C,720,480,60,VIDEO_REGION_PAL,VIDEO_ADAPTER_RGBSCART}, //720x480 PAL 60Hz RGB
 {0x20010101,640,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_RGBSCART}, //640x480 NTSCM 60Hz RGB
 {0x20020202,720,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_RGBSCART}, //720x480 NTSCM 60Hz RGB
 {0x20010103,640,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_RGBSCART}, //640x480 NTSCJ 60Hz RGB
 {0x20020204,720,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_RGBSCART}, //720x480 NTSCJ 60Hz RGB

 {0x88070701,640,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_HDTV}, //640x480p NTSCM 60Hz
 {0x88080801,720,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_HDTV}, //720x480p NTSCM 60Hz
 {0x880B0A02,1280,720,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_HDTV}, //1280x720p NTSCM 60Hz
 {0x880E0C03,1920,1080,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_HDTV}, //1920x1080i NTSCM 60Hz
 {0x88070701,640,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_HDTV}, //640x480p NTSCJ 60Hz
 {0x88080801,720,480,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_HDTV}, //720x480p NTSCJ 60Hz
 {0x880B0A02,1280,720,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_HDTV}, //1280x720p NTSCJ 60Hz
 {0x880E0C03,1920,1080,60,VIDEO_REGION_NTSCJ,VIDEO_ADAPTER_HDTV}, //1920x1080i NTSCJ 60Hz

 {0xC0060601,640,480,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_VGA_SOG}, //640x480 SVGA 60Hz
 {0xC0030303,800,600,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_VGA_SOG}, //800x600 SVGA 60Hz
 {0xC0040404,1024,768,60,VIDEO_REGION_NTSCM,VIDEO_ADAPTER_VGA_SOG}, //1024x768 SVGA 60Hz
};

int iVidModes = sizeof(vidModes) / sizeof(VIDEO_MODE_SETTING);


DWORD XVideoGetEncoderSettings(void)
{
	if(dwEncoderSettings == 0)
	{
		AvSendTVEncoderOption((PVOID)VIDEO_BASE, VIDEO_ENC_GET_SETTINGS, 0, (ULONG*)&dwEncoderSettings);
	}

	return dwEncoderSettings;
}

BOOLEAN XVideoListModes(VIDEO_MODE *vm, int bpp, int refresh, void **p)
{
	int i;
	int position = (int) *p;
	if (position >= iVidModes) {
		return FALSE;
	}
	DWORD dwEnc = XVideoGetEncoderSettings();
	
	DWORD dwAdapter = dwEnc & 0x000000FF;
	DWORD dwStandard = dwEnc & 0x0000FF00;
	
	VIDEO_MODE_SETTING *pVidMode;
	if (bpp == 0)
	{
		bpp = 32;
	}
	if (refresh == 0)
	{
		if(dwEnc & 0x00400000)
		{
			refresh = 60;
		} else
		{
			refresh = 50;
		}
	}
	for(; position < iVidModes; position++)
	{
		pVidMode = &vidModes[position];

		if((pVidMode->dwFlags & 0x000000FF) != dwAdapter)
			continue;

		if(pVidMode->dwStandard != dwStandard)
			continue;

		if(pVidMode->refresh != refresh)
			continue;

		break;
	}
	
	*p = (void *)(position + 1);
	
	if(position >= iVidModes) // No compatible mode found
	{
		return FALSE;
	}
	else
	{
		vm->width = pVidMode->width;
		vm->height = pVidMode->height;
		vm->bpp = bpp;
		vm->refresh = refresh;
		return TRUE;
	}
}

unsigned char* XVideoGetFB(void)
{
	return _fb;
}

VIDEO_MODE XVideoGetMode(void)
{
	return vmCurrent;
}

void XVideoInit(DWORD dwMode, int width, int height, int bpp)
{
	ULONG Step = 0;
	DWORD dwFormat = (bpp == 32) ? VIDEO_BPP_32 : VIDEO_BPP_16;

	XVideoSetVideoEnable(FALSE);

	do
	{
		Step = AvSetDisplayMode((PVOID)VIDEO_BASE, Step, 
			dwMode, dwFormat, width*(bpp/8), VIDEO_FRAMEBUFFER);
	} while(Step);

	XVideoSetFlickerFilter(5);
	XVideoSetSoftenFilter(TRUE);

	XVideoSetVideoEnable(TRUE);

	_fb = (unsigned char*)(0xF0000000+*(unsigned int*)0xFD600800);
	memset(_fb, 0x00, width*height*(bpp/8));
}


BOOL XVideoSetMode(int width, int height, int bpp, int refresh)
{
	VIDEO_MODE_SETTING *pVidMode = NULL;
	int vidRefresh = 0;
	int i = 0;

	DWORD dwEnc = XVideoGetEncoderSettings();
	
	DWORD dwAdapter		= dwEnc & 0x000000FF;
	DWORD dwStandard	= dwEnc & 0x0000FF00;

	if(bpp != 16 && bpp != 32)
		bpp = 32;

	if(refresh > 0)
		vidRefresh = refresh;
	else
	{
		if(dwEnc & 0x00400000) //60Hz refresh rate
			vidRefresh = 60;
		else
			vidRefresh = 50;
	}

	for(i=0; i<iVidModes; i++)
	{
		pVidMode = &vidModes[i];

		if((pVidMode->dwFlags & 0x000000FF) != dwAdapter)
			continue;

		if(pVidMode->dwStandard != dwStandard)
			continue;

		if(pVidMode->width != width || pVidMode->height != height)
			continue;

		if(pVidMode->refresh != vidRefresh)
			continue;

		break;
	}

	if(i >= iVidModes) // No compatible mode found
	{
		memset(&vmCurrent, 0x00, sizeof(VIDEO_MODE));
		return FALSE;
	}

	XVideoInit(pVidMode->dwMode, pVidMode->width, pVidMode->height, bpp);

	vmCurrent.width = pVidMode->width;
	vmCurrent.height = pVidMode->height;
	vmCurrent.bpp = bpp;
	vmCurrent.refresh = vidRefresh;

	return TRUE;
}


void XVideoSetVideoEnable(BOOL enable)
{
	AvSendTVEncoderOption((PVOID)VIDEO_BASE, VIDEO_ENC_VIDEOENABLE, enable ? FALSE : TRUE, NULL);
}


void XVideoSetFlickerFilter(int level)
{
	if(!flickerSet || (level & 0x07) != flickerLevel)
	{
		AvSendTVEncoderOption((PVOID)VIDEO_BASE, VIDEO_ENC_FLICKERFILTER, (level & 0x07), NULL);

		flickerSet = TRUE;
		flickerLevel = level & 0x07;
	}
}

void XVideoSetSoftenFilter(BOOL enable)
{
	if(!softenSet || softenFilter != enable)
	{
		AvSendTVEncoderOption((PVOID)VIDEO_BASE, VIDEO_ENC_SOFTEN_FILTER, enable, NULL);

		softenSet = TRUE;
		softenFilter = enable;
	}
}
