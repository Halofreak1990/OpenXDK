// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ps.h
// *
// * note : XBox Kernel *Process Structure* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_PS_H
#define XBOXKRNL_PS_H

XBOXSYSAPI VOID *PsCreateSystemThread;
XBOXSYSAPI VOID *PsCreateSystemThreadEx;
XBOXSYSAPI VOID *PsQueryStatistics;
XBOXSYSAPI VOID *PsSetCreateThreadNotifyRoutine;
XBOXSYSAPI VOID *PsTerminateSystemThread;
XBOXSYSAPI VOID *PsThreadObjectType;

#endif