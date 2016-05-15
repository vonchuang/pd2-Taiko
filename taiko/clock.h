#ifndef CLOCK_H
#define CLOCK_H
#include <QGraphicsTextItem>
#include <QTimer>
#include <QObject>

class Clock:public QGraphicsTextItem
{
    Q_OBJECT
public:
    Clock();
    int cnt;

public slots:
    void sec();
signals:
    void timeup();
    void stoptar();
};

#endif // CLOCK_H
