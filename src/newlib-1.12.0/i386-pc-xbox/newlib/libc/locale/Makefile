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

srcdir = ../../../.././newlib/libc/locale
top_srcdir = ../../../.././newlib/libc
VPATH = ../../../.././newlib/libc/locale
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

top_builddir = ..

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

INCLUDES = $(NEWLIB_CFLAGS) $(CROSS_CFLAGS) $(TARGET_CFLAGS)

GENERAL_SOURCES = timelocal.h ldpart.h locale.c lnumeric.h lmonetary.h lmessages.h 
#LIB_OBJS = 
LIB_OBJS = 	fix_grouping.$(oext) 	ldpart.$(oext) 	lmessages.$(oext) 	lnumeric.$(oext) 	lmonetary.$(oext) 	nl_langinfo.$(oext) 	timelocal.$(oext)

liblocale_la_LDFLAGS = -Xcompiler -nostdlib

#noinst_LTLIBRARIES = liblocale.la
#liblocale_la_SOURCES = $(GENERAL_SOURCES)
#liblocale_la_LIBADD = $(LIB_OBJS)
#liblocale_la_DEPENDENCIES = $(LIB_OBJS)
#noinst_DATA = objectlist.awk.in
noinst_DATA = 
noinst_LIBRARIES = lib.a
lib_a_SOURCES = $(GENERAL_SOURCES)
lib_a_LIBADD = $(LIB_OBJS)
lib_a_DEPENDENCIES = $(LIB_OBJS)

CHEWOUT_FILES = locale.def

SUFFIXES = .def

CHEW = ../../doc/makedoc -f $(srcdir)/../../doc/doc.str

TARGETDOC = ../tmp.texi

CLEANFILES = $(CHEWOUT_FILES) *.ref
mkinstalldirs = $(SHELL) $(top_srcdir)/../../mkinstalldirs
CONFIG_CLEAN_FILES = 
LIBRARIES =  $(noinst_LIBRARIES)


DEFS =  -DPACKAGE=\"newlib\" -DVERSION=\"1.12.0\"  -I. -I$(srcdir) 
CPPFLAGS = -O2 -g -O2
LIBS = 
lib_a_OBJECTS =  locale.$(OBJEXT)
LTLIBRARIES =  $(noinst_LTLIBRARIES)

