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
// *
// * allocates a range of physically contiguous, cache-aligned 
// * memory from nonpaged pool (main pool on xbox).
// *
// ******************************************************************
XBOXSYSAPI EXPORTNUM(1) PVOID NTAPI AvGetSavedDataAddress
(
	IN VOID
)
{
    return NULL;
}

XBOXSYSAPI VOID *AvSendTVEncoderOption = 0;
XBOXSYSAPI VOID *AvSetDisplayMode = 0;
XBOXSYSAPI VOID *AvSetSavedDataAddress = 0;
XBOXSYSAPI VOID *FscGetCacheSize = 0;
XBOXSYSAPI VOID *FscInvalidateIdleBlocks = 0;
XBOXSYSAPI VOID *FscSetCacheSize = 0;
XBOXSYSAPI VOID *KdDebuggerEnabled = 0;
XBOXSYSAPI VOID *KdDebuggerNotPresent = 0;
XBOXSYSAPI VOID *KfRaiseIrql = 0;
XBOXSYSAPI VOID *KfLowerIrql = 0;
XBOXSYSAPI VOID *KiBugCheckData = 0;
XBOXSYSAPI VOID *KiUnlockDispatcherDatabase = 0;
XBOXSYSAPI VOID *LaunchDataPage = 0;
XBOXSYSAPI VOID *PhyGetLinkState = 0;
XBOXSYSAPI VOID *PhyInitialize = 0;
XBOXSYSAPI VOID *XboxEEPROMKey = 0;
XBOXSYSAPI VOID *XboxHardwareInfo = 0;
XBOXSYSAPI VOID *XboxHDKey = 0;
XBOXSYSAPI VOID *XboxKrnlVersion = 0;
XBOXSYSAPI VOID *XboxSignatureKey = 0;
XBOXSYSAPI VOID *XeImageFileName = 0;
XBOXSYSAPI VOID *XeLoadSection = 0;
XBOXSYSAPI VOID *XeUnloadSection = 0;
XBOXSYSAPI VOID *XcSHAInit = 0;
XBOXSYSAPI VOID *XcSHAUpdate = 0;
XBOXSYSAPI VOID *XcSHAFinal = 0;
XBOXSYSAPI VOID *XcRC4Key = 0;
XBOXSYSAPI VOID *XcRC4Crypt = 0;
XBOXSYSAPI VOID *XcHMAC = 0;
XBOXSYSAPI VOID *XcPKEncPublic = 0;
XBOXSYSAPI VOID *XcPKDecPrivate = 0;
XBOXSYSAPI VOID *XcPKGetKeyLen = 0;
XBOXSYSAPI VOID *XcVerifyPKCS1Signature = 0;
XBOXSYSAPI VOID *XcModExp = 0;
XBOXSYSAPI VOID *XcDESKeyParity = 0;
XBOXSYSAPI VOID *XcKeyTable = 0;
XBOXSYSAPI VOID *XcBlockCrypt = 0;
XBOXSYSAPI VOID *XcBlockCryptCBC = 0;
XBOXSYSAPI VOID *XcCryptService = 0;
XBOXSYSAPI VOID *XcUpdateCrypto = 0;
XBOXSYSAPI VOID *XboxLANKey = 0;
XBOXSYSAPI VOID *XboxAlternateSignatureKeys = 0;
XBOXSYSAPI VOID *XePublicKeyData = 0;
XBOXSYSAPI VOID *IdexChannelObject = 0;
XBOXSYSAPI VOID *xsnprintf = 0;  // prefixed with "x" to avoid xlibc collisions
XBOXSYSAPI VOID *xsprintf = 0;   // ""
XBOXSYSAPI VOID *xvsnprintf = 0; // ""
XBOXSYSAPI VOID *xvsprintf = 0;  // ""
