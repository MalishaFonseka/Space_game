#ifndef AMMO_H
#define AMMO_H


#include <QGraphicsTextItem>

class ammo: public QGraphicsTextItem{

public:
    ammo(QGraphicsItem * parent=0);
    void decreaseAmmo();
    void increaseAmmo();
    void checkAmmoCount();
    int getAmmo();

private:

    int Ammo;

};

#endif // AMMO_H
