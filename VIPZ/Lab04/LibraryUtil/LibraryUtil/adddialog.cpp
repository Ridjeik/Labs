#include "adddialog.h"
#include "ui_adddialog.h"

#include <QMessageBox>

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

Book AddDialog::getResult() const
{
    Book result;
    strcpy(result.author.name, ui->authorEdit->text().trimmed().split(" ")[0].toStdString().c_str());
    strcpy(result.author.surname, ui->authorEdit->text().trimmed().split(" ")[1].toStdString().c_str());
    strcpy(result.title, ui->titleEdit->text().toStdString().c_str());
    result.pageCount = ui->pagesEdit->text().toInt();
    result.pubYear = ui->pubYearEdit->text().toInt();
    result.price = ui->priceEdit->text().toDouble();
    return result;
}

void AddDialog::on_pushButton_clicked()
{
    if(ui->authorEdit->text().trimmed().isEmpty() && ui->authorEdit->text().trimmed().split(" ").length() != 2)
    {
        QMessageBox::warning(this, "Неправильний ввід", "Ім'я автора обов'язкове до вводу!");
        return;
    }
    if(ui->titleEdit->text().trimmed().isEmpty())
    {
        QMessageBox::warning(this, "Неправильний ввід", "Назва книги обов'язкова до вводу!");
        return;
    }
    if(ui->pagesEdit->text().trimmed().isEmpty() || ui->pagesEdit->text().toInt() <= 0)
    {
        QMessageBox::warning(this, "Неправильний ввід", "Неправильна к-ть сторінок!");
        return;
    }
    if(ui->priceEdit->text().trimmed().isEmpty() || ui->priceEdit->text().toDouble() <= 0)
    {
        QMessageBox::warning(this, "Неправильний ввід", "Неправильна ціна!");
        return;
    }
    if(ui->pubYearEdit->text().trimmed().isEmpty() || ui->pubYearEdit->text().toInt() <= 0)
    {
        QMessageBox::warning(this, "Неправильний ввід", "Неправильний рік видання!");
        return;
    }
    accept();
}


void AddDialog::on_pushButton_2_clicked()
{
    this->close();
}

