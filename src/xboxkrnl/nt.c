// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_nt.c
// *
// * note : XBox Kernel *NT* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

NTSYSAPI VOID *NtAllocateVirtualMemory = 0;
NTSYSAPI VOID *NtCancelTimer = 0;
NTSYSAPI VOID *NtClearEvent = 0;

// ******************************************************************
// * NtClose
// ******************************************************************
NTSYSAPI EXPORTNUM(187) ULONG NTAPI NtClose
(
	IN HANDLE Handle
)
{
    return 0;
}

NTSYSAPI VOID *NtCreateDirectoryObject = 0;
NTSYSAPI VOID *NtCreateEvent = 0;

// ******************************************************************
// * NtCreateFile
// ******************************************************************
NTSYSAPI EXPORTNUM(190) NTSTATUS NTAPI NtCreateFile
(
	OUT PHANDLE  FileHandle, 
	IN  ULONG    DesiredAccess,      // TODO: should be ACCESS_MASK
	IN  PVOID	ObjectAttributes,    // TODO: correct other params
	OUT PVOID	IoStatusBlock,   
	IN  PVOID	AllocationSize, 
	IN  ULONG	FileAttributes, 
	IN  ULONG	ShareAccess, 
	IN  ULONG	CreateDisposition, 
	IN  ULONG	CreateOptions 
)
{
    return 0;
}

NTSYSAPI VOID *NtCreateIoCompletion = 0;
NTSYSAPI VOID *NtCreateMutant = 0;
NTSYSAPI VOID *NtCreateSemaphore = 0;
NTSYSAPI VOID *NtCreateTimer = 0;
NTSYSAPI VOID *NtDeleteFile = 0;
NTSYSAPI VOID *NtDeviceIoControlFile = 0;
NTSYSAPI VOID *NtDuplicateObject = 0;
NTSYSAPI VOID *NtFlushBuffersFile = 0;
NTSYSAPI VOID *NtFreeVirtualMemory = 0;
NTSYSAPI VOID *NtFsControlFile = 0;
NTSYSAPI VOID *NtOpenDirectoryObject = 0;
NTSYSAPI VOID *NtOpenFile = 0;
NTSYSAPI VOID *NtOpenSymbolicLinkObject = 0;
NTSYSAPI VOID *NtProtectVirtualMemory = 0;
NTSYSAPI VOID *NtPulseEvent = 0;
NTSYSAPI VOID *NtQueueApcThread = 0;
NTSYSAPI VOID *NtQueryDirectoryFile = 0;
NTSYSAPI VOID *NtQueryDirectoryObject = 0;
NTSYSAPI VOID *NtQueryEvent = 0;
NTSYSAPI VOID *NtQueryFullAttributesFile = 0;

// ******************************************************************
// * NtQueryInformationFile
// ******************************************************************
NTSYSAPI EXPORTNUM(211) NTSTATUS NTAPI NtQueryInformationFile
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

NTSYSAPI VOID *NtQueryIoCompletion = 0;
NTSYSAPI VOID *NtQueryMutant = 0;
NTSYSAPI VOID *NtQuerySemaphore = 0;
NTSYSAPI VOID *NtQuerySymbolicLinkObject = 0;
NTSYSAPI VOID *NtQueryTimer = 0;
NTSYSAPI VOID *NtQueryVirtualMemory = 0;
NTSYSAPI VOID *NtQueryVolumeInformationFile = 0;

// ******************************************************************
// * NtReadFile
// ******************************************************************
NTSYSAPI EXPORTNUM(219) NTSTATUS NTAPI NtReadFile
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

NTSYSAPI VOID *NtReadFileScatter = 0;
NTSYSAPI VOID *NtReleaseMutant = 0;
NTSYSAPI VOID *NtReleaseSemaphore = 0;
NTSYSAPI VOID *NtRemoveIoCompletion = 0;
NTSYSAPI VOID *NtResumeThread = 0;
NTSYSAPI VOID *NtSetEvent = 0;

// ******************************************************************
// * NtSetInformationFile
// ******************************************************************
NTSYSAPI EXPORTNUM(226) NTSTATUS NTAPI NtSetInformationFile
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

NTSYSAPI VOID *NtSetIoCompletion = 0;
NTSYSAPI VOID *NtSetSystemTime = 0;
NTSYSAPI VOID *NtSetTimerEx = 0;
NTSYSAPI VOID *NtSignalAndWaitForSingleObjectEx = 0;
NTSYSAPI VOID *NtSuspendThread = 0;
NTSYSAPI VOID *NtUserIoApcDispatcher = 0;

// ******************************************************************
// * NtWaitForSingleObject
// ******************************************************************
NTSYSAPI EXPORTNUM(233) NTSTATUS NTAPI NtWaitForSingleObject
(	
	IN  HANDLE  Handle,            // TODO: correct paramters
	IN	BOOLEAN	Alertable,
	IN	PVOID	Timeout
)
{
    return 0;
}

NTSYSAPI VOID *NtWaitForSingleObjectEx = 0;
NTSYSAPI VOID *NtWaitForMultipleObjectsEx = 0;

// ******************************************************************
// * NtWriteFile
// ******************************************************************
NTSYSAPI EXPORTNUM(236) NTSTATUS NTAPI NtWriteFile
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

NTSYSAPI VOID *NtWriteFileGather = 0;
NTSYSAPI VOID *NtYieldExecution = 0;
