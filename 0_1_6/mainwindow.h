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
#include "sqlite3.h"
#include "sqlite3ext.h"
#pragma comment(lib,"sqlite3.lib")

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
    map <QString,string> QAA;
private slots:

    void on_pushButton_clicked();   //确定
    void on_pushButton_2_clicked(); //退出
    void on_pushButton_3_clicked(); //设置

    void User_in(); //用户输入
    void map(); //map表
    void showset(); //显示设置界面

    //数据库相关 暂时用不上
    /*void Open_DB(char* sql);
    void Close_DB();
    void ExecSQL(char *sql);
    char **SrawQuery(char *sql, int *row, int *column, char **result);
    int UserResult(void *NotUsed, int argc, char **argv, char **azColName);
    SQLITE_API int Sqlite3_Open();
    int SelectUser(int bu);*/




private:
    Ui::MainWindow *ui;

};





#endif // MAINWINDOW_H
