#!/bin/bash

# if you are using a cross compiler (ie. on Linux), you
# will most likely need to set your gccPrefix and gccPathPrefix
# variables so something like (depending on what cross-compiler
# you are using and where you installed it):
#   gccPrefix="i586-mingw32msvc-"
#   gccPathPrefix="/opt/cross-tools/bin"
# The default values should work for Cygwin on Win32

gccPrefix=""
gccPathPrefix="/usr/bin"
installDir="/usr/local/openxdk"

echo Setting execute permissions
chmod +x *.sh
chmod +x */configure
 
echo OpenXDK - Creating symbolic links...
for x in ar as ld nm gcc ranlib dlltool windres; do
	ln -s $gccPathPrefix/$gccPrefix$x $gccPathPrefix/i386-pc-xbox-$x
done

echo OpenXDK - Installing CXBE...
mkdir -p $installDir/bin
cd cxbe
make
cp cxbe.exe $installDir/bin
cd ..

echo OpenXDK - Copying system headers...
mkdir -p $installDir/lib
mkdir -p $installDir/include/hal
mkdir -p $installDir/include/openxdk
mkdir -p $installDir/include/usb
mkdir -p $installDir/include/xboxkrnl
cp ../include/hal/*.h $installDir/include/hal
cp ../include/openxdk/*.h $installDir/include/openxdk
cp ../include/usb/*.h $installDir/include/usb
cp ../include/xboxkrnl/*.h $installDir/include/xboxkrnl

echo OpenXDK - Configuring newlib...
cd newlib-1.12.0
./configure --target=i386-pc-xbox --prefix=$installDir --with-newlib --without-headers
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
make -f Makefile.xbox
cd ..

echo OpenXDK - Finished

