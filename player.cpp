#include "player.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QApplication>
#include "bullet.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "my player knows you press a key . . .";

    switch(event->key())
    {
    case Qt::Key_Left:
    {
        if(pos().x() > 10)
            setPos(x()-10, y());
        break;
    }
    case Qt::Key_Right:
    {
        if(pos().x() + 100 + 10 < 800) //100 player width, 10, step, 800 view size
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
    {
        // TODO pause
//        setPos(x(),y());
//        Bullet * bullet = new Bullet();
//        bullet->setPos(20, 0);
//        scene()->addItem(bullet);
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
    Bullet * bullet = new Bullet();
    scene()->addItem(bullet);
}
