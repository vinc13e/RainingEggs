#include "game.h"
#include "egg.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>
#include <typeinfo>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background1.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    Player *player = new Player();
    player->setScale(0.4);
    player->setPos(325,498); //TODO center
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    lifes = new Lifes();
    lifes->setPos(lifes->x(), lifes->y()+24);
    scene->addItem(lifes);

    //spawn eggs
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    //timer->start(1000);

}

void Game::pause()
{
    QList<QGraphicsItem *> items = scene->items();
    if(running){
        //Pause
        timer->stop(); // stop spawning new eggs;

        foreach (QGraphicsItem *item, items) { // pause all eggs;
            if (typeid(*item) == typeid(Egg)){
                qgraphicsitem_cast<Egg *>(item)->timer->stop();
                qDebug() << "Egg ...." << endl;
            }
        }

    }
    else{
        //Resume
        timer->start(1000);

        foreach (QGraphicsItem *item, items) { // resume all eggs;
            if (typeid(*item) == typeid(Egg)){
                qgraphicsitem_cast<Egg *>(item)->timer->start(50);
                qDebug() << "Egg ...." << endl;
            }
        }
    }

    running = !running;
}
