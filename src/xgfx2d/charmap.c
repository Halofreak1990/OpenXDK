// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : charmap.c
// *
// * note : Simple character map system - 32bit screen mode only
// *        All variables are help in a structure, since this allows
// *        us to have multiple character maps IF we want to in the 
// *        future.
// *
// ******************************************************************

#include <openxdk.h>
#include "xhal/xvga_def.h"
#include <xgfx2d/charmap.h>
#include <malloc.h>

#include <xgfx2d/bitmap.h>
#include <xgfx2d/blit.h>
#include <xgfx2d/blitters.h>
#include <xgfx2d/drawprim.h>
	
	PCharMap	g_pCharMap;		// current character map

	// Out attributes colours (32bit mode)
	u32			CharMap_Attrib[]={	0x00000000, 0x000000ff, 0x0000ff00,0x00ff0000, 
									0x0000ffff, 0x00ffff00, 0x00ff00ff,0x00ffffff
	};

// ******************************************************************
// * charmap_render_character
// ******************************************************************
// *
// * Render the character at x,y on the charmap to the screen
// *
// ******************************************************************
void charmap_render_character( s32 x, s32 y )
{
	u32			nPaper, nInk;
	u16			c;
	int			i,i2,index,baseindex;
	u8*			pData;
	int			ScrMod, DataMod;
	PCharMap	pCharMap = g_pCharMap;						// get current screen
	u32*		pScreen = (u32*)pCharMap->pBitmap;
	u16*		pMap = pCharMap->pCharMap;
	
	
	c = pMap[(y*pCharMap->width)+x];
	baseindex = (y*FONT_HEIGHT*pCharMap->pixwidth)+(x*FONT_WIDTH);			// 32bit modes only

	nInk   = CharMap_Attrib[(c>>8)&7];				// extract INK
	nPaper = CharMap_Attrib[(c>>11)&7];				// extract PAPER
	c&=0xff;										// mask off flags+ink+paper, Keep character only

	// Workout character address inside FONT texture page
	c -= 32;
	if( c<0 ) return;

	index = (c/32)*15*256;							// get ROW
	index += (c%32)*8;								// column
	pData = &SystemFont[index];

	index=0;
	DataMod=256-8;									// texture page is 256 bytes wide (32 characters per page)
	ScrMod = (pCharMap->pixwidth-8);


	// Character is ALWAYS solid.
	for(i2=0;i2<15;i2++)
	{
		for(i=0;i<8;i++)
		{
			if( pData[index++]==0 ){
				pScreen[baseindex++]=nPaper;
			}
			else{
				pScreen[baseindex++]=nInk;
			}
		}
		baseindex+=ScrMod;
		index+=DataMod;
	}

}


// ******************************************************************
// * charmap_blit_screen
// ******************************************************************
// *
// * copy the character map texture to the screen. (simple copy)
// *
// ******************************************************************
void charmap_blit_screen( void )
{
#if 0
	ScreenInfo	ScrStruct = vga_get_screen_info();
	PCharMap	pCharMap = g_pCharMap;						// get current screen
	s32			x,y,w,h;
	u32			*pScreen;
	u32			*pSrc;
	u32			modulo;
	
	pSrc= (u32*)pCharMap->pBitmap;
	x = pCharMap->x;
	y = pCharMap->y;
	w = pCharMap->pixwidth;
	h = pCharMap->pixheight;

	pScreen = (u32*) (ScrStruct.ScreenAddress+((y*ScrStruct.lpitch)+(x*4)) );
	
//	modulo = (ScrStruct.lpitch-(w*4))/4;
	modulo = ScrStruct.lpitch/4;

	for(y=0;y<h;y++){
#if 1
		memcpy( pScreen, pSrc, w<<2 );		// Due to intrinsics, memcpy is VERY fast.
		pScreen+=modulo;
		pSrc+=w;
#else
		x=w;
		while( x-- > 0 ){
			*pScreen++=*pSrc++;				// DWORD aligncopy
		}
		pScreen+=modulo;
#endif
	}

#else

	//
	// Use ectors 2D blitter stuff, we get clipping in this.
	// normal_blit uses a memcpy, but due to intrinsics, memcpy is VERY fast.
	//
	Bitmap	*pScreen = get_screen_bitmap();
	Bitmap	pCharBitmap;

	pCharBitmap.data = (u32*)g_pCharMap->pBitmap;
	pCharBitmap.w = g_pCharMap->pixwidth;
	pCharBitmap.h = g_pCharMap->pixheight;
	pCharBitmap.pitch = g_pCharMap->pixwidth;

	blit_at(pScreen, &pCharBitmap, g_pCharMap->x, g_pCharMap->y, normal_blit, 0);

#endif
}

