# Microsoft Developer Studio Project File - Name="glibc" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=glibc - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "glibc.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "glibc.mak" CFG="glibc - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "glibc - Win32 Release" (based on "Win32 (x86) Static Library")
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
# PROP Intermediate_Dir "lib\glibc"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /G6 /Za /W3 /Ot /Oa /Ow /Og /Oy /Ob1 /X /I "include\glibc" /I "include" /u /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_LIBC" /D "__STD_C" /FR /FD /c
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

# Name "glibc - Win32 Release"
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "string"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\glibc\string\__memccpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\__stpncpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\bcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\bcopy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\bzero.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\ffs.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\index.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memccpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memchr.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memfrob.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memmem.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memmove.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\memset.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\rindex.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\stpcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\stpncpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strcasecmp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strcat.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strchr.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strcmp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strcpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strcspn.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strdup.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strfry.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strlen.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strncase.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strncat.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strncmp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strncpy.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strpbrk.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strrchr.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strsep.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strspn.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strstr.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\strtok.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\swab.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\string\wordcopy.c
# End Source File
# End Group
# Begin Group "stdio"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\glibc\stdio\conio.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\stdio\file_io.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\stdio\snprintf.c
# End Source File
# End Group
# Begin Group "math"

# PROP Default_Filter ""
# Begin Group "ieee754"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\__copysign.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\__drem.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\__infnan.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\__isinf.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\__isnan.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\__logb.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\cabs.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\cbrt.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\frexp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\ieee754.h
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\ldexp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\log10.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ieee754\sqrt.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\glibc\math\__expm1.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\__finite.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\__rint.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\__scalb.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\_fltused.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\acosh.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\asincos.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\asinh.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\atan.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\atan2.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\atanh.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\ceil.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\copysign.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\cosh.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\drem.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\exp.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\exp__E.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\expm1.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\fabs.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\finite.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\floor.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\fmod.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\infnan.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\isinf.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\isnan.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\log.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\log1p.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\log__L.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\logb.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\mathimpl.h
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\modf.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\pow.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\rint.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\scalb.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\sincos.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\sinh.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\tan.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\tanh.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\math\trig.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\glibc\__random.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\abs.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\atof.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\atoi.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\bsearch.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\ctype.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\ctype.h
# End Source File
# Begin Source File

SOURCE=.\src\glibc\ctypes.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\div.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\fileio.c
# End Source File
# Begin Source File

SOURCE=".\src\glibc\gnu-stabs.h"
# End Source File
# Begin Source File

SOURCE=.\src\glibc\itoa.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\labs.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\ldiv.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\malloc.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\misc_vars.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\qsort.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\rand.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\random.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\sbrk.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\srand.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\strtol.c
# End Source File
# Begin Source File

SOURCE=.\src\glibc\strtoul.c
# End Source File
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "bits"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\glibc\bits\endian.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\bits\types.h
# End Source File
# End Group
# Begin Group "misc"

# PROP Default_Filter ""
# Begin Group "sys No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\glibc\misc\sys\cdefs.h
# End Source File
# End Group
# End Group
# Begin Group "string No. 1"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\glibc\string\endian.h
# End Source File
# End Group
# Begin Group "sys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\glibc\sys\cdefs.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\sys\djtypes.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\glibc\ansidecl.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\conio.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\ctype.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\defs.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\endian.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\errno.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\errnos.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\features.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\features_old.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\float.h
# End Source File
# Begin Source File

SOURCE=".\include\glibc\gnu-stabs.h"
# End Source File
# Begin Source File

SOURCE=.\include\glibc\huge_val.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\limits.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\malloc.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\math.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\memcopy.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\stdarg.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\stddef.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\stdio.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\stdlib.h
# End Source File
# Begin Source File

SOURCE=.\include\glibc\string.h
# End Source File
# End Group
# End Target
# End Project
