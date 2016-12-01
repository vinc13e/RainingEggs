/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#ifndef EGG_H
#define EGG_H
#include <QGraphicsPixmapItem>
#include <QObject>


class Egg : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Egg();
    QTimer *getTimer() const;
    void setTimer(QTimer *value);

public slots:
    void move();
private:
    QTimer * timer;

};

#endif // EGG_H
