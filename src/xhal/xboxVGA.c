// ************************************************************************************
//
//
//								 xboxVGA.c
//                       First Version by Bigboy
//
//
//
//  Revision		By				Comment
//  --------		--				-------
//	1.0				Bigboy			First attempt at screen access and control
//									Much of this is based on VGA libs, and xbox Linux
//
//
// ************************************************************************************

#include	<openxdk.h>


	u32	pScreenBuffer[320*240];			// Our screen (software emulated for LOW res just now)
	u32	FrontBuffer=0;					// Current screen address (visible)
	u32	BackBuffer=0;						// Current back buffer

	//
	// 
	//
	u32	g_nFlags=0;						// System flags
	u32	g_nScreenRes=0;					// Current Screen RES

	u32	g_ScreenWidth = 320;			// Current Screen Width
	u32	g_ScreenHeight = 240;			// Current Screen Height
	u32	g_nBPP=4;						// number of bytes per pixel

	u32	g_nFontFlags=0;
	u32	g_nInk = 0xffffff;
	u32	g_nPaper=0x000000;


// These will get binned soon
Register Mode320x240[] =
	{
	{ 0x3c2, 0x0, 0xe3},
	{ 0x3d4, 0x0, 0x5f},
	{ 0x3d4, 0x1, 0x4f},
	{ 0x3d4, 0x2, 0x50},
	{ 0x3d4, 0x3, 0x82},
	{ 0x3d4, 0x4, 0x54},
	{ 0x3d4, 0x5, 0x80},
	{ 0x3d4, 0x6, 0xd},
	{ 0x3d4, 0x7, 0x3e},
	{ 0x3d4, 0x8, 0x0},
	{ 0x3d4, 0x9, 0x41},
	{ 0x3d4, 0x10, 0xea},
	{ 0x3d4, 0x11, 0xac},
	{ 0x3d4, 0x12, 0xdf},
	{ 0x3d4, 0x13, 0x28},
	{ 0x3d4, 0x14, 0x0},
	{ 0x3d4, 0x15, 0xe7},
	{ 0x3d4, 0x16, 0x6},
	{ 0x3d4, 0x17, 0xe3},
	{ 0x3c4, 0x1, 0x1},
	{ 0x3c4, 0x4, 0x6},
	{ 0x3ce, 0x5, 0x40},
	{ 0x3ce, 0x6, 0x5},
	{ 0x3c0, 0x10, 0x41},
	{ 0x3c0, 0x13, 0x0},
	{ -1,-1,-1 },
	};

Register Mode320x200[] =
{
//	{ 0x3d4, 0x0, 0x53},
//	{ 0x3c2, 0x0, 0x63},
//	{ 0x3d4, 0x0, 0x5f},
//	{ 0x3d4, 0x1, 0x4f},
//	{ 0x3d4, 0x2, 0x50},
//	{ 0x3d4, 0x3, 0x82},
//	{ 0x3d4, 0x4, 0x54},
//	{ 0x3d4, 0x5, 0x80},
//	{ 0x3d4, 0x6, 0xbf},
//	{ 0x3d4, 0x7, 0x1f},
	{ 0x3d4, 0x8, 0x00},
	{ 0x3d4, 0x9, 0x41},		// make 640x240 or 640x200 mode
//	{ 0x3d4, 0x9, 0x42},		// 160 high?
//	{ 0x3d4, 0x9, 0x43},		// 128 high?
//	{ 0x3d4, 0x10, 0x9c},
//	{ 0x3d4, 0x11, 0x8e},
//	{ 0x3d4, 0x12, 0x8f},
//	{ 0x3d4, 0x13, 0x28},
//	{ 0x3d4, 0x14, 0x00},
//	{ 0x3d4, 0x15, 0x96},
//	{ 0x3d4, 0x16, 0xb9},
//	{ 0x3d4, 0x17, 0xe3},
	{ 0x3c4, 0x1, 0x8},
	{ -1,-1,-1 },
};

Register Mode320x2002[] =
{
	{ 0x3c2, 0x0, 0x63},
	{ 0x3d4, 0x0, 0x5f},
	{ 0x3d4, 0x1, 0x4f},
	{ 0x3d4, 0x2, 0x50},
	{ 0x3d4, 0x3, 0x82},
	{ 0x3d4, 0x4, 0x54},
	{ 0x3d4, 0x5, 0x80},
	{ 0x3d4, 0x6, 0xbf},
	{ 0x3d4, 0x7, 0x1f},
	{ 0x3d4, 0x8, 0x00},
	{ 0x3d4, 0x9, 0x41},
	{ 0x3d4, 0x10, 0x9c},
	{ 0x3d4, 0x11, 0x8e},
	{ 0x3d4, 0x12, 0x8f},
	{ 0x3d4, 0x13, 0x28},
	{ 0x3d4, 0x14, 0x00},
	{ 0x3d4, 0x15, 0x96},
	{ 0x3d4, 0x16, 0xb9},
	{ 0x3d4, 0x17, 0xe3},
	{ -1,-1,-1 },
};



