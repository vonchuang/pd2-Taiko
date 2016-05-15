#include "score.h"
#include <QFont>

Score::Score()
{
    score=0;
    check=0;
    setPlainText(QString("Score: ")+QString::number(score));
    setFont(QFont("times",18));
    QObject::connect(this,SIGNAL(hor()),this,SLOT(addhorse()));
}

void Score::increase(){
    check=1;
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
    emit hor();
}

int Score::getScore(){
    return score;
}

void Score::addhorse(){
    hourse=new Hourse();
    scene()->addItem(hourse);
}
