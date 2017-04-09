TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += Wall
CONFIG += Werror

SOURCES += main.cpp \
    functions.cpp

HEADERS += \
    functions.h \
    utils.h
