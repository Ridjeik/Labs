#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}


int can_place_dot = 1;

void Calculator::on_pushButton_14_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "0");
    ui->mathInput->setText(text);
}


void Calculator::on_pushButton_9_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "1");
    ui->mathInput->setText(text);
}


void Calculator::on_pushButton_10_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "2");
    ui->mathInput->setText(text);
}


void Calculator::on_pushButton_11_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "3");
    ui->mathInput->setText(text);
}

void Calculator::on_pushButton_2_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "4");
    ui->mathInput->setText(text);
}


void Calculator::on_pushButton_4_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "5");
    ui->mathInput->setText(text);
}

void Calculator::on_pushButton_7_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "6");
    ui->mathInput->setText(text);
}

void Calculator::on_pushButton_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "7");
    ui->mathInput->setText(text);
}

void Calculator::on_pushButton_3_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "8");
    ui->mathInput->setText(text);
}


void Calculator::on_pushButton_5_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    strcat(text, "9");
    ui->mathInput->setText(text);
}



void Calculator::on_pushButton_13_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    if(can_place_dot && strlen(text) && isdigit(text[strlen(text) - 1]))
    {
        strcat(text, ".");
        ui->mathInput->setText(text);
        can_place_dot = 0;
    }
}


void Calculator::on_pushButton_6_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());

    if(strlen(text))
    {
        char last = text[strlen(text) - 1];
        if(last != '+' && last != '-' && last != '*' && last != '/' && last != '.')
        {
            strcat(text, "+");
            ui->mathInput->setText(text);
        }
    }
}


void Calculator::on_pushButton_8_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());
    if(strlen(text)){
    char last = text[strlen(text) - 1];
    char prelast = text[strlen(text) - 2];
        if(last == '.' ||
          ((last == '+' || last == '-' || last == '*' || last == '/') &&
          (prelast == '+' || prelast == '-' || prelast == '*' || prelast == '/'))) return;
    }
    strcat(text, "-");
    ui->mathInput->setText(text);
}


void Calculator::on_pushButton_12_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());

    if(strlen(text))
    {
        char last = text[strlen(text) - 1];
        if(last != '+' && last != '-' && last != '*' && last != '/' && last != '.')
        {
            strcat(text, "*");
            ui->mathInput->setText(text);
        }
    }
}


void Calculator::on_pushButton_16_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());

    if(strlen(text))
    {
        char last = text[strlen(text) - 1];
        if(last != '+' && last != '-' && last != '*' && last != '/' && last != '.')
        {
            strcat(text, "/");
            ui->mathInput->setText(text);
        }
    }
}


typedef double(*operation)(double, double);

int getPrior(char op)
{
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

double add(double a, double b)
{
    return a + b;
}
double sub(double a, double b)
{
    return a - b;
}
double mul(double a, double b)
{
    return a * b;
}
double div(double a, double b)
{
    return a / b;
}

operation getOperation(char op)
{
    switch (op)
    {
    case '+':
        return add;
    case '-':
        return sub;
    case '*':
        return mul;
    case '/':
        return div;
    }
}

void Calculator::on_pushButton_15_clicked()
{
    char buffer[256];

    double stack_n[256];
    int peek_n = -1;
    char stack_o[256];
    int peek_o = -1;

    strcpy_s(buffer, 256, ui->mathInput->text().toStdString().c_str());

    qDebug() << buffer;
    double value;
    char op;
    for (char* p = buffer; *p != 0; p++)
    {

        if (isdigit(*p) || (*p == '-' && (p == buffer || *(p-1) == '+' || *(p-1) == '-' || *(p-1) == '*' || *(p-1) == '/')))
        {
            value = strtod(p, &p);
            p--;
            stack_n[++peek_n] = value;
            qDebug() << "putting number " << value << " to stack";
        }
        else
        {
            op = *p;
            if(op == '(') stack_o[++peek_o] = op;
            else if (op == ')')
            {
                while (stack_o[peek_o] != '(')
                {
                    char op = stack_o[peek_o--];
                    double last = stack_n[peek_n];
                    double prelast = stack_n[peek_n - 1];
                    qDebug() << "Performing: " << prelast << op << last;
                    value = getOperation(op)(prelast, last);
                    peek_n -= 2;
                    stack_n[++peek_n] = value;
                }
                peek_o--;
            }
            else {
                while (getPrior(op) <= getPrior(stack_o[peek_o]))
                {
                    char op = stack_o[peek_o--];
                    double last = stack_n[peek_n];
                    double prelast = stack_n[peek_n - 1];
                    qDebug() << "Performing: " << prelast << op << last;
                    value = getOperation(op)(prelast, last);
                    peek_n -= 2;
                    stack_n[++peek_n] = value;
                }
                qDebug() << "putting operation " << op << " to stack";
                stack_o[++peek_o] = op;
            }
        }
    }

    while (peek_o >= 0)
    {
        char op = stack_o[peek_o--];
        double last = stack_n[peek_n];
        double prelast = stack_n[peek_n - 1];
        qDebug() << "Performing: " << prelast << op << last;
        value = getOperation(op)(prelast, last);
        peek_n -= 2;
        stack_n[++peek_n] = value;
    }
    sprintf(buffer, "%.2lf", value);
    ui->mathInput->setText(buffer);
    qDebug() << "------------------------------------------------------";
}


void Calculator::on_pushButton_19_clicked()
{
    char buffer[256];
    strcpy_s(buffer, 256, ui->mathInput->text().toStdString().c_str());
    buffer[strlen(buffer) - 1] = '\0';
    ui->mathInput->setText(buffer);
}


void Calculator::on_pushButton_20_clicked()
{
    ui->mathInput->setText("");
}


void Calculator::on_pushButton_17_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());

    if(!strlen(text) ||
            text[strlen(text) - 1] == '+' ||
            text[strlen(text) - 1] == '-' ||
            text[strlen(text) - 1] == '*' ||
            text[strlen(text) - 1] == '/' ||
            text[strlen(text) - 1] == '(')
    {
        strcat(text, "(");
        ui->mathInput->setText(text);
    }

}


void Calculator::on_pushButton_18_clicked()
{
    char text[256];
    strcpy_s(text, 255, ui->mathInput->text().toStdString().c_str());

    if(strlen(text) &&
            (isdigit(text[strlen(text) - 1]) ||
             text[strlen(text) - 1] == ')'))
    {
        strcat(text, ")");
        ui->mathInput->setText(text);
    }
}

