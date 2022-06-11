#ifndef ARRAYVIEWER_H
#define ARRAYVIEWER_H

#include <QMainWindow>
#include "MyArray.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ArrayViewer; }
QT_END_NAMESPACE

class ArrayViewer : public QMainWindow
{
    Q_OBJECT

public:
    ArrayViewer(QWidget *parent = nullptr);
    ~ArrayViewer();

private slots:
    void on_sortAscButton_clicked();

    void on_sortDescButton_clicked();

    void on_minElemButton_clicked();

private:

    template <class T>
    void sort(bool descending = false);

    template <class T>
    void min();

    void sortWithType(bool descending = false);


    Ui::ArrayViewer *ui;

    static constexpr size_t arrays_size = 5;
};
#endif // ARRAYVIEWER_H
