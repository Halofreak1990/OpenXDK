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

#include "xhal/xvga_def.h"
#include "xhal/xnvidia.h"

u32	pScreenBuffer[320*240];			// Our screen (software emulated for LOW res just now)
u32	FrontBuffer=0;					// Current screen address (visible)
u32	BackBuffer=0;						// Current back buffer

u32	_FrontBuffer=0;					// Current screen address (visible)
u32	_BackBuffer=0;						// Current back buffer
u32	_Framebuffer;


int	_fltused;
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




// **************************************************************************
//
// Flip buffers (320x240) or (320x200) only just now...more later
//
// **************************************************************************
void	vga_flip( void )
{
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
			Scr.lpitch = 640*4;
			return Scr;
		}
		else{
			Scr.ScreenAddress = (u32) &pScreenBuffer[0];
			Scr.lpitch = 640*4;
			return Scr;
		}
	}
	else{
		Scr.ScreenAddress = _BackBuffer;	//_Framebuffer;	//(BackBuffer&0x0fffffff);
		Scr.lpitch = 640*4;
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
	int	i=0;
//	u8*	pScr;

	switch( (Mode&RES_MASK) )
	{
		case	RES_320X200:	g_ScreenWidth = 320;
								g_ScreenHeight= 240;
								g_nFlags |= XHAL_320SCREEN|YHAL_200SCREEN;			// Software mode, screen will need copied
								break;
		case	RES_320X240:	g_ScreenWidth = 320;
								g_ScreenHeight= 240;
								g_nFlags |= XHAL_320SCREEN;							// Software mode, screen will need copied
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
	//NVSetBPP(Mode&COLOUR_MASK);


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

		// Get CPU screen address
		_FrontBuffer=XBOX_SCREENRAM+0x40;										// address of VRAM (logical address for CPU)
		_BackBuffer = _FrontBuffer+(g_ScreenWidth*g_ScreenHeight*g_nBPP);		// Current back buffer

		// Get HW address for setting buffers
		FrontBuffer = XBOX_SCREENRAM&0xfffffff;									// Get Physical address
		BackBuffer = FrontBuffer+(g_ScreenWidth*g_ScreenHeight*g_nBPP);			// Current back buffer
	}
	else{
		XdkSetVideoMode( Mode&RES_MASK, Mode&COLOUR_MASK );
		
/*		
	  AvSetDisplayMode(
			(PVOID)NV_REGBASE,
			0,
			(ULONG)0,		//640,	//RESOLUTION_640,	//res,
			(ULONG)0,		//PIXEL_32BITS,	//pix,
			(ULONG)(640*4),			//Pitch,
			XBOX_SCREENRAM&0xfffffff
		);

		_FrontBuffer=XBOX_SCREENRAM+ 0x40;
		_BackBuffer=_FrontBuffer;

		FrontBuffer = XBOX_SCREENRAM&0xfffffff;											// Set current visible screen
		BackBuffer = FrontBuffer;
*/
	}

	
	// Clear both buffers
//	i = g_ScreenWidth*g_ScreenHeight*g_nBPP*2;
//	pScr = (u8*)FrontBuffer;
//	while(i>=0){
//		pScr [i]=0;
//		i--;
//	}



#endif

}


// **************************************************************************
//
//	Name:		Cls
//	Function:	Clear the screen to BLACK (better will follow)
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
void vga_set_reg( int port, int reg, int data )
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
void vga_set_color( int reg, int R, int G, int B )
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
#ifdef	_MSC_VER
/*
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
*/

__declspec(naked) long _ftol(float arg)
{
	_asm{
		  // store as a quadword int and reload
		sub		esp, 8					// RING 0 - MUST do
		fld     st(0)					// X X
		fistp   QWORD PTR [esp]			// X
		fild    QWORD PTR [esp]			// X [X]
		mov     edx,DWORD PTR [esp+4]
		mov     eax,DWORD PTR [esp]
		test    eax,eax
		je      maybe_zero

		// number isn't zero, so get X - [X]
	not_zero:
		fsubp   st(1),st				// X - [X]
		test    edx,edx
		jns     positive

		// number < 0 - inc eax if X - [X] is >0
		fstp    DWORD PTR [esp]
		mov     ecx,DWORD PTR [esp]		// get IEEE rep
		xor     ecx,80000000h			// now <0 if diff >0
		add     ecx,7FFFFFFFh			// carry if it was 00000001 to 7FFFFFFF
		adc     eax,0					// add carry in
		add		esp, 8
		ret

	positive:
		// number > 0 - dec eax if X - [X] is <0
		fstp    DWORD PTR [esp]
		mov     ecx,DWORD PTR [esp]		// get IEEE rep
		add     ecx,7FFFFFFFh			// carry if it was 80000001 to FFFFFFFF
		sbb     eax,0					// sub carry
		add		esp, 8
		ret

	maybe_zero:
		test    edx,7FFFFFFFh
		jnz     not_zero

		// number is zero - clear the stack
		fstp    st(0)
		fstp    st(0)
		add		esp, 8
		ret
	}
}
#endif // _MSC_VER


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
	ScreenInfo	ScrStruct = vga_get_screen_info();
	u32*	pScreen = (u32*)ScrStruct.ScreenAddress;

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






