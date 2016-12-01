#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>
#include <typeinfo>
#include "egg.h"
#include "player.h"
#include "game.h"


extern Game * game;

Egg::Egg(): QObject(), QGraphicsPixmapItem(){
    //set randon type/color of egg
    int egg = (rand() % 3) + 1;
    auto file = QString(":/images/images/egg%1.png").arg(egg);

    setPixmap(QPixmap(file));

    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // connect
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


void Egg::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            if(pos().y() >= 600-100){
                game->getScore()->increase();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }

    setPos(x(), y()+10);
    if(pos().y() > 800 || pos().y() < 0){
        game->getLifes()->decrease();
        scene()->removeItem(this);
        delete this;
    }
}

QTimer *Egg::getTimer() const
{
    return timer;
}

void Egg::setTimer(QTimer *value)
{
    timer = value;
}
