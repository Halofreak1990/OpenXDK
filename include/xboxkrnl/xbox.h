// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xbox.h
// *
// * note : XBox Kernel Declarations
// *
// ******************************************************************
#ifndef XBOX_H
#define XBOX_H

// ******************************************************************
// * AvGetSavedDataAddress
// ******************************************************************
// *
// * get current Display Start Address
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(1) PVOID NTAPI AvGetSavedDataAddress
(
	IN VOID
);

NTSYSAPI VOID *AvSendTVEncoderOption;


NTSYSAPI EXPORTNUM(4) ULONG NTAPI AvSetDisplayMode
(
	IN PVOID	Address,
	IN ULONG	Step,
	IN ULONG	Mode,
	IN ULONG	Format,
	IN ULONG	Pitch,
	IN ULONG	FrameBuffer
);
//NTSYSAPI VOID *AvSetDisplayMode;

// ******************************************************************
// * AvGetSavedDataAddress
// ******************************************************************
// *
// * get current Display Start Address
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(4) VOID NTAPI AvSetSavedDataAddress
(
	IN PVOID	Address
);
//NTSYSAPI VOID *AvSetSavedDataAddress;
NTSYSAPI VOID *FscGetCacheSize;
NTSYSAPI VOID *FscInvalidateIdleBlocks;
NTSYSAPI VOID *FscSetCacheSize;
NTSYSAPI VOID *KdDebuggerEnabled;
NTSYSAPI VOID *KdDebuggerNotPresent;
NTSYSAPI VOID *KfRaiseIrql;
NTSYSAPI VOID *KfLowerIrql;
NTSYSAPI VOID *KiBugCheckData;
NTSYSAPI VOID *KiUnlockDispatcherDatabase;
NTSYSAPI VOID *LaunchDataPage;
NTSYSAPI VOID *PhyGetLinkState;
NTSYSAPI VOID *PhyInitialize;
NTSYSAPI VOID *XboxEEPROMKey;
NTSYSAPI VOID *XboxHardwareInfo;
NTSYSAPI VOID *XboxHDKey;
NTSYSAPI VOID *XboxKrnlVersion;
NTSYSAPI VOID *XboxSignatureKey;
NTSYSAPI VOID *XeImageFileName;
NTSYSAPI VOID *XeLoadSection;
NTSYSAPI VOID *XeUnloadSection;
NTSYSAPI VOID *XcSHAInit;
NTSYSAPI VOID *XcSHAUpdate;
NTSYSAPI VOID *XcSHAFinal;
NTSYSAPI VOID *XcRC4Key;
NTSYSAPI VOID *XcRC4Crypt;
NTSYSAPI VOID *XcHMAC;
NTSYSAPI VOID *XcPKEncPublic;
NTSYSAPI VOID *XcPKDecPrivate;
NTSYSAPI VOID *XcPKGetKeyLen;
NTSYSAPI VOID *XcVerifyPKCS1Signature;
NTSYSAPI VOID *XcModExp;
NTSYSAPI VOID *XcDESKeyParity;
NTSYSAPI VOID *XcKeyTable;
NTSYSAPI VOID *XcBlockCrypt;
NTSYSAPI VOID *XcBlockCryptCBC;
NTSYSAPI VOID *XcCryptService;
NTSYSAPI VOID *XcUpdateCrypto;
NTSYSAPI VOID *XboxLANKey;
NTSYSAPI VOID *XboxAlternateSignatureKeys;
NTSYSAPI VOID *XePublicKeyData;
NTSYSAPI VOID *IdexChannelObject;
NTSYSAPI VOID *xsnprintf;     // prefixed with "x" to avoid xlibc collisions
NTSYSAPI VOID *xsprintf;      // ""
NTSYSAPI VOID *xvsnprintf;    // ""
NTSYSAPI VOID *xvsprintf;     // ""

#endif


