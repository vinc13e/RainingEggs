/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOverrideCursor(Qt::BlankCursor);
    game = new Game();
    game->show();

    return a.exec();
}

