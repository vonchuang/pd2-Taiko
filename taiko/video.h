#ifndef VIDEO_H
#define VIDEO_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QTimer>

class Video:public QMediaPlayer
{
    Q_OBJECT
public:
    Video();
    int cnt;
    QGraphicsVideoItem *video;
public slots:
    void playEndvideo();
    void countTime();
};

#endif // VIDEO_H
