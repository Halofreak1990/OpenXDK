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

NTSYSAPI VOID *ExAcquireReadWriteLockExclusive = 0;
NTSYSAPI VOID *ExAcquireReadWriteLockShared = 0;

// ******************************************************************
// * ExAllocatePool
// ******************************************************************
NTSYSAPI EXPORTNUM(14) PVOID NTAPI ExAllocatePool
(
	IN ULONG NumberOfBytes
)
{
    return NULL;
}

NTSYSAPI VOID *ExAllocatePoolWithTag = 0;
NTSYSAPI VOID *ExEventObjectType = 0;
NTSYSAPI VOID *ExFreePool = 0;
NTSYSAPI VOID *ExInitializeReadWriteLock = 0;
NTSYSAPI VOID *ExInterlockedAddLargeInteger = 0;
NTSYSAPI VOID *ExInterlockedAddLargeStatistic = 0;
NTSYSAPI VOID *ExInterlockedCompareExchange64 = 0;
NTSYSAPI VOID *ExMutantObjectType = 0;
NTSYSAPI VOID *ExQueryPoolBlockSize = 0;
NTSYSAPI VOID *ExQueryNonVolatileSetting = 0;
NTSYSAPI VOID *ExReadWriteRefurbInfo = 0;
NTSYSAPI VOID *ExRaiseException = 0;
NTSYSAPI VOID *ExRaiseStatus = 0;
NTSYSAPI VOID *ExReleaseReadWriteLock = 0;
NTSYSAPI VOID *ExSaveNonVolatileSetting = 0;
NTSYSAPI VOID *ExSemaphoreObjectType = 0;
NTSYSAPI VOID *ExTimerObjectType = 0;
NTSYSAPI VOID *ExfInterlockedInsertHeadList = 0;
NTSYSAPI VOID *ExfInterlockedInsertTailList = 0;
NTSYSAPI VOID *ExfInterlockedRemoveHeadList = 0;
NTSYSAPI VOID *InterlockedCompareExchange = 0;
NTSYSAPI VOID *InterlockedDecrement = 0;
NTSYSAPI VOID *InterlockedIncrement = 0;
NTSYSAPI VOID *InterlockedExchange = 0;
NTSYSAPI VOID *InterlockedExchangeAdd = 0;
NTSYSAPI VOID *InterlockedFlushSList = 0;
NTSYSAPI VOID *InterlockedPopEntrySList = 0;
NTSYSAPI VOID *InterlockedPushEntrySList = 0;
