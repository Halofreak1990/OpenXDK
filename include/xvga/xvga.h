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
// * external functions
// ******************************************************************
extern void xvga_set256x240();
extern void xvga_set320x240();
extern void xvga_set320x200();

extern void xvga_wait_vblank();
extern void xvga_wait_vblank_end();

#if defined(__cplusplus)
}
#endif

#endif
