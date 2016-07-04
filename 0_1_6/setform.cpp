#include "setform.h"
extern QSqlQuery query;

SetForm::SetForm(QWidget *parent) :
    QWidget(parent)
    //setf(new SetForm)
{
    setupUi(this);

}

SetForm::~SetForm()
{
   delete setf;
}

void SetForm::on_pushButton_4_clicked()
{
    AboutForm* abou = new AboutForm();
    abou->show();   //显示关于窗口
    abou->setWindowTitle(tr("关于"));
    abou->setFixedSize(360,640); //限制窗口大小
    abou->setWindowModality(Qt::ApplicationModal);
}

void SetForm::on_pushButton_clicked()   //确定添加
{
    //string ask = setf->textEdit->toPlainText().toStdString();
    //string answer = setf->textEdit_2->toPlainText().toStdString();
    Add_Sql();
}

void SetForm::Add_Sql()
{

    //拼接添加语句
    QString Aask = this->textEdit->toPlainText();
    QString Aans = this->textEdit_2->toPlainText();
    QString Asqq = "INSERT INTO LAI VALUES(NULL,'";
    QString Asqz = "','";
    QString Asqm = "')";
    QString Asq_a = Asqq+Aask+Asqz+Aans+Asqm;

    query.exec(Asq_a);
    query.exec("SELECT * FROM LAI ORDER BY ID ASC");
    this->textBrowser->append("##报告~添加成功##");
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

    this->textBrowser->append("##报告~删除成功##");
}

void SetForm::on_pushButton_2_clicked()
{
    Show_Sql();
}

void SetForm::Show_Sql()
{
    //query.exec("SELECT * FROM LAI ORDER BY ID ASC");
    //QString Q = "\n问: ";
    //QString A = "答: ";

    while(query.next())
    {
        QString sak = query.value(1).toString();
        QString answer = query.value(2).toString();
        //this->textBrowser->setText(Q);
        this->textBrowser->append(sak);
        //this->textBrowser->setText(A);
        this->textBrowser->append(answer);

    }
    this->textBrowser->append("##报告~输出完成##");
}

void SetForm::on_pushButton_3_clicked()
{
    close();
}

