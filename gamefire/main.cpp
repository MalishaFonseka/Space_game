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


//Dcelaration of global objects
score * Player_score;
health * Player_health;
ammo * player_ammo;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creating a scenes
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //Background image is set up
    scene->setBackgroundBrush(QBrush(QImage(":/images/PurpleStars.gif")));

    //player object from myrect is created and added to the scene
    myrect * player = new myrect();
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->setPos(400,500);
    player->setFocus();


    //creating a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    //Removal of scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    //Score is added to the scene
    Player_score = new score();
    scene->addItem(Player_score);

    //health is added to the screen and positioned
    Player_health = new health();
    Player_health->setPos(Player_health->x(),Player_health->y()+25);
    scene->addItem(Player_health);

    //ammo is added to the screen and positioned
    player_ammo = new ammo();
    player_ammo->setPos(player_ammo->x(),player_ammo->y()+50);
    scene->addItem(player_ammo);


    //Creating the alien
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //creating the medipack
    QTimer * medipacktimer = new QTimer();
    QObject::connect(medipacktimer,SIGNAL(timeout()),player,SLOT(medispawn()));
    medipacktimer->start(10000);

    //creating the magazine
    QTimer * ammomagtimer = new QTimer();
    QObject::connect(ammomagtimer,SIGNAL(timeout()),player,SLOT(magspawn()));
    ammomagtimer->start(11000);


    //Background music is added
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/alien-spaceship_daniel_simion.mp3"));
    //background music is repeated
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    //background music is played
    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();


    return a.exec();
}
