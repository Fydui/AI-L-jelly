#include "setform.h"
#include "aboutform.h"


SetForm::SetForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void SetForm::on_pushButton_3_clicked()
{

    abou->show();   //显示关于窗口
    abou->setWindowTitle(tr("关于"));
    abou->setFixedSize(360,640); //限制窗口大小
    abou->setWindowModality(Qt::ApplicationModal);
}


void SetForm::on_pushButton_4_clicked()
{
    close();
}
