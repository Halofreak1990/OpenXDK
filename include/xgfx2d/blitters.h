#ifndef XBLITTERS_H
#define XBLITTERS_H

#include <openxdk.h>
#include "xgfx2d/bitmap.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#define DECLARE_BLITTER(name,parameter) \
  void name (uint32 *s, uint32 *d, int len, int parameter) 

DECLARE_BLITTER(normal_blit,none);
DECLARE_BLITTER(sprite_blit,none);
DECLARE_BLITTER(additive_blit,none);
DECLARE_BLITTER(additive_alpha_blit,alpha);
DECLARE_BLITTER(alphavalue_blit,alpha);
DECLARE_BLITTER(alphavalue_sprite_blit,none);
DECLARE_BLITTER(alphavalue50_blit,none);
DECLARE_BLITTER(multiply_blit,none);
DECLARE_BLITTER(invert_blit,none);
DECLARE_BLITTER(subtractive_blit,none);
DECLARE_BLITTER(colorize_sprite_blit,color);
//real alpha_blit that takes alpha from alpha channel is still missing

		
#if defined(__cplusplus)
}
#endif

#endif
	
