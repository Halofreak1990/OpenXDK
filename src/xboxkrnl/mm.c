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

// ******************************************************************
// * MmAllocateSystemMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(167) PVOID NTAPI MmAllocateSystemMemory
(
	ULONG NumberOfBytes,
	ULONG Protect
)
{
	return NULL;
}

// ******************************************************************
// * MmClaimGpuInstanceMemory;
// ******************************************************************
XBSYSAPI EXPORTNUM(168) PVOID NTAPI MmClaimGpuInstanceMemory
(
	   ULONG Mask,
	IN PVOID pBaseAddr
)
{
	return NULL;
}

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

// ******************************************************************
// * MmFreeSystemMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(172) NTSTATUS NTAPI MmFreeSystemMemory
(
	PVOID BaseAddress,
	ULONG NumberOfBytes
)
{
	return STATUS_SUCCESS;
}

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

// ******************************************************************
// * MmIsAddressValid
// ******************************************************************
XBSYSAPI EXPORTNUM(174) BOOLEAN NTAPI MmIsAddressValid
(
	IN PVOID VirtualAddress
)
{
	return TRUE;
}

XBSYSAPI EXPORTNUM(175) PHYSICAL_ADDRESS NTAPI MmLockUnlockBufferPages
(
	IN PHYSICAL_ADDRESS BaseAddress,
	IN ULONG            NumberOfBytes,
	IN ULONG            Protect
)
{
	return 0;
}

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

// ******************************************************************
// * MmQueryAddressProtect
// ******************************************************************
XBSYSAPI EXPORTNUM(179) LONG NTAPI MmQueryAddressProtect
(
	IN	PVOID	Address
)
{
	return 0;
}

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

// ******************************************************************
// * MmQueryStatistics
// ******************************************************************
XBSYSAPI EXPORTNUM(181) NTSTATUS NTAPI MmQueryStatistics
(
    OUT PMM_STATISTICS MemoryStatistics
)
{
    return STATUS_SUCCESS;
}

// ******************************************************************
// * MmQueryAllocationSize
// ******************************************************************
XBSYSAPI EXPORTNUM(182) VOID NTAPI MmSetAddressProtect
(
    IN PVOID BaseAddress,
    IN ULONG NumberOfBytes,
    IN ULONG NewProtect
)
{
    return;
}

// ******************************************************************
// * MmUnmapIoSpace
// ******************************************************************
XBSYSAPI EXPORTNUM(183) PVOID NTAPI MmUnmapIoSpace
(
	IN PVOID BaseAddress,
	IN ULONG NumberOfBytes
)
{
	return NULL;
}
