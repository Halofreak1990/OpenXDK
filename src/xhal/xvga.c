// ************************************************************************************
//
//
//								  xvga.c
//                       First Version by Bigboy
//
//
//
//  Revision		By				Comment
//  --------		--				-------
//	1.0				Bigboy			First attempt at screen access and control
//									Much of this is based on VGA libs, and xbox Linux
//  1.1             Bigboy          Added 640x480x32 mode.
//  1.2             Bigboy          Moved internal functions to xvga_sys.c
//
// ************************************************************************************

#include	<openxdk.h>

#include "xhal/xvga_def.h"
#include "xhal/xnvidia.h"


	u32	pScreenBuffer[320*240];			// Our screen (software emulated for LOW res just now)
	u32	FrontBuffer=0;					// Current screen address (visible)
	u32	BackBuffer=0;					// Current back buffer

	u32	_FrontBuffer=0;					// Current screen address (visible)
	u32	_BackBuffer=0;					// Current back buffer
	u32	_Framebuffer;

	u32	g_nFlags=0;						// System flags
	u32	g_nScreenRes=0;					// Current Screen RES

	u32	g_ActualWidth = 640;			// ACTUAL display buffer Width
	u32	g_ActualHeight = 240;			// ACTUAL display buffer Height
	u32	g_ScreenWidth = 320;			// Current Screen Width
	u32	g_ScreenHeight = 240;			// Current Screen Height
	u32	g_nBPP=4;						// number of bytes per pixel


	u32	g_ScreenBase=0;					// base address of BOTH screens

	u32	g_nFontFlags=0;					// font rendering options
	u32	g_nInk = 0xffffff;				// font drawing. In native screen mode colours
	u32	g_nPaper=0x000000;				//


// **************************************************************************
//
// Flip buffers (320x240) or (320x200) only just now...more later
//
// **************************************************************************
void	vga_testpattern( int shift)
{
	int	x,y,i;
	uint32 *pix = (uint32*)g_ScreenBase; 

	for(y=0;y<480;y++){
		for(x=0;x<640;x++){
			*pix++ = x<<shift;
		}
	}

}

// **************************************************************************
//
// Flip buffers (320x240) or (320x200) only just now...more later
//
// **************************************************************************
void	vga_flip( void )
{
//#if 1
#ifndef	_PCEMU

	s32	i2,i=0;
	s32	size = g_ScreenWidth*g_ScreenHeight;
	u32	*pSCR = (u32*) _BackBuffer;			// get current BACK buffer
	u32	*pScr = (u32*) (pScreenBuffer);

	// Software screen copy? in 320x??? modes we need to double up on pixels
	if(	(g_nFlags & XHAL_320SCREEN) != 0 )
	{
		// clear upper and lower ares of the screen...
		if(	(g_nFlags & YHAL_200SCREEN) != 0 ){
			u32	*pScr = (u32*) (pScreenBuffer);
			i=(320*20);
			i2=(320*240);
			while(--i>=0){
				pScr[i]=0;
				pScr[--i2]=0;
			}
		}
		if( g_nBPP ==2){
			u16*	pSource=(u16*)pSCR;
			size = size>>1;
			while(i!=size )	{
				u16 a  = *pSource++;
				*pScr++ = (a<<16)|a;
				i++;
			}
		}
		else{
			while(i!=size )	{
				u32 a  = *pScr++;
				*pSCR++ = a;
				*pSCR++ = a;
				i++;
			}
		}
	}

	_FrontBuffer^=_BackBuffer;
	_BackBuffer^=_FrontBuffer;
	_FrontBuffer^=_BackBuffer;

	NVSetScreenAddress();		// Flip buffers
#endif
}

// **************************************************************************
//
// Name:		Get Screen Address
// Function:	get the current backbuffer address. 
//				This is simulated just now, since the screen is copied
//
// **************************************************************************
ScreenInfo vga_get_screen_info( void )
{
	ScreenInfo Scr;

	if(	(g_nFlags & XHAL_320SCREEN) != 0 ){
		if(	(g_nFlags & YHAL_200SCREEN) != 0 ){
			Scr.ScreenAddress = (u32) &pScreenBuffer[320*20*g_nBPP];
			Scr.lpitch = 320*4;	//640*4;
			return Scr;
		}
		else{
			Scr.ScreenAddress = (u32) &pScreenBuffer[0];
			Scr.lpitch = 320*4; //640*4;
			return Scr;
		}
	}
	else{
		Scr.ScreenAddress = _BackBuffer;	//_Framebuffer;	//(BackBuffer&0x0fffffff);
		Scr.lpitch = 640*4;//g_nBPP;
		return Scr;
	}
}


