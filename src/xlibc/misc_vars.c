// ******************************************************************
// * 
// * proj : openLIBC
// *
// * desc : Totally Free LIC replacement
// *
// * file : _memccpy.c
// *
// * note : This LIBC is TOTALLY free - do what you like with it!!
// *
// ******************************************************************
#include	<stdlib.h>

int 		errno;
int			_ftol;
int			_fltused;
u8			_Nan[8]={0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0xFF };		// define an __int64 for a NAN
u8			_Inf[8]={0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0x7F };		// INF

// FPU rounding modes
int			_RoundNear      = 0x133a;
int			_RoundDown      = 0x173a;
int			_RoundUp        = 0x1b3a;
int			_RoundChop      = 0x1f3a;




