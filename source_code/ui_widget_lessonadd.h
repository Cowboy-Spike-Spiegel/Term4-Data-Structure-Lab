/********************************************************************************
** Form generated from reading UI file 'widget_lessonadd.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LESSONADD_H
#define UI_WIDGET_LESSONADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_LessonAdd
{
public:
    QLabel *label;
    QLineEdit *line_Name;
    QComboBox *comboBox_location;
    QGroupBox *groupBox;
    QRadioButton *radio_xitucheng;
    QRadioButton *radio_shahe;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_week;
    QComboBox *comboBox_index;
    QComboBox *comboBox_class;
    QPushButton *pushButton_c;
    QPushButton *pushButton_s;
    QLineEdit *lineEdit_qun;
    QLabel *label_5;
    QLineEdit *lineEdit_extra;

    void setupUi(QWidget *Widget_LessonAdd)
    {
        if (Widget_LessonAdd->objectName().isEmpty())
            Widget_LessonAdd->setObjectName(QString::fromUtf8("Widget_LessonAdd"));
        Widget_LessonAdd->resize(450, 350);
        label = new QLabel(Widget_LessonAdd);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 100, 40));
        line_Name = new QLineEdit(Widget_LessonAdd);
        line_Name->setObjectName(QString::fromUtf8("line_Name"));
        line_Name->setGeometry(QRect(179, 30, 221, 40));
        comboBox_location = new QComboBox(Widget_LessonAdd);
        comboBox_location->setObjectName(QString::fromUtf8("comboBox_location"));
        comboBox_location->setGeometry(QRect(220, 220, 121, 26));
        groupBox = new QGroupBox(Widget_LessonAdd);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 150, 171, 61));
        radio_xitucheng = new QRadioButton(groupBox);
        radio_xitucheng->setObjectName(QString::fromUtf8("radio_xitucheng"));
        radio_xitucheng->setGeometry(QRect(0, 20, 118, 24));
        radio_shahe = new QRadioButton(groupBox);
        radio_shahe->setObjectName(QString::fromUtf8("radio_shahe"));
        radio_shahe->setGeometry(QRect(0, 40, 118, 24));
        label_2 = new QLabel(Widget_LessonAdd);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 150, 69, 20));
        label_3 = new QLabel(Widget_LessonAdd);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(110, 150, 69, 20));
        label_4 = new QLabel(Widget_LessonAdd);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 200, 151, 20));
        comboBox_week = new QComboBox(Widget_LessonAdd);
        comboBox_week->setObjectName(QString::fromUtf8("comboBox_week"));
        comboBox_week->setGeometry(QRect(50, 170, 51, 26));
        comboBox_index = new QComboBox(Widget_LessonAdd);
        comboBox_index->setObjectName(QString::fromUtf8("comboBox_index"));
        comboBox_index->setGeometry(QRect(110, 170, 81, 26));
        comboBox_class = new QComboBox(Widget_LessonAdd);
        comboBox_class->setObjectName(QString::fromUtf8("comboBox_class"));
        comboBox_class->setGeometry(QRect(50, 220, 141, 26));
        pushButton_c = new QPushButton(Widget_LessonAdd);
        pushButton_c->setObjectName(QString::fromUtf8("pushButton_c"));
        pushButton_c->setGeometry(QRect(90, 280, 131, 41));
        pushButton_s = new QPushButton(Widget_LessonAdd);
        pushButton_s->setObjectName(QString::fromUtf8("pushButton_s"));
        pushButton_s->setGeometry(QRect(220, 280, 131, 41));
        lineEdit_qun = new QLineEdit(Widget_LessonAdd);
        lineEdit_qun->setObjectName(QString::fromUtf8("lineEdit_qun"));
        lineEdit_qun->setGeometry(QRect(179, 80, 221, 40));
        label_5 = new QLabel(Widget_LessonAdd);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 80, 131, 40));
        lineEdit_extra = new QLineEdit(Widget_LessonAdd);
        lineEdit_extra->setObjectName(QString::fromUtf8("lineEdit_extra"));
        lineEdit_extra->setGeometry(QRect(340, 220, 51, 25));

        retranslateUi(Widget_LessonAdd);

        QMetaObject::connectSlotsByName(Widget_LessonAdd);
    } // setupUi

    void retranslateUi(QWidget *Widget_LessonAdd)
    {
        Widget_LessonAdd->setWindowTitle(QCoreApplication::translate("Widget_LessonAdd", "Form", nullptr));
        label->setText(QCoreApplication::translate("Widget_LessonAdd", "\350\257\276\347\250\213\345\220\215\347\247\260\357\274\210\345\277\205\345\241\253\357\274\211", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget_LessonAdd", "\344\270\212\350\257\276\345\234\260\347\202\271", nullptr));
        radio_xitucheng->setText(QCoreApplication::translate("Widget_LessonAdd", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));
        radio_shahe->setText(QCoreApplication::translate("Widget_LessonAdd", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        label_2->setText(QCoreApplication::translate("Widget_LessonAdd", "\344\270\212\350\257\276\346\230\237\346\234\237", nullptr));
        label_3->setText(QCoreApplication::translate("Widget_LessonAdd", "\344\270\212\350\257\276\350\212\202\346\225\260", nullptr));
        label_4->setText(QCoreApplication::translate("Widget_LessonAdd", "\344\270\212\350\257\276\347\217\255\347\272\247\357\274\210\345\277\205\344\277\256\345\241\253\357\274\211", nullptr));
        pushButton_c->setText(QCoreApplication::translate("Widget_LessonAdd", "\346\267\273\345\212\240\345\277\205\344\277\256\350\257\276\347\250\213", nullptr));
        pushButton_s->setText(QCoreApplication::translate("Widget_LessonAdd", "\346\267\273\345\212\240\351\200\211\344\277\256\350\257\276\347\250\213", nullptr));
        label_5->setText(QCoreApplication::translate("Widget_LessonAdd", "\350\257\276\347\250\213\347\276\244\345\217\267\357\274\210\351\200\211\345\241\253\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_LessonAdd: public Ui_Widget_LessonAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LESSONADD_H
