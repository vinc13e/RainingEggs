/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#include "game.h"
#include "egg.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QDebug>
#include <typeinfo>
#include <QThread>
#include <QMediaPlayer>

Game::Game(QWidget *parent){
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/images/background1.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    Player *player = new Player();
    player->setScale(0.4);
    player->setPos(325,498);
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

    // play background music
    bgPlayList = new QMediaPlaylist();
    bgPlayList->addMedia(QUrl("qrc:/sounds/sounds/bgsound.mp3"));
    bgPlayList->setPlaybackMode(QMediaPlaylist::Sequential);
    bgSound = new QMediaPlayer();
    bgSound->setPlaylist(bgPlayList);
    bgSound->play();


    gameoverPlayList = new QMediaPlaylist();
    gameoverPlayList->addMedia(QUrl("qrc:/sounds/sounds/gameover.mp3"));
    gameoverPlayList->setPlaybackMode(QMediaPlaylist::Sequential);
    gameoverSound = new QMediaPlayer();
    gameoverSound->setPlaylist(gameoverPlayList);

    pointWonPlayList = new QMediaPlaylist();
    pointWonPlayList->addMedia(QUrl("qrc:/sounds/sounds/pointWon.wav"));
    pointWonPlayList->setPlaybackMode(QMediaPlaylist::Sequential);
    pointWonSound = new QMediaPlayer();
    pointWonSound->setPlaylist(pointWonPlayList);

}


void Game::start(){
    if(gameover){
        systemLabels->beforeGame();
        gameover = !gameover;
    }

    else{
        running = true;
        score->setScore(0);
        lifes->setLifes(3);
        score->show();
        lifes->show();
        systemLabels->hide();
        pauseResume(); //resume;
    }

    gameoverSound->stop();
    bgSound->play();

}

void Game::over(){
    running = false;
    paused = true;
    gameover = true;

    systemLabels->afterGame();
    systemLabels->show();
    score->hide();
    lifes->hide();

    timer->stop(); // stop spawning new eggs;

    // play game over sound
    bgSound->stop();
    gameoverSound->stop();
    gameoverSound->play();

    return;
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
                qgraphicsitem_cast<Egg *>(item)->getTimer()->stop();
            }
        }

    }
    else{
        //Resume
        timer->start(1200);
        foreach (QGraphicsItem *item, items) { // resume all eggs;
            if (typeid(*item) == typeid(Egg)){
                qgraphicsitem_cast<Egg *>(item)->getTimer()->start(50);
            }
        }
    }
    paused = !paused;
}

bool Game::isRunning() const
{
    return running;
}

void Game::setRunning(bool value)
{
    running = value;
}

bool Game::isPaused() const
{
    return paused;
}

void Game::setPaused(bool value)
{
    paused = value;
}

bool Game::isGameover() const
{
    return gameover;
}

void Game::setGameover(bool value)
{
    gameover = value;
}

QGraphicsScene *Game::getScene() const
{
    return scene;
}

void Game::setScene2(QGraphicsScene *value)
{
    scene = value;
}

Player *Game::getPlayer() const
{
    return player;
}

void Game::setPlayer(Player *value)
{
    player = value;
}

Score *Game::getScore() const
{
    return score;
}

void Game::setScore(Score *value)
{
    score = value;
}

Lifes *Game::getLifes() const
{
    return lifes;
}

void Game::setLifes(Lifes *value)
{
    lifes = value;
}

QTimer *Game::getTimer() const
{
    return timer;
}

void Game::setTimer(QTimer *value)
{
    timer = value;
}

GameStateLabels *Game::getSystemLabels() const
{
    return systemLabels;
}

void Game::setSystemLabels(GameStateLabels *value)
{
    systemLabels = value;
}

QMediaPlayer *Game::getPwp() const
{
    return pointWonSound;
}

QMediaPlayer *Game::getPointWonSound() const
{
    return pointWonSound;
}


