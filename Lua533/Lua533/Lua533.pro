#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T11:20:24
#
#-------------------------------------------------

QT       -= gui

TARGET = Lua533
TEMPLATE = lib
CONFIG += staticlib

SOURCES += lua533.cpp \
    ../lua-5.3.3/src/lapi.c \
    ../lua-5.3.3/src/lauxlib.c \
    ../lua-5.3.3/src/lbaselib.c \
    ../lua-5.3.3/src/lbitlib.c \
    ../lua-5.3.3/src/lcode.c \
    ../lua-5.3.3/src/lcorolib.c \
    ../lua-5.3.3/src/lctype.c \
    ../lua-5.3.3/src/ldblib.c \
    ../lua-5.3.3/src/ldebug.c \
    ../lua-5.3.3/src/ldo.c \
    ../lua-5.3.3/src/ldump.c \
    ../lua-5.3.3/src/lfunc.c \
    ../lua-5.3.3/src/lgc.c \
    ../lua-5.3.3/src/linit.c \
    ../lua-5.3.3/src/liolib.c \
    ../lua-5.3.3/src/llex.c \
    ../lua-5.3.3/src/lmathlib.c \
    ../lua-5.3.3/src/lmem.c \
    ../lua-5.3.3/src/loadlib.c \
    ../lua-5.3.3/src/lobject.c \
    ../lua-5.3.3/src/lopcodes.c \
    ../lua-5.3.3/src/loslib.c \
    ../lua-5.3.3/src/lparser.c \
    ../lua-5.3.3/src/lstate.c \
    ../lua-5.3.3/src/lstring.c \
    ../lua-5.3.3/src/lstrlib.c \
    ../lua-5.3.3/src/ltable.c \
    ../lua-5.3.3/src/ltablib.c \
    ../lua-5.3.3/src/ltm.c \
    ../lua-5.3.3/src/lundump.c \
    ../lua-5.3.3/src/lutf8lib.c \
    ../lua-5.3.3/src/lvm.c \
    ../lua-5.3.3/src/lzio.c

HEADERS += lua533.h \
    ../lua-5.3.3/src/lapi.h \
    ../lua-5.3.3/src/lauxlib.h \
    ../lua-5.3.3/src/lcode.h \
    ../lua-5.3.3/src/lctype.h \
    ../lua-5.3.3/src/ldebug.h \
    ../lua-5.3.3/src/ldo.h \
    ../lua-5.3.3/src/lfunc.h \
    ../lua-5.3.3/src/lgc.h \
    ../lua-5.3.3/src/llex.h \
    ../lua-5.3.3/src/llimits.h \
    ../lua-5.3.3/src/lmem.h \
    ../lua-5.3.3/src/lobject.h \
    ../lua-5.3.3/src/lopcodes.h \
    ../lua-5.3.3/src/lparser.h \
    ../lua-5.3.3/src/lprefix.h \
    ../lua-5.3.3/src/lstate.h \
    ../lua-5.3.3/src/lstring.h \
    ../lua-5.3.3/src/ltable.h \
    ../lua-5.3.3/src/ltm.h \
    ../lua-5.3.3/src/lua.h \
    ../lua-5.3.3/src/lua.hpp \
    ../lua-5.3.3/src/luaconf.h \
    ../lua-5.3.3/src/lualib.h \
    ../lua-5.3.3/src/lundump.h \
    ../lua-5.3.3/src/lvm.h \
    ../lua-5.3.3/src/lzio.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    ../lua-5.3.3/src/Makefile
