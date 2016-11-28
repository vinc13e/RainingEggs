#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include "game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    game = new Game();
    game->show();

    return a.exec();
}


//TODO
//tut 6 done
// lifes <=0 game over
// botao para iniciar jogada / reinicar apos game over
// botao para pause / resume
// botao para iniciar objectos
// usar um ou dois botoes em x de teclas...por exemplo pause/resume
// texturas (azul ceu - area jogo ?)
// rectanglo -> cesto
// bullets -> eggs (cor aleatoria)

//center bucket
//https://www.youtube.com/watch?v=SnkszRZPcvM
