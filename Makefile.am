all-local: directories-stamp newlib-stamp sdl-stamp openxdk-stamp freetype-stamp zlib-stamp libpng-stamp jpeg-stamp SDL_image-stamp SDL_ttf-stamp SDL_mixer-stamp
# openxdk-stamp

install-exec-local: newlib-install sdl-install directories-install openxdk-install freetype-install zlib-install libpng-install jpeg-install SDL_image-install SDL_ttf-install SDL_mixer-install
# openxdk-install

AM_CFLAGS="-I$(PWD)/$(top_srcdir)/include"
INCLUDES="-I$(PWD)/$(top_srcdir)/include"

SUBDIRS=include .

DISTCLEANFILES=*~ *.~
 
MAINTAINERCLEANFILES=aclocal.m4 config.guess config.sub configure depcomp install-sh Makefile.in missing INSTALL

#src

#######################
#
#   directories
#

directories-stamp:
	$(INSTALL) -d build
	$(INSTALL) -d build/newlib
	$(INSTALL) -d build/freetype
	$(INSTALL) -d build/zlib
	$(INSTALL) -d build/jpeg
	$(INSTALL) -d build/libpng
	$(INSTALL) -d build/SDL_image
	$(INSTALL) -d build/SDL_ttf
	$(INSTALL) -d build/SDL_mixer
	$(INSTALL) -d build/sdl
	$(INSTALL) -d build/bin
	$(INSTALL) -d build/lib
	$(INSTALL) -d build/include/hal
	$(INSTALL) -d build/include/openxdk
	$(INSTALL) -d build/include/usb
	$(INSTALL) -d build/include/xboxkrnl
	
	ln -fs $(AR) build/bin/$(target)-ar
	ln -fs $(AS) build/bin/$(target)-as
	ln -fs $(LD) build/bin/$(target)-ld
	ln -fs $(NM) build/bin/$(target)-nm
	ln -fs $(GCC) build/bin/$(target)-gcc
	ln -fs $(CXX) build/bin/$(target)-g++
	ln -fs $(RANLIB) build/bin/$(target)-ranlib
	ln -fs $(DLLTOOL) build/bin/$(target)-dlltool
	ln -fs $(WINDRES) build/bin/$(target)-windres
	ln -fs $(STRIP) build/bin/$(target)-strip

	touch $@

directories-install:
	ln -fs $(AR) $(DESTDIR)$(prefix)/bin/$(target)-ar
	ln -fs $(AS) $(DESTDIR)$(prefix)/bin/$(target)-as
	ln -fs $(LD) $(DESTDIR)$(prefix)/bin/$(target)-ld
	ln -fs $(NM) $(DESTDIR)$(prefix)/bin/$(target)-nm
	ln -fs $(GCC) $(DESTDIR)$(prefix)/bin/$(target)-gcc
	ln -fs $(CXX) $(DESTDIR)$(prefix)/bin/$(target)-g++
	ln -fs $(RANLIB) $(DESTDIR)$(prefix)/bin/$(target)-ranlib
	ln -fs $(DLLTOOL) $(DESTDIR)$(prefix)/bin/$(target)-dlltool
	ln -fs $(WINDRES) $(DESTDIR)$(prefix)/bin/$(target)-windres
	ln -fs $(STRIP) $(DESTDIR)$(prefix)/bin/$(target)-strip

#######################
#
#   newlib
#
newlib: newlib-stamp

