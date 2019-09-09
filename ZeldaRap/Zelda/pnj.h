#ifndef PNJ_H
#define PNJ_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "collidable.h"
#include "interactable.h"

class Pnj: public QObject, public Interactable, public Collidable
{
    Q_OBJECT
public:
    /*Pnj(int, int, QGraphicsItem * parent=0);*/
    Pnj(int, int, QString dialog="",int itemWidth = 64, int itemHeight= 100, QGraphicsItem * parent=0);
    ~Pnj();
    QString interact() override;
};

#endif // PNJ_H
