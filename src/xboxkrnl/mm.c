// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_io.c
// *
// * note : XBox Kernel *Memory Manager* Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

XBOXSYSAPI VOID *MmGlobalData = 0;

// ******************************************************************
// * MmAllocateContiguousMemory
// ******************************************************************
// *
// * allocates a range of physically contiguous, cache-aligned 
// * memory from nonpaged pool (main pool on xbox).
// *
// ******************************************************************
XBOXSYSAPI EXPORTNUM(165) PVOID NTAPI MmAllocateContiguousMemory
(
	IN ULONG NumberOfBytes
)
{
    return NULL;
}

// ******************************************************************
// * MmAllocateContiguousMemoryEx
// ******************************************************************
XBOXSYSAPI EXPORTNUM(166) PVOID NTAPI MmAllocateContiguousMemoryEx
(
	IN ULONG NumberOfBytes,
	IN PHYSICAL_ADDRESS LowestAcceptableAddress,
	IN PHYSICAL_ADDRESS HighestAcceptableAddress,
	IN ULONG Alignment OPTIONAL,
	IN ULONG ProtectionType
)
{
    return NULL;
}

XBOXSYSAPI VOID *MmAllocateSystemMemory = 0;
XBOXSYSAPI VOID *MmClaimGpuInstanceMemory = 0;
XBOXSYSAPI VOID *MmCreateKernelStack = 0;
XBOXSYSAPI VOID *MmDeleteKernelStack = 0;

// ******************************************************************
// * MmFreeContiguousMemory
// ******************************************************************
XBOXSYSAPI EXPORTNUM(171) VOID NTAPI MmFreeContiguousMemory
(
	IN PVOID BaseAddress
)
{
    return;
}

XBOXSYSAPI VOID *MmFreeSystemMemory = 0;
XBOXSYSAPI VOID *MmGetPhysicalAddress = 0;
XBOXSYSAPI VOID *MmIsAddressValid = 0;
XBOXSYSAPI VOID *MmLockUnlockBufferPages = 0;
XBOXSYSAPI VOID *MmLockUnlockPhysicalPage = 0;
XBOXSYSAPI VOID *MmMapIoSpace = 0;

// ******************************************************************
// * MmPersistContiguousMemory
// ******************************************************************
XBOXSYSAPI EXPORTNUM(178) VOID NTAPI MmPersistContiguousMemory
(
    IN PVOID   BaseAddress,
    IN ULONG   NumberOfBytes,
    IN BOOLEAN Persist
)
{
    return;
}

XBOXSYSAPI VOID *MmQueryAddressProtect = 0;
XBOXSYSAPI VOID *MmQueryAllocationSize = 0;
XBOXSYSAPI VOID *MmQueryStatistics = 0;
XBOXSYSAPI VOID *MmSetAddressProtect = 0;
XBOXSYSAPI VOID *MmUnmapIoSpace = 0;
