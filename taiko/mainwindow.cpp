#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new Scene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFixedSize(995,500);
    scene->setSceneRect(0,0,981,490);  //??
    setBg(0);
    ui->graphicsView->show();
    QObject::connect(scene,SIGNAL(pressExit()),this,SLOT(close()));

    //endVideo
    checkVideoConnect=1;
    checkVidoeAdd=0;
    player=new QMediaPlayer();
    endvideo=new QGraphicsVideoItem();
    player->setVideoOutput(endvideo);
    endvideo->setSize(QSize(600,500));
    endvideo->setOffset(QPoint(200,55));
    player->setMedia(QUrl::fromLocalFile("../video/endingVideo.wmv"));
    QObject::connect(scene,SIGNAL(playEndVideo()),this,SLOT(playEndvideo()));

    //beginVideo
    player1=new QMediaPlayer();
    beginvideo=new QGraphicsVideoItem();
    player1->setVideoOutput(beginvideo);
    beginvideo->setSize(QSize(600,500));
    beginvideo->setOffset(QPoint(180,35));
    player1->setMedia(QUrl::fromLocalFile("../video/beginVideo.wmv"));
    QObject::connect(scene,SIGNAL(pressStart()),this,SLOT(playBeginVideo()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBg(int x_start){
    QImage bg;
    bg.load(":/img/begin.jpg");
    bg=bg.scaled(981,490);
    scene->setBackgroundBrush(bg);
    scene->Init(x_start);

}

void MainWindow::playEndvideo(){

   if(checkVidoeAdd==0){
        ui->graphicsView->scene()->addItem(endvideo);
        player->play();
        checkVidoeAdd=1;
        scene->screenMode=1;
        QObject::connect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stopEndVideo()));
    }
    if(checkVideoConnect==0){
        checkVideoConnect=1;
    }

}

void MainWindow::stopEndVideo(){
    if(scene->timeupCheck==1){
        scene->timeupCheck=0;
        scene->screenMode=0;
        player->stop();
        ui->graphicsView->scene()->removeItem(endvideo);
        QObject::disconnect(player,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stopEndVideo()));
        checkVideoConnect=0;
        checkVidoeAdd=0;
    }
}

void MainWindow::playBeginVideo(){
    ui->graphicsView->scene()->addItem(beginvideo);
    player1->play();
    QObject::connect(player1,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stopBeginVideo()));
    scene->playTimes=1;
}

void MainWindow::stopBeginVideo(){
    player1->stop();
    ui->graphicsView->scene()->removeItem(beginvideo);
    QObject::disconnect(player1,SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(stopBeginVideo()));
    scene->bgChange();
}
