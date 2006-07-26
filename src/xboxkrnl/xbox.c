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

// ******************************************************************
// * FscSetCacheSize
// ******************************************************************
XBSYSAPI EXPORTNUM(37) LONG NTAPI FscSetCacheSize(ULONG uCachePages)
{
    return 0;
}

XBSYSAPI VOID *KdDebuggerEnabled = 0;
XBSYSAPI VOID *KdDebuggerNotPresent = 0;
XBSYSAPI VOID *KfRaiseIrql = 0;
XBSYSAPI VOID *KfLowerIrql = 0;
XBSYSAPI VOID *KiBugCheckData = 0;
XBSYSAPI VOID *KiUnlockDispatcherDatabase = 0;

// ******************************************************************
// * LaunchDataPage (actually a pointer)
// ******************************************************************
XBSYSAPI PLAUNCH_DATA_PAGE LaunchDataPage = {0};

// ******************************************************************
// * PhyGetLinkState
// ******************************************************************
XBSYSAPI EXPORTNUM(252) ULONG NTAPI PhyGetLinkState
(
	IN ULONG	Mode
)
{
	return 0;
}

// ******************************************************************
// * PhyInitialize
// ******************************************************************
XBSYSAPI EXPORTNUM(253) ULONG NTAPI PhyInitialize
(
	IN ULONG	Parameter1,
	IN ULONG	Parameter2
)
{
	return 0;
}

// ******************************************************************
// * XboxEEPROMKey
// ******************************************************************
XBSYSAPI EXPORTNUM(321) UCHAR XboxEEPROMKey[16];

// ******************************************************************
// * XboxHardwareInfo
// ******************************************************************
XBSYSAPI EXPORTNUM(322) XBOX_HARDWARE_INFO XboxHardwareInfo;

// ******************************************************************
// * XboxHDKey
// ******************************************************************
XBSYSAPI EXPORTNUM(323) UCHAR XboxHDKey[16] = {0};

XBSYSAPI VOID *XboxKrnlVersion = 0;

// ******************************************************************
// * XboxSignatureKey
// ******************************************************************
XBSYSAPI EXPORTNUM(325) BYTE XboxSignatureKey[16];

XBSYSAPI VOID *XeImageFileName = 0;
XBSYSAPI VOID *XeLoadSection = 0;
XBSYSAPI VOID *XeUnloadSection = 0;

// ******************************************************************
// * XcSHAInit
// ******************************************************************
XBSYSAPI EXPORTNUM(335) VOID NTAPI XcSHAInit(UCHAR *pbSHAContext)
{
    return;
}

// ******************************************************************
// * XcSHAUpdate
// ******************************************************************
XBSYSAPI EXPORTNUM(336) VOID NTAPI XcSHAUpdate(UCHAR *pbSHAContext, UCHAR *pbInput, ULONG dwInputLength)
{
    return;
}

// ******************************************************************
// * XcSHAFinal
// ******************************************************************
XBSYSAPI EXPORTNUM(337) VOID NTAPI XcSHAFinal(UCHAR *pbSHAContext, UCHAR *pbDigest)
{
    return;
}


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

// ******************************************************************
// * XePublicKeyData
// ******************************************************************

XBSYSAPI EXPORTNUM(355) BYTE XePublicKeyData[276];

XBSYSAPI VOID *IdexChannelObject = 0;
