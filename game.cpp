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
    score->hide();
    scene->addItem(score);

    lifes = new Lifes();
    lifes->hide();
    lifes->setPos(lifes->x(), lifes->y()+24);
    scene->addItem(lifes);


    systemLabels = new GameStateLabels();
    scene->addItem(systemLabels);
    QTimer *labelsTimer = new QTimer();
    QObject::connect(labelsTimer,SIGNAL(timeout()),systemLabels,SLOT(blink()));
    labelsTimer->start(500);


    //spawn eggs
    timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));

}

void Game::start(){
    running = true;
    score->setScore(0);
    lifes->setLifes(2);
    score->show();
    lifes->show();
    systemLabels->hide();
    pauseResume(); //resume;
    qDebug() << "running: " << running << endl;
}

void Game::over(){
//    running = false;
//    paused = true;

    systemLabels->afterGame();
    systemLabels->show();
    score->hide();
    lifes->hide();

    pauseResume(); //Pause

    //delete all Eggs
    QList<QGraphicsItem *> items = scene->items();
    foreach (QGraphicsItem *item, items) {
        if (typeid(*item) == typeid(Egg)){
            scene->removeItem(item);
            delete item;
            return;
        }
    }
//    scene->update();
//    paused = true;
//    start();

}


void Game::pauseResume()
{
    if(!running) return;
    QList<QGraphicsItem *> items = scene->items();
    if(!paused){
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

    paused = !paused;
}
