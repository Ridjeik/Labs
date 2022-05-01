#include "posthelperwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PostHelperWindow w;
    w.show();
    return a.exec();
}
