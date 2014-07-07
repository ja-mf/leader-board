#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    khandler = new KinectHandler;
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionConnect_Kinect_triggered() {
    cout << "abriendo kinect" << endl;
    khandler->init();
}
