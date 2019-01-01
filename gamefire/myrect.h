#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>


class myrect:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT

public:
    myrect(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();
    void magspawn();
    void medispawn();
    void destroyenemy();
    void ammomagCatched();
    void Catched();
    void medipackCatched();
private:
    QMediaPlayer * bulletsound;


};


#endif // MYRECT_H
