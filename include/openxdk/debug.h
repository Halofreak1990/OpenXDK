#ifndef CEXDK_H
#define CEXDK_H

#include <stdarg.h>

#define WHITE   0x00FFFFFF
#define BLACK   0x00000000
#define RED     0x00FF0000
#define GREEN   0x0000FF00
#define BLUE    0x000000FF

/**
 * Prints a message to whatever debug facilities might
 * be available.
 */
void debugPrint(char *format, ...);
void debugPrintNum(int i);
void debugPrintHex(char *buffer, int length);

#endif
