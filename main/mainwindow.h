#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "thread.h"
#include <QMainWindow>
#include <QString>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initBox();
    void initList();
    void initFakeList();
    void show_list(QString ip,QString mac);
    void show_log(QString s);

private slots:
    void on_scanButton_clicked();
    void on_adapterBox_activated(const QString &arg1);
    void on_ipmacTable_doubleClicked(const QModelIndex &index);
    void on_fakeTable_doubleClicked(const QModelIndex &index);

    void showScanHelp();
    void showAttackHelp();
    void showPhoexina();

private:
    Ui::MainWindow *ui;
    PIP_ADAPTER_INFO ipAdapterinfo;
    bool scanflag;
    QVector<SendThread*> sdthList;
    QStandardItemModel *macmodel;
    QStandardItemModel *fakemodel;
};
#endif // MAINWINDOW_H
