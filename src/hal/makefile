#

CLINK = -std=gnu99 -nostdlib -mwindows
ALIGN = -Wl,--file-alignment,0x20 -Wl,--section-alignment,0x20 
SHARED = -shared
ENTRYPOINT = -Wl,--entry,_WinMainCRTStartup 
STRIP = -Wl,--strip-all

LD_FLAGS = $(CLINK) $(ALIGN) $(SHARED) $(ENTRYPOINT) $(STRIP)

AR = i386-pc-xbox-ar
AS = i386-pc-xbox-as
CC = i386-pc-xbox-gcc
CXBE = cxbe
CC_FLAGS = -c -g -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-exceptions -mno-cygwin -march=i386
INCLUDE = -I/usr/local/openxdk/i386-pc-xbox/include -I../../include
XBOXKRNL = -L/usr/local/openxdk/i386-pc-xbox/lib -L/usr/local/openxdk/lib -lxboxkrnl

all: libhal.a

.c.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

.s.o:
	$(AS) $< -o $@ 

libhal.a: fileio.o xbox.o pad.o io.o audio.o audioInterrupt.o
	$(AR) rcs libhal.a *.o
	cp libhal.a /usr/local/openxdk/lib
	cp ../../include/hal/*.h /usr/local/openxdk/include/hal

clean: 
	rm -f *.a *.o *.exe *.dll *.xbe *.cxbe


