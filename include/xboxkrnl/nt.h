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

NTSYSAPI EXPORTNUM(187) ULONG NTAPI NtClose
(
	IN	void**		 FileHandle
);

//NTSYSAPI VOID *NtClose;
NTSYSAPI VOID *NtCreateDirectoryObject;
NTSYSAPI VOID *NtCreateEvent;

NTSYSAPI EXPORTNUM(190) ULONG NTAPI NtCreateFile
(
	IN	void**		 FileHandle, 
	IN	unsigned long DesiredAccess, 
	IN	PVOID	ObjectAttributes, 
	IN	PVOID	IoStatusBlock, 
	IN	PVOID	AllocationSize, 
	IN	ULONG	FileAttributes, 
	IN	ULONG	ShareAccess, 
	IN	ULONG	CreateDisposition, 
	IN	ULONG	CreateOptions 
);
//NTSYSAPI VOID *NtCreateFile;
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
NTSYSAPI VOID *NtQueryInformationFile;
NTSYSAPI VOID *NtQueryIoCompletion;
NTSYSAPI VOID *NtQueryMutant;
NTSYSAPI VOID *NtQuerySemaphore;
NTSYSAPI VOID *NtQuerySymbolicLinkObject;
NTSYSAPI VOID *NtQueryTimer;
NTSYSAPI VOID *NtQueryVirtualMemory;
NTSYSAPI VOID *NtQueryVolumeInformationFile;


NTSYSAPI EXPORTNUM(219) ULONG NTAPI NtReadFile
(
	IN	PVOID	Handle,
	IN	PVOID	Event,
	IN	PVOID	CALLBACK,
	IN	PVOID	Context,
	IN	PVOID	IoStatusBlock,
	IN	PVOID	Buffer,
	IN	ULONG	nNumberOfBytesToRead,
	IN	PVOID	Offset
);
//NTSYSAPI VOID *NtReadFile;
NTSYSAPI VOID *NtReadFileScatter;
NTSYSAPI VOID *NtReleaseMutant;
NTSYSAPI VOID *NtReleaseSemaphore;
NTSYSAPI VOID *NtRemoveIoCompletion;
NTSYSAPI VOID *NtResumeThread;
NTSYSAPI VOID *NtSetEvent;
NTSYSAPI VOID *NtSetInformationFile;
NTSYSAPI VOID *NtSetIoCompletion;
NTSYSAPI VOID *NtSetSystemTime;
NTSYSAPI VOID *NtSetTimerEx;
NTSYSAPI VOID *NtSignalAndWaitForSingleObjectEx;
NTSYSAPI VOID *NtSuspendThread;
NTSYSAPI VOID *NtUserIoApcDispatcher;

NTSYSAPI EXPORTNUM(233) ULONG NTAPI NtWaitForSingleObject
(	
	IN	PVOID	Handle,
	IN	PVOID	Alert,
	IN	PVOID	Timeout
);
//NTSYSAPI VOID *NtWaitForSingleObject;
NTSYSAPI VOID *NtWaitForSingleObjectEx;
NTSYSAPI VOID *NtWaitForMultipleObjectsEx;
NTSYSAPI VOID *NtWriteFile;
NTSYSAPI VOID *NtWriteFileGather;
NTSYSAPI VOID *NtYieldExecution;

#endif


