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

NTSYSAPI VOID *MmGlobalData = 0;

// ******************************************************************
// * MmAllocateContiguousMemory
// ******************************************************************
// *
// * allocates a range of physically contiguous, cache-aligned 
// * memory from nonpaged pool (main pool on xbox).
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(165) PVOID NTAPI MmAllocateContiguousMemory
(
	IN ULONG NumberOfBytes
)
{
    return NULL;
}

// ******************************************************************
// * MmAllocateContiguousMemoryEx
// ******************************************************************
NTSYSAPI EXPORTNUM(166) PVOID NTAPI MmAllocateContiguousMemoryEx
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

NTSYSAPI VOID *MmAllocateSystemMemory = 0;
NTSYSAPI VOID *MmClaimGpuInstanceMemory = 0;
NTSYSAPI VOID *MmCreateKernelStack = 0;
NTSYSAPI VOID *MmDeleteKernelStack = 0;

// ******************************************************************
// * MmFreeContiguousMemory
// ******************************************************************
NTSYSAPI EXPORTNUM(171) VOID NTAPI MmFreeContiguousMemory
(
	IN PVOID BaseAddress
)
{
    return;
}

NTSYSAPI VOID *MmFreeSystemMemory = 0;
NTSYSAPI VOID *MmGetPhysicalAddress = 0;
NTSYSAPI VOID *MmIsAddressValid = 0;
NTSYSAPI VOID *MmLockUnlockBufferPages = 0;
NTSYSAPI VOID *MmLockUnlockPhysicalPage = 0;
NTSYSAPI VOID *MmMapIoSpace = 0;

// ******************************************************************
// * MmPersistContiguousMemory
// ******************************************************************
NTSYSAPI EXPORTNUM(178) VOID NTAPI MmPersistContiguousMemory
(
    IN PVOID   BaseAddress,
    IN ULONG   NumberOfBytes,
    IN BOOLEAN Persist
)
{
    return;
}

NTSYSAPI VOID *MmQueryAddressProtect = 0;
NTSYSAPI VOID *MmQueryAllocationSize = 0;
NTSYSAPI VOID *MmQueryStatistics = 0;
NTSYSAPI VOID *MmSetAddressProtect = 0;
NTSYSAPI VOID *MmUnmapIoSpace = 0;
