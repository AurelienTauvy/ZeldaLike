#include "player.h"
#include "collidable.h"
#include "interactable.h"
#include "game.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>


extern QList<Collidable *> collidingObjects;
extern QList<Interactable *> interactingObjects;
extern int TILE_SIZE;
QList<Collidable *> closeItems;
extern Game game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    health = 100;
    //moveFlag = true;

    for (int i = 0; i < 4; i++){
        collisions[i] = false;
    }

    //setPixmap(QPixmap(":/images/characters/Link/Link_2D.png"));
    setPixmap(QPixmap(":/images/characters/Link/link_down.png"));

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movable()));

    timer->start(100);
}

void Player::movable(){
    moveFlag = true;
}

void Player::keyPressEvent(QKeyEvent *event)
{

    //qDebug() << "Player knows that you pressed a key";
    QString dialog;//Dialog in case of interaction
    for (int i = 0; i < 4; i++){
        collisions[i] = false;
    }
    closeItems.clear();
    foreach(Collidable *c, collidingObjects){
        checkCollisions(c);
    }


    if(moveFlag == true){

        switch (event->key()) {

        case Qt::Key_Left:
        case Qt::Key_Q:
            if (!(collisions[1])){
                setPos(x()-64,y());
            }
            direction = "Left";
            setPixmap(QPixmap(":/images/characters/Link/link_left.png"));
            //qDebug() << direction;
            moveFlag = false;
            break;

        case Qt::Key_Right:
        case Qt::Key_D:
            if (!collisions[2]){
                setPos(x()+64,y());
            }
            direction = "Right";
            setPixmap(QPixmap(":/images/characters/Link/link_right.png"));
            //qDebug() << direction;
            moveFlag = false;
            break;

        case Qt::Key_Up:
        case Qt::Key_Z:
            if (!collisions[0]){
                setPos(x(),y()-64);
            }
            direction = "Up";
            setPixmap(QPixmap(":/images/characters/Link/link_up.png"));
            //qDebug() << direction;
            moveFlag = false;
            break;

        case Qt::Key_Down:
        case Qt::Key_S:
            if (!collisions[3]){
                setPos(x(),y()+64);
            }
            direction = "Down";
            setPixmap(QPixmap(":/images/characters/Link/link_down.png"));
            //qDebug() << direction;
            moveFlag = false;
            break;

        case Qt::Key_Space:
        case Qt::Key_E:
            //Interact
            foreach(Collidable *c, closeItems){
                if (direction == "Left"){
                    //Here to check for crashes on interaction with environment (lines with "dynamic_cast")
                    if(this->x()-1> c->x() && this->x()-1 <= c->x()+c->width()){
                        dialog = dynamic_cast<Interactable*> (c)->interact();
                    }
                } else if (direction == "Right"){
                    if(this->x()+64+1> c->x() && this->x()+64+1 <= c->x()+c->width()){
                        dialog = dynamic_cast<Interactable*> (c)->interact();
                    }
                } else if (direction == "Up"){
                    if(this->y()-1> c->y() && this->y()-1 <= c->y()+c->height()){
                        dialog = dynamic_cast<Interactable*> (c)->interact();
                    }
                } else if (direction == "Down"){
                    if(this->y()+100+1> c->y() && this->y()+100+1 <= c->y()+c->height()){
                        dialog = dynamic_cast<Interactable*> (c)->interact();
                    }
                } else {
                    qDebug("Non-existing direction !");
                }
            }
            if (dialog != ""){
                qDebug()<<dialog;
            }
            break;

        default:
            qDebug() << event->key();
            break;
        }
    }

}

//Think of the player as a Rectangle. We check collisions for 8 points :
//---A---       ---0---
//-------
//-------
//B-----C       1-----2
//-------
//-------
//---D---       ---3---

void Player::checkCollisions(Collidable * itemToCheck){
    //TODO Comment magic numbers
    if (x() == 0){
        collisions[1] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }
    if (y() == 0){
        collisions[0] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }

    if (x() == TILE_SIZE*19){
        collisions[2] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }
    if (y() == TILE_SIZE*8){
        collisions[3] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }

    int xCollisionLeft = this->x()-1;
    int yCollisionTop = this->y()-1;

    int xCollisionRight = this->x()+64+1;
    int yCollisionBottom = this->y()+100+1;

    int xa = this->x()+32;
    int ya = yCollisionTop;

    int xb = xCollisionLeft;
    int yb = this->y() + 36;

    int xc = xCollisionRight;
    int yc = yb;

    int xd = xa;
    int yd = yCollisionBottom;


    if (xa > itemToCheck->x() && xa < itemToCheck->x()+itemToCheck->width()
            && ya > itemToCheck->y() && ya < itemToCheck->y()+itemToCheck->height()){
        //A BLOCKED
        qDebug()<<"TOP BLOCKED";
        collisions[0] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }

    if (xb > itemToCheck->x() && xb < itemToCheck->x()+itemToCheck->width()
            && yb > itemToCheck->y() && yb < itemToCheck->y()+itemToCheck->height()){
        //B BLOCKED
        qDebug()<<"LEFT BLOCKED";
        collisions[1] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }

    if (xc > itemToCheck->x() && xc < itemToCheck->x()+itemToCheck->width()
            && yc > itemToCheck->y() && yc < itemToCheck->y()+itemToCheck->height()){
        //C BLOCKED
        qDebug()<<"RIGHT BLOCKED";
        collisions[2] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }

    if (xd > itemToCheck->x() && xd < itemToCheck->x()+itemToCheck->width()
            && yd > itemToCheck->y() && yd < itemToCheck->y()+itemToCheck->height()){
        //D BLOCKED
        qDebug()<<"BOTTOM BLOCKED";
        collisions[3] = true;
        closeItems.append(itemToCheck);
        //closeItems.append(dynamic_cast<Interactable*> (itemToCheck));
    }

}
