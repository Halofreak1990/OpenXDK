// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xohci_pci.h
// *
// * note : XBox USB Open Host Controller Interface (PCI)
// *
// ******************************************************************
#include "openxdk.h"
#include <stdio.h>

// ******************************************************************
// * xohci_pci_init
// ******************************************************************
void xohci_pci_init()
{
    PCI_COMMON_CONFIG config_info;

    // ******************************************************************
    // * retrieve g_ohci_regs
    // ******************************************************************
    {
        PCI_SLOT_NUMBER slot_number;

        RtlZeroMemory(&slot_number, sizeof(slot_number));

        slot_number.u.bits.DeviceNumber   = PCI_USB0_DEVICE_ID;
        slot_number.u.bits.FunctionNumber = PCI_USB0_FUNCTION_ID;

        HalReadWritePCISpace(0, slot_number.u.AsULONG, 0, &config_info, PCI_COMMON_HDR_LENGTH, FALSE);

        if(config_info.VendorID != PCI_VENDOR_NVIDIA_CORPORATION || config_info.DeviceID != PCI_USB0_OHCI_CONTROLLER)
            HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error

        // ******************************************************************
        // * obtain io_addr pointer
        // ******************************************************************
        {
            PHYSICAL_ADDRESS io_phys = (PHYSICAL_ADDRESS)(config_info.u.type0.BaseAddresses[0] & 0xFFFFF000);

            g_ohci_regs = MmMapIoSpace(io_phys, 0x16, PAGE_READWRITE | PAGE_NOCACHE);
        }
    }

    return;
}