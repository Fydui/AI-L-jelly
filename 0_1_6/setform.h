#ifndef SETFORM_H
#define SETFORM_H

#include <QtSql>
#include <QString>
#include <string>
#include <QString>
#include <QSqlQuery>
#include <qsqlquery.h>
#include "ui_setform.h"
#include "aboutform.h"
#include "mainwindow.h"
using namespace std;


class SetForm : public QWidget, private Ui::SetForm
{
    Q_OBJECT

public:
    explicit SetForm(QWidget *parent = 0);
    //AboutForm* abou = new AboutForm();


private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
    void on_pushButton_clicked();
    void Add_Sql(QString Ask,QString Answer);   //添加数据
    void Del_Sql(QString Ask);                  //删除数据
    void Show_Sql();                            //查看数据
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();

private:
    SetForm* setf;
};

#endif // SETFORM_H
