#include "score.h"
#include <QFont>
#include "game.h"

extern Game *game;

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase(){
    if(!game->isRunning()) return;
    score++;
    setPlainText(QString("Score: ") + QString::number(score));

    if (game->getPwp()->state() == QMediaPlayer::PlayingState)
    {
        game->getPwp()->setPosition(0);
    }
    else{
        game->getPwp()->play();
    }

}

int Score::getScore(){
    return score;
}

void Score::setScore(int value)
{
    score = value;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}
