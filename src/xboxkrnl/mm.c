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
	IN ULONG			NumberOfBytes,
	IN PHYSICAL_ADDRESS LowestAcceptableAddress,
	IN PHYSICAL_ADDRESS HighestAcceptableAddress,
	IN ULONG Alignment	OPTIONAL,
	IN ULONG			ProtectionType
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

// ******************************************************************
// * MmGetPhysicalAddress
// ******************************************************************
NTSYSAPI EXPORTNUM(173) PHYSICAL_ADDRESS NTAPI MmGetPhysicalAddress
(
    IN PVOID   BaseAddress
)
{
    return 0;
}

NTSYSAPI VOID *MmIsAddressValid = 0;
NTSYSAPI VOID *MmLockUnlockBufferPages = 0;
NTSYSAPI VOID *MmLockUnlockPhysicalPage = 0;

// ******************************************************************
// * MmMapIoSpace
// ******************************************************************
NTSYSAPI EXPORTNUM(177) PVOID NTAPI MmMapIoSpace
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

// ******************************************************************
// * MmQueryAllocationSize
// ******************************************************************
NTSYSAPI EXPORTNUM(180) ULONG NTAPI MmQueryAllocationSize
(
    IN PVOID   BaseAddress
)
{
    return 0;
}

NTSYSAPI VOID *MmQueryStatistics = 0;
NTSYSAPI VOID *MmSetAddressProtect = 0;
NTSYSAPI VOID *MmUnmapIoSpace = 0;
