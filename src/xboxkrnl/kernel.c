// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : kernel.c
// *
// * note : XBox Kernel Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

// ******************************************************************
// * EntryDummy
// ******************************************************************
void EntryDummy()
{
}

NTSYSAPI VOID *KeAlertResumeThread = 0;
NTSYSAPI VOID *KeAlertThread = 0;
NTSYSAPI VOID *KeBoostPriorityThread = 0;
NTSYSAPI VOID *KeBugCheck = 0;
NTSYSAPI VOID *KeBugCheckEx = 0;
NTSYSAPI VOID *KeCancelTimer = 0;
NTSYSAPI VOID *KeConnectInterrupt = 0;
NTSYSAPI VOID *KeDelayExecutionThread = 0;
NTSYSAPI VOID *KeDisconnectInterrupt = 0;
NTSYSAPI VOID *KeEnterCriticalRegion = 0;
NTSYSAPI VOID *KeGetCurrentIrql = 0;
NTSYSAPI VOID *KeGetCurrentThread = 0;
NTSYSAPI VOID *KeInitializeApc = 0;
NTSYSAPI VOID *KeInitializeDeviceQueue = 0;
NTSYSAPI VOID *KeInitializeDpc = 0;
NTSYSAPI VOID *KeInitializeEvent = 0;
NTSYSAPI VOID *KeInitializeInterrupt = 0;
NTSYSAPI VOID *KeInitializeMutant = 0;
NTSYSAPI VOID *KeInitializeQueue = 0;
NTSYSAPI VOID *KeInitializeSemaphore = 0;
NTSYSAPI VOID *KeInitializeTimerEx = 0;
NTSYSAPI VOID *KeInsertByKeyDeviceQueue = 0;
NTSYSAPI VOID *KeInsertDeviceQueue = 0;
NTSYSAPI VOID *KeInsertHeadQueue = 0;
NTSYSAPI VOID *KeInsertQueue = 0;
NTSYSAPI VOID *KeInsertQueueApc = 0;
NTSYSAPI VOID *KeInsertQueueDpc = 0;
NTSYSAPI VOID *KeInterruptTime = 0;
NTSYSAPI VOID *KeIsExecutingDpc = 0;
NTSYSAPI VOID *KeLeaveCriticalRegion = 0;
NTSYSAPI VOID *KePulseEvent = 0;
NTSYSAPI VOID *KeQueryBasePriorityThread = 0;
NTSYSAPI VOID *KeQueryInterruptTime = 0;
NTSYSAPI VOID *KeQueryPerformanceCounter = 0;
NTSYSAPI VOID *KeQueryPerformanceFrequency = 0;
NTSYSAPI VOID *KeQuerySystemTime = 0;
NTSYSAPI VOID *KeRaiseIrqlToDpcLevel = 0;
NTSYSAPI VOID *KeRaiseIrqlToSynchLevel = 0;
NTSYSAPI VOID *KeReleaseMutant = 0;
NTSYSAPI VOID *KeReleaseSemaphore = 0;
NTSYSAPI VOID *KeRemoveByKeyDeviceQueue = 0;
NTSYSAPI VOID *KeRemoveDeviceQueue = 0;
NTSYSAPI VOID *KeRemoveEntryDeviceQueue = 0;
NTSYSAPI VOID *KeRemoveQueue = 0;
NTSYSAPI VOID *KeRemoveQueueDpc = 0;
NTSYSAPI VOID *KeResetEvent = 0;
NTSYSAPI VOID *KeRestoreFloatingPointState = 0;
NTSYSAPI VOID *KeResumeThread = 0;
NTSYSAPI VOID *KeRundownQueue = 0;
NTSYSAPI VOID *KeSaveFloatingPointState = 0;
NTSYSAPI VOID *KeSetBasePriorityThread = 0;
NTSYSAPI VOID *KeSetDisableBoostThread = 0;
NTSYSAPI VOID *KeSetEvent = 0;
NTSYSAPI VOID *KeSetEventBoostPriority = 0;
NTSYSAPI VOID *KeSetPriorityProcess = 0;
NTSYSAPI VOID *KeSetPriorityThread = 0;
NTSYSAPI VOID *KeSetTimer = 0;
NTSYSAPI VOID *KeSetTimerEx = 0;
NTSYSAPI VOID *KeStallExecutionProcessor = 0;
NTSYSAPI VOID *KeSuspendThread = 0;
NTSYSAPI VOID *KeSynchronizeExecution = 0;
NTSYSAPI VOID *KeSystemTime = 0;
NTSYSAPI VOID *KeTestAlertThread = 0;

// ******************************************************************
// * KeTickCount
// ******************************************************************
NTSYSAPI EXPORTNUM(156) DWORD KeTickCount = 0;

NTSYSAPI VOID *KeTimeIncrement = 0;
NTSYSAPI VOID *KeWaitForMultipleObjects = 0;
NTSYSAPI VOID *KeWaitForSingleObject = 0;
