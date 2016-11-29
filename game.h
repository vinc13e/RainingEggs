#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
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

    //TODO set private
    bool running = false; //TODO starts false
    bool paused = true;
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Lifes * lifes;
    QTimer * timer;
    GameStateLabels *systemLabels;

};


#endif // GAME_H
