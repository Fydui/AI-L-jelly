#include "setform.h"
#include "aboutform.h"
#include "mainwindow.h"
using namespace std;
extern QSqlQuery query;
SetForm::SetForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void SetForm::on_pushButton_3_clicked()
{
    AboutForm* abou = new AboutForm();
    abou->show();   //显示关于窗口
    abou->setWindowTitle(tr("关于"));
    abou->setFixedSize(360,640); //限制窗口大小
    abou->setWindowModality(Qt::ApplicationModal);
}


void SetForm::on_pushButton_4_clicked()
{
    setf->textBrowser_3->clear();
    close();
}

void SetForm::on_pushButton_clicked()
{
    QString ask = setf->textEdit->toPlainText();
    QString answer = setf->textEdit_2->toPlainText();
    Add_Sql(ask,answer);

}

void SetForm::Add_Sql(QString Ask, QString Answer)
{
    //拼接添加语句
    QString Aask = Ask;
    QString Aans = Answer;
    QString Asqq = "INSERT INTO LAI VALUES(NULL,'";
    QString Asqz = "','";
    QString Asqm = "')";
    QString Asq_a = Asqq+Aask+Asqz+Aans+Asqm;
    //query.exec(Asq_a);
    query.exec(Asq_a);
    query.exec("SELECT * FROM LAI ORDER BY ID ASC");
    setf->textBrowser_3->append("##报告~添加成功##");
}

void SetForm::on_pushButton_5_clicked()
{
    QString ask = setf->textEdit_2->toPlainText();
    Del_Sql(ask);
}

void SetForm::Del_Sql(QString Ask)
{
    //拼接删除语句
    QString Dask = Ask;
    QString Delq = "SELECT * FROM LAI WHERE ASK LIKE '";
    QString Delm = "%'";
    QString Dask_d = Delq+Dask+Delm;
    query.exec(Dask_d);
    QString dele;
    while (query.next())
    {
        dele = query.value(0).toString();
    }
    QString Dels = "DELETE FROM LAI WHERE ID = ";
    QString Dels_d = Dels+dele;
    query.exec(Dels_d);
    query.exec("SELECT * FROM LAI ORDER BY ID ASC");

    setf->textBrowser_3->append("##报告~删除成功##");
}

void SetForm::on_pushButton_2_clicked()
{
    Show_Sql();
}

void SetForm::Show_Sql()
{
    query.exec("SELECT * FROM LAI ORDER BY ID ASC");
    QString Q = "\n问: ";
    QString A = "答: ";
    while(query.next())
    {
        QString sak = query.value(1).toString();
        QString answer = query.value(2).toString();
        setf->textBrowser_3->setText(Q);
        setf->textBrowser_3->append(sak);
        setf->textBrowser_3->setText(A);
        setf->textBrowser_3->append(answer);

    }
    setf->textBrowser_3->append("##报告~输出完成##");
}
