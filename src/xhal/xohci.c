// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xohci.h
// *
// * note : XBox USB Open Host Controller Interface
// *
// ******************************************************************
#include "openxdk.h"
#include <stdio.h>

// ******************************************************************
// * xohci_init
// ******************************************************************
void xohci_init()
{
    char buffer[1024];

    xohci_pci_init();

    // ******************************************************************
    // * verify revision (BCD representation of the lowest 8 bits)
    // ******************************************************************
    {
        uint32 revision = READ_REGISTER_ULONG(&g_ohci_regs->hc_revision) & 0x000000FF;

        if(revision != 0x10)
            HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error
    }

    // ******************************************************************
    // * allocate necessary host controller structures
    // ******************************************************************
    {
        // TODO: verify this aligns properly, etc
        xohci_hcca *hcca = MmAllocateContiguousMemoryEx(256, 0, -1, 256, PAGE_READWRITE);

        if(hcca == NULL)
            HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error

        g_xohci.m_hcca = (xohci_hcca*)MmGetPhysicalAddress(hcca);

        WRITE_REGISTER_ULONG(&g_ohci_regs->hc_hcca, (ULONG)g_xohci.m_hcca);
    }

    // ******************************************************************
    // * verify state is USB_RESET and interrupt routing is not set
    // ******************************************************************
    {
        uint32 control = READ_REGISTER_ULONG(&g_ohci_regs->hc_control);
        if( (control & HC_CONTROL_FUNCTIONAL_STATE) != OHCI_USB_RESET || (control & HC_CONTROL_INT_ROUTING))
            HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error
    }

    // ******************************************************************
    // * wait 10ms per USB Specification
    // ******************************************************************
    {
        DWORD start = KeTickCount;

        while( (start + 10) < KeTickCount );
    }

    // ******************************************************************
    // * setup host controller
    // ******************************************************************
    {
        uint32 restore_interval = READ_REGISTER_ULONG(&g_ohci_regs->hc_fm_interval);

        // ******************************************************************
        // * Issue Software Reset
        // ******************************************************************
        WRITE_REGISTER_ULONG(&g_ohci_regs->hc_cmdstatus, (LONG)HC_CMDSTATUS_HCR);

        // ******************************************************************
        // * wait max of 10ms for reset to complete
        // ******************************************************************
        {
            DWORD start = KeTickCount;

            while( (READ_REGISTER_ULONG(&g_ohci_regs->hc_cmdstatus) & HC_CMDSTATUS_HCR) != 0)
                if(KeTickCount > start + 10)
                    HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error
        }

        // ******************************************************************
        // * Restore hc_fm_interval
        // ******************************************************************
        WRITE_REGISTER_ULONG(&g_ohci_regs->hc_fm_interval, restore_interval);

        // ******************************************************************
        // * TODO: initialize device data HCC block ??? (5.1.1.4 OHCI Spec)
        // ******************************************************************
        {
        }

        // ******************************************************************
        // * initialize operational registers to match the current device
        // * data state (lists are empty at this point)
        // ******************************************************************
        {
            WRITE_REGISTER_ULONG(&g_ohci_regs->hc_control_head, 0);
            WRITE_REGISTER_ULONG(&g_ohci_regs->hc_bulk_head, 0);

            // reset clears this, so we have to write it again
            WRITE_REGISTER_ULONG(&g_ohci_regs->hc_hcca, (ULONG)g_xohci.m_hcca);
        }

        sprintf(buffer, "hc_fm_interval : %.08X", READ_REGISTER_ULONG(&g_ohci_regs->hc_fm_interval));
    }

    // ******************************************************************
    // * update debug status
    // ******************************************************************
    {
        vga_clear();

        vga_print(20, 50, buffer);

        vga_vsync();

        vga_flip();

        {
            int v;

            for(v=0;v<50*3;v++)
                vga_vsync();
        }
    }

    return;
}