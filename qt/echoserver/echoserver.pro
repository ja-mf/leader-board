QT       += core websockets
QT       += gui

TARGET = echoserver
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += "C:\Program Files (x86)\OpenNI2\Include"
LIBS += "C:\Program Files (x86)\OpenNI2\Lib\OpenNI2.lib"
INCLUDEPATH += "C:\Program Files (x86)\PrimeSense\NiTE2\Include"
LIBS += "C:\Program Files (x86)\PrimeSense\NiTE2\Lib\NiTE2.lib"

SOURCES += \
    main.cpp \
    echoserver.cpp \
    GenInfo.cpp

HEADERS += \
    echoserver.h \
    GenInfo.h

OTHER_FILES += echoclient.html
