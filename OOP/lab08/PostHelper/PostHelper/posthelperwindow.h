#ifndef POSTHELPERWINDOW_H
#define POSTHELPERWINDOW_H

#include <QMainWindow>
#include <fstream>
#include "parcel.h"
#include "parcelwithdefinedvalue.h"
#include "electronictransfer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PostHelperWindow; }
QT_END_NAMESPACE

class PostHelperWindow : public QMainWindow
{
    Q_OBJECT

    Parcel* lastParcel = nullptr;
    ParcelWithDefinedValue* lastParcelWithDefinedValue = nullptr;
    ElectronicTransfer* lastElectronicTransfer = nullptr;
    std::ofstream stream;

public:
    PostHelperWindow(QWidget *parent = nullptr);
    ~PostHelperWindow();

private slots:
    void on_parcelRadioButton_clicked(bool checked);

    void on_valueParcelRadioButton_clicked(bool checked);

    void on_electronicTranferRadioButton_clicked(bool checked);

    void on_confirmationButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::PostHelperWindow *ui;
};
#endif // POSTHELPERWINDOW_H
