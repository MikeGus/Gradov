TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    spline.cpp \
    io.cpp \
    func.cpp

HEADERS += \
    spline.h \
    io.h \
    errors.h \
    func.h
