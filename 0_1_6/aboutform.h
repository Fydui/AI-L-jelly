#ifndef ABOUTFORM_H
#define ABOUTFORM_H

#include "ui_aboutform.h"

class AboutForm : public QWidget, private Ui::AboutForm
{
    Q_OBJECT

public:
    explicit AboutForm(QWidget *parent = 0);

private slots:
    void on_pushButton_clicked();
};

#endif // ABOUTFORM_H
