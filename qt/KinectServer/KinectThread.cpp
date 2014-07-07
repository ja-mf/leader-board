#include "KinectThread.h"

KinectThread::KinectThread(QObject *parent) : QThread(parent) {
    rc          = openni::STATUS_OK;
    deviceURI   = NULL;
    isConnected = false;
    action      = ACTION_NONE;
}

void KinectThread::run() {
    switch(action) {
    case ACTION_INITIALIZE:
        initialize();
        break;
    case ACTION_RUN:
        main_run();
        break;
    default:
        emit reportStatus("* Not recognized parameter for KinectThread\n");
    }
}

void KinectThread::init() {
    action = ACTION_INITIALIZE;
    this->start();
}

void KinectThread::shutdown() {
    emit enableStart(false);
    depth.destroy();
    openni::OpenNI::shutdown();
}

void KinectThread::kickStart() {
    action = ACTION_RUN;
    this->start();
}

//////////////////////////////////////////////////////
/// Acciones de hebra propia:
///
//####################################################
void KinectThread::initialize() {
    emit reportStatus("> Initializing");
    deviceURI = openni::ANY_DEVICE;

    rc = openni::OpenNI::initialize();
    emit reportStatus("> Opening...");

    rc = device.open(deviceURI);
    if(rc != openni::STATUS_OK) {
        emit reportStatus("* Error at opening Kinect");
        openni::OpenNI::shutdown();
        return;
    }

    isConnected = true;
    emit reportStatus("> Correctly connected");
    emit reportStatus("======================\n");

    if(device.getSensorInfo(openni::SENSOR_COLOR) != NULL) {
        rc = color.create(device, openni::SENSOR_COLOR);
        if(rc != openni::STATUS_OK) {
            emit reportStatus("> No pudo crear streaming color");
            return;
        }
        rc = color.start();
        if(rc != openni::STATUS_OK) {
            emit reportStatus("> No pudo iniciar streaming color");
            return;
        }
        else
            emit reportStatus("> streaming color iniciado");
    }

    if(device.getSensorInfo(openni::SENSOR_DEPTH) != NULL) {
        rc = depth.create(device, openni::SENSOR_DEPTH);
        if(rc != openni::STATUS_OK)
            emit reportStatus("> No pudo crear streaming depth");
        rc = depth.start();
        if(rc != openni::STATUS_OK)
            emit reportStatus("> No pudo iniciar streaming depth");
        else
            emit reportStatus("> streaming depth iniciado");
    }
    emit reportStatus("======================\n");

    depthVideoMode = depth.getVideoMode();
    colorVideoMode = color.getVideoMode();

    int depthW = depthVideoMode.getResolutionX();
    int depthH = depthVideoMode.getResolutionY();
    int colorW = colorVideoMode.getResolutionX();
    int colorH = colorVideoMode.getResolutionY();

    if(depthW == colorW && depthH == colorH) {
        kWidth  = depthW;
        kHeight = depthH;
        emit reportStatus("Dimensiones: "+QString::number(kWidth)+"x"+QString::number(kHeight));
    } else {
        emit reportStatus("Dimensions dont match");
    }

    img = new openni::RGB888Pixel[kWidth*kHeight];

    emit enableStart(true);
}

//####################################################
void KinectThread::main_run() {
    while(isConnected) {
        //depth.readFrame(&depthFrame);
        //msleep(1000);
        emit reportStatus("tamos listos pa obtener el esqueleto");

        isConnected = false;
    }
}
