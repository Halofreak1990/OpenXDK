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

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * kernel exports, others import
// ******************************************************************
#ifndef _XBOXKRNL_INTERNAL_
#define NTSYSAPI __declspec( dllimport )
#else
#define NTSYSAPI __declspec( dllexport )
#endif

// ******************************************************************
// * Null
// ******************************************************************
#ifndef	NULL
#define NULL                0
#endif

// ******************************************************************
// * CONST
// ******************************************************************
#define CONST               const

// ******************************************************************
// * Basic types
// ******************************************************************
typedef char                CHAR;
typedef unsigned char       BYTE;
typedef unsigned char       BOOLEAN;
typedef unsigned short      USHORT;
typedef	unsigned short		WORD;
typedef unsigned long       ULONG;
typedef	unsigned long       DWORD;
typedef unsigned long       SIZE_T;
typedef unsigned long       ACCESS_MASK;
typedef unsigned long       PHYSICAL_ADDRESS;
typedef	long				LONG;
typedef void                VOID;

// ******************************************************************
// * Pointer types
// ******************************************************************
typedef CHAR               *PCHAR;
typedef CHAR               *PCSZ;
typedef BYTE               *PBYTE;
typedef BOOLEAN            *PBOOLEAN;
typedef USHORT             *PUSHORT;
typedef ULONG              *PULONG;
typedef ACCESS_MASK        *PACCESS_MASK;
typedef LONG               *LONG_PTR;
typedef VOID               *PVOID;
typedef void               *HANDLE;
typedef HANDLE             *PHANDLE;

// ******************************************************************
// * NTSTATUS
// ******************************************************************
typedef long                NTSTATUS;

// ******************************************************************
// * calling conventions
// ******************************************************************
#define NTAPI               __stdcall
#define CDECL               __cdecl
#define DECLSPEC_NORETURN   __declspec( noreturn )

// ******************************************************************
// * documentation purposes only
// ******************************************************************
#define EXPORTNUM(a)
#define UNALIGNED
#define OPTIONAL
#define IN
#define OUT

// ******************************************************************
// * STRING
// ******************************************************************
typedef struct _STRING
{
    USHORT  Length;
    USHORT  MaximumLength;
    PCHAR   Buffer;
}
STRING, ANSI_STRING, *PSTRING, *PANSI_STRING;

// ******************************************************************
// * OBJECT_ATTRIBUTES
// ******************************************************************
typedef struct _OBJECT_ATTRIBUTES
{
    HANDLE  RootDirectory;
    PSTRING ObjectName;
    ULONG   Attributes;
}
OBJECT_ATTRIBUTES, *POBJECT_ATTRIBUTES;

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


