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

XBSYSAPI VOID *HalReadSMCTrayState = 0;
XBSYSAPI VOID *HalClearSoftwareInterrupt = 0;
XBSYSAPI VOID *HalDisableSystemInterrupt = 0;
XBSYSAPI VOID *HalDiskCachePartitionCount = 0;
XBSYSAPI VOID *HalDiskModelNumber = 0;
XBSYSAPI VOID *HalDiskSerialNumber = 0;
XBSYSAPI VOID *HalEnableSystemInterrupt = 0;
XBSYSAPI VOID *HalGetInterruptVector = 0;

// ******************************************************************
// * HalReadSMBusValue
// ******************************************************************
XBSYSAPI EXPORTNUM(45) VOID NTAPI HalReadSMBusValue
(
    ULONG   BusNumber,
    ULONG   SlotNumber,
    ULONG   RegisterNumber,
    PVOID   Buffer,
    ULONG   Length,
    BOOLEAN WritePCISpace
)
{
    return;
}

// ******************************************************************
// * HalReadWritePCISpace
// ******************************************************************
XBSYSAPI EXPORTNUM(46) VOID NTAPI HalReadWritePCISpace
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

XBSYSAPI VOID *HalRegisterShutdownNotification = 0;
XBSYSAPI VOID *HalRequestSoftwareInterrupt = 0;

// ******************************************************************
// * 0x0031 - HalReturnToFirmware
// ******************************************************************
XBSYSAPI EXPORTNUM(49) VOID DECLSPEC_NORETURN HalReturnToFirmware
(
	RETURN_FIRMWARE Routine
)
{

}

// ******************************************************************
// * HalWriteSMBusValue
// ******************************************************************
XBSYSAPI EXPORTNUM(50) ULONG NTAPI HalWriteSMBusValue
(
    UCHAR   Address,
    UCHAR   Command,
    BOOLEAN WordFlag,
    ULONG   Value
)
{
    return 0;
}

// ******************************************************************
// * HalBootSMCVideoMode
// ******************************************************************
XBSYSAPI EXPORTNUM(356) DWORD HalBootSMCVideoMode = 0;

XBSYSAPI VOID *HalIsResetOrShutdownPending = 0;
XBSYSAPI VOID *HalInitiateShutdown = 0;
XBSYSAPI VOID *HalEnableSecureTrayEject = 0;
XBSYSAPI VOID *HalWriteSMCScratchRegister = 0;

// ******************************************************************
// * READ_PORT_BUFFER_UCHAR
// ******************************************************************
XBSYSAPI EXPORTNUM(329) VOID NTAPI READ_PORT_BUFFER_UCHAR
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
XBSYSAPI EXPORTNUM(330) VOID NTAPI READ_PORT_BUFFER_USHORT
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
XBSYSAPI EXPORTNUM(331) VOID NTAPI READ_PORT_BUFFER_ULONG
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
XBSYSAPI EXPORTNUM(332) VOID NTAPI WRITE_PORT_BUFFER_UCHAR
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
XBSYSAPI EXPORTNUM(333) VOID NTAPI WRITE_PORT_BUFFER_USHORT
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
XBSYSAPI EXPORTNUM(334) VOID NTAPI WRITE_PORT_BUFFER_ULONG
(
    IN PULONG Port,
    IN PULONG Buffer,
    IN ULONG  Count
)
{
    return;
}