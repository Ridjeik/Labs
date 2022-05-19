#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listscontroller.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(ListsController* controller, QWidget *parent = nullptr);
    ~MainWindow();
    void onListsChanged(QTabWidget *newWidget);

private slots:
    void on_actionLoad_to_current_list_triggered();
    void onTabChanged(int index);
    void onTabClosed(int index);


    void on_createButton_clicked();

    void on_sortButton_clicked();

    void on_filterButton_clicked();

    void on_actionExit_triggered();

    void on_actionSave_current_list_to_triggered();

    void on_topButton_clicked();

    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;
    ListsController *controller;
};
#endif // MAINWINDOW_H
