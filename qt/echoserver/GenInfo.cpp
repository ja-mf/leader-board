#include "GenInfo.h"

#include <iostream>
#include <QString>

using namespace std;

GenInfo::GenInfo(QObject *parent) : QThread(parent) {
    //pSocket = NULL;
}

void GenInfo::run() {
    nite::HandTracker*        pHandTracker;
    nite::HandTrackerFrameRef handFrame;
    nite::NiTE::initialize();
    pHandTracker = new nite::HandTracker;
    pHandTracker->create();
    QString json_stream;

    pHandTracker->startGestureDetection(nite::GESTURE_HAND_RAISE);

    // ciclo: agregar for/while
    while(true) {
        nite::Status rc = pHandTracker->readFrame(&handFrame);
        const nite::Array<nite::GestureData>& gestures = handFrame.getGestures();
        for(int i=0; i<gestures.getSize(); ++i) {
            if(gestures[i].isComplete()) {
                nite::HandId id;
                pHandTracker->startHandTracking(gestures[i].getCurrentPosition(), &id);
            }
        }

        const nite::Array<nite::HandData>& hands = handFrame.getHands();
        int g_nHandsCount = hands.getSize();

        json_stream.clear();
        json_stream.append("[");
        for(int i=0; i<4; i++) {
            if(i<g_nHandsCount) {
                const nite::HandData& handData = hands[i];
                if(handData.isTracking()) {
                    float x, y;
                    pHandTracker->convertHandCoordinatesToDepth(
                                handData.getPosition().x,
                                handData.getPosition().y,
                                handData.getPosition().z, &x, &y);
                    json_stream.append("{ \"n\": "+
                                       QString::number(i)+", \"x\": "+
                                       QString::number(handData.getPosition().x)+", \"y\": "+
                                       QString::number(handData.getPosition().y)+", \"z\": "+
                                       QString::number(handData.getPosition().z)+"}");
                    //cout << "{" << i << "," << handData.getPosition().x << "," << handData.getPosition().y << "," << handData.getPosition().z << "}" << endl;
                    //cout << g_nHandsCount << "|" << i << ": X: " << handData.getPosition().x << ", Y: " << handData.getPosition().y << ", Z: " << handData.getPosition().z << endl;
                }
            } else {
                json_stream.append("{ \"n\": "+
                                   QString::number(i)+
                                   ", \"x\": null, \"y\": null, \"z\": null}");
                //cout << "{ \"n\": " << i << ",null,null,NULL}" << endl;
            }

            if(i<3)
                json_stream.append(",");
            else {
                json_stream.append("]");

                //###############
                // ENVIAR!!!!:
                emit enviarInfo(json_stream);
                //cout << "]" << endl;
            }
        }
    }//fin while

//    int i=0;
//    while(true) {
//        cout << "chao" << endl;
//        i++;
//        msleep(33);
//    }
}
