#

CLINK = -std=gnu99 -nostdlib -mwindows
ALIGN = -Wl,--file-alignment,0x20 -Wl,--section-alignment,0x20 
SHARED = -shared
ENTRYPOINT = -Wl,--entry,_WinMainCRTStartup 
STRIP = -Wl,--strip-all

LD_FLAGS = $(CLINK) $(ALIGN) $(SHARED) $(ENTRYPOINT) $(STRIP)

AR = i386-pc-xbox-ar
CC = i386-pc-xbox-gcc
CXBE = cxbe
CC_FLAGS = -c -g -std=gnu99 -ffreestanding -nostdlib -fno-builtin -fno-exceptions -mno-cygwin -march=i386
INCLUDE = -I/usr/local/openxdk/i386-pc-xbox/include -I../../include
XBOXKRNL = -L/usr/local/openxdk/i386-pc-xbox/lib -L/usr/local/openxdk/lib -lxboxkrnl

all: libusb.a

.c.o:
	$(CC) -c $< $(CC_FLAGS) $(INCLUDE)

libusb.a: hub.o ohci.o bulk.o
	$(AR) rcs libusb.a *.o
	cp libusb.a /usr/local/openxdk/lib
	cp ../../include/usb/*.h /usr/local/openxdk/include/usb

clean: 
	rm -f *.a *.o *.exe *.dll *.xbe *.cxbe


