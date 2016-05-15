#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "hourse.h"

class Score:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score();

    void increase();
    int getScore();
    Hourse *hourse;
    int check;
public slots:
    void addhorse();
signals:
    void hor();
private:
    int score;
};

#endif // SCORE_H
