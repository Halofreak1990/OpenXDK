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

XBSYSAPI VOID *ObCreateObject;
XBSYSAPI VOID *ObDirectoryObjectType;
XBSYSAPI VOID *ObInsertObject;
XBSYSAPI VOID *ObMakeTemporaryObject;
XBSYSAPI VOID *ObOpenObjectByName;
XBSYSAPI VOID *ObOpenObjectByPointer;
XBSYSAPI VOID *ObpObjectHandleTable;
XBSYSAPI VOID *ObReferenceObjectByHandle;
XBSYSAPI VOID *ObReferenceObjectByName;
XBSYSAPI VOID *ObReferenceObjectByPointer;
XBSYSAPI VOID *ObSymbolicLinkObjectType;
XBSYSAPI VOID *ObfDereferenceObject;
XBSYSAPI VOID *ObfReferenceObject;

#endif


