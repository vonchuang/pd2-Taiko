#include "hourse.h"

Hourse::Hourse()
{
    cnt=0;
    x=0;
    //horses
    QTimer *time=new QTimer();
    hor[0].load(":/img/hourse/hourse1.png");
    hor[1].load(":/img/hourse/hourse2.png");
    hor[2].load(":/img/hourse/hourse3.png");
    hor[3].load(":/img/hourse/hourse4.png");
    hor[4].load(":/img/hourse/hourse5.png");
    hor[5].load(":/img/hourse/hourse6.png");
    hor[6].load(":/img/hourse/hourse7.png");
    hor[7].load(":/img/hourse/hourse8.png");
    hor[8].load(":/img/hourse/hourse9.png");
    hor[9].load(":/img/hourse/hourse10.png");
    hor[10].load(":/img/hourse/hourse11.png");
    hor[11].load(":/img/hourse/hourse12.png");
    hor[12].load(":/img/hourse/hourse13.png");
    hor[13].load(":/img/hourse/hourse14.png");
    hor[14].load(":/img/hourse/hourse15.png");

    hor[0]=hor[0].scaled(hor[0].width()/2,hor[0].height()/2,Qt::KeepAspectRatio);
    hor[1]=hor[1].scaled(hor[1].width()/2,hor[1].height()/2,Qt::KeepAspectRatio);
    hor[2]=hor[2].scaled(hor[2].width()/2,hor[2].height()/2,Qt::KeepAspectRatio);
    hor[3]=hor[3].scaled(hor[3].width()/2,hor[3].height()/2,Qt::KeepAspectRatio);
    hor[4]=hor[4].scaled(hor[4].width()/2,hor[4].height()/2,Qt::KeepAspectRatio);
    hor[5]=hor[5].scaled(hor[5].width()/2,hor[5].height()/2,Qt::KeepAspectRatio);
    hor[6]=hor[6].scaled(hor[6].width()/2,hor[6].height()/2,Qt::KeepAspectRatio);
    hor[7]=hor[7].scaled(hor[7].width()/2,hor[7].height()/2,Qt::KeepAspectRatio);
    hor[8]=hor[8].scaled(hor[8].width()/2,hor[8].height()/2,Qt::KeepAspectRatio);
    hor[9]=hor[9].scaled(hor[9].width()/2,hor[9].height()/2,Qt::KeepAspectRatio);
    hor[10]=hor[10].scaled(hor[10].width()/2,hor[10].height()/2,Qt::KeepAspectRatio);
    hor[11]=hor[11].scaled(hor[11].width()/2,hor[11].height()/2,Qt::KeepAspectRatio);
    hor[12]=hor[12].scaled(hor[12].width()/2,hor[12].height()/2,Qt::KeepAspectRatio);
    hor[13]=hor[13].scaled(hor[13].width()/2,hor[13].height()/2,Qt::KeepAspectRatio);
    hor[14]=hor[14].scaled(hor[14].width()/2,hor[14].height()/2,Qt::KeepAspectRatio);


    QObject::connect(time,SIGNAL(timeout()),this,SLOT(Horse()));
    time->start(100);
    this->setPos(x,300);
    this->setPixmap(hor[0]);

}

void Hourse::Horse(){
    this->setPixmap(hor[cnt]);
    this->setPos(x,300);
    cnt++;
    x=x+15;
    if(cnt==15) cnt=0;
    if(x>990){
        scene()->removeItem(this);
        delete this;
    }
}

