#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T13:32:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KinectServer
TEMPLATE = app

INCLUDEPATH += "C:\Program Files (x86)\OpenNI2\Include"
LIBS += "C:\Program Files (x86)\OpenNI2\Lib\OpenNI2.lib"
INCLUDEPATH += "C:\Program Files (x86)\PrimeSense\NiTE2\Include"
LIBS += "C:\Program Files (x86)\PrimeSense\NiTE2\Lib\NiTE2.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
    KinectThread.cpp

HEADERS  += mainwindow.h \
    KinectThread.h

FORMS    += mainwindow.ui
