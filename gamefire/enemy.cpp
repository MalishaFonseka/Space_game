#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "health.h"


extern health * Player_health;



enemy::enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rand_num = rand() % 700;
    setPos(rand_num,0);

    setPixmap(QPixmap(":/images/enemyship_1.jpg"));

    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void enemy::move()
{

    setPos(x(),y()+5);
    if(pos().y() >600){
      Player_health->decrease();
      scene()->removeItem(this);
      delete this;


    }


}

