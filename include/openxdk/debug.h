//
//	Debug output scrolling code submitted by Robin Mulloy
//
//
#ifndef CEXDK_H
#define CEXDK_H

#include <stdarg.h>

#if defined(__cplusplus)
extern "C" {
#endif

#define WHITE   0x00FFFFFF
#define BLACK   0x00000000
#define RED     0x00FF0000
#define GREEN   0x0000FF00
#define BLUE    0x000000FF

#define WHITE_16BPP   0xFFFF
#define BLACK_16BPP  0x0000

/**
 * Prints a message to whatever debug facilities might
 * be available.
 */
void debugPrint(char *format, ...);
void debugPrintNum(int i);
void debugPrintBinary( int num );
void debugPrintHex(char *buffer, int length);
void debugClearScreen( void );
void advanceScreen( void );

#if defined(__cplusplus)
}
#endif

#endif
