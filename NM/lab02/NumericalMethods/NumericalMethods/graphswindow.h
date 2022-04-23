#ifndef GRAPHSWINDOW_H
#define GRAPHSWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GraphsWindow; }
QT_END_NAMESPACE

class GraphsWindow : public QMainWindow
{
    Q_OBJECT

public:
    GraphsWindow(QWidget *parent = nullptr);
    ~GraphsWindow();

    void initGraphs(double begin, double end);
    void performDyhotomea(double begin, double end, double precision);
    void performHordes(double begin, double end, double precision);
    void performSimpleIteration(double begin, double precision);
    void performTangents(double begin, double end, double precision);

private slots:
    void on_pushButton_clicked();

private:
    Ui::GraphsWindow *ui;
};
#endif // GRAPHSWINDOW_H
