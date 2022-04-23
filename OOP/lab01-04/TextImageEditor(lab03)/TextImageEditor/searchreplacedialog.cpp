#include "searchreplacedialog.h"
#include "ui_searchreplacedialog.h"

SearchReplaceDialog::SearchReplaceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchReplaceDialog)
{
    ui->setupUi(this);
}

SearchReplaceDialog::~SearchReplaceDialog()
{
    delete ui;
}

QString *SearchReplaceDialog::getValues() const
{
    QString *res = new QString[2];
    res[0] = ui->searchText->text();
    res[1] = ui->replaceText->text();
    return res;
}