// **************************************************************************
//
//	Name:		InitMode
//	Function:	Setup a display mode
//
//	In:			Mode setting from #define list
//	Out:		none
//
// **************************************************************************
void vga_init_mode( int Mode )
{
#ifndef	_PCEMU
	int		i=0;
	u32*	pScr;
	u32		ReqRes = Mode;

	// Use the 640x480 display thats aready set up at boot time....
	if( Mode == MODE_640x480x32_DEBUG )
	{
		_FrontBuffer=XBOX_SCREENRAM+0x240;//0x40;										// address of VRAM (logical address for CPU)
		_BackBuffer = _FrontBuffer;												// Single buffer

		// Get HW address for setting buffers
		FrontBuffer = XBOX_SCREENRAM&0xfffffff;									// Get Physical address
		BackBuffer = FrontBuffer;												// Single buffer

		g_ScreenWidth = 640;
		g_ScreenHeight= 480;
		g_ActualWidth = 640;
		g_ActualHeight = 480;
		g_nBPP=4;
		NVSetFlickerFilter(1);				// Set flicker fixer to a sharper image
		return;
	}


	switch( (Mode&RES_MASK) )
	{
		case	RES_320X200:	g_ScreenWidth = 320;
								g_ScreenHeight= 240;
								g_ActualWidth = 640;
								g_ActualHeight = 240;
								g_nFlags |= XHAL_320SCREEN|YHAL_200SCREEN;			// Software mode, screen will need copied
								ReqRes = RES_640X480;
								break;
		case	RES_320X240:	g_ScreenWidth = 320;
								g_ScreenHeight= 240;
								g_ActualWidth = 640;
								g_ActualHeight = 240;
								g_nFlags |= XHAL_320SCREEN;							// Software mode, screen will need copied
								ReqRes = RES_640X480;
								break;
		case	RES_640X480:	g_ScreenWidth = 640;
								g_ScreenHeight= 480;
								g_ActualWidth = 640;
								g_ActualHeight = 480;
								break;
	}

	switch( (Mode&COLOUR_MASK) )
	{
		case	_32BITCOLOUR:	g_nBPP = 4; break;
		case	_16BITCOLOUR:	g_nBPP = 2; break;
		case	_8BITCOLOUR:	g_nBPP = 1; break;
	}

	if( g_ScreenHeight <=240 ){
		NVSetVideoMode( ReqRes&RES_MASK, Mode&COLOUR_MASK );
		g_ScreenBase = _FrontBuffer;

		// Kick into 240 high mode
		readyVgaRegs();
		while( 1 ){
			if( Mode320x200[i].port!=-1 ){
				outReg( Mode320x200[i] );
			}
			else{
				break;
			}
			i++;
		}

		// Get CPU screen address
		//_FrontBuffer=XBOX_SCREENRAM+0x240;//0x40;										// address of VRAM (logical address for CPU)
		//_BackBuffer = _FrontBuffer+(g_ActualWidth*g_ActualHeight*g_nBPP);		// Current back buffer

		// Get HW address for setting buffers
		//FrontBuffer = XBOX_SCREENRAM&0xfffffff;									// Get Physical address
		//BackBuffer = FrontBuffer+(g_ActualWidth*g_ActualHeight*g_nBPP);			// Current back buffer(second one)
	}
	else{
		NVSetVideoMode( Mode&RES_MASK, Mode&COLOUR_MASK );
		g_ScreenBase = _FrontBuffer;
		
	}

	NVSetBPP(Mode&COLOUR_MASK);			// Set the correct bits per pixel

	// Clear both buffers
	i = (g_ActualWidth*g_ActualHeight*g_nBPP*2)/4;
	pScr = (u32*)_FrontBuffer;
	while(i-->=0){
		*pScr=0;
	}

	//vga_testpattern( 0 );
	//vga_flip();
	// Clear both buffers
/*	i = (g_ActualWidth*g_ActualHeight*g_nBPP*2)/4;
	pScr = (u32*)_FrontBuffer;
	while(i-->=0){
		*pScr=0xffffffff;
	}
*/
	//vga_testpattern( 8 );

	NVSetFlickerFilter(1);				// Set flicker fixer to a sharper image


#endif

}


// **************************************************************************
//
//	Name:		Cls
//	Function:	Clear the screen to BLACK (better will follow)
//				if in a 320x???? mode, this clears the software buffer
//
// **************************************************************************
void vga_clear( void )
{
	u32		c, size = g_ScreenWidth*g_ScreenHeight;
	ScreenInfo ScrStruct = vga_get_screen_info();
	u32*	pScr = (u32*)ScrStruct.ScreenAddress;

	for(c=0;c<size;c++){
		*pScr++ = 0;
	}
}
	
