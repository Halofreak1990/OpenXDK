// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_rtl.c
// *
// * note : XBox Kernel *Run-time Library* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

NTSYSAPI VOID *RtlAnsiStringToUnicodeString = 0;
NTSYSAPI VOID *RtlAppendStringToString = 0;
NTSYSAPI VOID *RtlAppendUnicodeStringToString = 0;
NTSYSAPI VOID *RtlAppendUnicodeToString = 0;
NTSYSAPI VOID *RtlAssert = 0;
NTSYSAPI VOID *RtlCaptureContext = 0;
NTSYSAPI VOID *RtlCaptureStackBackTrace = 0;
NTSYSAPI VOID *RtlCharToInteger = 0;
NTSYSAPI VOID *RtlCompareMemory = 0;
NTSYSAPI VOID *RtlCompareMemoryUlong = 0;
NTSYSAPI VOID *RtlCompareString = 0;
NTSYSAPI VOID *RtlCompareUnicodeString = 0;
NTSYSAPI VOID *RtlCopyString = 0;
NTSYSAPI VOID *RtlCopyUnicodeString = 0;
NTSYSAPI VOID *RtlCreateUnicodeString = 0;
NTSYSAPI VOID *RtlDowncaseUnicodeChar = 0;
NTSYSAPI VOID *RtlDowncaseUnicodeString = 0;
NTSYSAPI VOID *RtlEnterCriticalSection = 0;
NTSYSAPI VOID *RtlEnterCriticalSectionAndRegion = 0;
NTSYSAPI VOID *RtlEqualString = 0;
NTSYSAPI VOID *RtlEqualUnicodeString = 0;
NTSYSAPI VOID *RtlExtendedIntegerMultiply = 0;
NTSYSAPI VOID *RtlExtendedLargeIntegerDivide = 0;
NTSYSAPI VOID *RtlExtendedMagicDivide = 0;
NTSYSAPI VOID *RtlFillMemory = 0;
NTSYSAPI VOID *RtlFillMemoryUlong = 0;
NTSYSAPI VOID *RtlFreeAnsiString = 0;
NTSYSAPI VOID *RtlFreeUnicodeString = 0;
NTSYSAPI VOID *RtlGetCallersAddress = 0;
NTSYSAPI VOID *RtlInitAnsiString = 0;
NTSYSAPI VOID *RtlInitUnicodeString = 0;
NTSYSAPI VOID *RtlInitializeCriticalSection = 0;
NTSYSAPI VOID *RtlIntegerToChar = 0;
NTSYSAPI VOID *RtlIntegerToUnicodeString = 0;
NTSYSAPI VOID *RtlLeaveCriticalSection = 0;
NTSYSAPI VOID *RtlLeaveCriticalSectionAndRegion = 0;
NTSYSAPI VOID *RtlLowerChar = 0;
NTSYSAPI VOID *RtlMapGenericMask = 0;
NTSYSAPI VOID *RtlMoveMemory = 0;
NTSYSAPI VOID *RtlMultiByteToUnicodeN = 0;
NTSYSAPI VOID *RtlMultiByteToUnicodeSize = 0;
NTSYSAPI VOID *RtlNtStatusToDosError = 0;
NTSYSAPI VOID *RtlRaiseException = 0;
NTSYSAPI VOID *RtlRaiseStatus = 0;
NTSYSAPI VOID *RtlTimeFieldsToTime = 0;
NTSYSAPI VOID *RtlTimeToTimeFields = 0;
NTSYSAPI VOID *RtlTryEnterCriticalSection = 0;
NTSYSAPI VOID *RtlUlongByteSwap = 0;
NTSYSAPI VOID *RtlUnicodeStringToAnsiString = 0;
NTSYSAPI VOID *RtlUnicodeStringToInteger = 0;
NTSYSAPI VOID *RtlUnicodeToMultiByteN = 0;
NTSYSAPI VOID *RtlUnicodeToMultiByteSize = 0;
NTSYSAPI VOID *RtlUnwind = 0;
NTSYSAPI VOID *RtlUpcaseUnicodeChar = 0;
NTSYSAPI VOID *RtlUpcaseUnicodeString = 0;
NTSYSAPI VOID *RtlUpcaseUnicodeToMultiByteN = 0;
NTSYSAPI VOID *RtlUpperChar = 0;
NTSYSAPI VOID *RtlUpperString = 0;
NTSYSAPI VOID *RtlUshortByteSwap = 0;
NTSYSAPI VOID *RtlWalkFrameChain = 0;

NTSYSAPI EXPORTNUM(320) VOID CDECL RtlZeroMemory
(
  IN VOID UNALIGNED  *Destination,
  IN SIZE_T           Length
)
{
    return;
}

NTSYSAPI VOID *RtlRip = 0;