build/newlib/newlib-1.12.0/Makefile: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/newlib-1.12.0.tar.gz | (cd build/newlib; tar -x) && \
		(cd build/newlib ;patch -p1) < $(top_srcdir)/Patches/newlib-1.12.0.diff && \
		mkdir -p build/newlib/newlib-1.12.0/i386-pc-xbox && \
		cp -a $(top_srcdir)/src/newlib-1.12.0/* build/newlib/newlib-1.12.0/
	cd build/newlib/newlib-1.12.0 && \
		CFLAGS="-I$(PWD)/$(top_srcdir)/include" PATH="$(PWD)/build/bin:$(PATH)" ./configure --host=$(host_alias) --target=$(target) --prefix=$(prefix) --with-newlib --without-headers

newlib-stamp: directories-stamp build/newlib/newlib-1.12.0/Makefile
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/newlib/newlib-1.12.0 all
	touch $@

newlib-install: newlib-stamp
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/newlib/newlib-1.12.0 install

#######################
#
#   sdl
#
sdl: sdl-stamp

build/sdl/SDL-1.2.7/Makefile: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/SDL-1.2.7.tar.gz | (cd build/sdl; tar -x) && \
		(cd build/sdl; patch -p1) < $(top_srcdir)/Patches/SDL-1.2.7.diff && \
		cp -a $(top_srcdir)/src/SDL-1.2.7/* build/sdl/SDL-1.2.7/
	cd build/sdl/SDL-1.2.7 && \
		./autogen.sh && \
		CFLAGS="-I$(PWD)/$(top_srcdir)/include" PATH="$(PWD)/build/bin:$(PATH)" ./configure --host=$(target) --prefix=$(prefix)

sdl-stamp: directories-stamp build/sdl/SDL-1.2.7/Makefile
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/sdl/SDL-1.2.7 all
	touch $@

sdl-install: sdl-stamp
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/sdl/SDL-1.2.7 install

#######################
#
#   openxdk
#
openxdk: openxdk-stamp

openxdk-stamp: directories-stamp
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C src all CFLAGS="-I$(PWD)/$(top_srcdir)/include"
	touch $@

openxdk-install: openxdk-stamp
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C src install

#######################
#
#   freetype
#
freetype: freetype-stamp

build/freetype/freetype-2.1.9/src/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/freetype-2.1.9.tar.gz | (cd build/freetype; tar -x) && \
		(cd build/freetype ;patch -p1) < $(top_srcdir)/Patches/freetype-2.1.9.diff && \
		cp -a $(top_srcdir)/src/freetype-2.1.9/* build/freetype/freetype-2.1.9/

freetype-stamp: directories-stamp build/freetype/freetype-2.1.9/src/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/freetype/freetype-2.1.9/src -f Makefile.xbox all
	touch $@

freetype-install: freetype-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" PREFIX=$(prefix) $(MAKE) -C build/freetype/freetype-2.1.9/src -f Makefile.xbox install

#######################
#
#   zlib
#
zlib: zlib-stamp

build/zlib/zlib-1.2.1/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/zlib-1.2.1.tar.gz | (cd build/zlib; tar -x) && \
		(cd build/zlib ;patch -p1) < $(top_srcdir)/Patches/zlib-1.2.1.diff && \
		cp -a $(top_srcdir)/src/zlib-1.2.1/* build/zlib/zlib-1.2.1/

zlib-stamp: directories-stamp build/zlib/zlib-1.2.1/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/zlib/zlib-1.2.1 -f Makefile.xbox all
	touch $@

zlib-install: zlib-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" PREFIX=$(prefix) $(MAKE) -C build/zlib/zlib-1.2.1 -f Makefile.xbox install

#######################
#
#   jpeg
#
jpeg: jpeg-stamp

build/jpeg/jpeg-6b/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/jpeg-6b.tar.gz | (cd build/jpeg; tar -x) && \
		cp -a $(top_srcdir)/src/jpeg-6b/* build/jpeg/jpeg-6b/

jpeg-stamp: directories-stamp build/jpeg/jpeg-6b/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/jpeg/jpeg-6b -f Makefile.xbox all
	touch $@

jpeg-install: jpeg-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" PREFIX=$(prefix) $(MAKE) -C build/jpeg/jpeg-6b -f Makefile.xbox install

#######################
#
#   libpng
#
libpng: libpng-stamp

build/libpng/libpng-1.2.7/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/libpng-1.2.7.tar.gz | (cd build/libpng; tar -x) && \
		cp -a $(top_srcdir)/src/libpng-1.2.7/* build/libpng/libpng-1.2.7/

libpng-stamp: directories-stamp build/libpng/libpng-1.2.7/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/libpng/libpng-1.2.7 -f Makefile.xbox all
	touch $@

libpng-install: libpng-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" PREFIX=$(prefix) $(MAKE) -C build/libpng/libpng-1.2.7 -f Makefile.xbox install

#######################
#
#   SDL_image
#
SDL_image: SDL_image-stamp

build/SDL_image/SDL_image-1.2.3/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/SDL_image-1.2.3.tar.gz | (cd build/SDL_image; tar -x) && \
		cp -a $(top_srcdir)/src/SDL_image-1.2.3/* build/SDL_image/SDL_image-1.2.3/

SDL_image-stamp: directories-stamp build/SDL_image/SDL_image-1.2.3/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/SDL_image/SDL_image-1.2.3 -f Makefile.xbox all
	touch $@

SDL_image-install: SDL_image-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" PREFIX=$(prefix) $(MAKE) -C build/SDL_image/SDL_image-1.2.3 -f Makefile.xbox install

#######################
#
#   SDL_ttf
#
SDL_ttf: SDL_ttf-stamp

build/SDL_ttf/SDL_ttf-2.0.7/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/SDL_ttf-2.0.7.tar.gz | (cd build/SDL_ttf; tar -x) && \
		cp -a $(top_srcdir)/src/SDL_ttf-2.0.7/* build/SDL_ttf/SDL_ttf-2.0.7/

SDL_ttf-stamp: directories-stamp build/SDL_ttf/SDL_ttf-2.0.7/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/SDL_ttf/SDL_ttf-2.0.7 -f Makefile.xbox all
	touch $@

SDL_ttf-install: SDL_ttf-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" PREFIX=$(prefix) $(MAKE) -C build/SDL_ttf/SDL_ttf-2.0.7 -f Makefile.xbox install

#######################
#
#   SDL_mixer
#
SDL_mixer: SDL_mixer-stamp

build/SDL_mixer/SDL_mixer-1.2.5/Makefile.xbox: directories-stamp
	gunzip -cd $(top_srcdir)/Archive/SDL_mixer-1.2.5.tar.gz | (cd build/SDL_mixer; tar -x) && \
		cp -a $(top_srcdir)/src/SDL_mixer-1.2.5/* build/SDL_mixer/SDL_mixer-1.2.5/

SDL_mixer-stamp: directories-stamp build/SDL_mixer/SDL_mixer-1.2.5/Makefile.xbox
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/SDL_mixer/SDL_mixer-1.2.5 -f Makefile.xbox PREFIX=$(prefix) all
	touch $@

SDL_mixer-install: SDL_mixer-stamp
	mkdir -p $(prefix)/lib
	PATH="$(PWD)/build/bin:$(PATH)" $(MAKE) -C build/SDL_mixer/SDL_mixer-1.2.5 -f Makefile.xbox PREFIX=$(prefix) install

#######################
#
#   cleanup
#

clean-local:
	-rm -rf build
	-rm sdl-stamp openxdk-stamp newlib-stamp directories-stamp
	-rm freetype-stamp zlib-stamp libpng-stamp jpeg-stamp SDL_image-stamp SDL_ttf-stamp SDL_mixer-stamp
	-$(MAKE) -C src clean
	-rmdir include src/* src

distclean-local:
	-$(MAKE) -C src distclean
	-rm -rf include/Makefile.in
	-rm -rf src/Makefile.in
	-rm -rf src/cxbe/Makefile.in
	-rm -rf src/hal/Makefile.in
	-rm -rf src/openxdk/Makefile.in
	-rm -rf src/usb/Makefile.in
	-rm -rf src/xboxkrnl/Makefile.in
