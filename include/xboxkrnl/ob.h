// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ob.h
// *
// * note : XBox Kernel *Object Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_OB_H
#define XBOXKRNL_OB_H

XBOXSYSAPI VOID *ObCreateObject;
XBOXSYSAPI VOID *ObDirectoryObjectType;
XBOXSYSAPI VOID *ObInsertObject;
XBOXSYSAPI VOID *ObMakeTemporaryObject;
XBOXSYSAPI VOID *ObOpenObjectByName;
XBOXSYSAPI VOID *ObOpenObjectByPointer;
XBOXSYSAPI VOID *ObpObjectHandleTable;
XBOXSYSAPI VOID *ObReferenceObjectByHandle;
XBOXSYSAPI VOID *ObReferenceObjectByName;
XBOXSYSAPI VOID *ObReferenceObjectByPointer;
XBOXSYSAPI VOID *ObSymbolicLinkObjectType;
XBOXSYSAPI VOID *ObfDereferenceObject;
XBOXSYSAPI VOID *ObfReferenceObject;

#endif