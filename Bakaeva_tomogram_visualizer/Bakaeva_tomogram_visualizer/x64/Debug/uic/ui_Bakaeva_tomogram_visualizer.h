/********************************************************************************
** Form generated from reading UI file 'Bakaeva_tomogram_visualizer.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAKAEVA_TOMOGRAM_VISUALIZER_H
#define UI_BAKAEVA_TOMOGRAM_VISUALIZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bakaeva_tomogram_visualizerClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Bakaeva_tomogram_visualizerClass)
    {
        if (Bakaeva_tomogram_visualizerClass->objectName().isEmpty())
            Bakaeva_tomogram_visualizerClass->setObjectName(QString::fromUtf8("Bakaeva_tomogram_visualizerClass"));
        Bakaeva_tomogram_visualizerClass->resize(600, 400);
        menuBar = new QMenuBar(Bakaeva_tomogram_visualizerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Bakaeva_tomogram_visualizerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Bakaeva_tomogram_visualizerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Bakaeva_tomogram_visualizerClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Bakaeva_tomogram_visualizerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Bakaeva_tomogram_visualizerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Bakaeva_tomogram_visualizerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Bakaeva_tomogram_visualizerClass->setStatusBar(statusBar);

        retranslateUi(Bakaeva_tomogram_visualizerClass);

        QMetaObject::connectSlotsByName(Bakaeva_tomogram_visualizerClass);
    } // setupUi

    void retranslateUi(QMainWindow *Bakaeva_tomogram_visualizerClass)
    {
        Bakaeva_tomogram_visualizerClass->setWindowTitle(QCoreApplication::translate("Bakaeva_tomogram_visualizerClass", "Bakaeva_tomogram_visualizer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Bakaeva_tomogram_visualizerClass: public Ui_Bakaeva_tomogram_visualizerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAKAEVA_TOMOGRAM_VISUALIZER_H
