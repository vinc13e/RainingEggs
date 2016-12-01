/*
 * RainingEggs: Mini 2D game
 *
 * Copyright (C) 2016 Vicente Fernandes
 * vinc13e@gmail.com
 */

#ifndef GAMESTATELABELS_H
#define GAMESTATELABELS_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QColor>
#include <vector>
class GameStateLabels: public QGraphicsTextItem
{
    Q_OBJECT //Macro
public:
    GameStateLabels(QGraphicsItem * parent=0);
    void beforeGame();
    void afterGame();
public slots:
    void blink();

private:
    QString before = "<big>Welcome to <b>RainingEggs</b> !! </big><br>"
                     "> Try to catch all the Eggs <br>"
                     "> Use left and right arrows to move the basket <br>"
                     "> Press space to pause/resume the game <br> "
                     "> Press Enter to start a new game";

    QString after = "<big>GAME OVER !!</big> <br>"
                    "<font size='1'>> Press Enter to return to menu</font>";

    QString family;
    unsigned int count=0;
    std::vector<QColor> colors = {Qt::yellow, Qt::red, Qt::blue, Qt::green};
};


#endif // GAMESTATELABELS_H
