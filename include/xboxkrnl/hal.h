// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_hal.h
// *
// * note : XBox Kernel *Hardware Abstraction Layer* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_HAL_H
#define XBOXKRNL_HAL_H

// ******************************************************************
// * RETURN_FIRMWARE
// ******************************************************************
typedef enum _RETURN_FIRMWARE
{
    ReturnFirmwareHalt          = 0x0,
    ReturnFirmwareReboot        = 0x1,
    ReturnFirmwareQuickReboot   = 0x2,
    ReturnFirmwareHard          = 0x3,
    ReturnFirmwareFatal         = 0x4,
    ReturnFirmwareAll           = 0x5
}
RETURN_FIRMWARE, *LPRETURN_FIRMWARE;

XBOXSYSAPI VOID *HalReadSMCTrayState;
XBOXSYSAPI VOID *HalClearSoftwareInterrupt;
XBOXSYSAPI VOID *HalDisableSystemInterrupt;
XBOXSYSAPI VOID *HalDiskCachePartitionCount;
XBOXSYSAPI VOID *HalDiskModelNumber;
XBOXSYSAPI VOID *HalDiskSerialNumber;
XBOXSYSAPI VOID *HalEnableSystemInterrupt;
XBOXSYSAPI VOID *HalGetInterruptVector;
XBOXSYSAPI VOID *HalReadSMBusValue;
XBOXSYSAPI VOID *HalReadWritePCISpace;
XBOXSYSAPI VOID *HalRegisterShutdownNotification;
XBOXSYSAPI VOID *HalRequestSoftwareInterrupt;

// ******************************************************************
// * 0x0031 - HalReturnToFirmware
// ******************************************************************
// *
// * Reboot / Shutdown / Etc
// *
// ******************************************************************
XBOXSYSAPI DECLSPEC_NORETURN VOID HalReturnToFirmware
(
	RETURN_FIRMWARE Routine
);

XBOXSYSAPI VOID *HalWriteSMBusValue;
XBOXSYSAPI VOID *HalBootSMCVideoMode;
XBOXSYSAPI VOID *HalIsResetOrShutdownPending;
XBOXSYSAPI VOID *HalInitiateShutdown;
XBOXSYSAPI VOID *HalEnableSecureTrayEject;
XBOXSYSAPI VOID *HalWriteSMCScratchRegister;
XBOXSYSAPI VOID *READ_PORT_BUFFER_UCHAR;
XBOXSYSAPI VOID *READ_PORT_BUFFER_USHORT;
XBOXSYSAPI VOID *READ_PORT_BUFFER_ULONG;
XBOXSYSAPI VOID *WRITE_PORT_BUFFER_UCHAR;
XBOXSYSAPI VOID *WRITE_PORT_BUFFER_USHORT;
XBOXSYSAPI VOID *WRITE_PORT_BUFFER_ULONG;

#endif