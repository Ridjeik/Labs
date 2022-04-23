/********************************************************************************
** Form generated from reading UI file 'triangleviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLEVIEWER_H
#define UI_TRIANGLEVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <viewwidget.h>

QT_BEGIN_NAMESPACE

class Ui_TriangleViewer
{
public:
    QAction *actionTriangle;
    QAction *actionTriangles;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *calculationsFrame;
    QVBoxLayout *verticalLayout;
    QLabel *infoLabel;
    QLabel *perimeterLabel;
    QLabel *areaLabel;
    QLabel *anglesLabel;
    QLabel *mediansLabel;
    QLabel *rectangularLabel;
    QFrame *settingFrame;
    QVBoxLayout *verticalLayout_2;
    QLabel *setSidesLabel;
    QLabel *label_2;
    QLineEdit *sideAField;
    QLabel *label_3;
    QLineEdit *sideBField;
    QLabel *label_4;
    QLineEdit *sideCField;
    QPushButton *setSidesButton;
    QFrame *increaseFrame;
    QVBoxLayout *verticalLayout_3;
    QLabel *increaseLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *increaseField;
    QPushButton *increaseButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *multiplyField;
    QPushButton *multiplyButton;
    QSpacerItem *verticalSpacer_4;
    QFrame *imageFrame;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    ViewWidget *viewWidget;
    QGridLayout *gridLayout_2;
    QCheckBox *sidesCheckBox;
    QCheckBox *mediansCheckBox;
    QCheckBox *verticesCheckBox;
    QFrame *infoFrame;
    QVBoxLayout *verticalLayout_4;
    QLabel *sidesLabel;
    QLabel *sideALabel;
    QLabel *sideBLabel;
    QLabel *sideCLabel;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *createdTrianglesLabel;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QMenu *menuCompare;

    void setupUi(QMainWindow *TriangleViewer)
    {
        if (TriangleViewer->objectName().isEmpty())
            TriangleViewer->setObjectName(QString::fromUtf8("TriangleViewer"));
        TriangleViewer->resize(597, 622);
        actionTriangle = new QAction(TriangleViewer);
        actionTriangle->setObjectName(QString::fromUtf8("actionTriangle"));
        actionTriangles = new QAction(TriangleViewer);
        actionTriangles->setObjectName(QString::fromUtf8("actionTriangles"));
        centralwidget = new QWidget(TriangleViewer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(4);
        calculationsFrame = new QFrame(centralwidget);
        calculationsFrame->setObjectName(QString::fromUtf8("calculationsFrame"));
        calculationsFrame->setFrameShape(QFrame::StyledPanel);
        calculationsFrame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(calculationsFrame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        infoLabel = new QLabel(calculationsFrame);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));
        infoLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(infoLabel);

        perimeterLabel = new QLabel(calculationsFrame);
        perimeterLabel->setObjectName(QString::fromUtf8("perimeterLabel"));

        verticalLayout->addWidget(perimeterLabel);

        areaLabel = new QLabel(calculationsFrame);
        areaLabel->setObjectName(QString::fromUtf8("areaLabel"));

        verticalLayout->addWidget(areaLabel);

        anglesLabel = new QLabel(calculationsFrame);
        anglesLabel->setObjectName(QString::fromUtf8("anglesLabel"));

        verticalLayout->addWidget(anglesLabel);

        mediansLabel = new QLabel(calculationsFrame);
        mediansLabel->setObjectName(QString::fromUtf8("mediansLabel"));

        verticalLayout->addWidget(mediansLabel);

        rectangularLabel = new QLabel(calculationsFrame);
        rectangularLabel->setObjectName(QString::fromUtf8("rectangularLabel"));

        verticalLayout->addWidget(rectangularLabel);


        gridLayout->addWidget(calculationsFrame, 3, 0, 1, 1);

        settingFrame = new QFrame(centralwidget);
        settingFrame->setObjectName(QString::fromUtf8("settingFrame"));
        settingFrame->setFrameShape(QFrame::StyledPanel);
        settingFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(settingFrame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        setSidesLabel = new QLabel(settingFrame);
        setSidesLabel->setObjectName(QString::fromUtf8("setSidesLabel"));
        setSidesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(setSidesLabel);

        label_2 = new QLabel(settingFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        sideAField = new QLineEdit(settingFrame);
        sideAField->setObjectName(QString::fromUtf8("sideAField"));

        verticalLayout_2->addWidget(sideAField);

        label_3 = new QLabel(settingFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        sideBField = new QLineEdit(settingFrame);
        sideBField->setObjectName(QString::fromUtf8("sideBField"));

        verticalLayout_2->addWidget(sideBField);

        label_4 = new QLabel(settingFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        sideCField = new QLineEdit(settingFrame);
        sideCField->setObjectName(QString::fromUtf8("sideCField"));

        verticalLayout_2->addWidget(sideCField);

        setSidesButton = new QPushButton(settingFrame);
        setSidesButton->setObjectName(QString::fromUtf8("setSidesButton"));

        verticalLayout_2->addWidget(setSidesButton);


        gridLayout->addWidget(settingFrame, 3, 2, 1, 1);

        increaseFrame = new QFrame(centralwidget);
        increaseFrame->setObjectName(QString::fromUtf8("increaseFrame"));
        increaseFrame->setFrameShape(QFrame::StyledPanel);
        increaseFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_3 = new QVBoxLayout(increaseFrame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        increaseLabel = new QLabel(increaseFrame);
        increaseLabel->setObjectName(QString::fromUtf8("increaseLabel"));
        increaseLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(increaseLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        increaseField = new QLineEdit(increaseFrame);
        increaseField->setObjectName(QString::fromUtf8("increaseField"));

        horizontalLayout->addWidget(increaseField);

        increaseButton = new QPushButton(increaseFrame);
        increaseButton->setObjectName(QString::fromUtf8("increaseButton"));

        horizontalLayout->addWidget(increaseButton);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label_5 = new QLabel(increaseFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        multiplyField = new QLineEdit(increaseFrame);
        multiplyField->setObjectName(QString::fromUtf8("multiplyField"));

        horizontalLayout_5->addWidget(multiplyField);

        multiplyButton = new QPushButton(increaseFrame);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));

        horizontalLayout_5->addWidget(multiplyButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_4);


        gridLayout->addWidget(increaseFrame, 2, 2, 1, 1);

        imageFrame = new QFrame(centralwidget);
        imageFrame->setObjectName(QString::fromUtf8("imageFrame"));
        imageFrame->setFrameShape(QFrame::StyledPanel);
        imageFrame->setFrameShadow(QFrame::Sunken);
        imageFrame->setLineWidth(1);
        verticalLayout_5 = new QVBoxLayout(imageFrame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(imageFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        viewWidget = new ViewWidget(imageFrame);
        viewWidget->setObjectName(QString::fromUtf8("viewWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(viewWidget->sizePolicy().hasHeightForWidth());
        viewWidget->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(viewWidget);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        sidesCheckBox = new QCheckBox(imageFrame);
        sidesCheckBox->setObjectName(QString::fromUtf8("sidesCheckBox"));

        gridLayout_2->addWidget(sidesCheckBox, 0, 0, 1, 1);

        mediansCheckBox = new QCheckBox(imageFrame);
        mediansCheckBox->setObjectName(QString::fromUtf8("mediansCheckBox"));

        gridLayout_2->addWidget(mediansCheckBox, 0, 1, 1, 1);

        verticesCheckBox = new QCheckBox(imageFrame);
        verticesCheckBox->setObjectName(QString::fromUtf8("verticesCheckBox"));

        gridLayout_2->addWidget(verticesCheckBox, 1, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        verticalLayout_5->setStretch(1, 1);

        gridLayout->addWidget(imageFrame, 1, 0, 2, 1);

        infoFrame = new QFrame(centralwidget);
        infoFrame->setObjectName(QString::fromUtf8("infoFrame"));
        infoFrame->setFrameShape(QFrame::StyledPanel);
        infoFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_4 = new QVBoxLayout(infoFrame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        sidesLabel = new QLabel(infoFrame);
        sidesLabel->setObjectName(QString::fromUtf8("sidesLabel"));
        sidesLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(sidesLabel);

        sideALabel = new QLabel(infoFrame);
        sideALabel->setObjectName(QString::fromUtf8("sideALabel"));

        verticalLayout_4->addWidget(sideALabel);

        sideBLabel = new QLabel(infoFrame);
        sideBLabel->setObjectName(QString::fromUtf8("sideBLabel"));

        verticalLayout_4->addWidget(sideBLabel);

        sideCLabel = new QLabel(infoFrame);
        sideCLabel->setObjectName(QString::fromUtf8("sideCLabel"));

        verticalLayout_4->addWidget(sideCLabel);


        gridLayout->addWidget(infoFrame, 1, 2, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        createdTrianglesLabel = new QLabel(centralwidget);
        createdTrianglesLabel->setObjectName(QString::fromUtf8("createdTrianglesLabel"));

        horizontalLayout_4->addWidget(createdTrianglesLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 3);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(2, 1);
        TriangleViewer->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(TriangleViewer);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 22));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuCompare = new QMenu(menuBar);
        menuCompare->setObjectName(QString::fromUtf8("menuCompare"));
        TriangleViewer->setMenuBar(menuBar);

        menuBar->addAction(menuNew->menuAction());
        menuBar->addAction(menuCompare->menuAction());
        menuNew->addAction(actionTriangle);
        menuCompare->addAction(actionTriangles);

        retranslateUi(TriangleViewer);

        QMetaObject::connectSlotsByName(TriangleViewer);
    } // setupUi

    void retranslateUi(QMainWindow *TriangleViewer)
    {
        TriangleViewer->setWindowTitle(QCoreApplication::translate("TriangleViewer", "TriangleViewer", nullptr));
        actionTriangle->setText(QCoreApplication::translate("TriangleViewer", "Triangle", nullptr));
        actionTriangles->setText(QCoreApplication::translate("TriangleViewer", "Triangles", nullptr));
        infoLabel->setText(QCoreApplication::translate("TriangleViewer", "Information", nullptr));
        perimeterLabel->setText(QCoreApplication::translate("TriangleViewer", "Perimeter:", nullptr));
        areaLabel->setText(QCoreApplication::translate("TriangleViewer", "Area:", nullptr));
        anglesLabel->setText(QCoreApplication::translate("TriangleViewer", "Angles:", nullptr));
        mediansLabel->setText(QCoreApplication::translate("TriangleViewer", "Medians:", nullptr));
        rectangularLabel->setText(QCoreApplication::translate("TriangleViewer", "Is rectangular:", nullptr));
        setSidesLabel->setText(QCoreApplication::translate("TriangleViewer", "Set sides", nullptr));
        label_2->setText(QCoreApplication::translate("TriangleViewer", "Side a", nullptr));
        label_3->setText(QCoreApplication::translate("TriangleViewer", "Side b", nullptr));
        label_4->setText(QCoreApplication::translate("TriangleViewer", "Side c", nullptr));
        setSidesButton->setText(QCoreApplication::translate("TriangleViewer", "Set sides", nullptr));
        increaseLabel->setText(QCoreApplication::translate("TriangleViewer", "Increase sides", nullptr));
        increaseButton->setText(QCoreApplication::translate("TriangleViewer", "Increase", nullptr));
        label_5->setText(QCoreApplication::translate("TriangleViewer", "Multiply sides", nullptr));
        multiplyButton->setText(QCoreApplication::translate("TriangleViewer", "Multiply", nullptr));
        label->setText(QCoreApplication::translate("TriangleViewer", "Image", nullptr));
        sidesCheckBox->setText(QCoreApplication::translate("TriangleViewer", "Show sides", nullptr));
        mediansCheckBox->setText(QCoreApplication::translate("TriangleViewer", "Show medians", nullptr));
        verticesCheckBox->setText(QCoreApplication::translate("TriangleViewer", "Show vertices", nullptr));
        sidesLabel->setText(QCoreApplication::translate("TriangleViewer", "Sides", nullptr));
        sideALabel->setText(QCoreApplication::translate("TriangleViewer", "Side a:", nullptr));
        sideBLabel->setText(QCoreApplication::translate("TriangleViewer", "Side b:", nullptr));
        sideCLabel->setText(QCoreApplication::translate("TriangleViewer", "Side c:", nullptr));
        createdTrianglesLabel->setText(QCoreApplication::translate("TriangleViewer", "Created triangles: 0", nullptr));
        menuNew->setTitle(QCoreApplication::translate("TriangleViewer", "New", nullptr));
        menuCompare->setTitle(QCoreApplication::translate("TriangleViewer", "Compare", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriangleViewer: public Ui_TriangleViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLEVIEWER_H
