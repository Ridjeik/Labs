#ifndef SETVIEWER_H
#define SETVIEWER_H

#include <QMainWindow>
#include <QTableWidget>
#include "treeset.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SetViewer; }
QT_END_NAMESPACE

class SetViewer : public QMainWindow
{
    Q_OBJECT

public:
    SetViewer(QWidget *parent = nullptr);
    ~SetViewer();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

private:
    TreeSet getCurrSet() const;
    Ui::SetViewer *ui;
};
#endif // SETVIEWER_H
