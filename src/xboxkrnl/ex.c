// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ex.c
// *
// * note : XBox Kernel *Executive* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBOXSYSAPI VOID *ExAcquireReadWriteLockExclusive = 0;
XBOXSYSAPI VOID *ExAcquireReadWriteLockShared = 0;

// ******************************************************************
// * MmAllocateContiguousMemory
// ******************************************************************
// *
// * allocates a range of physically contiguous, cache-aligned 
// * memory from nonpaged pool (main pool on xbox).
// *
// ******************************************************************
XBOXSYSAPI EXPORTNUM(14) PVOID NTAPI ExAllocatePool
(
	IN ULONG NumberOfBytes
)
{
    return NULL;
}

XBOXSYSAPI VOID *ExAllocatePoolWithTag = 0;
XBOXSYSAPI VOID *ExEventObjectType = 0;
XBOXSYSAPI VOID *ExFreePool = 0;
XBOXSYSAPI VOID *ExInitializeReadWriteLock = 0;
XBOXSYSAPI VOID *ExInterlockedAddLargeInteger = 0;
XBOXSYSAPI VOID *ExInterlockedAddLargeStatistic = 0;
XBOXSYSAPI VOID *ExInterlockedCompareExchange64 = 0;
XBOXSYSAPI VOID *ExMutantObjectType = 0;
XBOXSYSAPI VOID *ExQueryPoolBlockSize = 0;
XBOXSYSAPI VOID *ExQueryNonVolatileSetting = 0;
XBOXSYSAPI VOID *ExReadWriteRefurbInfo = 0;
XBOXSYSAPI VOID *ExRaiseException = 0;
XBOXSYSAPI VOID *ExRaiseStatus = 0;
XBOXSYSAPI VOID *ExReleaseReadWriteLock = 0;
XBOXSYSAPI VOID *ExSaveNonVolatileSetting = 0;
XBOXSYSAPI VOID *ExSemaphoreObjectType = 0;
XBOXSYSAPI VOID *ExTimerObjectType = 0;
XBOXSYSAPI VOID *ExfInterlockedInsertHeadList = 0;
XBOXSYSAPI VOID *ExfInterlockedInsertTailList = 0;
XBOXSYSAPI VOID *ExfInterlockedRemoveHeadList = 0;
XBOXSYSAPI VOID *InterlockedCompareExchange = 0;
XBOXSYSAPI VOID *InterlockedDecrement = 0;
XBOXSYSAPI VOID *InterlockedIncrement = 0;
XBOXSYSAPI VOID *InterlockedExchange = 0;
XBOXSYSAPI VOID *InterlockedExchangeAdd = 0;
XBOXSYSAPI VOID *InterlockedFlushSList = 0;
XBOXSYSAPI VOID *InterlockedPopEntrySList = 0;
XBOXSYSAPI VOID *InterlockedPushEntrySList = 0;
