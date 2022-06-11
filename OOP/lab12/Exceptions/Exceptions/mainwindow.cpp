#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myExceptions.h"
#include <QMessageBox>
#include <ctype.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkFields(bool first, bool second) const
{
    if(first)
    {
        QString a = ui->Num->text();
        if(a.size() > 11 || a.size() == 0 || (a.size()==1 && a[0]=='-')) throw InvalidFormatException();
        for(int i = 0; i < a.size(); i++)
        {
            if(i == 0 && a[i] == '-')
                continue;
            if(isdigit(a[i].toLatin1()))
                continue;
            throw InvalidFormatException();
        }
        QString b = ui->Denom->text();
        if(b.size() > 11 || b.size() == 0 || (b.size()==1 && b[0]=='-')) throw InvalidFormatException();
        for(int i = 0; i < b.size(); i++)
        {
            if(i == 0 && b[i] == '-')
                continue;
            if(isdigit(b[i].toLatin1()))
                continue;
            throw InvalidFormatException();
        }
    }
    if(second)
    {
        QString a = ui->Num2->text();
        if(a.size() > 11 || a.size() == 0 || (a.size()==1 && a[0]=='-')) throw InvalidFormatException();
        for(int i = 0; i < a.size(); i++)
        {
            if(i == 0 && a[i] == '-')
                continue;
            if(isdigit(a[i].toLatin1()))
                continue;
            throw InvalidFormatException();
        }
        QString b = ui->Denom2->text();
        if(b.size() > 11 || b.size() == 0 || (b.size()==1 && b[0]=='-')) throw InvalidFormatException();
        for(int i = 0; i < b.size(); i++)
        {
            if(i == 0 && b[i] == '-')
                continue;
            if(isdigit(b[i].toLatin1()))
                continue;
            throw InvalidFormatException();
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    try{
        checkFields(true, true);
        Fraction a
                (
                    ui->Num->text().toLongLong(),
                    ui->Denom->text().toLongLong()
                );

        Fraction b
                (
                    ui->Num2->text().toLongLong(),
                    ui->Denom2->text().toLongLong()
                );

        Fraction c = a + b;

        ui->Num3->setText(QString::number(c.getNumerator()));
        ui->Denom3->setText(QString::number(c.getDenominator()));
        ui->operationLabel->setText("+");
    }
    catch(std::exception& exc)
    {
        QMessageBox::critical(this, "Error", exc.what());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    try{
        checkFields(true, true);
        Fraction a
                (
                    ui->Num->text().toLongLong(),
                    ui->Denom->text().toLongLong()
                );

        Fraction b
                (
                    ui->Num2->text().toLongLong(),
                    ui->Denom2->text().toLongLong()
                );

        Fraction c = a - b;

        ui->Num3->setText(QString::number(c.getNumerator()));
        ui->Denom3->setText(QString::number(c.getDenominator()));
        ui->operationLabel->setText("-");
    }
    catch(std::exception& exc)
    {
        QMessageBox::critical(this, "Error", exc.what());
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    try{
        checkFields(true, true);
        Fraction a
                (
                    ui->Num->text().toLongLong(),
                    ui->Denom->text().toLongLong()
                );

        Fraction b
                (
                    ui->Num2->text().toLongLong(),
                    ui->Denom2->text().toLongLong()
                );

        Fraction c = a * b;

        ui->Num3->setText(QString::number(c.getNumerator()));
        ui->Denom3->setText(QString::number(c.getDenominator()));
        ui->operationLabel->setText("*");
    }
    catch(std::exception& exc)
    {
        QMessageBox::critical(this, "Error", exc.what());
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    try{
        checkFields(true, true);
        Fraction a
                (
                    ui->Num->text().toLongLong(),
                    ui->Denom->text().toLongLong()
                );

        Fraction b
                (
                    ui->Num2->text().toLongLong(),
                    ui->Denom2->text().toLongLong()
                );

        Fraction c = a / b;

        ui->Num3->setText(QString::number(c.getNumerator()));
        ui->Denom3->setText(QString::number(c.getDenominator()));
        ui->operationLabel->setText("*");
    }
    catch(std::exception& exc)
    {
        QMessageBox::critical(this, "Error", exc.what());
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    try{
        checkFields(true, false);
        Fraction a
                (
                    ui->Num->text().toLongLong(),
                    ui->Denom->text().toLongLong()
                );

        a = a.inversed();
        ui->Num->setText(QString::number(a.getNumerator()));
        ui->Denom->setText(QString::number(a.getDenominator()));
    }
    catch(std::exception& exc)
    {
        QMessageBox::critical(this, "Error", exc.what());
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    try{
        checkFields(false, true);
        Fraction a
                (
                    ui->Num2->text().toLongLong(),
                    ui->Denom2->text().toLongLong()
                );

        a = a.inversed();
        ui->Num2->setText(QString::number(a.getNumerator()));
        ui->Denom2->setText(QString::number(a.getDenominator()));
    }
    catch(std::exception& exc)
    {
        QMessageBox::critical(this, "Error", exc.what());
    }
}

