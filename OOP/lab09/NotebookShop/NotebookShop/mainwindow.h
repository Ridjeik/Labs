#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "order.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_newButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Order* currentOrder = nullptr;

    void updateText();
};
#endif // MAINWINDOW_H
