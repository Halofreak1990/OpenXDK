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
    IN ULONG         AllocationType,
    IN ULONG         Protect
)
{
    return 0;
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
    return 0;
}

XBSYSAPI VOID *NtCreateDirectoryObject = 0;
XBSYSAPI VOID *NtCreateEvent = 0;

// ******************************************************************
// * NtCreateFile
// ******************************************************************
XBSYSAPI EXPORTNUM(190) NTSTATUS NTAPI NtCreateFile
(
	OUT PHANDLE     FileHandle, 
	IN  ACCESS_MASK DesiredAccess,
	IN  PVOID	    ObjectAttributes,    // TODO: correct other params
	OUT PVOID	    IoStatusBlock,   
	IN  PVOID	    AllocationSize, 
	IN  ULONG	    FileAttributes, 
	IN  ULONG	    ShareAccess, 
	IN  ULONG	    CreateDisposition, 
	IN  ULONG	    CreateOptions 
)
{
    return 0;
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
    return 0;
}

XBSYSAPI VOID *NtFsControlFile = 0;
XBSYSAPI VOID *NtOpenDirectoryObject = 0;
XBSYSAPI VOID *NtOpenFile = 0;
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
	IN  HANDLE FileHandle,          // TODO: improve parameter accuracy
	OUT PVOID  IoStatusBlock,
	OUT PVOID  FileInformation, 
	IN  ULONG  Length, 
	IN  ULONG  FileInfo
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
XBSYSAPI VOID *NtQueryVolumeInformationFile = 0;

// ******************************************************************
// * NtReadFile
// ******************************************************************
XBSYSAPI EXPORTNUM(219) NTSTATUS NTAPI NtReadFile
(
	IN  HANDLE   FileHandle,            // TODO: correct paramters
	IN  PVOID    Event OPTIONAL,
	IN  PVOID    ApcRoutine OPTIONAL,
	IN  PVOID    ApcContext,
	OUT PVOID    IoStatusBlock,
	OUT PVOID    Buffer,
	IN  ULONG    Length,
	IN  PVOID    ByteOffset
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
