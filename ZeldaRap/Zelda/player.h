#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "collidable.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
    Player(QGraphicsItem * parent=0);
    int health;
    bool collisions[4];
    bool moveFlag;

    void checkCollisions(Collidable * itemToCheck);

private:
    QString direction;

public slots:
    void movable();
};

#endif // PLAYER_H
