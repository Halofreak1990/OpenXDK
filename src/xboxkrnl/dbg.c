// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_dbg.c
// *
// * note : XBox Kernel *Debug* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBOXSYSAPI VOID *DbgBreakPoint = 0;
XBOXSYSAPI VOID *DbgBreakPointWithStatus = 0;
XBOXSYSAPI VOID *DbgLoadImageSymbols = 0;
XBOXSYSAPI VOID *DbgPrint = 0;
XBOXSYSAPI VOID *DbgPrompt = 0;
XBOXSYSAPI VOID *DbgUnLoadImageSymbols = 0;
