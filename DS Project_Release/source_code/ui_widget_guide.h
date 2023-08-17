/********************************************************************************
** Form generated from reading UI file 'widget_guide.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_GUIDE_H
#define UI_WIDGET_GUIDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Guide
{
public:
    QComboBox *comboBox_Dest;
    QGroupBox *groupBox_Dest;
    QRadioButton *shahe_Dest;
    QRadioButton *xitucheng_Dest;
    QGroupBox *groupBox_Source;
    QRadioButton *shahe_Source;
    QRadioButton *xitucheng_Source;
    QComboBox *comboBox_Source;
    QPushButton *Button_Search;
    QGroupBox *groupBox_Mode;
    QRadioButton *Mode_1;
    QRadioButton *Mode_2;
    QRadioButton *Mode_3;
    QPushButton *Button_Search_2;
    QTextEdit *textEdit;
    QPushButton *pushButton_show;
    QPushButton *pushButton_clear;
    QComboBox *comboBox_lesson;
    QLabel *label;
    QPushButton *pushButton_more;

    void setupUi(QWidget *Widget_Guide)
    {
        if (Widget_Guide->objectName().isEmpty())
            Widget_Guide->setObjectName(QString::fromUtf8("Widget_Guide"));
        Widget_Guide->resize(1400, 800);
        comboBox_Dest = new QComboBox(Widget_Guide);
        comboBox_Dest->setObjectName(QString::fromUtf8("comboBox_Dest"));
        comboBox_Dest->setGeometry(QRect(430, 620, 181, 31));
        groupBox_Dest = new QGroupBox(Widget_Guide);
        groupBox_Dest->setObjectName(QString::fromUtf8("groupBox_Dest"));
        groupBox_Dest->setGeometry(QRect(330, 620, 101, 91));
        shahe_Dest = new QRadioButton(groupBox_Dest);
        shahe_Dest->setObjectName(QString::fromUtf8("shahe_Dest"));
        shahe_Dest->setGeometry(QRect(0, 30, 118, 24));
        xitucheng_Dest = new QRadioButton(groupBox_Dest);
        xitucheng_Dest->setObjectName(QString::fromUtf8("xitucheng_Dest"));
        xitucheng_Dest->setGeometry(QRect(0, 60, 118, 24));
        groupBox_Source = new QGroupBox(Widget_Guide);
        groupBox_Source->setObjectName(QString::fromUtf8("groupBox_Source"));
        groupBox_Source->setGeometry(QRect(90, 620, 101, 91));
        shahe_Source = new QRadioButton(groupBox_Source);
        shahe_Source->setObjectName(QString::fromUtf8("shahe_Source"));
        shahe_Source->setGeometry(QRect(0, 30, 118, 24));
        xitucheng_Source = new QRadioButton(groupBox_Source);
        xitucheng_Source->setObjectName(QString::fromUtf8("xitucheng_Source"));
        xitucheng_Source->setGeometry(QRect(0, 60, 118, 24));
        comboBox_Source = new QComboBox(Widget_Guide);
        comboBox_Source->setObjectName(QString::fromUtf8("comboBox_Source"));
        comboBox_Source->setGeometry(QRect(190, 620, 111, 31));
        Button_Search = new QPushButton(Widget_Guide);
        Button_Search->setObjectName(QString::fromUtf8("Button_Search"));
        Button_Search->setGeometry(QRect(370, 740, 81, 41));
        groupBox_Mode = new QGroupBox(Widget_Guide);
        groupBox_Mode->setObjectName(QString::fromUtf8("groupBox_Mode"));
        groupBox_Mode->setGeometry(QRect(20, 730, 351, 51));
        Mode_1 = new QRadioButton(groupBox_Mode);
        Mode_1->setObjectName(QString::fromUtf8("Mode_1"));
        Mode_1->setGeometry(QRect(10, 20, 101, 24));
        Mode_2 = new QRadioButton(groupBox_Mode);
        Mode_2->setObjectName(QString::fromUtf8("Mode_2"));
        Mode_2->setGeometry(QRect(110, 20, 101, 24));
        Mode_3 = new QRadioButton(groupBox_Mode);
        Mode_3->setObjectName(QString::fromUtf8("Mode_3"));
        Mode_3->setGeometry(QRect(210, 20, 131, 24));
        Button_Search_2 = new QPushButton(Widget_Guide);
        Button_Search_2->setObjectName(QString::fromUtf8("Button_Search_2"));
        Button_Search_2->setGeometry(QRect(580, 740, 171, 41));
        textEdit = new QTextEdit(Widget_Guide);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(760, 620, 621, 161));
        pushButton_show = new QPushButton(Widget_Guide);
        pushButton_show->setObjectName(QString::fromUtf8("pushButton_show"));
        pushButton_show->setGeometry(QRect(20, 620, 51, 29));
        pushButton_clear = new QPushButton(Widget_Guide);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(20, 670, 51, 29));
        comboBox_lesson = new QComboBox(Widget_Guide);
        comboBox_lesson->setObjectName(QString::fromUtf8("comboBox_lesson"));
        comboBox_lesson->setGeometry(QRect(580, 701, 171, 31));
        label = new QLabel(Widget_Guide);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 680, 69, 20));
        pushButton_more = new QPushButton(Widget_Guide);
        pushButton_more->setObjectName(QString::fromUtf8("pushButton_more"));
        pushButton_more->setGeometry(QRect(450, 740, 121, 41));

        retranslateUi(Widget_Guide);

        QMetaObject::connectSlotsByName(Widget_Guide);
    } // setupUi

    void retranslateUi(QWidget *Widget_Guide)
    {
        Widget_Guide->setWindowTitle(QCoreApplication::translate("Widget_Guide", "Form", nullptr));
        groupBox_Dest->setTitle(QCoreApplication::translate("Widget_Guide", "\347\233\256\347\232\204\346\240\241\345\214\272", nullptr));
        shahe_Dest->setText(QCoreApplication::translate("Widget_Guide", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        xitucheng_Dest->setText(QCoreApplication::translate("Widget_Guide", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));
        groupBox_Source->setTitle(QCoreApplication::translate("Widget_Guide", "\345\207\272\345\217\221\346\240\241\345\214\272", nullptr));
        shahe_Source->setText(QCoreApplication::translate("Widget_Guide", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        xitucheng_Source->setText(QCoreApplication::translate("Widget_Guide", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));
        Button_Search->setText(QCoreApplication::translate("Widget_Guide", "\346\237\245\350\257\242", nullptr));
        groupBox_Mode->setTitle(QCoreApplication::translate("Widget_Guide", "\346\250\241\345\274\217", nullptr));
        Mode_1->setText(QCoreApplication::translate("Widget_Guide", "\346\255\245\350\241\214|\350\267\257\347\250\213", nullptr));
        Mode_2->setText(QCoreApplication::translate("Widget_Guide", "\346\255\245\350\241\214|\346\227\266\351\227\264", nullptr));
        Mode_3->setText(QCoreApplication::translate("Widget_Guide", "\346\255\245\350\241\214/\351\252\221\350\275\246|\346\227\266\351\227\264", nullptr));
        Button_Search_2->setText(QCoreApplication::translate("Widget_Guide", "\350\257\276\347\250\213\344\276\277\346\215\267\345\257\274\350\210\252", nullptr));
        pushButton_show->setText(QCoreApplication::translate("Widget_Guide", "\346\230\276\347\244\272", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("Widget_Guide", "\346\270\205\351\231\244", nullptr));
        label->setText(QCoreApplication::translate("Widget_Guide", "\351\200\211\346\213\251\350\257\276\347\250\213", nullptr));
        pushButton_more->setText(QCoreApplication::translate("Widget_Guide", "\345\244\232\350\267\257\345\276\204\345\274\200\345\205\263", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Guide: public Ui_Widget_Guide {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_GUIDE_H
