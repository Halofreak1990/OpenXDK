// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_hal.c
// *
// * note : XBox Kernel *Hardware Abstraction Layer* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBOXSYSAPI VOID *HalReadSMCTrayState = 0;
XBOXSYSAPI VOID *HalClearSoftwareInterrupt = 0;
XBOXSYSAPI VOID *HalDisableSystemInterrupt = 0;
XBOXSYSAPI VOID *HalDiskCachePartitionCount = 0;
XBOXSYSAPI VOID *HalDiskModelNumber = 0;
XBOXSYSAPI VOID *HalDiskSerialNumber = 0;
XBOXSYSAPI VOID *HalEnableSystemInterrupt = 0;
XBOXSYSAPI VOID *HalGetInterruptVector = 0;
XBOXSYSAPI VOID *HalReadSMBusValue = 0;
XBOXSYSAPI VOID *HalReadWritePCISpace = 0;
XBOXSYSAPI VOID *HalRegisterShutdownNotification = 0;
XBOXSYSAPI VOID *HalRequestSoftwareInterrupt = 0;

// ******************************************************************
// * 0x0031 - HalReturnToFirmware
// ******************************************************************
// *
// * Reboots the xbox in various ways
// *
// ******************************************************************
XBOXSYSAPI DECLSPEC_NORETURN VOID HalReturnToFirmware
(
	RETURN_FIRMWARE Routine
)
{
}

XBOXSYSAPI VOID *HalWriteSMBusValue = 0;
XBOXSYSAPI VOID *HalBootSMCVideoMode = 0;
XBOXSYSAPI VOID *HalIsResetOrShutdownPending = 0;
XBOXSYSAPI VOID *HalInitiateShutdown = 0;
XBOXSYSAPI VOID *HalEnableSecureTrayEject = 0;
XBOXSYSAPI VOID *HalWriteSMCScratchRegister = 0;
XBOXSYSAPI VOID *READ_PORT_BUFFER_UCHAR = 0;
XBOXSYSAPI VOID *READ_PORT_BUFFER_USHORT = 0;
XBOXSYSAPI VOID *READ_PORT_BUFFER_ULONG = 0;
XBOXSYSAPI VOID *WRITE_PORT_BUFFER_UCHAR = 0;
XBOXSYSAPI VOID *WRITE_PORT_BUFFER_USHORT = 0;
XBOXSYSAPI VOID *WRITE_PORT_BUFFER_ULONG = 0;
