// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : hal.h
// *
// * note : XBox Kernel *Hardware Abstraction Layer* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_HAL_H
#define XBOXKRNL_HAL_H

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
  IN ULONG   RegisterNumber,
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

// ******************************************************************
// * READ_PORT_BUFFER_UCHAR
// ******************************************************************
NTSYSAPI EXPORTNUM(329) VOID NTAPI READ_PORT_BUFFER_UCHAR
(
    IN PUCHAR Port,
    IN PUCHAR Buffer,
    IN ULONG  Count
);

// ******************************************************************
// * READ_PORT_BUFFER_USHORT
// ******************************************************************
NTSYSAPI EXPORTNUM(330) VOID NTAPI READ_PORT_BUFFER_USHORT
(
    IN PUSHORT Port,
    IN PUSHORT Buffer,
    IN ULONG   Count
);

// ******************************************************************
// * READ_PORT_BUFFER_ULONG
// ******************************************************************
NTSYSAPI EXPORTNUM(331) VOID NTAPI READ_PORT_BUFFER_ULONG
(
    IN PULONG Port,
    IN PULONG Buffer,
    IN ULONG  Count
);

// ******************************************************************
// * WRITE_PORT_BUFFER_UCHAR
// ******************************************************************
NTSYSAPI EXPORTNUM(332) VOID NTAPI WRITE_PORT_BUFFER_UCHAR
(
    IN PUCHAR Port,
    IN PUCHAR Buffer,
    IN ULONG  Count
);

// ******************************************************************
// * WRITE_PORT_BUFFER_USHORT
// ******************************************************************
NTSYSAPI EXPORTNUM(333) VOID NTAPI WRITE_PORT_BUFFER_USHORT
(
    IN PUSHORT Port,
    IN PUSHORT Buffer,
    IN ULONG   Count
);

// ******************************************************************
// * WRITE_PORT_BUFFER_ULONG
// ******************************************************************
NTSYSAPI EXPORTNUM(334) VOID NTAPI WRITE_PORT_BUFFER_ULONG
(
    IN PULONG Port,
    IN PULONG Buffer,
    IN ULONG  Count
);

#endif


