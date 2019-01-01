#include "medipack.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>


medipack::medipack(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //creating medipack staring points base on a randomm number assigned to a variable
    int rand_num = rand() % 500;
    setPos(rand_num,0);

    //setting the edipack image
    setPixmap(QPixmap(":/images/medipack_1.jpg"));

    //connecting the medipack with movefunction
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);
}

void medipack::move()
{

    setPos(x(),y()+5);
    //medipack is removed when passes the boudary
    if(pos().y() >600){
      scene()->removeItem(this);
      delete this;

    }


}

