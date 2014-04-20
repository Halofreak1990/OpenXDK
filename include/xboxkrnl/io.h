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

#include "xboxkrnl.h"

// ******************************************************************
// * IoAllocateIrp
// ******************************************************************
XBSYSAPI EXPORTNUM(59) NTSTATUS NTAPI IoAllocateIrp
(
	IN	PDEVICE_OBJECT	DeviceObject
);

XBSYSAPI EXPORTNUM(60) VOID *IoBuildAsynchronousFsdRequest;
XBSYSAPI EXPORTNUM(61) VOID *IoBuildDeviceIoControlRequest;
XBSYSAPI EXPORTNUM(62) VOID *IoBuildSynchronousFsdRequest;
XBSYSAPI EXPORTNUM(63) VOID *IoCheckShareAccess;
XBSYSAPI EXPORTNUM(64) VOID *IoCompletionObjectType;
XBSYSAPI EXPORTNUM(65) VOID *IoCreateDevice;

// ******************************************************************
// * IoCreateFile
// ******************************************************************
XBSYSAPI EXPORTNUM(66) NTSTATUS NTAPI IoCreateFile
(
	OUT PHANDLE             FileHandle,
	IN  ACCESS_MASK         DesiredAccess,
	IN  POBJECT_ATTRIBUTES  ObjectAttributes,
	OUT PIO_STATUS_BLOCK    IoStatusBlock,
	IN  PLARGE_INTEGER      AllocationSize,
	IN  ULONG               FileAttributes,
	IN  ULONG               ShareAccess,
	IN  ULONG               Disposition,
	IN  ULONG               CreateOptions,
	IN  ULONG               Options
);

// ******************************************************************
// * IoCreateSymbolicLink
// ******************************************************************
XBSYSAPI EXPORTNUM(67) NTSTATUS NTAPI IoCreateSymbolicLink
(
	IN PSTRING SymbolicLinkName,
	IN PSTRING DeviceName
);

XBSYSAPI EXPORTNUM(68) VOID *IoDeleteDevice;

// ******************************************************************
// * IoDeleteSymbolicLink
// ******************************************************************
XBSYSAPI EXPORTNUM(69) NTSTATUS NTAPI IoDeleteSymbolicLink
(
	IN PSTRING SymbolicLinkName
);

XBSYSAPI EXPORTNUM(70) VOID *IoDeviceObjectType;
XBSYSAPI EXPORTNUM(71) VOID *IoFileObjectType;
XBSYSAPI EXPORTNUM(72) VOID *IoFreeIrp;
XBSYSAPI EXPORTNUM(73) VOID *IoInitializeIrp;
XBSYSAPI EXPORTNUM(74) VOID *IoInvalidDeviceRequest;
XBSYSAPI EXPORTNUM(75) VOID *IoQueryFileInformation;

// ******************************************************************
// * IoQueryVolumeInformation
// ******************************************************************
XBSYSAPI EXPORTNUM(76) BOOLEAN NTAPI IoQueryVolumeInformation
(
	IN	LPCSTR	lpRootPathName, 
	OUT	LPSTR	lpVolumeNameBuffer,
	IN	DWORD	nVolumeNameSize,
	OUT	LPDWORD	lpVolumeSerialNumber,
	OUT	LPDWORD lpMaximumComponentLength,
	OUT	LPDWORD	lpFileSystemFlags,
	OUT	LPSTR	lpFileSystemNameBuffer,
	IN	DWORD	nFileSystemNameSize
);

XBSYSAPI EXPORTNUM(77) VOID *IoQueueThreadIrp;
XBSYSAPI EXPORTNUM(78) VOID *IoRemoveShareAccess;
XBSYSAPI EXPORTNUM(79) VOID *IoSetIoCompletion;
XBSYSAPI EXPORTNUM(80) VOID *IoSetShareAccess;
XBSYSAPI EXPORTNUM(81) VOID *IoStartNextPacket;
XBSYSAPI EXPORTNUM(82) VOID *IoStartNextPacketByKey;
XBSYSAPI EXPORTNUM(83) VOID *IoStartPacket;

// ******************************************************************
// * IoSynchronousDeviceIoControlRequest
// ******************************************************************
// *
// * Performs a blocking IOCTL on the specified device.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(84) NTSTATUS NTAPI IoSynchronousDeviceIoControlRequest
(
	IN	ULONG			IoControlCode,
	IN	PDEVICE_OBJECT	DeviceObject,
	IN	PVOID			InputBuffer OPTIONAL,
	IN	ULONG			InputBufferLength,
	OUT	PVOID			OutputBuffer OPTIONAL,
	IN	ULONG			OutputBufferLength,
	OUT	PDWORD			unknown_use_zero OPTIONAL,
	IN	BOOLEAN			InternalDeviceIoControl
);

// ******************************************************************
// * IoSynchronousFsdRequest
// ******************************************************************
XBSYSAPI EXPORTNUM(85) NTSTATUS NTAPI IoSynchronousFsdRequest
(
	IN	ULONG		MajorFunction,
	IN	PDEVICE_OBJECT	DeviceObject,
	IN OUT	PVOID		Buffer OPTIONAL,
	IN	ULONG		Length OPTIONAL,
	IN	PLARGE_INTEGER	StartingOffset OPTIONAL
);

XBSYSAPI EXPORTNUM(86) VOID *IofCallDriver;
XBSYSAPI EXPORTNUM(87) VOID *IofCompleteRequest;
XBSYSAPI EXPORTNUM(89) VOID *IoDismountVolume;

// ******************************************************************
// * IoDismountVolumeByName
// ******************************************************************
XBSYSAPI EXPORTNUM(90) NTSTATUS NTAPI IoDismountVolumeByName
(
	IN PANSI_STRING DeviceName
);

XBSYSAPI VOID *IoMarkIrpMustComplete;

#endif
