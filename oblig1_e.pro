#-------------------------------------------------
#
# Project created by QtCreator 2013-09-06T11:14:08
#
#-------------------------------------------------

QT       = core

QT       -= gui

TARGET = oblig1_e
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    lib.cpp
LIBS += -larmadillo -lblas -llapack
