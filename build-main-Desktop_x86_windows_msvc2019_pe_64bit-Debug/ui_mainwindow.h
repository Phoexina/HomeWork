/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionARP_SCAN;
    QAction *actionARP_ATTACK;
    QAction *actionPhoexina;
    QWidget *centralwidget;
    QComboBox *adapterBox;
    QTableView *ipmacTable;
    QPushButton *scanButton;
    QLineEdit *fakeipText;
    QTextBrowser *logBrowser;
    QLabel *iplabel;
    QLabel *maclabel;
    QLineEdit *fakemacText;
    QTableView *fakeTable;
    QLabel *arpfakeLabel;
    QLabel *logLabel;
    QMenuBar *menubar;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1800, 1000);
        actionARP_SCAN = new QAction(MainWindow);
        actionARP_SCAN->setObjectName(QString::fromUtf8("actionARP_SCAN"));
        actionARP_ATTACK = new QAction(MainWindow);
        actionARP_ATTACK->setObjectName(QString::fromUtf8("actionARP_ATTACK"));
        actionPhoexina = new QAction(MainWindow);
        actionPhoexina->setObjectName(QString::fromUtf8("actionPhoexina"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        adapterBox = new QComboBox(centralwidget);
        adapterBox->setObjectName(QString::fromUtf8("adapterBox"));
        adapterBox->setGeometry(QRect(50, 30, 871, 111));
        ipmacTable = new QTableView(centralwidget);
        ipmacTable->setObjectName(QString::fromUtf8("ipmacTable"));
        ipmacTable->setGeometry(QRect(60, 240, 861, 321));
        scanButton = new QPushButton(centralwidget);
        scanButton->setObjectName(QString::fromUtf8("scanButton"));
        scanButton->setGeometry(QRect(60, 160, 101, 51));
        fakeipText = new QLineEdit(centralwidget);
        fakeipText->setObjectName(QString::fromUtf8("fakeipText"));
        fakeipText->setGeometry(QRect(220, 160, 311, 61));
        logBrowser = new QTextBrowser(centralwidget);
        logBrowser->setObjectName(QString::fromUtf8("logBrowser"));
        logBrowser->setGeometry(QRect(940, 60, 821, 871));
        iplabel = new QLabel(centralwidget);
        iplabel->setObjectName(QString::fromUtf8("iplabel"));
        iplabel->setGeometry(QRect(180, 160, 81, 31));
        maclabel = new QLabel(centralwidget);
        maclabel->setObjectName(QString::fromUtf8("maclabel"));
        maclabel->setGeometry(QRect(550, 160, 91, 31));
        fakemacText = new QLineEdit(centralwidget);
        fakemacText->setObjectName(QString::fromUtf8("fakemacText"));
        fakemacText->setGeometry(QRect(600, 160, 321, 61));
        fakeTable = new QTableView(centralwidget);
        fakeTable->setObjectName(QString::fromUtf8("fakeTable"));
        fakeTable->setGeometry(QRect(60, 610, 861, 321));
        arpfakeLabel = new QLabel(centralwidget);
        arpfakeLabel->setObjectName(QString::fromUtf8("arpfakeLabel"));
        arpfakeLabel->setGeometry(QRect(60, 580, 351, 31));
        logLabel = new QLabel(centralwidget);
        logLabel->setObjectName(QString::fromUtf8("logLabel"));
        logLabel->setGeometry(QRect(940, 30, 81, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1800, 21));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionARP_SCAN);
        menuHelp->addAction(actionARP_ATTACK);
        menuHelp->addSeparator();
        menuHelp->addAction(actionPhoexina);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionARP_SCAN->setText(QApplication::translate("MainWindow", "ARP SCAN", nullptr));
        actionARP_ATTACK->setText(QApplication::translate("MainWindow", "ARP ATTACK", nullptr));
        actionPhoexina->setText(QApplication::translate("MainWindow", "Phoexina 0v0", nullptr));
        scanButton->setText(QApplication::translate("MainWindow", "SCAN", nullptr));
        iplabel->setText(QApplication::translate("MainWindow", "IP:", nullptr));
        maclabel->setText(QApplication::translate("MainWindow", "MAC:", nullptr));
        arpfakeLabel->setText(QApplication::translate("MainWindow", "ARP FAKE INFO:", nullptr));
        logLabel->setText(QApplication::translate("MainWindow", "LOG", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
