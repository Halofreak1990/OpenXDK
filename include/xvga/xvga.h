// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xvga.h
// *
// * note : XBox VGA
// *
// ******************************************************************
#ifndef XVGA_H
#define XVGA_H

#include "openxdk.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// ******************************************************************
// * vga registers
// ******************************************************************
static volatile char * const ATTR_REG_INDEX = (char * const)0xFD6013c0;
static volatile char * const ATTR_REG_DATA  = (char * const)0xFD6013c1;
static volatile char * const CRTC_REG_INDEX = (char * const)0xFD6013d4;
static volatile char * const CRTC_REG_DATA  = (char * const)0xFD6013d5;
static volatile char * const GRA_REG_INDEX  = (char * const)0xFD0c03ce;
static volatile char * const GRA_REG_DATA   = (char * const)0xFD0c03cf;
static volatile char * const SEQ_REG_INDEX  = (char * const)0xFD0c03c4;
static volatile char * const SEQ_REG_DATA   = (char * const)0xFD0c03c5;
static volatile char * const MISC_REG       = (char * const)0xFD0c03c2;

// ******************************************************************
// * vga_reg
// ******************************************************************
typedef struct _vga_reg
{
	unsigned      port;
	unsigned char index;
	unsigned char value;
}
vga_reg;

// ******************************************************************
// * external functions
// ******************************************************************
extern void xvga_set320x240();
extern void xvga_wait_vblank();
extern void xvga_wait_vblank_end();

#if defined(__cplusplus)
}
#endif

#endif
