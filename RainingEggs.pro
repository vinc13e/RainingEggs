#-------------------------------------------------
#
# Project created by QtCreator 2016-11-25T12:23:28
#
#-------------------------------------------------

QT       += core gui \
    multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RainingEggs
TEMPLATE = app


SOURCES += src/main.cpp \
    src/player.cpp \
    src/game.cpp \
    src/score.cpp \
    src/lifes.cpp \
    src/egg.cpp \
    src/gamestatelabels.cpp

HEADERS  += \
    src/player.h \
    src/game.h \
    src/score.h \
    src/lifes.h \
    src/egg.h \
    src/gamestatelabels.h

FORMS    +=

CONFIG += c++11

RESOURCES += \
    resources/resources.qrc
