#!/bin/bash
echo OpenXDK - Creating symbolics links...
ln -s /usr/bin/ar /usr/bin/i386-pc-xbox-ar
ln -s /usr/bin/as /usr/bin/i386-pc-xbox-as
ln -s /usr/bin/ld /usr/bin/i386-pc-xbox-ld
ln -s /usr/bin/nm /usr/bin/i386-pc-xbox-nm
ln -s /usr/bin/gcc /usr/bin/i386-pc-xbox-gcc
ln -s /usr/bin/ranlib /usr/bin/i386-pc-xbox-ranlib
ln -s /usr/bin/dlltool /usr/bin/i386-pc-xbox-dlltool
ln -s /usr/bin/windres /usr/bin/i386-pc-xbox-windres

echo OpenXDK - Copying system headers...
mkdir -p /usr/local/openxdk/lib
mkdir -p /usr/local/openxdk/include/hal
mkdir -p /usr/local/openxdk/include/openxdk
mkdir -p /usr/local/openxdk/include/usb
mkdir -p /usr/local/openxdk/include/xboxkrnl
cp ../include/hal/*.h /usr/local/openxdk/include/hal
cp ../include/openxdk/*.h /usr/local/openxdk/include/openxdk
cp ../include/usb/*.h /usr/local/openxdk/include/usb
cp ../include/xboxkrnl/*.h /usr/local/openxdk/include/xboxkrnl

echo OpenXDK - Configuring newlib...
cd newlib-1.12.0
./configure --target=i386-pc-xbox --prefix=/usr/local/openxdk --with-newlib --without-headers
cd ..

echo OpenXDK - Compiling xboxkrnl...
cd xboxkrnl
make
cd ..

echo OpenXDK - Compiling newlib...
cd newlib-1.12.0
make all install
cd ..

echo OpenXDK - Compiling hal...
cd hal
make
cd ..

echo OpenXDK - Compiling openxdk...
cd openxdk
make
cd ..

echo OpenXDK - Compiling usb...
cd usb
make
cd ..

echo OpenXDK - Compiling SDL...
cd SDL-1.2.7
make -f makefile.xbox
cd ..

echo OpenXDK - Finished

