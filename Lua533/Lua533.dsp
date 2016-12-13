# Microsoft Developer Studio Project File - Name="Lua533" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Lua533 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Lua533.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Lua533.mak" CFG="Lua533 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Lua533 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Lua533 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Lua533 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Lua533 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ  /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Lua533 - Win32 Release"
# Name "Lua533 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=".\lua-5.3.3\src\lapi.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lauxlib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lbaselib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lbitlib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lcode.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lcorolib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lctype.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ldblib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ldebug.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ldo.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ldump.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lfunc.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lgc.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\linit.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\liolib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\llex.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lmathlib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lmem.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\loadlib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lobject.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lopcodes.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\loslib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lparser.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lstate.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lstring.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lstrlib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ltable.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ltablib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ltm.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lundump.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lutf8lib.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lvm.c"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lzio.c"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=".\lua-5.3.3\src\lapi.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lauxlib.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lcode.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lctype.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ldebug.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ldo.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lfunc.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lgc.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\llex.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\llimits.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lmem.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lobject.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lopcodes.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lparser.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lprefix.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lstate.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lstring.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ltable.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\ltm.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lua.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lua.hpp"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\luaconf.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lualib.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lundump.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lvm.h"
# End Source File
# Begin Source File

SOURCE=".\lua-5.3.3\src\lzio.h"
# End Source File
# End Group
# Begin Source File

SOURCE=".\lua-5.3.3\src\Makefile"
# End Source File
# End Target
# End Project
