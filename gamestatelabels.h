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
    QString before = "Wellcome to RainningEggs !! <br>"
                     "> Try to catch all the Eggs! <br>"
                     "> Use left and rigth arrows to move the basket <br>"
                     "> Press Enter to start a new game";

    QString after = "<big>GAME OVER !!</big> <br>";

    QString family;
    unsigned int count=0;
    std::vector<QColor> colors = {Qt::yellow, Qt::red, Qt::blue, Qt::green};
};


#endif // GAMESTATELABELS_H
