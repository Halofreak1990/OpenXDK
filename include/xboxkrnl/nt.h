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
NTSYSAPI VOID *NtClose;
NTSYSAPI VOID *NtCreateDirectoryObject;
NTSYSAPI VOID *NtCreateEvent;
NTSYSAPI VOID *NtCreateFile;
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
NTSYSAPI VOID *NtReadFile;
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
NTSYSAPI VOID *NtWaitForSingleObject;
NTSYSAPI VOID *NtWaitForSingleObjectEx;
NTSYSAPI VOID *NtWaitForMultipleObjectsEx;
NTSYSAPI VOID *NtWriteFile;
NTSYSAPI VOID *NtWriteFileGather;
NTSYSAPI VOID *NtYieldExecution;

#endif


