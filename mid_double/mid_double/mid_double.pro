TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    data.cpp \
    matrix.cpp \
    function.cpp

HEADERS += \
    data.h \
    errors.h \
    matrix.h \
    function.h
