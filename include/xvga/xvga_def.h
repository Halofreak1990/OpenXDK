// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xvga_internal.h
// *
// * note : XBox VGA
// *
// ******************************************************************
#ifndef XVGA_DEF_H
#define XVGA_DEF_H

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
static volatile char * const VERTICAL_BLANK = (char * const)0xFD6013DA;

// ******************************************************************
// * vga_reg
// ******************************************************************
typedef struct _vga_reg
{
	unsigned short port;
	unsigned char  index;
	unsigned char  value;
}
vga_reg;

// ******************************************************************
// * vga mode definitions
// ******************************************************************
extern vga_reg mode_256x240[];
extern vga_reg mode_320x240[];
extern vga_reg mode_320x200[];

// ******************************************************************
// * mode sizes
// ******************************************************************
#define MODE256x240SIZE (sizeof(*mode_256x240)/sizeof(vga_reg))
#define MODE320x240SIZE (sizeof(*mode_320x240)/sizeof(vga_reg))
#define MODE320x200SIZE (sizeof(*mode_320x200)/sizeof(vga_reg))

#if defined(__cplusplus)
}
#endif

#endif
