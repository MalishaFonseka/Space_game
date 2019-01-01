#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class health: public QGraphicsTextItem{

public:
    health(QGraphicsItem * parent=0);
    void decrease();
    void increase();
    void healthChecker();
    int gethealth();


private:
    int playerHealth;

};

#endif // HEALTH_H
