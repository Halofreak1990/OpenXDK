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
NTSYSAPI VOID *RtlAppendStringToString;
NTSYSAPI VOID *RtlAppendUnicodeStringToString;
NTSYSAPI VOID *RtlAppendUnicodeToString;
NTSYSAPI VOID *RtlAssert;
NTSYSAPI VOID *RtlCaptureContext;
NTSYSAPI VOID *RtlCaptureStackBackTrace;
NTSYSAPI VOID *RtlCharToInteger;
NTSYSAPI VOID *RtlCompareMemory;
NTSYSAPI VOID *RtlCompareMemoryUlong;
NTSYSAPI VOID *RtlCompareString;
NTSYSAPI VOID *RtlCompareUnicodeString;
NTSYSAPI VOID *RtlCopyString;
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
NTSYSAPI VOID *RtlInitAnsiString;
NTSYSAPI VOID *RtlInitUnicodeString;
NTSYSAPI VOID *RtlInitializeCriticalSection;
NTSYSAPI VOID *RtlIntegerToChar;
NTSYSAPI VOID *RtlIntegerToUnicodeString;
NTSYSAPI VOID *RtlLeaveCriticalSection;
NTSYSAPI VOID *RtlLeaveCriticalSectionAndRegion;
NTSYSAPI VOID *RtlLowerChar;
NTSYSAPI VOID *RtlMapGenericMask;
NTSYSAPI VOID *RtlMoveMemory;
NTSYSAPI VOID *RtlMultiByteToUnicodeN;
NTSYSAPI VOID *RtlMultiByteToUnicodeSize;
NTSYSAPI VOID *RtlNtStatusToDosError;
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

NTSYSAPI EXPORTNUM(320) VOID CDECL RtlZeroMemory
(
  IN VOID UNALIGNED  *Destination,
  IN SIZE_T           Length
);

NTSYSAPI VOID *RtlRip;

#endif


