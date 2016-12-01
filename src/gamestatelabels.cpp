/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#include"gamestatelabels.h"
#include <QFont>
#include <QFontDatabase>
#include <QThread>

GameStateLabels::GameStateLabels(QGraphicsItem *parent): QGraphicsTextItem(parent){

    int id = QFontDatabase::addApplicationFont(":/fonts/fonts/Cookies.ttf");
    family = QFontDatabase::applicationFontFamilies(id).at(0);

    beforeGame();
}

void GameStateLabels::beforeGame()
{
    QFont cookies(family, 14);
    setPos(20,60);
    setHtml(before);
    setDefaultTextColor(Qt::blue);
    setFont(cookies);
}


void GameStateLabels::afterGame()
{
    QFont cookies(family, 20);
    setPos(250,250);
    setHtml(after);
    setDefaultTextColor(Qt::red);
    setFont(cookies);
}

void GameStateLabels::blink()
{
    setDefaultTextColor(colors[count++%colors.size()]);
}
