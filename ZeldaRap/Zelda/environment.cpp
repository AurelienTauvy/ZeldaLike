#include "environment.h"

Environment::Environment(int posX, int posY, int itemWidth, int itemHeight, QString filename, QGraphicsItem *parent): QObject(), Collidable(itemWidth, itemHeight, parent)
{
    setPixmap(QPixmap(filename));
    setPos(posX,posY);
}
