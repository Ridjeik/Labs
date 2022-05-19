#include "filterdialog.h"
#include "ui_filterdialog.h"

#include <QMessageBox>

FilterDialog::FilterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterDialog)
{
    ui->setupUi(this);
}

FilterDialog::~FilterDialog()
{
    delete ui;
}

void FilterDialog::getValues(ListsFacade::Target &target, ListsFacade::Criterea &criteria, QString &param) const
{
    target = targetFromString(ui->comboBox->currentText());

    if(ui->aboveAverageBtn->isChecked())
    {
        criteria = ListsFacade::Criterea::AboveAverage;
    }
    else if(ui->belowAverageBtn->isChecked())
    {
        criteria = ListsFacade::Criterea::BelowAverage;
    }
    else if(ui->lessThanBtn->isChecked())
    {
        criteria = ListsFacade::Criterea::LessThan;
        param = ui->lessThanEdit->text();
    }
    else if(ui->notStartsWithBtn->isChecked())
    {
        criteria = ListsFacade::Criterea::NotStartsWith;
        param = ui->notStartsWithEdit->text();
    }
    else if(ui->startsWithBtn->isChecked())
    {
        criteria = ListsFacade::Criterea::StartsWith;
        param = ui->startsWithEdit->text();
    }
    else
    {
        criteria = ListsFacade::Criterea::MoreThan;
        param = ui->moreThanEdit->text();
    }

}

ListsFacade::Target FilterDialog::targetFromString(const QString &string) const
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



void FilterDialog::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1 == "Ім'я автора" || arg1 == "Прізвище автора" || arg1 == "Назва книги")
    {
        ui->startsWithBtn->setChecked(true);
        ui->startsWithBtn->setDisabled(false);
        ui->notStartsWithBtn->setDisabled(false);
        ui->startsWithEdit->setDisabled(false);
        ui->notStartsWithEdit->setDisabled(false);
        ui->aboveAverageBtn->setDisabled(true);
        ui->belowAverageBtn->setDisabled(true);
        ui->lessThanBtn->setDisabled(true);
        ui->moreThanBtn->setDisabled(true);
        ui->lessThanEdit->setDisabled(true);
        ui->moreThanEdit->setDisabled(true);
    }
    else
    {
        ui->aboveAverageBtn->setChecked(true);
        ui->startsWithBtn->setDisabled(true);
        ui->notStartsWithBtn->setDisabled(true);
        ui->startsWithEdit->setDisabled(true);
        ui->notStartsWithEdit->setDisabled(true);
        ui->aboveAverageBtn->setDisabled(false);
        ui->belowAverageBtn->setDisabled(false);
        ui->lessThanBtn->setDisabled(false);
        ui->moreThanBtn->setDisabled(false);
        ui->lessThanEdit->setDisabled(false);
        ui->moreThanEdit->setDisabled(false);
    }
}


void FilterDialog::on_okButton_clicked()
{
    if(ui->aboveAverageBtn->isChecked() || ui->belowAverageBtn->isChecked())
    {
        accept();
        return;
    }

    if(ui->startsWithBtn->isChecked())
    {
        if(ui->startsWithEdit->text().isEmpty())
            QMessageBox::warning(this, "Неправильний ввід", "Поле для цього критерію не може бути порожнім.");
        else
            accept();
        return;
    }
    if(ui->notStartsWithBtn->isChecked())
    {
        if(ui->notStartsWithEdit->text().isEmpty())
            QMessageBox::warning(this, "Неправильний ввід", "Поле для цього критерію не може бути порожнім.");
        else
            accept();
        return;
    }
    if(ui->moreThanBtn->isChecked())
    {
        bool ok = false;
        double a = ui->moreThanEdit->text().toDouble(&ok);
        if(ok && a > 0)
        {
            accept();
        }
        else
        {
            QMessageBox::warning(this, "Неправильний ввід", "Неправильний формат вводу.");
        }
    }
    if(ui->lessThanBtn->isChecked())
    {
        bool ok = false;
        double a = ui->lessThanEdit->text().toDouble(&ok);
        if(ok && a > 0)
        {
            accept();
        }
        else
        {
            QMessageBox::warning(this, "Неправильний ввід", "Неправильний формат вводу.");
        }
    }
}


void FilterDialog::on_cancelButton_clicked()
{
    this->close();
}

