// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ex.c
// *
// * note : XBox Kernel *Executive* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBSYSAPI VOID *ExAcquireReadWriteLockExclusive = 0;
XBSYSAPI VOID *ExAcquireReadWriteLockShared = 0;

// ******************************************************************
// * ExAllocatePool
// ******************************************************************
XBSYSAPI EXPORTNUM(14) PVOID NTAPI ExAllocatePool
(
	IN ULONG NumberOfBytes
)
{
    return NULL;
}

XBSYSAPI VOID *ExAllocatePoolWithTag = 0;
XBSYSAPI VOID *ExEventObjectType = 0;

// ******************************************************************
// * ExFreePool
// ******************************************************************
// *
// * Deallocates a block  of pool memory
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(17) PVOID NTAPI ExFreePool
(
    IN PVOID P
)
{
    return NULL;
}

XBSYSAPI VOID *ExInitializeReadWriteLock = 0;
XBSYSAPI VOID *ExInterlockedAddLargeInteger = 0;
XBSYSAPI VOID *ExInterlockedAddLargeStatistic = 0;
XBSYSAPI VOID *ExInterlockedCompareExchange64 = 0;
XBSYSAPI VOID *ExMutantObjectType = 0;
XBSYSAPI VOID *ExQueryPoolBlockSize = 0;

// ******************************************************************
// * ExQueryNonVolatileSetting
// ******************************************************************
XBSYSAPI EXPORTNUM(24) NTSTATUS NTAPI ExQueryNonVolatileSetting
(
	IN  DWORD               ValueIndex,
	OUT DWORD              *Type,
	OUT PUCHAR              Value,
	IN  SIZE_T              ValueLength,
	OUT PSIZE_T             ResultLength OPTIONAL
)
{
    return 0;
}

XBSYSAPI VOID *ExReadWriteRefurbInfo = 0;
XBSYSAPI VOID *ExRaiseException = 0;
XBSYSAPI VOID *ExRaiseStatus = 0;
XBSYSAPI VOID *ExReleaseReadWriteLock = 0;

// ******************************************************************
// * ExSaveNonVolatileSetting
// ******************************************************************
XBSYSAPI EXPORTNUM(29) NTSTATUS NTAPI ExSaveNonVolatileSetting
(
    IN  DWORD               ValueIndex,
    OUT DWORD              *Type,
    IN  PUCHAR              Value,
    IN  SIZE_T              ValueLength
)
{
    return 0;
}

XBSYSAPI VOID *ExSemaphoreObjectType = 0;
XBSYSAPI VOID *ExTimerObjectType = 0;
XBSYSAPI VOID *ExfInterlockedInsertHeadList = 0;
XBSYSAPI VOID *ExfInterlockedInsertTailList = 0;
XBSYSAPI VOID *ExfInterlockedRemoveHeadList = 0;
XBSYSAPI VOID *InterlockedCompareExchange = 0;
XBSYSAPI VOID *InterlockedDecrement = 0;
XBSYSAPI VOID *InterlockedIncrement = 0;
XBSYSAPI VOID *InterlockedExchange = 0;
XBSYSAPI VOID *InterlockedExchangeAdd = 0;
XBSYSAPI VOID *InterlockedFlushSList = 0;
XBSYSAPI VOID *InterlockedPopEntrySList = 0;
XBSYSAPI VOID *InterlockedPushEntrySList = 0;
