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

XBOXSYSAPI VOID *RtlAnsiStringToUnicodeString = 0;
XBOXSYSAPI VOID *RtlAppendStringToString = 0;
XBOXSYSAPI VOID *RtlAppendUnicodeStringToString = 0;
XBOXSYSAPI VOID *RtlAppendUnicodeToString = 0;
XBOXSYSAPI VOID *RtlAssert = 0;
XBOXSYSAPI VOID *RtlCaptureContext = 0;
XBOXSYSAPI VOID *RtlCaptureStackBackTrace = 0;
XBOXSYSAPI VOID *RtlCharToInteger = 0;
XBOXSYSAPI VOID *RtlCompareMemory = 0;
XBOXSYSAPI VOID *RtlCompareMemoryUlong = 0;
XBOXSYSAPI VOID *RtlCompareString = 0;
XBOXSYSAPI VOID *RtlCompareUnicodeString = 0;
XBOXSYSAPI VOID *RtlCopyString = 0;
XBOXSYSAPI VOID *RtlCopyUnicodeString = 0;
XBOXSYSAPI VOID *RtlCreateUnicodeString = 0;
XBOXSYSAPI VOID *RtlDowncaseUnicodeChar = 0;
XBOXSYSAPI VOID *RtlDowncaseUnicodeString = 0;
XBOXSYSAPI VOID *RtlEnterCriticalSection = 0;
XBOXSYSAPI VOID *RtlEnterCriticalSectionAndRegion = 0;
XBOXSYSAPI VOID *RtlEqualString = 0;
XBOXSYSAPI VOID *RtlEqualUnicodeString = 0;
XBOXSYSAPI VOID *RtlExtendedIntegerMultiply = 0;
XBOXSYSAPI VOID *RtlExtendedLargeIntegerDivide = 0;
XBOXSYSAPI VOID *RtlExtendedMagicDivide = 0;
XBOXSYSAPI VOID *RtlFillMemory = 0;
XBOXSYSAPI VOID *RtlFillMemoryUlong = 0;
XBOXSYSAPI VOID *RtlFreeAnsiString = 0;
XBOXSYSAPI VOID *RtlFreeUnicodeString = 0;
XBOXSYSAPI VOID *RtlGetCallersAddress = 0;
XBOXSYSAPI VOID *RtlInitAnsiString = 0;
XBOXSYSAPI VOID *RtlInitUnicodeString = 0;
XBOXSYSAPI VOID *RtlInitializeCriticalSection = 0;
XBOXSYSAPI VOID *RtlIntegerToChar = 0;
XBOXSYSAPI VOID *RtlIntegerToUnicodeString = 0;
XBOXSYSAPI VOID *RtlLeaveCriticalSection = 0;
XBOXSYSAPI VOID *RtlLeaveCriticalSectionAndRegion = 0;
XBOXSYSAPI VOID *RtlLowerChar = 0;
XBOXSYSAPI VOID *RtlMapGenericMask = 0;
XBOXSYSAPI VOID *RtlMoveMemory = 0;
XBOXSYSAPI VOID *RtlMultiByteToUnicodeN = 0;
XBOXSYSAPI VOID *RtlMultiByteToUnicodeSize = 0;
XBOXSYSAPI VOID *RtlNtStatusToDosError = 0;
XBOXSYSAPI VOID *RtlRaiseException = 0;
XBOXSYSAPI VOID *RtlRaiseStatus = 0;
XBOXSYSAPI VOID *RtlTimeFieldsToTime = 0;
XBOXSYSAPI VOID *RtlTimeToTimeFields = 0;
XBOXSYSAPI VOID *RtlTryEnterCriticalSection = 0;
XBOXSYSAPI VOID *RtlUlongByteSwap = 0;
XBOXSYSAPI VOID *RtlUnicodeStringToAnsiString = 0;
XBOXSYSAPI VOID *RtlUnicodeStringToInteger = 0;
XBOXSYSAPI VOID *RtlUnicodeToMultiByteN = 0;
XBOXSYSAPI VOID *RtlUnicodeToMultiByteSize = 0;
XBOXSYSAPI VOID *RtlUnwind = 0;
XBOXSYSAPI VOID *RtlUpcaseUnicodeChar = 0;
XBOXSYSAPI VOID *RtlUpcaseUnicodeString = 0;
XBOXSYSAPI VOID *RtlUpcaseUnicodeToMultiByteN = 0;
XBOXSYSAPI VOID *RtlUpperChar = 0;
XBOXSYSAPI VOID *RtlUpperString = 0;
XBOXSYSAPI VOID *RtlUshortByteSwap = 0;
XBOXSYSAPI VOID *RtlWalkFrameChain = 0;
XBOXSYSAPI VOID *RtlZeroMemory = 0;
XBOXSYSAPI VOID *RtlRip = 0;
