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
#include <xlibc/stdio.h>

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
        uint32 revision = READ_REGISTER_ULONG(&g_xohci_regs->hc_revision) & 0x000000FF;

        if(revision != 0x10)
            HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error
    }

    // ******************************************************************
    // * allocate necessary host controller structures
    // ******************************************************************
    {
        // TODO: verify this aligns properly, etc
        g_xohci.m_hcca = MmAllocateContiguousMemoryEx(256, 0, -1, 256, PAGE_READWRITE);

        if(g_xohci.m_hcca == NULL)
            HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error

        g_xohci.m_hcca_dma = MmGetPhysicalAddress(g_xohci.m_hcca);

        WRITE_REGISTER_ULONG(&g_xohci_regs->hc_hcca, (ULONG)g_xohci.m_hcca_dma);
    }

    // ******************************************************************
    // * verify state is USB_RESET and interrupt routing is not set
    // ******************************************************************
    {
        uint32 control = READ_REGISTER_ULONG(&g_xohci_regs->hc_control);

        if( (control & XOHCI_CTRL_HCFS) != XOHCI_USB_RESET || (control & XOHCI_CTRL_IR))
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
        uint32 restore_interval = READ_REGISTER_ULONG(&g_xohci_regs->hc_fm_interval);

        // ******************************************************************
        // * Issue Software Reset
        // ******************************************************************
        WRITE_REGISTER_ULONG(&g_xohci_regs->hc_cmdstatus, (LONG)XOHCI_HCR);

        // ******************************************************************
        // * wait max of 10ms for reset to complete
        // ******************************************************************
        {
            DWORD start = KeTickCount;

            while( (READ_REGISTER_ULONG(&g_xohci_regs->hc_cmdstatus) & XOHCI_HCR) != 0)
            {
                if(KeTickCount > start + 10)
                    HalReturnToFirmware(ReturnFirmwareReboot);  // TODO: Fatal Error
            }
        }

        // ******************************************************************
        // * Restore hc_fm_interval
        // ******************************************************************
        WRITE_REGISTER_ULONG(&g_xohci_regs->hc_fm_interval, restore_interval);

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
            ULONG fminterval = 0x2EDF;

            g_xohci.m_disabled = 1;

            // empty lists at this point
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_control_head, 0);
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_bulk_head, 0);

            // reset clears this, so we have to write it again
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_hcca, (ULONG)g_xohci.m_hcca_dma);

            // ******************************************************************
            // * enable all interrupts except SOF detect
            // ******************************************************************
            {
                ULONG mask = XOHCI_INTR_SO | XOHCI_INTR_WDH | XOHCI_INTR_UE | XOHCI_INTR_MIE;

                WRITE_REGISTER_ULONG(&g_xohci_regs->hc_int_enable, mask);
                WRITE_REGISTER_ULONG(&g_xohci_regs->hc_int_status, mask);
            }

            // ******************************************************************
            // * set hc_control to have "all queues on", set XOHCI_USB_OPERATIONAL
            // ******************************************************************
            {
                ULONG hc_control = (XOHCI_CTRL_CBSR & 0x3) | XOHCI_CTRL_PLE | XOHCI_CTRL_IE;

                g_xohci.m_hc_control = hc_control;

                WRITE_REGISTER_ULONG(&g_xohci_regs->hc_control, hc_control);
            }

            // hc_periodic_start = 90% of FrameInterval field of fminterval
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_periodic_start, (fminterval*9)/10);

            // make sure fminterval is set correctly (from usb_ohci.c linux 2.4.19)
            fminterval |= ((((fminterval - 210) * 6) / 7) << 16);
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_fm_interval, fminterval);

            // this is not really necessary, because this value is probably already correct?
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_ls_threshold, 0x628);

            // set host controller functional state to XOHCI_USB_OPERATIONAL
            g_xohci.m_hc_control = XOHCI_USB_OPERATIONAL;
            WRITE_REGISTER_ULONG(&g_xohci_regs->hc_control, XOHCI_USB_OPERATIONAL);

            // we're enabled now
            g_xohci.m_disabled = 0;
        }
    }

    // ******************************************************************
    // * update debug status
    // ******************************************************************
    {
        int v;

        for(v=0;v<50*10;v++)
        {
            vga_clear();

            sprintf(buffer, "Frames Remaining : %.08X", READ_REGISTER_ULONG(&g_xohci_regs->hc_fm_remaining));

            vga_print(50, 50, buffer);

            vga_vsync();

            vga_flip();

        }
    }

    return;
}