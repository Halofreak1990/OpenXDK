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

XBOXSYSAPI VOID *KeAlertResumeThread = 0;
XBOXSYSAPI VOID *KeAlertThread = 0;
XBOXSYSAPI VOID *KeBoostPriorityThread = 0;
XBOXSYSAPI VOID *KeBugCheck = 0;
XBOXSYSAPI VOID *KeBugCheckEx = 0;
XBOXSYSAPI VOID *KeCancelTimer = 0;
XBOXSYSAPI VOID *KeConnectInterrupt = 0;
XBOXSYSAPI VOID *KeDelayExecutionThread = 0;
XBOXSYSAPI VOID *KeDisconnectInterrupt = 0;
XBOXSYSAPI VOID *KeEnterCriticalRegion = 0;
XBOXSYSAPI VOID *KeGetCurrentIrql = 0;
XBOXSYSAPI VOID *KeGetCurrentThread = 0;
XBOXSYSAPI VOID *KeInitializeApc = 0;
XBOXSYSAPI VOID *KeInitializeDeviceQueue = 0;
XBOXSYSAPI VOID *KeInitializeDpc = 0;
XBOXSYSAPI VOID *KeInitializeEvent = 0;
XBOXSYSAPI VOID *KeInitializeInterrupt = 0;
XBOXSYSAPI VOID *KeInitializeMutant = 0;
XBOXSYSAPI VOID *KeInitializeQueue = 0;
XBOXSYSAPI VOID *KeInitializeSemaphore = 0;
XBOXSYSAPI VOID *KeInitializeTimerEx = 0;
XBOXSYSAPI VOID *KeInsertByKeyDeviceQueue = 0;
XBOXSYSAPI VOID *KeInsertDeviceQueue = 0;
XBOXSYSAPI VOID *KeInsertHeadQueue = 0;
XBOXSYSAPI VOID *KeInsertQueue = 0;
XBOXSYSAPI VOID *KeInsertQueueApc = 0;
XBOXSYSAPI VOID *KeInsertQueueDpc = 0;
XBOXSYSAPI VOID *KeInterruptTime = 0;
XBOXSYSAPI VOID *KeIsExecutingDpc = 0;
XBOXSYSAPI VOID *KeLeaveCriticalRegion = 0;
XBOXSYSAPI VOID *KePulseEvent = 0;
XBOXSYSAPI VOID *KeQueryBasePriorityThread = 0;
XBOXSYSAPI VOID *KeQueryInterruptTime = 0;
XBOXSYSAPI VOID *KeQueryPerformanceCounter = 0;
XBOXSYSAPI VOID *KeQueryPerformanceFrequency = 0;
XBOXSYSAPI VOID *KeQuerySystemTime = 0;
XBOXSYSAPI VOID *KeRaiseIrqlToDpcLevel = 0;
XBOXSYSAPI VOID *KeRaiseIrqlToSynchLevel = 0;
XBOXSYSAPI VOID *KeReleaseMutant = 0;
XBOXSYSAPI VOID *KeReleaseSemaphore = 0;
XBOXSYSAPI VOID *KeRemoveByKeyDeviceQueue = 0;
XBOXSYSAPI VOID *KeRemoveDeviceQueue = 0;
XBOXSYSAPI VOID *KeRemoveEntryDeviceQueue = 0;
XBOXSYSAPI VOID *KeRemoveQueue = 0;
XBOXSYSAPI VOID *KeRemoveQueueDpc = 0;
XBOXSYSAPI VOID *KeResetEvent = 0;
XBOXSYSAPI VOID *KeRestoreFloatingPointState = 0;
XBOXSYSAPI VOID *KeResumeThread = 0;
XBOXSYSAPI VOID *KeRundownQueue = 0;
XBOXSYSAPI VOID *KeSaveFloatingPointState = 0;
XBOXSYSAPI VOID *KeSetBasePriorityThread = 0;
XBOXSYSAPI VOID *KeSetDisableBoostThread = 0;
XBOXSYSAPI VOID *KeSetEvent = 0;
XBOXSYSAPI VOID *KeSetEventBoostPriority = 0;
XBOXSYSAPI VOID *KeSetPriorityProcess = 0;
XBOXSYSAPI VOID *KeSetPriorityThread = 0;
XBOXSYSAPI VOID *KeSetTimer = 0;
XBOXSYSAPI VOID *KeSetTimerEx = 0;
XBOXSYSAPI VOID *KeStallExecutionProcessor = 0;
XBOXSYSAPI VOID *KeSuspendThread = 0;
XBOXSYSAPI VOID *KeSynchronizeExecution = 0;
XBOXSYSAPI VOID *KeSystemTime = 0;
XBOXSYSAPI VOID *KeTestAlertThread = 0;
XBOXSYSAPI VOID *KeTickCount = 0;
XBOXSYSAPI VOID *KeTimeIncrement = 0;
XBOXSYSAPI VOID *KeWaitForMultipleObjects = 0;
XBOXSYSAPI VOID *KeWaitForSingleObject = 0;
