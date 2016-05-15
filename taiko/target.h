#ifndef TARGET_H
#define TARGET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QKeyEvent>
using namespace std;

class Target:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Target();
    void setSpeed(int s);
    int speed;
public slots:
    void move();

signals:
    void rightPlace();
    void wrongPalce();


};

#endif // TARGET_H
