/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2004 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Sam Lantinga
    slouken@libsdl.org
*/

#ifdef SAVE_RCSID
static char rcsid =
 "@(#) $Id$";
#endif

/* X11 based SDL video driver implementation.
   Note:  This implementation does not currently need X11 thread locking,
          since the event thread uses a separate X connection and any
          additional locking necessary is handled internally.  However,
          if full locking is neccessary, take a look at XInitThreads().
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#ifdef MTRR_SUPPORT
#include <asm/mtrr.h>
#include <sys/fcntl.h>
#endif

#ifdef HAVE_ALLOCA_H
#include <alloca.h>
#endif

#ifdef HAVE_ALLOCA
#define ALLOCA(n) ((void*)alloca(n))
#define FREEA(p)
#else
#define ALLOCA(n) malloc(n)
#define FREEA(p) free(p)
#endif

#include "SDL.h"
#include "SDL_error.h"
#include "SDL_timer.h"
#include "SDL_thread.h"
#include "SDL_video.h"
#include "SDL_mouse.h"
#include "SDL_endian.h"
#include "SDL_sysvideo.h"
#include "SDL_pixels_c.h"
#include "SDL_events_c.h"
#include "SDL_x11video.h"
#include "SDL_x11wm_c.h"
#include "SDL_x11mouse_c.h"
#include "SDL_x11events_c.h"
#include "SDL_x11modes_c.h"
#include "SDL_x11image_c.h"
#include "SDL_x11yuv_c.h"
#include "SDL_x11gl_c.h"
#include "SDL_x11gamma_c.h"
#include "blank_cursor.h"

/* Initialization/Query functions */
static int X11_VideoInit(_THIS, SDL_PixelFormat *vformat);
static SDL_Surface *X11_SetVideoMode(_THIS, SDL_Surface *current, int width, int height, int bpp, Uint32 flags);
static int X11_ToggleFullScreen(_THIS, int on);
static void X11_UpdateMouse(_THIS);
static int X11_SetColors(_THIS, int firstcolor, int ncolors,
			 SDL_Color *colors);
static int X11_SetGammaRamp(_THIS, Uint16 *ramp);
static void X11_VideoQuit(_THIS);

/* X11 driver bootstrap functions */

static int X11_Available(void)
{
	Display *display;

	display = XOpenDisplay(NULL);
	if ( display != NULL ) {
		XCloseDisplay(display);
	}
	return(display != NULL);
}

static void X11_DeleteDevice(SDL_VideoDevice *device)
{
	if ( device ) {
		if ( device->hidden ) {
			free(device->hidden);
		}
		if ( device->gl_data ) {
			free(device->gl_data);
		}
		free(device);
	}
}

static SDL_VideoDevice *X11_CreateDevice(int devindex)
{
	SDL_VideoDevice *device;

	/* Initialize all variables that we clean on shutdown */
	device = (SDL_VideoDevice *)malloc(sizeof(SDL_VideoDevice));
	if ( device ) {
		memset(device, 0, (sizeof *device));
		device->hidden = (struct SDL_PrivateVideoData *)
				malloc((sizeof *device->hidden));
		device->gl_data = (struct SDL_PrivateGLData *)
				malloc((sizeof *device->gl_data));
	}
	if ( (device == NULL) || (device->hidden == NULL) ||
	                         (device->gl_data == NULL) ) {
		SDL_OutOfMemory();
		X11_DeleteDevice(device);
		return(0);
	}
	memset(device->hidden, 0, (sizeof *device->hidden));
	memset(device->gl_data, 0, (sizeof *device->gl_data));

	/* Set the driver flags */
	device->handles_any_size = 1;

	/* Set the function pointers */
	device->VideoInit = X11_VideoInit;
	device->ListModes = X11_ListModes;
	device->SetVideoMode = X11_SetVideoMode;
	device->ToggleFullScreen = X11_ToggleFullScreen;
	device->UpdateMouse = X11_UpdateMouse;
#ifdef XFREE86_XV
	device->CreateYUVOverlay = X11_CreateYUVOverlay;
#endif
	device->SetColors = X11_SetColors;
	device->UpdateRects = NULL;
	device->VideoQuit = X11_VideoQuit;
	device->AllocHWSurface = X11_AllocHWSurface;
	device->CheckHWBlit = NULL;
	device->FillHWRect = NULL;
	device->SetHWColorKey = NULL;
	device->SetHWAlpha = NULL;
	device->LockHWSurface = X11_LockHWSurface;
	device->UnlockHWSurface = X11_UnlockHWSurface;
	device->FlipHWSurface = X11_FlipHWSurface;
	device->FreeHWSurface = X11_FreeHWSurface;
	device->SetGamma = X11_SetVidModeGamma;
	device->GetGamma = X11_GetVidModeGamma;
	device->SetGammaRamp = X11_SetGammaRamp;
	device->GetGammaRamp = NULL;
#ifdef HAVE_OPENGL
	device->GL_LoadLibrary = X11_GL_LoadLibrary;
	device->GL_GetProcAddress = X11_GL_GetProcAddress;
	device->GL_GetAttribute = X11_GL_GetAttribute;
	device->GL_MakeCurrent = X11_GL_MakeCurrent;
	device->GL_SwapBuffers = X11_GL_SwapBuffers;
#endif
	device->SetCaption = X11_SetCaption;
	device->SetIcon = X11_SetIcon;
	device->IconifyWindow = X11_IconifyWindow;
	device->GrabInput = X11_GrabInput;
	device->GetWMInfo = X11_GetWMInfo;
	device->FreeWMCursor = X11_FreeWMCursor;
	device->CreateWMCursor = X11_CreateWMCursor;
	device->ShowWMCursor = X11_ShowWMCursor;
	device->WarpWMCursor = X11_WarpWMCursor;
	device->CheckMouseMode = X11_CheckMouseMode;
	device->InitOSKeymap = X11_InitOSKeymap;
	device->PumpEvents = X11_PumpEvents;

	device->free = X11_DeleteDevice;

	return device;
}

