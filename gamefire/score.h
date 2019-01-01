#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class score: public QGraphicsTextItem{

public:
    score(QGraphicsItem * parent=0);
    void increase();
    void decrease();
    void marksevaluator();
    int getscore();

private:
    int playerscore;

};



#endif // SCORE_H
