// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : rtl.c
// *
// * note : XBox Kernel *Run-time Library* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBSYSAPI VOID *RtlAnsiStringToUnicodeString = 0;

// ******************************************************************
// * RtlAppendStringToString
// ******************************************************************
XBSYSAPI EXPORTNUM(261) ULONG NTAPI RtlAppendStringToString
(
  IN PVOID			Destination,    // TODO: should be STRING
  IN PVOID			Source          // TODO: should be STRING
)
{
	return 0;
}

XBSYSAPI VOID *RtlAppendUnicodeStringToString = 0;
XBSYSAPI VOID *RtlAppendUnicodeToString = 0;
XBSYSAPI VOID *RtlAssert = 0;
XBSYSAPI VOID *RtlCaptureContext = 0;
XBSYSAPI VOID *RtlCaptureStackBackTrace = 0;
XBSYSAPI VOID *RtlCharToInteger = 0;


// ******************************************************************
// * RtlCompareMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(268) SIZE_T NTAPI RtlCompareMemory
(
  IN CONST VOID *Source1,
  IN CONST VOID *Source2,
  IN SIZE_T      Length
)
{
	return 0;
}

XBSYSAPI VOID *RtlCompareMemoryUlong = 0;
XBSYSAPI VOID *RtlCompareString = 0;
XBSYSAPI VOID *RtlCompareUnicodeString = 0;

// ******************************************************************
// * RtlCopyString
// ******************************************************************
XBSYSAPI EXPORTNUM(272) VOID NTAPI RtlCopyString
(
  IN OUT PVOID	Destination,        // TODO: should be STRING
  IN     PVOID	Source OPTIONAL     // TODO: should be STRING
)
{
	return;
}

XBSYSAPI VOID *RtlCopyUnicodeString = 0;
XBSYSAPI VOID *RtlCreateUnicodeString = 0;
XBSYSAPI VOID *RtlDowncaseUnicodeChar = 0;
XBSYSAPI VOID *RtlDowncaseUnicodeString = 0;

// ******************************************************************
// * RtlEnterCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(277) VOID RtlEnterCriticalSection(DWORD Unknown)
{
    return;
}

XBSYSAPI VOID *RtlEnterCriticalSectionAndRegion = 0;
XBSYSAPI VOID *RtlEqualString = 0;
XBSYSAPI VOID *RtlEqualUnicodeString = 0;
XBSYSAPI VOID *RtlExtendedIntegerMultiply = 0;
XBSYSAPI VOID *RtlExtendedLargeIntegerDivide = 0;
XBSYSAPI VOID *RtlExtendedMagicDivide = 0;
XBSYSAPI VOID *RtlFillMemory = 0;
XBSYSAPI VOID *RtlFillMemoryUlong = 0;
XBSYSAPI VOID *RtlFreeAnsiString = 0;
XBSYSAPI VOID *RtlFreeUnicodeString = 0;
XBSYSAPI VOID *RtlGetCallersAddress = 0;

// ******************************************************************
// * RtlInitAnsiString
// ******************************************************************
XBSYSAPI EXPORTNUM(289) VOID NTAPI RtlInitAnsiString 
(
  IN OUT PANSI_STRING DestinationString,
  IN     PCSZ         SourceString
)
{
	return;
}

XBSYSAPI VOID *RtlInitUnicodeString = 0;
XBSYSAPI VOID *RtlInitializeCriticalSection = 0;
XBSYSAPI VOID *RtlIntegerToChar = 0;
XBSYSAPI VOID *RtlIntegerToUnicodeString = 0;

// ******************************************************************
// * RtlLeaveCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(294) VOID RtlLeaveCriticalSection(DWORD Unknown)
{
    return;
}

XBSYSAPI VOID *RtlLeaveCriticalSectionAndRegion = 0;
XBSYSAPI VOID *RtlLowerChar = 0;
XBSYSAPI VOID *RtlMapGenericMask = 0;

// ******************************************************************
// * RtlMoveMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(298) VOID NTAPI RtlMoveMemory
(
  IN VOID UNALIGNED       *Destination,
  IN CONST VOID UNALIGNED *Source,
  IN SIZE_T                Length
)
{
	return;
}

XBSYSAPI VOID *RtlMultiByteToUnicodeN = 0;
XBSYSAPI VOID *RtlMultiByteToUnicodeSize = 0;

// ******************************************************************
// * RtlNtStatusToDosError
// ******************************************************************
XBSYSAPI EXPORTNUM(301) ULONG NTAPI RtlNtStatusToDosError
(
	IN NTSTATUS	Status
)
{
    return 0;
}

XBSYSAPI VOID *RtlRaiseException = 0;
XBSYSAPI VOID *RtlRaiseStatus = 0;
XBSYSAPI VOID *RtlTimeFieldsToTime = 0;
XBSYSAPI VOID *RtlTimeToTimeFields = 0;
XBSYSAPI VOID *RtlTryEnterCriticalSection = 0;
XBSYSAPI VOID *RtlUlongByteSwap = 0;
XBSYSAPI VOID *RtlUnicodeStringToAnsiString = 0;
XBSYSAPI VOID *RtlUnicodeStringToInteger = 0;
XBSYSAPI VOID *RtlUnicodeToMultiByteN = 0;
XBSYSAPI VOID *RtlUnicodeToMultiByteSize = 0;
XBSYSAPI VOID *RtlUnwind = 0;
XBSYSAPI VOID *RtlUpcaseUnicodeChar = 0;
XBSYSAPI VOID *RtlUpcaseUnicodeString = 0;
XBSYSAPI VOID *RtlUpcaseUnicodeToMultiByteN = 0;
XBSYSAPI VOID *RtlUpperChar = 0;
XBSYSAPI VOID *RtlUpperString = 0;
XBSYSAPI VOID *RtlUshortByteSwap = 0;
XBSYSAPI VOID *RtlWalkFrameChain = 0;

// ******************************************************************
// * RtlZeroMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(320) VOID NTAPI RtlZeroMemory
(
  IN VOID UNALIGNED  *Destination,
  IN SIZE_T           Length
)
{
    return;
}

XBSYSAPI VOID *RtlRip = 0;