VideoBootStrap X11_bootstrap = {
	"x11", "X Window System",
	X11_Available, X11_CreateDevice
};

/* Shared memory information */
extern int XShmQueryExtension(Display *dpy);	/* Not in X11 headers */

/* Normal X11 error handler routine */
static int (*X_handler)(Display *, XErrorEvent *) = NULL;
static int x_errhandler(Display *d, XErrorEvent *e)
{
#ifdef XFREE86_VM
	extern int vm_error;
#endif
#ifdef XFREE86_DGAMOUSE
	extern int dga_error;
#endif

#ifdef XFREE86_VM
	/* VidMode errors are non-fatal. :) */
	/* Are the errors offset by one from the error base?
	   e.g. the error base is 143, the code is 148, and the
	        actual error is XF86VidModeExtensionDisabled (4) ?
	 */
        if ( (vm_error >= 0) &&
	     (((e->error_code == BadRequest)&&(e->request_code == vm_error)) ||
	      ((e->error_code > vm_error) &&
	       (e->error_code <= (vm_error+XF86VidModeNumberErrors)))) ) {
#ifdef XFREE86_DEBUG
{ char errmsg[1024];
  XGetErrorText(d, e->error_code, errmsg, sizeof(errmsg));
printf("VidMode error: %s\n", errmsg);
}
#endif
        	return(0);
        }
#endif /* XFREE86_VM */

#ifdef XFREE86_DGAMOUSE
	/* DGA errors can be non-fatal. :) */
        if ( (dga_error >= 0) &&
	     ((e->error_code > dga_error) &&
	      (e->error_code <= (dga_error+XF86DGANumberErrors))) ) {
#ifdef XFREE86_DEBUG
{ char errmsg[1024];
  XGetErrorText(d, e->error_code, errmsg, sizeof(errmsg));
printf("DGA error: %s\n", errmsg);
}
#endif
        	return(0);
        }
#endif /* XFREE86_DGAMOUSE */

	return(X_handler(d,e));
}

/* X11 I/O error handler routine */
static int (*XIO_handler)(Display *) = NULL;
static int xio_errhandler(Display *d)
{
	/* Ack!  Lost X11 connection! */

	/* We will crash if we try to clean up our display */
	if ( current_video->hidden->Ximage ) {
		SDL_VideoSurface->pixels = NULL;
	}
	current_video->hidden->X11_Display = NULL;

	/* Continue with the standard X11 error handler */
	return(XIO_handler(d));
}

