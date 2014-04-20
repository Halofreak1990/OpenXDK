#include <memory.h>
#include <sys/stat.h>
#include <hal/xbox.h>
#include <hal/fileio.h>
#include <xboxkrnl/xboxkrnl.h>

#include <stdio.h>
#include <openxdk/debug.h>

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
	LARGE_INTEGER li;

	li.QuadPart = (LONGLONG)milliseconds * -10000;

	// Where possible, Alertable should be set to FALSE and WaitMode should be set to kernelMode,
	// in order to reduce driver complexity. The principal exception to this is when the wait is a long term wait.
	KeDelayExecutionThread((KPROCESSOR_MODE)0, false, &li); // it doesn't seem to get KernelMode from the added MODE enum
								// in xboxkrnl/types.h so we just use 0 (it's the same value)
}

/**
 * Launches an XBE.  Examples of xbePath might be:
 *   c:\\blah.xbe
 *   c:/foo/bar.xbe
 * If the XBE is able to be launched, this method will
 * not return.  If there is a problem, then it return.
 */
void XLaunchXBE(char *xbePath)
{
	struct stat statbuf;
	if (stat(xbePath, &statbuf) < 0)
		return;	
	
	memset((void*)LaunchDataPage, 0, 0x1000);
	
	LaunchDataPage->Header.dwLaunchDataType = 0xFFFFFFFF;
	LaunchDataPage->Header.dwTitleId = 0;
	XConvertDOSFilenameToXBOX(xbePath, LaunchDataPage->Header.szLaunchPath);
	
	// one last thing... xbePath now looks like:
	//   \Device\Harddisk0\Partition2\blah\doom.xbe
	// but it has to look like:
	//   \Device\Harddisk0\Partition2\blah;doom.xbe
	char *lastSlash = strrchr(LaunchDataPage->Header.szLaunchPath, '\\');
	if (lastSlash != NULL)
	{
		*lastSlash = ';';
		HalReturnToFirmware(ReturnFirmwareQuickReboot);
	}
	
	// if we couldn't find a trailing slash, the conversion to 
	// the xbox path mustn't have worked, so we will return
}

int XCreateThread(XThreadCallback callback, void *args1, void *args2)
{
	ULONG id;
	HANDLE handle;

	NTSTATUS status = PsCreateSystemThreadEx(
		(HANDLE)&handle,
		0,
		65536,
		0,
		&id,
		args1,
		args2,
		FALSE,
		FALSE,
		(PKSTART_ROUTINE)callback);

	if (handle == 0) {
		return -1;
	}

	return (unsigned int)handle;
}

