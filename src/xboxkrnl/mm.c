// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : io.c
// *
// * note : XBox Kernel *Memory Manager* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBSYSAPI VOID *MmGlobalData = 0;

// ******************************************************************
// * MmAllocateContiguousMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(165) PVOID NTAPI MmAllocateContiguousMemory
(
	IN ULONG NumberOfBytes
)
{
    return NULL;
}

// ******************************************************************
// * MmAllocateContiguousMemoryEx
// ******************************************************************
XBSYSAPI EXPORTNUM(166) PVOID NTAPI MmAllocateContiguousMemoryEx
(
	IN ULONG			NumberOfBytes,
	IN PHYSICAL_ADDRESS LowestAcceptableAddress,
	IN PHYSICAL_ADDRESS HighestAcceptableAddress,
	IN ULONG Alignment	OPTIONAL,
	IN ULONG			ProtectionType
)
{
    return NULL;
}

XBSYSAPI VOID *MmAllocateSystemMemory = 0;
XBSYSAPI VOID *MmClaimGpuInstanceMemory = 0;
XBSYSAPI VOID *MmCreateKernelStack = 0;
XBSYSAPI VOID *MmDeleteKernelStack = 0;

// ******************************************************************
// * MmFreeContiguousMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(171) VOID NTAPI MmFreeContiguousMemory
(
	IN PVOID BaseAddress
)
{
    return;
}

XBSYSAPI VOID *MmFreeSystemMemory = 0;

// ******************************************************************
// * MmGetPhysicalAddress
// ******************************************************************
XBSYSAPI EXPORTNUM(173) PHYSICAL_ADDRESS NTAPI MmGetPhysicalAddress
(
    IN PVOID   BaseAddress
)
{
    return 0;
}

XBSYSAPI VOID *MmIsAddressValid = 0;
XBSYSAPI VOID *MmLockUnlockBufferPages = 0;
XBSYSAPI VOID *MmLockUnlockPhysicalPage = 0;

// ******************************************************************
// * MmMapIoSpace
// ******************************************************************
XBSYSAPI EXPORTNUM(177) PVOID NTAPI MmMapIoSpace
(
    IN PHYSICAL_ADDRESS PhysicalAddress,
    IN ULONG            NumberOfBytes,
    IN ULONG            Protect
)
{
    return NULL;
}

// ******************************************************************
// * MmPersistContiguousMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(178) VOID NTAPI MmPersistContiguousMemory
(
    IN PVOID   BaseAddress,
    IN ULONG   NumberOfBytes,
    IN BOOLEAN Persist
)
{
    return;
}

XBSYSAPI VOID *MmQueryAddressProtect = 0;

// ******************************************************************
// * MmQueryAllocationSize
// ******************************************************************
XBSYSAPI EXPORTNUM(180) ULONG NTAPI MmQueryAllocationSize
(
    IN PVOID   BaseAddress
)
{
    return 0;
}

XBSYSAPI VOID *MmQueryStatistics = 0;
XBSYSAPI VOID *MmSetAddressProtect = 0;
XBSYSAPI VOID *MmUnmapIoSpace = 0;
