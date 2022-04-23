#include "newtriangledialog.h"
#include "ui_newtriangledialog.h"
#include "triangleviewer.h"

NewTriangleDialog::NewTriangleDialog(TriangleViewer* viewer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTriangleDialog)
{
    ui->setupUi(this);
    mainWindow = viewer;

    Triangle triangle;
    *mainWindow << triangle;
    double a, b, c;
    triangle.getSides(a,b,c);

    ui->sideASet->setText(QString::number(a));
    ui->sideBSet->setText(QString::number(b));
    ui->sideCSet->setText(QString::number(c));
}

NewTriangleDialog::~NewTriangleDialog()
{
    delete ui;
}

void NewTriangleDialog::on_buttonBox_accepted()
{
    Triangle triangle
            (
                ui->sideASet->text().toDouble(),
                ui->sideBSet->text().toDouble(),
                ui->sideCSet->text().toDouble()
            );

    *mainWindow >> triangle;
}

