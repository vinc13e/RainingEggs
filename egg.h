#ifndef EGG_H
#define EGG_H
#include <QGraphicsPixmapItem>
#include <QObject>

//TODO change name to egg


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
