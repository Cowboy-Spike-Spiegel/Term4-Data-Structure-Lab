/********************************************************************************
** Form generated from reading UI file 'widget_lessontest.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LESSONTEST_H
#define UI_WIDGET_LESSONTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_LessonTest
{
public:
    QLabel *label_lesson;
    QComboBox *comboBox_lesson;
    QLabel *label_test;
    QLineEdit *lineEdit_name;
    QComboBox *comboBox_location;
    QGroupBox *groupBox;
    QRadioButton *radioButton_xitucheng;
    QRadioButton *radioButton_shahe;
    QPushButton *pushButton;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QLineEdit *lineEdit_extra;
    QLabel *label;

    void setupUi(QWidget *Widget_LessonTest)
    {
        if (Widget_LessonTest->objectName().isEmpty())
            Widget_LessonTest->setObjectName(QString::fromUtf8("Widget_LessonTest"));
        Widget_LessonTest->resize(350, 350);
        label_lesson = new QLabel(Widget_LessonTest);
        label_lesson->setObjectName(QString::fromUtf8("label_lesson"));
        label_lesson->setGeometry(QRect(50, 20, 69, 20));
        comboBox_lesson = new QComboBox(Widget_LessonTest);
        comboBox_lesson->setObjectName(QString::fromUtf8("comboBox_lesson"));
        comboBox_lesson->setGeometry(QRect(50, 40, 251, 26));
        label_test = new QLabel(Widget_LessonTest);
        label_test->setObjectName(QString::fromUtf8("label_test"));
        label_test->setGeometry(QRect(50, 100, 81, 30));
        lineEdit_name = new QLineEdit(Widget_LessonTest);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(130, 100, 171, 30));
        comboBox_location = new QComboBox(Widget_LessonTest);
        comboBox_location->setObjectName(QString::fromUtf8("comboBox_location"));
        comboBox_location->setGeometry(QRect(40, 250, 121, 26));
        groupBox = new QGroupBox(Widget_LessonTest);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(40, 140, 121, 81));
        radioButton_xitucheng = new QRadioButton(groupBox);
        radioButton_xitucheng->setObjectName(QString::fromUtf8("radioButton_xitucheng"));
        radioButton_xitucheng->setGeometry(QRect(20, 20, 91, 24));
        radioButton_shahe = new QRadioButton(groupBox);
        radioButton_shahe->setObjectName(QString::fromUtf8("radioButton_shahe"));
        radioButton_shahe->setGeometry(QRect(20, 50, 91, 24));
        pushButton = new QPushButton(Widget_LessonTest);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 300, 131, 41));
        dateEdit = new QDateEdit(Widget_LessonTest);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(170, 150, 131, 31));
        timeEdit = new QTimeEdit(Widget_LessonTest);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(170, 190, 131, 31));
        lineEdit_extra = new QLineEdit(Widget_LessonTest);
        lineEdit_extra->setObjectName(QString::fromUtf8("lineEdit_extra"));
        lineEdit_extra->setGeometry(QRect(180, 250, 121, 25));
        label = new QLabel(Widget_LessonTest);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 230, 69, 20));

        retranslateUi(Widget_LessonTest);

        QMetaObject::connectSlotsByName(Widget_LessonTest);
    } // setupUi

    void retranslateUi(QWidget *Widget_LessonTest)
    {
        Widget_LessonTest->setWindowTitle(QCoreApplication::translate("Widget_LessonTest", "Form", nullptr));
        label_lesson->setText(QCoreApplication::translate("Widget_LessonTest", "\345\217\257\351\200\211\350\257\276\347\250\213", nullptr));
        label_test->setText(QCoreApplication::translate("Widget_LessonTest", "\350\200\203\350\257\225\345\220\215\347\247\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget_LessonTest", "\346\240\241\345\214\272", nullptr));
        radioButton_xitucheng->setText(QCoreApplication::translate("Widget_LessonTest", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));
        radioButton_shahe->setText(QCoreApplication::translate("Widget_LessonTest", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget_LessonTest", "\346\267\273\345\212\240", nullptr));
        label->setText(QCoreApplication::translate("Widget_LessonTest", "\346\225\231\345\256\244\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_LessonTest: public Ui_Widget_LessonTest {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LESSONTEST_H
