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
    gamelevel.cpp \
    mybutton.cpp \
    enemy.cpp \
    enemy1.cpp \
    enemy2.cpp \
    enemy3.cpp \
    enemy4.cpp

HEADERS  += mainwindow.h \
    levels.h \
    gamelevel.h \
    util.h \
    mybutton.h \
    enemy.h \
    enemy1.h \
    enemy2.h \
    windialog.h \
    enemy3.h \
    enemy4.h

RESOURCES += \
    resource/resources.qrc
