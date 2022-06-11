#include "arrayviewer.h"
#include "MyArray.h"
#include <sstream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArrayViewer w;
    w.show();
    return a.exec();
}
