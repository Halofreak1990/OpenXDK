// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : nt.h
// *
// * note : XBox Kernel *NT* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_NT_H
#define XBOXKRNL_NT_H

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
);

XBSYSAPI VOID *NtCancelTimer;
XBSYSAPI VOID *NtClearEvent;

// ******************************************************************
// * NtClose
// ******************************************************************
// *
// * Closes an object handle
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(187) NTSTATUS NTAPI NtClose
(
	IN HANDLE Handle
);

XBSYSAPI VOID *NtCreateDirectoryObject;

// ******************************************************************
// * NtCreateEvent
// ******************************************************************
XBSYSAPI EXPORTNUM(189) NTSTATUS NTAPI NtCreateEvent
(
    OUT PHANDLE             EventHandle,
    IN  POBJECT_ATTRIBUTES  ObjectAttributes OPTIONAL,
    IN  EVENT_TYPE          EventType,
    IN  BOOLEAN             InitialState
);

// ******************************************************************
// * NtCreateFile
// ******************************************************************
// *
// * Causes a new file or directory to be created, or opens and
// * existing file, device, directory, or volume, giving the caller
// * a handle for the file object.
// *
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
);

XBSYSAPI VOID *NtCreateIoCompletion;
XBSYSAPI VOID *NtCreateMutant;
XBSYSAPI VOID *NtCreateSemaphore;
XBSYSAPI VOID *NtCreateTimer;
XBSYSAPI VOID *NtDeleteFile;
XBSYSAPI VOID *NtDeviceIoControlFile;
XBSYSAPI VOID *NtDuplicateObject;
XBSYSAPI VOID *NtFlushBuffersFile;

// ******************************************************************
// * NtFreeVirtualMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(199) NTSTATUS NtFreeVirtualMemory
(
    IN OUT PVOID *BaseAddress,
    IN OUT PULONG FreeSize,
    IN ULONG      FreeType
);

XBSYSAPI VOID *NtFsControlFile;
XBSYSAPI VOID *NtOpenDirectoryObject;

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
);

XBSYSAPI VOID *NtOpenSymbolicLinkObject;
XBSYSAPI VOID *NtProtectVirtualMemory;
XBSYSAPI VOID *NtPulseEvent;
XBSYSAPI VOID *NtQueueApcThread;
XBSYSAPI VOID *NtQueryDirectoryFile;
XBSYSAPI VOID *NtQueryDirectoryObject;
XBSYSAPI VOID *NtQueryEvent;
XBSYSAPI VOID *NtQueryFullAttributesFile;

// ******************************************************************
// * NtQueryInformationFile
// ******************************************************************
// *
// * Return various kinds of information about a given file object.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(211) NTSTATUS NTAPI NtQueryInformationFile
(   
    IN  HANDLE                      FileHandle,
    OUT PIO_STATUS_BLOCK            IoStatusBlock,
    OUT PFILE_FS_SIZE_INFORMATION   FileInformation, 
    IN  ULONG                       Length, 
    IN  FILE_INFORMATION_CLASS      FileInfo
);

XBSYSAPI VOID *NtQueryIoCompletion;
XBSYSAPI VOID *NtQueryMutant;
XBSYSAPI VOID *NtQuerySemaphore;
XBSYSAPI VOID *NtQuerySymbolicLinkObject;
XBSYSAPI VOID *NtQueryTimer;
XBSYSAPI VOID *NtQueryVirtualMemory;

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
);

// ******************************************************************
// * NtReadFile
// ******************************************************************
// *
// * Read data from an opened file.
// *
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
);

XBSYSAPI VOID *NtReadFileScatter;
XBSYSAPI VOID *NtReleaseMutant;
XBSYSAPI VOID *NtReleaseSemaphore;
XBSYSAPI VOID *NtRemoveIoCompletion;
XBSYSAPI VOID *NtResumeThread;
XBSYSAPI VOID *NtSetEvent;

// ******************************************************************
// * NtSetInformationFile
// ******************************************************************
// *
// * Changes various kinds of information about a given file object.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(226) NTSTATUS NTAPI NtSetInformationFile
(	
	IN  HANDLE  FileHandle,            // TODO: correct paramters
	OUT	PVOID	IoStatusBlock,
	IN	PVOID	FileInformation,
	IN	ULONG	Length,
	IN	ULONG	FileInformationClass
);

XBSYSAPI VOID *NtSetIoCompletion;
XBSYSAPI VOID *NtSetSystemTime;
XBSYSAPI VOID *NtSetTimerEx;
XBSYSAPI VOID *NtSignalAndWaitForSingleObjectEx;
XBSYSAPI VOID *NtSuspendThread;
XBSYSAPI VOID *NtUserIoApcDispatcher;

// ******************************************************************
// * NtWaitForSingleObject
// ******************************************************************
// *
// * Put the current thread into a wait state until the given 
// * dispatcher object is set to a signaled state or (optionally) 
// * until the wait times out.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(233) NTSTATUS NTAPI NtWaitForSingleObject
(	
	IN  HANDLE  Handle,            // TODO: correct paramters
	IN	BOOLEAN	Alertable,
	IN	PVOID	Timeout
);

XBSYSAPI VOID *NtWaitForSingleObjectEx;
XBSYSAPI VOID *NtWaitForMultipleObjectsEx;

// ******************************************************************
// * NtWriteFile
// ******************************************************************
// *
// * Write data to an opened file.
// *
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
);

XBSYSAPI VOID *NtWriteFileGather;
XBSYSAPI VOID *NtYieldExecution;

#endif