// ******************************************************************
// * charmap_clear
// ******************************************************************
// *
// * Clear our character map
// *
// ******************************************************************
void charmap_clear( void )
{
	
	PCharMap	pCharMap = g_pCharMap;						// get current screen
	int			size = pCharMap->width*pCharMap->height;
	int			data = pCharMap->attrib_char|MAP_TOUCHED;
	u16*		pMap = pCharMap->pCharMap;
	
	while(size>0){
		*pMap++=data;
		size--;
	}

	pCharMap->curx = pCharMap->wx1;		// reset to top of current TEXT window
	pCharMap->cury = pCharMap->wy1;
}



// ******************************************************************
// * init_charmap
// ******************************************************************
// *
// * Init the simulated character map. width and 
// *
// * in:		basex = x coord on screen for charmap
// *            basey = y corrd on screen for charmap
// *    		width = width in pixels of charmap
// *			height= height in pixels of charmap
// * out:       none
// *
// ******************************************************************
void charmap_init( s32 baseX, s32 baseY, s32 width, s32 height )
{
	PCharMap	pCharMap;
	
	pCharMap = malloc( sizeof(SCharMap) );			// create charmap

	pCharMap->pixwidth = width;						// Set pixel width 
	pCharMap->pixheight = height;					// and height
	pCharMap->x = baseX;							// also set the top left of the charmap bitmap
	pCharMap->y = baseY;							//

	pCharMap->width = width/FONT_WIDTH;				// get number of characters in bit map
	pCharMap->height = height/FONT_HEIGHT;			//


	//
	// And, allocate space for the bitmap, and character map
	//
	pCharMap->pBitmap = malloc( width*height*4 );
	pCharMap->pCharMap = malloc( pCharMap->width*pCharMap->height*2 );

	pCharMap->wx1 = 0;
	pCharMap->wy1 = 0;
	pCharMap->wx2 = pCharMap->width;
	pCharMap->wy2 = pCharMap->height;
	pCharMap->curx = pCharMap->wx1;
	pCharMap->cury = pCharMap->wy1;

	pCharMap->attrib_char = (INK_WHITE|0x20);		// space,black on black
	g_pCharMap = pCharMap;							// set current screen

	charmap_clear();
	memset(pCharMap->pBitmap, 0xff, width*height*4);
}


// ******************************************************************
// * charmap_display
// ******************************************************************
// *
// * Update any characters that need it, and render it to the screen
// *
// ******************************************************************
void charmap_display( void )
{
	PCharMap	pCharMap = g_pCharMap;						// get current screen
	int			size = pCharMap->width*pCharMap->height;
	int			data = pCharMap->attrib_char|MAP_TOUCHED;
	u16*		pMap = pCharMap->pCharMap;
	s32			xs,ys,y,x;
	
	xs = pCharMap->width;
	ys = pCharMap->height;

	for(y=0;y<ys;y++){
		for(x=0;x<xs;x++){
			if( (*pMap++&MAP_TOUCHED)!=0 ){
				charmap_render_character(x,y);				// render the character at (x,y) to the bitmap
				pMap[-1]&=~MAP_TOUCHED;						// clear flag
			}
		}
	}

	charmap_blit_screen();									// Copy the character map to the screen
}



// ******************************************************************
// * charmap_scroll_window
// ******************************************************************
// *
// * Scroll current window up a line. 
// *
// ******************************************************************
void charmap_scroll_window( void )
{	
	s32		x,y,x2,y2,w,xx;
	u16		*pMap = g_pCharMap->pCharMap;
	u16		attrib = g_pCharMap->attrib_char|MAP_TOUCHED;			// get current clear character and ink and paper

	x = g_pCharMap->wx1;
	y = g_pCharMap->wy1;
	x2 = g_pCharMap->wx2;
	y2 = g_pCharMap->wy2;
	w = g_pCharMap->width;

	y2--;			// 1 row less.
	xx = x;			// remember window LEFT edge
	while(y<y2)
	{
		memcpy( &(pMap[(y*w)+x]),  &(pMap[((y+1)*w)+x]), (x2-x)<<1 );		// intrinsic memcpy is nice and fast.
		y++;
	}

	// Clear bottom line of window
	x = x2-xx;
	pMap = &(pMap[(y*w)+xx]);
	while(x-->0)
	{
		*pMap++ = attrib;
	}	

	//
	// This scrolls the character map BITMAP up, so we dont need to redraw all the characters.
	//
	{
		u8*	pSrc;
		u8*	pDest;

		y = g_pCharMap->wy1;
		y2 = g_pCharMap->wy2-1;
		y*=FONT_HEIGHT;
		y2*=FONT_HEIGHT;


		pDest= &(g_pCharMap->pBitmap[((y*g_pCharMap->pixwidth)+(xx*FONT_WIDTH))*4]);
		pSrc = &(g_pCharMap->pBitmap[(((y+FONT_HEIGHT)*g_pCharMap->pixwidth)+(xx*FONT_WIDTH))*4]);
		x = ((x2-xx)*FONT_WIDTH)*4;
		
		while(y<y2)
		{
			memcpy( pDest,pSrc,x );
			pSrc+=g_pCharMap->pixwidth<<2;
			pDest+=g_pCharMap->pixwidth<<2;
			y++;
		}
	}

}



