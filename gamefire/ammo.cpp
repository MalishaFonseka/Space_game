#include "ammo.h"
#include <QFont>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>



ammo::ammo(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    //Initialize ammo count
    Ammo  =100;

    //Set text font,color,size of the ammo count displayed
    setDefaultTextColor(Qt::blue);
    setPlainText(QString("Ammo :")+QString::number(Ammo)+QString("/100"));

    setFont(QFont("times",12));

}

void ammo::checkAmmoCount(){

    //condition to check the the amount of ammo to change the color of ammo amount displayed
    if(Ammo>70){
        setPlainText(QString("Ammo :")+QString::number(Ammo)+QString("/100"));
    }else if(Ammo>30){
        setDefaultTextColor(Qt::yellow);
         setPlainText(QString("Ammo :")+QString::number(Ammo)+QString("/100"));
    }else if(Ammo>=0){
        setDefaultTextColor(Qt::red);
         setPlainText(QString("Ammo :")+QString::number(Ammo)+QString("/100"));
   }else {

        //pop up
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game over");
        msgBox.setText("Ammo finished.Do you like to replay?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);

        switch (msgBox.exec()) {

                case QMessageBox::Yes:{
                QApplication::quit();
                QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
                break;

                }
        case QMessageBox::No:{

                QApplication::quit();
                break;
        }

        }
}


}

void ammo::decreaseAmmo()
{
     Ammo=Ammo-1;
     checkAmmoCount();
}

void ammo::increaseAmmo()
{
    Ammo = Ammo+10;
    checkAmmoCount();
}

int ammo::getAmmo()
{
    return Ammo;
}
