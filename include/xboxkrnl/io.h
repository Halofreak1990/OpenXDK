// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : io.h
// *
// * note : XBox Kernel *I/O Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_IO_H
#define XBOXKRNL_IO_H

NTSYSAPI VOID *IoAllocateIrp;
NTSYSAPI VOID *IoBuildAsynchronousFsdRequest;
NTSYSAPI VOID *IoBuildDeviceIoControlRequest;
NTSYSAPI VOID *IoBuildSynchronousFsdRequest;
NTSYSAPI VOID *IoCheckShareAccess;
NTSYSAPI VOID *IoCompletionObjectType;
NTSYSAPI VOID *IoCreateDevice;
NTSYSAPI VOID *IoCreateFile;
NTSYSAPI VOID *IoCreateSymbolicLink;
NTSYSAPI VOID *IoDeleteDevice;
NTSYSAPI VOID *IoDeleteSymbolicLink;
NTSYSAPI VOID *IoDeviceObjectType;
NTSYSAPI VOID *IoFileObjectType;
NTSYSAPI VOID *IoFreeIrp;
NTSYSAPI VOID *IoInitializeIrp;
NTSYSAPI VOID *IoInvalidDeviceRequest;
NTSYSAPI VOID *IoQueryFileInformation;
NTSYSAPI VOID *IoQueryVolumeInformation;
NTSYSAPI VOID *IoQueueThreadIrp;
NTSYSAPI VOID *IoRemoveShareAccess;
NTSYSAPI VOID *IoSetIoCompletion;
NTSYSAPI VOID *IoSetShareAccess;
NTSYSAPI VOID *IoStartNextPacket;
NTSYSAPI VOID *IoStartNextPacketByKey;
NTSYSAPI VOID *IoStartPacket;
NTSYSAPI VOID *IoSynchronousDeviceIoControlRequest;
NTSYSAPI VOID *IoSynchronousFsdRequest;
NTSYSAPI VOID *IofCallDriver;
NTSYSAPI VOID *IofCompleteRequest;
NTSYSAPI VOID *IoDismountVolume;
NTSYSAPI VOID *IoDismountVolumeByName;
NTSYSAPI VOID *IoMarkIrpMustComplete;

#endif


