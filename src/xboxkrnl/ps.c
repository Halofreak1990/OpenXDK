// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ps.c
// *
// * note : XBox Kernel *Process Structure* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBOXSYSAPI VOID *PsCreateSystemThread = 0;
XBOXSYSAPI VOID *PsCreateSystemThreadEx = 0;
XBOXSYSAPI VOID *PsQueryStatistics = 0;
XBOXSYSAPI VOID *PsSetCreateThreadNotifyRoutine = 0;
XBOXSYSAPI VOID *PsTerminateSystemThread = 0;
XBOXSYSAPI VOID *PsThreadObjectType = 0;
