/********************************************************************************
** Form generated from reading UI file 'widget_clock.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CLOCK_H
#define UI_WIDGET_CLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Clock
{
public:
    QPushButton *pushButton_Once;
    QPushButton *pushButton_Dayly;
    QPushButton *pushButton_Weekly;
    QLineEdit *lineEdit_Name;
    QLineEdit *lineEdit_Hour;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QDateEdit *dateEdit;
    QComboBox *comboBox;

    void setupUi(QWidget *Widget_Clock)
    {
        if (Widget_Clock->objectName().isEmpty())
            Widget_Clock->setObjectName(QString::fromUtf8("Widget_Clock"));
        Widget_Clock->resize(355, 218);
        pushButton_Once = new QPushButton(Widget_Clock);
        pushButton_Once->setObjectName(QString::fromUtf8("pushButton_Once"));
        pushButton_Once->setGeometry(QRect(30, 150, 121, 40));
        pushButton_Dayly = new QPushButton(Widget_Clock);
        pushButton_Dayly->setObjectName(QString::fromUtf8("pushButton_Dayly"));
        pushButton_Dayly->setGeometry(QRect(229, 30, 111, 40));
        pushButton_Weekly = new QPushButton(Widget_Clock);
        pushButton_Weekly->setObjectName(QString::fromUtf8("pushButton_Weekly"));
        pushButton_Weekly->setGeometry(QRect(170, 150, 121, 40));
        lineEdit_Name = new QLineEdit(Widget_Clock);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setGeometry(QRect(20, 40, 101, 31));
        lineEdit_Hour = new QLineEdit(Widget_Clock);
        lineEdit_Hour->setObjectName(QString::fromUtf8("lineEdit_Hour"));
        lineEdit_Hour->setGeometry(QRect(130, 40, 81, 31));
        label = new QLabel(Widget_Clock);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 101, 20));
        label_2 = new QLabel(Widget_Clock);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 20, 81, 20));
        label_6 = new QLabel(Widget_Clock);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 90, 121, 20));
        label_7 = new QLabel(Widget_Clock);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(170, 90, 121, 20));
        dateEdit = new QDateEdit(Widget_Clock);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(30, 110, 121, 31));
        comboBox = new QComboBox(Widget_Clock);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(170, 110, 121, 31));

        retranslateUi(Widget_Clock);

        QMetaObject::connectSlotsByName(Widget_Clock);
    } // setupUi

    void retranslateUi(QWidget *Widget_Clock)
    {
        Widget_Clock->setWindowTitle(QCoreApplication::translate("Widget_Clock", "Form", nullptr));
        pushButton_Once->setText(QCoreApplication::translate("Widget_Clock", "\346\267\273\345\212\240\345\215\225\346\254\241\351\227\271\351\222\237", nullptr));
        pushButton_Dayly->setText(QCoreApplication::translate("Widget_Clock", "\346\267\273\345\212\240\346\227\245\345\270\270\351\227\271\351\222\237", nullptr));
        pushButton_Weekly->setText(QCoreApplication::translate("Widget_Clock", "\346\267\273\345\212\240\346\257\217\345\221\250\351\227\271\351\222\237", nullptr));
        lineEdit_Hour->setText(QString());
        label->setText(QCoreApplication::translate("Widget_Clock", "\345\220\215\347\247\260\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("Widget_Clock", "\345\260\217\346\227\266\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        label_6->setText(QCoreApplication::translate("Widget_Clock", "\357\274\210\345\215\225\346\254\241\351\231\204\345\212\240\346\225\260\346\215\256\357\274\211", nullptr));
        label_7->setText(QCoreApplication::translate("Widget_Clock", "\357\274\210\346\257\217\345\221\250\351\231\204\345\212\240\346\225\260\346\215\256\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Clock: public Ui_Widget_Clock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CLOCK_H
