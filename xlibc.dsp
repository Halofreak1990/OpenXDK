# Microsoft Developer Studio Project File - Name="xlibc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=xlibc - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xlibc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xlibc.mak" CFG="xlibc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xlibc - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "lib\xlibc"
# PROP Intermediate_Dir "lib\xlibc"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /G6 /Za /W2 /Ot /Oa /Ow /Og /Oy /Ob1 /X /I "include\xlibc" /I "include" /u /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_LIBC" /D "__STD_C" /FD /QIfist /c
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"lib\xlibc.lib"
# Begin Target

# Name "xlibc - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "String"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xlibc\string\__memccpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memset.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcat.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strlen.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strncat.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strncmp.c
# End Source File
# End Group
# Begin Group "stdio"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xlibc\stdio\conio.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\stdio\file_io.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\stdio\sprintf.c
# End Source File
# End Group
# Begin Group "math"

# PROP Default_Filter ""
# Begin Group "ieee754"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\src\xlibc\math\acos.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\asin.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\atan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ceil.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\exp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\fabs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\floor.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\fmod.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ftol.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\hypot.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\log.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\pow.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\sincos.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\sqrt.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\tan.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\xlibc\abort.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\abs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\div.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\itoa.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\ldiv.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\ltoa.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\malloc.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\misc_vars.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\rand.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "bits"

# PROP Default_Filter ""
# End Group
# Begin Group "misc"

# PROP Default_Filter ""
# Begin Group "sys No. 1"

# PROP Default_Filter ""
# End Group
# End Group
# Begin Group "string No. 1"

# PROP Default_Filter ""
# End Group
# Begin Group "sys"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=.\include\xlibc\ansidecl.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\ctype.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\malloc.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\math.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\stdarg.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\stdio.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\stdlib.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\string.h
# End Source File
# End Group
# End Target
# End Project
