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

XBOXSYSAPI VOID *MmGlobalData;

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
);

// ******************************************************************
// * MmAllocateContiguousMemoryEx
// ******************************************************************
XBOXSYSAPI EXPORTNUM(166) PVOID NTAPI MmAllocateContiguousMemoryEx
(
	IN ULONG			NumberOfBytes,
	IN PHYSICAL_ADDRESS LowestAcceptableAddress,
	IN PHYSICAL_ADDRESS HighestAcceptableAddress,
	IN ULONG			Alignment OPTIONAL,
	IN ULONG			ProtectionType
);

XBOXSYSAPI VOID *MmAllocateSystemMemory;
XBOXSYSAPI VOID *MmClaimGpuInstanceMemory;
XBOXSYSAPI VOID *MmCreateKernelStack;
XBOXSYSAPI VOID *MmDeleteKernelStack;

// ******************************************************************
// * MmFreeContiguousMemory
// ******************************************************************
XBOXSYSAPI EXPORTNUM(171) VOID NTAPI MmFreeContiguousMemory
(
	IN PVOID BaseAddress
);

XBOXSYSAPI VOID *MmFreeSystemMemory;
XBOXSYSAPI VOID *MmGetPhysicalAddress;
XBOXSYSAPI VOID *MmIsAddressValid;
XBOXSYSAPI VOID *MmLockUnlockBufferPages;
XBOXSYSAPI VOID *MmLockUnlockPhysicalPage;
XBOXSYSAPI VOID *MmMapIoSpace;

// ******************************************************************
// * MmPersistContiguousMemory
// ******************************************************************
XBOXSYSAPI EXPORTNUM(178) VOID NTAPI MmPersistContiguousMemory
(
    IN PVOID   BaseAddress,
    IN ULONG   NumberOfBytes,
    IN BOOLEAN Persist
);

XBOXSYSAPI VOID *MmQueryAddressProtect;
XBOXSYSAPI VOID *MmQueryAllocationSize;
XBOXSYSAPI VOID *MmQueryStatistics;
XBOXSYSAPI VOID *MmSetAddressProtect;
XBOXSYSAPI VOID *MmUnmapIoSpace;

#endif



