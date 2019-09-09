#include "game.h"
#include <QApplication>
#include <QDebug>

Game * game;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    game = new Game();
    game->show();

    //character->setPos(view->width()/2,view->height() - character->rect().height());

    return app.exec();
}
