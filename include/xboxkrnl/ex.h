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

XBOXSYSAPI VOID *ExAcquireReadWriteLockExclusive;
XBOXSYSAPI VOID *ExAcquireReadWriteLockShared;
//XBOXSYSAPI VOID *ExAllocatePool;
XBOXSYSAPI EXPORTNUM(165) PVOID NTAPI ExAllocatePool
(
	IN ULONG NumberOfBytes
);
XBOXSYSAPI VOID *ExAllocatePoolWithTag;
XBOXSYSAPI VOID *ExEventObjectType;
XBOXSYSAPI VOID *ExFreePool;
XBOXSYSAPI VOID *ExInitializeReadWriteLock;
XBOXSYSAPI VOID *ExInterlockedAddLargeInteger;
XBOXSYSAPI VOID *ExInterlockedAddLargeStatistic;
XBOXSYSAPI VOID *ExInterlockedCompareExchange64;
XBOXSYSAPI VOID *ExMutantObjectType;
XBOXSYSAPI VOID *ExQueryPoolBlockSize;
XBOXSYSAPI VOID *ExQueryNonVolatileSetting;
XBOXSYSAPI VOID *ExReadWriteRefurbInfo;
XBOXSYSAPI VOID *ExRaiseException;
XBOXSYSAPI VOID *ExRaiseStatus;
XBOXSYSAPI VOID *ExReleaseReadWriteLock;
XBOXSYSAPI VOID *ExSaveNonVolatileSetting;
XBOXSYSAPI VOID *ExSemaphoreObjectType;
XBOXSYSAPI VOID *ExTimerObjectType;
XBOXSYSAPI VOID *ExfInterlockedInsertHeadList;
XBOXSYSAPI VOID *ExfInterlockedInsertTailList;
XBOXSYSAPI VOID *ExfInterlockedRemoveHeadList;
XBOXSYSAPI VOID *InterlockedCompareExchange;
XBOXSYSAPI VOID *InterlockedDecrement;
XBOXSYSAPI VOID *InterlockedIncrement;
XBOXSYSAPI VOID *InterlockedExchange;
XBOXSYSAPI VOID *InterlockedExchangeAdd;
XBOXSYSAPI VOID *InterlockedFlushSList;
XBOXSYSAPI VOID *InterlockedPopEntrySList;
XBOXSYSAPI VOID *InterlockedPushEntrySList;

#endif


