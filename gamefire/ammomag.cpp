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

    //Staring point of magaine is based on the random number
    setPos(rand_num,0);

    //Setting magazine image
    setPixmap(QPixmap(":/images/magazine_1.jpg"));


    //Connecting magazine with move function
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(70);
}

void ammomag::move()
{


    setPos(x(),y()+5);
    //Magazine is removed from the scene when it moves away from the screen
    if(pos().y() >600){
      scene()->removeItem(this);
      delete this;

    }

}

