
#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "bullet.h"

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    Player *player = new Player();
    player->setRect(0,0,100,100); //change from 0 0 to 100 100
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setPos(width()/2-(player->rect().width()/2), height()-player->rect().height());
    player->setFocus();
    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    lifes = new Lifes();
    lifes->setPos(lifes->x(), lifes->y()+24);
    scene->addItem(lifes);
    //spawn bullets

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000);

}
