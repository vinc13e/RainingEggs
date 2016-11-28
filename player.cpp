#include "player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include "egg.h"
#include "game.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){


    setPixmap(QPixmap(":/images/bucket1.gif"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "my player knows you press a key . . .";

    switch(event->key())
    {
    case Qt::Key_Left:
    {
        if(!game->running) break;
        if(pos().x() > 0)
            setPos(x()-10, y());
        break;
    }
    case Qt::Key_Right:
    {
        if(!game->running) break;
        if(pos().x() + 100 + 20 < 800) //100 player width, 20, step, 800 view size
            setPos(x()+10, y());
        break;
    }
        //    case Qt::Key_Up:
        //        setPos(x(), y()-10);
        //        break;

        //    case Qt::Key_Down:
        //        setPos(x(), y()+10);
        //        break;

    case Qt::Key_Space :
    case Qt::Key_P :
    {
        game->pause();
        break;
    }

    case Qt::Key_Q :
    case Qt::Key_Escape :
    {
        qApp->quit();
        break;
    }
    }
}

void Player::spawn()
{
    Egg * egg = new Egg();
    egg->setScale(0.1);
    scene()->addItem(egg);
}
