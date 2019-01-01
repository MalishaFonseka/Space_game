#include <QApplication>
#include <QGraphicsView>
#include "myrect.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QObject>
#include "score.h"
#include "health.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include "ammo.h"
#include "ammomag.h"

score * Player_score;
health * Player_health;
ammo * player_ammo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QBrush(QImage(":/images/PurpleStars.gif")));

    myrect * player = new myrect();
   // player->setRect(0,0,100,100);

    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    view->show();

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(400,500);
    player->setFocus();

    scene->addItem(player);

    Player_score = new score();
    scene->addItem(Player_score);

    Player_health = new health();
    Player_health->setPos(Player_health->x(),Player_health->y()+25);
    scene->addItem(Player_health);


    player_ammo = new ammo();
    player_ammo->setPos(player_ammo->x(),player_ammo->y()+50);
    scene->addItem(player_ammo);


    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QTimer * medipacktimer = new QTimer();
    QObject::connect(medipacktimer,SIGNAL(timeout()),player,SLOT(medispawn()));
    medipacktimer->start(10000);

    QTimer * ammomagtimer = new QTimer();
    QObject::connect(ammomagtimer,SIGNAL(timeout()),player,SLOT(magspawn()));
    ammomagtimer->start(11000);


    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/alien-spaceship_daniel_simion.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();
    return a.exec();
}
