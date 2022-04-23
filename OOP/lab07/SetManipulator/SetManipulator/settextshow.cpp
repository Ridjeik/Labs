#include "settextshow.h"
#include "ui_settextshow.h"

SetTextShow::SetTextShow(TreeSet set, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetTextShow)
{
    ui->setupUi(this);
    *(ui->textEdit) << set;
}

SetTextShow::~SetTextShow()
{
    delete ui;
}
