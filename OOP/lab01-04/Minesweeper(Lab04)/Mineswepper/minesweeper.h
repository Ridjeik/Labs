#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MineSweeper; }
QT_END_NAMESPACE

class MineSweeper : public QWidget
{
    Q_OBJECT

public:
    MineSweeper(QWidget *parent = nullptr);
    ~MineSweeper();

private slots:
    void on_newGameButton_clicked();
    void buttonClicked();


private:
    Ui::MineSweeper *ui;
};
#endif // MINESWEEPER_H
