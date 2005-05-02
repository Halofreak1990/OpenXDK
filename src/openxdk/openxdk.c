#include <stdio.h>
#include <openxdk/openxdk.h>
#include <hal/video.h>

extern void XBoxStartup();

void WinMainCRTStartup()
{
	// ******************************************************************
	// * this is a hack to ensure that at least 1 kernel export is used
	// * without this, cxbe will generate an invalid .xbe file
	// ******************************************************************
	{
		volatile int fail = 1;
		if(fail != 1)
			HalReturnToFirmware(ReturnFirmwareFatal);
	}

	// ******************************************************************
	// * Setup default video mode - 640x480x32
	// ******************************************************************
	XVideoSetMode(640, 480, 32, REFRESH_DEFAULT);

	// ******************************************************************
	// * Start user application
	// ******************************************************************
	XBoxStartup();

	// Lets make sure that any output has been flushed
	fclose(stdout);
	fclose(stderr);
	
	// ******************************************************************
	// * If user application returns, just reboot.
	// ******************************************************************
	HalReturnToFirmware(ReturnFirmwareReboot);
}

