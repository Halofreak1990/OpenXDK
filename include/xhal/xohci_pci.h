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
typedef struct _xohci_regs
{
    uint32 hc_revision;
    uint32 hc_control;
    uint32 hc_cmdstatus;
    uint32 hc_int_status;
    uint32 hc_int_enable;
    uint32 hc_int_disable;

    struct _xohci_hcca *hc_hcca;
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
xohci_regs;

// ******************************************************************
// * global pointer to OHCI Host Controller Operational Registers
// ******************************************************************
xohci_regs *g_ohci_regs;

// ******************************************************************
// * hc_control register masks
// ******************************************************************
#define OHCI_CTRL_CBSR	(3 << 0)	// control/bulk service ratio
#define OHCI_CTRL_PLE	(1 << 2)	// periodic list enable
#define OHCI_CTRL_IE	(1 << 3)	// isochronous enable
#define OHCI_CTRL_CLE	(1 << 4)	// control list enable
#define OHCI_CTRL_BLE	(1 << 5)	// bulk list enable
#define OHCI_CTRL_HCFS	(3 << 6)	// host controller functional state
#define OHCI_CTRL_IR	(1 << 8)	// interrupt routing
#define OHCI_CTRL_RWC	(1 << 9)	// remote wakeup connected
#define OHCI_CTRL_RWE	(1 << 10)	// remote wakeup enable

// ******************************************************************
// * pre-shifted values for HC_CONTROL_FUNCTIONAL_STATE
// ******************************************************************
#define OHCI_USB_RESET       (0 << 6)
#define OHCI_USB_RESUME      (1 << 6)
#define OHCI_USB_OPERATIONAL (2 << 6)
#define OHCI_USB_SUSPEND     (3 << 6)

// ******************************************************************
// * hc_cmdstatus register masks
// ******************************************************************
#define OHCI_HCR	(1 << 0)	// host controller reset
#define OHCI_CLF  	(1 << 1)	// control list filled
#define OHCI_BLF  	(1 << 2)	// bulk list filled
#define OHCI_OCR  	(1 << 3)	// ownership change request
#define OHCI_SOC  	(3 << 16)	// scheduling overrun count

// ******************************************************************
// * interrupt register masks (status/enable/disable regs)
// ******************************************************************
#define OHCI_INTR_SO	(1 << 0)	// scheduling overrun
#define OHCI_INTR_WDH	(1 << 1)	// writeback of done_head
#define OHCI_INTR_SF	(1 << 2)	// start frame
#define OHCI_INTR_RD	(1 << 3)	// resume detect
#define OHCI_INTR_UE	(1 << 4)	// unrecoverable error
#define OHCI_INTR_FNO	(1 << 5)	// frame number overflow
#define OHCI_INTR_RHSC	(1 << 6)	// root hub status change
#define OHCI_INTR_OC	(1 << 30)	// ownership change
#define OHCI_INTR_MIE	(1 << 31)	// master interrupt enable

#if defined(__cplusplus)
}
#endif

#endif
