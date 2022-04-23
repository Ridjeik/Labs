#include "newtriangledialog.h"
#include "triangleviewer.h"
#include "ui_triangleviewer.h"

#include <QPainter>
#include <QPen>
#include <cmath>

const double a = 1, b = 2, c = 3;

TriangleViewer::TriangleViewer(QWidget *parent)
    : QMainWindow(parent)
    , triangle(a,b,c)
    , ui(new Ui::TriangleViewer)
{
    ui->setupUi(this);
    Triangle a;
    updateInteraface();
}

TriangleViewer::~TriangleViewer()
{
    delete ui;
}

void TriangleViewer::setTriangle(const Triangle &triangle)
{
    this->triangle = triangle;
    updateInteraface();
}

Triangle TriangleViewer::getTriangle() const
{
    return triangle;
}
//...
void TriangleViewer::updateInteraface()
{
    double a, b, c;
    triangle.getSides(a, b, c);
    ui->sideALabel->setText(tr("Side a: %1").arg(a));
    ui->sideBLabel->setText(tr("Side b: %1").arg(b));
    ui->sideCLabel->setText(tr("Side c: %1").arg(c));

    ui->perimeterLabel->setText(tr("Perimeter: %1").arg(triangle.getPerimeter()));
    ui->areaLabel->setText(tr("Area: %1").arg(triangle.getArea()));

    double angA, angB, angC;
    triangle.getAngles(angA, angB, angC);

    ui->anglesLabel->setText(tr("Angles: A: %1°; B: %2°; C: %3°").arg(angA * (180/M_PI)).arg(angB * (180/M_PI)).arg(angC * (180/M_PI)));

    double medA, medB, medC;
    triangle.getMedians(medA, medB, medC);
    ui->mediansLabel->setText(tr("Medians: Ma: %1; Mb: %2; Mc: %3").arg(medA).arg(medB).arg(medC));

    ui->rectangularLabel->setText(tr("Is rectangular: %1").arg(triangle.isRectangular() ? "true" : "false"));

    ui->viewWidget->setTriangle(triangle);
    ui->viewWidget->update();
}

void TriangleViewer::on_increaseButton_clicked()
{
    double delta = ui->increaseField->text().toDouble();
    ui->increaseField->setText("");

    triangle.increaseSidesBy(delta);
    updateInteraface();
}

void TriangleViewer::on_setSidesButton_clicked()
{
    double a = ui->sideAField->text().toDouble();
    double b = ui->sideBField->text().toDouble();
    double c = ui->sideCField->text().toDouble();

    ui->sideAField->setText("");
    ui->sideBField->setText("");
    ui->sideCField->setText("");

    triangle.setSides(a,b,c);
    updateInteraface();
}


void TriangleViewer::on_sidesCheckBox_stateChanged(int arg1)
{
    ui->viewWidget->setShowSides(static_cast<bool>(arg1));
}

void TriangleViewer::on_mediansCheckBox_stateChanged(int arg1)
{
    ui->viewWidget->setShowMedians(static_cast<bool>(arg1));
}

void TriangleViewer::on_verticesCheckBox_stateChanged(int arg1)
{
    ui->viewWidget->setShowVertices(static_cast<bool>(arg1));
}

void TriangleViewer::on_actionTriangle_triggered()
{
    NewTriangleDialog dialog(this);

    dialog.exec();
}


