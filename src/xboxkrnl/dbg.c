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

XBSYSAPI VOID *DbgBreakPoint = 0;
XBSYSAPI VOID *DbgBreakPointWithStatus = 0;
XBSYSAPI VOID *DbgLoadImageSymbols = 0;
XBSYSAPI VOID *DbgPrint = 0;
XBSYSAPI VOID *DbgPrompt = 0;
XBSYSAPI VOID *DbgUnLoadImageSymbols = 0;
