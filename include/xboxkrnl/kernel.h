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

NTSYSAPI VOID *KeAlertResumeThread;
NTSYSAPI VOID *KeAlertThread;
NTSYSAPI VOID *KeBoostPriorityThread;
NTSYSAPI VOID *KeBugCheck;
NTSYSAPI VOID *KeBugCheckEx;
NTSYSAPI VOID *KeCancelTimer;
NTSYSAPI VOID *KeConnectInterrupt;
NTSYSAPI VOID *KeDelayExecutionThread;
NTSYSAPI VOID *KeDisconnectInterrupt;
NTSYSAPI VOID *KeEnterCriticalRegion;
NTSYSAPI VOID *KeGetCurrentIrql;
NTSYSAPI VOID *KeGetCurrentThread;
NTSYSAPI VOID *KeInitializeApc;
NTSYSAPI VOID *KeInitializeDeviceQueue;
NTSYSAPI VOID *KeInitializeDpc;
NTSYSAPI VOID *KeInitializeEvent;
NTSYSAPI VOID *KeInitializeInterrupt;
NTSYSAPI VOID *KeInitializeMutant;
NTSYSAPI VOID *KeInitializeQueue;
NTSYSAPI VOID *KeInitializeSemaphore;
NTSYSAPI VOID *KeInitializeTimerEx;
NTSYSAPI VOID *KeInsertByKeyDeviceQueue;
NTSYSAPI VOID *KeInsertDeviceQueue;
NTSYSAPI VOID *KeInsertHeadQueue;
NTSYSAPI VOID *KeInsertQueue;
NTSYSAPI VOID *KeInsertQueueApc;
NTSYSAPI VOID *KeInsertQueueDpc;
NTSYSAPI VOID *KeInterruptTime;
NTSYSAPI VOID *KeIsExecutingDpc;
NTSYSAPI VOID *KeLeaveCriticalRegion;
NTSYSAPI VOID *KePulseEvent;
NTSYSAPI VOID *KeQueryBasePriorityThread;
NTSYSAPI VOID *KeQueryInterruptTime;
NTSYSAPI VOID *KeQueryPerformanceCounter;
NTSYSAPI VOID *KeQueryPerformanceFrequency;
NTSYSAPI VOID *KeQuerySystemTime;
NTSYSAPI VOID *KeRaiseIrqlToDpcLevel;
NTSYSAPI VOID *KeRaiseIrqlToSynchLevel;
NTSYSAPI VOID *KeReleaseMutant;
NTSYSAPI VOID *KeReleaseSemaphore;
NTSYSAPI VOID *KeRemoveByKeyDeviceQueue;
NTSYSAPI VOID *KeRemoveDeviceQueue;
NTSYSAPI VOID *KeRemoveEntryDeviceQueue;
NTSYSAPI VOID *KeRemoveQueue;
NTSYSAPI VOID *KeRemoveQueueDpc;
NTSYSAPI VOID *KeResetEvent;
NTSYSAPI VOID *KeRestoreFloatingPointState;
NTSYSAPI VOID *KeResumeThread;
NTSYSAPI VOID *KeRundownQueue;
NTSYSAPI VOID *KeSaveFloatingPointState;
NTSYSAPI VOID *KeSetBasePriorityThread;
NTSYSAPI VOID *KeSetDisableBoostThread;
NTSYSAPI VOID *KeSetEvent;
NTSYSAPI VOID *KeSetEventBoostPriority;
NTSYSAPI VOID *KeSetPriorityProcess;
NTSYSAPI VOID *KeSetPriorityThread;
NTSYSAPI VOID *KeSetTimer;
NTSYSAPI VOID *KeSetTimerEx;
NTSYSAPI VOID *KeStallExecutionProcessor;
NTSYSAPI VOID *KeSuspendThread;
NTSYSAPI VOID *KeSynchronizeExecution;
NTSYSAPI VOID *KeSystemTime;
NTSYSAPI VOID *KeTestAlertThread;

// ******************************************************************
// * KeTickCount
// ******************************************************************
NTSYSAPI EXPORTNUM(156) DWORD KeTickCount;

NTSYSAPI VOID *KeTimeIncrement;
NTSYSAPI VOID *KeWaitForMultipleObjects;
NTSYSAPI VOID *KeWaitForSingleObject;

#endif


