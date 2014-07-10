#include "GenInfo.h"

#include <iostream>

using namespace std;

GenInfo::GenInfo(QObject *parent) : QThread(parent) {
    //pSocket = NULL;
}

void GenInfo::run() {
    int i=0;
    while(true) {
        cout << "chao" << endl;
        i++;
        emit enviarInfo(QString::number(i));
        msleep(33);
    }
}
