// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : dbg.c
// *
// * note : XBox Kernel *Debug* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

NTSYSAPI VOID *DbgBreakPoint = 0;
NTSYSAPI VOID *DbgBreakPointWithStatus = 0;
NTSYSAPI VOID *DbgLoadImageSymbols = 0;
NTSYSAPI VOID *DbgPrint = 0;
NTSYSAPI VOID *DbgPrompt = 0;
NTSYSAPI VOID *DbgUnLoadImageSymbols = 0;
