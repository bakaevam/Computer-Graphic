/********************************************************************************
** Form generated from reading UI file 'dialogminmax.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMINMAX_H
#define UI_DIALOGMINMAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogMinMax
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *minLineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *maxLineEdit;

    void setupUi(QDialog *DialogMinMax)
    {
        if (DialogMinMax->objectName().isEmpty())
            DialogMinMax->setObjectName(QString::fromUtf8("DialogMinMax"));
        DialogMinMax->resize(362, 140);
        horizontalLayoutWidget = new QWidget(DialogMinMax);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 221, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);

        horizontalLayout->addWidget(label);

        minLineEdit = new QLineEdit(horizontalLayoutWidget);
        minLineEdit->setObjectName(QString::fromUtf8("minLineEdit"));

        horizontalLayout->addWidget(minLineEdit);

        pushButton = new QPushButton(DialogMinMax);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 40, 93, 28));
        pushButton_2 = new QPushButton(DialogMinMax);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 80, 93, 28));
        horizontalLayoutWidget_2 = new QWidget(DialogMinMax);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(8, 60, 221, 69));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::NoFrame);

        horizontalLayout_2->addWidget(label_2);

        maxLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        maxLineEdit->setObjectName(QString::fromUtf8("maxLineEdit"));

        horizontalLayout_2->addWidget(maxLineEdit);


        retranslateUi(DialogMinMax);
        QObject::connect(pushButton_2, SIGNAL(clicked()), DialogMinMax, SLOT(reject()));

        pushButton->setDefault(true);


        QMetaObject::connectSlotsByName(DialogMinMax);
    } // setupUi

    void retranslateUi(QDialog *DialogMinMax)
    {
        DialogMinMax->setWindowTitle(QCoreApplication::translate("DialogMinMax", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogMinMax", "min", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogMinMax", "OK", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DialogMinMax", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("DialogMinMax", "max", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogMinMax: public Ui_DialogMinMax {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMINMAX_H
