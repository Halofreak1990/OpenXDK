// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ex.h
// *
// * note : XBox Kernel *Executive* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_EX_H
#define XBOXKRNL_EX_H

NTSYSAPI VOID *ExAcquireReadWriteLockExclusive;
NTSYSAPI VOID *ExAcquireReadWriteLockShared;

// ******************************************************************
// * ExAllocatePool
// ******************************************************************
// *
// * Allocates pool memory
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(14) PVOID NTAPI ExAllocatePool
(
	IN ULONG NumberOfBytes
);

NTSYSAPI VOID *ExAllocatePoolWithTag;
NTSYSAPI VOID *ExEventObjectType;
NTSYSAPI VOID *ExFreePool;
NTSYSAPI VOID *ExInitializeReadWriteLock;
NTSYSAPI VOID *ExInterlockedAddLargeInteger;
NTSYSAPI VOID *ExInterlockedAddLargeStatistic;
NTSYSAPI VOID *ExInterlockedCompareExchange64;
NTSYSAPI VOID *ExMutantObjectType;
NTSYSAPI VOID *ExQueryPoolBlockSize;
NTSYSAPI VOID *ExQueryNonVolatileSetting;
NTSYSAPI VOID *ExReadWriteRefurbInfo;
NTSYSAPI VOID *ExRaiseException;
NTSYSAPI VOID *ExRaiseStatus;
NTSYSAPI VOID *ExReleaseReadWriteLock;
NTSYSAPI VOID *ExSaveNonVolatileSetting;
NTSYSAPI VOID *ExSemaphoreObjectType;
NTSYSAPI VOID *ExTimerObjectType;
NTSYSAPI VOID *ExfInterlockedInsertHeadList;
NTSYSAPI VOID *ExfInterlockedInsertTailList;
NTSYSAPI VOID *ExfInterlockedRemoveHeadList;
NTSYSAPI VOID *InterlockedCompareExchange;
NTSYSAPI VOID *InterlockedDecrement;
NTSYSAPI VOID *InterlockedIncrement;
NTSYSAPI VOID *InterlockedExchange;
NTSYSAPI VOID *InterlockedExchangeAdd;
NTSYSAPI VOID *InterlockedFlushSList;
NTSYSAPI VOID *InterlockedPopEntrySList;
NTSYSAPI VOID *InterlockedPushEntrySList;

#endif


