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

XBOXSYSAPI VOID *NtAllocateVirtualMemory = 0;
XBOXSYSAPI VOID *NtCancelTimer = 0;
XBOXSYSAPI VOID *NtClearEvent = 0;
XBOXSYSAPI VOID *NtClose = 0;
XBOXSYSAPI VOID *NtCreateDirectoryObject = 0;
XBOXSYSAPI VOID *NtCreateEvent = 0;
XBOXSYSAPI VOID *NtCreateFile = 0;
XBOXSYSAPI VOID *NtCreateIoCompletion = 0;
XBOXSYSAPI VOID *NtCreateMutant = 0;
XBOXSYSAPI VOID *NtCreateSemaphore = 0;
XBOXSYSAPI VOID *NtCreateTimer = 0;
XBOXSYSAPI VOID *NtDeleteFile = 0;
XBOXSYSAPI VOID *NtDeviceIoControlFile = 0;
XBOXSYSAPI VOID *NtDuplicateObject = 0;
XBOXSYSAPI VOID *NtFlushBuffersFile = 0;
XBOXSYSAPI VOID *NtFreeVirtualMemory = 0;
XBOXSYSAPI VOID *NtFsControlFile = 0;
XBOXSYSAPI VOID *NtOpenDirectoryObject = 0;
XBOXSYSAPI VOID *NtOpenFile = 0;
XBOXSYSAPI VOID *NtOpenSymbolicLinkObject = 0;
XBOXSYSAPI VOID *NtProtectVirtualMemory = 0;
XBOXSYSAPI VOID *NtPulseEvent = 0;
XBOXSYSAPI VOID *NtQueueApcThread = 0;
XBOXSYSAPI VOID *NtQueryDirectoryFile = 0;
XBOXSYSAPI VOID *NtQueryDirectoryObject = 0;
XBOXSYSAPI VOID *NtQueryEvent = 0;
XBOXSYSAPI VOID *NtQueryFullAttributesFile = 0;
XBOXSYSAPI VOID *NtQueryInformationFile = 0;
XBOXSYSAPI VOID *NtQueryIoCompletion = 0;
XBOXSYSAPI VOID *NtQueryMutant = 0;
XBOXSYSAPI VOID *NtQuerySemaphore = 0;
XBOXSYSAPI VOID *NtQuerySymbolicLinkObject = 0;
XBOXSYSAPI VOID *NtQueryTimer = 0;
XBOXSYSAPI VOID *NtQueryVirtualMemory = 0;
XBOXSYSAPI VOID *NtQueryVolumeInformationFile = 0;
XBOXSYSAPI VOID *NtReadFile = 0;
XBOXSYSAPI VOID *NtReadFileScatter = 0;
XBOXSYSAPI VOID *NtReleaseMutant = 0;
XBOXSYSAPI VOID *NtReleaseSemaphore = 0;
XBOXSYSAPI VOID *NtRemoveIoCompletion = 0;
XBOXSYSAPI VOID *NtResumeThread = 0;
XBOXSYSAPI VOID *NtSetEvent = 0;
XBOXSYSAPI VOID *NtSetInformationFile = 0;
XBOXSYSAPI VOID *NtSetIoCompletion = 0;
XBOXSYSAPI VOID *NtSetSystemTime = 0;
XBOXSYSAPI VOID *NtSetTimerEx = 0;
XBOXSYSAPI VOID *NtSignalAndWaitForSingleObjectEx = 0;
XBOXSYSAPI VOID *NtSuspendThread = 0;
XBOXSYSAPI VOID *NtUserIoApcDispatcher = 0;
XBOXSYSAPI VOID *NtWaitForSingleObject = 0;
XBOXSYSAPI VOID *NtWaitForSingleObjectEx = 0;
XBOXSYSAPI VOID *NtWaitForMultipleObjectsEx = 0;
XBOXSYSAPI VOID *NtWriteFile = 0;
XBOXSYSAPI VOID *NtWriteFileGather = 0;
XBOXSYSAPI VOID *NtYieldExecution = 0;
