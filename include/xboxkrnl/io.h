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

XBSYSAPI VOID *IoAllocateIrp;
XBSYSAPI VOID *IoBuildAsynchronousFsdRequest;
XBSYSAPI VOID *IoBuildDeviceIoControlRequest;
XBSYSAPI VOID *IoBuildSynchronousFsdRequest;
XBSYSAPI VOID *IoCheckShareAccess;
XBSYSAPI VOID *IoCompletionObjectType;
XBSYSAPI VOID *IoCreateDevice;
XBSYSAPI VOID *IoCreateFile;
XBSYSAPI VOID *IoCreateSymbolicLink;
XBSYSAPI VOID *IoDeleteDevice;
XBSYSAPI VOID *IoDeleteSymbolicLink;
XBSYSAPI VOID *IoDeviceObjectType;
XBSYSAPI VOID *IoFileObjectType;
XBSYSAPI VOID *IoFreeIrp;
XBSYSAPI VOID *IoInitializeIrp;
XBSYSAPI VOID *IoInvalidDeviceRequest;
XBSYSAPI VOID *IoQueryFileInformation;
XBSYSAPI VOID *IoQueryVolumeInformation;
XBSYSAPI VOID *IoQueueThreadIrp;
XBSYSAPI VOID *IoRemoveShareAccess;
XBSYSAPI VOID *IoSetIoCompletion;
XBSYSAPI VOID *IoSetShareAccess;
XBSYSAPI VOID *IoStartNextPacket;
XBSYSAPI VOID *IoStartNextPacketByKey;
XBSYSAPI VOID *IoStartPacket;
XBSYSAPI VOID *IoSynchronousDeviceIoControlRequest;
XBSYSAPI VOID *IoSynchronousFsdRequest;
XBSYSAPI VOID *IofCallDriver;
XBSYSAPI VOID *IofCompleteRequest;
XBSYSAPI VOID *IoDismountVolume;
XBSYSAPI VOID *IoDismountVolumeByName;
XBSYSAPI VOID *IoMarkIrpMustComplete;

#endif


