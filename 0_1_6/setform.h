#ifndef SETFORM_H
#define SETFORM_H

#include <QtSql>
#include <QString>
#include <string>
#include <QString>
#include <QSqlQuery>
#include <QtWidgets/QTextEdit>
#include <qwidget.h>
#include <qsqlquery.h>
#include "ui_setform.h"
#include "aboutform.h"
#include "mainwindow.h"

class SetForm : public QWidget, private Ui::SetForm
{
    Q_OBJECT

public:
    explicit SetForm(QWidget *parent = 0);
    ~SetForm();


private slots:
    void on_pushButton_4_clicked(); //显示关于界面

    void on_pushButton_clicked();
    void Add_Sql();   //添加数据
    void Del_Sql();                  //删除数据
    void Show_Sql();                            //查看数据

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    SetForm* setf;
};

#endif // SETFORM_H
