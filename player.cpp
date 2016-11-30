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


void Player::focusOutEvent(QFocusEvent* event){
    //To fix focus losses caused by mouse events
    this->setFocus();
}


void Player::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "my player knows you press a key . . .";

    switch(event->key())
    {
    case Qt::Key_Left:
    {
        if(!game->isRunning() || game->isPaused()) break;
        if(pos().x() > 0){
            setPos(x()-10, y());
        }
        break;
    }
    case Qt::Key_Right:
    {
        if(!game->isRunning() || game->isPaused()) break;
        if(pos().x() + 100 + 20 < 800){
            setPos(x()+10, y());
        }
        break;
    }
    case Qt::Key_Return :
    case Qt::Key_Enter :
    {
        if(game->isRunning()) break;
        game->start();
        break;
    }

    case Qt::Key_Space :
    case Qt::Key_P :
    {
        game->pauseResume();
        break;
    }

    case Qt::Key_Q :
    case Qt::Key_Escape :
    {
        qApp->quit();
        break;
    }
    default:
    {
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
