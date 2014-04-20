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

// ******************************************************************
// * DbgBreakPoint
// ******************************************************************
XBSYSAPI EXPORTNUM(5) VOID NTAPI DbgBreakPoint()
{
	return;
}

XBSYSAPI EXPORTNUM(6) VOID *DbgBreakPointWithStatus = 0;

// ******************************************************************
// * DbgLoadImageSymbols
// ******************************************************************
XBSYSAPI EXPORTNUM(7) NTSTATUS NTAPI DbgLoadImageSymbols
(
	IN	PANSI_STRING	Name,
	IN	ULONG		Base,
	IN	ULONG		Unknown3
)
{
	return 0;
}

// ******************************************************************
// * DbgPrint
// ******************************************************************
// *
// * Displays a message on the debugger.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(8) ULONG __cdecl DbgPrint
(
	IN PCSZ Format,
	...
)
{
	return 0;
}

XBSYSAPI EXPORTNUM(10) VOID *DbgPrompt;

// ******************************************************************
// * DbgUnLoadImageSymbols
// ******************************************************************
XBSYSAPI EXPORTNUM(11) NTSTATUS NTAPI DbgUnLoadImageSymbols
(
	IN PANSI_STRING Name,
	IN ULONG Base,
	IN ULONG Unknown3
)
{
	return 0;
}
