// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_mm.h
// *
// * note : XBox Kernel *Memory Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_MM_H
#define XBOXKRNL_MM_H

NTSYSAPI VOID *MmGlobalData;

// ******************************************************************
// * MmAllocateContiguousMemory
// ******************************************************************
// *
// * Allocates a range of physically contiguous, cache-aligned 
// * memory from nonpaged pool (main pool on xbox).
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(165) PVOID NTAPI MmAllocateContiguousMemory
(
	IN ULONG NumberOfBytes
);

// ******************************************************************
// * MmAllocateContiguousMemoryEx
// ******************************************************************
NTSYSAPI EXPORTNUM(166) PVOID NTAPI MmAllocateContiguousMemoryEx
(
	IN ULONG			NumberOfBytes,
	IN PHYSICAL_ADDRESS LowestAcceptableAddress,
	IN PHYSICAL_ADDRESS HighestAcceptableAddress,
	IN ULONG			Alignment OPTIONAL,
	IN ULONG			ProtectionType
);

NTSYSAPI VOID *MmAllocateSystemMemory;
NTSYSAPI VOID *MmClaimGpuInstanceMemory;
NTSYSAPI VOID *MmCreateKernelStack;
NTSYSAPI VOID *MmDeleteKernelStack;

// ******************************************************************
// * MmFreeContiguousMemory
// ******************************************************************
NTSYSAPI EXPORTNUM(171) VOID NTAPI MmFreeContiguousMemory
(
	IN PVOID BaseAddress
);

NTSYSAPI VOID *MmFreeSystemMemory;

// ******************************************************************
// * MmGetPhysicalAddress
// ******************************************************************
NTSYSAPI EXPORTNUM(173) PHYSICAL_ADDRESS NTAPI MmGetPhysicalAddress
(
    IN PVOID   BaseAddress
);

NTSYSAPI VOID *MmIsAddressValid;
NTSYSAPI VOID *MmLockUnlockBufferPages;
NTSYSAPI VOID *MmLockUnlockPhysicalPage;
NTSYSAPI VOID *MmMapIoSpace;

// ******************************************************************
// * MmPersistContiguousMemory
// ******************************************************************
NTSYSAPI EXPORTNUM(178) VOID NTAPI MmPersistContiguousMemory
(
    IN PVOID   BaseAddress,
    IN ULONG   NumberOfBytes,
    IN BOOLEAN Persist
);

NTSYSAPI VOID *MmQueryAddressProtect;

// ******************************************************************
// * MmQueryAllocationSize
// ******************************************************************
NTSYSAPI EXPORTNUM(180) ULONG NTAPI MmQueryAllocationSize
(
    IN PVOID   BaseAddress
);

NTSYSAPI VOID *MmQueryStatistics;
NTSYSAPI VOID *MmSetAddressProtect;
NTSYSAPI VOID *MmUnmapIoSpace;

#endif



