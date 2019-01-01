#include "health.h"
#include <QFont>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QProcess>


health::health(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{

    playerHealth  =100;
    setDefaultTextColor(Qt::blue);
    setPlainText(QString("Health :")+QString::number(playerHealth)+QString("/100"));

    setFont(QFont("times",12));

}

void health::decrease()
{
     playerHealth=playerHealth-10;
    healthChecker();

}

void health::healthChecker(){
    if(playerHealth>70){
        setPlainText(QString("Health :")+QString::number(playerHealth)+QString("/100"));
    }else if(playerHealth>30){
        setDefaultTextColor(Qt::yellow);
        setPlainText(QString("Health :")+QString::number(playerHealth)+QString("/100"));
    }else if(playerHealth>=0){
        setDefaultTextColor(Qt::red);
        setPlainText(QString("Health :")+QString::number(playerHealth)+QString("/100"));
   }else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game over");
        msgBox.setText("Game over.Do you like to replay?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);
        switch (msgBox.exec()) {
                qDebug() << "Yes pressed";
                case QMessageBox::Yes:{
                QApplication::quit();
                QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
                break;

                }
        case QMessageBox::No:{
                qDebug() << "No pressed";
                QApplication::quit();
                break;
        }

        }
}

}


void health::increase()
{
    playerHealth = playerHealth+20;
    healthChecker();
}

int health::gethealth()
{
    return playerHealth;
}
