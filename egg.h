#ifndef EGG_H
#define EGG_H
#include <QGraphicsPixmapItem>
#include <QObject>

//TODO change name to egg


class Egg : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Egg();
    QTimer * timer;
public slots:
    void move();
private:

};

#endif // EGG_H
