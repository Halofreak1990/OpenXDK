// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_io.h
// *
// * note : XBox Kernel *I/O Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_IO_H
#define XBOXKRNL_IO_H

XBOXSYSAPI VOID *IoAllocateIrp;
XBOXSYSAPI VOID *IoBuildAsynchronousFsdRequest;
XBOXSYSAPI VOID *IoBuildDeviceIoControlRequest;
XBOXSYSAPI VOID *IoBuildSynchronousFsdRequest;
XBOXSYSAPI VOID *IoCheckShareAccess;
XBOXSYSAPI VOID *IoCompletionObjectType;
XBOXSYSAPI VOID *IoCreateDevice;
XBOXSYSAPI VOID *IoCreateFile;
XBOXSYSAPI VOID *IoCreateSymbolicLink;
XBOXSYSAPI VOID *IoDeleteDevice;
XBOXSYSAPI VOID *IoDeleteSymbolicLink;
XBOXSYSAPI VOID *IoDeviceObjectType;
XBOXSYSAPI VOID *IoFileObjectType;
XBOXSYSAPI VOID *IoFreeIrp;
XBOXSYSAPI VOID *IoInitializeIrp;
XBOXSYSAPI VOID *IoInvalidDeviceRequest;
XBOXSYSAPI VOID *IoQueryFileInformation;
XBOXSYSAPI VOID *IoQueryVolumeInformation;
XBOXSYSAPI VOID *IoQueueThreadIrp;
XBOXSYSAPI VOID *IoRemoveShareAccess;
XBOXSYSAPI VOID *IoSetIoCompletion;
XBOXSYSAPI VOID *IoSetShareAccess;
XBOXSYSAPI VOID *IoStartNextPacket;
XBOXSYSAPI VOID *IoStartNextPacketByKey;
XBOXSYSAPI VOID *IoStartPacket;
XBOXSYSAPI VOID *IoSynchronousDeviceIoControlRequest;
XBOXSYSAPI VOID *IoSynchronousFsdRequest;
XBOXSYSAPI VOID *IofCallDriver;
XBOXSYSAPI VOID *IofCompleteRequest;
XBOXSYSAPI VOID *IoDismountVolume;
XBOXSYSAPI VOID *IoDismountVolumeByName;
XBOXSYSAPI VOID *IoMarkIrpMustComplete;

#endif