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

//XBSYSAPI VOID *PsCreateSystemThread = 0;
XBSYSAPI EXPORTNUM(254) NTSTATUS NTAPI PsCreateSystemThread
(
   PULONG lpThreadAttributes,               // SD
   DWORD dwStackSize,                       // initial stack size
   PKSTART_ROUTINE lpStartAddress,          // thread function
   VOID* lpParameter,                       // thread argument
   DWORD dwCreationFlags,                   // creation option
   DWORD* lpThreadId                        // thread identifier

)
{
    return 0;
};


// ******************************************************************
// * PsCreateSystemThreadEx
// ******************************************************************
XBSYSAPI EXPORTNUM(255) NTSTATUS NTAPI PsCreateSystemThreadEx
(
    OUT PHANDLE         ThreadHandle,
    IN  ULONG           ThreadExtraSize,
    IN  ULONG           KernelStackSize,
    IN  ULONG           TlsDataSize,
    OUT PULONG          ThreadId OPTIONAL,
    IN  PVOID           StartContext1,
    IN  PVOID           StartContext2,
    IN  BOOLEAN         CreateSuspended,
    IN  BOOLEAN         DebugStack,
    IN  PKSTART_ROUTINE StartRoutine
)
{
    return 0;
}

XBSYSAPI VOID *PsQueryStatistics = 0;
XBSYSAPI VOID *PsSetCreateThreadNotifyRoutine = 0;

// ******************************************************************
// * PsTerminateSystemThread
// ******************************************************************
XBSYSAPI EXPORTNUM(258) VOID NTAPI PsTerminateSystemThread(IN NTSTATUS ExitStatus)
{
    return;
}

//XBSYSAPI VOID *PsThreadObjectType = 0;
XBSYSAPI EXPORTNUM(259) volatile DWORD PsThreadObjectType;


