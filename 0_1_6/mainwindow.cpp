#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("凉果冻"));
    QString str = "你好啊~人类0v0~";
    ui->textBrowser->append(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString O = ui->textEdit->toPlainText();
    QString x = "";
    if(O == x)
    {
        QString str = "\n你想说啥你到是说啊,喵=v=";
        ui->textBrowser->append(str);
    }
    else
    {
        //ui->textBrowser->append("ahahahh");
        User_in();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}


void MainWindow::User_in()
{
    QString O = ui->textEdit->toPlainText();    //获取用户输入
    string str = O.toStdString();

    map<string,QString>QAA;     //新建哈希表
    QString A = QAA["你好"];
    QString B = QAA["你叫啥"];
    QAA["你好啊"] = A;
    QAA["凉果冻"] = B;



    int t = 1;
    while (t) {

        map<string,QString>::iterator iter;
        iter = QAA.find(str);
        if(iter != QAA.end())
        {
            ui->textBrowser->append();
            t =0;
        }
        else
        {
            ui->textBrowser->append("\n你说啥你说啥(｡•ˇ‸ˇ•｡)我听不懂呀~");
            ui->textBrowser->append("我现在还很笨,你可以教我说话哦╰(￣▽￣)╭\n");
            t = 0;
        }
    }



}
