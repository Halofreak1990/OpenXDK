// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_ob.c
// *
// * note : XBox Kernel *Object Manager* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBOXSYSAPI VOID *ObCreateObject = 0;
XBOXSYSAPI VOID *ObDirectoryObjectType = 0;
XBOXSYSAPI VOID *ObInsertObject = 0;
XBOXSYSAPI VOID *ObMakeTemporaryObject = 0;
XBOXSYSAPI VOID *ObOpenObjectByName = 0;
XBOXSYSAPI VOID *ObOpenObjectByPointer = 0;
XBOXSYSAPI VOID *ObpObjectHandleTable = 0;
XBOXSYSAPI VOID *ObReferenceObjectByHandle = 0;
XBOXSYSAPI VOID *ObReferenceObjectByName = 0;
XBOXSYSAPI VOID *ObReferenceObjectByPointer = 0;
XBOXSYSAPI VOID *ObSymbolicLinkObjectType = 0;
XBOXSYSAPI VOID *ObfDereferenceObject = 0;
XBOXSYSAPI VOID *ObfReferenceObject = 0;
