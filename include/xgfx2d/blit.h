
#ifndef XBLIT_H
#define XBLIT_H

#include <openxdk.h>
#include "xgfx2d/bitmap.h"

#if defined(__cplusplus)
extern "C"
{
#endif
	
	
// pass in a blitter from blitters.h
void blit(Bitmap *dest, Bitmap *src, 
	int dx, int dy, 
	int sx, int sy, int sw, int sh, 
	void (*blitter)(uint32*,uint32*,int,int), 
	int parameter);

void full_blit(Bitmap *dest, Bitmap *src, 
	void (*blitter)(uint32*,uint32*,int,int), 
	int parameter);

void blit_at(Bitmap *dest, Bitmap *src, 
	int x, int y, 
	void (*blitter)(uint32*,uint32*,int,int), 
	int parameter);


	
	
#if defined(__cplusplus)
}
#endif

#endif
