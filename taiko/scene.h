#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QSound>
#include <QObject>
#include "btn.h"
#include "target.h"
#include "score.h"
#include "clock.h"
#include "goal.h"
#include "hourse.h"

class Scene: public QGraphicsScene
{
    Q_OBJECT
public:
    //function
    Scene(QObject *parent= 0);  //???
    void Init(int x_strt);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void bgChange();
    void keyPressEvent(QKeyEvent *event);
    void gameBGChange();

    //button
    Btn *btn_start;
    Btn *btn_exit;
    Btn *btn_restart;
    int btn_w;
    int btn_h;

    //game
    Clock *time;
    Goal *goal;
    Goal *hint1;
    Goal *hint2;
    Goal *trail;
    QGraphicsPixmapItem *gameBG[10];
    int cntBG;
    int cnt,add;
    int change;

    //timer
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timerBG;
    int timeupCheck;


    //scene
    int screenMode;

    //scene boundary
    int leftBound;
    int rightBound;

    //score
    Score *score;

    //sound
    QSound *bgm;
    QSound *bang;

    //restare
    int checkRestart;
    int playTimes;

public slots:
    void timeupSlot();
    void stoptar1();
    void stoptar2();
    void changeBG();

signals:
    void timeupSignal();
    void pressExit();
    void pressStart();
    void playEndVideo();

};

#endif // SCENE_H
