#include <sys/times.h>
#include <hal/xbox.h>
#include <xboxkrnl/xboxkrnl.h>

void XReboot()
{
	HalReturnToFirmware(ReturnFirmwareReboot);
}

int XGetTickCount()
{
	return KeTickCount;
}

void XSleep(int milliseconds)
{
	int target = times(NULL)+milliseconds;
	while(times(NULL)<target);
}
