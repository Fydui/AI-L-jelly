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
        on_textEdit_textChanged();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    exit(0);
}


void MainWindow::on_textEdit_textChanged()
{
    QString O = ui->textEdit->toPlainText();

}
