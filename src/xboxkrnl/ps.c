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

NTSYSAPI VOID *PsCreateSystemThread = 0;
NTSYSAPI VOID *PsCreateSystemThreadEx = 0;
NTSYSAPI VOID *PsQueryStatistics = 0;
NTSYSAPI VOID *PsSetCreateThreadNotifyRoutine = 0;
NTSYSAPI VOID *PsTerminateSystemThread = 0;
NTSYSAPI VOID *PsThreadObjectType = 0;
