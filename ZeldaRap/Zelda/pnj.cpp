#include "pnj.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "game.h"

//extern Game * game;

Pnj::Pnj(int posX, int posY, QString dialog,int itemWidth, int itemHeight, QGraphicsItem *parent): QObject(), Interactable(dialog), Collidable(itemWidth, itemHeight, parent)//QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/characters/pnj.png"));
    setPos(posX,posY);
}
Pnj::~Pnj(){
    qDebug()<<"Destructing Pnj";
}

QString Pnj::interact(){
    return this->getDialog();
}
