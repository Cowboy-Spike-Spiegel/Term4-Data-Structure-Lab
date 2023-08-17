/********************************************************************************
** Form generated from reading UI file 'widget_lessonchange.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LESSONCHANGE_H
#define UI_WIDGET_LESSONCHANGE_H

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

class Ui_Widget_LessonChange
{
public:
    QComboBox *comboBox_Lesson;
    QPushButton *pushButton;
    QLineEdit *line_Name;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox_week;
    QComboBox *comboBox_location;
    QComboBox *comboBox_index;
    QGroupBox *groupBox;
    QRadioButton *radio_xitucheng;
    QRadioButton *radio_shahe;
    QLabel *label_4;
    QLineEdit *line_qun;
    QLineEdit *lineEdit_extra;

    void setupUi(QWidget *Widget_LessonChange)
    {
        if (Widget_LessonChange->objectName().isEmpty())
            Widget_LessonChange->setObjectName(QString::fromUtf8("Widget_LessonChange"));
        Widget_LessonChange->resize(364, 400);
        comboBox_Lesson = new QComboBox(Widget_LessonChange);
        comboBox_Lesson->setObjectName(QString::fromUtf8("comboBox_Lesson"));
        comboBox_Lesson->setGeometry(QRect(60, 50, 231, 26));
        pushButton = new QPushButton(Widget_LessonChange);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 340, 141, 31));
        line_Name = new QLineEdit(Widget_LessonChange);
        line_Name->setObjectName(QString::fromUtf8("line_Name"));
        line_Name->setGeometry(QRect(130, 130, 181, 30));
        label = new QLabel(Widget_LessonChange);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 101, 20));
        label_2 = new QLabel(Widget_LessonChange);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 100, 161, 20));
        label_3 = new QLabel(Widget_LessonChange);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 130, 69, 30));
        label_5 = new QLabel(Widget_LessonChange);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 220, 69, 20));
        label_6 = new QLabel(Widget_LessonChange);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 270, 69, 20));
        comboBox_week = new QComboBox(Widget_LessonChange);
        comboBox_week->setObjectName(QString::fromUtf8("comboBox_week"));
        comboBox_week->setGeometry(QRect(60, 240, 91, 26));
        comboBox_location = new QComboBox(Widget_LessonChange);
        comboBox_location->setObjectName(QString::fromUtf8("comboBox_location"));
        comboBox_location->setGeometry(QRect(180, 260, 131, 26));
        comboBox_index = new QComboBox(Widget_LessonChange);
        comboBox_index->setObjectName(QString::fromUtf8("comboBox_index"));
        comboBox_index->setGeometry(QRect(60, 290, 91, 26));
        groupBox = new QGroupBox(Widget_LessonChange);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(179, 210, 131, 51));
        radio_xitucheng = new QRadioButton(groupBox);
        radio_xitucheng->setObjectName(QString::fromUtf8("radio_xitucheng"));
        radio_xitucheng->setGeometry(QRect(10, 10, 118, 24));
        radio_shahe = new QRadioButton(groupBox);
        radio_shahe->setObjectName(QString::fromUtf8("radio_shahe"));
        radio_shahe->setGeometry(QRect(10, 30, 118, 24));
        label_4 = new QLabel(Widget_LessonChange);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 160, 69, 30));
        line_qun = new QLineEdit(Widget_LessonChange);
        line_qun->setObjectName(QString::fromUtf8("line_qun"));
        line_qun->setGeometry(QRect(130, 160, 181, 30));
        lineEdit_extra = new QLineEdit(Widget_LessonChange);
        lineEdit_extra->setObjectName(QString::fromUtf8("lineEdit_extra"));
        lineEdit_extra->setGeometry(QRect(180, 290, 131, 26));

        retranslateUi(Widget_LessonChange);

        QMetaObject::connectSlotsByName(Widget_LessonChange);
    } // setupUi

    void retranslateUi(QWidget *Widget_LessonChange)
    {
        Widget_LessonChange->setWindowTitle(QCoreApplication::translate("Widget_LessonChange", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget_LessonChange", "\344\277\256\346\224\271", nullptr));
        label->setText(QCoreApplication::translate("Widget_LessonChange", "\345\217\257\344\277\256\346\224\271\347\232\204\350\257\276\347\250\213", nullptr));
        label_2->setText(QCoreApplication::translate("Widget_LessonChange", "\345\217\257\346\233\264\346\226\260\347\232\204\345\255\227\346\256\265\357\274\210\345\217\257\345\244\232\351\200\211\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("Widget_LessonChange", "\350\257\276\347\250\213\345\220\215\347\247\260", nullptr));
        label_5->setText(QCoreApplication::translate("Widget_LessonChange", "\346\230\237\346\234\237\346\225\260", nullptr));
        label_6->setText(QCoreApplication::translate("Widget_LessonChange", "\350\212\202\346\225\260", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Widget_LessonChange", "\345\234\260\347\202\271", nullptr));
        radio_xitucheng->setText(QCoreApplication::translate("Widget_LessonChange", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));
        radio_shahe->setText(QCoreApplication::translate("Widget_LessonChange", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        label_4->setText(QCoreApplication::translate("Widget_LessonChange", "\350\257\276\347\250\213\347\276\244\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_LessonChange: public Ui_Widget_LessonChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LESSONCHANGE_H
