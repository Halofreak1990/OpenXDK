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

XBOXSYSAPI VOID *AvGetSavedDataAddress;
XBOXSYSAPI VOID *AvSendTVEncoderOption;
XBOXSYSAPI VOID *AvSetDisplayMode;
XBOXSYSAPI VOID *AvSetSavedDataAddress;
XBOXSYSAPI VOID *FscGetCacheSize;
XBOXSYSAPI VOID *FscInvalidateIdleBlocks;
XBOXSYSAPI VOID *FscSetCacheSize;
XBOXSYSAPI VOID *KdDebuggerEnabled;
XBOXSYSAPI VOID *KdDebuggerNotPresent;
XBOXSYSAPI VOID *KfRaiseIrql;
XBOXSYSAPI VOID *KfLowerIrql;
XBOXSYSAPI VOID *KiBugCheckData;
XBOXSYSAPI VOID *KiUnlockDispatcherDatabase;
XBOXSYSAPI VOID *LaunchDataPage;
XBOXSYSAPI VOID *PhyGetLinkState;
XBOXSYSAPI VOID *PhyInitialize;
XBOXSYSAPI VOID *XboxEEPROMKey;
XBOXSYSAPI VOID *XboxHardwareInfo;
XBOXSYSAPI VOID *XboxHDKey;
XBOXSYSAPI VOID *XboxKrnlVersion;
XBOXSYSAPI VOID *XboxSignatureKey;
XBOXSYSAPI VOID *XeImageFileName;
XBOXSYSAPI VOID *XeLoadSection;
XBOXSYSAPI VOID *XeUnloadSection;
XBOXSYSAPI VOID *XcSHAInit;
XBOXSYSAPI VOID *XcSHAUpdate;
XBOXSYSAPI VOID *XcSHAFinal;
XBOXSYSAPI VOID *XcRC4Key;
XBOXSYSAPI VOID *XcRC4Crypt;
XBOXSYSAPI VOID *XcHMAC;
XBOXSYSAPI VOID *XcPKEncPublic;
XBOXSYSAPI VOID *XcPKDecPrivate;
XBOXSYSAPI VOID *XcPKGetKeyLen;
XBOXSYSAPI VOID *XcVerifyPKCS1Signature;
XBOXSYSAPI VOID *XcModExp;
XBOXSYSAPI VOID *XcDESKeyParity;
XBOXSYSAPI VOID *XcKeyTable;
XBOXSYSAPI VOID *XcBlockCrypt;
XBOXSYSAPI VOID *XcBlockCryptCBC;
XBOXSYSAPI VOID *XcCryptService;
XBOXSYSAPI VOID *XcUpdateCrypto;
XBOXSYSAPI VOID *XboxLANKey;
XBOXSYSAPI VOID *XboxAlternateSignatureKeys;
XBOXSYSAPI VOID *XePublicKeyData;
XBOXSYSAPI VOID *IdexChannelObject;
XBOXSYSAPI VOID *snprintf;
//XBOXSYSAPI VOID *sprintf;			// We dont want this oen
XBOXSYSAPI VOID *vsnprintf;
XBOXSYSAPI VOID *vsprintf;

#endif


