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
#ifndef XOHCI_PCI_H
#define XOHCI_PCI_H

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * external functions
// ******************************************************************
void xohci_pci_init();

// ******************************************************************
// * class : ohci_regs (OHCI Host Controller Operational Registers)
// ******************************************************************
// *
// * NOTE: These fields must be accessed using the functions:
// *
// * WRITE_REGISTER_* and READ_REGISTER_*
// *
// * NOTE: These should fall naturally on a 32 byte boundary
// *
// ******************************************************************
struct ohci_regs
{
    uint32 hc_revision;
    uint32 hc_control;
    uint32 hc_cmdstatus;
    uint32 hc_int_status;
    uint32 hc_int_enable;
    uint32 hc_int_disable;

    uint32 hc_hcca;
    uint32 hc_period_cur;
    uint32 hc_control_head;
    uint32 hc_control_cur;
    uint32 hc_bulk_head;
    uint32 hc_bulk_cur;
    uint32 hc_done_head;

    uint32 hc_fm_interval;
    uint32 hc_fm_remaining;
    uint32 hc_fm_number;
    uint32 hc_periodic_start;
    uint32 hc_ls_threshold;

    uint32 hc_rh_descriptor_a;
    uint32 hc_rh_descriptor_b;
    uint32 hc_rh_status;
    uint32 hc_rh_port_status[15];
}
*g_ohci_regs;

#if defined(__cplusplus)
}
#endif

#endif
