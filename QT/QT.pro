#-------------------------------------------------
#
# Project created by QtCreator 2022-06-27T17:56:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    levels.cpp \
    gamelevel.cpp

HEADERS  += mainwindow.h \
    levels.h \
    gamelevel.h \
    util.h

RESOURCES += \
    resource/resources.qrc