// ******************************************************************
// * charmap_newline
// ******************************************************************
// *
// * Do a linefeed+cart return. Scroll current window IF we need to.
// *
// ******************************************************************
void charmap_newline( void )
{	
	g_pCharMap->curx = g_pCharMap->wx1;
	g_pCharMap->cury++;
	if( g_pCharMap->cury >= g_pCharMap->wy2 ){
		g_pCharMap->cury = g_pCharMap->wy2-1;		// Make sure we are on the BOTTOM of the text window
		charmap_scroll_window();					// scroll current character map WINDOW up a text line
	}
}




// ******************************************************************
// * charmap_outchar
// ******************************************************************
// *
// * Output a single character to the display, at the current cursor
// * X,Y. Then move the cursor location on one position.
// *
// ******************************************************************
void charmap_outchar( char Ch )
{
	u16		attrib = (g_pCharMap->attrib_char&0xff00)|MAP_TOUCHED;	// get current ink and paper

	if(( Ch== 0x0a )|( Ch== 0x0d )){
		charmap_newline();									// do a newline, and scroll if we need to.
		return;
	}
	g_pCharMap->pCharMap[(g_pCharMap->cury*g_pCharMap->width)+g_pCharMap->curx]=Ch|attrib;		// set new character
	g_pCharMap->curx++;
	if( g_pCharMap->curx >= g_pCharMap->wx2 ){
		charmap_newline();									// do a newline, and scroll if we need to.
	}
}


// ******************************************************************
// * charset_move_cursor
// ******************************************************************
// *
// * Move the cursor to a new location (check its inside the current 
// * TEXT window.
// *
// ******************************************************************
void charset_move_cursor( s32 x, s32 y)
{
	// make sure we are ON screen
	if( x<g_pCharMap->wx1) x = g_pCharMap->wx1;
	if( y<g_pCharMap->wy1) y = g_pCharMap->wy1;
	if( x>g_pCharMap->wx2) x = g_pCharMap->wx2-1;
	if( y>g_pCharMap->wy2) y = g_pCharMap->wy2-1;
	

	// Set cursor
	g_pCharMap->curx = x;
	g_pCharMap->cury = y;
}


// ******************************************************************
// * charmap_print
// ******************************************************************
// *
// * Print a string into our character map display
// *
// ******************************************************************
void charmap_print( char *pStr )
{
	PCharMap	pCharMap = g_pCharMap;									// get current screen
	
	while(*pStr!=0x00 ){
		charmap_outchar(*pStr++);
	}
}



// ******************************************************************
// * charmap_printat
// ******************************************************************
// *
// * Print a string into our character map display
// *
// ******************************************************************
void charmap_printat( s32 x, s32 y, char *pStr )
{
	PCharMap	pCharMap = g_pCharMap;									// get current screen
	

	charset_move_cursor(x,y);
	while(*pStr!=0x00 ){
		charmap_outchar(*pStr++);
	}
}

// ******************************************************************
// * charmap_setink
// ******************************************************************
// *
// * Set thre current INK colour
// *
// ******************************************************************
void charmap_setink( u8 ink )
{
	g_pCharMap->attrib_char = (g_pCharMap->attrib_char&~(7<<8))|((ink&7)<<8);
}


// ******************************************************************
// * charmap_setink
// ******************************************************************
// *
// * Set thre current INK colour
// *
// ******************************************************************
void charmap_setpaper( u8 paper )
{
	g_pCharMap->attrib_char = (g_pCharMap->attrib_char&~(7<<11))|((paper&7)<<11);
}



// ******************************************************************
// * charmap_set_window
// ******************************************************************
// *
// * Set thre current Text window
// *
// ******************************************************************
void charmap_set_window( s32 x1,s32 y1,s32 x2, s32 y2 )
{
	g_pCharMap->wx1 = x1;
	g_pCharMap->wx1 = y1;
	g_pCharMap->wx1 = x2;
	g_pCharMap->wx1 = y2;
}


// ******************************************************************
// * charmap_home
// ******************************************************************
// *
// * set the cursor X,Y to the top left of the current window
// *
// ******************************************************************
void charmap_home( void )
{
	g_pCharMap->curx = g_pCharMap->wx1;
	g_pCharMap->cury = g_pCharMap->wy1;
}