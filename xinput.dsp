# Microsoft Developer Studio Project File - Name="xinput" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 60000
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=XINPUT - WIN32 RELEASE
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xinput.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xinput.mak" CFG="XINPUT - WIN32 RELEASE"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xinput - Win32 Release" (based on "Win32 (x86) Static Library")
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
# PROP Intermediate_Dir "lib\xinput"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /G6 /W3 /O2 /I "include" /I "include\xinput" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "_XBOX" /U "NDEBUG" /U "_MBCS" /U "_LIB" /U "_XBOX" /FD /c
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

# Name "xinput - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\src\xinput\hub.cpp
# End Source File
# Begin Source File

SOURCE=.\src\xinput\misc.cpp
# End Source File
# Begin Source File

SOURCE=.\src\xinput\ohci.cpp
# End Source File
# Begin Source File

SOURCE=.\src\xinput\pad.cpp
# End Source File
# Begin Source File

SOURCE=.\src\xinput\xinput.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\include\xinput\hub.h
# End Source File
# Begin Source File

SOURCE=.\include\xinput\misc.h
# End Source File
# Begin Source File

SOURCE=.\include\xinput\ohci.h
# End Source File
# Begin Source File

SOURCE=.\include\xinput\pad.h
# End Source File
# Begin Source File

SOURCE=.\include\xinput\xinput.h
# End Source File
# End Group
# End Target
# End Project
