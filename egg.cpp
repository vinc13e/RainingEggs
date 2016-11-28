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
    auto file = QString(":/images/egg%1.png").arg(egg);

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
            if(pos().y() >= 600-100){ //sizeo of player //so colisoes por cima contam ...
                game->score->increase();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
    }

    setPos(x(), y()+10);
    if(pos().y() > 800 || pos().y() < 0){ //TODO get from global scope
        //TODO draw smash egg on tis egg position y=600 -epsilon
        game->lifes->decrease();
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted" << endl;
    }
}
