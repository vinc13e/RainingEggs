/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "player.h"
#include "score.h"
#include "lifes.h"
#include "gamestatelabels.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);
    void start();
    void pauseResume();
    void over();

    bool isRunning() const;
    void setRunning(bool value);

    bool isPaused() const;
    void setPaused(bool value);

    bool isGameover() const;
    void setGameover(bool value);

    QGraphicsScene *getScene() const;
    void setScene2(QGraphicsScene *value);

    Player *getPlayer() const;
    void setPlayer(Player *value);

    Score *getScore() const;
    void setScore(Score *value);

    Lifes *getLifes() const;
    void setLifes(Lifes *value);

    QTimer *getTimer() const;
    void setTimer(QTimer *value);

    GameStateLabels *getSystemLabels() const;
    void setSystemLabels(GameStateLabels *value);

    QMediaPlayer *getPointLostSound() const;

    QMediaPlayer *getPointWonSound() const;

    QMediaPlayer *getPwp() const;

    QMediaPlayer *getPlp() const;

private:
    bool running = false;
    bool paused = true;
    bool gameover = false;
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Lifes * lifes;
    QTimer * timer;
    GameStateLabels *systemLabels;

    QMediaPlaylist * bgPlayList;
    QMediaPlayer * bgSound;

    QMediaPlaylist *gameoverPlayList;
    QMediaPlayer *gameoverSound;

    QMediaPlaylist *pointWonPlayList;
    QMediaPlayer *pointWonSound;

};


#endif // GAME_H
