#include "createrequest.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loadrequest.h"
#include "switchrequest.h"
#include "sortrequest.h"
#include "sortdialog.h"
#include "filterdialog.h"
#include "filterrequest.h"
#include "saverequest.h"
#include "limitrequest.h"
#include "deleterequest.h"
#include "adddialog.h"
#include "addrequest.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QFontDialog>

MainWindow::MainWindow(ListsController *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller(controller)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onListsChanged(QTabWidget *newWidget)
{
    delete ui->horizontalLayout->replaceWidget(ui->listsTabsWindow, newWidget);
    connect(newWidget, SIGNAL(currentChanged(int)), this, SLOT(onTabChanged(int)));
    connect(newWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(onTabClosed(int)));
    ui->listsTabsWindow = newWidget;
}

void MainWindow::on_actionLoad_to_current_list_triggered()
{
    if(ui->listsTabsWindow->count() == 0)
    {
        QMessageBox::warning(this, "Відмовлено у операції", "Спочатку треба створити список!");
        return;
    }
    QFileDialog dialog(this, "Завантаження файлу", "", "Текстові файли(*.txt)");

    if(dialog.exec() == QDialog::Accepted)
    {
        QString filename = dialog.selectedFiles()[0];
        QFile file(filename);

        try{
            controller->processRequest(this, LoadRequest(filename));
        }
        catch(...)
        {
            QMessageBox::critical(this, "Помилка", "Помилка відкриття файлу. Перевірте права доступу до файлу, а також його неушкодженість.");
            return;
        }


    }
}
void MainWindow::onTabChanged(int index)
{
    controller->processRequest(this, SwitchRequest(ui->listsTabsWindow->tabText(index)));
}

void MainWindow::onTabClosed(int index)
{
    if(QMessageBox::question(this, "Закриття файлу", "Чи хочете ви зберегти список у файл перед закриттям?") == QMessageBox::StandardButton::Yes)
    {
        on_actionSave_current_list_to_triggered();
    }
    controller->processRequest(this, DeleteRequest(ui->listsTabsWindow->tabText(index)));
}

void MainWindow::on_createButton_clicked()
{
    bool ok;
    QString listName = QInputDialog::getText(this, "Нове ім'я списку", "Введіть нове ім'я списку: ", QLineEdit::Normal, "", &ok);
    if(!ok) return;
    if(!listName.isEmpty())
    {
        controller->processRequest(this, CreateRequest(listName));
    }
    else QMessageBox::warning(this, "Неправильний ввід", "Ім'я списку не може бути порожнім.");
}

void MainWindow::on_sortButton_clicked()
{
    if(ui->listsTabsWindow->count() == 0)
    {
        QMessageBox::warning(this, "Відмовлено у операції", "Спочатку треба створити список!");
        return;
    }
    SortDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted)
    {
        ListsFacade::Target sortTarget;
        bool descending;
        dialog.getValues(sortTarget, descending);
        controller->processRequest(this, SortRequest(sortTarget, descending));
    }
}


void MainWindow::on_filterButton_clicked()
{
    if(ui->listsTabsWindow->count() == 0)
    {
        QMessageBox::warning(this, "Відмовлено у операції", "Спочатку треба створити список!");
        return;
    }
    FilterDialog dialog(this);

    if(dialog.exec() == QDialog::Accepted)
    {
        ListsFacade::Target filterTarget;
        ListsFacade::Criterea filterCriterea;
        QString param;

        dialog.getValues(filterTarget, filterCriterea, param);
        controller->processRequest(this, FilterRequest(filterTarget, filterCriterea, param));
    }

}


void MainWindow::on_actionExit_triggered()
{
    this->close();
}


void MainWindow::on_actionSave_current_list_to_triggered()
{
    if(ui->listsTabsWindow->count() == 0)
    {
        QMessageBox::warning(this, "Відмовлено у операції", "Спочатку треба створити список!");
        return;
    }
    QFileDialog dialog(this, "Збереження", "", "Текстові файли(*.txt)");

    if(dialog.exec() == QDialog::Accepted)
    {
        QString filename = dialog.selectedFiles()[0];
        QFile file(filename);
        file.remove();
        controller->processRequest(this, SaveRequest(filename));
        QMessageBox::information(this, "Успіх", "Файл успішно збережено.");
    }
}

void MainWindow::on_topButton_clicked()
{
    if(ui->listsTabsWindow->count() == 0)
    {
        QMessageBox::warning(this, "Відмовлено у операції", "Спочатку треба створити список!");
        return;
    }
    bool ok;
    int a = QInputDialog::getInt(this, "Ввід даних", "Введіть к-ть книг, яку потрбно залишити: ", 1, 1, 2147483647, 1, &ok);

    if(!ok)
    {
        QMessageBox::warning(this, "Неправильний ввід", "Неправильно введене число");
        return;
    }

    controller->processRequest(this, LimitRequest(a));
}


void MainWindow::on_addButton_clicked()
{
    if(ui->listsTabsWindow->count() == 0)
    {
        QMessageBox::warning(this, "Відмовлено у операції", "Спочатку треба створити список!");
        return;
    }
    AddDialog dialog(this);

    if(dialog.exec() == QDialog::Accepted)
    {
        controller->processRequest(this, AddRequest(dialog.getResult()));
    }
}

