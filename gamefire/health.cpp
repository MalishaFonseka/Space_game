#include "health.h"
#include <QFont>
#include <QDebug>
#include <QApplication>
#include <QMessageBox>
#include <QProcess>


health::health(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{

    //initialize the health
    playerHealth  =100;

    //font settings of health dislpayed on screen is set
    setDefaultTextColor(Qt::blue);
    setPlainText(QString("Health :")+QString::number(playerHealth)+QString("/100"));
    setFont(QFont("times",12));

}

void health::decrease()
{
    //decrease the health by 10
     playerHealth=playerHealth-10;

   //calling of a method
     healthChecker();

}


//method to check health level and vary the color of health displayed
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
        //Message box is set up
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game over");
        msgBox.setText("Game over.Do you like to replay?");
        msgBox.setStandardButtons(QMessageBox::Yes);
        msgBox.addButton(QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::No);

        switch (msgBox.exec()) {
                case QMessageBox::Yes:{
                //restart the game if 'yes' is pressed
                QApplication::quit();
                QProcess::startDetached(qApp->arguments()[0],qApp->arguments());
                break;

                }
        case QMessageBox::No:{
                //quit the game if 'no' is pressed
                QApplication::quit();
                break;
        }

        }
}

}


void health::increase()
{
    //increment health by 20
    playerHealth = playerHealth+20;
    healthChecker();
}

int health::gethealth()
{
    //return health
    return playerHealth;
}
