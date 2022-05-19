#include "mainwindow.h"
#include "listscontroller.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ListsController().getConnectedWindow()->show();
    return a.exec();
}
