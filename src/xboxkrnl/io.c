// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_io.c
// *
// * note : XBox Kernel *I/O Manager* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

NTSYSAPI VOID *IoAllocateIrp = 0;
NTSYSAPI VOID *IoBuildAsynchronousFsdRequest = 0;
NTSYSAPI VOID *IoBuildDeviceIoControlRequest = 0;
NTSYSAPI VOID *IoBuildSynchronousFsdRequest = 0;
NTSYSAPI VOID *IoCheckShareAccess = 0;
NTSYSAPI VOID *IoCompletionObjectType = 0;
NTSYSAPI VOID *IoCreateDevice = 0;
NTSYSAPI VOID *IoCreateFile = 0;
NTSYSAPI VOID *IoCreateSymbolicLink = 0;
NTSYSAPI VOID *IoDeleteDevice = 0;
NTSYSAPI VOID *IoDeleteSymbolicLink = 0;
NTSYSAPI VOID *IoDeviceObjectType = 0;
NTSYSAPI VOID *IoFileObjectType = 0;
NTSYSAPI VOID *IoFreeIrp = 0;
NTSYSAPI VOID *IoInitializeIrp = 0;
NTSYSAPI VOID *IoInvalidDeviceRequest = 0;
NTSYSAPI VOID *IoQueryFileInformation = 0;
NTSYSAPI VOID *IoQueryVolumeInformation = 0;
NTSYSAPI VOID *IoQueueThreadIrp = 0;
NTSYSAPI VOID *IoRemoveShareAccess = 0;
NTSYSAPI VOID *IoSetIoCompletion = 0;
NTSYSAPI VOID *IoSetShareAccess = 0;
NTSYSAPI VOID *IoStartNextPacket = 0;
NTSYSAPI VOID *IoStartNextPacketByKey = 0;
NTSYSAPI VOID *IoStartPacket = 0;
NTSYSAPI VOID *IoSynchronousDeviceIoControlRequest = 0;
NTSYSAPI VOID *IoSynchronousFsdRequest = 0;
NTSYSAPI VOID *IofCallDriver = 0;
NTSYSAPI VOID *IofCompleteRequest = 0;
NTSYSAPI VOID *IoDismountVolume = 0;
NTSYSAPI VOID *IoDismountVolumeByName = 0;
NTSYSAPI VOID *IoMarkIrpMustComplete = 0;
