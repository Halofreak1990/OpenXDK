# Microsoft Developer Studio Project File - Name="xboxkrnl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=xboxkrnl - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "xboxkrnl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "xboxkrnl.mak" CFG="xboxkrnl - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "xboxkrnl - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
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
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G6 /MT /W3 /O2 /I "include" /I "include\xlibc" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /entry:"EntryDummy" /subsystem:windows /machine:I386 /nodefaultlib /subsystem:native
# SUBTRACT LINK32 /pdb:none
# Begin Target

# Name "xboxkrnl - Win32 Release"
# Begin Group "debug"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\dbg.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\dbg.h
# End Source File
# End Group
# Begin Group "i/o manager"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\io.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\io.h
# End Source File
# End Group
# Begin Group "nt"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\nt.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\nt.h
# End Source File
# End Group
# Begin Group "hal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\hal.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\hal.h
# End Source File
# End Group
# Begin Group "executive"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\ex.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\ex.h
# End Source File
# End Group
# Begin Group "memory manager"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\mm.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\mm.h
# End Source File
# End Group
# Begin Group "object manager"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\ob.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\ob.h
# End Source File
# End Group
# Begin Group "process structure"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\ps.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\ps.h
# End Source File
# End Group
# Begin Group "run-time library"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\rtl.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\rtl.h
# End Source File
# End Group
# Begin Group "xbox"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\xbox.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\xbox.h
# End Source File
# End Group
# Begin Group "kernel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\xboxkrnl\kernel.c
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\kernel.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\xboxkrnl\xboxkrnl.def
# End Source File
# Begin Source File

SOURCE=.\include\xboxkrnl\xboxkrnl.h
# End Source File
# End Target
# End Project
