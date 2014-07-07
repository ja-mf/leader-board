#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>

#include "KinectHandler.h"

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
    Ui::MainWindow* ui;

    KinectHandler*  khandler;

public slots:
    void on_actionConnect_Kinect_triggered();
};

#endif // MAINWINDOW_H
