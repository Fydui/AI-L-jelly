#include "mainwindow.h"
#include <QApplication>
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动链接sqlite
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
