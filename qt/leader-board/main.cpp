#include <iostream>
#include <NiTE.h>
#include <iostream>

using namespace std;

int main()
{
    nite::HandTracker*        pHandTracker;
    nite::HandTrackerFrameRef handFrame;
    nite::NiTE::initialize();
    pHandTracker = new nite::HandTracker;
    pHandTracker->create();

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

        cout << "[";
        for(int i=0; i<4; i++) {
            if(i<g_nHandsCount) {
                const nite::HandData& handData = hands[i];
                if(handData.isTracking()) {
                    float x, y;
                    pHandTracker->convertHandCoordinatesToDepth(
                                handData.getPosition().x,
                                handData.getPosition().y,
                                handData.getPosition().z, &x, &y);
                    cout << "{" << i << "," << handData.getPosition().x << "," << handData.getPosition().y << "," << handData.getPosition().z << "}" << endl;
                    //cout << g_nHandsCount << "|" << i << ": X: " << handData.getPosition().x << ", Y: " << handData.getPosition().y << ", Z: " << handData.getPosition().z << endl;

                }
            } else {
                cout << "{" << i << ",NULL,NULL,NULL}" << endl;
            }

            if(i<3)
                cout << ",";
            else
                cout << "]" << endl;
        }
    }//fin while

    return 0;
}

