#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include "listsfacade.h"

namespace Ui {
class SortDialog;
}

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = nullptr);
    ~SortDialog();
    void getValues(ListsFacade::Target& sortTarget, bool& descending) const;

private:

    ListsFacade::Target targetFromString(const QString& string) const;

    Ui::SortDialog *ui;
};

#endif // SORTDIALOG_H
