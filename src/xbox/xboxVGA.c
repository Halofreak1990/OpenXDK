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


	u32	pScreenBuffer[640*480];			// Our screen (software emulator just now)
	u8*	pCurrentScreen;					// Current screen address
	u32	g_ScreenWidth = 320;			// Current Screen Width
	u32	g_ScreenHeight = 240;			// Current Screen Height
	u32	g_nFlags=0;
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
//	{ 0x3d4, 0x8, 0x00},
	{ 0x3d4, 0x9, 0x41},		// make 640x240 or 640x200 mode
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
	int v;
	outportb(0x3d4,0x11);
    v = inportb(0x3d5) & 0x7f;
	outportb(0x3d4,0x11);
	outportb(0x3d5,v);
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
			outportb(ATTRCON_ADDR, r.index | 0x20);
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


// **************************************************************************
//
// Flip buffers (320x240) or (320x200) only just now...more later
//
// **************************************************************************
void	Flip( void )
{
#ifdef	_XBOX
	u32	i=0;
	u32	size = g_ScreenWidth*g_ScreenHeight;
	u32	*pSCR = (u32*) XBOX_SCREENRAM;
	u32	*pScr = (u32*) (pScreenBuffer);

	while(i!=size ){
		u32 a  = *pScr++;
		*pSCR++ = a;
		*pSCR++ = a;
		i++;
	}
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
	return	(u8*)&(pScreenBuffer[0]);
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
	int	i=0;


	g_ScreenWidth = 320;		// Set Current Screen Width
	g_ScreenHeight= 240;			// Set Current Screen Height


#ifdef	_XBOX
	readyVgaRegs();
	while( 1 ){
		if( Mode320x200[i].port!=-1 ){
			outReg( Mode320x200[i] );
		}
		else{
			return;
		}
		i++;
	}
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
#ifdef	_XBOX
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

//	if( ( x+8 )> g_nScreen_X ){
//		int	diff = (x+8)-g_nScreen_X
//		DataMod += diff;
//		ScrMod += diff;
//		cx -= diff;
//	}

	if((g_nFlags&1)==0 ){
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
#ifdef	_XBOX
	while( *pText != 0x00 ){
		OutChar(x,y,*pText++ );
		x+=8;
	}
#endif
}


