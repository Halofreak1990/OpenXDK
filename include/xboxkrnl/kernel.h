// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : kernel.h
// *
// * note : XBox Kernel Declarations
// *
// ******************************************************************
#ifndef KERNEL_H
#define KERNEL_H

#include "xboxkrnl.h"

XBSYSAPI EXPORTNUM(92) VOID *KeAlertResumeThread;
XBSYSAPI EXPORTNUM(93) VOID *KeAlertThread;
XBSYSAPI EXPORTNUM(94) VOID *KeBoostPriorityThread;

// ******************************************************************
// * KeBugCheck
// ******************************************************************
XBSYSAPI EXPORTNUM(95) VOID NTAPI KeBugCheck
(
    IN ULONG BugCheckCode
);

// ******************************************************************
// * KeBugCheckEx
// ******************************************************************
XBSYSAPI EXPORTNUM(96) VOID NTAPI KeBugCheckEx
(
    IN ULONG        BugCheckCode,
    IN ULONG_PTR    BugCheckParameter1,
    IN ULONG_PTR    BugCheckParameter2,
    IN ULONG_PTR    BugCheckParameter3,
    IN ULONG_PTR    BugCheckParameter4
);

XBSYSAPI EXPORTNUM(97) VOID *KeCancelTimer;

// ******************************************************************
// * KeConnectInterrupt
// ******************************************************************
XBSYSAPI EXPORTNUM(98) NTSTATUS NTAPI KeConnectInterrupt
(
    IN PKINTERRUPT  InterruptObject
);

// ******************************************************************
// * KeDelayExecutionThread
// ******************************************************************
XBSYSAPI EXPORTNUM(99) NTSTATUS NTAPI KeDelayExecutionThread
(
    IN KPROCESSOR_MODE  WaitMode,
    IN BOOLEAN          Alertable,
    IN PLARGE_INTEGER   Interval
);

// ******************************************************************
// * KeDisconnectInterrupt
// ******************************************************************
XBSYSAPI EXPORTNUM(100) VOID NTAPI KeDisconnectInterrupt
(
    IN PKINTERRUPT  InterruptObject
);

// ******************************************************************
// * KeEnterCriticalRegion
// ******************************************************************
XBSYSAPI EXPORTNUM(101) VOID NTAPI KeEnterCriticalRegion();

XBSYSAPI EXPORTNUM(103) VOID *KeGetCurrentIrql;

// ******************************************************************
// * KeGetCurrentThread
// ******************************************************************
XBSYSAPI EXPORTNUM(104) PKTHREAD NTAPI KeGetCurrentThread();

XBSYSAPI EXPORTNUM(105) VOID *KeInitializeApc;
XBSYSAPI EXPORTNUM(106) VOID *KeInitializeDeviceQueue;

// ******************************************************************
// * KeInitializeDpc
// ******************************************************************
XBSYSAPI EXPORTNUM(107) VOID NTAPI KeInitializeDpc
(
    KDPC                *Dpc,
    PKDEFERRED_ROUTINE   DeferredRoutine,
    PVOID                DeferredContext
);

XBSYSAPI EXPORTNUM(108) VOID *KeInitializeEvent;

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
);

XBSYSAPI EXPORTNUM(110) VOID *KeInitializeMutant;
XBSYSAPI EXPORTNUM(111) VOID *KeInitializeQueue;
XBSYSAPI EXPORTNUM(112) VOID *KeInitializeSemaphore;

// ******************************************************************
// * KeInitializeTimerEx
// ******************************************************************
XBSYSAPI EXPORTNUM(113) VOID NTAPI KeInitializeTimerEx
(
    IN OUT PKTIMER      Timer,
    IN	   TIMER_TYPE   Type
);

XBSYSAPI EXPORTNUM(114) VOID *KeInsertByKeyDeviceQueue;
XBSYSAPI EXPORTNUM(115) VOID *KeInsertDeviceQueue;
XBSYSAPI EXPORTNUM(116) VOID *KeInsertHeadQueue;
XBSYSAPI EXPORTNUM(117) VOID *KeInsertQueue;
XBSYSAPI EXPORTNUM(118) VOID *KeInsertQueueApc;

// ******************************************************************
// * KeInsertQueueDpc
// ******************************************************************
XBSYSAPI EXPORTNUM(119) BOOLEAN NTAPI KeInsertQueueDpc
(
    IN PKDPC        Dpc,
    IN PVOID        SystemArgument1,
    IN PVOID        SystemArgument2
);

XBSYSAPI EXPORTNUM(120) VOID *KeInterruptTime;
XBSYSAPI EXPORTNUM(121) VOID *KeIsExecutingDpc;

// ******************************************************************
// * KeLeaveCriticalRegion
// ******************************************************************
XBSYSAPI EXPORTNUM(122) VOID NTAPI KeLeaveCriticalRegion();

