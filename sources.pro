#-------------------------------------------------
#
# Project created by QtCreator 2015-09-03T11:18:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sources
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        typeBorne.cpp\
        station.cpp\
        technicien.cpp\
        visite.cpp


HEADERS  += mainwindow.h\
    typeBorne.h\
    visite.h\
    technicien.h\
    station.h

FORMS    += mainwindow.ui
