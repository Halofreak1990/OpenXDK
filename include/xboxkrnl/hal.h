// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxkrnl_hal.h
// *
// * note : XBox Kernel *Hardware Abstraction Layer* Declarations
// *
// ******************************************************************
#ifndef XBOXKRNL_HAL_H
#define XBOXKRNL_HAL_H

// ******************************************************************
// * RETURN_FIRMWARE
// ******************************************************************
typedef enum _RETURN_FIRMWARE
{
    ReturnFirmwareHalt          = 0x0,
    ReturnFirmwareReboot        = 0x1,
    ReturnFirmwareQuickReboot   = 0x2,
    ReturnFirmwareHard          = 0x3,
    ReturnFirmwareFatal         = 0x4,
    ReturnFirmwareAll           = 0x5
}
RETURN_FIRMWARE, *LPRETURN_FIRMWARE;

NTSYSAPI VOID *HalReadSMCTrayState;
NTSYSAPI VOID *HalClearSoftwareInterrupt;
NTSYSAPI VOID *HalDisableSystemInterrupt;
NTSYSAPI VOID *HalDiskCachePartitionCount;
NTSYSAPI VOID *HalDiskModelNumber;
NTSYSAPI VOID *HalDiskSerialNumber;
NTSYSAPI VOID *HalEnableSystemInterrupt;
NTSYSAPI VOID *HalGetInterruptVector;
NTSYSAPI VOID *HalReadSMBusValue;

// ******************************************************************
// * PCI_SLOT_NUMBER
// ******************************************************************
typedef struct _PCI_SLOT_NUMBER
{
    union
    {
        struct
        {
            ULONG   DeviceNumber:5;
            ULONG   FunctionNumber:3;
            ULONG   Reserved:18;
        }
        bits;

        ULONG   AsULONG;
    }u;
}
PCI_SLOT_NUMBER, *PPCI_SLOT_NUMBER;

#define PCI_TYPE0_ADDRESSES             6
#define PCI_TYPE1_ADDRESSES             2
#define PCI_TYPE2_ADDRESSES             5

// ******************************************************************
// * PCI_COMMON_CONFIG
// ******************************************************************
typedef struct _PCI_COMMON_CONFIG
{
    USHORT  VendorID;                   // (ro)
    USHORT  DeviceID;                   // (ro)
    USHORT  Command;                    // Device control
    USHORT  Status;
    UCHAR   RevisionID;                 // (ro)
    UCHAR   ProgIf;                     // (ro)
    UCHAR   SubClass;                   // (ro)
    UCHAR   BaseClass;                  // (ro)
    UCHAR   CacheLineSize;              // (ro+)
    UCHAR   LatencyTimer;               // (ro+)
    UCHAR   HeaderType;                 // (ro)
    UCHAR   BIST;                       // Built in self test

    union
    {
        struct _PCI_HEADER_TYPE_0
        {
            ULONG   BaseAddresses[PCI_TYPE0_ADDRESSES];
            ULONG   CIS;
            USHORT  SubVendorID;
            USHORT  SubSystemID;
            ULONG   ROMBaseAddress;
            UCHAR   CapabilitiesPtr;
            UCHAR   Reserved1[3];
            ULONG   Reserved2;
            UCHAR   InterruptLine;      //
            UCHAR   InterruptPin;       // (ro)
            UCHAR   MinimumGrant;       // (ro)
            UCHAR   MaximumLatency;     // (ro)
        }
        type0;
    }u;

    UCHAR DeviceSpecific[192];

}
PCI_COMMON_CONFIG, *PPCI_COMMON_CONFIG;

// ******************************************************************
// * HalReadWritePCISpace
// ******************************************************************
NTSYSAPI EXPORTNUM(46) VOID NTAPI HalReadWritePCISpace
(
  IN ULONG   BusNumber,
  IN ULONG   SlotNumber,
  IN ULONG   RegisterNumber,
  IN PVOID   Buffer,
  IN ULONG   Length,
  IN BOOLEAN WritePCISpace
);

NTSYSAPI VOID *HalRegisterShutdownNotification;
NTSYSAPI VOID *HalRequestSoftwareInterrupt;

// ******************************************************************
// * HalReturnToFirmware
// ******************************************************************
// *
// * Reboot / Shutdown / Etc
// *
// ******************************************************************
NTSYSAPI EXPORTNUM(49) VOID DECLSPEC_NORETURN HalReturnToFirmware
(
	RETURN_FIRMWARE Routine
);

NTSYSAPI VOID *HalWriteSMBusValue;
NTSYSAPI VOID *HalBootSMCVideoMode;
NTSYSAPI VOID *HalIsResetOrShutdownPending;
NTSYSAPI VOID *HalInitiateShutdown;
NTSYSAPI VOID *HalEnableSecureTrayEject;
NTSYSAPI VOID *HalWriteSMCScratchRegister;
NTSYSAPI VOID *READ_PORT_BUFFER_UCHAR;
NTSYSAPI VOID *READ_PORT_BUFFER_USHORT;
NTSYSAPI VOID *READ_PORT_BUFFER_ULONG;
NTSYSAPI VOID *WRITE_PORT_BUFFER_UCHAR;
NTSYSAPI VOID *WRITE_PORT_BUFFER_USHORT;
NTSYSAPI VOID *WRITE_PORT_BUFFER_ULONG;

#endif


