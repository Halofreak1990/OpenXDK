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
// * Append string 2 to string 1, returns index?
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(261) ULONG NTAPI RtlAppendStringToString
(
  IN PVOID			String1,
  IN PVOID			String2
);
//NTSYSAPI VOID *RtlAppendStringToString;
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
// * Takes 2 strings, and the length required... 
// * returns the actual length that matches
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(289) ULONG CDECL RtlCompareMemory
(
  IN PCHAR			String1,
  IN PCHAR			String2,
  IN ULONG			length
);
//NTSYSAPI VOID *RtlCompareMemory;
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
  IN PVOID			String1,
  IN PVOID			String2
);

//NTSYSAPI VOID *RtlCopyString;
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



NTSYSAPI EXPORTNUM(289) VOID NTAPI RtlInitAnsiString 
(
  IN PVOID			 *OutputString,
  IN PCHAR			FileName
);
//NTSYSAPI VOID *RtlInitAnsiString;
NTSYSAPI VOID *RtlInitUnicodeString;
NTSYSAPI VOID *RtlInitializeCriticalSection;
NTSYSAPI VOID *RtlIntegerToChar;
NTSYSAPI VOID *RtlIntegerToUnicodeString;
NTSYSAPI VOID *RtlLeaveCriticalSection;
NTSYSAPI VOID *RtlLeaveCriticalSectionAndRegion;
NTSYSAPI VOID *RtlLowerChar;
NTSYSAPI VOID *RtlMapGenericMask;

NTSYSAPI EXPORTNUM(298) VOID NTAPI RtlMoveMemory
(
  IN PVOID			 *New,
  IN PVOID			 *Old,
  IN ULONG			size
);
//NTSYSAPI VOID *RtlMoveMemory;
NTSYSAPI VOID *RtlMultiByteToUnicodeN;
NTSYSAPI VOID *RtlMultiByteToUnicodeSize;

NTSYSAPI EXPORTNUM(301) ULONG NTAPI RtlNtStatusToDosError
(
	IN ULONG	Status
);


//NTSYSAPI VOID *RtlNtStatusToDosError;
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

NTSYSAPI EXPORTNUM(320) VOID NTAPI RtlZeroMemory
(
  IN PVOID UNALIGNED  Destination,
  IN SIZE_T           Length
);

NTSYSAPI VOID *RtlRip;

#endif


