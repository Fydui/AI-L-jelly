#include "setform.h"
#include "mainwindow.h"
extern QSqlQuery* query;

SetForm::SetForm(QWidget *parent) :
    QWidget(parent)
    //setf(new SetForm)
{
    setupUi(this);

}

SetForm::~SetForm()
{
    delete setf;
    delete query;
}

void SetForm::on_pushButton_4_clicked()
{
    AboutForm* abou = new AboutForm();
    abou->show();   //显示关于窗口
    abou->setWindowTitle(tr("关于"));
    //abou->setFixedSize(360,640); //限制窗口大小
    //abou->setWindowModality(Qt::ApplicationModal);
    //QString Path = "<img src=\":/Resource/lex.jpg\"/>";
    //Path = Path.arg(Path);
    //QString img = QString("./Resource/lex.jpg");
}

void SetForm::on_pushButton_clicked()   //确定添加
{

    Add_Sql();
}

void SetForm::Add_Sql()
{
    query = new QSqlQuery;

    //拼接添加语句
    QString Aask = this->textEdit->toPlainText();
    QString Aans = this->textEdit_2->toPlainText();

    if((Aask == "") && (Aans == ""))
            this->textBrowser->append("##请输入问答##");

    else if(Aask == "")
            this->textBrowser->append("##请输入问题##");

    else if(Aans == "")
            this->textBrowser->append("##请输入回答##");
    else{

        QString Asqq = "INSERT INTO LAI VALUES(NULL,'";
        QString Asqz = "','";
        QString Asqm = "')";
        QString Asq_a = Asqq+Aask+Asqz+Aans+Asqm;

        query->exec(Asq_a);
        query->exec("SELECT * FROM LAI ORDER BY ID ASC");
        this->textBrowser->append("##报告~添加成功##");
        this->textEdit->clear();
        this->textEdit_2->clear();

    }

}

void SetForm::on_pushButton_5_clicked()
{
    //QString ask = setf->textEdit_2->toPlainText();
    Del_Sql();
}

void SetForm::Del_Sql()
{
    QString ask = this->textEdit->toPlainText();
    query = new QSqlQuery;
    if(ask == "")
    {
        this->textBrowser->append("##请输入问题,不必输入回答##");
    }
    else{

        //拼接删除语句
        QString Delq = "SELECT * FROM LAI WHERE ASK LIKE '";
        QString Delm = "%'";
        QString Dask_d = Delq+ask+Delm;
        query->exec(Dask_d);
        QString dele;
        while (query->next())
        {
            dele = query->value(0).toString();  //获取ID
        }


        QString Dels = "DELETE FROM LAI WHERE ID = ";   //拼接
        QString Dels_d = Dels+dele;
        query->exec(Dels_d);                            //按照id删除语句
        query->exec("SELECT * FROM LAI ORDER BY ID ASC");

        this->textBrowser->append("##报告~删除成功##");
        this->textEdit->clear();
    }

}

void SetForm::on_pushButton_2_clicked()
{
    Show_Sql();
}

void SetForm::Show_Sql()
{
    query = new QSqlQuery;
    query->exec("SELECT * FROM LAI ORDER BY ID ASC");
    QString Q = "\n问: ";
    QString A = "答: ";
    while(query->next())
    {
        QString sak = query->value(1).toString();
        QString answer = query->value(2).toString();

        sak = Q+sak+"\n";
        this->textBrowser->append(sak);

        answer = A+answer+"\n";
        this->textBrowser->append(answer);

    }

    this->textBrowser->append("##报告~输出完成##");

}

void SetForm::on_pushButton_3_clicked()
{
    close();
}

