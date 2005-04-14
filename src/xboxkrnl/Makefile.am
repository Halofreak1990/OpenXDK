AM_CFLAGS = -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-exceptions -mno-cygwin -march=i386
AM_LDFLAGS = -Wl,--out-implib=libxboxkrnl.a -Wl,--add-stdcall-alias

INCLUDES = -I../../include

noinst_PROGRAMS = xboxkrnl
xboxkrnl_SOURCES = $(SRCS)
xboxkrnl_LDADD = $(PWD)/$(srcdir)/xboxkrnl.exe.def

SRCS = dbg.c ex.c hal.c io.c kernel.c mm.c nt.c ob.c ps.c rtl.c xbox.c

install-exec-local:
		install libxboxkrnl.a ${prefix}/lib/libxboxkrnl.a

uninstall-local:
		-rm ${prefix}/lib/libxboxkrnl.a

distclean-local:
		-rm libxboxkrnl.a
