#ifndef	__XBFRAME__
#define	__XBFRAME__
#ifdef	__cplusplus
extern "C" {
#endif

#include	"openxdk.h"

#define	_32BITCOLOUR			(0x00000000)
#define	_16BITCOLOUR			(0x00000100)
#define	_8BITCOLOUR				(0x00000200)

#define	RES_320X200				(1)
#define	RES_320X240				(2)
#define	RES_640X400				(3)
#define	RES_640X480				(4)

#define	MODE_320x200x32			(RES_320X200|_32BITCOLOUR)		// not yet
#define	MODE_320x240x32			(RES_320X240|_32BITCOLOUR)
#define	MODE_640x400x32			(RES_640X400|_32BITCOLOUR)		// not yet
#define	MODE_640x480x32			(RES_640X480|_32BITCOLOUR)		// not yet
#define	MODE_320x200x16			(RES_320X200|_16BITCOLOUR)		// not yet
#define	MODE_320x240x16			(RES_320X240|_16BITCOLOUR)		// not yet
#define	MODE_640x400x16			(RES_640X400|_16BITCOLOUR)		// not yet
#define	MODE_640x480x16			(RES_640X480|_16BITCOLOUR)		// not yet


extern	u8 SystemFont[];


#ifndef		__XBOXVGA_INTERNAL_INCLUDE__
#define		__XBOXVGA_INTERNAL_INCLUDE__

extern	u32	g_nFlags;
extern	u32	g_nInk;
extern	u32	g_nPaper;

// **************************************************************
//
//	User Functions
//
// **************************************************************
void	InitMode( int Mode );					// Init VGA screen to a selected mode
void	WaitVBlank( void );						// Wait for vertical blank
void	Flip( void );							// Flip buffers
void	Cls( void );							// Clear screen
u8*		GetScreen( void );						// get screen base address
void	Box( int x1,int y1, int x2,int y2 );	// Draw wireframe BOX (WHITE)
void	Print( int x, int y, char* pText );		// Draw text using SYSTEM font

// **************************************************************
//
// Misc things... will be used later
//
// **************************************************************
void	SetColour( int reg, int R, int G, int B );
void	SetReg( int port, int reg, int data );


#endif	//__XBOXVGA_INTERNAL_INCLUDE__


// **************************************************************
//
// internally used stuff
//
// **************************************************************

#define XBV_BASE			0xfd601000
#define XBV_ATTR_REG_INDEX	0xfd6013c0
#define XBV_ATTR_REG_DATA	0xfd6013c1
#define XBV_ATTR_REG_INDEX2	0xfd6013c2
#define XBV_ATTR_REG_INDEX3	0xfd6013c3
#define XBV_CRTC_REG_INDEX	0xfd6013d4
#define XBV_CRTC_REG_DATA	0xfd6013d5
#define XBV_GRA_REG_INDEX	0xfd0C03ce
#define XBV_GRA_REG_DATA	0xfd0C03cf
#define XBV_SEQ_REG_INDEX	0xfd0C03c4
#define XBV_SEQ_REG_DATA	0xfd0C03c5
#define XBV_MISC_REG	0xfd0C03c2
#define VBL					0xfd6013da

#define XBV_COLOUR_REG		0xfd6013c8
#define XBV_COLOUR_DATA		0xfd6013c9

#define	XBOX_SCREENRAM		0x8003d040		//0xF0040240	//+(95*4)		// Xbox screen RAM starts here


/*
	xxxxADDR defines the base port number used to access VGA component xxxx,
	and is defined for xxxx =
		ATTRCON		-	Attribute Controller
		MISC		-	Miscellaneous Register
		VGAENABLE	-	VGA Enable Register
		SEQ			-	Sequencer
		GRACON		-	Graphics Controller
		CRTC		-	Cathode Ray Tube Controller
		STATUS		-	Status Register
*/
typedef struct
	{
			short	port;
	unsigned char	index;
	unsigned char	value;
} Register;

#define ATTRCON_ADDR	0x3c0
#define MISC_ADDR		0x3c2
#define VGAENABLE_ADDR	0x3c3
#define SEQ_ADDR		0x3c4
#define GRACON_ADDR		0x3ce
#define CRTC_ADDR		0x3d4
#define STATUS_ADDR		0x3da




#ifdef	__cplusplus
}
#endif
#endif	//__XBFRAME__



