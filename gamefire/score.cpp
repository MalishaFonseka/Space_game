#include "score.h"
#include <QFont>
#include <QMessageBox>
#include <QApplication>
#include <QProcess>

score::score(QGraphicsItem *parent) : QGraphicsTextItem (parent)
{
    //initialization of playerscore
    playerscore=0;

    //playerscore is displayed
    setPlainText(QString("Score :")+QString::number(playerscore)+QString("/300"));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",12));

}


void score::marksevaluator(){
    //condition to change the color of the text based on the score
    if(playerscore>0&&playerscore<100){
     setDefaultTextColor(Qt::white);
     setPlainText(QString("Score :")+QString::number(playerscore)+QString("/300"));
    }else if(playerscore>100&&playerscore<200){
        setDefaultTextColor(Qt::yellow);
        setPlainText(QString("Score :")+QString::number(playerscore)+QString("/300"));
    }else if(playerscore>200&&playerscore<=300){
        setDefaultTextColor(Qt::green);
        setPlainText(QString("Score :")+QString::number(playerscore)+QString("/300"));

    }else if(playerscore>300){
        QMessageBox msgBox;
        msgBox.setWindowTitle("Game finish");
        msgBox.setText("Congratulations!!!\n You have won the game\n Want to play again?");
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

void score::increase()
{
    //increases the player's score from 10
    playerscore=playerscore+10;
    marksevaluator();
}

void score::decrease()
{
      //decreases the player's score from 5
    playerscore=playerscore-5;
    marksevaluator();
}

int score::getscore()
{
      //ireturns the score
    return playerscore;
}
