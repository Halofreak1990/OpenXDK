// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ps.h
// *
// * note : XBox Kernel *Process Structure* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_PS_H
#define XBOXKRNL_PS_H

NTSYSAPI VOID *PsCreateSystemThread;
NTSYSAPI VOID *PsCreateSystemThreadEx;
NTSYSAPI VOID *PsQueryStatistics;
NTSYSAPI VOID *PsSetCreateThreadNotifyRoutine;
NTSYSAPI VOID *PsTerminateSystemThread;
NTSYSAPI VOID *PsThreadObjectType;

#endif


