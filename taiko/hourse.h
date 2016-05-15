#ifndef HOURSE_H
#define HOURSE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class Hourse:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Hourse();

    QPixmap hor[15];

public slots:
    void Horse();

private:
    int cnt;
    int x;
};

#endif // HOURSE_H
