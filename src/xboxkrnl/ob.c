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
XBSYSAPI VOID *ObReferenceObjectByHandle = 0;
XBSYSAPI VOID *ObReferenceObjectByName = 0;
XBSYSAPI VOID *ObReferenceObjectByPointer = 0;
XBSYSAPI VOID *ObSymbolicLinkObjectType = 0;
XBSYSAPI VOID *ObfDereferenceObject = 0;
XBSYSAPI VOID *ObfReferenceObject = 0;