// **************************************************************************
//
// VGA output
//
// **************************************************************************
void outportb( int port, unsigned char data )
{
		*((volatile unsigned char*)(XBV_BASE|port)) = data;
}
unsigned char inportb( int port )
{
		return *((volatile unsigned char*)(XBV_BASE|port));
}

// **************************************************************************
//
// get VGA registers ready...
//
// **************************************************************************
void readyVgaRegs(void)
{
	u8 v;
	outportb(0x3d4,0x11);
    v = inportb(0x3d5) & 0x7f;
	outportb(0x3d4,0x11);
	outportb(0x3d5,(u8)v);
}


// **************************************************************************
//
// output 1 regset from the "tweak" dataset
//
// **************************************************************************
void outReg(Register r)
{
	switch (r.port)
		{
		// First handle special cases:

		case ATTRCON_ADDR:
			inportb(STATUS_ADDR);  		// reset read/write flip-flop 
			outportb(ATTRCON_ADDR, (u8) (r.index | 0x20));
										// ensure VGA output is enabled 
			outportb(ATTRCON_ADDR, r.value);
			break;

		case MISC_ADDR:
		case VGAENABLE_ADDR:
			outportb(r.port, r.value);	//	directly to the port 
			break;

		case SEQ_ADDR:
		case GRACON_ADDR:
		case CRTC_ADDR:
		default:						// This is the default method: 
			outportb(r.port, r.index);	//	index to port			   
			outportb(r.port+1, r.value);//	value to port+1 		   
			break;
	}
}


//********************************************************
//
// Name:		NVSetScreenAddress
// Function:   	Set screen address, and do a WaitVBlank()
//
// In:			None
// Out:			None
//
//********************************************************
void NVSetScreenAddress( void )
{
	while(CRTC_READ(NV_INPUT_STATUS) & 0x08);		// Wait for VBLANK to start

	// swap buffers around
	FrontBuffer ^= BackBuffer;
	BackBuffer ^= FrontBuffer;
	FrontBuffer ^= BackBuffer;

	if (FrontBuffer && BackBuffer)
	{
		CRTC_WRITEL(NV_CRTC_FB_ADDR, FrontBuffer );
	}

	while(!(CRTC_READ(NV_INPUT_STATUS) & 0x08));	// Wait till start of frame.... Why?

}


