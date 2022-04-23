#include "setviewer.h"
#include "ui_setviewer.h"
#include "treeset.h"
#include "settextshow.h"

#include <QScrollBar>

SetViewer::SetViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SetViewer)
{
    ui->setupUi(this);

    ui->set1Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->set2Table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->resultSetTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

SetViewer::~SetViewer()
{
    delete ui;
}

void SetViewer::on_pushButton_clicked()
{
    ui->set1Table->setColumnCount(ui->set1Table->columnCount() + 1);
}


void SetViewer::on_pushButton_2_clicked()
{
     ui->set1Table->setColumnCount(ui->set1Table->columnCount() - 1);
}


void SetViewer::on_pushButton_3_clicked()
{
     ui->set2Table->setColumnCount(ui->set2Table->columnCount() + 1);
}


void SetViewer::on_pushButton_4_clicked()
{
     ui->set2Table->setColumnCount(ui->set2Table->columnCount() - 1);
}


void SetViewer::on_pushButton_9_clicked()
{
    TreeSet a, b;
    *(ui->set1Table) >> a;
    *(ui->set2Table) >> b;

    ui->signLabel->setText("∪");
    *(ui->resultSetTable) << a + b;
}


void SetViewer::on_pushButton_8_clicked()
{
    TreeSet a, b;
    *(ui->set1Table) >> a;
    *(ui->set2Table) >> b;

    ui->signLabel->setText("∩");
    *(ui->resultSetTable) << a - b;
}


void SetViewer::on_pushButton_7_clicked()
{
    TreeSet a, b;
    *(ui->set1Table) >> a;
    *(ui->set2Table) >> b;

    ui->signLabel->setText("\\");
    *(ui->resultSetTable) << a / b;
}

TreeSet SetViewer::getCurrSet() const
{
    TreeSet set;
    if(ui->setSelector->currentText() == "First set")
        *(ui->set1Table) >> set;
    else if(ui->setSelector->currentText() == "Second set")
        *(ui->set2Table) >> set;
    else
        *(ui->resultSetTable) >> set;
    return set;
}


void SetViewer::on_pushButton_5_clicked()
{
    int num = ui->containsField->text().toInt();
    TreeSet set = getCurrSet();
    ui->containsLabel->setText(tr("Result: %1").arg(set.contains(num)));
}

void SetViewer::on_pushButton_6_clicked()
{
    TreeSet set = getCurrSet();
    ui->powerLabel->setText(tr("Power of selected set: %1").arg(set.power()));
}


void SetViewer::on_pushButton_11_clicked()
{
    TreeSet set = getCurrSet();
    ui->maxLabel->setText(tr("Max of selected set: %1").arg(set.max()));
}


void SetViewer::on_pushButton_12_clicked()
{
    TreeSet set = getCurrSet();
    ui->minLabel->setText(tr("Min of selected set: %1").arg(set.min()));
}


void SetViewer::on_pushButton_10_clicked()
{
    TreeSet result;
    *(ui->resultSetTable) >> result;
    SetTextShow dialog(result);
    dialog.exec();
}