#liblocale_la_OBJECTS =  locale.lo
CFLAGS = -O2 -g -O2
COMPILE = $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
LTCOMPILE = $(LIBTOOL) --mode=compile $(CC) $(DEFS) $(INCLUDES) $(AM_CPPFLAGS) $(CPPFLAGS) $(AM_CFLAGS) $(CFLAGS)
CCLD = $(CC)
LINK = $(LIBTOOL) --mode=link $(CCLD) $(AM_CFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
DATA =  $(noinst_DATA)

DIST_COMMON =  Makefile.am Makefile.in


DISTFILES = $(DIST_COMMON) $(SOURCES) $(HEADERS) $(TEXINFOS) $(EXTRA_DIST)

TAR = gtar
GZIP_ENV = --best
SOURCES = $(lib_a_SOURCES) $(liblocale_la_SOURCES)
OBJECTS = $(lib_a_OBJECTS) $(liblocale_la_OBJECTS)

all: all-redirect
.SUFFIXES:
.SUFFIXES: .S .c .def .lo .o .obj .s
$(srcdir)/Makefile.in: # Makefile.am $(top_srcdir)/configure.in $(ACLOCAL_M4) $(srcdir)/../../Makefile.shared
	cd $(top_srcdir) && $(AUTOMAKE) --cygnus locale/Makefile

Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status


mostlyclean-noinstLIBRARIES:

clean-noinstLIBRARIES:
	-test -z "$(noinst_LIBRARIES)" || rm -f $(noinst_LIBRARIES)

distclean-noinstLIBRARIES:

maintainer-clean-noinstLIBRARIES:

.c.o:
	$(COMPILE) -c $<

# FIXME: We should only use cygpath when building on Windows,
# and only if it is available.
.c.obj:
	$(COMPILE) -c `cygpath -w $<`

.s.o:
	$(COMPILE) -c $<

.S.o:
	$(COMPILE) -c $<

mostlyclean-compile:
	-rm -f *.o core *.core
	-rm -f *.$(OBJEXT)

clean-compile:

distclean-compile:
	-rm -f *.tab.c

maintainer-clean-compile:

.c.lo:
	$(LIBTOOL) --mode=compile $(COMPILE) -c $<

.s.lo:
	$(LIBTOOL) --mode=compile $(COMPILE) -c $<

.S.lo:
	$(LIBTOOL) --mode=compile $(COMPILE) -c $<

mostlyclean-libtool:
	-rm -f *.lo

clean-libtool:
	-rm -rf .libs _libs

distclean-libtool:

maintainer-clean-libtool:

lib.a: $(lib_a_OBJECTS) $(lib_a_DEPENDENCIES)
	-rm -f lib.a
	$(AR) cru lib.a $(lib_a_OBJECTS) $(lib_a_LIBADD)
	$(RANLIB) lib.a

mostlyclean-noinstLTLIBRARIES:

clean-noinstLTLIBRARIES:
	-test -z "$(noinst_LTLIBRARIES)" || rm -f $(noinst_LTLIBRARIES)

distclean-noinstLTLIBRARIES:

maintainer-clean-noinstLTLIBRARIES:

liblocale.la: $(liblocale_la_OBJECTS) $(liblocale_la_DEPENDENCIES)
	$(LINK)  $(liblocale_la_LDFLAGS) $(liblocale_la_OBJECTS) $(liblocale_la_LIBADD) $(LIBS)

tags: TAGS

ID: $(HEADERS) $(SOURCES) $(LISP)
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	here=`pwd` && cd $(srcdir) \
	  && mkid -f$$here/ID $$unique $(LISP)

TAGS:  $(HEADERS) $(SOURCES)  $(TAGS_DEPENDENCIES) $(LISP)
	tags=; \
	here=`pwd`; \
	list='$(SOURCES) $(HEADERS)'; \
	unique=`for i in $$list; do echo $$i; done | \
	  awk '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || (cd $(srcdir) && etags $(ETAGS_ARGS) $$tags  $$unique $(LISP) -o $$here/TAGS)

mostlyclean-tags:

clean-tags:

distclean-tags:
	-rm -f TAGS ID

maintainer-clean-tags:

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)

subdir = locale

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

install-data-am:
install-data: install-data-am

install-am: all-am
	@$(MAKE) $(AM_MAKEFLAGS) install-exec-am install-data-am
install: install-am
uninstall-am:
uninstall: uninstall-am
all-am: Makefile $(LIBRARIES) $(LTLIBRARIES) $(DATA)
all-redirect: all-am
install-strip:
	$(MAKE) $(AM_MAKEFLAGS) AM_INSTALL_PROGRAM_FLAGS=-s install
installdirs:


mostlyclean-generic:

clean-generic:
	-test -z "$(CLEANFILES)" || rm -f $(CLEANFILES)

distclean-generic:
	-rm -f Makefile $(CONFIG_CLEAN_FILES)
	-rm -f config.cache config.log stamp-h stamp-h[0-9]*

maintainer-clean-generic:
mostlyclean-am:  mostlyclean-noinstLIBRARIES mostlyclean-compile \
		mostlyclean-libtool mostlyclean-noinstLTLIBRARIES \
		mostlyclean-tags mostlyclean-generic

mostlyclean: mostlyclean-am

clean-am:  clean-noinstLIBRARIES clean-compile clean-libtool \
		clean-noinstLTLIBRARIES clean-tags clean-generic \
		mostlyclean-am

clean: clean-am

distclean-am:  distclean-noinstLIBRARIES distclean-compile \
		distclean-libtool distclean-noinstLTLIBRARIES \
		distclean-tags distclean-generic clean-am
	-rm -f libtool

distclean: distclean-am

maintainer-clean-am:  maintainer-clean-noinstLIBRARIES \
		maintainer-clean-compile maintainer-clean-libtool \
		maintainer-clean-noinstLTLIBRARIES \
		maintainer-clean-tags maintainer-clean-generic \
		distclean-am
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

maintainer-clean: maintainer-clean-am

.PHONY: mostlyclean-noinstLIBRARIES distclean-noinstLIBRARIES \
clean-noinstLIBRARIES maintainer-clean-noinstLIBRARIES \
mostlyclean-compile distclean-compile clean-compile \
maintainer-clean-compile mostlyclean-libtool distclean-libtool \
clean-libtool maintainer-clean-libtool mostlyclean-noinstLTLIBRARIES \
distclean-noinstLTLIBRARIES clean-noinstLTLIBRARIES \
maintainer-clean-noinstLTLIBRARIES tags mostlyclean-tags distclean-tags \
clean-tags maintainer-clean-tags distdir info-am info dvi-am dvi check \
check-am installcheck-am installcheck install-info-am install-info \
install-exec-am install-exec install-data-am install-data install-am \
install uninstall-am uninstall all-redirect all-am all installdirs \
mostlyclean-generic distclean-generic clean-generic \
maintainer-clean-generic clean mostlyclean distclean maintainer-clean


objectlist.awk.in: $(noinst_LTLIBRARIES)
	-rm -f objectlist.awk.in
	for i in `ls *.lo` ; \
	do \
	  echo $$i `pwd`/$$i >> objectlist.awk.in ; \
	done

.c.def:
	$(CHEW) < $< > $*.def 2> $*.ref
	touch stmp-def

doc: $(CHEWOUT_FILES)
	cat $(srcdir)/locale.tex >> $(TARGETDOC)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
