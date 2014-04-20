// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ex.h
// *
// * note : XBox Kernel *Executive* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_EX_H
#define XBOXKRNL_EX_H

#include "xboxkrnl.h"

XBSYSAPI EXPORTNUM(12) VOID *ExAcquireReadWriteLockExclusive;
XBSYSAPI EXPORTNUM(13) VOID *ExAcquireReadWriteLockShared;

// ******************************************************************
// * ExAllocatePool
// ******************************************************************
// *
// * Allocates pool memory
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(14) PVOID NTAPI ExAllocatePool
(
	IN ULONG NumberOfBytes
);

// ******************************************************************
// * ExAllocatePoolWithTag
// ******************************************************************
// *
// * Allocates memory from the memory pool.  The Tag parameter is a 
// * 4-letter character constant to which to associate the allocation
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(15) PVOID NTAPI ExAllocatePoolWithTag
(
	IN SIZE_T NumberOfBytes,
	IN ULONG Tag
);

XBSYSAPI VOID *ExEventObjectType;

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
);

XBSYSAPI VOID *ExInitializeReadWriteLock;
XBSYSAPI VOID *ExInterlockedAddLargeInteger;
XBSYSAPI VOID *ExInterlockedAddLargeStatistic;
XBSYSAPI VOID *ExInterlockedCompareExchange64;
XBSYSAPI VOID *ExMutantObjectType;
XBSYSAPI VOID *ExQueryPoolBlockSize;

// ******************************************************************
// * ExQueryNonVolatileSetting
// ******************************************************************
XBSYSAPI EXPORTNUM(24) NTSTATUS NTAPI ExQueryNonVolatileSetting
(
	IN  ULONG	ValueIndex,
	OUT PULONG	Type,
	OUT PVOID	Value,
	IN  ULONG	ValueLength,
	OUT PULONG	ResultLength OPTIONAL
);

// ******************************************************************
// * ExReadWriteRefurbInfo
// ******************************************************************
XBSYSAPI EXPORTNUM(25) NTSTATUS NTAPI ExReadWriteRefurbInfo
(
	OUT	XBOX_REFURB_INFO*	RefurbInfo,
	IN	ULONG			ValueLength,
	IN	BOOLEAN			DoWrite
);

// ******************************************************************
// * ExRaiseException
// ******************************************************************
XBSYSAPI EXPORTNUM(26) VOID NTAPI ExRaiseException
(
	IN DWORD	dwExceptionCode,
	IN DWORD	dwExceptionFlags,
	IN DWORD	nNumberOfArguments,
	IN CONST ULONG	*lpArguments
);

XBSYSAPI EXPORTNUM(27) VOID *ExRaiseStatus;
XBSYSAPI EXPORTNUM(28) VOID *ExReleaseReadWriteLock;

// ******************************************************************
// * ExSaveNonVolatileSetting
// ******************************************************************
XBSYSAPI EXPORTNUM(29) NTSTATUS NTAPI ExSaveNonVolatileSetting
(
	IN	ULONG	ValueIndex,
	IN	PULONG	Type OPTIONAL,
	IN	PVOID	Value,
	IN	ULONG	ValueLength
);

XBSYSAPI EXPORTNUM(30) VOID *ExSemaphoreObjectType;
XBSYSAPI EXPORTNUM(31) VOID *ExTimerObjectType;
XBSYSAPI EXPORTNUM(32) VOID *ExfInterlockedInsertHeadList;
XBSYSAPI EXPORTNUM(33) VOID *ExfInterlockedInsertTailList;
XBSYSAPI EXPORTNUM(34) VOID *ExfInterlockedRemoveHeadList;
XBSYSAPI EXPORTNUM(51) VOID *InterlockedCompareExchange;
XBSYSAPI EXPORTNUM(52) VOID *InterlockedDecrement;
XBSYSAPI EXPORTNUM(53) VOID *InterlockedIncrement;
XBSYSAPI EXPORTNUM(54) VOID *InterlockedExchange;
XBSYSAPI EXPORTNUM(55) VOID *InterlockedExchangeAdd;
XBSYSAPI EXPORTNUM(56) VOID *InterlockedFlushSList;
XBSYSAPI EXPORTNUM(57) VOID *InterlockedPopEntrySList;
XBSYSAPI EXPORTNUM(58) VOID *InterlockedPushEntrySList;

#endif
