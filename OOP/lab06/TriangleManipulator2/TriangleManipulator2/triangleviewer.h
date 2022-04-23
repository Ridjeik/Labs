#ifndef TRIANGLEVIEWER_H
#define TRIANGLEVIEWER_H

#include <QMainWindow>
#include "comparasionwindow.h"
#include "triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TriangleViewer; }
QT_END_NAMESPACE


class TriangleViewer : public QMainWindow
{
    Q_OBJECT

    Triangle triangle;
public:
    TriangleViewer(QWidget *parent = nullptr);
    ~TriangleViewer();

    void setTriangle(const Triangle& triangle);
    Triangle getTriangle() const;
    void updateInteraface();

private slots:
    void on_increaseButton_clicked();

    void on_setSidesButton_clicked();

    void on_sidesCheckBox_stateChanged(int arg1);

    void on_mediansCheckBox_stateChanged(int arg1);

    void on_actionTriangle_triggered();

    void on_verticesCheckBox_stateChanged(int arg1);

    void on_multiplyButton_clicked();

    void on_actionTriangles_triggered();

private:
    ComparasionWindow *wind = nullptr;
    Ui::TriangleViewer *ui;
};
#endif // TRIANGLEVIEWER_H
