#ifndef GOAL_H
#define GOAL_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include "target.h"
using namespace std;

class Goal:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Goal();
    Target *target1;
    Target *target2;
    int tmp1,tmp2;
    int rand1,rand2;
    int f1,f2;
    int get1,get2;
    int noget1,noget2;

public slots:
    void tar1();
    void tar2();
    void hitGoal1();
    void hitGoal2();
    void nohitGoal1();
    void nohitGoal2();

signals:
    void score1();
    void score2();
    void noscore1();
    void noscore2();

};
#endif // GOAL_H
