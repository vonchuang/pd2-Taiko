#include "scene.h"
#include <QDebug>
#include <stdlib.h>
#include <QTimer>
#include <QDir>

Scene::Scene(QObject *parent)
{
    checkRestart=0;
    screenMode=0;
    timeupCheck=0;
    playTimes=0;
}

void Scene::Init(int x_start){
    //path
    QDir dir;
    QString s;
    s=dir.currentPath();
    qDebug()<<s;
    //start
    btn_start=new Btn();
    QPixmap start;
    start.load(":/img/start.png");
    start=start.scaled((start.width()*3)/2,(start.height()*3)/2,Qt::KeepAspectRatio);   //150*60
    btn_w=(start.width()*3)/2-60;   //
    btn_h=(start.height()*3)/2-30;
    btn_start->setPixmap(start);
    btn_start->setPos(250,390);
    addItem(btn_start);

    //exit
    btn_exit=new Btn();
    QPixmap exit1;
    exit1.load(":/img/exit.png");
    exit1=exit1.scaled((exit1.width()*3)/2,(exit1.height()*3)/2,Qt::KeepAspectRatio);
    btn_exit->setPixmap(exit1);
    btn_exit->setPos(500,390);
    addItem(btn_exit);

    //set boundary
    leftBound=x_start;
    rightBound=x_start+981;



}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(screenMode==0){  //beginning page
        //press start
        if(event->scenePos().x()>btn_start->pos().x() && event->scenePos().x()<=btn_start->pos().x()+btn_w){
            if(event->scenePos().y()>btn_start->pos().y() && event->scenePos().y()<=btn_start->pos().y()+btn_h){
                screenMode=1;
                if(playTimes==0){
                    emit pressStart();
                }else{
                    bgChange();
                }
            }
        }
        //press exit
        if(event->scenePos().x()>btn_exit->pos().x() && event->scenePos().x()<=btn_exit->pos().x()+btn_w){
            if(event->scenePos().y()>btn_exit->pos().y() && event->scenePos().y()<=btn_exit->pos().y()+btn_h){

                emit pressExit();
            }
        }
    }
    else if(screenMode==1){ //game page.

    }
}


void Scene::bgChange(){
    //check restart
    if(checkRestart==1){
        this->removeItem(score);
        checkRestart=0;
    }
    //background
    QImage bg;
    bg.load(":/img/game.jpg");
    bg=bg.scaled(981,490);
    this->setBackgroundBrush(bg);
    this->removeItem(btn_start);
    this->removeItem(btn_exit);

    gameBGChange();

    //time
    time=new Clock;
    timer=new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),time,SLOT(sec()));
    QObject::connect(time,SIGNAL(timeup()),this,SLOT(timeupSlot()));
    timer->start(1000);
    this->addItem(time);


    //score
    score=new Score;
    this->addItem(score);


    //goal
    QPixmap goa,hin1,hin2,tra;
    goal=new Goal();
    goa.load(":/img/goal.png");
    goa=goa.scaled(goa.width()/3,goa.height()/3,Qt::KeepAspectRatio);
    goal->setPixmap(goa);
    goal->setPos(10,160);
    this->addItem(goal);

    //trail
    trail=new Goal();
    tra.load(":/img/trail.png");
    trail->setPixmap(tra);
    trail->setPos(0,190);
    this->addItem(trail);

    //hint
    hint1=new Goal();
    hin1.load(":/img/hint1.png");
    hint1->setPixmap(hin1);
    hint1->setPos(700,10);
    this->addItem(hint1);

    hint2=new Goal();
    hin2.load(":/img/hint2.png");
    hint2->setPixmap(hin2);
    hint2->setPos(700,60);
    this->addItem(hint2);

    //target
    timer1=new QTimer(this);
    QObject::connect(timer1,SIGNAL(timeout()),goal,SLOT(tar1()));
    QObject::connect(time,SIGNAL(stoptar()),this,SLOT(stoptar1()));
    timer1->start(200);

    timer2=new QTimer(this);
    QObject::connect(timer2,SIGNAL(timeout()),goal,SLOT(tar2()));
    QObject::connect(time,SIGNAL(stoptar()),this,SLOT(stoptar2()));
    timer2->start(300);

    //bgm
    bgm=new QSound(":/sound/bgm.wav");
    bang=new QSound(":/sound/bang.wav");
    bgm->play();


}

void Scene::keyPressEvent(QKeyEvent *event){

    //press 's' -> target1
    if(event->key()==0x53){
        //animation...
        if(goal->get1==1 && goal->noget1==0){
            //shoot target1
            this->score->increase();
            bang->play();
            goal->get1=0;
        }
    }
    //press 'f' ->target2

    else if(event->key()==0x46){
        //animation...
        if(goal->get2==1 && goal->noget2==0){
            //shoot target2
            this->score->increase();
            bang->play();
            goal->get2=0;
        }
    }
}

