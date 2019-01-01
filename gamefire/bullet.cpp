#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "score.h"
#include "ammo.h"

extern  score * Player_score;
extern ammo * player_ammo;

bullet::bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //image of bullet
    setPixmap(QPixmap(":/images/bullet_2.jpg"));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}




void bullet::move(){

    //Colliding items are added to a list
    QList<QGraphicsItem *> colliding_Items = collidingItems();

    //loop to iterate
    for(int i=0,n=colliding_Items.size();i<n;++i){

        //players ammo is reduced in every move
        player_ammo->decreaseAmmo();



        if (typeid(*(colliding_Items[i])) == typeid(enemy)){

            //players score is incremented when bullet hits an enemy
            Player_score->increase();

            //remove the colliding enemy and the respective bullet
            scene()->removeItem(colliding_Items[i]);
            scene()->removeItem(this);
            delete colliding_Items[i];
            delete this;
            return;

        }

    }

     //bullet is removed when it disappears from the screen for memory mannemgent
     setPos(x(),y()-10);
      if(pos().y() <0){
          scene()->removeItem(this);
          delete this;

      }


}
