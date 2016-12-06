QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    dataaccess.cpp \
    scientist.cpp \
    service.cpp \
    computer.cpp

HEADERS += \
    consoleui.h \
    dataaccess.h \
    scientist.h \
    service.h \
    computer.h
