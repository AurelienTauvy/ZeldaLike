#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Collidable : public QGraphicsPixmapItem
{
public:
    int itemWidth;
    int itemHeight;
    Collidable(int width, int height, QGraphicsItem * parent=0);
    int width();
    int height();
};

#endif // COLLIDABLE_H
