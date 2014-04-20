// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : dbg.h
// *
// * note : XBox Kernel *Debug* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_DBG_H
#define XBOXKRNL_DBG_H

#include "xboxkrnl.h"

// ******************************************************************
// * DbgBreakPoint
// ******************************************************************
XBSYSAPI EXPORTNUM(5) VOID NTAPI DbgBreakPoint();

XBSYSAPI EXPORTNUM(6) VOID *DbgBreakPointWithStatus;

// ******************************************************************
// * DbgLoadImageSymbols
// ******************************************************************
XBSYSAPI EXPORTNUM(7) NTSTATUS NTAPI DbgLoadImageSymbols
(
	IN	PANSI_STRING	Name,
	IN	ULONG		Base,
	IN	ULONG		Unknown3
);

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
);

XBSYSAPI EXPORTNUM(10) VOID *DbgPrompt;

// ******************************************************************
// * DbgUnLoadImageSymbols
// ******************************************************************
XBSYSAPI EXPORTNUM(11) NTSTATUS NTAPI DbgUnLoadImageSymbols
(
	IN PANSI_STRING Name,
	IN ULONG Base,
	IN ULONG Unknown3
);

#endif
