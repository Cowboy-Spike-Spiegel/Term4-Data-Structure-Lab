/********************************************************************************
** Form generated from reading UI file 'widget_lessontask.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LESSONTASK_H
#define UI_WIDGET_LESSONTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_LessonTask
{
public:
    QComboBox *comboBox;
    QLabel *label_lesson;
    QLabel *label_name;
    QLineEdit *lineEdit_name;
    QPushButton *pushButton;
    QLabel *label_date;
    QDateEdit *dateEdit;
    QLineEdit *lineEdit_hour;

    void setupUi(QWidget *Widget_LessonTask)
    {
        if (Widget_LessonTask->objectName().isEmpty())
            Widget_LessonTask->setObjectName(QString::fromUtf8("Widget_LessonTask"));
        Widget_LessonTask->resize(300, 250);
        comboBox = new QComboBox(Widget_LessonTask);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(40, 40, 231, 26));
        label_lesson = new QLabel(Widget_LessonTask);
        label_lesson->setObjectName(QString::fromUtf8("label_lesson"));
        label_lesson->setGeometry(QRect(40, 20, 69, 20));
        label_name = new QLabel(Widget_LessonTask);
        label_name->setObjectName(QString::fromUtf8("label_name"));
        label_name->setGeometry(QRect(40, 90, 69, 30));
        lineEdit_name = new QLineEdit(Widget_LessonTask);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(110, 90, 161, 30));
        pushButton = new QPushButton(Widget_LessonTask);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 190, 101, 29));
        label_date = new QLabel(Widget_LessonTask);
        label_date->setObjectName(QString::fromUtf8("label_date"));
        label_date->setGeometry(QRect(40, 140, 71, 31));
        dateEdit = new QDateEdit(Widget_LessonTask);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(110, 140, 101, 31));
        lineEdit_hour = new QLineEdit(Widget_LessonTask);
        lineEdit_hour->setObjectName(QString::fromUtf8("lineEdit_hour"));
        lineEdit_hour->setGeometry(QRect(220, 140, 51, 31));

        retranslateUi(Widget_LessonTask);

        QMetaObject::connectSlotsByName(Widget_LessonTask);
    } // setupUi

    void retranslateUi(QWidget *Widget_LessonTask)
    {
        Widget_LessonTask->setWindowTitle(QCoreApplication::translate("Widget_LessonTask", "Form", nullptr));
        label_lesson->setText(QCoreApplication::translate("Widget_LessonTask", "\345\217\257\351\200\211\350\257\276\347\250\213", nullptr));
        label_name->setText(QCoreApplication::translate("Widget_LessonTask", "\344\275\234\344\270\232\345\220\215\347\247\260", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget_LessonTask", "\346\267\273\345\212\240", nullptr));
        label_date->setText(QCoreApplication::translate("Widget_LessonTask", "\346\210\252\346\255\242\346\227\245\346\234\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_LessonTask: public Ui_Widget_LessonTask {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LESSONTASK_H
