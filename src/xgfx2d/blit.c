// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : blit.c
// *
// * note : Simple 2D Bitmap library
// *
// ******************************************************************

#include "xgfx2d/blit.h"


//my old stuff (pretty good though) :

//**********************************************************************************
//THE MIGHTY BLIT FUNCTION
//Takes a blitter as a parameter, then calls it for every line
//The blitters can also be used on their own
//Clips source and dest rectangles, so there's no way it can crash unless the bitmap
//structs are corrupt (hopefully :) )
//**********************************************************************************

//probably bugfree, well tested
void blit(Bitmap *dest, Bitmap *src, int dx, int dy, int sx, int sy, int sw, int sh, void (*blitter)(uint32*,uint32*,int,int), int parameter) {
	int y;
	int xstarts=sx, ystarts=sy,
		xstartd=dx, ystartd=dy,
		width=sw,   height=sh;

	uint32 *s, *d;
	
	int dstx=xstartd,
		dsty=ystartd;
	
	//if outside dest bail out
	if (xstartd<-width || ystartd<-height || xstartd>=dest->w || ystartd>=dest->h) return;
	//if outside source bail out
	if (xstarts<-width || ystarts<-height || xstarts>=src->w || ystarts>=src->h) return;
	
	if (xstarts<0) {xstartd -= xstarts; width -= -xstarts; xstarts=0; }
	if (ystarts<0) {ystartd -= ystarts; height -= -ystarts; ystarts=0; }
	if (xstarts>=src->w-width) {width -= (xstarts+width)-src->w; }
	if (ystarts>=src->h-height) {height-= (ystarts+height)-src->h; }
	
	if (xstartd<0) {xstarts += -xstartd; width -= -xstartd; xstartd=0; }
	if (ystartd<0) {ystarts += -ystartd; height -= -ystartd; ystartd=0; }
	if (xstartd>=dest->w-width) {width -= (xstartd+width)-dest->w;} 
	if (ystartd>=dest->h-height) {height -= (ystartd+height)-dest->h;} 

	if (width<=0) return;

	for (y=ystarts; y<ystarts+height; y++, dsty++)
	{
		s = src->data + src->pitch * y + xstarts; 
		d = dest->data + dest->pitch * dsty + xstartd;

		blitter(s, d, width, parameter);
	}
}


void full_blit(Bitmap *dest, Bitmap *src, void (*blitter)(uint32*,uint32*,int,int), int special) {
	int minw=src->w, minh=src->h;
	if (dest->w<minw) minw=dest->w;
	if (dest->h<minh) minh=dest->h;
	blit(src,dest,0,0,0,0,minw,minh,blitter,special);
}


void blit_at(Bitmap *dest, Bitmap *src, int x, int y, void (*blitter)(uint32*,uint32*,int,int), int special) {
	int minw=src->w, minh=src->h;
	if (dest->w<minw) minw=dest->w;
	if (dest->h<minh) minh=dest->h;
	blit(src,dest,x,y,0,0,minw,minh,blitter,special);
}