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

NTSYSAPI VOID *HalReadSMCTrayState;
NTSYSAPI VOID *HalClearSoftwareInterrupt;
NTSYSAPI VOID *HalDisableSystemInterrupt;
NTSYSAPI VOID *HalDiskCachePartitionCount;
NTSYSAPI VOID *HalDiskModelNumber;
NTSYSAPI VOID *HalDiskSerialNumber;
NTSYSAPI VOID *HalEnableSystemInterrupt;
NTSYSAPI VOID *HalGetInterruptVector;
NTSYSAPI VOID *HalReadSMBusValue;

// ******************************************************************
// * HalReadWritePCISpace
// ******************************************************************
NTSYSAPI EXPORTNUM(46) VOID NTAPI HalReadWritePCISpace
(
  IN ULONG   BusNumber,
  IN ULONG   SlotNumber,
  IN PVOID   Buffer,
  IN ULONG   Length,
  IN BOOLEAN WritePCISpace
);

NTSYSAPI VOID *HalRegisterShutdownNotification;
NTSYSAPI VOID *HalRequestSoftwareInterrupt;

// ******************************************************************
// * HalReturnToFirmware
// ******************************************************************
// *
// * Reboot / Shutdown / Etc
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(49) VOID DECLSPEC_NORETURN HalReturnToFirmware
(
	RETURN_FIRMWARE Routine
);

NTSYSAPI VOID *HalWriteSMBusValue;
NTSYSAPI VOID *HalBootSMCVideoMode;
NTSYSAPI VOID *HalIsResetOrShutdownPending;
NTSYSAPI VOID *HalInitiateShutdown;
NTSYSAPI VOID *HalEnableSecureTrayEject;
NTSYSAPI VOID *HalWriteSMCScratchRegister;
NTSYSAPI VOID *READ_PORT_BUFFER_UCHAR;
NTSYSAPI VOID *READ_PORT_BUFFER_USHORT;
NTSYSAPI VOID *READ_PORT_BUFFER_ULONG;
NTSYSAPI VOID *WRITE_PORT_BUFFER_UCHAR;
NTSYSAPI VOID *WRITE_PORT_BUFFER_USHORT;
NTSYSAPI VOID *WRITE_PORT_BUFFER_ULONG;

#endif