/* Create auxiliary (toplevel) windows with the current visual */
static void create_aux_windows(_THIS)
{
    XSetWindowAttributes xattr;
    XWMHints *hints;
    XTextProperty titleprop, iconprop;
    int def_vis = (SDL_Visual == DefaultVisual(SDL_Display, SDL_Screen));

    /* Don't create any extra windows if we are being managed */
    if ( SDL_windowid ) {
	FSwindow = 0;
	WMwindow = strtol(SDL_windowid, NULL, 0);
        return;
    }

    if(FSwindow)
	XDestroyWindow(SDL_Display, FSwindow);

    xattr.override_redirect = True;
    xattr.background_pixel = def_vis ? BlackPixel(SDL_Display, SDL_Screen) : 0;
    xattr.border_pixel = 0;
    xattr.colormap = SDL_XColorMap;

    FSwindow = XCreateWindow(SDL_Display, SDL_Root,
                             xinerama_x, xinerama_y, 32, 32, 0,
			     this->hidden->depth, InputOutput, SDL_Visual,
			     CWOverrideRedirect | CWBackPixel | CWBorderPixel
			     | CWColormap,
			     &xattr);

    XSelectInput(SDL_Display, FSwindow, StructureNotifyMask);

    /* Tell KDE to keep the fullscreen window on top */
    {
	XEvent ev;
	long mask;

	memset(&ev, 0, sizeof(ev));
	ev.xclient.type = ClientMessage;
	ev.xclient.window = SDL_Root;
	ev.xclient.message_type = XInternAtom(SDL_Display,
					      "KWM_KEEP_ON_TOP", False);
	ev.xclient.format = 32;
	ev.xclient.data.l[0] = FSwindow;
	ev.xclient.data.l[1] = CurrentTime;
	mask = SubstructureRedirectMask;
	XSendEvent(SDL_Display, SDL_Root, False, mask, &ev);
    }

    hints = NULL;
    titleprop.value = iconprop.value = NULL;
    if(WMwindow) {
	/* All window attributes must survive the recreation */
	hints = XGetWMHints(SDL_Display, WMwindow);
	XGetWMName(SDL_Display, WMwindow, &titleprop);
	XGetWMIconName(SDL_Display, WMwindow, &iconprop);
	XDestroyWindow(SDL_Display, WMwindow);
    }

    /* Create the window for windowed management */
    /* (reusing the xattr structure above) */
    WMwindow = XCreateWindow(SDL_Display, SDL_Root, 0, 0, 32, 32, 0,
			     this->hidden->depth, InputOutput, SDL_Visual,
			     CWBackPixel | CWBorderPixel | CWColormap,
			     &xattr);

    /* Set the input hints so we get keyboard input */
    if(!hints) {
	hints = XAllocWMHints();
	hints->input = True;
	hints->flags = InputHint;
    }
    XSetWMHints(SDL_Display, WMwindow, hints);
    XFree(hints);
    if(titleprop.value) {
	XSetWMName(SDL_Display, WMwindow, &titleprop);
	XFree(titleprop.value);
    }
    if(iconprop.value) {
	XSetWMIconName(SDL_Display, WMwindow, &iconprop);
	XFree(iconprop.value);
    }

    XSelectInput(SDL_Display, WMwindow,
		 FocusChangeMask | KeyPressMask | KeyReleaseMask
		 | PropertyChangeMask | StructureNotifyMask | KeymapStateMask);

    /* Set the class hints so we can get an icon (AfterStep) */
    {
	XClassHint *classhints;
	classhints = XAllocClassHint();
	if(classhints != NULL) {
            char *classname = getenv("SDL_VIDEO_X11_WMCLASS");
            if ( ! classname ) {
                classname = "SDL_App";
            }
	    classhints->res_name = classname;
	    classhints->res_class = classname;
	    XSetClassHint(SDL_Display, WMwindow, classhints);
	    XFree(classhints);
	}
    }

    /* Allow the window to be deleted by the window manager */
    WM_DELETE_WINDOW = XInternAtom(SDL_Display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(SDL_Display, WMwindow, &WM_DELETE_WINDOW, 1);
}

static int X11_VideoInit(_THIS, SDL_PixelFormat *vformat)
{
	char *display;
	int i;

	/* Open the X11 display */
	display = NULL;		/* Get it from DISPLAY environment variable */

	if ( (strncmp(XDisplayName(display), ":", 1) == 0) ||
	     (strncmp(XDisplayName(display), "unix:", 5) == 0) ) {
		local_X11 = 1;
	} else {
		local_X11 = 0;
	}
	SDL_Display = XOpenDisplay(display);
	if ( SDL_Display == NULL ) {
		SDL_SetError("Couldn't open X11 display");
		return(-1);
	}
#ifdef X11_DEBUG
	XSynchronize(SDL_Display, True);
#endif

	/* Create an alternate X display for graphics updates -- allows us
	   to do graphics updates in a separate thread from event handling.
	   Thread-safe X11 doesn't seem to exist.
	 */
	GFX_Display = XOpenDisplay(display);
	if ( GFX_Display == NULL ) {
		SDL_SetError("Couldn't open X11 display");
		return(-1);
	}

	/* Set the normal X error handler */
	X_handler = XSetErrorHandler(x_errhandler);

	/* Set the error handler if we lose the X display */
	XIO_handler = XSetIOErrorHandler(xio_errhandler);

	/* use default screen (from $DISPLAY) */
	SDL_Screen = DefaultScreen(SDL_Display);

#ifndef NO_SHARED_MEMORY
	/* Check for MIT shared memory extension */
	use_mitshm = 0;
	if ( local_X11 ) {
		use_mitshm = XShmQueryExtension(SDL_Display);
	}
#endif /* NO_SHARED_MEMORY */

	/* Get the available video modes */
	if(X11_GetVideoModes(this) < 0)
	    return -1;

	/* Determine the default screen depth:
	   Use the default visual (or at least one with the same depth) */
	SDL_DisplayColormap = DefaultColormap(SDL_Display, SDL_Screen);
	for(i = 0; i < this->hidden->nvisuals; i++)
	    if(this->hidden->visuals[i].depth == DefaultDepth(SDL_Display,
							      SDL_Screen))
		break;
	if(i == this->hidden->nvisuals) {
	    /* default visual was useless, take the deepest one instead */
	    i = 0;
	}
	SDL_Visual = this->hidden->visuals[i].visual;
	if ( SDL_Visual == DefaultVisual(SDL_Display, SDL_Screen) ) {
	    SDL_XColorMap = SDL_DisplayColormap;
	} else {
	    SDL_XColorMap = XCreateColormap(SDL_Display, SDL_Root,
					    SDL_Visual, AllocNone);
	}
	this->hidden->depth = this->hidden->visuals[i].depth;
	vformat->BitsPerPixel = this->hidden->visuals[i].bpp;
	if ( vformat->BitsPerPixel > 8 ) {
		vformat->Rmask = SDL_Visual->red_mask;
	  	vformat->Gmask = SDL_Visual->green_mask;
	  	vformat->Bmask = SDL_Visual->blue_mask;
	}
	X11_SaveVidModeGamma(this);

	/* See if we have been passed a window to use */
	SDL_windowid = getenv("SDL_WINDOWID");

	/* Create the fullscreen and managed windows */
	create_aux_windows(this);

	/* Create the blank cursor */
	SDL_BlankCursor = this->CreateWMCursor(this, blank_cdata, blank_cmask,
					BLANK_CWIDTH, BLANK_CHEIGHT,
						BLANK_CHOTX, BLANK_CHOTY);

	/* Fill in some window manager capabilities */
	this->info.wm_available = 1;

	/* We're done! */
	XFlush(SDL_Display);
	return(0);
}

static void X11_DestroyWindow(_THIS, SDL_Surface *screen)
{
	/* Clean up OpenGL */
	if ( screen ) {
		screen->flags &= ~(SDL_OPENGL|SDL_OPENGLBLIT);
	}
	X11_GL_Shutdown(this);

	if ( ! SDL_windowid ) {
		/* Hide the managed window */
		if ( WMwindow ) {
			XUnmapWindow(SDL_Display, WMwindow);
		}
		if ( screen && (screen->flags & SDL_FULLSCREEN) ) {
			screen->flags &= ~SDL_FULLSCREEN;
			X11_LeaveFullScreen(this);
		}

		/* Destroy the output window */
		if ( SDL_Window ) {
			XDestroyWindow(SDL_Display, SDL_Window);
		}

		/* Free the colormap entries */
		if ( SDL_XPixels ) {
			int numcolors;
			unsigned long pixel;
			numcolors = SDL_Visual->map_entries;
			for ( pixel=0; pixel<numcolors; ++pixel ) {
				while ( SDL_XPixels[pixel] > 0 ) {
					XFreeColors(GFX_Display,
						SDL_DisplayColormap,&pixel,1,0);
					--SDL_XPixels[pixel];
				}
			}
			free(SDL_XPixels);
			SDL_XPixels = NULL;
		} 

		/* Free the graphics context */
		if ( SDL_GC ) {
			XFreeGC(SDL_Display, SDL_GC);
			SDL_GC = 0;
		}
	}
}

static SDL_bool X11_WindowPosition(_THIS, int *x, int *y, int w, int h)
{
	const char *window = getenv("SDL_VIDEO_WINDOW_POS");
	const char *center = getenv("SDL_VIDEO_CENTERED");
	if ( window ) {
		if ( sscanf(window, "%d,%d", x, y) == 2 ) {
			return SDL_TRUE;
		}
		if ( strcmp(window, "center") == 0 ) {
			center = window;
		}
	}
	if ( center ) {
		*x = (DisplayWidth(SDL_Display, SDL_Screen) - w)/2;
		*y = (DisplayHeight(SDL_Display, SDL_Screen) - h)/2;
		return SDL_TRUE;
	}
	return SDL_FALSE;
}

static void X11_SetSizeHints(_THIS, int w, int h, Uint32 flags)
{
	XSizeHints *hints;

	hints = XAllocSizeHints();
	if ( hints ) {
		if ( flags & SDL_RESIZABLE ) {
			hints->min_width = 32;
			hints->min_height = 32;
			hints->max_height = 4096;
			hints->max_width = 4096;
		} else {
			hints->min_width = hints->max_width = w;
			hints->min_height = hints->max_height = h;
		}
		hints->flags = PMaxSize | PMinSize;
		if ( flags & SDL_FULLSCREEN ) {
			hints->x = 0;
			hints->y = 0;
			hints->flags |= USPosition;
		} else
		/* Center it, if desired */
		if ( X11_WindowPosition(this, &hints->x, &hints->y, w, h) ) {
			hints->flags |= USPosition;
			XMoveWindow(SDL_Display, WMwindow, hints->x, hints->y);

			/* Flush the resize event so we don't catch it later */
			XSync(SDL_Display, True);
		}
		XSetWMNormalHints(SDL_Display, WMwindow, hints);
		XFree(hints);
	}

	/* Respect the window caption style */
	if ( flags & SDL_NOFRAME ) {
		SDL_bool set;
		Atom WM_HINTS;

		/* We haven't modified the window manager hints yet */
		set = SDL_FALSE;

		/* First try to set MWM hints */
		WM_HINTS = XInternAtom(SDL_Display, "_MOTIF_WM_HINTS", True);
		if ( WM_HINTS != None ) {
			/* Hints used by Motif compliant window managers */
			struct {
				unsigned long flags;
				unsigned long functions;
				unsigned long decorations;
				long input_mode;
				unsigned long status;
			} MWMHints = { (1L << 1), 0, 0, 0, 0 };

			XChangeProperty(SDL_Display, WMwindow,
			                WM_HINTS, WM_HINTS, 32,
			                PropModeReplace,
					(unsigned char *)&MWMHints,
					sizeof(MWMHints)/sizeof(long));
			set = SDL_TRUE;
		}
		/* Now try to set KWM hints */
		WM_HINTS = XInternAtom(SDL_Display, "KWM_WIN_DECORATION", True);
		if ( WM_HINTS != None ) {
			long KWMHints = 0;

			XChangeProperty(SDL_Display, WMwindow,
			                WM_HINTS, WM_HINTS, 32,
			                PropModeReplace,
					(unsigned char *)&KWMHints,
					sizeof(KWMHints)/sizeof(long));
			set = SDL_TRUE;
		}
		/* Now try to set GNOME hints */
		WM_HINTS = XInternAtom(SDL_Display, "_WIN_HINTS", True);
		if ( WM_HINTS != None ) {
			long GNOMEHints = 0;

			XChangeProperty(SDL_Display, WMwindow,
			                WM_HINTS, WM_HINTS, 32,
			                PropModeReplace,
					(unsigned char *)&GNOMEHints,
					sizeof(GNOMEHints)/sizeof(long));
			set = SDL_TRUE;
		}
		/* Finally set the transient hints if necessary */
		if ( ! set ) {
			XSetTransientForHint(SDL_Display, WMwindow, SDL_Root);
		}
	} else {
		SDL_bool set;
		Atom WM_HINTS;

		/* We haven't modified the window manager hints yet */
		set = SDL_FALSE;

		/* First try to unset MWM hints */
		WM_HINTS = XInternAtom(SDL_Display, "_MOTIF_WM_HINTS", True);
		if ( WM_HINTS != None ) {
			XDeleteProperty(SDL_Display, WMwindow, WM_HINTS);
			set = SDL_TRUE;
		}
		/* Now try to unset KWM hints */
		WM_HINTS = XInternAtom(SDL_Display, "KWM_WIN_DECORATION", True);
		if ( WM_HINTS != None ) {
			XDeleteProperty(SDL_Display, WMwindow, WM_HINTS);
			set = SDL_TRUE;
		}
		/* Now try to unset GNOME hints */
		WM_HINTS = XInternAtom(SDL_Display, "_WIN_HINTS", True);
		if ( WM_HINTS != None ) {
			XDeleteProperty(SDL_Display, WMwindow, WM_HINTS);
			set = SDL_TRUE;
		}
		/* Finally unset the transient hints if necessary */
		if ( ! set ) {
			/* NOTE: Does this work? */
			XSetTransientForHint(SDL_Display, WMwindow, None);
		}
	}
}

static int X11_CreateWindow(_THIS, SDL_Surface *screen,
			    int w, int h, int bpp, Uint32 flags)
{
	int i, depth;
	Visual *vis;
	int vis_change;

	/* If a window is already present, destroy it and start fresh */
	if ( SDL_Window ) {
		X11_DestroyWindow(this, screen);
	}

	/* See if we have been given a window id */
	if ( SDL_windowid ) {
		SDL_Window = strtol(SDL_windowid, NULL, 0);
	} else {
		SDL_Window = 0;
	}

	/* find out which visual we are going to use */
	if ( flags & SDL_OPENGL ) {
		XVisualInfo *vi;

		vi = X11_GL_GetVisual(this);
		if( !vi ) {
			return -1;
		}
		vis = vi->visual;
		depth = vi->depth;
	} else if ( SDL_windowid ) {
		XWindowAttributes a;

		XGetWindowAttributes(SDL_Display, SDL_Window, &a);
		vis = a.visual;
		depth = a.depth;
	} else {
		for ( i = 0; i < this->hidden->nvisuals; i++ ) {
			if ( this->hidden->visuals[i].bpp == bpp )
				break;
		}
		if ( i == this->hidden->nvisuals ) {
			SDL_SetError("No matching visual for requested depth");
			return -1;	/* should never happen */
		}
		vis = this->hidden->visuals[i].visual;
		depth = this->hidden->visuals[i].depth;
	}
#ifdef X11_DEBUG
        printf("Choosing %s visual at %d bpp - %d colormap entries\n", vis->class == PseudoColor ? "PseudoColor" : (vis->class == TrueColor ? "TrueColor" : (vis->class == DirectColor ? "DirectColor" : "Unknown")), depth, vis->map_entries);
#endif
	vis_change = (vis != SDL_Visual);
	SDL_Visual = vis;
	this->hidden->depth = depth;

	/* Allocate the new pixel format for this video mode */
	if ( ! SDL_ReallocFormat(screen, bpp,
			vis->red_mask, vis->green_mask, vis->blue_mask, 0) )
		return -1;

	/* Create the appropriate colormap */
	if ( SDL_XColorMap != SDL_DisplayColormap ) {
		XFreeColormap(SDL_Display, SDL_XColorMap);
	}
	if ( SDL_Visual->class == PseudoColor ) {
	    int ncolors;

	    /* Allocate the pixel flags */
	    ncolors = SDL_Visual->map_entries;
	    SDL_XPixels = malloc(ncolors * sizeof(int));
	    if(SDL_XPixels == NULL) {
		SDL_OutOfMemory();
		return -1;
	    }
	    memset(SDL_XPixels, 0, ncolors * sizeof(*SDL_XPixels));

	    /* always allocate a private colormap on non-default visuals */
	    if ( SDL_Visual != DefaultVisual(SDL_Display, SDL_Screen) ) {
		flags |= SDL_HWPALETTE;
	    }
	    if ( flags & SDL_HWPALETTE ) {
		screen->flags |= SDL_HWPALETTE;
		SDL_XColorMap = XCreateColormap(SDL_Display, SDL_Root,
		                                SDL_Visual, AllocAll);
	    } else {
		SDL_XColorMap = SDL_DisplayColormap;
	    }
	} else if ( SDL_Visual->class == DirectColor ) {

	    /* Create a colormap which we can manipulate for gamma */
	    SDL_XColorMap = XCreateColormap(SDL_Display, SDL_Root,
		                            SDL_Visual, AllocAll);
            XSync(SDL_Display, False);

	    /* Initialize the colormap to the identity mapping */
	    SDL_GetGammaRamp(0, 0, 0);
	    this->screen = screen;
	    X11_SetGammaRamp(this, this->gamma);
	    this->screen = NULL;
	} else {
	    /* Create a read-only colormap for our window */
	    SDL_XColorMap = XCreateColormap(SDL_Display, SDL_Root,
	                                    SDL_Visual, AllocNone);
	}

	/* Recreate the auxiliary windows, if needed (required for GL) */
	if ( vis_change )
	    create_aux_windows(this);

	if(screen->flags & SDL_HWPALETTE) {
	    /* Since the full-screen window might have got a nonzero background
	       colour (0 is white on some displays), we should reset the
	       background to 0 here since that is what the user expects
	       with a private colormap */
	    XSetWindowBackground(SDL_Display, FSwindow, 0);
	    XClearWindow(SDL_Display, FSwindow);
	}

	/* resize the (possibly new) window manager window */
	if( !SDL_windowid ) {
	        X11_SetSizeHints(this, w, h, flags);
		current_w = w;
		current_h = h;
		XResizeWindow(SDL_Display, WMwindow, w, h);
	}

	/* Create (or use) the X11 display window */
	if ( !SDL_windowid ) {
		if ( flags & SDL_OPENGL ) {
			if ( X11_GL_CreateWindow(this, w, h) < 0 ) {
				return(-1);
			}
		} else {
			XSetWindowAttributes swa;

			swa.background_pixel = 0;
			swa.border_pixel = 0;
			swa.colormap = SDL_XColorMap;
			SDL_Window = XCreateWindow(SDL_Display, WMwindow,
		                           	0, 0, w, h, 0, depth,
		                           	InputOutput, SDL_Visual,
		                           	CWBackPixel | CWBorderPixel
		                           	| CWColormap, &swa);
		}
		/* Only manage our input if we own the window */
		XSelectInput(SDL_Display, SDL_Window,
					( EnterWindowMask | LeaveWindowMask
					| ButtonPressMask | ButtonReleaseMask
					| PointerMotionMask | ExposureMask ));
	}

	/* Create the graphics context here, once we have a window */
	if ( flags & SDL_OPENGL ) {
		if ( X11_GL_CreateContext(this) < 0 ) {
			return(-1);
		} else {
			screen->flags |= SDL_OPENGL;
		}
	} else {
		XGCValues gcv;

		gcv.graphics_exposures = False;
		SDL_GC = XCreateGC(SDL_Display, SDL_Window,
		                   GCGraphicsExposures, &gcv);
		if ( ! SDL_GC ) {
			SDL_SetError("Couldn't create graphics context");
			return(-1);
		}
	}

	/* Set our colormaps when not setting a GL mode */
	if ( ! (flags & SDL_OPENGL) ) {
		XSetWindowColormap(SDL_Display, SDL_Window, SDL_XColorMap);
		if( !SDL_windowid ) {
		    XSetWindowColormap(SDL_Display, FSwindow, SDL_XColorMap);
		    XSetWindowColormap(SDL_Display, WMwindow, SDL_XColorMap);
		}
	}

#if 0 /* This is an experiment - are the graphics faster now? - nope. */
	if ( getenv("SDL_VIDEO_X11_BACKINGSTORE") )
#endif
	/* Cache the window in the server, when possible */
	{
		Screen *xscreen;
		XSetWindowAttributes a;

		xscreen = ScreenOfDisplay(SDL_Display, SDL_Screen);
		a.backing_store = DoesBackingStore(xscreen);
		if ( a.backing_store != NotUseful ) {
			XChangeWindowAttributes(SDL_Display, SDL_Window,
			                        CWBackingStore, &a);
		}
	}

	/* Update the internal keyboard state */
	X11_SetKeyboardState(SDL_Display, NULL);

	/* When the window is first mapped, ignore non-modifier keys */
	{
		Uint8 *keys = SDL_GetKeyState(NULL);
		for ( i = 0; i < SDLK_LAST; ++i ) {
			switch (i) {
			    case SDLK_NUMLOCK:
			    case SDLK_CAPSLOCK:
			    case SDLK_LCTRL:
			    case SDLK_RCTRL:
			    case SDLK_LSHIFT:
			    case SDLK_RSHIFT:
			    case SDLK_LALT:
			    case SDLK_RALT:
			    case SDLK_LMETA:
			    case SDLK_RMETA:
			    case SDLK_MODE:
				break;
			    default:
				keys[i] = SDL_RELEASED;
				break;
			}
		}
	}

	/* Map them both and go fullscreen, if requested */
	if ( ! SDL_windowid ) {
		XMapWindow(SDL_Display, SDL_Window);
		XMapWindow(SDL_Display, WMwindow);
		X11_WaitMapped(this, WMwindow);
		if ( flags & SDL_FULLSCREEN ) {
			screen->flags |= SDL_FULLSCREEN;
			X11_EnterFullScreen(this);
		} else {
			screen->flags &= ~SDL_FULLSCREEN;
		}
	}
	return(0);
}

static int X11_ResizeWindow(_THIS,
			SDL_Surface *screen, int w, int h, Uint32 flags)
{
	if ( ! SDL_windowid ) {
		/* Resize the window manager window */
		X11_SetSizeHints(this, w, h, flags);
		current_w = w;
		current_h = h;
		XResizeWindow(SDL_Display, WMwindow, w, h);

		/* Resize the fullscreen and display windows */
		if ( flags & SDL_FULLSCREEN ) {
			if ( screen->flags & SDL_FULLSCREEN ) {
				X11_ResizeFullScreen(this);
			} else {
				screen->flags |= SDL_FULLSCREEN;
				X11_EnterFullScreen(this);
			}
		} else {
			if ( screen->flags & SDL_FULLSCREEN ) {
				screen->flags &= ~SDL_FULLSCREEN;
				X11_LeaveFullScreen(this);
			}
		}
		XResizeWindow(SDL_Display, SDL_Window, w, h);
	}
	return(0);
}

SDL_Surface *X11_SetVideoMode(_THIS, SDL_Surface *current,
				int width, int height, int bpp, Uint32 flags)
{
	Uint32 saved_flags;

	/* Lock the event thread, in multi-threading environments */
	SDL_Lock_EventThread();

	/* Check the combination of flags we were passed */
	if ( flags & SDL_FULLSCREEN ) {
		/* Clear fullscreen flag if not supported */
		if ( SDL_windowid ) {
			flags &= ~SDL_FULLSCREEN;
		}
	}

	/* Flush any delayed updates */
	XSync(GFX_Display, False);

	/* Set up the X11 window */
	saved_flags = current->flags;
	if (SDL_Window && (saved_flags&SDL_OPENGL) == (flags&SDL_OPENGL)
	    && bpp == current->format->BitsPerPixel) {
		if (X11_ResizeWindow(this, current, width, height, flags) < 0) {
			current = NULL;
			goto done;
		}
	} else {
		if (X11_CreateWindow(this,current,width,height,bpp,flags) < 0) {
			current = NULL;
			goto done;
		}
	}

	/* Set up the new mode framebuffer */
	if ( ((current->w != width) || (current->h != height)) ||
             ((saved_flags&SDL_OPENGL) != (flags&SDL_OPENGL)) ) {
		current->w = width;
		current->h = height;
		current->pitch = SDL_CalculatePitch(current);
		X11_ResizeImage(this, current, flags);
	}
	current->flags |= (flags&(SDL_RESIZABLE|SDL_NOFRAME));

  done:
	/* Release the event thread */
	XSync(SDL_Display, False);
	SDL_Unlock_EventThread();

	/* We're done! */
	return(current);
}

static int X11_ToggleFullScreen(_THIS, int on)
{
	Uint32 event_thread;

	/* Don't switch if we don't own the window */
	if ( SDL_windowid ) {
		return(0);
	}

	/* Don't lock if we are the event thread */
	event_thread = SDL_EventThreadID();
	if ( event_thread && (SDL_ThreadID() == event_thread) ) {
		event_thread = 0;
	}
	if ( event_thread ) {
		SDL_Lock_EventThread();
	}
	if ( on ) {
		this->screen->flags |= SDL_FULLSCREEN;
		X11_EnterFullScreen(this);
	} else {
		this->screen->flags &= ~SDL_FULLSCREEN;
		X11_LeaveFullScreen(this);
	}
	X11_RefreshDisplay(this);
	if ( event_thread ) {
		SDL_Unlock_EventThread();
	}
	SDL_ResetKeyboard();
	return(1);
}

/* Update the current mouse state and position */
static void X11_UpdateMouse(_THIS)
{
	Window u1; int u2;
	Window current_win;
	int x, y;
	unsigned int mask;

	/* Lock the event thread, in multi-threading environments */
	SDL_Lock_EventThread();
	if ( XQueryPointer(SDL_Display, SDL_Window, &u1, &current_win,
	                   &u2, &u2, &x, &y, &mask) ) {
		if ( (x >= 0) && (x < SDL_VideoSurface->w) &&
		     (y >= 0) && (y < SDL_VideoSurface->h) ) {
			SDL_PrivateAppActive(1, SDL_APPMOUSEFOCUS);
			SDL_PrivateMouseMotion(0, 0, x, y);
		} else {
			SDL_PrivateAppActive(0, SDL_APPMOUSEFOCUS);
		}
	}
	SDL_Unlock_EventThread();
}

/* simple colour distance metric. Supposed to be better than a plain
   Euclidian distance anyway. */
#define COLOUR_FACTOR 3
#define LIGHT_FACTOR 1
#define COLOUR_DIST(r1, g1, b1, r2, g2, b2)				\
	(COLOUR_FACTOR * (abs(r1 - r2) + abs(g1 - g2) + abs(b1 - b2))	\
	 + LIGHT_FACTOR * abs(r1 + g1 + b1 - (r2 + g2 + b2)))

static void allocate_nearest(_THIS, SDL_Color *colors,
			     SDL_Color *want, int nwant)
{
	/*
	 * There is no way to know which ones to choose from, so we retrieve
	 * the entire colormap and try the nearest possible, until we find one
	 * that is shared.
	 */
	XColor all[256];
	int i;
	for(i = 0; i < 256; i++)
		all[i].pixel = i;
	/* 
	 * XQueryColors sets the flags in the XColor struct, so we use
	 * that to keep track of which colours are available
	 */
	XQueryColors(GFX_Display, SDL_XColorMap, all, 256);

	for(i = 0; i < nwant; i++) {
		XColor *c;
		int j;
		int best = 0;
		int mindist = 0x7fffffff;
		int ri = want[i].r;
		int gi = want[i].g;
		int bi = want[i].b;
		for(j = 0; j < 256; j++) {
			int rj, gj, bj, d2;
			if(!all[j].flags)
				continue;	/* unavailable colour cell */
			rj = all[j].red >> 8;
			gj = all[j].green >> 8;
			bj = all[j].blue >> 8;
			d2 = COLOUR_DIST(ri, gi, bi, rj, gj, bj);
			if(d2 < mindist) {
				mindist = d2;
				best = j;
			}
		}
		if(SDL_XPixels[best])
			continue; /* already allocated, waste no more time */
		c = all + best;
		if(XAllocColor(GFX_Display, SDL_XColorMap, c)) {
			/* got it */
			colors[c->pixel].r = c->red >> 8;
			colors[c->pixel].g = c->green >> 8;
			colors[c->pixel].b = c->blue >> 8;
			++SDL_XPixels[c->pixel];
		} else {
			/* 
			 * The colour couldn't be allocated, probably being
			 * owned as a r/w cell by another client. Flag it as
			 * unavailable and try again. The termination of the
			 * loop is guaranteed since at least black and white
			 * are always there.
			 */
			c->flags = 0;
			i--;
		}
	}
}

int X11_SetColors(_THIS, int firstcolor, int ncolors, SDL_Color *colors)
{
	int nrej = 0;

	/* Check to make sure we have a colormap allocated */
	if ( SDL_XPixels == NULL ) {
		return(0);
	}
	if ( (this->screen->flags & SDL_HWPALETTE) == SDL_HWPALETTE ) {
	        /* private writable colormap: just set the colours we need */
	        XColor  *xcmap;
		int i;
	        xcmap = ALLOCA(ncolors*sizeof(*xcmap));
		if(xcmap == NULL)
		        return 0;
		for ( i=0; i<ncolors; ++i ) {
			xcmap[i].pixel = i + firstcolor;
			xcmap[i].red   = (colors[i].r<<8)|colors[i].r;
			xcmap[i].green = (colors[i].g<<8)|colors[i].g;
			xcmap[i].blue  = (colors[i].b<<8)|colors[i].b;
			xcmap[i].flags = (DoRed|DoGreen|DoBlue);
		}
		XStoreColors(GFX_Display, SDL_XColorMap, xcmap, ncolors);
		XSync(GFX_Display, False);
		FREEA(xcmap);
	} else {
	        /*
		 * Shared colormap: We only allocate read-only cells, which
		 * increases the likelyhood of colour sharing with other
		 * clients. The pixel values will almost certainly be
		 * different from the requested ones, so the user has to
		 * walk the colormap and see which index got what colour.
		 *
		 * We can work directly with the logical palette since it
		 * has already been set when we get here.
		 */
		SDL_Color *want, *reject;
	        unsigned long *freelist;
		int i;
		int nfree = 0;
		int nc = this->screen->format->palette->ncolors;
	        colors = this->screen->format->palette->colors;
		freelist = ALLOCA(nc * sizeof(*freelist));
		/* make sure multiple allocations of the same cell are freed */
	        for(i = 0; i < ncolors; i++) {
		        int pixel = firstcolor + i;
		        while(SDL_XPixels[pixel]) {
			        freelist[nfree++] = pixel;
				--SDL_XPixels[pixel];
			}
		}
		XFreeColors(GFX_Display, SDL_XColorMap, freelist, nfree, 0);
		FREEA(freelist);

		want = ALLOCA(ncolors * sizeof(SDL_Color));
		reject = ALLOCA(ncolors * sizeof(SDL_Color));
		memcpy(want, colors + firstcolor, ncolors * sizeof(SDL_Color));
		/* make sure the user isn't fooled by her own wishes
		   (black is safe, always available in the default colormap) */
		memset(colors + firstcolor, 0, ncolors * sizeof(SDL_Color));

		/* now try to allocate the colours */
		for(i = 0; i < ncolors; i++) {
		        XColor col;
			col.red = want[i].r << 8;
			col.green = want[i].g << 8;
			col.blue = want[i].b << 8;
			col.flags = DoRed | DoGreen | DoBlue;
			if(XAllocColor(GFX_Display, SDL_XColorMap, &col)) {
			        /* We got the colour, or at least the nearest
				   the hardware could get. */
			        colors[col.pixel].r = col.red >> 8;
				colors[col.pixel].g = col.green >> 8;
				colors[col.pixel].b = col.blue >> 8;
				++SDL_XPixels[col.pixel];
			} else {
				/*
				 * no more free cells, add it to the list
				 * of rejected colours
				 */
				reject[nrej++] = want[i];
			}
		}
		if(nrej)
			allocate_nearest(this, colors, reject, nrej);
		FREEA(reject);
		FREEA(want);
	}
	return nrej == 0;
}

int X11_SetGammaRamp(_THIS, Uint16 *ramp)
{
	int i, ncolors;
	XColor xcmap[256];

	/* See if actually setting the gamma is supported */
	if ( SDL_Visual->class != DirectColor ) {
	    SDL_SetError("Gamma correction not supported on this visual");
	    return(-1);
	}

	/* Calculate the appropriate palette for the given gamma ramp */
	ncolors = SDL_Visual->map_entries;
	for ( i=0; i<ncolors; ++i ) {
		Uint8 c = (256 * i / ncolors);
		xcmap[i].pixel = SDL_MapRGB(this->screen->format, c, c, c);
		xcmap[i].red   = ramp[0*256+c];
		xcmap[i].green = ramp[1*256+c];
		xcmap[i].blue  = ramp[2*256+c];
		xcmap[i].flags = (DoRed|DoGreen|DoBlue);
	}
	XStoreColors(GFX_Display, SDL_XColorMap, xcmap, ncolors);
	XSync(GFX_Display, False);
	return(0);
}

/* Note:  If we are terminated, this could be called in the middle of
   another SDL video routine -- notably UpdateRects.
*/
void X11_VideoQuit(_THIS)
{
	/* Shutdown everything that's still up */
	/* The event thread should be done, so we can touch SDL_Display */
	if ( SDL_Display != NULL ) {
		/* Flush any delayed updates */
		XSync(GFX_Display, False);

		/* Start shutting down the windows */
		X11_DestroyImage(this, this->screen);
		X11_DestroyWindow(this, this->screen);
		X11_FreeVideoModes(this);
		if ( SDL_XColorMap != SDL_DisplayColormap ) {
			XFreeColormap(SDL_Display, SDL_XColorMap);
		}
		if ( SDL_iconcolors ) {
			unsigned long pixel;
			Colormap dcmap = DefaultColormap(SDL_Display,
							 SDL_Screen);
			for(pixel = 0; pixel < 256; ++pixel) {
				while(SDL_iconcolors[pixel] > 0) {
					XFreeColors(GFX_Display,
						    dcmap, &pixel, 1, 0);
					--SDL_iconcolors[pixel];
				}
			}
			free(SDL_iconcolors);
			SDL_iconcolors = NULL;
		} 
		/* Restore gamma settings if they've changed */
		if ( SDL_GetAppState() & SDL_APPACTIVE ) {
			X11_SwapVidModeGamma(this);
		}

		/* Free that blank cursor */
		if ( SDL_BlankCursor != NULL ) {
			this->FreeWMCursor(this, SDL_BlankCursor);
			SDL_BlankCursor = NULL;
		}

		/* Close the X11 graphics connection */
		if ( GFX_Display != NULL ) {
			XCloseDisplay(GFX_Display);
			GFX_Display = NULL;
		}

		/* Close the X11 display connection */
		XCloseDisplay(SDL_Display);
		SDL_Display = NULL;

		/* Reset the X11 error handlers */
		if ( XIO_handler ) {
			XSetIOErrorHandler(XIO_handler);
		}
		if ( X_handler ) {
			XSetErrorHandler(X_handler);
		}

		/* Unload GL library after X11 shuts down */
		X11_GL_UnloadLibrary(this);
	}
	if ( this->screen && (this->screen->flags & SDL_HWSURFACE) ) {
		/* Direct screen access, no memory buffer */
		this->screen->pixels = NULL;
	}
}

