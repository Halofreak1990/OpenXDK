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

//simple straightforward functions
void clear(Bitmap *bmp, uint32 col);
void putpixel(Bitmap *bmp, int x, int y, uint32 col);
void line(Bitmap *bmp, int x1, int y1, int x2, int y2, int d);
void hline(Bitmap *bmp, int x1, int y, int x2, uint32 color);
void vline(Bitmap *bmp, int x, int y1, int y2, uint32 color);
void rect(Bitmap *bmp, int x1, int y1, int x2, int y2, uint32 color);
void rectfill(Bitmap *bmp, int x1, int y1, int x2, int y2, uint32 color);
void circle(Bitmap *bmp, int x, int y, int radius, uint32 color);

//more advanced stuff

//use this for smooth scrolling starfields and stuff :) x and y are in 16.16 fixed point
void aa_pixel(Bitmap *bmp, int x, int y, int color);
//this one takes floats
void aa_pixel_float(Bitmap *bmp, float x,float y,int color);
// single alpha blended pixel, used by bilinear_pixel and aa_line
void alpha_pixel(Bitmap *bmp, int x, int y, uint32 sc, int alpha);
// nice antialiased line drawing
void aa_line(Bitmap *bmp, float x1, float y1, float x2, float y2, uint32 color, int alpha);

#if defined(__cplusplus)
}
#endif

#endif
	
