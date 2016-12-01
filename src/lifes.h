#ifndef LIFES_H
#define LIFES_H

#include <QGraphicsTextItem>

class Lifes: public QGraphicsTextItem{
public:
    Lifes(QGraphicsItem * parent=0);
    void decrease();
    int getLifes();
    void setLifes(int value);

private:
    int lifes;
};
#endif // LIFES_H
