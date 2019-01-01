#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "health.h"


extern health * Player_health;



enemy::enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //random number is assigned
    int rand_num = rand() % 700;

    //position is set using a variable containing a random number
    setPos(rand_num,0);

    //Enemy image is set
    setPixmap(QPixmap(":/images/enemyship_1.jpg"));

    //Enemy is connected with the move function
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void enemy::move()
{

    setPos(x(),y()+5);

    //remove the enemies who moves away from the screen
    if(pos().y() >600){
      Player_health->decrease();
      scene()->removeItem(this);
      delete this;


    }
}

