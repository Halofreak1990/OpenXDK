// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl.h
// *
// * note : XBox Kernel Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_H
#define XBOXKRNL_H

#include "types.h"
#ifdef __GNUC__
#include "winerror.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * dll import/export/extern
// ******************************************************************
#define DECLSPEC_IMPORT __declspec(dllimport)
#define DECLSPEC_EXPORT __declspec(dllexport)
#define DECLSPEC_EXTERN extern

// ******************************************************************
// * kernel exports, others either import or link locally
// ******************************************************************
#define XBSYSAPI DECLSPEC_IMPORT

#ifdef _XBOXKRNL_INTERNAL_
#undef  XBSYSAPI
#define XBSYSAPI DECLSPEC_EXPORT
#endif
#ifdef _XBOXKRNL_DEFEXTRN_
#undef  XBSYSAPI
#define XBSYSAPI DECLSPEC_EXTERN
#endif

// ******************************************************************
// * calling conventions
// ******************************************************************
#define INLINE __inline
#ifdef __GNUC__
	#define NTAPI               __attribute__((__stdcall__))
	#define DECLSPEC_NORETURN   __attribute__((noreturn))
#else
	#define NTAPI               __stdcall
	#define DECLSPEC_NORETURN   __declspec(noreturn)
#endif


// ******************************************************************
// * used for documentation purposes
// ******************************************************************
#define EXPORTNUM(ordinal)
#define IN
#define OUT
#define OPTIONAL
#define UNALIGNED

// ******************************************************************
// * Debug
// ******************************************************************
#include "dbg.h"

// ******************************************************************
// * Executive
// ******************************************************************
#include "ex.h"

// ******************************************************************
// * Hardware Abstraction Layer
// ******************************************************************
#include "hal.h"

// ******************************************************************
// * I/O Manager
// ******************************************************************
#include "io.h"

// ******************************************************************
// * Kernel
// ******************************************************************
#include "kernel.h"

// ******************************************************************
// * Memory Manager
// ******************************************************************
#include "mm.h"

// ******************************************************************
// * NT
// ******************************************************************
#include "nt.h"

// ******************************************************************
// * Object Manager
// ******************************************************************
#include "ob.h"

// ******************************************************************
// * Process Structure
// ******************************************************************
#include "ps.h"

// ******************************************************************
// * Run-time Library
// ******************************************************************
#include "rtl.h"

// ******************************************************************
// * XBox
// ******************************************************************
#include "xbox.h"

#if defined(__cplusplus)
}
#endif

#endif


