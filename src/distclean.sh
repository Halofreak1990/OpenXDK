#!/bin/bash
echo OpenXDK - Cleaning xboxkrnl...
cd xboxkrnl
make clean
cd ..

echo OpenXDK - Cleaning newlib...
cd newlib-1.12.0
# for some reason, we need to do this twice to complete clean up
make distclean
make distclean
cd ..

echo OpenXDK - Cleaning hal...
cd hal
make clean
cd ..

echo OpenXDK - Cleaning openxdk...
cd openxdk
make clean
cd ..

echo OpenXDK - Cleaning usb...
cd usb
make clean
cd ..

echo OpenXDK - Cleaning SDL...
cd SDL-1.2.7
make -f makefile.xbox clean
cd ..

echo OpenXDK - Finished

