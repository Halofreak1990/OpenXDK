// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xstartup.h
// *
// * note : Entry point for user applications
// *
// ******************************************************************
#include "openxdk.h"

// ******************************************************************
// * XBoxCRTStartup
// ******************************************************************
VOID XBoxCRTStartup()
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
    // * Start user application
    // ******************************************************************
    XBoxStartup();

    // ******************************************************************
    // * If user application returns, just reboot.
    // ******************************************************************
    HalReturnToFirmware(ReturnFirmwareReboot);

    return;
}
