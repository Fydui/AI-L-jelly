#include "aboutform.h"

AboutForm::AboutForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}

void AboutForm::on_pushButton_clicked()
{
    close();
}
