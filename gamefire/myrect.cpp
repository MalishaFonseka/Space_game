#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include "score.h"
#include "medipack.h"
#include "health.h"
#include "ammomag.h"
#include "ammo.h"
#include <QDebug>

extern health * Player_health;
extern  score * Player_score;
extern ammo * player_ammo;

myrect::myrect(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    //shooting sound is added
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/380_gunshot_single-mike-koenig.mp3"));

    //player's image is added
    setPixmap(QPixmap(":/images/rocket_2.jpg"));
}

void myrect::keyPressEvent(QKeyEvent *event)
{

    //condition to check the keyboard's key movements
    if(event->key() == Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-10,y());
        destroyenemy();
        medipackCatched();
        ammomagCatched();

    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()<800)
        setPos(x()+10,y());
        destroyenemy();
        medipackCatched();
        ammomagCatched();
    }
    else if(event->key() == Qt::Key_Space) {
      bullet * bulet = new bullet();
      bulet->setPos(x(),y());
        scene()->addItem(bulet);

        if(bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();

        }



    }



}

void myrect::destroyenemy(){

    //colliding items are added
    QList<QGraphicsItem *> colliding_Items = collidingItems();
    //loop to iterate
    for(int i=0,n=colliding_Items.size();i<n;++i){
          if (typeid(*(colliding_Items[i])) == typeid(enemy)){

            //players score is reduced
            Player_score->decrease();

            //players health is rreduced
            Player_health->decrease();

            //colliding item is removed
            scene()->removeItem(colliding_Items[i]);
            delete colliding_Items[i];
            return;

        }

}
}



void myrect::medipackCatched(){

    QList<QGraphicsItem *> colliding_Items = collidingItems();
    for(int i=0,n=colliding_Items.size();i<n;++i){
          if (typeid(*(colliding_Items[i])) == typeid(medipack)){

            //Player_score is increased
            Player_score->increase();


            //Player_health is increase
            Player_health->increase();
            scene()->removeItem(colliding_Items[i]);
            delete colliding_Items[i];
            return;

        }

}
}


void myrect::ammomagCatched(){

    QList<QGraphicsItem *> colliding_Items = collidingItems();

    for(int i=0,n=colliding_Items.size();i<n;++i){
          if (typeid(*(colliding_Items[i])) == typeid(ammomag)){

            //Player_score is increased
            player_ammo->increaseAmmo();

            scene()->removeItem(colliding_Items[i]);
            delete colliding_Items[i];
            return;

        }

}

}


void myrect::spawn()
{
    //enemy object is created
    enemy * enemyObj = new enemy();
    scene()->addItem(enemyObj);
}


void myrect::medispawn()
{
    //medipack object is created
    medipack * medipackObj = new medipack();
    scene()->addItem(medipackObj);

}

void myrect::magspawn(){

    ammomag * ammoObj = new ammomag();
    scene()->addItem(ammoObj);

}

