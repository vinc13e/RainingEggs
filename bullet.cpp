#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>
#include <typeinfo>
#include "bullet.h"
#include "player.h"
#include "game.h"


extern Game * game;

Bullet::Bullet(): QObject(), QGraphicsRectItem(){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    setRect(0,0,10,10);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            if(pos().y() <= 600-100){ //sizeo of player //so colisoes por cima contam ...
                game->score->increase();
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x(), y()+10);
    if(pos().y() > 800 || pos().y() < 0){ //TODO get from global scope
        game->lifes->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted" << endl;
    }
}
