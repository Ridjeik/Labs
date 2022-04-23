/********************************************************************************
** Form generated from reading UI file 'newtriangledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTRIANGLEDIALOG_H
#define UI_NEWTRIANGLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewTriangleDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *sideASet;
    QLabel *label_2;
    QLineEdit *sideBSet;
    QLabel *label;
    QLineEdit *sideCSet;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewTriangleDialog)
    {
        if (NewTriangleDialog->objectName().isEmpty())
            NewTriangleDialog->setObjectName(QString::fromUtf8("NewTriangleDialog"));
        NewTriangleDialog->resize(192, 164);
        horizontalLayout = new QHBoxLayout(NewTriangleDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(NewTriangleDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        sideASet = new QLineEdit(NewTriangleDialog);
        sideASet->setObjectName(QString::fromUtf8("sideASet"));

        verticalLayout->addWidget(sideASet);

        label_2 = new QLabel(NewTriangleDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        sideBSet = new QLineEdit(NewTriangleDialog);
        sideBSet->setObjectName(QString::fromUtf8("sideBSet"));

        verticalLayout->addWidget(sideBSet);

        label = new QLabel(NewTriangleDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        sideCSet = new QLineEdit(NewTriangleDialog);
        sideCSet->setObjectName(QString::fromUtf8("sideCSet"));

        verticalLayout->addWidget(sideCSet);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(NewTriangleDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(NewTriangleDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewTriangleDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewTriangleDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewTriangleDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTriangleDialog)
    {
        NewTriangleDialog->setWindowTitle(QCoreApplication::translate("NewTriangleDialog", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("NewTriangleDialog", "Side a", nullptr));
        label_2->setText(QCoreApplication::translate("NewTriangleDialog", "Side b", nullptr));
        label->setText(QCoreApplication::translate("NewTriangleDialog", "Side c", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTriangleDialog: public Ui_NewTriangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTRIANGLEDIALOG_H
