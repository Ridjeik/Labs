#ifndef SETTEXTSHOW_H
#define SETTEXTSHOW_H

#include <QDialog>
#include "treeset.h"

namespace Ui {
class SetTextShow;
}

class SetTextShow : public QDialog
{
    Q_OBJECT

public:
    explicit SetTextShow(TreeSet set, QWidget *parent = nullptr);
    ~SetTextShow();

private:

    Ui::SetTextShow *ui;
};

#endif // SETTEXTSHOW_H
