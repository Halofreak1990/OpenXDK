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

all: libopenxdk.a

.c.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

.s.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

libopenxdk.a: debug.o openxdk.o alloca.o
	$(AR) rcs libopenxdk.a *.o
	cp libopenxdk.a /usr/local/openxdk/lib
	cp ../../include/openxdk/*.h /usr/local/openxdk/include/openxdk

clean: 
	rm -f *.a *.o *.exe *.dll *.xbe *.cxbe


