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
struct ed
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
};
#pragma pack()

#if defined(__cplusplus)
}
#endif

#endif
