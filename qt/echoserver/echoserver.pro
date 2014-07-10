QT       += core websockets
QT       -= gui

TARGET = echoserver
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    echoserver.cpp \
    GenInfo.cpp

HEADERS += \
    echoserver.h \
    GenInfo.h

OTHER_FILES += echoclient.html