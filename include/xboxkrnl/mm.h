// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : mm.h
// *
// * note : XBox Kernel *Memory Manager* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_MM_H
#define XBOXKRNL_MM_H

XBSYSAPI VOID *MmGlobalData;

// ******************************************************************
// * MmAllocateContiguousMemory
// ******************************************************************
// *
// * Allocates a range of physically contiguous, cache-aligned 
// * memory from nonpaged pool (main pool on xbox).
// *
// ******************************************************************
XBSYSAPI EXPORTNUM(165) PVOID NTAPI MmAllocateContiguousMemory
(
	IN ULONG NumberOfBytes
);

// ******************************************************************
// * MmAllocateContiguousMemoryEx
// ******************************************************************
XBSYSAPI EXPORTNUM(166) PVOID NTAPI MmAllocateContiguousMemoryEx
(
	IN ULONG			NumberOfBytes,
	IN PHYSICAL_ADDRESS LowestAcceptableAddress,
	IN PHYSICAL_ADDRESS HighestAcceptableAddress,
	IN ULONG			Alignment OPTIONAL,
	IN ULONG			ProtectionType
);

XBSYSAPI VOID *MmAllocateSystemMemory;
XBSYSAPI VOID *MmClaimGpuInstanceMemory;
XBSYSAPI VOID *MmCreateKernelStack;
XBSYSAPI VOID *MmDeleteKernelStack;

// ******************************************************************
// * MmFreeContiguousMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(171) VOID NTAPI MmFreeContiguousMemory
(
	IN PVOID BaseAddress
);

XBSYSAPI VOID *MmFreeSystemMemory;

// ******************************************************************
// * MmGetPhysicalAddress
// ******************************************************************
XBSYSAPI EXPORTNUM(173) PHYSICAL_ADDRESS NTAPI MmGetPhysicalAddress
(
    IN PVOID   BaseAddress
);

XBSYSAPI VOID *MmIsAddressValid;
XBSYSAPI VOID *MmLockUnlockBufferPages;
XBSYSAPI VOID *MmLockUnlockPhysicalPage;

// ******************************************************************
// * MmMapIoSpace
// ******************************************************************
XBSYSAPI EXPORTNUM(177) PVOID NTAPI MmMapIoSpace
(
    IN PHYSICAL_ADDRESS PhysicalAddress,
    IN ULONG            NumberOfBytes,
    IN ULONG            Protect
);

// ******************************************************************
// * MmPersistContiguousMemory
// ******************************************************************
XBSYSAPI EXPORTNUM(178) VOID NTAPI MmPersistContiguousMemory
(
    IN PVOID   BaseAddress,
    IN ULONG   NumberOfBytes,
    IN BOOLEAN Persist
);

XBSYSAPI VOID *MmQueryAddressProtect;

// ******************************************************************
// * MmQueryAllocationSize
// ******************************************************************
XBSYSAPI EXPORTNUM(180) ULONG NTAPI MmQueryAllocationSize
(
    IN PVOID   BaseAddress
);

XBSYSAPI VOID *MmQueryStatistics;
XBSYSAPI VOID *MmSetAddressProtect;
XBSYSAPI VOID *MmUnmapIoSpace;

#endif



