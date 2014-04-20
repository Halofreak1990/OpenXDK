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

// ******************************************************************
// * RtlAnsiStringToUnicodeString
// ******************************************************************
XBSYSAPI EXPORTNUM(260) NTSTATUS NTAPI RtlAnsiStringToUnicodeString
(
    PUNICODE_STRING DestinationString,
    PSTRING         SourceString,
    UCHAR           AllocateDestinationString
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * RtlAppendStringToString
// ******************************************************************
XBSYSAPI EXPORTNUM(261) NTSTATUS NTAPI RtlAppendStringToString
(
  IN PSTRING    Destination,
  IN PSTRING    Source
)
{
	return STATUS_SUCCESS;
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
XBSYSAPI EXPORTNUM(277) VOID NTAPI RtlEnterCriticalSection
(
  IN PRTL_CRITICAL_SECTION CriticalSection
)
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

// ******************************************************************
// * RtlInitializeCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(291) VOID NTAPI RtlInitializeCriticalSection
(
  IN PRTL_CRITICAL_SECTION CriticalSection
)
{
    return;
}


XBSYSAPI VOID *RtlIntegerToChar = 0;
XBSYSAPI VOID *RtlIntegerToUnicodeString = 0;

// ******************************************************************
// * RtlLeaveCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(294) VOID NTAPI RtlLeaveCriticalSection
(
  IN PRTL_CRITICAL_SECTION CriticalSection
)
{
    return;
}

XBSYSAPI VOID *RtlLeaveCriticalSectionAndRegion = 0;

// ******************************************************************
// * RtlLowerChar
// ******************************************************************
XBSYSAPI EXPORTNUM(296) CHAR NTAPI RtlLowerChar(CHAR Character)
{
    return '\0';
}

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

// ******************************************************************
// * RtlTimeFieldsToTime
// ******************************************************************
XBSYSAPI EXPORTNUM(304) BOOLEAN NTAPI RtlTimeFieldsToTime
(
    IN  PTIME_FIELDS    TimeFields,
    OUT PLARGE_INTEGER  Time
)
{
    return TRUE;
}

// ******************************************************************
// * RtlTimeToTimeFields
// ******************************************************************
XBSYSAPI EXPORTNUM(305) VOID NTAPI RtlTimeToTimeFields
(
    IN  PLARGE_INTEGER  Time,
    OUT PTIME_FIELDS    TimeFields 
)
{
    return;
}

// ******************************************************************
// * RtlTryEnterCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(306) BOOLEAN NTAPI RtlTryEnterCriticalSection
(
    IN PRTL_CRITICAL_SECTION CriticalSection
)
{
    return TRUE;
}

XBSYSAPI VOID *RtlUlongByteSwap = 0;

// ******************************************************************
// * RtlUnicodeStringToAnsiString
// ******************************************************************
XBSYSAPI EXPORTNUM(308) NTSTATUS NTAPI RtlUnicodeStringToAnsiString
(
    IN OUT PSTRING         DestinationString,
    IN     PUNICODE_STRING SourceString,
    IN     BOOLEAN         AllocateDestinationString
)
{
    return STATUS_SUCCESS;
}

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
