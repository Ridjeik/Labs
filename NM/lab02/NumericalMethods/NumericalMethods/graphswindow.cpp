#include "graphswindow.h"
#include "ui_graphswindow.h"
#include "functions.h"
#include "qcustomplot.h"
#include <QVector>

GraphsWindow::GraphsWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GraphsWindow)
{
    ui->setupUi(this);

    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");
    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esFlatArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esFlatArrow);
}
GraphsWindow::~GraphsWindow()
{
    delete ui;
}

void GraphsWindow::initGraphs(double begin, double end)
{
    if(begin >= end) return;
    QVector<double> x_f, y_f,
                    x_phi, y_phi,
                    x_x, y_x;

    double max_phi = phi(begin);
    for (double xi = begin; xi <= end + 0.01; xi+=0.01)
    {
      x_f.push_back(xi);
      y_f.push_back( f(xi) );

      x_phi.push_back(xi);
      y_phi.push_back(phi(xi));
      if(phi(xi) > max_phi) max_phi = phi(xi);

      x_x.push_back(xi);
      y_x.push_back(xi);
    }


    ui->plot->xAxis->setRange(begin, end);
    ui->plot->yAxis->setRange(-max_phi*1.5, max_phi*1.5);

    static auto fGraph = ui->plot->addGraph();
    fGraph->setName("y = f(x)");
    fGraph->setData(x_f, y_f);
    fGraph->setPen(QPen(QBrush(QColor::fromRgb(255,0,0)), 1.5));

    static auto phiGraph = ui->plot->addGraph();
    phiGraph->setData(x_phi, y_phi);
    phiGraph->setName("y = φ(x)");

    static auto xGraph = ui->plot->addGraph();
    xGraph->setName("y = x");
    xGraph->setData(x_x, y_x);
    xGraph->setPen(QPen(QBrush(QColor::fromRgb(100,255,100)), 1.5, Qt::DashLine));

    ui->plot->legend->setVisible(true);
    ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignLeft);
    ui->plot->replot();
}

void GraphsWindow::performDyhotomea(double begin, double end, double precision)
{
    try {
        int iterations = 0;
        double result = findDyhotomea(begin, end, precision, iterations);
        ui->dyhotomeaResult->setText(tr("Результат: %1").arg(QString::number(result, 'g', 8)));
        ui->dyhotomeaIterations->setText(tr("Ітерацій: %1").arg(iterations));
    }  catch (const char* except) {
        ui->dyhotomeaResult->setText("Результат: неможливо знайти корінь");
        ui->dyhotomeaIterations->setText(tr("Ітерацій: 0"));
    }
}

void GraphsWindow::performHordes(double begin, double end, double precision)
{
    try {
        int iterations = 0;
        double result = findHordes(begin, end, precision, iterations);
        ui->hordesResult->setText(tr("Результат: %1").arg(QString::number(result, 'g', 8)));
        ui->hordesIterations->setText(tr("Ітерацій: %1").arg(iterations));
    }  catch (const char* except) {
        ui->hordesResult->setText("Результат: неможливо знайти корінь");
        ui->hordesIterations->setText(tr("Ітерацій: 0"));
    }
}

void GraphsWindow::performSimpleIteration(double begin, double precision)
{
    int iterations = 0;
    double result = findSimpleIteration(begin, precision, iterations);
    ui->simpleIterResult->setText(tr("Результат: %1").arg(QString::number(result, 'g', 8)));
    ui->simpleIterIterations->setText(tr("Ітерацій: %1").arg(iterations));
}

void GraphsWindow::performTangents(double begin, double end, double precision)
{
    int iterations = 0;
    double result = findTangents(begin, end, precision, iterations);
    ui->tangentsResult->setText(tr("Результат: %1").arg(QString::number(result, 'g', 8)));
    ui->tangentsIterations->setText(tr("Ітерацій: %1").arg(iterations));
}


void GraphsWindow::on_pushButton_clicked()
{
    double begin = ui->beginSetter->value();
    double end = ui->endSetter->value();

    if(begin > end)
    {
        ui->beginSetter->setValue(end);
        ui->endSetter->setValue(begin);
        std::swap(begin, end);
    }
    double precision = ui->precisionSetter->value();

    qDebug() << begin << " " << end;

    initGraphs(begin,end);
    performDyhotomea(begin, end, precision);
    performHordes(begin, end, precision);
    performSimpleIteration(begin, precision);
    performTangents(begin, end, precision);
}

