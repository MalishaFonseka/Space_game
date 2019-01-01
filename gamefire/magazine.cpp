#include "magazine.h"
#include <QFont>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>



magazine::magazine(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{

    playerHealth  =100;
    setDefaultTextColor(Qt::blue);
    setPlainText(QString("Health :")+QString::number(playerHealth));

    setFont(QFont("times",16));

}

void magazine::decrease()
{
     playerHealth=playerHealth-10;
     if(playerHealth>70){
         setPlainText(QString("Health :")+QString::number(playerHealth));
     }else if(playerHealth>30){
         setDefaultTextColor(Qt::yellow);
          setPlainText(QString("Health :")+QString::number(playerHealth));
     }else if(playerHealth>=0){
         setDefaultTextColor(Qt::red);
          setPlainText(QString("Health :")+QString::number(playerHealth));
    }else {
         QMessageBox msgBox;
         msgBox.setWindowTitle("Game over");
         msgBox.setText("Game over.Do you like to replay?");
         msgBox.setStandardButtons(QMessageBox::Yes);
         msgBox.addButton(QMessageBox::No);
         msgBox.setDefaultButton(QMessageBox::No);
         if(msgBox.exec() == QMessageBox::Yes){
           // do something
         }else {
           QApplication::quit();
         }
}

}

void health::increase()
{
    playerHealth = playerHealth+20;
}

int health::gethealth()
{
    return playerHealth;
}
