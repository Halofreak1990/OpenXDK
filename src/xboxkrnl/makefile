#
CLINK = -std=gnu99 -nostdlib -mwindows
ALIGN = -Wl,--file-alignment,0x20 -Wl,--section-alignment,0x20 
SHARED = -shared
ENTRYPOINT = -Wl,--entry,_WinMainCRTStartup 
STRIP = -Wl,--strip-all
OUTLIB = -Wl,--out-implib=libxboxkrnl.a
STDCALLALIAS = -Wl,--add-stdcall-alias

LD_FLAGS = $(CLINK) $(ALIGN) $(SHARED) $(ENTRYPOINT) $(STRIP) $(STDCALLALIAS) $(OUTLIB)

AR = i386-pc-xbox-ar
CC = i386-pc-xbox-gcc
CXBE = cxbe
CC_FLAGS = -c -g -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-exceptions -mno-cygwin -march=i386
INCLUDE = -I../../include
XBOXKRNL = 

DEPS = xboxkrnl.exe.def dbg.o ex.o hal.o io.o kernel.o mm.o nt.o ob.o ps.o rtl.o xbox.o

all: xboxkrnl.exe

.c.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

xboxkrnl.exe: $(DEPS)
	$(CC) $(DEPS) -o $@ $< xboxkrnl.exe.def $(LD_FLAGS)
	cp *.a /usr/local/openxdk/lib
	cp ../../include/xboxkrnl/*.h /usr/local/openxdk/include/xboxkrnl

clean: 
	rm -f *.a *.o *.exe *.dll *.xbe *.cxbe