// **************************************************************************
//
// Flip buffers (320x240) or (320x200) only just now...more later
//
// **************************************************************************
void	Flip( void )
{
#ifndef	_PCEMU

	u32	i=0;
	u32	size = g_ScreenWidth*g_ScreenHeight;
	u32	*pSCR = (u32*) BackBuffer;			// get current BACK buffer
	u32	*pScr = (u32*) (pScreenBuffer);

	// Software screen copy? in 320x??? modes we need to double up on pixels
	if(	(g_nFlags & XHAL_320SCREEN) != 0 )
	{
		while(i!=size )	{
			u32 a  = *pScr++;
			*pSCR++ = a;
			*pSCR++ = a;
			i++;
		}
	}

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
u8*	GetScreen( void )
{
	if(	(g_nFlags & XHAL_320SCREEN) != 0 ){
		return (u8*) &pScreenBuffer[0];
	}
	else{
		return	(u8*) BackBuffer;
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
void InitMode( int Mode )
{
#ifndef	_PCEMU
	int	i=0;

	switch( (Mode&RES_MASK) )
	{
		case	RES_320X200:	g_ScreenWidth = 320;
								g_ScreenHeight= 200;
								g_nFlags |= XHAL_320SCREEN;			// Software mode, screen will need copied
								break;
		case	RES_320X240:	g_ScreenWidth = 320;
								g_ScreenHeight= 240;
								g_nFlags |= XHAL_320SCREEN;			// Software mode, screen will need copied
								break;
		case	RES_640X480:	g_ScreenWidth = 640;
								g_ScreenHeight= 480;
								break;
	}

	switch( (Mode&COLOUR_MASK) )
	{
		case	_32BITCOLOUR:	g_nBPP = 4; break;
		case	_8BITCOLOUR:	g_nBPP = 2; break;
		case	_16BITCOLOUR:	g_nBPP = 1; break;
	}


	if( g_ScreenHeight <=240 ){
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
	}

	FrontBuffer = XBOX_SCREENRAM;											// Set current visible screen
	BackBuffer = FrontBuffer+(g_ScreenWidth*g_ScreenHeight*g_nBPP);			// Current back buffer



#endif

}


// **************************************************************************
//
//	Name:		Cls
//	Function:	Clear the screen to BLACK (better will follow)
//
// **************************************************************************
void	Cls( void )
{
	u32		c, size = g_ScreenWidth*g_ScreenHeight;
	u32*	pScr = ((u32*) GetScreen());

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
void	Box( int x1,int y1, int x2,int y2 )
{
	int	x,y;
	u32	*pScreen = (u32*) GetScreen();

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
void	WaitVBlank ( void )
{
	/*
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
#endif*/
}

// **************************************************************************
//
//	Name:		SetReg
//	Function:	Set a VGA register
//
//	In:			port	=	VGA port to set
//				reg		=	register to set
//				data	=	data to set
//	Out:		none
//
// **************************************************************************
void	SetReg( int port, int reg, int data )
{
	if( port == 0x3c0){	
		*((volatile unsigned char*)(XBV_ATTR_REG_INDEX)) = reg|0x20;
		*((volatile unsigned char*)(XBV_ATTR_REG_DATA)) = reg;
	}else if(port == 0x3c2) {
		*((volatile unsigned char*)(XBV_ATTR_REG_INDEX2)) = data;
	}else if(port == 0x3c3) {
		*((volatile unsigned char*)(XBV_ATTR_REG_INDEX3)) = data;
	}else{
		*((volatile unsigned char*)(XBV_BASE|port)) = reg;
		*((volatile unsigned char*)((XBV_BASE|port)+1)) = data;
	}
}


// **************************************************************************
//
//	Name:		SetColour
//	Function:	Set the VGA palette registers
//
//	In:			Register number (palette index)
//				R,G,B = colour to set
//	Out:		none
//
// **************************************************************************
void	SetColour( int reg, int R, int G, int B )
{
	*((volatile unsigned char*)(XBV_COLOUR_REG)) = reg;
	*((volatile unsigned char*)(XBV_COLOUR_DATA)) = R;
	*((volatile unsigned char*)(XBV_COLOUR_DATA)) = G;
	*((volatile unsigned char*)(XBV_COLOUR_DATA)) = B;

}


// **************************************************************************
//
//	Name:		_ftol
//	Function:	replacement for _ftol, much faster
//
//	In:		float = float to convert to int
//	Out:	int
//
// **************************************************************************
/*
#if defined(_MSC_VER) && defined(_M_IX86)
// Standard VC++ _ftol is horribly slow because it changes rounding modes twice.
// This replacement comes courtesy of Intel.
// Just linking it in will replace the VC++ standard one.
// Using the /QIfist compiler option is a faster solution, but this is a good
// compromise fallback if compatibility is important.
__declspec(naked) long _ftol(float arg)
{
  __asm
  {
	sub			esp, 4					// RING 0 - MUST do
	fstp		dword ptr [esp]
	movss		xmm0, dword ptr [esp]
	cvttss2si	eax, xmm0
	add			esp, 4					// RING 0 - MUST do
	ret
  }
}
#endif // _M_IX86 && _MSC_VER
*/



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
	int		i,i2,index;
	u8*		pData;
	int		ScrMod, DataMod;
	int		cx;
	u32*	pScreen = ((u32*) GetScreen());

	if( x>(int)g_ScreenWidth ) return;		// clip x>max
	if( y>(int)g_ScreenHeight ) return;		// clip y>max
	if( (x+8)<0 ) return;			// clip x<0
	if( (y+15)<0 ) return;			// clip y>0


	x = (y*g_ScreenWidth)+x;

	c -= 32;
	if(c==0) return;				// dont print spaces!
	index = (c/32)*15*256;			// get ROW
	index += (c%32)*8;
	pData = &SystemFont[index];

	index=0;
	DataMod=256-8;
	ScrMod = (g_ScreenWidth-8);
	cx=8;


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
void Print( int x, int y, char* pText )
{
#ifndef	_PCEMU
	while( *pText != 0x00 ){
		OutChar(x,y,*pText++ );
		x+=8;
	}
#endif
}






