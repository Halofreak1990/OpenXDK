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

XBSYSAPI VOID *KeAlertResumeThread;
XBSYSAPI VOID *KeAlertThread;
XBSYSAPI VOID *KeBoostPriorityThread;
XBSYSAPI VOID *KeBugCheck;
XBSYSAPI VOID *KeBugCheckEx;
XBSYSAPI VOID *KeCancelTimer;
XBSYSAPI VOID *KeConnectInterrupt;
XBSYSAPI VOID *KeDelayExecutionThread;
XBSYSAPI VOID *KeDisconnectInterrupt;
XBSYSAPI VOID *KeEnterCriticalRegion;
XBSYSAPI VOID *KeGetCurrentIrql;
XBSYSAPI VOID *KeGetCurrentThread;
XBSYSAPI VOID *KeInitializeApc;
XBSYSAPI VOID *KeInitializeDeviceQueue;
XBSYSAPI VOID *KeInitializeDpc;
XBSYSAPI VOID *KeInitializeEvent;
XBSYSAPI VOID *KeInitializeInterrupt;
XBSYSAPI VOID *KeInitializeMutant;
XBSYSAPI VOID *KeInitializeQueue;
XBSYSAPI VOID *KeInitializeSemaphore;
XBSYSAPI VOID *KeInitializeTimerEx;
XBSYSAPI VOID *KeInsertByKeyDeviceQueue;
XBSYSAPI VOID *KeInsertDeviceQueue;
XBSYSAPI VOID *KeInsertHeadQueue;
XBSYSAPI VOID *KeInsertQueue;
XBSYSAPI VOID *KeInsertQueueApc;
XBSYSAPI VOID *KeInsertQueueDpc;
XBSYSAPI VOID *KeInterruptTime;
XBSYSAPI VOID *KeIsExecutingDpc;
XBSYSAPI VOID *KeLeaveCriticalRegion;
XBSYSAPI VOID *KePulseEvent;
XBSYSAPI VOID *KeQueryBasePriorityThread;
XBSYSAPI VOID *KeQueryInterruptTime;
XBSYSAPI VOID *KeQueryPerformanceCounter;
XBSYSAPI VOID *KeQueryPerformanceFrequency;
XBSYSAPI VOID *KeQuerySystemTime;
XBSYSAPI VOID *KeRaiseIrqlToDpcLevel;
XBSYSAPI VOID *KeRaiseIrqlToSynchLevel;
XBSYSAPI VOID *KeReleaseMutant;
XBSYSAPI VOID *KeReleaseSemaphore;
XBSYSAPI VOID *KeRemoveByKeyDeviceQueue;
XBSYSAPI VOID *KeRemoveDeviceQueue;
XBSYSAPI VOID *KeRemoveEntryDeviceQueue;
XBSYSAPI VOID *KeRemoveQueue;
XBSYSAPI VOID *KeRemoveQueueDpc;
XBSYSAPI VOID *KeResetEvent;
XBSYSAPI VOID *KeRestoreFloatingPointState;
XBSYSAPI VOID *KeResumeThread;
XBSYSAPI VOID *KeRundownQueue;
XBSYSAPI VOID *KeSaveFloatingPointState;
XBSYSAPI VOID *KeSetBasePriorityThread;
XBSYSAPI VOID *KeSetDisableBoostThread;
XBSYSAPI VOID *KeSetEvent;
XBSYSAPI VOID *KeSetEventBoostPriority;
XBSYSAPI VOID *KeSetPriorityProcess;
XBSYSAPI VOID *KeSetPriorityThread;
XBSYSAPI VOID *KeSetTimer;
XBSYSAPI VOID *KeSetTimerEx;
XBSYSAPI VOID *KeStallExecutionProcessor;
XBSYSAPI VOID *KeSuspendThread;
XBSYSAPI VOID *KeSynchronizeExecution;
XBSYSAPI VOID *KeSystemTime;
XBSYSAPI VOID *KeTestAlertThread;

// ******************************************************************
// * KeTickCount
// ******************************************************************
XBSYSAPI EXPORTNUM(156) DWORD KeTickCount;

XBSYSAPI VOID *KeTimeIncrement;
XBSYSAPI VOID *KeWaitForMultipleObjects;
XBSYSAPI VOID *KeWaitForSingleObject;

#endif


