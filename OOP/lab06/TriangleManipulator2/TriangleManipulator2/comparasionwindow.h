#ifndef COMPARASIONWINDOW_H
#define COMPARASIONWINDOW_H

#include <QWidget>

namespace Ui {
class ComparasionWindow;
}

class ComparasionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ComparasionWindow(QWidget *parent = nullptr);
    ~ComparasionWindow();

private slots:
    void on_compareButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::ComparasionWindow *ui;
};

#endif // COMPARASIONWINDOW_H
