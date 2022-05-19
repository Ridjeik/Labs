#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDialog>
#include "listsfacade.h"

namespace Ui {
class FilterDialog;
}

class FilterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FilterDialog(QWidget *parent = nullptr);
    ~FilterDialog();

    void getValues(ListsFacade::Target& target, ListsFacade::Criterea& criteria, QString& param) const;

private slots:

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    ListsFacade::Target targetFromString(const QString& string) const;
    Ui::FilterDialog *ui;
};

#endif // FILTERDIALOG_H
