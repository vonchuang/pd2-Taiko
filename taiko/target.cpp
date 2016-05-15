#include "target.h"
#include "goal.h"
#include "score.h"
#include <QTimer>
#include <QDebug>
#include <QList>
#include <typeinfo>


Target::Target()
{
    speed=0;
    QTimer *timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

}

void Target::move(){

    //move
    setPos(x()-speed,y());

    //check place
    if(pos().x()<1){
        scene()->removeItem(this);
        delete this;
    }else if(pos().x()<10){
        emit wrongPalce();
    }else if(pos().x()<50){
        emit rightPlace();
    }

}

void Target::setSpeed(int s){
    speed=s;
}

