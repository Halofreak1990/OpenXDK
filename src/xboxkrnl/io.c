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

XBOXSYSAPI VOID *IoAllocateIrp = 0;
XBOXSYSAPI VOID *IoBuildAsynchronousFsdRequest = 0;
XBOXSYSAPI VOID *IoBuildDeviceIoControlRequest = 0;
XBOXSYSAPI VOID *IoBuildSynchronousFsdRequest = 0;
XBOXSYSAPI VOID *IoCheckShareAccess = 0;
XBOXSYSAPI VOID *IoCompletionObjectType = 0;
XBOXSYSAPI VOID *IoCreateDevice = 0;
XBOXSYSAPI VOID *IoCreateFile = 0;
XBOXSYSAPI VOID *IoCreateSymbolicLink = 0;
XBOXSYSAPI VOID *IoDeleteDevice = 0;
XBOXSYSAPI VOID *IoDeleteSymbolicLink = 0;
XBOXSYSAPI VOID *IoDeviceObjectType = 0;
XBOXSYSAPI VOID *IoFileObjectType = 0;
XBOXSYSAPI VOID *IoFreeIrp = 0;
XBOXSYSAPI VOID *IoInitializeIrp = 0;
XBOXSYSAPI VOID *IoInvalidDeviceRequest = 0;
XBOXSYSAPI VOID *IoQueryFileInformation = 0;
XBOXSYSAPI VOID *IoQueryVolumeInformation = 0;
XBOXSYSAPI VOID *IoQueueThreadIrp = 0;
XBOXSYSAPI VOID *IoRemoveShareAccess = 0;
XBOXSYSAPI VOID *IoSetIoCompletion = 0;
XBOXSYSAPI VOID *IoSetShareAccess = 0;
XBOXSYSAPI VOID *IoStartNextPacket = 0;
XBOXSYSAPI VOID *IoStartNextPacketByKey = 0;
XBOXSYSAPI VOID *IoStartPacket = 0;
XBOXSYSAPI VOID *IoSynchronousDeviceIoControlRequest = 0;
XBOXSYSAPI VOID *IoSynchronousFsdRequest = 0;
XBOXSYSAPI VOID *IofCallDriver = 0;
XBOXSYSAPI VOID *IofCompleteRequest = 0;
XBOXSYSAPI VOID *IoDismountVolume = 0;
XBOXSYSAPI VOID *IoDismountVolumeByName = 0;
XBOXSYSAPI VOID *IoMarkIrpMustComplete = 0;
