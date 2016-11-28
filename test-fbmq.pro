#-------------------------------------------------
#
# Project created by QtCreator 2016-11-25T12:23:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test-fbmq
TEMPLATE = app


SOURCES += main.cpp \
    player.cpp \
    game.cpp \
    score.cpp \
    lifes.cpp \
    egg.cpp

HEADERS  += \
    player.h \
    game.h \
    score.h \
    lifes.h \
    egg.h

FORMS    +=

CONFIG += c++11

RESOURCES += \
    resources.qrc