// **************************************************************************
//
//	Name:		Box
//	Function:	Draw a wireframe Box (simple/slow)  NO clipping
//
//	In:		x1,y1 = top left
//			x2,y2 = Width,Height
//	Out:	none
//
// **************************************************************************
void vga_box( int x1,int y1, int x2,int y2 )
{
	int	x,y;
	ScreenInfo ScrStruct = vga_get_screen_info();
	u32*	pScreen = (u32*)ScrStruct.ScreenAddress;

	x2 = x1+x2;
	y2 = y1+y2;

	for(x=x1;x<=x2;x++){
		pScreen[x+(y1*g_ScreenWidth)] =0xffffff;
		pScreen[x+(y2*g_ScreenWidth)] =0xffffff;
	}

	for(y=y1;y<=y2;y++){
		pScreen[x1+(y*g_ScreenWidth)] =0xffffff;
		pScreen[x2+(y*g_ScreenWidth)] =0xffffff;
	}
}



// **************************************************************************
//
//	Name:		WaitVBlank
//	Function:	Wait for vertical blanking. Must be a nicer way to handle this.
//
// **************************************************************************
void vga_vsync( void )
{

#ifndef	_PCEMU
	while(1){
		unsigned char a =  *((volatile unsigned char*)(VBL));
		if( (a&8)!=8 ){
			break;
		}
	}
	while(1){
		unsigned char a =  *((volatile unsigned char*)(VBL));
		if( (a&8)!=0 ){
			break;
		}
	}
#endif
    
}


//********************************************************
//
// Name:		PrintChar
// Function:   	VERY simple print a string to the screen bitmap
// Author:		Bigboy
//
// In:			x,y  = coord
//				pText= string to print
// Out:			None
//
//********************************************************
void OutChar(int x, int y, char c )
{
	int		i,i2,index,baseindex;
	u8*		pData;
	u8*		pS;
	int		ScrMod, DataMod;
	int		cx;
	ScreenInfo	ScrStruct = vga_get_screen_info();



	if( x>(int)g_ScreenWidth ) return;		// clip x>max
	if( y>(int)g_ScreenHeight ) return;		// clip y>max
	if( (x+8)<0 ) return;			// clip x<0
	if( (y+15)<0 ) return;			// clip y>0

	pS = (u8*) ScrStruct.ScreenAddress;

	baseindex = (y*ScrStruct.lpitch)+(x*g_nBPP);


	// Workout character address inside FONT 
	c -= 32;
	if(c==0) return;				// dont print spaces!
	index = (c/32)*15*256;			// get ROW
	index += (c%32)*8;
	pData = &SystemFont[index];

	x = 0;
	index=0;
	DataMod=256-8;
	ScrMod = (g_ScreenWidth-8);
	cx=8;


	if( g_nBPP==4 )
	{
		u32*	pScreen = (u32*) &(pS[baseindex]);

		if((g_nFontFlags&FONT_SOLID)==0 ){
			for(i2=0;i2<15;i2++){
				for(i=0;i<cx;i++){
					if( pData[index++]==0 ){
						x++;
					}
					else{
						pScreen[x++]=g_nInk;
					}
				}
				x+=ScrMod;
				index+=DataMod;
			}
		}
		else{
			for(i2=0;i2<15;i2++){
				for(i=0;i<cx;i++){
					if( pData[index++]==0 ){
						pScreen[x++]=g_nPaper;
					}
					else{
						pScreen[x++]=g_nInk;
					}
				}
				x+=ScrMod;
				index+=DataMod;
			}
		}
	}
	else if( g_nBPP == 2 )
	{
		u16*	pScreen16 = (u16*) &(pS[baseindex]);

		ScrMod=(ScrMod*2)+8;
		if((g_nFontFlags&FONT_SOLID)==0 ){
			for(i2=0;i2<15;i2++){
				for(i=0;i<cx;i++){
					if( pData[index++]==0 ){
						x++;
					}
					else{
						pScreen16[x++]=g_nInk;
					}
				}
				x+=ScrMod;
				index+=DataMod;
			}
		}
		else{
			for(i2=0;i2<15;i2++){
				for(i=0;i<cx;i++){
					if( pData[index++]==0 ){
						pScreen16[x++]=g_nPaper;
					}
					else{
						pScreen16[x++]=g_nInk;
					}
				}
				x+=ScrMod;
				index+=DataMod;
			}
		}
	}
}


//********************************************************
//
// Name:		Print
// Function:   	Prints a string to the screen bitmap
// Author:		Bigboy
//
// In:			x,y  = coord
//				pText= string to print
// Out:			None
//
//********************************************************
void vga_print( int x, int y, char* pText )
{
#ifndef	_PCEMU
	int		StartX=x;

	while( *pText != 0x00 ){
		OutChar(x,y,*pText++ );
		x+=8;
		if((g_nFontFlags&FONT_WRAP)!=0 )
		{
			if( x>(int)(g_ScreenWidth-15) ){
				x = StartX;
				y+=15;
			}
		}

	}
#endif
}






