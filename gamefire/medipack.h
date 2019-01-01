#ifndef MEDIPACK_H
#define MEDIPACK_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class medipack: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    medipack(QGraphicsItem *parent=0);

public slots:
    void move();

};
#endif // MEDIPACK_H
