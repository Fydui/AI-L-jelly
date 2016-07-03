#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtWidgets/QTextEdit>
#include <qwidget.h>
#include <QString>
#include <string>
#include <iostream>
#include <map>
#include <QtSql>
#include <QSqlQuery>
#include <qsqlquery.h>
#include <QDebug>
#include <QTextCodec>
#include <QObject>
#include "setform.h"
extern QSqlQuery query;
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
                                           //数据库操作变量 对其进行数据库操作
private slots:

    void on_pushButton_clicked();   //确定
    void on_pushButton_2_clicked(); //退出
    void on_pushButton_3_clicked(); //设置

    void User_in(); //用户输入
    //void map();     //map表
    //void showset(); //显示设置界面
    void Lsql();    //初始化数据库




private:
    Ui::MainWindow *ui;

};





#endif // MAINWINDOW_H
