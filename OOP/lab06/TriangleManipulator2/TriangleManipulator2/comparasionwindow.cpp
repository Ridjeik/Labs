#include "comparasionwindow.h"
#include "triangle.h"
#include "ui_comparasionwindow.h"

ComparasionWindow::ComparasionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ComparasionWindow)
{
    ui->setupUi(this);
}

ComparasionWindow::~ComparasionWindow()
{
    delete ui;
}

void ComparasionWindow::on_compareButton_clicked()
{
    Triangle a
            (
            ui->sideALabel->text().toDouble(),
            ui->sideBLabel->text().toDouble(),
            ui->sideCLabel->text().toDouble()
            );

    Triangle b
            (
            ui->sideA2Label->text().toDouble(),
            ui->sideB2Label->text().toDouble(),
            ui->sideC2Label->text().toDouble()
            );

    if(a > b) ui->signLabel->setText(">");
    else if(a < b) ui->signLabel->setText("<");
    else if(a == b) ui->signLabel->setText("=");
}


void ComparasionWindow::on_exitButton_clicked()
{
    this->close();
}

