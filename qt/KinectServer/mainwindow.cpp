#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    kThread = new KinectThread(this);
    connect(kThread, SIGNAL(reportStatus(QString)), this, SLOT(appendLogStatus(QString)));
    connect(kThread, SIGNAL(enableStart(bool)), this, SLOT(enableStart(bool)));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_actionConnect_Kinect_triggered() {
    kThread->init();
}

void MainWindow::on_actionDisconnect_Kinect_triggered() {
    kThread->shutdown();
}

void MainWindow::on_start_buttom_clicked() {
    kThread->kickStart();
}

void MainWindow::appendLogStatus(QString info) {
    ui->logger->appendPlainText(info);
}

void MainWindow::enableStart(bool flag) {
    ui->start_buttom->setEnabled(flag);
}
