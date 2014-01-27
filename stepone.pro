TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp \
    tuple.cpp \
    fastparser.cpp \
    basenumfunc.cpp \
    basefunc.cpp \
    basemacro.cpp \
    typepredicates.cpp \
    core.cpp

HEADERS += \
    typestemp.h \
    tuple.h \
    numfunctemp.h \
    fastparser.h \
    basenumfunc.h \
    basefunc.h \
    basemacro.h \
    integers.h \
    floats.h \
    numbers.h \
    typepredicates.h \
    dbg.h \
    core.h \
    stepone.h

