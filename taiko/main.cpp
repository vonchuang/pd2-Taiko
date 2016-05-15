#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QDesktopWidget wid;
    int scw=981;
    int sch=490;
    wid.setGeometry((wid.screen()->width()/2)-(scw/2),(wid.screen()->height()/2)-(sch/2),scw,sch);  //???
    w.setWindowTitle("Taiko");
    w.setWindowIcon(QIcon(":/img/icon.jpg"));

    w.setMaximumWidth(981);
    w.setMaximumHeight(490);
    w.setMinimumWidth(981);
    w.setMinimumHeight(490);

    w.show();

    return a.exec();
}
