// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : bitmap.h
// *
// * note : Simple 2D Bitmap library
// *
// ******************************************************************

#ifndef XBITMAP_H
#define XBITMAP_H

#include "openxdk.h"

#if defined(__cplusplus)
extern "C"
{
#endif



typedef struct
{
	uint32 *data;
	int w, h;
	int pitch;	//in pixels, not bytes as many libs do
				//will in most cases be same as w
} Bitmap;


Bitmap *create_bitmap(int w, int h);
void destroy_bitmap(Bitmap *bmp);

//image loaders
Bitmap *load_tga(char *filename);

#if defined(__cplusplus)
}
#endif

#endif
