#ifndef KINECTTHREAD_H
#define KINECTTHREAD_H

#include <QThread>
#include <iostream>
#include <NiTE.h>
#include <QString>
//#include "KinectController.h"

#define ACTION_INITIALIZE  0
#define ACTION_RUN         1
#define ACTION_NONE       -1

using namespace std;

class KinectThread : public QThread {
    Q_OBJECT
public:
    explicit KinectThread(QObject *parent = 0);

    void init();
    void shutdown();

    void kickStart();

private:
    void run();

    void initialize();
    void main_run();

    bool isConnected;
    int  action;

    openni::Status      rc;
    openni::Device      device;
    openni::VideoStream depth, color;
    openni::VideoMode   depthVideoMode;
    openni::VideoMode   colorVideoMode;
    int                 kWidth;
    int                 kHeight;
    const char*         deviceURI;

    openni::RGB888Pixel*  img;
    openni::VideoFrameRef depthFrame;
    openni::VideoFrameRef colorFrame;

signals:
    void reportStatus(QString);
    void enableStart(bool);

public slots:

};

#endif // KINECTTHREAD_H
