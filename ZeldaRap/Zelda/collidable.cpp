#include "collidable.h"

Collidable::Collidable(int width, int height, QGraphicsItem * parent)
{
    this->itemWidth = width;
    this->itemHeight = height;
}

int Collidable::width(){
    return this->itemWidth;
}

int Collidable::height(){
    return this->itemHeight;
}
