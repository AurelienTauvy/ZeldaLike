#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "pnj.h"
#include "environment.h"
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>

extern int TILE_SIZE = 64;
QList<Collidable *> collidingObjects;
QList<Interactable *> interactingObjects;

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    collidingObjects = QList<Collidable *>();
    character = new Player();

    //Not working
    QMediaPlayer * mediaPlayer = new QMediaPlayer();
    mediaPlayer->setMedia(QUrl("qrc:/music/kokiriMusic.mp3"));
    mediaPlayer->setVolume(100);
    mediaPlayer->play();


    scene->setSceneRect(0,0,TILE_SIZE*20,TILE_SIZE*10);
    setBackgroundBrush(QBrush(QImage(":/images/Environment/background/fond.png")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(TILE_SIZE*20,TILE_SIZE*10);

    //character->setRect(0,0,100,100);
    //character->setVisible(true);
    character->setPos(TILE_SIZE*5,TILE_SIZE*5);
    character->setFlag(QGraphicsItem::ItemIsFocusable);
    character->setFocus();
    //character->setScale(2);

    scene->addItem(character);

    ///////////////////////////////////
    //TODO :
    //Refactor/extract method for setting up all items
    ///////////////////////////////////

    Environment * arbre = new Environment(TILE_SIZE*8, TILE_SIZE*2, TILE_SIZE*2, TILE_SIZE*2, ":/images/Environment/collidables/arbre.png");
    collidingObjects.append(arbre);

    for (int i = 0; i < 10; i++){
        Environment * barriere = new Environment(TILE_SIZE*i*2, 0, TILE_SIZE*2, TILE_SIZE*2, ":/images/Environment/collidables/arbre.png");
        collidingObjects.append(barriere);
    }

    for (int i = 1; i < 20; i++){
        Environment * barriere = new Environment(TILE_SIZE*i, TILE_SIZE*9, TILE_SIZE*1, TILE_SIZE*1, ":/images/Environment/collidables/tronc.png");
        collidingObjects.append(barriere);
    }

    Environment * barriere = new Environment(TILE_SIZE*0, TILE_SIZE*6, TILE_SIZE*1, TILE_SIZE*1, ":/images/Environment/collidables/tronc.png");
    collidingObjects.append(barriere);

    barriere = new Environment(TILE_SIZE*1, TILE_SIZE*6, TILE_SIZE*1, TILE_SIZE*1, ":/images/Environment/collidables/tronc.png");
    collidingObjects.append(barriere);

    barriere = new Environment(TILE_SIZE*1, TILE_SIZE*7, TILE_SIZE*1, TILE_SIZE*1, ":/images/Environment/collidables/tronc.png");
    collidingObjects.append(barriere);

    barriere = new Environment(TILE_SIZE*1, TILE_SIZE*8, TILE_SIZE*1, TILE_SIZE*1, ":/images/Environment/collidables/tronc.png");
    collidingObjects.append(barriere);

    Environment * rubis = new Environment(TILE_SIZE*0, TILE_SIZE*7, TILE_SIZE*1, TILE_SIZE*1, ":/images/collectibles/Rubis.png");
    collidingObjects.append(rubis);

    rubis = new Environment(TILE_SIZE*0, TILE_SIZE*8, TILE_SIZE*1, TILE_SIZE*1, ":/images/collectibles/Rubis.png");
    collidingObjects.append(rubis);

    rubis = new Environment(TILE_SIZE*0, TILE_SIZE*9, TILE_SIZE*1, TILE_SIZE*1, ":/images/collectibles/Rubis.png");
    collidingObjects.append(rubis);

    Environment * panneau = new Environment(TILE_SIZE*3, TILE_SIZE*7, TILE_SIZE*1, TILE_SIZE*1, ":/images/Environment/collidables/pancarte.png");
    collidingObjects.append(panneau);


    Pnj * pnj = new Pnj(TILE_SIZE*2,TILE_SIZE*2, "Bonjour, jeune développeur ! Je suis le PNJ numéro 1 !");
    collidingObjects.append(pnj);
    interactingObjects.append(pnj);

    Pnj * pnj2 = new Pnj(TILE_SIZE*15,TILE_SIZE*4, "Donnez-moi un visage ! :(");
    collidingObjects.append(pnj2);
    interactingObjects.append(pnj2);

    foreach(QGraphicsItem *q, collidingObjects){
        scene->addItem(q);
    }

    //QGraphicsView * view = new QGraphicsView(scene);


    show();
}
