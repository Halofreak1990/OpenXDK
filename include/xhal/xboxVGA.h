#ifndef	__XBFRAME__
#define	__XBFRAME__
#ifdef	__cplusplus
extern "C" {
#endif

#include	"openxdk.h"
#include	"NVidia.h"

//
// Bit depths
//
#define	_32BITCOLOUR			(0x00000000)
#define	_16BITCOLOUR			(0x00000010)
#define	_8BITCOLOUR				(0x00000020)
#define	COLOUR_MASK				(0x00000030)

//
// Pixel resolutions
//
#define	RES_320X200				(1)								// Hardware mode *NOT YET*
#define	RES_320X240				(2)								// Software emulated
#define	RES_640X200				(3)								// Hardware mode *NOT YET*
#define	RES_640X240				(4)								// Hardware mode *NOT YET*
#define	RES_640X400				(5)								// Hardware mode *NOT YET*
#define	RES_640X480				(6)								// Hardware mode
#define	RES_MASK				(15)

//
// Easy to use screen modes
// 
#define	MODE_320x200x32			(RES_320X200|_32BITCOLOUR)		// not yet
#define	MODE_320x240x32			(RES_320X240|_32BITCOLOUR)
#define	MODE_640x200x32			(RES_320X200|_32BITCOLOUR)		// not yet
#define	MODE_640x240x32			(RES_320X240|_32BITCOLOUR)
#define	MODE_640x400x32			(RES_640X400|_32BITCOLOUR)		// not yet
#define	MODE_640x480x32			(RES_640X480|_32BITCOLOUR)		// not yet
#define	MODE_320x200x16			(RES_320X200|_16BITCOLOUR)		// not yet
#define	MODE_320x240x16			(RES_320X240|_16BITCOLOUR)		// not yet
#define	MODE_640x200x16			(RES_320X200|_16BITCOLOUR)		// not yet
#define	MODE_640x240x16			(RES_320X240|_16BITCOLOUR)		// not yet
#define	MODE_640x400x16			(RES_640X400|_16BITCOLOUR)		// not yet
#define	MODE_640x480x16			(RES_640X480|_16BITCOLOUR)		// not yet


// GetScreen() return struct
typedef	struct SScreen{
	u32	ScreenAddress;
	u32	lpitch;
}SScreen;


extern	u8 SystemFont[];						// handy to use system font


#ifndef		__XBOXVGA_INTERNAL_INCLUDE__
#define		__XBOXVGA_INTERNAL_INCLUDE__

extern	u32	g_nFlags;
extern	u32	g_nInk;
extern	u32	g_nPaper;
extern	u8	*pFont;								// point to the system Font by default. You can change it to your own

extern	u32	pScreenBuffer[];					// Our screen (software emulated for LOW res just now)
extern	u32	FrontBuffer;						// Current screen address (visible)
extern	u32	BackBuffer;							// Current back buffer
extern	u32	g_nFontFlags;

extern	int	_fltused;
// **************************************************************
//
//	User Functions
//
// **************************************************************
void	InitMode( int Mode );					// Init VGA screen to a selected mode
void	WaitVBlank( void );						// Wait for vertical blank
void	Flip( void );							// Flip buffers
void	Cls( void );							// Clear screen
SScreen	GetScreen( void );						// get screen base address
void	Box( int x1,int y1, int x2,int y2 );	// Draw wireframe BOX (WHITE)
void	Print( int x, int y, char* pText );		// Draw text using SYSTEM font (32bit modes only just now)

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
#define XBV_MISC_REG		0xfd0C03c2
#define VBL					0xfd6013da

#define XBV_COLOUR_REG		0xfd6013c8
#define XBV_COLOUR_DATA		0xfd6013c9

#define	XBOX_SCREENRAM		0x8003d040		// Xbox screen RAM starts here (power on default)


//
// System flags
//
#define	XHAL_320SCREEN		(1)				// Software emulation of 320x??? mode
#define	YHAL_200SCREEN		(2)				// Center 200 screen inside a 240 one

#define	FONT_SOLID			(1)				// render font with SOLID background (with paper colour)
#define	FONT_WRAP			(2)				// Wrap PRINT's when they go off the screen

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



/*
 *
 * VGA registers
 *
 */
#define VGAREG_ACTL_ADDRESS            0x3c0
#define VGAREG_ACTL_WRITE_DATA         0x3c0
#define VGAREG_ACTL_READ_DATA          0x3c1

#define VGAREG_INPUT_STATUS            0x3c2
#define VGAREG_WRITE_MISC_OUTPUT       0x3c2
#define VGAREG_VIDEO_ENABLE            0x3c3
#define VGAREG_SEQU_ADDRESS            0x3c4
#define VGAREG_SEQU_DATA               0x3c5

#define VGAREG_PEL_MASK                0x3c6
#define VGAREG_DAC_STATE               0x3c7
#define VGAREG_DAC_READ_ADDRESS        0x3c7
#define VGAREG_DAC_WRITE_ADDRESS       0x3c8
#define VGAREG_DAC_DATA                0x3c9

#define VGAREG_READ_FEATURE_CTL        0x3ca
#define VGAREG_READ_MISC_OUTPUT        0x3cc

#define VGAREG_GRDC_ADDRESS            0x3ce
#define VGAREG_GRDC_DATA               0x3cf

#define VGAREG_MDA_CRTC_ADDRESS        0x3b4
#define VGAREG_MDA_CRTC_DATA           0x3b5
#define VGAREG_VGA_CRTC_ADDRESS        0x3d4
#define VGAREG_VGA_CRTC_DATA           0x3d5

#define VGAREG_MDA_WRITE_FEATURE_CTL   0x3ba
#define VGAREG_VGA_WRITE_FEATURE_CTL   0x3da
#define VGAREG_ACTL_RESET              0x3da

#define VGAREG_MDA_MODECTL             0x3b8
#define VGAREG_CGA_MODECTL             0x3d8
#define VGAREG_CGA_PALETTE             0x3d9

/* Video memory */
#define VGAMEM_GRAPH 0xA000
#define VGAMEM_CTEXT 0xB800
#define VGAMEM_MTEXT 0xB000


#ifdef	__cplusplus
}
#endif
#endif	//__XBFRAME__



