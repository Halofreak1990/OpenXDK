// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ob.c
// *
// * note : XBox Kernel *Object Manager* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBSYSAPI VOID *ObCreateObject = 0;
XBSYSAPI VOID *ObDirectoryObjectType = 0;
XBSYSAPI VOID *ObInsertObject = 0;
XBSYSAPI VOID *ObMakeTemporaryObject = 0;
XBSYSAPI VOID *ObOpenObjectByName = 0;
XBSYSAPI VOID *ObOpenObjectByPointer = 0;
XBSYSAPI VOID *ObpObjectHandleTable = 0;

// ******************************************************************
// * ObReferenceObjectByHandle
// ******************************************************************
XBSYSAPI EXPORTNUM(246) BOOLEAN NTAPI ObReferenceObjectByHandle
(
	IN	HANDLE       Handle,
	IN	POBJECT_TYPE ObjectType OPTIONAL,
	OUT	PVOID        *Object
)
{
	return TRUE;
}

XBSYSAPI VOID *ObReferenceObjectByName = 0;
XBSYSAPI VOID *ObReferenceObjectByPointer = 0;
XBSYSAPI VOID *ObSymbolicLinkObjectType = 0;

// ******************************************************************
// * ObfDereferenceObject
// ******************************************************************
XBSYSAPI EXPORTNUM(250) VOID NTAPI ObfDereferenceObject
(
	IN PVOID Object
)
{
	return;
}

// ******************************************************************
// * ObfReferenceObject
// ******************************************************************
XBSYSAPI EXPORTNUM(251) VOID NTAPI ObfReferenceObject
(
	IN PVOID Object
)
{
	return;
}