XBSYSAPI EXPORTNUM(123) VOID *KePulseEvent;
XBSYSAPI EXPORTNUM(124) VOID *KeQueryBasePriorityThread;
XBSYSAPI EXPORTNUM(125) VOID *KeQueryInterruptTime;

// ******************************************************************
// * KeQueryPerformanceCounter
// ******************************************************************
XBSYSAPI EXPORTNUM(126) ULONGLONG NTAPI KeQueryPerformanceCounter();

// ******************************************************************
// * KeQueryPerformanceFrequency
// ******************************************************************
XBSYSAPI EXPORTNUM(127) ULONGLONG NTAPI KeQueryPerformanceFrequency();

// ******************************************************************
// * KeQuerySystemTime
// ******************************************************************
XBSYSAPI EXPORTNUM(128) VOID NTAPI KeQuerySystemTime
(
    PLARGE_INTEGER CurrentTime
);

// ******************************************************************
// * KeRaiseIrqlToDpcLevel
// ******************************************************************
XBSYSAPI EXPORTNUM(129) KIRQL NTAPI KeRaiseIrqlToDpcLevel();

XBSYSAPI EXPORTNUM(130) VOID *KeRaiseIrqlToSynchLevel;
XBSYSAPI EXPORTNUM(131) VOID *KeReleaseMutant;
XBSYSAPI EXPORTNUM(132) VOID *KeReleaseSemaphore;
XBSYSAPI EXPORTNUM(133) VOID *KeRemoveByKeyDeviceQueue;
XBSYSAPI EXPORTNUM(134) VOID *KeRemoveDeviceQueue;
XBSYSAPI EXPORTNUM(135) VOID *KeRemoveEntryDeviceQueue;
XBSYSAPI EXPORTNUM(136) VOID *KeRemoveQueue;
XBSYSAPI EXPORTNUM(137) VOID *KeRemoveQueueDpc;
XBSYSAPI EXPORTNUM(138) VOID *KeResetEvent;

// ******************************************************************
// * KeRestoreFloatingPointState
// ******************************************************************
XBSYSAPI EXPORTNUM(139) VOID NTAPI KeRestoreFloatingPointState();

// ******************************************************************
// * KeResumeThread
// ******************************************************************
XBSYSAPI EXPORTNUM(140) DWORD NTAPI KeResumeThread
(
    IN  HANDLE    hThread
);

XBSYSAPI EXPORTNUM(141) VOID *KeRundownQueue;

// ******************************************************************
// * KeRestoreFloatingPointState
// ******************************************************************
XBSYSAPI EXPORTNUM(142) VOID NTAPI KeSaveFloatingPointState();

// ******************************************************************
// * KeSetBasePriorityThread
// ******************************************************************
XBSYSAPI EXPORTNUM(143) BOOLEAN NTAPI KeSetBasePriorityThread
(
    IN PKTHREAD  Thread,
    IN PVOID  Priority
);

XBSYSAPI VOID *KeSetDisableBoostThread;
XBSYSAPI VOID *KeSetEvent;
XBSYSAPI VOID *KeSetEventBoostPriority;
XBSYSAPI VOID *KeSetPriorityProcess;

// ******************************************************************
// * KeSetPriorityThread
// ******************************************************************
XBSYSAPI EXPORTNUM(148) BOOLEAN NTAPI KeSetPriorityThread
(
    IN PKTHREAD  Thread,
    IN PVOID  Priority
);

// ******************************************************************
// * KeSetTimer
// ******************************************************************
XBSYSAPI EXPORTNUM(149) BOOLEAN NTAPI KeSetTimer
(
    IN PKTIMER        Timer,
    IN LARGE_INTEGER  DueTime,
    IN PKDPC          Dpc OPTIONAL
);

XBSYSAPI VOID *KeSetTimerEx;

// ******************************************************************
// * KeStallExecutionProcessor
// ******************************************************************
XBSYSAPI EXPORTNUM(151) VOID NTAPI KeStallExecutionProcessor
(
    IN ULONG          Microseconds
);

// ******************************************************************
// * KeSuspendThread
// ******************************************************************
XBSYSAPI EXPORTNUM(152) DWORD NTAPI KeSuspendThread
(
	IN	HANDLE	hThread
);

XBSYSAPI VOID *KeSynchronizeExecution;
XBSYSAPI VOID *KeSystemTime;
XBSYSAPI VOID *KeTestAlertThread;

// ******************************************************************
// * KeTickCount
// ******************************************************************
XBSYSAPI EXPORTNUM(156) volatile DWORD KeTickCount;

XBSYSAPI VOID *KeTimeIncrement;
XBSYSAPI VOID *KeWaitForMultipleObjects;
XBSYSAPI VOID *KeWaitForSingleObjects;

#endif
