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

XBOXSYSAPI VOID *NtAllocateVirtualMemory;
XBOXSYSAPI VOID *NtCancelTimer;
XBOXSYSAPI VOID *NtClearEvent;
XBOXSYSAPI VOID *NtClose;
XBOXSYSAPI VOID *NtCreateDirectoryObject;
XBOXSYSAPI VOID *NtCreateEvent;
XBOXSYSAPI VOID *NtCreateFile;
XBOXSYSAPI VOID *NtCreateIoCompletion;
XBOXSYSAPI VOID *NtCreateMutant;
XBOXSYSAPI VOID *NtCreateSemaphore;
XBOXSYSAPI VOID *NtCreateTimer;
XBOXSYSAPI VOID *NtDeleteFile;
XBOXSYSAPI VOID *NtDeviceIoControlFile;
XBOXSYSAPI VOID *NtDuplicateObject;
XBOXSYSAPI VOID *NtFlushBuffersFile;
XBOXSYSAPI VOID *NtFreeVirtualMemory;
XBOXSYSAPI VOID *NtFsControlFile;
XBOXSYSAPI VOID *NtOpenDirectoryObject;
XBOXSYSAPI VOID *NtOpenFile;
XBOXSYSAPI VOID *NtOpenSymbolicLinkObject;
XBOXSYSAPI VOID *NtProtectVirtualMemory;
XBOXSYSAPI VOID *NtPulseEvent;
XBOXSYSAPI VOID *NtQueueApcThread;
XBOXSYSAPI VOID *NtQueryDirectoryFile;
XBOXSYSAPI VOID *NtQueryDirectoryObject;
XBOXSYSAPI VOID *NtQueryEvent;
XBOXSYSAPI VOID *NtQueryFullAttributesFile;
XBOXSYSAPI VOID *NtQueryInformationFile;
XBOXSYSAPI VOID *NtQueryIoCompletion;
XBOXSYSAPI VOID *NtQueryMutant;
XBOXSYSAPI VOID *NtQuerySemaphore;
XBOXSYSAPI VOID *NtQuerySymbolicLinkObject;
XBOXSYSAPI VOID *NtQueryTimer;
XBOXSYSAPI VOID *NtQueryVirtualMemory;
XBOXSYSAPI VOID *NtQueryVolumeInformationFile;
XBOXSYSAPI VOID *NtReadFile;
XBOXSYSAPI VOID *NtReadFileScatter;
XBOXSYSAPI VOID *NtReleaseMutant;
XBOXSYSAPI VOID *NtReleaseSemaphore;
XBOXSYSAPI VOID *NtRemoveIoCompletion;
XBOXSYSAPI VOID *NtResumeThread;
XBOXSYSAPI VOID *NtSetEvent;
XBOXSYSAPI VOID *NtSetInformationFile;
XBOXSYSAPI VOID *NtSetIoCompletion;
XBOXSYSAPI VOID *NtSetSystemTime;
XBOXSYSAPI VOID *NtSetTimerEx;
XBOXSYSAPI VOID *NtSignalAndWaitForSingleObjectEx;
XBOXSYSAPI VOID *NtSuspendThread;
XBOXSYSAPI VOID *NtUserIoApcDispatcher;
XBOXSYSAPI VOID *NtWaitForSingleObject;
XBOXSYSAPI VOID *NtWaitForSingleObjectEx;
XBOXSYSAPI VOID *NtWaitForMultipleObjectsEx;
XBOXSYSAPI VOID *NtWriteFile;
XBOXSYSAPI VOID *NtWriteFileGather;
XBOXSYSAPI VOID *NtYieldExecution;

#endif