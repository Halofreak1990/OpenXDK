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

NTSYSAPI VOID *ObCreateObject;
NTSYSAPI VOID *ObDirectoryObjectType;
NTSYSAPI VOID *ObInsertObject;
NTSYSAPI VOID *ObMakeTemporaryObject;
NTSYSAPI VOID *ObOpenObjectByName;
NTSYSAPI VOID *ObOpenObjectByPointer;
NTSYSAPI VOID *ObpObjectHandleTable;
NTSYSAPI VOID *ObReferenceObjectByHandle;
NTSYSAPI VOID *ObReferenceObjectByName;
NTSYSAPI VOID *ObReferenceObjectByPointer;
NTSYSAPI VOID *ObSymbolicLinkObjectType;
NTSYSAPI VOID *ObfDereferenceObject;
NTSYSAPI VOID *ObfReferenceObject;

#endif


