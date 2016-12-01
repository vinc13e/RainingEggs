/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
    void setScore(int value);

private:
    int score;
};


#endif // SCORE_H
