QT += core
QT -= gui

CONFIG += c++11

TARGET = ComputerScientists
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    performerservice.cpp \
    dataaccess.cpp

HEADERS += \
    consoleui.h \
    performerservice.h \
    dataaccess.h