void Scene::timeupSlot(){
    //gameover background
    screenMode=0;
    QImage bg;
    bg.load(":/img/gameoverbg.jpg");
    bg=bg.scaled(981,490,Qt::KeepAspectRatio);
    this->setBackgroundBrush(bg);

    //restart button
    QPixmap restart;
    restart.load(":/img/restart.png");
    restart=restart.scaled((restart.width()*3)/2,(restart.height()*3)/2,Qt::KeepAspectRatio);   //150*60
    btn_w=(restart.width()*3)/2-60;   //
    btn_h=(restart.height()*3)/2-30;
    btn_start->setPixmap(restart);
    btn_start->setPos(250,390);
    addItem(btn_start);

    //exit button
    QPixmap exit1;
    exit1.load(":/img/exit.png");
    exit1=exit1.scaled((exit1.width()*3)/2,(exit1.height()*3)/2,Qt::KeepAspectRatio);
    btn_exit->setPixmap(exit1);
    btn_exit->setPos(500,390);
    addItem(btn_exit);

    //reset
    checkRestart=1;
    QObject::disconnect(time,SIGNAL(timeup()),this,SLOT(timeupSlot()));
    QObject::disconnect(timer1,SIGNAL(timeout()),goal,SLOT(tar1()));
    QObject::disconnect(timer2,SIGNAL(timeout()),goal,SLOT(tar2()));
    this->removeItem(goal);
    this->removeItem(time);
    this->removeItem(hint1);
    this->removeItem(hint2);
    this->removeItem(trail);
    for(int i=0;i<10;++i){
        this->removeItem(gameBG[i]);
    }
    QObject::disconnect(timerBG,SIGNAL(timeout()),this,SLOT(changeBG()));
    bgm->stop();

    //score
    score->setX(400);
    score->setY(50);
    score->setFont(QFont("bold",30));

    timeupCheck=1;
    score->check=0;
    emit playEndVideo();


}

void Scene::stoptar1(){
    QObject::disconnect(timer1,SIGNAL(timeout()),goal,SLOT(tar1()));
    QObject::disconnect(time,SIGNAL(stoptar()),this,SLOT(stoptar1()));
}

void Scene::stoptar2(){
    QObject::disconnect(timer2,SIGNAL(timeout()),goal,SLOT(tar2()));
    QObject::disconnect(time,SIGNAL(stoptar()),this,SLOT(stoptar2()));
}

void Scene::gameBGChange(){
    int i;
    add=0;
    cntBG=0;
    cnt=990;
    change=990;
    for(i=0;i<10;++i){
        gameBG[i]=new QGraphicsPixmapItem;
    }
    timerBG=new QTimer();
    QPixmap bg[10];

    bg[0].load(":/img/bg/bg1.png");
    bg[1].load(":/img/bg/bg2.png");
    bg[2].load(":/img/bg/bg3.png");
    bg[3].load(":/img/bg/bg4.png");
    bg[4].load(":/img/bg/bg5.png");
    bg[5].load(":/img/bg/bg6.png");
    bg[6].load(":/img/bg/bg7.png");
    bg[7].load(":/img/bg/bg8.png");
    bg[8].load(":/img/bg/bg9.png");
    bg[9].load(":/img/bg/bg10.png");

    for(int i=0;i<10;++i){
        bg[i]=bg[i].scaled(1010,500);
        gameBG[i]->setPixmap(bg[i]);
        gameBG[i]->setPos(990,0);
        this->addItem(gameBG[i]);
    }

    QObject::connect(timerBG,SIGNAL(timeout()),this,SLOT(changeBG()));
    timerBG->start(100);   //100
}

void Scene::changeBG(){
    if(score->check==1){
    gameBG[cntBG]->setPos(change,0);
    change-=10;
    if(gameBG[cntBG]->pos().x()==0){
        if(cntBG<9){
            //next
            add=1;
            cntBG++;
            change=990;

        }else if(cntBG==9){
            gameBG[9]->setPos(0,0);
            QObject::disconnect(timerBG,SIGNAL(timeout()),this,SLOT(changeBG()));
            timerBG->stop();
            cntBG=0;
        }
    }

    //current
    if(cntBG>0 && add==1){
        if(cnt>0){
            cnt-=10;
            gameBG[cntBG-1]->setPos(cnt-980,0);
        }else if(cnt==0){
            this->removeItem(gameBG[cntBG-1]);
            add=0;
            cnt=980;
        }
    }else if(cntBG==0 && add==1){
        if(cnt>0){
            cnt-=9;
            gameBG[0]->setPos(cnt-988,0);
        }else if(cnt==0){
            this->removeItem(gameBG[0]);
            add=0;
            cnt=980;
        }
    }
    }

}
