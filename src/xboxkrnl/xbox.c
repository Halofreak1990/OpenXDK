// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xbox.c
// *
// * note : XBox Kernel Definitions
// *
// ******************************************************************
#define _XBOXKRNL_INTERNAL_
#include "xboxkrnl/xboxkrnl.h"

// ******************************************************************
// * AvGetSavedDataAddress
// ******************************************************************
NTSYSAPI EXPORTNUM(1) PVOID NTAPI AvGetSavedDataAddress()
{
    return NULL;
}

// ******************************************************************
// * AvGetSavedDataAddress
// ******************************************************************
NTSYSAPI EXPORTNUM(2) VOID NTAPI AvSendTVEncoderOption
(
	IN	PVOID	RegisterBase, 
	IN	ULONG	Option, 
	IN	ULONG	Param, 
	OUT	ULONG	*Result
)
{
    return;
}

// ******************************************************************
// * AvSetDisplayMode
// ******************************************************************
NTSYSAPI EXPORTNUM(4) ULONG NTAPI AvSetDisplayMode
(
	IN PVOID	RegisterBase,
	IN ULONG	Step,
	IN ULONG	Mode,
	IN ULONG	Format,
	IN ULONG	Pitch,
	IN ULONG	FrameBuffer
)
{
	return 0;
}

// ******************************************************************
// * AvGetSavedDataAddress
// ******************************************************************
NTSYSAPI EXPORTNUM(4) VOID NTAPI AvSetSavedDataAddress
(
	IN PVOID	Address
)
{
	return;
}

NTSYSAPI VOID *FscGetCacheSize = 0;
NTSYSAPI VOID *FscInvalidateIdleBlocks = 0;
NTSYSAPI VOID *FscSetCacheSize = 0;
NTSYSAPI VOID *KdDebuggerEnabled = 0;
NTSYSAPI VOID *KdDebuggerNotPresent = 0;
NTSYSAPI VOID *KfRaiseIrql = 0;
NTSYSAPI VOID *KfLowerIrql = 0;
NTSYSAPI VOID *KiBugCheckData = 0;
NTSYSAPI VOID *KiUnlockDispatcherDatabase = 0;
NTSYSAPI VOID *LaunchDataPage = 0;
NTSYSAPI VOID *PhyGetLinkState = 0;
NTSYSAPI VOID *PhyInitialize = 0;
NTSYSAPI VOID *XboxEEPROMKey = 0;
NTSYSAPI VOID *XboxHardwareInfo = 0;
NTSYSAPI VOID *XboxHDKey = 0;
NTSYSAPI VOID *XboxKrnlVersion = 0;
NTSYSAPI VOID *XboxSignatureKey = 0;
NTSYSAPI VOID *XeImageFileName = 0;
NTSYSAPI VOID *XeLoadSection = 0;
NTSYSAPI VOID *XeUnloadSection = 0;
NTSYSAPI VOID *XcSHAInit = 0;
NTSYSAPI VOID *XcSHAUpdate = 0;
NTSYSAPI VOID *XcSHAFinal = 0;
NTSYSAPI VOID *XcRC4Key = 0;
NTSYSAPI VOID *XcRC4Crypt = 0;
NTSYSAPI VOID *XcHMAC = 0;
NTSYSAPI VOID *XcPKEncPublic = 0;
NTSYSAPI VOID *XcPKDecPrivate = 0;
NTSYSAPI VOID *XcPKGetKeyLen = 0;
NTSYSAPI VOID *XcVerifyPKCS1Signature = 0;
NTSYSAPI VOID *XcModExp = 0;
NTSYSAPI VOID *XcDESKeyParity = 0;
NTSYSAPI VOID *XcKeyTable = 0;
NTSYSAPI VOID *XcBlockCrypt = 0;
NTSYSAPI VOID *XcBlockCryptCBC = 0;
NTSYSAPI VOID *XcCryptService = 0;
NTSYSAPI VOID *XcUpdateCrypto = 0;
NTSYSAPI VOID *XboxLANKey = 0;
NTSYSAPI VOID *XboxAlternateSignatureKeys = 0;
NTSYSAPI VOID *XePublicKeyData = 0;
NTSYSAPI VOID *IdexChannelObject = 0;
NTSYSAPI VOID *xsnprintf = 0;  // prefixed with "x" to avoid xlibc collisions
NTSYSAPI VOID *xsprintf = 0;   // ""
NTSYSAPI VOID *xvsnprintf = 0; // ""
NTSYSAPI VOID *xvsprintf = 0;  // ""
