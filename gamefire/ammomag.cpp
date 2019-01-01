#include "ammomag.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "health.h"
#include "score.h"




ammomag::ammomag(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //A random number is generated and assigned to a variable
    int rand_num = rand() % 600;

    //Position is made on a random number
    setPos(rand_num,0);

    //Setting magazine image
    setPixmap(QPixmap(":/images/magazine_1.jpg"));


    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(70);
}

void ammomag::move()
{


    setPos(x(),y()+5);
    //Magazine is removed from the scene based on the condition
    if(pos().y() >600){
      scene()->removeItem(this);
      delete this;

    }


}

