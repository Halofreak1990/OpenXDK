#

CLINK = -std=gnu99 -nostdlib -mwindows
ALIGN = -Wl,--file-alignment,0x20 -Wl,--section-alignment,0x20 
SHARED = -shared
ENTRYPOINT = -Wl,--entry,_WinMainCRTStartup 
STRIP = -Wl,--strip-all

IMAGEBASE = -Wl,--image-base,0x00010000
AUTOIMPORT = -Wl,--enable-auto-import 
STACKSIZE = -Wl,--stack,0x100000
LD_FLAGS = $(CLINK) $(ALIGN) $(SHARED) $(ENTRYPOINT) $(STRIP)

AR = ar
CC = gcc
CXBE = cxbe
CC_FLAGS = -c -g -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-exceptions -mno-cygwin -march=i386
INCLUDE = -I/usr/local/openxdk/i386-pc-xbox/include -I../../include
XBOXKRNL = -L/usr/local/openxdk/i386-pc-xbox/lib -L/usr/local/openxdk/lib -lxboxkrnl

all: libhal.a

.c.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

libhal.a: fileio.o xbox.o pad.o
	$(AR) rcs libhal.a *.o
	cp libhal.a /usr/local/openxdk/lib
	cp ../../include/hal/*.h /usr/local/openxdk/include/hal

clean: 
	rm -f *.a *.o *.exe *.dll *.xbe *.cxbe


