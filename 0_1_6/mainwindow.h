#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTextEdit>
#include <QString>
#include <string>
#include <iostream>
#include <map>
//#include "sqlite3.h"
//#include "sqlite3ext.h"
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

    //void Text_in();
    //void User_in();


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void User_in();
    void map();
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
