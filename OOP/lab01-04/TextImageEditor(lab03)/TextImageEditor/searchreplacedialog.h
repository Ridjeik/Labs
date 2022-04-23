#ifndef SEARCHREPLACEDIALOG_H
#define SEARCHREPLACEDIALOG_H

#include <QDialog>

namespace Ui {
class SearchReplaceDialog;
}

class SearchReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchReplaceDialog(QWidget *parent = nullptr);
    ~SearchReplaceDialog();
    QString* getValues() const;

private:
    Ui::SearchReplaceDialog *ui;
};

#endif // SEARCHREPLACEDIALOG_H
