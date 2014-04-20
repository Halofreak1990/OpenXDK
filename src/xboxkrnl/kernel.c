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

XBSYSAPI EXPORTNUM(92) VOID *KeAlertResumeThread = 0;
XBSYSAPI EXPORTNUM(93) VOID *KeAlertThread = 0;
XBSYSAPI EXPORTNUM(94) VOID *KeBoostPriorityThread = 0;

// ******************************************************************
// * KeBugCheck
// ******************************************************************
XBSYSAPI EXPORTNUM(95) VOID NTAPI KeBugCheck
(
	IN ULONG BugCheckCode
)
{
	return;
}

// ******************************************************************
// * KeBugCheckEx
// ******************************************************************
XBSYSAPI EXPORTNUM(96) VOID NTAPI KeBugCheckEx
(
	IN ULONG	BugCheckCode,
	IN ULONG_PTR	BugCheckParameter1,
	IN ULONG_PTR	BugCheckParameter2,
	IN ULONG_PTR	BugCheckParameter3,
	IN ULONG_PTR	BugCheckParameter4
)
{
	return;
}

XBSYSAPI EXPORTNUM(97) VOID *KeCancelTimer = 0;

// ******************************************************************
// * KeConnectInterrupt
// ******************************************************************
XBSYSAPI EXPORTNUM(98) NTSTATUS NTAPI KeConnectInterrupt
(
    IN PKINTERRUPT  InterruptObject
)
{
	return STATUS_SUCCESS;
}

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

// ******************************************************************
// * KeDisconnectInterrupt
// ******************************************************************
XBSYSAPI EXPORTNUM(100) VOID NTAPI KeDisconnectInterrupt
(
    IN PKINTERRUPT  InterruptObject
)
{
	return;
}

// ******************************************************************
// * KeEnterCriticalRegion
// ******************************************************************
XBSYSAPI EXPORTNUM(101) VOID NTAPI KeEnterCriticalRegion()
{
	return;
}

XBSYSAPI EXPORTNUM(103) VOID *KeGetCurrentIrql = 0;

// ******************************************************************
// * KeGetCurrentThread
// ******************************************************************
XBSYSAPI EXPORTNUM(104) PKTHREAD *KeGetCurrentThread()
{
	return NULL;
}

XBSYSAPI EXPORTNUM(105) VOID *KeInitializeApc = 0;
XBSYSAPI EXPORTNUM(106) VOID *KeInitializeDeviceQueue = 0;

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

XBSYSAPI EXPORTNUM(108) VOID *KeInitializeEvent = 0;

// ******************************************************************
// * KeInitializeInterrupt
// ******************************************************************

XBSYSAPI EXPORTNUM(109) VOID NTAPI KeInitializeInterrupt
(
    OUT PKINTERRUPT Interrupt,
    IN PKSERVICE_ROUTINE ServiceRoutine,
    IN PVOID ServiceContext,
    IN ULONG Vector,
    IN KIRQL Irql,
    IN KINTERRUPT_MODE InterruptMode,
    IN BOOLEAN ShareVector
)
{
    return;
}

XBSYSAPI EXPORTNUM(110) VOID *KeInitializeMutant = 0;
XBSYSAPI EXPORTNUM(111) VOID *KeInitializeQueue = 0;
XBSYSAPI EXPORTNUM(112) VOID *KeInitializeSemaphore = 0;

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

XBSYSAPI EXPORTNUM(114) VOID *KeInsertByKeyDeviceQueue = 0;
XBSYSAPI EXPORTNUM(115) VOID *KeInsertDeviceQueue = 0;
XBSYSAPI EXPORTNUM(116) VOID *KeInsertHeadQueue = 0;
XBSYSAPI EXPORTNUM(117) VOID *KeInsertQueue = 0;
XBSYSAPI EXPORTNUM(118) VOID *KeInsertQueueApc = 0;

// ******************************************************************
// * KeInsertQueueDpc
// ******************************************************************
XBSYSAPI EXPORTNUM(119) BOOLEAN NTAPI KeInsertQueueDpc
(
    IN PKDPC        Dpc,
    IN PVOID        SystemArgument1,
    IN PVOID        SystemArgument2
)
{
    return TRUE;
}

XBSYSAPI EXPORTNUM(120) VOID *KeInterruptTime = 0;
XBSYSAPI EXPORTNUM(121) VOID *KeIsExecutingDpc = 0;

// ******************************************************************
// * KeLeaveCriticalRegion
// ******************************************************************
XBSYSAPI EXPORTNUM(122) VOID NTAPI KeLeaveCriticalRegion()
{
	return;
}

XBSYSAPI EXPORTNUM(123) VOID *KePulseEvent = 0;
XBSYSAPI EXPORTNUM(124) VOID *KeQueryBasePriorityThread = 0;
XBSYSAPI EXPORTNUM(125) VOID *KeQueryInterruptTime = 0;

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

// ******************************************************************
// * KeRaiseIrqlToDpcLevel
// ******************************************************************
XBSYSAPI EXPORTNUM(129) KIRQL NTAPI KeRaiseIrqlToDpcLevel()
{
	return 0;
}

XBSYSAPI EXPORTNUM(130) VOID *KeRaiseIrqlToSynchLevel = 0;
XBSYSAPI EXPORTNUM(131) VOID *KeReleaseMutant = 0;
XBSYSAPI EXPORTNUM(132) VOID *KeReleaseSemaphore = 0;
XBSYSAPI EXPORTNUM(133) VOID *KeRemoveByKeyDeviceQueue = 0;
XBSYSAPI EXPORTNUM(134) VOID *KeRemoveDeviceQueue = 0;
XBSYSAPI EXPORTNUM(135) VOID *KeRemoveEntryDeviceQueue = 0;
XBSYSAPI EXPORTNUM(136) VOID *KeRemoveQueue = 0;
XBSYSAPI EXPORTNUM(137) VOID *KeRemoveQueueDpc = 0;
XBSYSAPI EXPORTNUM(138) VOID *KeResetEvent = 0;

// ******************************************************************
// * KeRestoreFloatingPointState
// ******************************************************************
XBSYSAPI EXPORTNUM(139) VOID NTAPI KeRestoreFloatingPointState()
{
	return;
}

// ******************************************************************
// * KeResumeThread
// ******************************************************************
XBSYSAPI EXPORTNUM(140) DWORD NTAPI KeResumeThread
(
	IN  HANDLE    hThread
)
{
	return;
}

XBSYSAPI EXPORTNUM(141) VOID *KeRundownQueue = 0;

// ******************************************************************
// * KeRestoreFloatingPointState
// ******************************************************************
XBSYSAPI EXPORTNUM(142) VOID NTAPI KeSaveFloatingPointState()
{
	return;
}

// ******************************************************************
// * KeSetBasePriorityThread
// ******************************************************************
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

// ******************************************************************
// * KeSetPriorityThread
// ******************************************************************
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

// ******************************************************************
// * KeStallExecutionProcessor
// ******************************************************************
XBSYSAPI EXPORTNUM(151) VOID NTAPI KeStallExecutionProcessor
(
    IN ULONG          Microseconds
)
{
    return;
}

// ******************************************************************
// * KeSuspendThread
// ******************************************************************
XBSYSAPI EXPORTNUM(152) DWORD NTAPI KeSuspendThread
(
	IN	HANDLE	hThread
)
{
	return;
}

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

