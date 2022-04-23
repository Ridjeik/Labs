#include "triangleviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TriangleViewer w;
    w.show();
    return a.exec();
}
