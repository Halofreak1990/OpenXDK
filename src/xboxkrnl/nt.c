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
NTSYSAPI VOID *NtClose = 0;
NTSYSAPI VOID *NtCreateDirectoryObject = 0;
NTSYSAPI VOID *NtCreateEvent = 0;
NTSYSAPI VOID *NtCreateFile = 0;
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
NTSYSAPI VOID *NtQueryInformationFile = 0;
NTSYSAPI VOID *NtQueryIoCompletion = 0;
NTSYSAPI VOID *NtQueryMutant = 0;
NTSYSAPI VOID *NtQuerySemaphore = 0;
NTSYSAPI VOID *NtQuerySymbolicLinkObject = 0;
NTSYSAPI VOID *NtQueryTimer = 0;
NTSYSAPI VOID *NtQueryVirtualMemory = 0;
NTSYSAPI VOID *NtQueryVolumeInformationFile = 0;
NTSYSAPI VOID *NtReadFile = 0;
NTSYSAPI VOID *NtReadFileScatter = 0;
NTSYSAPI VOID *NtReleaseMutant = 0;
NTSYSAPI VOID *NtReleaseSemaphore = 0;
NTSYSAPI VOID *NtRemoveIoCompletion = 0;
NTSYSAPI VOID *NtResumeThread = 0;
NTSYSAPI VOID *NtSetEvent = 0;
NTSYSAPI VOID *NtSetInformationFile = 0;
NTSYSAPI VOID *NtSetIoCompletion = 0;
NTSYSAPI VOID *NtSetSystemTime = 0;
NTSYSAPI VOID *NtSetTimerEx = 0;
NTSYSAPI VOID *NtSignalAndWaitForSingleObjectEx = 0;
NTSYSAPI VOID *NtSuspendThread = 0;
NTSYSAPI VOID *NtUserIoApcDispatcher = 0;
NTSYSAPI VOID *NtWaitForSingleObject = 0;
NTSYSAPI VOID *NtWaitForSingleObjectEx = 0;
NTSYSAPI VOID *NtWaitForMultipleObjectsEx = 0;
NTSYSAPI VOID *NtWriteFile = 0;
NTSYSAPI VOID *NtWriteFileGather = 0;
NTSYSAPI VOID *NtYieldExecution = 0;
