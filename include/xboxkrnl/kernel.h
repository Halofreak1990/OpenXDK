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

XBOXSYSAPI VOID *KeAlertResumeThread;
XBOXSYSAPI VOID *KeAlertThread;
XBOXSYSAPI VOID *KeBoostPriorityThread;
XBOXSYSAPI VOID *KeBugCheck;
XBOXSYSAPI VOID *KeBugCheckEx;
XBOXSYSAPI VOID *KeCancelTimer;
XBOXSYSAPI VOID *KeConnectInterrupt;
XBOXSYSAPI VOID *KeDelayExecutionThread;
XBOXSYSAPI VOID *KeDisconnectInterrupt;
XBOXSYSAPI VOID *KeEnterCriticalRegion;
XBOXSYSAPI VOID *KeGetCurrentIrql;
XBOXSYSAPI VOID *KeGetCurrentThread;
XBOXSYSAPI VOID *KeInitializeApc;
XBOXSYSAPI VOID *KeInitializeDeviceQueue;
XBOXSYSAPI VOID *KeInitializeDpc;
XBOXSYSAPI VOID *KeInitializeEvent;
XBOXSYSAPI VOID *KeInitializeInterrupt;
XBOXSYSAPI VOID *KeInitializeMutant;
XBOXSYSAPI VOID *KeInitializeQueue;
XBOXSYSAPI VOID *KeInitializeSemaphore;
XBOXSYSAPI VOID *KeInitializeTimerEx;
XBOXSYSAPI VOID *KeInsertByKeyDeviceQueue;
XBOXSYSAPI VOID *KeInsertDeviceQueue;
XBOXSYSAPI VOID *KeInsertHeadQueue;
XBOXSYSAPI VOID *KeInsertQueue;
XBOXSYSAPI VOID *KeInsertQueueApc;
XBOXSYSAPI VOID *KeInsertQueueDpc;
XBOXSYSAPI VOID *KeInterruptTime;
XBOXSYSAPI VOID *KeIsExecutingDpc;
XBOXSYSAPI VOID *KeLeaveCriticalRegion;
XBOXSYSAPI VOID *KePulseEvent;
XBOXSYSAPI VOID *KeQueryBasePriorityThread;
XBOXSYSAPI VOID *KeQueryInterruptTime;
XBOXSYSAPI VOID *KeQueryPerformanceCounter;
XBOXSYSAPI VOID *KeQueryPerformanceFrequency;
XBOXSYSAPI VOID *KeQuerySystemTime;
XBOXSYSAPI VOID *KeRaiseIrqlToDpcLevel;
XBOXSYSAPI VOID *KeRaiseIrqlToSynchLevel;
XBOXSYSAPI VOID *KeReleaseMutant;
XBOXSYSAPI VOID *KeReleaseSemaphore;
XBOXSYSAPI VOID *KeRemoveByKeyDeviceQueue;
XBOXSYSAPI VOID *KeRemoveDeviceQueue;
XBOXSYSAPI VOID *KeRemoveEntryDeviceQueue;
XBOXSYSAPI VOID *KeRemoveQueue;
XBOXSYSAPI VOID *KeRemoveQueueDpc;
XBOXSYSAPI VOID *KeResetEvent;
XBOXSYSAPI VOID *KeRestoreFloatingPointState;
XBOXSYSAPI VOID *KeResumeThread;
XBOXSYSAPI VOID *KeRundownQueue;
XBOXSYSAPI VOID *KeSaveFloatingPointState;
XBOXSYSAPI VOID *KeSetBasePriorityThread;
XBOXSYSAPI VOID *KeSetDisableBoostThread;
XBOXSYSAPI VOID *KeSetEvent;
XBOXSYSAPI VOID *KeSetEventBoostPriority;
XBOXSYSAPI VOID *KeSetPriorityProcess;
XBOXSYSAPI VOID *KeSetPriorityThread;
XBOXSYSAPI VOID *KeSetTimer;
XBOXSYSAPI VOID *KeSetTimerEx;
XBOXSYSAPI VOID *KeStallExecutionProcessor;
XBOXSYSAPI VOID *KeSuspendThread;
XBOXSYSAPI VOID *KeSynchronizeExecution;
XBOXSYSAPI VOID *KeSystemTime;
XBOXSYSAPI VOID *KeTestAlertThread;
XBOXSYSAPI VOID *KeTickCount;
XBOXSYSAPI VOID *KeTimeIncrement;
XBOXSYSAPI VOID *KeWaitForMultipleObjects;
XBOXSYSAPI VOID *KeWaitForSingleObject;

#endif


