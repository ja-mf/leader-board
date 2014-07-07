#include "KinectHandler.h"

KinectHandler::KinectHandler() {
    rc = openni::STATUS_OK;
}

void KinectHandler::init() {
    string info;
    deviceURI = openni::ANY_DEVICE;

    rc = openni::OpenNI::initialize();
    if(rc != openni::STATUS_OK) {
        cout << "no pudo inicializar" << endl;
        return;
    }

    info.clear();
    info.append(openni::OpenNI::getExtendedError());
    cout << "inicializado: " << info << endl;

    rc = device.open(deviceURI);
    if(rc != openni::STATUS_OK) {
        cout << "error" << endl;
        return;
    }

    cout << "conectado" << endl;
}
