// ******************************************************************
// * 
// * proj : OpenXDK
// *
// * desc : Open Source XBox Development Kit
// *
// * file : xboxvga.h
// *
// * note : 
// *
// ******************************************************************


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
#define	RES_640X480				(6)								// Hardware mode *NOT YET*
#define	RES_720X480				(7)								// Hardware mode *NOT YET*
#define	RES_800X600				(8)								// Hardware mode *NOT YET*
#define	RES_1024X768			(9)								// Hardware mode *NOT YET*
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



extern	u32	g_nFlags;
extern	u32	g_nInk;
extern	u32	g_nPaper;
extern	u8	*pFont;								// point to the system Font by default. You can change it to your own

extern	u32	pScreenBuffer[];					// Our screen (software emulated for LOW res just now)
extern	u32	FrontBuffer;						// Current screen address (visible)
extern	u32	BackBuffer;							// Current back buffer
extern	u32	g_nFontFlags;

extern	u32	_FrontBuffer;						// Current screen address (visible)
extern	u32	_BackBuffer;						// Current back buffer
extern	u32	_Framebuffer;
extern  u32	g_ScreenWidth;			// Current Screen Width
extern  u32	g_ScreenHeight;			// Current Screen Height

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






#ifdef	__cplusplus
}
#endif
#endif	//__XBFRAME__



