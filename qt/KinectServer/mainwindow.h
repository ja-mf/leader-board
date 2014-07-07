#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "KinectThread.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow*    ui;

    KinectThread*      kThread;

public slots:
    void on_actionConnect_Kinect_triggered();
    void on_actionDisconnect_Kinect_triggered();
    void on_start_buttom_clicked();

    void appendLogStatus(QString);
    void enableStart(bool);
};

#endif // MAINWINDOW_H
