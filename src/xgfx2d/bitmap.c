// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : bitmap.c
// *
// * note : Simple 2D Bitmap library
// *
// ******************************************************************

#include <malloc.h>
#include "xgfx2d/bitmap.h"

Bitmap *create_bitmap(int w, int h)
{
	int dataSize = w*h*sizeof(uint32);
	void *block = malloc(sizeof(Bitmap) + dataSize);
	Bitmap *theBmp = block;
	theBmp->data = (uint32 *) ((char *)block + sizeof(Bitmap));
	return theBmp;
}

void destroy_bitmap(Bitmap *bmp)
{
	free(bmp);
}