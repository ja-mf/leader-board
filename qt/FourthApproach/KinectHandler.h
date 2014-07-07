#ifndef KINECTHANDLER_H
#define KINECTHANDLER_H

#include <iostream>
#include <string>
#include <NiTE.h>

using namespace std;

class KinectHandler
{
public:
    KinectHandler();

    void init();

private:
    openni::Status      rc;
    openni::Device      device;
    openni::VideoStream depth, color;
    const char*         deviceURI;
};

#endif // KINECTHANDLER_H

