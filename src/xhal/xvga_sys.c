// ************************************************************************************
//
//
//								 xvga_sys.c
//                       First Version by Bigboy
//
//
//
//  Revision		By				Comment
//  --------		--				-------
//	1.0				Bigboy			Moved misc internal VGA function to here.
//  
//
// ************************************************************************************
#include	<openxdk.h>

#include "xhal/xvga_def.h"
#include "xhal/xnvidia.h"



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
