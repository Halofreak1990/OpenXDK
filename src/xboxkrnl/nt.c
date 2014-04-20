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
XBSYSAPI EXPORTNUM(184) NTSTATUS NTAPI NtAllocateVirtualMemory
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

// ******************************************************************
// * NtClearEvent
// ******************************************************************
XBSYSAPI EXPORTNUM(186) NTSTATUS NTAPI NtClearEvent
(
    IN HANDLE EventHandle
)
{
    return STATUS_SUCCESS;
}

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

// ******************************************************************
// * NtCreateMutant
// ******************************************************************
XBSYSAPI EXPORTNUM(192) NTSTATUS NTAPI NtCreateMutant
(
    OUT PHANDLE             MutantHandle,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes,
    IN  BOOLEAN             InitialOwner
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtCreateSemaphore
// ******************************************************************
XBSYSAPI EXPORTNUM(193) NTSTATUS NTAPI NtCreateSemaphore
(
    OUT PHANDLE           SemaphoreHandle,
    IN POBJECT_ATTRIBUTES ObjectAttributes OPTIONAL,
    IN LONG               InitialCount,
    IN LONG               MaximumCount
)
{
		return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtCreateTimer = 0;

// ******************************************************************
// * NtDeleteFile
// ******************************************************************
XBSYSAPI EXPORTNUM(195) BOOLEAN NTAPI NtDeleteFile
(
	IN	LPCSTR	lpFileName
)
{
	return TRUE;
}

// ******************************************************************
// * NtDeviceIoControlFile
// ******************************************************************
XBSYSAPI EXPORTNUM(196) NTSTATUS NTAPI NtDeviceIoControlFile
(
	IN	HANDLE			FileHandle,
	IN	HANDLE			Event OPTIONAL,
	IN	PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
	IN	PVOID			ApcContext OPTIONAL,
	OUT	PIO_STATUS_BLOCK	IoStatusBlock,
	IN	ULONG			IoControlCode,
	IN	PVOID			InputBuffer OPTIONAL,
	IN	ULONG			InputBufferLength,
	OUT	PVOID			OutputBuffer OPTIONAL,
	IN	ULONG			OutputBufferLength
)
{
	return STATUS_SUCCESS;
}

// ******************************************************************
// * NtDuplicateObject
// ******************************************************************
XBSYSAPI EXPORTNUM(197) NTSTATUS NTAPI NtDuplicateObject
(
    PVOID   SourceHandle,
    PVOID  *TargetHandle,
    DWORD   Options
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtFlushBuffersFile
// ******************************************************************
XBSYSAPI EXPORTNUM(198) NTSTATUS NTAPI NtFlushBuffersFile
(
    PVOID                FileHandle,
    OUT PIO_STATUS_BLOCK IoStatusBlock
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtFreeVirtualMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(199) NTSTATUS NTAPI NtFreeVirtualMemory
(
    IN OUT PVOID *BaseAddress,
    IN OUT PULONG FreeSize,
    IN ULONG      FreeType
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtFsControlFile
// ******************************************************************
XBSYSAPI EXPORTNUM(200) NTSTATUS NTAPI NtFsControlFile
(
	IN	HANDLE			FileHandle,
	IN	HANDLE			Event OPTIONAL,
	IN	PIO_APC_ROUTINE		ApcRoutine OPTIONAL,
	IN	PVOID			ApcContext OPTIONAL,
	OUT	PIO_STATUS_BLOCK	IoStatusBlock,
	IN	ULONG			FsControlCode,
	IN	PVOID			InputBuffer OPTIONAL,
	IN	ULONG			InputBufferLength,
	OUT	PVOID			OutputBuffer OPTIONAL,
	IN	ULONG			OutputBufferLength
)
{
	return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtOpenDirectoryObject = 0;

// ******************************************************************
// * NtOpenFile
// ******************************************************************
XBSYSAPI EXPORTNUM(202) NTSTATUS NTAPI NtOpenFile
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

// ******************************************************************
// * NtPulseEvent
// ******************************************************************
XBSYSAPI EXPORTNUM(205) NTSTATUS NTAPI NtPulseEvent
(
    IN HANDLE                       EventHandle,
    OUT PLONG                       PreviousState OPTIONAL
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtQueueApcThread = 0;

// ******************************************************************
// * NtQueryDirectoryFile
// ******************************************************************
XBSYSAPI EXPORTNUM(207) NTSTATUS NTAPI NtQueryDirectoryFile
(
    IN  HANDLE                      FileHandle,
    IN  HANDLE                      Event OPTIONAL,
    IN  PVOID                       ApcRoutine, // Todo: define this routine's prototype
    IN  PVOID                       ApcContext,
    OUT PIO_STATUS_BLOCK            IoStatusBlock,
    OUT PVOID                       FileInformation,
    IN  ULONG                       Length,
    IN  FILE_INFORMATION_CLASS      FileInformationClass,
    IN  PSTRING                     FileMask,
    IN  BOOLEAN                     RestartScan
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtQueryDirectoryObject = 0;
XBSYSAPI VOID *NtQueryEvent = 0;

// ******************************************************************
// * NtQueryFullAttributesFile
// ******************************************************************
XBSYSAPI EXPORTNUM(210) NTSTATUS NTAPI NtQueryFullAttributesFile
(   
    IN  POBJECT_ATTRIBUTES          ObjectAttributes,
    OUT PVOID                       Attributes
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtQueryInformationFile
// ******************************************************************
XBSYSAPI EXPORTNUM(211) NTSTATUS NTAPI NtQueryInformationFile
(   
    IN  HANDLE                      FileHandle,
    OUT PIO_STATUS_BLOCK            IoStatusBlock,
    OUT PVOID                       FileInformation, 
    IN  ULONG                       Length, 
    IN  FILE_INFORMATION_CLASS      FileInfo
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtQueryIoCompletion = 0;
XBSYSAPI VOID *NtQueryMutant = 0;
XBSYSAPI VOID *NtQuerySemaphore = 0;

// ******************************************************************
// * NtQuerySymbolicLinkObject
// ******************************************************************
XBSYSAPI EXPORTNUM(215) NTSTATUS NTAPI NtQuerySymbolicLinkObject
(
	IN HANDLE			SymbolicLinkHandle,
	OUT PANSI_STRING		pLinkName,
	OUT PULONG			pDataWritten OPTIONAL
)
{
	return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtQueryTimer = 0;

// ******************************************************************
// * NtQueryVirtualMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(217) NTSTATUS NTAPI NtQueryVirtualMemory
(
    IN  PVOID                       BaseAddress,
    OUT PMEMORY_BASIC_INFORMATION   MemoryInformation
)
{
	return STATUS_SUCCESS;
}

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
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtReadFileScatter = 0;

// ******************************************************************
// * NtReleaseMutant
// ******************************************************************
XBSYSAPI EXPORTNUM(221) NTSTATUS NTAPI NtReleaseMutant
(
    IN  HANDLE  MutantHandle,
    OUT PLONG   PreviousCount
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI EXPORTNUM(222) NTSTATUS NTAPI NtReleaseSemaphore
(
    IN HANDLE   SemaphoreHandle,
    IN ULONG    ReleaseCount,
    OUT PULONG  PreviousCount OPTIONAL
)
{
	return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtRemoveIoCompletion = 0;

// ******************************************************************
// * NtResumeThread
// ******************************************************************
XBSYSAPI EXPORTNUM(224) NTSTATUS NTAPI NtResumeThread
(
    IN  HANDLE ThreadHandle,
    OUT PULONG PreviousSuspendCount
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtSetEvent
// ******************************************************************
XBSYSAPI EXPORTNUM(225) NTSTATUS NTAPI NtSetEvent
(
    IN  HANDLE  EventHandle,
    OUT PLONG   PreviousState
)
{
    return STATUS_SUCCESS;
}

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
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *NtSetIoCompletion = 0;
XBSYSAPI VOID *NtSetSystemTime = 0;
XBSYSAPI VOID *NtSetTimerEx = 0;
XBSYSAPI VOID *NtSignalAndWaitForSingleObjectEx = 0;

// ******************************************************************
// * NtSuspendThread
// ******************************************************************
XBSYSAPI EXPORTNUM(231) NTSTATUS NTAPI NtSuspendThread
(
    IN  HANDLE  ThreadHandle,
    OUT PULONG  PreviousSuspendCount OPTIONAL
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtUserIoApcDispatcher
// ******************************************************************
XBSYSAPI EXPORTNUM(232) VOID NTAPI NtUserIoApcDispatcher
(
    PVOID            ApcContext,
    PIO_STATUS_BLOCK IoStatusBlock,
    ULONG            Reserved
)
{
    return;
}

// ******************************************************************
// * NtWaitForSingleObject
// ******************************************************************
XBSYSAPI EXPORTNUM(233) NTSTATUS NTAPI NtWaitForSingleObject
(	
	IN  HANDLE         Handle,
	IN	BOOLEAN	       Alertable,
	IN	PLARGE_INTEGER Timeout
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtWaitForSingleObjectEx
// ******************************************************************
XBSYSAPI EXPORTNUM(234) NTSTATUS NTAPI NtWaitForSingleObjectEx
(
    IN  HANDLE          Handle,
    IN  CHAR            WaitMode,
    IN  BOOLEAN         Alertable,
    IN  PLARGE_INTEGER  Timeout
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtWaitForMultipleObjectsEx
// ******************************************************************
XBSYSAPI EXPORTNUM(235) NTSTATUS NTAPI NtWaitForMultipleObjectsEx
(
    IN  ULONG           Count,
    IN  HANDLE         *Handles,
    IN  WAIT_TYPE       WaitType,
    IN  CHAR            WaitMode,
    IN  BOOLEAN         Alertable,
    IN  PLARGE_INTEGER  Timeout
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtWriteFile
// ******************************************************************
XBSYSAPI EXPORTNUM(236) NTSTATUS NTAPI NtWriteFile
(	
	IN  HANDLE          FileHandle,            // TODO: correct paramters
	IN	PVOID	        Event,
	IN	PVOID	        ApcRoutine,
	IN	PVOID	        ApcContext,
	OUT	PVOID	        IoStatusBlock,
	IN	PVOID	        Buffer,
	IN	ULONG	        Length,
	IN	PLARGE_INTEGER  ByteOffset
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * NtWriteFileGather
// ******************************************************************
XBSYSAPI EXPORTNUM(237) BOOLEAN NTAPI NtWriteFileGather
(
	IN	HANDLE			hFile,
	OUT	FILE_SEGMENT_ELEMENT	aSegmentArray[],
	IN	DWORD			nNumberOfBytesToWrite,
	OUT	LPDWORD			lpNumberOfBytesWritten,
	IN	LPOVERLAPPED		lpOverLapped
)
{
	return TRUE;
}

// ******************************************************************
// * NtYieldExecution
// ******************************************************************
XBSYSAPI EXPORTNUM(238) VOID NTAPI NtYieldExecution()
{
    return;
}
