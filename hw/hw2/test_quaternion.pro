QT = testlib core
CONFIG += qt
SOURCES += src/quaternion.cpp
SOURCES += src/test_quaternion.cpp
HEADERS += src/quaternion.h
TARGET = test_quaternion

Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui