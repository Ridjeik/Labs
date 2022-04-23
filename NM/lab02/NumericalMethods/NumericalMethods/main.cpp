#include "graphswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GraphsWindow w;
    w.show();
    return a.exec();
}
