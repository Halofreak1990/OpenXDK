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
// * XboxKrnlEntryDummy
// ******************************************************************
XBSYSAPI VOID XboxKrnlEntryDummy()
{
}

XBSYSAPI VOID *KeAlertResumeThread = 0;
XBSYSAPI VOID *KeAlertThread = 0;
XBSYSAPI VOID *KeBoostPriorityThread = 0;
XBSYSAPI VOID *KeBugCheck = 0;
XBSYSAPI VOID *KeBugCheckEx = 0;
XBSYSAPI VOID *KeCancelTimer = 0;
XBSYSAPI VOID *KeConnectInterrupt = 0;

// ******************************************************************
// * KeDelayExecutionThread
// ******************************************************************
XBSYSAPI EXPORTNUM(99) NTSTATUS NTAPI KeDelayExecutionThread
(
    IN KPROCESSOR_MODE  WaitMode,
    IN BOOLEAN          Alertable,
    IN PLARGE_INTEGER   Interval
)
{
    return STATUS_SUCCESS;
}

XBSYSAPI VOID *KeDisconnectInterrupt = 0;
XBSYSAPI VOID *KeEnterCriticalRegion = 0;
XBSYSAPI VOID *KeGetCurrentIrql = 0;
XBSYSAPI VOID *KeGetCurrentThread = 0;
XBSYSAPI VOID *KeInitializeApc = 0;
XBSYSAPI VOID *KeInitializeDeviceQueue = 0;

// ******************************************************************
// * KeInitializeDpc
// ******************************************************************
XBSYSAPI EXPORTNUM(107) VOID NTAPI KeInitializeDpc
(
    KDPC                *Dpc,
    PKDEFERRED_ROUTINE   DeferredRoutine,
    PVOID                DeferredContext
)
{
    return;
}

XBSYSAPI VOID *KeInitializeEvent = 0;
XBSYSAPI VOID *KeInitializeInterrupt = 0;
XBSYSAPI VOID *KeInitializeMutant = 0;
XBSYSAPI VOID *KeInitializeQueue = 0;
XBSYSAPI VOID *KeInitializeSemaphore = 0;

// ******************************************************************
// * KeInitializeTimerEx
// ******************************************************************
XBSYSAPI EXPORTNUM(113) VOID NTAPI KeInitializeTimerEx
(
    IN PKTIMER      Timer,
    IN TIMER_TYPE   Type
)
{
    return;
}

XBSYSAPI VOID *KeInsertByKeyDeviceQueue = 0;
XBSYSAPI VOID *KeInsertDeviceQueue = 0;
XBSYSAPI VOID *KeInsertHeadQueue = 0;
XBSYSAPI VOID *KeInsertQueue = 0;
XBSYSAPI VOID *KeInsertQueueApc = 0;
XBSYSAPI VOID *KeInsertQueueDpc = 0;
XBSYSAPI VOID *KeInterruptTime = 0;
XBSYSAPI VOID *KeIsExecutingDpc = 0;
XBSYSAPI VOID *KeLeaveCriticalRegion = 0;
XBSYSAPI VOID *KePulseEvent = 0;
XBSYSAPI VOID *KeQueryBasePriorityThread = 0;
XBSYSAPI VOID *KeQueryInterruptTime = 0;

// ******************************************************************
// * KeQueryPerformanceCounter
// ******************************************************************
XBSYSAPI EXPORTNUM(126) ULONGLONG NTAPI KeQueryPerformanceCounter()
{
    return 0;
}

// ******************************************************************
// * KeQueryPerformanceFrequency
// ******************************************************************
XBSYSAPI EXPORTNUM(127) ULONGLONG NTAPI KeQueryPerformanceFrequency()
{
    return 0;
}

// ******************************************************************
// * KeQuerySystemTime
// ******************************************************************
XBSYSAPI EXPORTNUM(128) VOID NTAPI KeQuerySystemTime
(
    PLARGE_INTEGER CurrentTime
)
{
    return;
}

XBSYSAPI VOID *KeRaiseIrqlToDpcLevel = 0;
XBSYSAPI VOID *KeRaiseIrqlToSynchLevel = 0;
XBSYSAPI VOID *KeReleaseMutant = 0;
XBSYSAPI VOID *KeReleaseSemaphore = 0;
XBSYSAPI VOID *KeRemoveByKeyDeviceQueue = 0;
XBSYSAPI VOID *KeRemoveDeviceQueue = 0;
XBSYSAPI VOID *KeRemoveEntryDeviceQueue = 0;
XBSYSAPI VOID *KeRemoveQueue = 0;
XBSYSAPI VOID *KeRemoveQueueDpc = 0;
XBSYSAPI VOID *KeResetEvent = 0;
XBSYSAPI VOID *KeRestoreFloatingPointState = 0;
XBSYSAPI VOID *KeResumeThread = 0;
XBSYSAPI VOID *KeRundownQueue = 0;
XBSYSAPI VOID *KeSaveFloatingPointState = 0;


//XBSYSAPI VOID *KeSetBasePriorityThread = 0;
XBSYSAPI EXPORTNUM(143) BOOLEAN NTAPI KeSetBasePriorityThread
(
    IN PKTHREAD  Thread,
    IN PVOID  Priority
)
{
	return TRUE;
}


XBSYSAPI VOID *KeSetDisableBoostThread = 0;
XBSYSAPI VOID *KeSetEvent = 0;
XBSYSAPI VOID *KeSetEventBoostPriority = 0;
XBSYSAPI VOID *KeSetPriorityProcess = 0;



//XBSYSAPI VOID *KeSetPriorityThread = 0;
XBSYSAPI EXPORTNUM(148) BOOLEAN NTAPI KeSetPriorityThread
(
    IN PKTHREAD  Thread,
    IN PVOID  Priority
)
{
	return TRUE;
}


// ******************************************************************
// * KeSetTimer
// ******************************************************************
XBSYSAPI EXPORTNUM(149) BOOLEAN NTAPI KeSetTimer
(
    IN PKTIMER        Timer,
    IN LARGE_INTEGER  DueTime,
    IN PKDPC          Dpc OPTIONAL
)
{
    return TRUE;
}

XBSYSAPI VOID *KeSetTimerEx = 0;
XBSYSAPI VOID *KeStallExecutionProcessor = 0;
XBSYSAPI VOID *KeSuspendThread = 0;
XBSYSAPI VOID *KeSynchronizeExecution = 0;
XBSYSAPI VOID *KeSystemTime = 0;
XBSYSAPI VOID *KeTestAlertThread = 0;

// ******************************************************************
// * KeTickCount
// ******************************************************************
XBSYSAPI EXPORTNUM(156) volatile DWORD KeTickCount = 0;

XBSYSAPI VOID *KeTimeIncrement = 0;
XBSYSAPI VOID *KeWaitForMultipleObjects = 0;
XBSYSAPI VOID *KeWaitForSingleObject = 0;
