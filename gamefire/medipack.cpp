#include "medipack.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>


medipack::medipack(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int rand_num = rand() % 500;
    setPos(rand_num,0);

    setPixmap(QPixmap(":/images/medipack_1.jpg"));


    QTimer * timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(60);
}

void medipack::move()
{

    setPos(x(),y()+5);
    if(pos().y() >600){
      scene()->removeItem(this);
      delete this;

    }


}

