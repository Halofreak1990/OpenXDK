// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : ob.h
// *
// * note : XBox Kernel *Object Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_OB_H
#define XBOXKRNL_OB_H

#include "xboxkrnl.h"

XBSYSAPI VOID *ObCreateObject;
XBSYSAPI VOID *ObDirectoryObjectType;
XBSYSAPI VOID *ObInsertObject;
XBSYSAPI VOID *ObMakeTemporaryObject;
XBSYSAPI VOID *ObOpenObjectByName;
XBSYSAPI VOID *ObOpenObjectByPointer;
XBSYSAPI VOID *ObpObjectHandleTable;

// ******************************************************************
// * ObReferenceObjectByHandle
// ******************************************************************
// *
// * Turns a handle into a kernel object pointer. The ObjectType 
// * parameter specifies what type of object it is. This function 
// * also increments the object's reference count.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(246) BOOLEAN NTAPI ObReferenceObjectByHandle
(
    IN	HANDLE       Handle,
    IN	POBJECT_TYPE ObjectType OPTIONAL,
    OUT	PVOID        *Object
);

XBSYSAPI VOID *ObReferenceObjectByName;
XBSYSAPI VOID *ObReferenceObjectByPointer;
XBSYSAPI VOID *ObSymbolicLinkObjectType;

// ******************************************************************
// * ObfDereferenceObject
// ******************************************************************
// *
// * Decrements the object's reference count, deleting it if it is 
// * now unused.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(250) VOID NTAPI ObfDereferenceObject
(
    IN PVOID Object
);

// ******************************************************************
// * ObfReferenceObject
// ******************************************************************
// *
// * Increments the object's reference count.
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(251) VOID NTAPI ObfReferenceObject
(
    IN PVOID Object
);

#endif
