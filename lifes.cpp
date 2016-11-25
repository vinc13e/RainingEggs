#include "lifes.h"
#include <QFont>

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
    //TODO if 0 game over ....
}

int Lifes::getLifes(){
    return lifes;
}
