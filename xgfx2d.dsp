# Microsoft Developer Studio Project File - Name="xgfx2d" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=xgfx2d - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xgfx2d.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xgfx2d.mak" CFG="xgfx2d - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xgfx2d - Win32 Release" (based on "Win32 (x86) Static Library")
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
# ADD CPP /nologo /G6 /W3 /O2 /Op /X /I "include" /I "include\xlibc" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_XBOX" /FD /QIfist /c
# ADD BASE RSC /l 0x41d /d "NDEBUG"
# ADD RSC /l 0x41d /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Target

# Name "xgfx2d - Win32 Release"
# Begin Group "src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xgfx2d\bitmap.c
# End Source File
# Begin Source File

SOURCE=.\src\xgfx2d\blit.c
# End Source File
# Begin Source File

SOURCE=.\src\xgfx2d\blitters.c
# End Source File
# Begin Source File

SOURCE=.\src\xgfx2d\charmap.c
# End Source File
# Begin Source File

SOURCE=.\src\xgfx2d\drawprim.c
# End Source File
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\xgfx2d\bitmap.h
# End Source File
# Begin Source File

SOURCE=.\include\xgfx2d\blit.h
# End Source File
# Begin Source File

SOURCE=.\include\xgfx2d\blitters.h
# End Source File
# Begin Source File

SOURCE=.\include\xgfx2d\charmap.h
# End Source File
# Begin Source File

SOURCE=.\include\xgfx2d\drawprim.h
# End Source File
# End Group
# End Target
# End Project
