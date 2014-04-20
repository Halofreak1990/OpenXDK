// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : io.c
// *
// * note : XBox Kernel *I/O Manager* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

// ******************************************************************
// * IoAllocateIrp
// ******************************************************************
XBSYSAPI EXPORTNUM(59) NTSTATUS NTAPI IoAllocateIrp
(
	IN	PDEVICE_OBJECT	DeviceObject
)
{
	return STATUS_SUCCESS;
}

XBSYSAPI VOID *IoBuildAsynchronousFsdRequest = 0;
XBSYSAPI VOID *IoBuildDeviceIoControlRequest = 0;
XBSYSAPI VOID *IoBuildSynchronousFsdRequest = 0;
XBSYSAPI VOID *IoCheckShareAccess = 0;
XBSYSAPI VOID *IoCompletionObjectType = 0;
XBSYSAPI VOID *IoCreateDevice = 0;

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
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * IoCreateSymbolicLink
// ******************************************************************
XBSYSAPI EXPORTNUM(67) NTSTATUS NTAPI IoCreateSymbolicLink
(
    IN PSTRING SymbolicLinkName,
    IN PSTRING DeviceName
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *IoDeleteDevice = 0;

// ******************************************************************
// * IoDeleteSymbolicLink
// ******************************************************************
XBSYSAPI EXPORTNUM(69) NTSTATUS NTAPI IoDeleteSymbolicLink
(
    IN PSTRING SymbolicLinkName
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *IoDeviceObjectType = 0;
XBSYSAPI VOID *IoFileObjectType = 0;
XBSYSAPI VOID *IoFreeIrp = 0;
XBSYSAPI VOID *IoInitializeIrp = 0;
XBSYSAPI VOID *IoInvalidDeviceRequest = 0;
XBSYSAPI VOID *IoQueryFileInformation = 0;

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
)
{
	return TRUE;
}

XBSYSAPI VOID *IoQueueThreadIrp = 0;
XBSYSAPI VOID *IoRemoveShareAccess = 0;
XBSYSAPI VOID *IoSetIoCompletion = 0;
XBSYSAPI VOID *IoSetShareAccess = 0;
XBSYSAPI VOID *IoStartNextPacket = 0;
XBSYSAPI VOID *IoStartNextPacketByKey = 0;
XBSYSAPI VOID *IoStartPacket = 0;

// ******************************************************************
// * IoSynchronousDeviceIoControlRequest
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
)
{
	return STATUS_SUCCESS;
}

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
)
{
	return STATUS_SUCCESS;
}

XBSYSAPI VOID *IofCallDriver = 0;
XBSYSAPI VOID *IofCompleteRequest = 0;
XBSYSAPI VOID *IoDismountVolume = 0;

// ******************************************************************
// * IoDismountVolumeByName
// ******************************************************************
XBSYSAPI EXPORTNUM(90) NTSTATUS NTAPI IoDismountVolumeByName
(
	IN PANSI_STRING DeviceName
)
{
	return STATUS_SUCCESS;
}

XBSYSAPI VOID *IoMarkIrpMustComplete = 0;
