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
    ////////////////////////////////////////////////////////////////////////
    /// NiTE INITIALIZATION:                                             ///
    ////////////////////////////////////////////////////////////////////////
    //----------------------------------------------------------------------
    cout << "Initializing NiTE...";
    emit enviarInfo("Initializing NiTE...");
    if(nite::NiTE::initialize() != nite::STATUS_OK) {
        cout << "Failed" << endl;
        emit enviarInfo("Failed");
        return;
    }
    cout << "OK" << endl;
    emit enviarInfo("OK");
    pHandTracker = new nite::HandTracker;
    //----------------------------------------------------------------------
    cout << "Creating Hand Tracker...";
    emit enviarInfo("Creating Hand Tracker...");
    if(pHandTracker->create() != nite::STATUS_OK) {
        cout << "Failed" << endl;
        emit enviarInfo("Failed");
        return;
    }
    cout << "OK" << endl;
    emit enviarInfo("OK");
    QString json_stream;

    cout << "Setting Gesture Detection...";
    emit enviarInfo("Setting Gesture Detection...");
    if(pHandTracker->startGestureDetection(nite::GESTURE_HAND_RAISE) != nite::STATUS_OK) {
        cout << "Failed" << endl;
        emit enviarInfo("Failed");
        return;
    }
    cout << "OK" << endl;
    emit enviarInfo("OK");

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
            if(i==0) {
                json_stream.append("{ ");
            } else {
                json_stream.append(", { ");
            }

            if(i<g_nHandsCount) {
                const nite::HandData& handData = hands[i];
                if(handData.isTracking()) {
                    float x, y;
                    pHandTracker->convertHandCoordinatesToDepth(
                                handData.getPosition().x,
                                handData.getPosition().y,
                                handData.getPosition().z, &x, &y);
                    json_stream.append("\"n\": "+
                                       QString::number(i)+", \"x\": "+
                                       QString::number(x)+", \"y\": "+
                                       QString::number(y)+", \"z\": null}");
                    //cout << "{" << i << "," << handData.getPosition().x << "," << handData.getPosition().y << "," << handData.getPosition().z << "}" << endl;
                    //cout << g_nHandsCount << "|" << i << ": X: " << handData.getPosition().x << ", Y: " << handData.getPosition().y << ", Z: " << handData.getPosition().z << endl;
                } else {
                    json_stream.append("\"n\": "+
                                       QString::number(i)+
                                       ", \"x\": null, \"y\": null, \"z\": null}");
                }
            } else {
                json_stream.append("\"n\": "+
                                   QString::number(i)+
                                   ", \"x\": null, \"y\": null, \"z\": null}");
                //cout << "{ \"n\": " << i << ",null,null,NULL}" << endl;
            }

            if(i==3) {
                json_stream.append("]");
                //cout << json_stream.toStdString() << endl;
                //cout << "]" << endl;
            }
        }
        //###############
        // ENVIAR!!!!:
        emit enviarInfo(json_stream);
    }//fin while

//    int i=0;
//    while(true) {
//        cout << "chao" << endl;
//        i++;
//        msleep(33);
//    }
}
