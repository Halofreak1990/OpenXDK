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
