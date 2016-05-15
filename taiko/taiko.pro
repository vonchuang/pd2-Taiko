#-------------------------------------------------
#
# Project created by QtCreator 2016-05-02T23:05:27
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    target.cpp \
    score.cpp \
    clock.cpp \
    goal.cpp \
    hourse.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    target.h \
    score.h \
    clock.h \
    goal.h \
    hourse.h

FORMS    += mainwindow.ui

RESOURCES += \
    img/img.qrc \
    img/hourse/hourse.qrc \
    img/bg/bg.qrc \
    sound/sound.qrc
