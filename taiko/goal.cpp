#include "goal.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h>

Goal::Goal()
{
    tmp1=0; tmp2=0;
    f1=0;   f2=0;
    get1=0; get2=0;
    noget1=0;   get2=0;
}


void Goal::tar1(){
    if(f1==0){
        rand1=rand()%10;
        f1=1;
    }else{
        if(tmp1==rand1){
            tmp1=0; f1=0;
            target1=new Target();
            QPixmap tar;
            tar.load(":/img/target1.png");
            target1->setPixmap(tar);
            target1->setPos(981,160);
            target1->setSpeed(10);
            QObject::connect(target1,SIGNAL(rightPlace()),this,SLOT(hitGoal1()));
            QObject::connect(target1,SIGNAL(wrongPalce()),this,SLOT(nohitGoal1()));
            scene()->addItem(target1);
        }else{
            tmp1++;
        }
    }
}

void Goal::tar2(){
    if(f2==0){
        rand2=rand()%10;
        f2=1;
    }else{
        if(tmp2==rand2){
            tmp2=0; f2=0;
            target2=new Target();
            QPixmap tar;
            tar.load(":/img/target2.png");
            target2->setPixmap(tar);
            target2->setPos(981,160);
            target2->setSpeed(10);
            QObject::connect(target2,SIGNAL(rightPlace()),this,SLOT(hitGoal2()));
            QObject::connect(target2,SIGNAL(wrongPalce()),this,SLOT(nohitGoal2()));
            scene()->addItem(target2);
        }else{
            tmp2++;
        }
    }
}

void Goal::hitGoal1(){
    get1=1;
    noget1=0;
    emit score1();
}

void Goal::hitGoal2(){
    get2=1;
    noget2=0;
    emit score2();
}

void Goal::nohitGoal1(){
    noget1=1;
    get1=0;
    emit noscore1();
}

void Goal::nohitGoal2(){
    noget2=1;
    get2=0;
    emit noscore2();
}
