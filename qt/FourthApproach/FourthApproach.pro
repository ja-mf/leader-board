#-------------------------------------------------
#
# Project created by QtCreator 2014-07-07T11:01:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FourthApproach
TEMPLATE = app

INCLUDEPATH += "C:\Program Files (x86)\OpenNI2\Include"
LIBS += "C:\Program Files (x86)\OpenNI2\Lib\OpenNI2.lib"
INCLUDEPATH += "C:\Program Files (x86)\PrimeSense\NiTE2\Include"
LIBS += "C:\Program Files (x86)\PrimeSense\NiTE2\Lib\NiTE2.lib"

SOURCES += main.cpp\
        mainwindow.cpp \
    KinectHandler.cpp

HEADERS  += mainwindow.h \
    KinectHandler.h

FORMS    += mainwindow.ui
