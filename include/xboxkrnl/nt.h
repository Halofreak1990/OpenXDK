// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_nt.h
// *
// * note : XBox Kernel *NT* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_NT_H
#define XBOXKRNL_NT_H

NTSYSAPI VOID *NtAllocateVirtualMemory;
NTSYSAPI VOID *NtCancelTimer;
NTSYSAPI VOID *NtClearEvent;

// ******************************************************************
// * NtClose
// ******************************************************************
// *
// * Closes an object handle
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(187) ULONG NTAPI NtClose
(
	IN HANDLE Handle
);

NTSYSAPI VOID *NtCreateDirectoryObject;
NTSYSAPI VOID *NtCreateEvent;

// ******************************************************************
// * NtCreateFile
// ******************************************************************
// *
// * Causes a new file or directory to be created, or opens and
// * existing file, device, directory, or volume, giving the caller
// * a handle for the file object.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(190) NTSTATUS NTAPI NtCreateFile
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
);

NTSYSAPI VOID *NtCreateIoCompletion;
NTSYSAPI VOID *NtCreateMutant;
NTSYSAPI VOID *NtCreateSemaphore;
NTSYSAPI VOID *NtCreateTimer;
NTSYSAPI VOID *NtDeleteFile;
NTSYSAPI VOID *NtDeviceIoControlFile;
NTSYSAPI VOID *NtDuplicateObject;
NTSYSAPI VOID *NtFlushBuffersFile;
NTSYSAPI VOID *NtFreeVirtualMemory;
NTSYSAPI VOID *NtFsControlFile;
NTSYSAPI VOID *NtOpenDirectoryObject;
NTSYSAPI VOID *NtOpenFile;
NTSYSAPI VOID *NtOpenSymbolicLinkObject;
NTSYSAPI VOID *NtProtectVirtualMemory;
NTSYSAPI VOID *NtPulseEvent;
NTSYSAPI VOID *NtQueueApcThread;
NTSYSAPI VOID *NtQueryDirectoryFile;
NTSYSAPI VOID *NtQueryDirectoryObject;
NTSYSAPI VOID *NtQueryEvent;
NTSYSAPI VOID *NtQueryFullAttributesFile;

// ******************************************************************
// * NtQueryInformationFile
// ******************************************************************
// *
// * Return various kinds of information about a given file object.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(211) NTSTATUS NTAPI NtQueryInformationFile
(	
	IN  HANDLE FileHandle,          // TODO: improve parameter accuracy
	OUT PVOID  IoStatusBlock,
	OUT PVOID  FileInformation, 
	IN  ULONG  Length, 
	IN  ULONG  FileInfo
);

NTSYSAPI VOID *NtQueryIoCompletion;
NTSYSAPI VOID *NtQueryMutant;
NTSYSAPI VOID *NtQuerySemaphore;
NTSYSAPI VOID *NtQuerySymbolicLinkObject;
NTSYSAPI VOID *NtQueryTimer;
NTSYSAPI VOID *NtQueryVirtualMemory;
NTSYSAPI VOID *NtQueryVolumeInformationFile;

// ******************************************************************
// * NtReadFile
// ******************************************************************
// *
// * Read data from an opened file.
// *
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
);

NTSYSAPI VOID *NtReadFileScatter;
NTSYSAPI VOID *NtReleaseMutant;
NTSYSAPI VOID *NtReleaseSemaphore;
NTSYSAPI VOID *NtRemoveIoCompletion;
NTSYSAPI VOID *NtResumeThread;
NTSYSAPI VOID *NtSetEvent;

// ******************************************************************
// * NtSetInformationFile
// ******************************************************************
// *
// * Changes various kinds of information about a given file object.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(226) NTSTATUS NTAPI NtSetInformationFile
(	
	IN  HANDLE  FileHandle,            // TODO: correct paramters
	OUT	PVOID	IoStatusBlock,
	IN	PVOID	FileInformation,
	IN	ULONG	Length,
	IN	ULONG	FileInformationClass
);

NTSYSAPI VOID *NtSetIoCompletion;
NTSYSAPI VOID *NtSetSystemTime;
NTSYSAPI VOID *NtSetTimerEx;
NTSYSAPI VOID *NtSignalAndWaitForSingleObjectEx;
NTSYSAPI VOID *NtSuspendThread;
NTSYSAPI VOID *NtUserIoApcDispatcher;

// ******************************************************************
// * NtWaitForSingleObject
// ******************************************************************
// *
// * Put the current thread into a wait state until the given 
// * dispatcher object is set to a signaled state or (optionally) 
// * until the wait times out.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(233) NTSTATUS NTAPI NtWaitForSingleObject
(	
	IN  HANDLE  Handle,            // TODO: correct paramters
	IN	BOOLEAN	Alertable,
	IN	PVOID	Timeout
);

NTSYSAPI VOID *NtWaitForSingleObjectEx;
NTSYSAPI VOID *NtWaitForMultipleObjectsEx;

// ******************************************************************
// * NtWriteFile
// ******************************************************************
// *
// * Write data to an opened file.
// *
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
);

NTSYSAPI VOID *NtWriteFileGather;
NTSYSAPI VOID *NtYieldExecution;

#endif


