#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <QGraphicsTextItem>

class magazine: public QGraphicsTextItem{

public:
    magazine(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    int gethealth();

public:
    int playerHealth;

};

#endif // MAGAZINE_H
