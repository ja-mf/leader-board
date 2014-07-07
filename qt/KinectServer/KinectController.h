#ifndef KINECTCONTROLLER_H
#define KINECTCONTROLLER_H

#include <iostream>
#include <NiTE.h>

using namespace std;

class KinectController {
public:
    KinectController();

    void init();

private:
    openni::Status rc;
};

#endif // KINECTCONTROLLER_H
