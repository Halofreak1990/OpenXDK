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
XBSYSAPI EXPORTNUM(1) PVOID NTAPI AvGetSavedDataAddress()
{
    return NULL;
}

// ******************************************************************
// * AvGetSavedDataAddress
// ******************************************************************
XBSYSAPI EXPORTNUM(2) VOID NTAPI AvSendTVEncoderOption
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
XBSYSAPI EXPORTNUM(4) ULONG NTAPI AvSetDisplayMode
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
XBSYSAPI EXPORTNUM(4) VOID NTAPI AvSetSavedDataAddress
(
	IN PVOID	Address
)
{
	return;
}

XBSYSAPI VOID *FscGetCacheSize = 0;
XBSYSAPI VOID *FscInvalidateIdleBlocks = 0;
XBSYSAPI VOID *FscSetCacheSize = 0;
XBSYSAPI VOID *KdDebuggerEnabled = 0;
XBSYSAPI VOID *KdDebuggerNotPresent = 0;
XBSYSAPI VOID *KfRaiseIrql = 0;
XBSYSAPI VOID *KfLowerIrql = 0;
XBSYSAPI VOID *KiBugCheckData = 0;
XBSYSAPI VOID *KiUnlockDispatcherDatabase = 0;
XBSYSAPI VOID *LaunchDataPage = 0;
XBSYSAPI VOID *PhyGetLinkState = 0;
XBSYSAPI VOID *PhyInitialize = 0;

// ******************************************************************
// * XboxEEPROMKey
// ******************************************************************
XBSYSAPI EXPORTNUM(321) UCHAR XboxEEPROMKey[16];

XBSYSAPI VOID *XboxHardwareInfo = 0;
XBSYSAPI VOID *XboxHDKey = 0;
XBSYSAPI VOID *XboxKrnlVersion = 0;
XBSYSAPI VOID *XboxSignatureKey = 0;
XBSYSAPI VOID *XeImageFileName = 0;
XBSYSAPI VOID *XeLoadSection = 0;
XBSYSAPI VOID *XeUnloadSection = 0;
XBSYSAPI VOID *XcSHAInit = 0;
XBSYSAPI VOID *XcSHAUpdate = 0;
XBSYSAPI VOID *XcSHAFinal = 0;
XBSYSAPI VOID *XcRC4Key = 0;
XBSYSAPI VOID *XcRC4Crypt = 0;
XBSYSAPI VOID *XcHMAC = 0;
XBSYSAPI VOID *XcPKEncPublic = 0;
XBSYSAPI VOID *XcPKDecPrivate = 0;
XBSYSAPI VOID *XcPKGetKeyLen = 0;
XBSYSAPI VOID *XcVerifyPKCS1Signature = 0;
XBSYSAPI VOID *XcModExp = 0;
XBSYSAPI VOID *XcDESKeyParity = 0;
XBSYSAPI VOID *XcKeyTable = 0;
XBSYSAPI VOID *XcBlockCrypt = 0;
XBSYSAPI VOID *XcBlockCryptCBC = 0;
XBSYSAPI VOID *XcCryptService = 0;
XBSYSAPI VOID *XcUpdateCrypto = 0;
XBSYSAPI VOID *XboxLANKey = 0;
XBSYSAPI VOID *XboxAlternateSignatureKeys = 0;
XBSYSAPI VOID *XePublicKeyData = 0;
XBSYSAPI VOID *IdexChannelObject = 0;
XBSYSAPI VOID *xsnprintf = 0;  // prefixed with "x" to avoid xlibc collisions
XBSYSAPI VOID *xsprintf = 0;   // ""
XBSYSAPI VOID *xvsnprintf = 0; // ""
XBSYSAPI VOID *xvsprintf = 0;  // ""
