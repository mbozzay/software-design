/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QRadioButton *uniformRadioButton;
    QRadioButton *otherRadioButton;
    QRadioButton *normalRadioButton;
    QChartView *distributionChart;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 1000);
        MainWindow->setMinimumSize(QSize(1200, 1000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(400, 40, 411, 32));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        uniformRadioButton = new QRadioButton(gridLayoutWidget);
        uniformRadioButton->setObjectName(QString::fromUtf8("uniformRadioButton"));
        uniformRadioButton->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(uniformRadioButton, 0, 1, 1, 1);

        otherRadioButton = new QRadioButton(gridLayoutWidget);
        otherRadioButton->setObjectName(QString::fromUtf8("otherRadioButton"));

        gridLayout->addWidget(otherRadioButton, 0, 4, 1, 1);

        normalRadioButton = new QRadioButton(gridLayoutWidget);
        normalRadioButton->setObjectName(QString::fromUtf8("normalRadioButton"));
        normalRadioButton->setChecked(true);

        gridLayout->addWidget(normalRadioButton, 0, 2, 1, 1);

        distributionChart = new QChartView(centralwidget);
        distributionChart->setObjectName(QString::fromUtf8("distributionChart"));
        distributionChart->setGeometry(QRect(110, 90, 1000, 800));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(distributionChart->sizePolicy().hasHeightForWidth());
        distributionChart->setSizePolicy(sizePolicy1);
        distributionChart->setMinimumSize(QSize(1000, 800));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(normalRadioButton, SIGNAL(clicked()), MainWindow, SLOT(on_radioButton_clicked()));
        QObject::connect(otherRadioButton, SIGNAL(clicked()), MainWindow, SLOT(on_radioButton_clicked()));
        QObject::connect(uniformRadioButton, SIGNAL(clicked()), MainWindow, SLOT(on_radioButton_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        uniformRadioButton->setText(QCoreApplication::translate("MainWindow", "Uniform", nullptr));
        otherRadioButton->setText(QCoreApplication::translate("MainWindow", "Other", nullptr));
        normalRadioButton->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
