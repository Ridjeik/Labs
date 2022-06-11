#include "arrayviewer.h"
#include "ui_arrayviewer.h"
#include <sstream>
#include "MyArray.h"
#include "MyString.h"

ArrayViewer::ArrayViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ArrayViewer)
{
    ui->setupUi(this);
}

ArrayViewer::~ArrayViewer()
{
    delete ui;
}

void ArrayViewer::on_sortAscButton_clicked()
{
    sortWithType();
}

template<class T>
void ArrayViewer::sort(bool descending)
{
    std::stringstream input;
    input << ui->inputField->text().toStdString();

    Array<T, arrays_size> arr;
    input >> arr;
    arr.sort(descending);

    std::stringstream output;
    output << arr;
    ui->outputField->setText(output.str().c_str());
}


void ArrayViewer::on_sortDescButton_clicked()
{
    sortWithType(true);
}


void ArrayViewer::on_minElemButton_clicked()
{
    if(ui->typeBox->currentText() == "int")
        min<int>();
    else if(ui->typeBox->currentText() == "double")
        min<double>();
    else if(ui->typeBox->currentText() == "MyString")
        min<MyString>();
    else if(ui->typeBox->currentText() == "std::string")
        min<std::string>();
}

void ArrayViewer::sortWithType(bool descending)
{
    if(ui->typeBox->currentText() == "int")
        sort<int>(descending);
    else if(ui->typeBox->currentText() == "double")
        sort<double>(descending);
    else if(ui->typeBox->currentText() == "MyString")
        sort<MyString>(descending);
    else if(ui->typeBox->currentText() == "std::string")
        sort<std::string>(descending);
}


template<class T>
void ArrayViewer::min()
{
    std::stringstream input;
    input << ui->inputField->text().toStdString();

    Array<T, arrays_size> arr;
    input >> arr;

    std::stringstream output;
    output << arr.min_elem();
    ui->outputField->setText(output.str().c_str());
}
