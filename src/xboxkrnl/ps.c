// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ps.c
// *
// * note : XBox Kernel *Process Structure* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBSYSAPI VOID *PsCreateSystemThread = 0;
XBSYSAPI VOID *PsCreateSystemThreadEx = 0;
XBSYSAPI VOID *PsQueryStatistics = 0;
XBSYSAPI VOID *PsSetCreateThreadNotifyRoutine = 0;
XBSYSAPI VOID *PsTerminateSystemThread = 0;
XBSYSAPI VOID *PsThreadObjectType = 0;
