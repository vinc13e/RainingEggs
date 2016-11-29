#include "lifes.h"
#include <QFont>
#include "game.h"

extern Game * game;

Lifes::Lifes(QGraphicsItem *parent): QGraphicsTextItem(parent){
    lifes = 3;

    // draw the text
    setPlainText(QString("Lifes: ") + QString::number(lifes));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Lifes::decrease(){
    lifes--;
    setPlainText(QString("Lifes: ") + QString::number(lifes));
    if(lifes==0) game->over();
}

int Lifes::getLifes(){
    return lifes;
}

void Lifes::setLifes(int value)
{
    lifes = value;
    setPlainText(QString("Lifes: ") + QString::number(lifes));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}
