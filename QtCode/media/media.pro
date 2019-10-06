#-------------------------------------------------
#
# Project created by QtCreator 2018-08-25T10:29:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = media
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mazestack.cpp \
    maze.cpp \
    texture.cpp

HEADERS  += mainwindow.h \
    mazestack.h \
    maze.h \
    texture.h

FORMS    += mainwindow.ui

QT += core gui multimedia

RESOURCES += \
    music.qrc

QT += opengl

