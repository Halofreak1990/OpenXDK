// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : drawprim.h
// *
// * note : A bunch of drawing primitives
// *
// ******************************************************************


#ifndef XDRAWPRIM_H
#define XDRAWPRIM_H

#include <openxdk.h>
#include "xgfx2d/bitmap.h"

#if defined(__cplusplus)
extern "C"
{
#endif

void clear(Bitmap *bmp, uint32 col);
void putpixel(Bitmap *bmp, int x, int y, uint32 col);
void line(Bitmap *bmp, int x1, int y1, int x2, int y2, int d);
void hline(Bitmap *bmp, int x1, int y, int x2, uint32 color);
void vline(Bitmap *bmp, int x, int y1, int y2, uint32 color);
void rect(Bitmap *bmp, int x1, int y1, int x2, int y2, uint32 color);
void rectfill(Bitmap *bmp, int x1, int y1, int x2, int y2, uint32 color);
void circle(Bitmap *bmp, int x, int y, int radius, uint32 color);

#if defined(__cplusplus)
}
#endif

#endif
	
