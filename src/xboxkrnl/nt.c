// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : nt.c
// *
// * note : XBox Kernel *NT* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

// ******************************************************************
// * NtAllocateVirtualMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(184) NTSTATUS NtAllocateVirtualMemory
(
    IN OUT PVOID    *BaseAddress,
    IN ULONG         ZeroBits,
    IN OUT PULONG    AllocationSize,
    IN DWORD         AllocationType,
    IN DWORD         Protect
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtCancelTimer = 0;
XBSYSAPI VOID *NtClearEvent = 0;

// ******************************************************************
// * NtClose
// ******************************************************************
XBSYSAPI EXPORTNUM(187) NTSTATUS NTAPI NtClose
(
	IN HANDLE Handle
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtCreateDirectoryObject = 0;

// ******************************************************************
// * NtCreateEvent
// ******************************************************************
XBSYSAPI EXPORTNUM(189) NTSTATUS NTAPI NtCreateEvent
(
    OUT PHANDLE             EventHandle,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes OPTIONAL,
    IN  EVENT_TYPE          EventType,
    IN  BOOLEAN             InitialState
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtCreateFile
// ******************************************************************
XBSYSAPI EXPORTNUM(190) NTSTATUS NTAPI NtCreateFile
(
	OUT PHANDLE             FileHandle, 
	IN  ACCESS_MASK         DesiredAccess,
	IN  POBJECT_ATTRIBUTES	ObjectAttributes,
	OUT PIO_STATUS_BLOCK	IoStatusBlock,
	IN  PLARGE_INTEGER	    AllocationSize OPTIONAL, 
	IN  ULONG	            FileAttributes, 
	IN  ULONG	            ShareAccess, 
	IN  ULONG	            CreateDisposition, 
	IN  ULONG	            CreateOptions 
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtCreateIoCompletion = 0;
XBSYSAPI VOID *NtCreateMutant = 0;
XBSYSAPI VOID *NtCreateSemaphore = 0;
XBSYSAPI VOID *NtCreateTimer = 0;
XBSYSAPI VOID *NtDeleteFile = 0;
XBSYSAPI VOID *NtDeviceIoControlFile = 0;
XBSYSAPI VOID *NtDuplicateObject = 0;
XBSYSAPI VOID *NtFlushBuffersFile = 0;

// ******************************************************************
// * NtFreeVirtualMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(199) NTSTATUS NtFreeVirtualMemory
(
    IN OUT PVOID *BaseAddress,
    IN OUT PULONG FreeSize,
    IN ULONG      FreeType
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtFsControlFile = 0;
XBSYSAPI VOID *NtOpenDirectoryObject = 0;

// ******************************************************************
// * NtOpenFile
// ******************************************************************
XBSYSAPI EXPORTNUM(202) NTSTATUS NtOpenFile
(
    OUT PHANDLE             FileHandle,
    IN  ACCESS_MASK         DesiredAccess,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes,
    OUT PIO_STATUS_BLOCK    IoStatusBlock,
    IN  ULONG               ShareAccess,
    IN  ULONG               OpenOptions
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtOpenSymbolicLinkObject = 0;
XBSYSAPI VOID *NtProtectVirtualMemory = 0;
XBSYSAPI VOID *NtPulseEvent = 0;
XBSYSAPI VOID *NtQueueApcThread = 0;
XBSYSAPI VOID *NtQueryDirectoryFile = 0;
XBSYSAPI VOID *NtQueryDirectoryObject = 0;
XBSYSAPI VOID *NtQueryEvent = 0;
XBSYSAPI VOID *NtQueryFullAttributesFile = 0;

// ******************************************************************
// * NtQueryInformationFile
// ******************************************************************
XBSYSAPI EXPORTNUM(211) NTSTATUS NTAPI NtQueryInformationFile
(   
    IN  HANDLE                      FileHandle,
    OUT PIO_STATUS_BLOCK            IoStatusBlock,
    OUT PFILE_FS_SIZE_INFORMATION   FileInformation, 
    IN  ULONG                       Length, 
    IN  FILE_INFORMATION_CLASS      FileInfo
)
{
    return 0;
}

XBSYSAPI VOID *NtQueryIoCompletion = 0;
XBSYSAPI VOID *NtQueryMutant = 0;
XBSYSAPI VOID *NtQuerySemaphore = 0;
XBSYSAPI VOID *NtQuerySymbolicLinkObject = 0;
XBSYSAPI VOID *NtQueryTimer = 0;
XBSYSAPI VOID *NtQueryVirtualMemory = 0;

// ******************************************************************
// * NtQueryVolumeInformationFile
// ******************************************************************
XBSYSAPI EXPORTNUM(218) NTSTATUS NTAPI NtQueryVolumeInformationFile
(
    IN  HANDLE                      FileHandle,
    OUT PIO_STATUS_BLOCK            IoStatusBlock,
    OUT PFILE_FS_SIZE_INFORMATION   FileInformation,
    IN  ULONG                       Length,
    IN  FS_INFORMATION_CLASS        FileInformationClass
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtReadFile
// ******************************************************************
XBSYSAPI EXPORTNUM(219) NTSTATUS NTAPI NtReadFile
(
	IN  HANDLE          FileHandle,            // TODO: correct paramters
	IN  HANDLE          Event OPTIONAL,
	IN  PVOID           ApcRoutine OPTIONAL,
	IN  PVOID           ApcContext,
	OUT PVOID           IoStatusBlock,
	OUT PVOID           Buffer,
	IN  ULONG           Length,
	IN  PLARGE_INTEGER  ByteOffset OPTIONAL
)
{
    return 0;
}

XBSYSAPI VOID *NtReadFileScatter = 0;
XBSYSAPI VOID *NtReleaseMutant = 0;
XBSYSAPI VOID *NtReleaseSemaphore = 0;
XBSYSAPI VOID *NtRemoveIoCompletion = 0;
XBSYSAPI VOID *NtResumeThread = 0;
XBSYSAPI VOID *NtSetEvent = 0;

// ******************************************************************
// * NtSetInformationFile
// ******************************************************************
XBSYSAPI EXPORTNUM(226) NTSTATUS NTAPI NtSetInformationFile
(	
	IN  HANDLE  FileHandle,            // TODO: correct paramters
	OUT	PVOID	IoStatusBlock,
	IN	PVOID	FileInformation,
	IN	ULONG	Length,
	IN	ULONG	FileInformationClass
)
{
    return 0;
}

XBSYSAPI VOID *NtSetIoCompletion = 0;
XBSYSAPI VOID *NtSetSystemTime = 0;
XBSYSAPI VOID *NtSetTimerEx = 0;
XBSYSAPI VOID *NtSignalAndWaitForSingleObjectEx = 0;
XBSYSAPI VOID *NtSuspendThread = 0;
XBSYSAPI VOID *NtUserIoApcDispatcher = 0;

// ******************************************************************
// * NtWaitForSingleObject
// ******************************************************************
XBSYSAPI EXPORTNUM(233) NTSTATUS NTAPI NtWaitForSingleObject
(	
	IN  HANDLE  Handle,            // TODO: correct paramters
	IN	BOOLEAN	Alertable,
	IN	PVOID	Timeout
)
{
    return 0;
}

XBSYSAPI VOID *NtWaitForSingleObjectEx = 0;
XBSYSAPI VOID *NtWaitForMultipleObjectsEx = 0;

// ******************************************************************
// * NtWriteFile
// ******************************************************************
XBSYSAPI EXPORTNUM(236) NTSTATUS NTAPI NtWriteFile
(	
	IN  HANDLE  FileHandle,            // TODO: correct paramters
	IN	PVOID	Event,
	IN	PVOID	ApcRoutine,
	IN	PVOID	ApcContext,
	OUT	PVOID	IoStatusBlock,
	IN	PVOID	Buffer,
	IN	ULONG	Length,
	IN	PVOID	ByteOffset
)
{
    return 0;
}

XBSYSAPI VOID *NtWriteFileGather = 0;
XBSYSAPI VOID *NtYieldExecution = 0;
