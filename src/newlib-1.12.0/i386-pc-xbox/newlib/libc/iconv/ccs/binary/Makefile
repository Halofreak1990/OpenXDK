# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake 1.4-p6 from Makefile.am

# Copyright (C) 1994, 1995-8, 1999, 2001 Free Software Foundation, Inc.
# This Makefile.in is free software; the Free Software Foundation
# gives unlimited permission to copy and/or distribute it,
# with or without modifications, as long as this notice is preserved.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY, to the extent permitted by law; without
# even the implied warranty of MERCHANTABILITY or FITNESS FOR A
# PARTICULAR PURPOSE.



SHELL = /bin/sh

srcdir = ../../../../../.././newlib/libc/iconv/ccs/binary
top_srcdir = ../../../../../.././newlib/libc
VPATH = ../../../../../.././newlib/libc/iconv/ccs/binary
prefix = /usr/local/openxdk
exec_prefix = ${prefix}

bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${prefix}/info
mandir = ${prefix}/man
includedir = ${prefix}/include
oldincludedir = /usr/include

DESTDIR =

pkgdatadir = $(datadir)/newlib
pkglibdir = $(libdir)/newlib
pkgincludedir = $(includedir)/newlib

top_builddir = ../../..

ACLOCAL = aclocal-1.4
AUTOCONF = autoconf
AUTOMAKE = automake-1.4
AUTOHEADER = autoheader

INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL} $(AM_INSTALL_PROGRAM_FLAGS)
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL_PROGRAM}
transform = s,^,i386-pc-xbox-,;

NORMAL_INSTALL = :
PRE_INSTALL = :
POST_INSTALL = :
NORMAL_UNINSTALL = :
PRE_UNINSTALL = :
POST_UNINSTALL = :
build_alias = i686-pc-cygwin
build_triplet = i686-pc-cygwin
host_alias = i386-pc-xbox
host_triplet = i386-pc-xbox
target_alias = i386-pc-xbox
target_triplet = i386-pc-xbox
AR = i386-pc-xbox-ar
AS = i386-pc-xbox-as
CC = i386-pc-xbox-gcc -B/cygdrive/c/source/workspaceEclipse/OpenXDK/src/newlib-1.12.0/i386-pc-xbox/newlib/ -isystem /cygdrive/c/source/workspaceEclipse/OpenXDK/src/newlib-1.12.0/i386-pc-xbox/newlib/targ-include -isystem /cygdrive/c/source/workspaceEclipse/OpenXDK/src/newlib-1.12.0/newlib/libc/include
CPP = @CPP@
CRT0 = crt0.o
CXX = @CXX@
CXXCPP = @CXXCPP@
DLLTOOL = i386-pc-xbox-dlltool
EXEEXT = 
GCJ = @GCJ@
GCJFLAGS = @GCJFLAGS@
LDFLAGS = 
LIBC_EXTRA_DEF = 
LIBC_EXTRA_LIB = 
LIBC_MACHINE_LIB = machine/lib.a
LIBC_POSIX_LIB = 
LIBC_SIGNAL_DEF = signal/stmp-def
LIBC_SIGNAL_LIB = signal/lib.a
LIBC_STDIO64_DEF = 
LIBC_STDIO64_LIB = 
LIBC_SYSCALL_LIB = 
LIBC_SYS_LIB = sys/lib.a
LIBC_UNIX_LIB = 
LIBTOOL = 
LN_S = 
MAINT = #
MAKEINFO = makeinfo
NEWLIB_CFLAGS =  -O2 -D_COMPILING_NEWLIB -mno-cygwin -DMISSING_SYSCALL_NAMES -fno-builtin
OBJDUMP = 
OBJEXT = o
PACKAGE = newlib
RANLIB = i386-pc-xbox-ranlib
STRIP = 
VERSION = 1.12.0
aext = a
extra_dir = 
libm_machine_dir = i386
machine_dir = i386
newlib_basedir = ../../.././newlib/libc/..
oext = o
sys_dir = xbox

