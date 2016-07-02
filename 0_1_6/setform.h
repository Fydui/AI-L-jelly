#ifndef SETFORM_H
#define SETFORM_H

#include "ui_setform.h"
#include "aboutform.h"

class SetForm : public QWidget, private Ui::SetForm
{
    Q_OBJECT

public:
    explicit SetForm(QWidget *parent = 0);
    AboutForm* abou = new AboutForm();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
};

#endif // SETFORM_H
