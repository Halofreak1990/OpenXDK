all-local: directories-stamp newlib-stamp sdl-stamp openxdk-stamp
# openxdk-stamp

install-exec-local: newlib-install sdl-install directories-install openxdk-install
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
#   cleanup
#

clean-local:
	-rm -rf build
	-rm sdl-stamp openxdk-stamp newlib-stamp directories-stamp
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
