#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <qgraphicsview.h>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QTimer>
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene;
    void setBg(int x_start);

    //video
    int checkVideoConnect;
    int checkVidoeAdd;
    QGraphicsVideoItem *endvideo,*beginvideo;
    QMediaPlayer *player,*player1;

public slots:
    void playEndvideo();
    void stopEndVideo();
    void playBeginVideo();
    void stopBeginVideo();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
