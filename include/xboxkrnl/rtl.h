// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ps.h
// *
// * note : XBox Kernel *Run-time Library* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_RTL_H
#define XBOXKRNL_RTL_H

XBSYSAPI VOID *RtlAnsiStringToUnicodeString;

// ******************************************************************
// * RtlAppendStringToString
// ******************************************************************
XBSYSAPI EXPORTNUM(261) ULONG NTAPI RtlAppendStringToString
(
  IN PVOID			Destination,    // TODO: should be STRING
  IN PVOID			Source          // TODO: should be STRING
);

XBSYSAPI VOID *RtlAppendUnicodeStringToString;
XBSYSAPI VOID *RtlAppendUnicodeToString;
XBSYSAPI VOID *RtlAssert;
XBSYSAPI VOID *RtlCaptureContext;
XBSYSAPI VOID *RtlCaptureStackBackTrace;
XBSYSAPI VOID *RtlCharToInteger;

// ******************************************************************
// * RtlCompareMemory
// ******************************************************************
// *
// * compare block of memory, return number of equivalent bytes.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(268) SIZE_T NTAPI RtlCompareMemory
(
  IN CONST VOID *Source1,
  IN CONST VOID *Source2,
  IN SIZE_T      Length
);

XBSYSAPI VOID *RtlCompareMemoryUlong;
XBSYSAPI VOID *RtlCompareString;
XBSYSAPI VOID *RtlCompareUnicodeString;

// ******************************************************************
// * RtlCopyString
// ******************************************************************
// *
// * Copy Source to Destination
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(272) VOID NTAPI RtlCopyString
(
  IN OUT PVOID	Destination,        // TODO: should be STRING
  IN     PVOID	Source OPTIONAL     // TODO: should be STRING
);

XBSYSAPI VOID *RtlCopyUnicodeString;
XBSYSAPI VOID *RtlCreateUnicodeString;
XBSYSAPI VOID *RtlDowncaseUnicodeChar;
XBSYSAPI VOID *RtlDowncaseUnicodeString;

// ******************************************************************
// * RtlEnterCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(277) VOID NTAPI RtlEnterCriticalSection
(
  IN PRTL_CRITICAL_SECTION CriticalSection
);

XBSYSAPI VOID *RtlEnterCriticalSectionAndRegion;
XBSYSAPI VOID *RtlEqualString;
XBSYSAPI VOID *RtlEqualUnicodeString;
XBSYSAPI VOID *RtlExtendedIntegerMultiply;
XBSYSAPI VOID *RtlExtendedLargeIntegerDivide;
XBSYSAPI VOID *RtlExtendedMagicDivide;
XBSYSAPI VOID *RtlFillMemory;
XBSYSAPI VOID *RtlFillMemoryUlong;
XBSYSAPI VOID *RtlFreeAnsiString;
XBSYSAPI VOID *RtlFreeUnicodeString;
XBSYSAPI VOID *RtlGetCallersAddress;

// ******************************************************************
// * RtlInitAnsiString
// ******************************************************************
// *
// * Initialize a counted ANSI string.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(289) VOID NTAPI RtlInitAnsiString 
(
  IN OUT PANSI_STRING DestinationString,
  IN     PCSZ         SourceString
);

XBSYSAPI VOID *RtlInitUnicodeString;

// ******************************************************************
// * RtlInitializeCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(291) VOID NTAPI RtlInitializeCriticalSection
(
  IN PRTL_CRITICAL_SECTION CriticalSection
);

XBSYSAPI VOID *RtlIntegerToChar;
XBSYSAPI VOID *RtlIntegerToUnicodeString;

// ******************************************************************
// * RtlLeaveCriticalSection
// ******************************************************************
XBSYSAPI EXPORTNUM(294) VOID NTAPI RtlLeaveCriticalSection
(
  IN PRTL_CRITICAL_SECTION CriticalSection
);

XBSYSAPI VOID *RtlLeaveCriticalSectionAndRegion;
XBSYSAPI VOID *RtlLowerChar;
XBSYSAPI VOID *RtlMapGenericMask;

// ******************************************************************
// * RtlMoveMemory
// ******************************************************************
// *
// * Move memory either forward or backward, aligned or unaligned,
// * in 4-byte blocks, followed by any remaining blocks.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(298) VOID NTAPI RtlMoveMemory
(
  IN VOID UNALIGNED       *Destination,
  IN CONST VOID UNALIGNED *Source,
  IN SIZE_T                Length
);

XBSYSAPI VOID *RtlMultiByteToUnicodeN;
XBSYSAPI VOID *RtlMultiByteToUnicodeSize;

// ******************************************************************
// * RtlNtStatusToDosError
// ******************************************************************
XBSYSAPI EXPORTNUM(301) ULONG NTAPI RtlNtStatusToDosError
(
	IN NTSTATUS	Status
);

XBSYSAPI VOID *RtlRaiseException;
XBSYSAPI VOID *RtlRaiseStatus;
XBSYSAPI VOID *RtlTimeFieldsToTime;
XBSYSAPI VOID *RtlTimeToTimeFields;
XBSYSAPI VOID *RtlTryEnterCriticalSection;
XBSYSAPI VOID *RtlUlongByteSwap;

// ******************************************************************
// * RtlUnicodeStringToAnsiString
// ******************************************************************
XBSYSAPI EXPORTNUM(308) NTSTATUS NTAPI RtlUnicodeStringToAnsiString
(
    IN OUT PSTRING         DestinationString,
    IN     PUNICODE_STRING SourceString,
    IN     BOOLEAN         AllocateDestinationString
);

XBSYSAPI VOID *RtlUnicodeStringToInteger;
XBSYSAPI VOID *RtlUnicodeToMultiByteN;
XBSYSAPI VOID *RtlUnicodeToMultiByteSize;
XBSYSAPI VOID *RtlUnwind;
XBSYSAPI VOID *RtlUpcaseUnicodeChar;
XBSYSAPI VOID *RtlUpcaseUnicodeString;
XBSYSAPI VOID *RtlUpcaseUnicodeToMultiByteN;
XBSYSAPI VOID *RtlUpperChar;
XBSYSAPI VOID *RtlUpperString;
XBSYSAPI VOID *RtlUshortByteSwap;
XBSYSAPI VOID *RtlWalkFrameChain;

// ******************************************************************
// * RtlZeroMemory
// ******************************************************************
// *
// * Fill a block of memory with zeros.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(320) VOID NTAPI RtlZeroMemory
(
  IN VOID UNALIGNED  *Destination,
  IN SIZE_T           Length
);

XBSYSAPI VOID *RtlRip;

#endif


