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
# PROP Output_Dir "lib"
# PROP Intermediate_Dir "lib"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /G6 /Za /W2 /Zi /O2 /X /I "include\xlibc" /I "include" /u /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_LIBC" /D "__STD_C" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x809 /d "NDEBUG"
# ADD RSC /l 0x809 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
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

SOURCE=.\src\xlibc\string\__stpncpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\bcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\bcopy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\bzero.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\ffs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\index.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memccpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memchr.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memfrob.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memmem.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memmove.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\memset.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\rindex.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\stpcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\stpncpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcasecmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcat.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strchr.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strcspn.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strdup.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strfry.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strlen.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strncase.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strncat.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strncmp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strncpy.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strpbrk.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strrchr.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strsep.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strspn.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strstr.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\strtok.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\swab.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\string\wordcopy.c
# End Source File
# End Group
# Begin Group "stdio"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xlibc\stdio\snprintf.c
# End Source File
# End Group
# Begin Group "math"

# PROP Default_Filter ""
# Begin Group "ieee754"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\__copysign.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\__drem.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\__infnan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\__isinf.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\__isnan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\__logb.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\cabs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\cbrt.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\frexp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\ieee754.h
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\ldexp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\log10.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ieee754\sqrt.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\xlibc\math\__expm1.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\__finite.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\__rint.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\__scalb.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\_fltused.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\acosh.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\asincos.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\asinh.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\atan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\atan2.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\atanh.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\ceil.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\copysign.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\cosh.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\drem.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\exp.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\exp__E.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\expm1.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\fabs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\finite.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\floor.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\fmod.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\infnan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\isinf.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\isnan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\log.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\log1p.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\log__L.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\logb.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\mathimpl.h
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\modf.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\pow.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\rint.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\scalb.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\sincos.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\sinh.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\tan.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\tanh.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\math\trig.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\xlibc\__random.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\abs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\atof.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\atoi.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\bsearch.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\ctype.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\ctype.h
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\ctypes.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\div.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\fileio.c
# End Source File
# Begin Source File

SOURCE=".\src\xlibc\gnu-stabs.h"
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\itoa.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\labs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\ldiv.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\malloc.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\mblen.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\mbstowcs.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\misc_vars.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\qsort.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\rand.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\random.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\sbrk.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\srand.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\strtol.c
# End Source File
# Begin Source File

SOURCE=.\src\xlibc\strtoul.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "bits"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\xlibc\bits\endian.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\bits\types.h
# End Source File
# End Group
# Begin Group "misc"

# PROP Default_Filter ""
# Begin Group "sys No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\xlibc\misc\sys\cdefs.h
# End Source File
# End Group
# End Group
# Begin Group "string No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\xlibc\string\endian.h
# End Source File
# End Group
# Begin Group "sys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\xlibc\sys\cdefs.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\sys\djtypes.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\xlibc\ansidecl.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\ctype.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\defs.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\endian.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\errno.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\errnos.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\features.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\features_old.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\float.h
# End Source File
# Begin Source File

SOURCE=".\include\xlibc\gnu-stabs.h"
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\huge_val.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\limits.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\malloc.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\math.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\memcopy.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\stdarg.h
# End Source File
# Begin Source File

SOURCE=.\include\xlibc\stddef.h
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
