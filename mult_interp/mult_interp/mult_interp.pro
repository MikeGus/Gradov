TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    functions.cpp \
    io.cpp \
    data_table.cpp \
    spline.cpp

HEADERS += \
    functions.h \
    utils.h \
    errors.h \
    io.h \
    data_table.h \
    spline.h
