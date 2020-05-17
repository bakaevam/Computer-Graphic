/********************************************************************************
** Form generated from reading UI file 'Raytracing.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAYTRACING_H
#define UI_RAYTRACING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RaytracingClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RaytracingClass)
    {
        if (RaytracingClass->objectName().isEmpty())
            RaytracingClass->setObjectName(QString::fromUtf8("RaytracingClass"));
        RaytracingClass->resize(600, 400);
        menuBar = new QMenuBar(RaytracingClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        RaytracingClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RaytracingClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        RaytracingClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RaytracingClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        RaytracingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RaytracingClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RaytracingClass->setStatusBar(statusBar);

        retranslateUi(RaytracingClass);

        QMetaObject::connectSlotsByName(RaytracingClass);
    } // setupUi

    void retranslateUi(QMainWindow *RaytracingClass)
    {
        RaytracingClass->setWindowTitle(QCoreApplication::translate("RaytracingClass", "Raytracing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RaytracingClass: public Ui_RaytracingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAYTRACING_H
