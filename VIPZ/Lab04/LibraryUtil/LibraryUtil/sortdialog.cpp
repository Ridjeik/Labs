#include "sortdialog.h"
#include "ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
}

SortDialog::~SortDialog()
{
    delete ui;
}

void SortDialog::getValues(ListsFacade::Target &sortTarget, bool &descending) const
{
    sortTarget = targetFromString(ui->comboBox->currentText());
    descending = ui->checkBox->isChecked();
}

ListsFacade::Target SortDialog::targetFromString(const QString &string) const
{
    if(string == "Ім'я автора")
        return ListsFacade::Target::AuthorName;
    else if(string == "Прізвище автора")
        return ListsFacade::Target::AuthorSurname;
    else if(string == "Назва книги")
        return ListsFacade::Target::BookTitle;
    else if(string == "Рік видання")
        return ListsFacade::Target::PublicationYear;
    else if(string == "К-ть сторінок")
        return ListsFacade::Target::PageCount;
    else
        return ListsFacade::Target::BookPrice;
}