AUTOMAKE_OPTIONS = cygnus

cctdir = $(datadir)/iconv_data

cct_DATA = big5.cct cns11643_plane1.cct cns11643_plane14.cct cns11643_plane2.cct cp775.cct cp850.cct cp852.cct cp855.cct cp866.cct gb_2312_80.cct iso_8859_1.cct iso_8859_15.cct iso_8859_2.cct iso_8859_4.cct iso_8859_5.cct jis_x0201.cct jis_x0208_1983.cct jis_x0212_1990.cct koi8_r.cct koi8_u.cct ksx1001.cct shift_jis.cct us_ascii.cct

mkinstalldirs = $(SHELL) $(top_srcdir)/../../mkinstalldirs
CONFIG_CLEAN_FILES = 
DATA =  $(cct_DATA)

DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = gtar
GZIP_ENV = --best
all: all-redirect
.SUFFIXES:
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) $(srcdir)/../../../../Makefile.shared
	cd $(top_srcdir) && $(AUTOMAKE) --cygnus iconv/ccs/binary/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


install-cctDATA: $(cct_DATA)
	@$(NORMAL_INSTALL)
	$(mkinstalldirs) $(DESTDIR)$(cctdir)
	@list='$(cct_DATA)'; for p in $$list; do \
	  if test -f $(srcdir)/$$p; then \
	    echo " $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(cctdir)/$$p"; \
	    $(INSTALL_DATA) $(srcdir)/$$p $(DESTDIR)$(cctdir)/$$p; \
	  else if test -f $$p; then \
	    echo " $(INSTALL_DATA) $$p $(DESTDIR)$(cctdir)/$$p"; \
	    $(INSTALL_DATA) $$p $(DESTDIR)$(cctdir)/$$p; \
	  fi; fi; \
	done

uninstall-cctDATA:
	@$(NORMAL_UNINSTALL)
	list='$(cct_DATA)'; for p in $$list; do \
	  rm -f $(DESTDIR)$(cctdir)/$$p; \
	done
tags: TAGS
TAGS:


distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = iconv/ccs/binary

distdir: $(DISTFILES)
	@for file in $(DISTFILES); do \
	  if test -f $$file; then d=.; else d=$(srcdir); fi; \
	  if test -d $$d/$$file; then \
	    cp -pr $$d/$$file $(distdir)/$$file; \
	  else \
	    test -f $(distdir)/$$file \
	    || ln $$d/$$file $(distdir)/$$file 2> /dev/null \
	    || cp -p $$d/$$file $(distdir)/$$file || :; \
	  fi; \
	done
info-am:
info: info-am
dvi-am:
dvi: dvi-am
check-am:
check: check-am
installcheck-am:
installcheck: installcheck-am
install-info-am: 
install-info: install-info-am
install-exec-am:
install-exec: install-exec-am

install-data-am: install-cctDATA
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am: uninstall-cctDATA
uninstall: uninstall-am
all-am: Makefile $(DATA)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:
	$(mkinstalldirs)  $(DESTDIR)$(cctdir)


mostlyclean-generic:

clean-generic:

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-generic mostlyclean-am

clean: clean-am

distclean-am:  distclean-generic clean-am
	-rm -f libtool

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-generic distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: uninstall-cctDATA install-cctDATA tags distdir info-am info \
dvi-am dvi check check-am installcheck-am installcheck install-info-am \
install-info install-exec-am install-exec install-data-am install-data \
install-am install uninstall-am uninstall all-redirect all-am all \
installdirs mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


objectlist.awk.in: $(noinst_LTLIBRARIES)
	-rm -f objectlist.awk.in
	for i in `ls *.lo` ; \
	do \
	  echo $$i `pwd`/$$i >> objectlist.awk.in ; \
	done

info:

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
