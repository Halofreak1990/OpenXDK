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
#ifndef XOHCI_H
#define XOHCI_H

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * OHCI (PCI)
// ******************************************************************
#include "xohci_pci.h"

// ******************************************************************
// * external functions
// ******************************************************************
void xohci_init();

// ******************************************************************
// * struct : ed (Endpoint Descriptor)
// ******************************************************************
#pragma pack(16)
typedef struct _xohci_ed
{
    // ******************************************************************
    // * DWord 0
    // ******************************************************************
    uint32  m_function_addr   : 7;
    uint32  m_endpoint_numb   : 4;
    #define ED_DIRECTION_IN   = 0;
    #define ED_DIRECTION_OUT  = 1;
    uint32  m_direction       : 2;
    #define ED_SPEED_FULL     = 0;
    #define ED_SPEED_LOW      = 1;
    uint32  m_speed           : 1;
    uint32  m_skip            : 1;
    uint32  m_format          : 1;
    uint32  m_max_packet_size : 11;
    uint32  m_reserved0       : 5;

    // ******************************************************************
    // * DWord 1
    // ******************************************************************
    uint32  m_reserved1       : 4;
    uint32  m_tail_p          : 28;

    // ******************************************************************
    // * DWord 2
    // ******************************************************************
    uint32  m_halted          : 1;
    uint32  m_toggle_carry    : 1;
    uint32  m_zero_bit        : 2;
    uint32  m_head_p          : 28;

    // ******************************************************************
    // * DWord 1
    // ******************************************************************
    uint32  m_reserved3       : 4;
    uint32  m_next_ed         : 28;
}
xohci_ed;
#pragma pack()

// ******************************************************************
// * struct : xohci_hcca (Host Controller Communications Area)
// ******************************************************************
// *
// * Note: This must be 256-byte aligned
// *
// ******************************************************************
#pragma pack(1)
typedef struct _xohci_hcca
{
    uint32 int_table[32];
    uint16 frame_number;
    uint16 pad1;
    uint32 done_head;
    uint08 reserved[116];
    // less than 256 bytes..why?
}
xohci_hcca;
#pragma pack()

#if defined(__cplusplus)
}
#endif

#endif
