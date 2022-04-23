/********************************************************************************
** Form generated from reading UI file 'comparasionwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPARASIONWINDOW_H
#define UI_COMPARASIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComparasionWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *sideALabel;
    QLabel *label_4;
    QLineEdit *sideBLabel;
    QLabel *label_5;
    QLineEdit *sideCLabel;
    QVBoxLayout *verticalLayout_4;
    QLabel *signLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QLabel *label_6;
    QLineEdit *sideA2Label;
    QLabel *label_8;
    QLineEdit *sideB2Label;
    QLabel *label_9;
    QLineEdit *sideC2Label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *compareButton;
    QPushButton *exitButton;

    void setupUi(QWidget *ComparasionWindow)
    {
        if (ComparasionWindow->objectName().isEmpty())
            ComparasionWindow->setObjectName(QString::fromUtf8("ComparasionWindow"));
        ComparasionWindow->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(ComparasionWindow);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(ComparasionWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_2 = new QLabel(ComparasionWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        sideALabel = new QLineEdit(ComparasionWindow);
        sideALabel->setObjectName(QString::fromUtf8("sideALabel"));

        verticalLayout->addWidget(sideALabel);

        label_4 = new QLabel(ComparasionWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        sideBLabel = new QLineEdit(ComparasionWindow);
        sideBLabel->setObjectName(QString::fromUtf8("sideBLabel"));

        verticalLayout->addWidget(sideBLabel);

        label_5 = new QLabel(ComparasionWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        sideCLabel = new QLineEdit(ComparasionWindow);
        sideCLabel->setObjectName(QString::fromUtf8("sideCLabel"));

        verticalLayout->addWidget(sideCLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        signLabel = new QLabel(ComparasionWindow);
        signLabel->setObjectName(QString::fromUtf8("signLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(signLabel->sizePolicy().hasHeightForWidth());
        signLabel->setSizePolicy(sizePolicy);
        signLabel->setMinimumSize(QSize(30, 0));
        QFont font;
        font.setPointSize(26);
        signLabel->setFont(font);
        signLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(signLabel);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(ComparasionWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);

        label_6 = new QLabel(ComparasionWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);

        sideA2Label = new QLineEdit(ComparasionWindow);
        sideA2Label->setObjectName(QString::fromUtf8("sideA2Label"));

        verticalLayout_2->addWidget(sideA2Label);

        label_8 = new QLabel(ComparasionWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_2->addWidget(label_8);

        sideB2Label = new QLineEdit(ComparasionWindow);
        sideB2Label->setObjectName(QString::fromUtf8("sideB2Label"));

        verticalLayout_2->addWidget(sideB2Label);

        label_9 = new QLabel(ComparasionWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_2->addWidget(label_9);

        sideC2Label = new QLineEdit(ComparasionWindow);
        sideC2Label->setObjectName(QString::fromUtf8("sideC2Label"));

        verticalLayout_2->addWidget(sideC2Label);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        compareButton = new QPushButton(ComparasionWindow);
        compareButton->setObjectName(QString::fromUtf8("compareButton"));

        horizontalLayout_2->addWidget(compareButton);

        exitButton = new QPushButton(ComparasionWindow);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        horizontalLayout_2->addWidget(exitButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 1);

        retranslateUi(ComparasionWindow);

        QMetaObject::connectSlotsByName(ComparasionWindow);
    } // setupUi

    void retranslateUi(QWidget *ComparasionWindow)
    {
        ComparasionWindow->setWindowTitle(QCoreApplication::translate("ComparasionWindow", "Comparator", nullptr));
        label_3->setText(QCoreApplication::translate("ComparasionWindow", "First triangle", nullptr));
        label_2->setText(QCoreApplication::translate("ComparasionWindow", "Side a:", nullptr));
        label_4->setText(QCoreApplication::translate("ComparasionWindow", "Side b:", nullptr));
        label_5->setText(QCoreApplication::translate("ComparasionWindow", "Side c:", nullptr));
        signLabel->setText(QString());
        label_7->setText(QCoreApplication::translate("ComparasionWindow", "Second triangle", nullptr));
        label_6->setText(QCoreApplication::translate("ComparasionWindow", "Side a:", nullptr));
        label_8->setText(QCoreApplication::translate("ComparasionWindow", "Side b:", nullptr));
        label_9->setText(QCoreApplication::translate("ComparasionWindow", "Side c:", nullptr));
        compareButton->setText(QCoreApplication::translate("ComparasionWindow", "Compare", nullptr));
        exitButton->setText(QCoreApplication::translate("ComparasionWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComparasionWindow: public Ui_ComparasionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPARASIONWINDOW_H
