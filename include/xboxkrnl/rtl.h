// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ps.h
// *
// * note : XBox Kernel *Run-time Library* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_RTL_H
#define XBOXKRNL_RTL_H

NTSYSAPI VOID *RtlAnsiStringToUnicodeString;

// ******************************************************************
// * RtlAppendStringToString
// ******************************************************************
// *
// * String concatination (Destination.Source)
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(261) ULONG NTAPI RtlAppendStringToString
(
  IN PVOID			Destination,    // TODO: should be STRING
  IN PVOID			Source          // TODO: should be STRING
);

NTSYSAPI VOID *RtlAppendUnicodeStringToString;
NTSYSAPI VOID *RtlAppendUnicodeToString;
NTSYSAPI VOID *RtlAssert;
NTSYSAPI VOID *RtlCaptureContext;
NTSYSAPI VOID *RtlCaptureStackBackTrace;
NTSYSAPI VOID *RtlCharToInteger;

// ******************************************************************
// * RtlCompareMemory
// ******************************************************************
// *
// * Compare block of memory, return number of equivalent bytes.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(268) SIZE_T CDECL RtlCompareMemory
(
  IN CONST VOID *Source1,
  IN CONST VOID *Source2,
  IN SIZE_T      Length
);

NTSYSAPI VOID *RtlCompareMemoryUlong;
NTSYSAPI VOID *RtlCompareString;
NTSYSAPI VOID *RtlCompareUnicodeString;

// ******************************************************************
// * RtlCopyString
// ******************************************************************
// *
// * Copy string1 into string2  (like libc function strcpy)
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(272) VOID NTAPI RtlCopyString
(
  IN OUT PVOID	Destination,    // TODO: should be STRING
  IN     PVOID	Source OPTIONAL // TODO: should be STRING
);

NTSYSAPI VOID *RtlCopyUnicodeString;
NTSYSAPI VOID *RtlCreateUnicodeString;
NTSYSAPI VOID *RtlDowncaseUnicodeChar;
NTSYSAPI VOID *RtlDowncaseUnicodeString;
NTSYSAPI VOID *RtlEnterCriticalSection;
NTSYSAPI VOID *RtlEnterCriticalSectionAndRegion;
NTSYSAPI VOID *RtlEqualString;
NTSYSAPI VOID *RtlEqualUnicodeString;
NTSYSAPI VOID *RtlExtendedIntegerMultiply;
NTSYSAPI VOID *RtlExtendedLargeIntegerDivide;
NTSYSAPI VOID *RtlExtendedMagicDivide;
NTSYSAPI VOID *RtlFillMemory;
NTSYSAPI VOID *RtlFillMemoryUlong;
NTSYSAPI VOID *RtlFreeAnsiString;
NTSYSAPI VOID *RtlFreeUnicodeString;
NTSYSAPI VOID *RtlGetCallersAddress;

// ******************************************************************
// * RtlInitAnsiString
// ******************************************************************
// *
// * Initialize a counted ANSI string.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(289) VOID CDECL RtlInitAnsiString 
(
  IN OUT PVOID *DestinationString,  // TODO: should be PANSI_STRING
  IN     PCHAR  SourceString        // TODO: should be PCSZ
);

NTSYSAPI VOID *RtlInitUnicodeString;
NTSYSAPI VOID *RtlInitializeCriticalSection;
NTSYSAPI VOID *RtlIntegerToChar;
NTSYSAPI VOID *RtlIntegerToUnicodeString;
NTSYSAPI VOID *RtlLeaveCriticalSection;
NTSYSAPI VOID *RtlLeaveCriticalSectionAndRegion;
NTSYSAPI VOID *RtlLowerChar;
NTSYSAPI VOID *RtlMapGenericMask;

// ******************************************************************
// * RtlMoveMemory
// ******************************************************************
// *
// * Move memory either forward or backward, aligned or unaligned,
// * in 4-byte blocks, followed by any remaining blocks.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(298) VOID CDECL RtlMoveMemory
(
  IN VOID UNALIGNED       *Destination,
  IN CONST VOID UNALIGNED *Source,
  IN SIZE_T                Length
);

NTSYSAPI VOID *RtlMultiByteToUnicodeN;
NTSYSAPI VOID *RtlMultiByteToUnicodeSize;

// ******************************************************************
// * RtlNtStatusToDosError
// ******************************************************************
NTSYSAPI EXPORTNUM(301) ULONG NTAPI RtlNtStatusToDosError
(
	IN NTSTATUS	Status
);

NTSYSAPI VOID *RtlRaiseException;
NTSYSAPI VOID *RtlRaiseStatus;
NTSYSAPI VOID *RtlTimeFieldsToTime;
NTSYSAPI VOID *RtlTimeToTimeFields;
NTSYSAPI VOID *RtlTryEnterCriticalSection;
NTSYSAPI VOID *RtlUlongByteSwap;
NTSYSAPI VOID *RtlUnicodeStringToAnsiString;
NTSYSAPI VOID *RtlUnicodeStringToInteger;
NTSYSAPI VOID *RtlUnicodeToMultiByteN;
NTSYSAPI VOID *RtlUnicodeToMultiByteSize;
NTSYSAPI VOID *RtlUnwind;
NTSYSAPI VOID *RtlUpcaseUnicodeChar;
NTSYSAPI VOID *RtlUpcaseUnicodeString;
NTSYSAPI VOID *RtlUpcaseUnicodeToMultiByteN;
NTSYSAPI VOID *RtlUpperChar;
NTSYSAPI VOID *RtlUpperString;
NTSYSAPI VOID *RtlUshortByteSwap;
NTSYSAPI VOID *RtlWalkFrameChain;

// ******************************************************************
// * RtlZeroMemory
// ******************************************************************
// *
// * Fill a block of memory with zeros.
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(320) VOID CDECL RtlZeroMemory
(
  IN VOID UNALIGNED  *Destination,
  IN SIZE_T           Length
);

NTSYSAPI VOID *RtlRip;

#endif


