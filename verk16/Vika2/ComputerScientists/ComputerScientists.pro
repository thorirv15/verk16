QT += core
QT -= gui

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    scientist.cpp \
    scientistservice.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    scientist.h \
    scientistservice.h
