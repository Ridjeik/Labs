#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    firstContainer.clear();

    int elems = rand() % 10 + 1;
    for(int i = 0; i < elems; i++)
        firstContainer.insert( -100 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/200)));
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->firstEdit->setText(" ");
    std::for_each(firstContainer.begin(), firstContainer.end(), [this](float a)
    {
        ui->firstEdit->setText(ui->firstEdit->text().append(QString::number(a) + " "));
    });
}

void MainWindow::on_pushButton_3_clicked()
{
    std::multiset<float>::iterator iter;
    while((iter = std::find_if(firstContainer.begin(), firstContainer.end(), [](float num){return abs(num) < 10;})) != firstContainer.end())
    {
        firstContainer.erase(iter);
    }

    std::multiset<float> temp;

    std::for_each(firstContainer.begin(), firstContainer.end(),[&temp](float a){temp.insert(a*2);});
    firstContainer.clear();
    std::for_each(temp.begin(), temp.end(), [this](float a) {firstContainer.insert(a);});
}


void MainWindow::on_pushButton_4_clicked()
{
   ui->firstEdit->setText(" ");
   std::multiset<float>::iterator iter;
   for(iter = firstContainer.begin(); iter != firstContainer.end(); iter++)
       ui->firstEdit->setText(ui->firstEdit->text().append(QString::number(*iter) + " "));
}


void MainWindow::on_pushButton_5_clicked()
{
    secondContainer.clear();

    int elems = rand() % 10 + 1;
    for(int i = 0; i < elems; i++)
        secondContainer.insert( -100 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(200))));
}


void MainWindow::on_pushButton_6_clicked()
{
    firstContainer.erase(
                std::next(firstContainer.begin(), ui->fromSpin->value() + 1),
                std::next(firstContainer.begin(), ui->fromSpin->value() + ui->toSpin->value() + 1));

    std::for_each(secondContainer.begin(), secondContainer.end(), [this](float a) {firstContainer.insert(a);});

}

void MainWindow::on_pushButton_7_clicked()
{
    ui->firstEdit->setText(" ");
    std::for_each(firstContainer.begin(), firstContainer.end(), [this](float a)
    {
        ui->firstEdit->setText(ui->firstEdit->text().append(QString::number(a) + " "));
    });

    ui->secondEdit->setText(" ");
    std::for_each(secondContainer.begin(), secondContainer.end(), [this](float a)
    {
        ui->secondEdit->setText(ui->secondEdit->text().append(QString::number(a) + " "));
    });
}


void MainWindow::on_pushButton_8_clicked()
{
    auto iter = std::find_if(secondContainer.begin(), secondContainer.end(), [](float num){return num > 50;});

    if(iter != secondContainer.end())
        QMessageBox::information(this, "Пошук", tr("Перший елемент, що більше 50 - це %0.").arg(*iter));
    else
        QMessageBox::information(this, "Пошук", "Немає елементу, більшого за 50.");
}


void MainWindow::on_pushButton_9_clicked()
{
    for(auto iter = secondContainer.begin(); iter != secondContainer.end(); iter++)
        if((int)trunc(abs(*iter)) % 2 == 0) thirdContainer.push(secondContainer.extract(iter).value());

}


void MainWindow::on_pushButton_10_clicked()
{
    ui->secondEdit->setText(" ");
    std::for_each(secondContainer.begin(), secondContainer.end(), [this](float a)
    {
        ui->secondEdit->setText(ui->secondEdit->text().append(QString::number(a) + " "));
    });
}

QString queueToStr(std::queue<float> queue)
{
    QString res = "";
    while(!queue.empty())
    {
        res.append(QString::number(queue.front()) + " ");
        queue.pop();
    }
    return res;
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->thirdEdit->setText(queueToStr(thirdContainer));
}


void MainWindow::on_pushButton_11_clicked()
{
    while(!thirdContainer.empty()) thirdContainer.pop();
    std::for_each(firstContainer.begin(), firstContainer.end(), [this](float a){thirdContainer.push(a);});
    std::for_each(secondContainer.begin(), secondContainer.end(), [this](float a){thirdContainer.push(a);});
}

size_t count_if(std::queue<float> queue, std::function<bool(float)> pred)
{
    size_t res = 0;
    while(!queue.empty())
    {
        if(pred(queue.front())) res++;
        queue.pop();
    }
    return res;
}

void MainWindow::on_pushButton_13_clicked()
{
    QMessageBox::information(this, "Пошук", tr("К-ть елементів, що задовольняють умові - %0.").arg(count_if(thirdContainer, [](float a){return a > 0;})));
}

