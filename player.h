#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

class Player: public QObject, public QGraphicsRectItem
{
    Q_OBJECT //Macro
public:
     Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
};
#endif // PLAYER_H
