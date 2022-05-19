#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "lab10_lib.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    Book getResult() const;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
