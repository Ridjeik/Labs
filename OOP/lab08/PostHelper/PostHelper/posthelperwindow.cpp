#include "posthelperwindow.h"
#include "ui_posthelperwindow.h"
#include <QString>
#include <QMessageBox>

PostHelperWindow::PostHelperWindow(QWidget *parent)
    : QMainWindow(parent)
    , stream("postings.txt", std::ios::app)
    , ui(new Ui::PostHelperWindow)
{
    ui->setupUi(this);

    ui->parcelRadioButton->setChecked(true);
    on_parcelRadioButton_clicked(true);
}

PostHelperWindow::~PostHelperWindow()
{
    delete ui;
    delete lastParcel;
    delete lastElectronicTransfer;
    delete lastParcelWithDefinedValue;
    stream.close();
}


void PostHelperWindow::on_parcelRadioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->weightEdit->setDisabled(false);
        ui->valueEdit->setDisabled(true);
        ui->sumEdit->setDisabled(true);
    }
}


void PostHelperWindow::on_valueParcelRadioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->weightEdit->setDisabled(false);
        ui->valueEdit->setDisabled(false);
        ui->sumEdit->setDisabled(true);
    }
}


void PostHelperWindow::on_electronicTranferRadioButton_clicked(bool checked)
{
    if(checked)
    {
        ui->weightEdit->setDisabled(true);
        ui->valueEdit->setDisabled(true);
        ui->sumEdit->setDisabled(false);
    }
}


void PostHelperWindow::on_confirmationButton_clicked()
{
    if(ui->parcelRadioButton->isChecked())
    {
        Parcel* toOutput = new Parcel
                (
                    Person(ui->fromNameEdit->text().toStdString(), ui->fromSurnameEdit->text().toStdString()),
                    Person(ui->toNameEdit->text().toStdString(), ui->toSurnameEdit->text().toStdString()),
                    ui->weightEdit->text().toDouble()
                );

        QMessageBox::StandardButton btn = QMessageBox::information(this, "New posting", QString::fromStdString(toOutput->getInfoString()), QMessageBox::Ok, QMessageBox::Cancel);
        if(btn == QMessageBox::Ok)
        {
            delete lastParcel;
            lastParcel = toOutput;
            stream << toOutput->getInfoString() << "\n";
            stream.flush();
            toOutput->print(ui->usedClassLabel);
        }
    }
    else if(ui->valueParcelRadioButton->isChecked())
    {
        ParcelWithDefinedValue* toOutput = new ParcelWithDefinedValue
                (
                    Person(ui->fromNameEdit->text().toStdString(), ui->fromSurnameEdit->text().toStdString()),
                    Person(ui->toNameEdit->text().toStdString(), ui->toSurnameEdit->text().toStdString()),
                    ui->weightEdit->text().toDouble(),
                    ui->valueEdit->text().toDouble()
                );

        QMessageBox::StandardButton btn = QMessageBox::information(this, "New posting", QString::fromStdString(toOutput->getInfoString()), QMessageBox::Ok, QMessageBox::Cancel);
        if(btn == QMessageBox::Ok)
        {
            delete lastParcelWithDefinedValue;
            lastParcelWithDefinedValue = toOutput;
            stream << toOutput->getInfoString() << "\n";
            stream.flush();
            toOutput->print(ui->usedClassLabel);
        }
    }
    else
    {
        ElectronicTransfer* toOutput = new ElectronicTransfer
                (
                    Person(ui->fromNameEdit->text().toStdString(), ui->fromSurnameEdit->text().toStdString()),
                    Person(ui->toNameEdit->text().toStdString(), ui->toSurnameEdit->text().toStdString()),
                    ui->sumEdit->text().toDouble()
                );

        QMessageBox::StandardButton btn = QMessageBox::information(this, "New posting", QString::fromStdString(toOutput->getInfoString()), QMessageBox::Ok, QMessageBox::Cancel);
        if(btn == QMessageBox::Ok)
        {
            delete lastElectronicTransfer;
            lastElectronicTransfer = toOutput;
            stream << toOutput->getInfoString() << "\n";
            stream.flush();
            toOutput->print(ui->usedClassLabel);
        }
    }
}


void PostHelperWindow::on_pushButton_clicked()
{
    if(ui->parcelRadioButton->isChecked() && lastParcel)
    {
        Parcel toOutput(*lastParcel);
        QMessageBox::StandardButton btn = QMessageBox::information(this, "New posting", QString::fromStdString(toOutput.getInfoString()), QMessageBox::Ok, QMessageBox::Cancel);
        if(btn == QMessageBox::Ok)
        {
            stream << toOutput.getInfoString() << "\n";
            stream.flush();
            toOutput.print(ui->usedClassLabel);
        }
    }
    else if(ui->valueParcelRadioButton->isChecked() && lastParcelWithDefinedValue)
    {
        ParcelWithDefinedValue toOutput(*lastParcelWithDefinedValue);
        QMessageBox::StandardButton btn = QMessageBox::information(this, "New posting", QString::fromStdString(toOutput.getInfoString()), QMessageBox::Ok, QMessageBox::Cancel);
        if(btn == QMessageBox::Ok)
        {
            stream << toOutput.getInfoString() << "\n";
            stream.flush();
            toOutput.print(ui->usedClassLabel);
        }
    }
    else if(lastElectronicTransfer)
    {
        ElectronicTransfer toOutput(*lastElectronicTransfer);
        QMessageBox::StandardButton btn = QMessageBox::information(this, "New posting", QString::fromStdString(toOutput.getInfoString()), QMessageBox::Ok, QMessageBox::Cancel);
        if(btn == QMessageBox::Ok)
        {
            stream << toOutput.getInfoString() << "\n";
            stream.flush();
            toOutput.print(ui->usedClassLabel);
        }
    }
}

