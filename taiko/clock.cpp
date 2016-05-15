#include "clock.h"
#include <QTimer>
#include <QFont>
#include <QDebug>

Clock::Clock()
{
    cnt=120;
    setPlainText(QString("Time: ")+QString::number(cnt));
    setFont(QFont("times",18));
    setX(0);
    setY(30);
}

void Clock::sec(){
    if(cnt>=0){
        cnt--;
        setPlainText(QString("Time: ")+QString::number(cnt));
    }
    if(cnt<13)   emit stoptar();
    if(cnt==-1){
        emit timeup();
    }
}
