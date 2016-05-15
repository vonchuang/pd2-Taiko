#include "video.h"
#include <QDebug>

Video::Video()
{
    cnt=0;
}

void Video::playEndvideo(){
    video=new QGraphicsVideoItem();
    this->setVideoOutput(video);
    video->setSize(QSize(1100,490));
    this->setMedia(QUrl::fromLocalFile("../video/endingVideo.wmv"));
    QTimer *time=new QTimer();
    QObject::connect(time,SIGNAL(timeout()),this,SLOT(countTime()));
    time->start(1000);
}

void Video::countTime(){
    cnt++;
    if(cnt>0)
        qDebug()<<cnt;
    if(cnt==63){
        cnt=0;
        this->stop();
        delete this;
    }
}
