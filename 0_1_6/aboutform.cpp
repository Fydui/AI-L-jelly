#include "aboutform.h"

AboutForm::AboutForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->textBrowser->insertHtml("<img src=\":/Resource/sw.png\"/>");
}

void AboutForm::on_pushButton_clicked()
{
    close();
}
