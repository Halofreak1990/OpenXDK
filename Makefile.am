all: .directories .newlib .sdl .openxdk

#######################
#
#   directories
#

.directories:
	$(INSTALL) -d $(prefix)/bin
	$(INSTALL) -d $(prefix)/lib
	$(INSTALL) -d $(prefix)/include/hal
	$(INSTALL) -d $(prefix)/include/openxdk
	$(INSTALL) -d $(prefix)/include/usb
	$(INSTALL) -d $(prefix)/include/xboxkrnl
	
	cp $(top_srcdir)/include/hal/*.h $(prefix)/include/hal
	cp $(top_srcdir)/include/openxdk/*.h $(prefix)/include/openxdk
	cp $(top_srcdir)/include/usb/*.h $(prefix)/include/usb
	cp $(top_srcdir)/include/xboxkrnl/*.h $(prefix)/include/xboxkrnl

	ln -fs $(AR) $(prefix)/bin/$(target)-ar
	ln -fs $(AS) $(prefix)/bin/$(target)-as
	ln -fs $(LD) $(prefix)/bin/$(target)-ld
	ln -fs $(NM) $(prefix)/bin/$(target)-nm
	ln -fs $(GCC) $(prefix)/bin/$(target)-gcc
	ln -fs $(RANLIB) $(prefix)/bin/$(target)-ranlib
	ln -fs $(DLLTOOL) $(prefix)/bin/$(target)-dlltool
	ln -fs $(WINDRES) $(prefix)/bin/$(target)-windres
	ln -fs $(STRIP) $(prefix)/bin/$(target)-strip
	
	touch $@

#######################
#
#   newlib
#

$(top_srcdir)/src/newlib-1.12.0/Makefile:
	cd $(top_srcdir)/src && gunzip -cd ../Archive/newlib-1.12.0.tar.gz | tar -x && \
		patch -p1 < ../Patches/newlib-1.12.0.diff
	cd $(top_srcdir)/src/newlib-1.12.0 && \
		./configure --host=$(host_alias) --target=$(target) --prefix=$(prefix) --with-newlib --without-headers

.newlib: .directories $(top_srcdir)/src/newlib-1.12.0/Makefile
	$(MAKE) -C $(top_srcdir)/src/newlib-1.12.0 all install
	touch $@

#######################
#
#   sdl
#

$(top_srcdir)/src/SDL-1.2.7/Makefile:
	cd $(top_srcdir)/src && gunzip -cd ../Archive/SDL-1.2.7.tar.gz | tar -x && \
		patch -p1 < ../Patches/SDL-1.2.7.diff
	cd $(top_srcdir)/src/SDL-1.2.7 && \
		./autogen.sh && \
		./configure --host=$(target) --prefix=$(prefix)

.sdl: .directories $(top_srcdir)/src/SDL-1.2.7/Makefile
	$(MAKE) -C $(top_srcdir)/src/SDL-1.2.7 all install-strip
	touch $@

#######################
#
#   openxdk
#

.openxdk: .directories
	$(MAKE) -C $(top_srcdir)/src all install-strip
	touch $@

#######################
#
#   cleanup
#

distclean-local:
	-$(MAKE) -C $(top_srcdir)/src/newlib-1.12.0 distclean
	-$(MAKE) -C $(top_srcdir)/src/SDL-1.2.7 distclean
	-$(MAKE) -C $(top_srcdir)/src distclean
	rm -rf $(top_srcdir)/autom4te.cache
	rm -rf $(top_srcdir)/src/newlib-1.12.0/config
	rm -rf $(top_srcdir)/src/newlib-1.12.0/contrib
	rm -rf $(top_srcdir)/src/newlib-1.12.0/etc
	rm -rf $(top_srcdir)/src/newlib-1.12.0/i386-pc-xbox
	rm -rf $(top_srcdir)/src/newlib-1.12.0/libgloss
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/doc
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/iconvdata
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/argz
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/ctype
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/errno
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/iconv
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/include
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/locale
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/machine
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/misc
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/posix
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/reent
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/search
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/signal
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/stdio
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/stdio64
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/stdlib
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/string
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/a29khif
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/arc
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/arm
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/d10v
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/decstation
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/h8300hms
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/h8500hms
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/linux
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/m88kbug
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/mmixware
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/netware
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/rtems
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sh
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sparc64
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sun4
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sysmec
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sysnec810
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sysnecv850
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sysvi386
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/sysvnecv70
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/tic80
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/w65
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/z8ksim
	find $(top_srcdir)/src/newlib-1.12.0/newlib/libc/sys/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/syscalls
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/time
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libc/unix
	find $(top_srcdir)/src/newlib-1.12.0/newlib/libc/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/libm
	rm -rf $(top_srcdir)/src/newlib-1.12.0/newlib/testsuite
	find $(top_srcdir)/src/newlib-1.12.0/newlib/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/newlib-1.12.0/texinfo
	rm -f $(top_srcdir)/src/newlib-1.12.0/.cvsignore
	find $(top_srcdir)/src/newlib-1.12.0/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/SDL-1.2.7/autom4te.cache
	rm -rf $(top_srcdir)/src/SDL-1.2.7/docs
	rm -rf $(top_srcdir)/src/SDL-1.2.7/include
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/alsa
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/arts
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/baudio
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/dc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/disk
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/dma
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/dmedia
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/dsp
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/esd
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/macrom
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/mint
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/mme
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/nas
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/nto
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/openbsd
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/paudio
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/riscos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/sun
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/ums
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/windib
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/audio/windx5
	find $(top_srcdir)/src/SDL-1.2.7/src/audio/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/cdrom
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/cpuinfo
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/endian
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/events
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/file
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/hermes
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/amigaos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/beos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/bsd
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/darwin
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/dc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/dummy
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/linux
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/macos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/mint
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/riscos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/joystick/win32
	find $(top_srcdir)/src/SDL-1.2.7/src/joystick/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/main
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/amigaos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/beos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/bsdi
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/dc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/epoc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/generic
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/irix
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/linux
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/pth
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/thread/win32
	find $(top_srcdir)/src/SDL-1.2.7/src/thread/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/amigaos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/beos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/dc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/epoc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/linux
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/macos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/mint
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/riscos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/timer/win32
	find $(top_srcdir)/src/SDL-1.2.7/src/timer/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/aalib
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/ataricommon
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/bwindow
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/cybergfx
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/dc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/dga
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/directfb
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/dummy
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/epoc
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/fbcon
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/gem
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/ggi
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/maccommon
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/macdsp
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/macrom
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/nanox
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/photon
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/picogui
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/ps2gs
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/qtopia
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/quartz
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/riscos
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/svga
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/vgl
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/wincommon
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/windib
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/windx5
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/x11
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/xbios
	rm -rf $(top_srcdir)/src/SDL-1.2.7/src/video/XFree86
	find $(top_srcdir)/src/SDL-1.2.7/src/video/* -type f -maxdepth 0 | xargs rm -f 
	find $(top_srcdir)/src/SDL-1.2.7/src/* -type f -maxdepth 0 | xargs rm -f 
	rm -rf $(top_srcdir)/src/SDL-1.2.7/test
	find $(top_srcdir)/src/SDL-1.2.7/* -type f -maxdepth 0 | xargs rm -f 
	rm -f $(top_srcdir)/src/SDL-1.2.7/src/audio/xbox/Makefile.in
	rm -f $(top_srcdir)/src/SDL-1.2.7/src/joystick/xbox/Makefile.in
	rm -f $(top_srcdir)/src/SDL-1.2.7/src/video/xbox/Makefile.in
	rm -f $(top_srcdir)/src/cxbe/Makefile.in
	rm -f $(top_srcdir)/src/hal/Makefile.in
	rm -f $(top_srcdir)/src/openxdk/Makefile.in
	rm -f $(top_srcdir)/src/usb/Makefile.in
	rm -f $(top_srcdir)/src/xboxkrnl/Makefile.in
	rm -f $(top_srcdir)/src/Makefile.in
	rm -f $(top_srcdir)/Makefile.in
	rm -f $(top_srcdir)/.directories
	rm -f $(top_srcdir)/.newlib
	rm -f $(top_srcdir)/.openxdk
	rm -f $(top_srcdir)/.sdl
	rm -f $(top_srcdir)/aclocal.m4
	rm -f $(top_srcdir)/config.guess
	rm -f $(top_srcdir)/config.sub
	rm -f $(top_srcdir)/configure
	rm -f $(top_srcdir)/depcomp
	rm -f $(top_srcdir)/INSTALL
	rm -f $(top_srcdir)/install-sh
	rm -f $(top_srcdir)/missing
	rm -f $(top_srcdir)/mkinstalldirs
