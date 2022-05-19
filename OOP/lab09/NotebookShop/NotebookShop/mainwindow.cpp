#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BuildInfrastructure/lowpricenotebookbuilder.h"
#include "BuildInfrastructure/middlepricenotebookbuilder.h"
#include "BuildInfrastructure/highpricenotebookbuilder.h"
#include "notebook.h"
#include "BuildInfrastructure/notebookproducer.h"

#include <QMessageBox>

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


void MainWindow::on_addButton_clicked()
{
    if(!currentOrder)
        currentOrder = new Order();

    else if(currentOrder->size() == 5)
    {
        QMessageBox::warning(this, "Denied", "There are cannot be more than 5 notebooks is order");
        return;
    }

    NotebookBuilder* builder = nullptr;

    if(ui->comboBox->currentText() == "Low price notebook")
        builder = new LowPriceNotebookBuilder();
    else if(ui->comboBox->currentText() == "Middle price notebook")
        builder = new MiddlePriceNotebookBuilder();
    else
        builder = new HighPriceNotebookBuilder();

    Notebook* newNotebook = NotebookProducer(builder).produce();
    currentOrder->add(newNotebook);

    updateText();
}


void MainWindow::on_newButton_clicked()
{
    delete currentOrder;
    currentOrder = nullptr;

    updateText();
}

void MainWindow::updateText()
{
    if(!currentOrder)
        ui->textEdit->setText("");
    else
        ui->textEdit->setText(QString::fromStdString(currentOrder->getOrderInfo()));
}


void MainWindow::on_pushButton_clicked()
{
    if(currentOrder) currentOrder->writeToFile("orders.txt");
}

