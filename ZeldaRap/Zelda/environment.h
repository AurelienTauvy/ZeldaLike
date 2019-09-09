#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QObject>
#include "collidable.h"

class Environment: public QObject, public Collidable
{
public:
    //Environment(int itemWidth, int itemHeight, QObject * parent=0);
    Environment(int posX, int posY, int itemWidth, int itemHeight, QString fileName, QGraphicsItem * parent=0);
};

#endif // ENVIRONMENT_H
