/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect_Kinect;
    QAction *actionDisconnect_Kinect;
    QWidget *centralWidget;
    QPlainTextEdit *logger;
    QLabel *label;
    QLabel *screen;
    QPushButton *start_buttom;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(930, 520);
        MainWindow->setMinimumSize(QSize(930, 520));
        MainWindow->setMaximumSize(QSize(930, 520));
        actionConnect_Kinect = new QAction(MainWindow);
        actionConnect_Kinect->setObjectName(QStringLiteral("actionConnect_Kinect"));
        actionDisconnect_Kinect = new QAction(MainWindow);
        actionDisconnect_Kinect->setObjectName(QStringLiteral("actionDisconnect_Kinect"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        logger = new QPlainTextEdit(centralWidget);
        logger->setObjectName(QStringLiteral("logger"));
        logger->setGeometry(QRect(3, 50, 271, 441));
        logger->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        logger->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        logger->setReadOnly(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(7, 30, 46, 13));
        screen = new QLabel(centralWidget);
        screen->setObjectName(QStringLiteral("screen"));
        screen->setGeometry(QRect(280, 10, 640, 480));
        screen->setFrameShape(QFrame::Box);
        screen->setAlignment(Qt::AlignCenter);
        start_buttom = new QPushButton(centralWidget);
        start_buttom->setObjectName(QStringLiteral("start_buttom"));
        start_buttom->setEnabled(false);
        start_buttom->setGeometry(QRect(190, 10, 75, 23));
        start_buttom->setCheckable(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 930, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionConnect_Kinect);
        menuFile->addAction(actionDisconnect_Kinect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionConnect_Kinect->setText(QApplication::translate("MainWindow", "Connect Kinect", 0));
        actionDisconnect_Kinect->setText(QApplication::translate("MainWindow", "Disconnect Kinect", 0));
        logger->setPlainText(QString());
        label->setText(QApplication::translate("MainWindow", "Log:", 0));
        screen->setText(QApplication::translate("MainWindow", "IMG", 0));
        start_buttom->setText(QApplication::translate("MainWindow", "Start", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
