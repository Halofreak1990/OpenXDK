// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : hal.c
// *
// * note : XBox Kernel *Hardware Abstraction Layer* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

NTSYSAPI VOID *HalReadSMCTrayState = 0;
NTSYSAPI VOID *HalClearSoftwareInterrupt = 0;
NTSYSAPI VOID *HalDisableSystemInterrupt = 0;
NTSYSAPI VOID *HalDiskCachePartitionCount = 0;
NTSYSAPI VOID *HalDiskModelNumber = 0;
NTSYSAPI VOID *HalDiskSerialNumber = 0;
NTSYSAPI VOID *HalEnableSystemInterrupt = 0;
NTSYSAPI VOID *HalGetInterruptVector = 0;
NTSYSAPI VOID *HalReadSMBusValue = 0;

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
)
{
    return;
}

NTSYSAPI VOID *HalRegisterShutdownNotification = 0;
NTSYSAPI VOID *HalRequestSoftwareInterrupt = 0;

// ******************************************************************
// * 0x0031 - HalReturnToFirmware
// ******************************************************************
NTSYSAPI EXPORTNUM(49) VOID DECLSPEC_NORETURN HalReturnToFirmware
(
	RETURN_FIRMWARE Routine
)
{

}

NTSYSAPI VOID *HalWriteSMBusValue = 0;
NTSYSAPI VOID *HalBootSMCVideoMode = 0;
NTSYSAPI VOID *HalIsResetOrShutdownPending = 0;
NTSYSAPI VOID *HalInitiateShutdown = 0;
NTSYSAPI VOID *HalEnableSecureTrayEject = 0;
NTSYSAPI VOID *HalWriteSMCScratchRegister = 0;

// ******************************************************************
// * READ_PORT_BUFFER_UCHAR
// ******************************************************************
NTSYSAPI EXPORTNUM(329) VOID NTAPI READ_PORT_BUFFER_UCHAR
(
    IN PUCHAR Port,
    IN PUCHAR Buffer,
    IN ULONG  Count
)
{
    return;
}

// ******************************************************************
// * READ_PORT_BUFFER_USHORT
// ******************************************************************
NTSYSAPI EXPORTNUM(330) VOID NTAPI READ_PORT_BUFFER_USHORT
(
    IN PUSHORT Port,
    IN PUSHORT Buffer,
    IN ULONG   Count
)
{
    return;
}

// ******************************************************************
// * READ_PORT_BUFFER_ULONG
// ******************************************************************
NTSYSAPI EXPORTNUM(331) VOID NTAPI READ_PORT_BUFFER_ULONG
(
    IN PULONG Port,
    IN PULONG Buffer,
    IN ULONG  Count
)
{
    return;
}

// ******************************************************************
// * WRITE_PORT_BUFFER_UCHAR
// ******************************************************************
NTSYSAPI EXPORTNUM(332) VOID NTAPI WRITE_PORT_BUFFER_UCHAR
(
    IN PUCHAR Port,
    IN PUCHAR Buffer,
    IN ULONG  Count
)
{
    return;
}

// ******************************************************************
// * WRITE_PORT_BUFFER_USHORT
// ******************************************************************
NTSYSAPI EXPORTNUM(333) VOID NTAPI WRITE_PORT_BUFFER_USHORT
(
    IN PUSHORT Port,
    IN PUSHORT Buffer,
    IN ULONG   Count
)
{
    return;
}

// ******************************************************************
// * WRITE_PORT_BUFFER_ULONG
// ******************************************************************
NTSYSAPI EXPORTNUM(334) VOID NTAPI WRITE_PORT_BUFFER_ULONG
(
    IN PULONG Port,
    IN PULONG Buffer,
    IN ULONG  Count
)
{
    return;
}