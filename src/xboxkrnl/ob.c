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

NTSYSAPI VOID *ObCreateObject = 0;
NTSYSAPI VOID *ObDirectoryObjectType = 0;
NTSYSAPI VOID *ObInsertObject = 0;
NTSYSAPI VOID *ObMakeTemporaryObject = 0;
NTSYSAPI VOID *ObOpenObjectByName = 0;
NTSYSAPI VOID *ObOpenObjectByPointer = 0;
NTSYSAPI VOID *ObpObjectHandleTable = 0;
NTSYSAPI VOID *ObReferenceObjectByHandle = 0;
NTSYSAPI VOID *ObReferenceObjectByName = 0;
NTSYSAPI VOID *ObReferenceObjectByPointer = 0;
NTSYSAPI VOID *ObSymbolicLinkObjectType = 0;
NTSYSAPI VOID *ObfDereferenceObject = 0;
NTSYSAPI VOID *ObfReferenceObject = 0;
