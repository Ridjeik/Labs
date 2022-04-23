#ifndef NEWTRIANGLEDIALOG_H
#define NEWTRIANGLEDIALOG_H

#include <QDialog>
#include "triangle.h"

class TriangleViewer;

namespace Ui {
class NewTriangleDialog;
}

class NewTriangleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTriangleDialog(TriangleViewer* viewer, QWidget *parent = nullptr);
    ~NewTriangleDialog();

private slots:
    void on_buttonBox_accepted();

private:
    TriangleViewer* mainWindow;
    Ui::NewTriangleDialog *ui;
};

#endif // NEWTRIANGLEDIALOG_H
