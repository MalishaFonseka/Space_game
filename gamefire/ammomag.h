#ifndef AMMOMAG_H
#define AMMOMAG_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class ammomag: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ammomag(QGraphicsItem *parent=0);

public slots:
    void move();

};

#endif // AMMOMAG_H
