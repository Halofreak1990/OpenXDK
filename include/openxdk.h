// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : openxdk.h
// *
// * note : Welcome To Heaven
// *
// ******************************************************************
#ifndef OPENXDK_H
#define OPENXDK_H

// ******************************************************************
// * OpenXDK Version Number
// ******************************************************************
#define OPENXDK_VERSION "0.0.1-BETA"

// ******************************************************************
// * OpenXDK Full Title
// ******************************************************************
#define OPENXDK_TITLE "OpenXDK " OPENXDK_VERSION

// ******************************************************************
// * Humor caustik with some of his favorite typedefs
// ******************************************************************
typedef signed int     sint;
typedef unsigned int   uint;

typedef char           int08;
typedef short          int16;
typedef long           int32;

typedef unsigned char  uint08;
typedef unsigned short uint16;
typedef unsigned long  uint32;

typedef signed char    sint08;
typedef signed short   sint16;
typedef signed long    sint32;

// ******************************************************************
// * Humor Bigboy with some of his favorite typedefs  :)
// ******************************************************************
typedef	unsigned char		byte;
typedef	unsigned char		u8;
typedef	signed char			s8;
typedef	unsigned short		u16;
typedef	signed short		s16;
typedef	unsigned int		u32;
typedef	signed int			s32;
//typedef	signed __int64		s64;		// We dont have an __int64 all the time yet
//typedef	unsigned __int64	u64;

// ******************************************************************
// * Some "handy" #defines that I always make 
// * (dont worry, MSDEV will optimise the divides :)
// ******************************************************************
#define	RAD2DEG				(57.29577951)
#define	DEG(a)				(a/RAD2DEG)
#define	COS(a)				cos((a)/RAD2DEG)
#define	SIN(a)				sin((a)/RAD2DEG)

#ifndef	NULL			// Since there are no "standard" LIBS, we may not have a NULL yet.
#define	NULL			0x00
#endif

// ******************************************************************
// * XBox Kernel
// ******************************************************************
#include	"xboxkrnl/xboxkrnl.h"

// ******************************************************************
// * XHal
// ******************************************************************
#include	"xhal/xboxVGA.h"

#endif




