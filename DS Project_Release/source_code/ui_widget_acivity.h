/********************************************************************************
** Form generated from reading UI file 'widget_acivity.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_ACIVITY_H
#define UI_WIDGET_ACIVITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Acivity
{
public:
    QLineEdit *edit_Name;
    QPushButton *Add_Acivity;
    QComboBox *comboBox;
    QGroupBox *groupBox_building;
    QRadioButton *radio_IsXiTuCheng;
    QRadioButton *radio_IsShaHe;
    QGroupBox *groupBox_acivity;
    QRadioButton *radio_ForSingal;
    QRadioButton *radio_ForPeople;
    QComboBox *comboBox_label;
    QDateEdit *dateEdit;
    QComboBox *comboBox_startHour;
    QComboBox *comboBox_endHour;
    QTextEdit *textEdit;
    QPushButton *pushButton_single;
    QPushButton *pushButton_allPeople;
    QLineEdit *lineEdit_select;
    QPushButton *pushButton_select;
    QPushButton *pushButton_timePaixu;
    QPushButton *pushButton_namePaixu;
    QComboBox *comboBox_labelSelect;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox_event;
    QPushButton *pushButton_eventDelete;

    void setupUi(QWidget *Widget_Acivity)
    {
        if (Widget_Acivity->objectName().isEmpty())
            Widget_Acivity->setObjectName(QString::fromUtf8("Widget_Acivity"));
        Widget_Acivity->resize(1200, 800);
        edit_Name = new QLineEdit(Widget_Acivity);
        edit_Name->setObjectName(QString::fromUtf8("edit_Name"));
        edit_Name->setGeometry(QRect(120, 80, 251, 41));
        Add_Acivity = new QPushButton(Widget_Acivity);
        Add_Acivity->setObjectName(QString::fromUtf8("Add_Acivity"));
        Add_Acivity->setGeometry(QRect(970, 70, 201, 71));
        comboBox = new QComboBox(Widget_Acivity);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(580, 130, 151, 31));
        groupBox_building = new QGroupBox(Widget_Acivity);
        groupBox_building->setObjectName(QString::fromUtf8("groupBox_building"));
        groupBox_building->setGeometry(QRect(580, 40, 120, 91));
        radio_IsXiTuCheng = new QRadioButton(groupBox_building);
        radio_IsXiTuCheng->setObjectName(QString::fromUtf8("radio_IsXiTuCheng"));
        radio_IsXiTuCheng->setGeometry(QRect(10, 30, 118, 24));
        radio_IsShaHe = new QRadioButton(groupBox_building);
        radio_IsShaHe->setObjectName(QString::fromUtf8("radio_IsShaHe"));
        radio_IsShaHe->setGeometry(QRect(10, 60, 118, 24));
        groupBox_acivity = new QGroupBox(Widget_Acivity);
        groupBox_acivity->setObjectName(QString::fromUtf8("groupBox_acivity"));
        groupBox_acivity->setGeometry(QRect(430, 40, 111, 91));
        radio_ForSingal = new QRadioButton(groupBox_acivity);
        radio_ForSingal->setObjectName(QString::fromUtf8("radio_ForSingal"));
        radio_ForSingal->setGeometry(QRect(10, 30, 81, 24));
        radio_ForPeople = new QRadioButton(groupBox_acivity);
        radio_ForPeople->setObjectName(QString::fromUtf8("radio_ForPeople"));
        radio_ForPeople->setGeometry(QRect(10, 60, 81, 24));
        comboBox_label = new QComboBox(Widget_Acivity);
        comboBox_label->setObjectName(QString::fromUtf8("comboBox_label"));
        comboBox_label->setGeometry(QRect(430, 130, 111, 31));
        dateEdit = new QDateEdit(Widget_Acivity);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(770, 60, 141, 51));
        comboBox_startHour = new QComboBox(Widget_Acivity);
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->addItem(QString());
        comboBox_startHour->setObjectName(QString::fromUtf8("comboBox_startHour"));
        comboBox_startHour->setGeometry(QRect(770, 120, 61, 22));
        comboBox_endHour = new QComboBox(Widget_Acivity);
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->addItem(QString());
        comboBox_endHour->setObjectName(QString::fromUtf8("comboBox_endHour"));
        comboBox_endHour->setGeometry(QRect(850, 120, 61, 22));
        textEdit = new QTextEdit(Widget_Acivity);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(180, 200, 991, 571));
        pushButton_single = new QPushButton(Widget_Acivity);
        pushButton_single->setObjectName(QString::fromUtf8("pushButton_single"));
        pushButton_single->setGeometry(QRect(30, 230, 131, 41));
        pushButton_allPeople = new QPushButton(Widget_Acivity);
        pushButton_allPeople->setObjectName(QString::fromUtf8("pushButton_allPeople"));
        pushButton_allPeople->setGeometry(QRect(30, 270, 131, 41));
        lineEdit_select = new QLineEdit(Widget_Acivity);
        lineEdit_select->setObjectName(QString::fromUtf8("lineEdit_select"));
        lineEdit_select->setGeometry(QRect(30, 390, 131, 31));
        pushButton_select = new QPushButton(Widget_Acivity);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));
        pushButton_select->setGeometry(QRect(30, 420, 131, 41));
        pushButton_timePaixu = new QPushButton(Widget_Acivity);
        pushButton_timePaixu->setObjectName(QString::fromUtf8("pushButton_timePaixu"));
        pushButton_timePaixu->setGeometry(QRect(80, 520, 75, 24));
        pushButton_namePaixu = new QPushButton(Widget_Acivity);
        pushButton_namePaixu->setObjectName(QString::fromUtf8("pushButton_namePaixu"));
        pushButton_namePaixu->setGeometry(QRect(80, 540, 75, 24));
        comboBox_labelSelect = new QComboBox(Widget_Acivity);
        comboBox_labelSelect->setObjectName(QString::fromUtf8("comboBox_labelSelect"));
        comboBox_labelSelect->setGeometry(QRect(30, 360, 131, 31));
        label = new QLabel(Widget_Acivity);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 340, 31, 16));
        label_2 = new QLabel(Widget_Acivity);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 60, 71, 16));
        comboBox_event = new QComboBox(Widget_Acivity);
        comboBox_event->setObjectName(QString::fromUtf8("comboBox_event"));
        comboBox_event->setGeometry(QRect(30, 700, 131, 31));
        pushButton_eventDelete = new QPushButton(Widget_Acivity);
        pushButton_eventDelete->setObjectName(QString::fromUtf8("pushButton_eventDelete"));
        pushButton_eventDelete->setGeometry(QRect(30, 740, 131, 31));

        retranslateUi(Widget_Acivity);

        QMetaObject::connectSlotsByName(Widget_Acivity);
    } // setupUi

    void retranslateUi(QWidget *Widget_Acivity)
    {
        Widget_Acivity->setWindowTitle(QCoreApplication::translate("Widget_Acivity", "Form", nullptr));
        Add_Acivity->setText(QCoreApplication::translate("Widget_Acivity", "\346\267\273\345\212\240\346\264\273\345\212\250", nullptr));
        groupBox_building->setTitle(QCoreApplication::translate("Widget_Acivity", "\346\240\241\345\214\272", nullptr));
        radio_IsXiTuCheng->setText(QCoreApplication::translate("Widget_Acivity", "\350\245\277\345\234\237\345\237\216\346\240\241\345\214\272", nullptr));
        radio_IsShaHe->setText(QCoreApplication::translate("Widget_Acivity", "\346\262\231\346\262\263\346\240\241\345\214\272", nullptr));
        groupBox_acivity->setTitle(QCoreApplication::translate("Widget_Acivity", "\346\264\273\345\212\250\347\261\273\345\236\213", nullptr));
        radio_ForSingal->setText(QCoreApplication::translate("Widget_Acivity", "\344\270\252\344\272\272\346\264\273\345\212\250", nullptr));
        radio_ForPeople->setText(QCoreApplication::translate("Widget_Acivity", "\351\233\206\344\275\223\346\264\273\345\212\250", nullptr));
        comboBox_startHour->setItemText(0, QCoreApplication::translate("Widget_Acivity", "0", nullptr));
        comboBox_startHour->setItemText(1, QCoreApplication::translate("Widget_Acivity", "1", nullptr));
        comboBox_startHour->setItemText(2, QCoreApplication::translate("Widget_Acivity", "2", nullptr));
        comboBox_startHour->setItemText(3, QCoreApplication::translate("Widget_Acivity", "3", nullptr));
        comboBox_startHour->setItemText(4, QCoreApplication::translate("Widget_Acivity", "4", nullptr));
        comboBox_startHour->setItemText(5, QCoreApplication::translate("Widget_Acivity", "5", nullptr));
        comboBox_startHour->setItemText(6, QCoreApplication::translate("Widget_Acivity", "6", nullptr));
        comboBox_startHour->setItemText(7, QCoreApplication::translate("Widget_Acivity", "7", nullptr));
        comboBox_startHour->setItemText(8, QCoreApplication::translate("Widget_Acivity", "8", nullptr));
        comboBox_startHour->setItemText(9, QCoreApplication::translate("Widget_Acivity", "9", nullptr));
        comboBox_startHour->setItemText(10, QCoreApplication::translate("Widget_Acivity", "10", nullptr));
        comboBox_startHour->setItemText(11, QCoreApplication::translate("Widget_Acivity", "11", nullptr));
        comboBox_startHour->setItemText(12, QCoreApplication::translate("Widget_Acivity", "12", nullptr));
        comboBox_startHour->setItemText(13, QCoreApplication::translate("Widget_Acivity", "13", nullptr));
        comboBox_startHour->setItemText(14, QCoreApplication::translate("Widget_Acivity", "14", nullptr));
        comboBox_startHour->setItemText(15, QCoreApplication::translate("Widget_Acivity", "15", nullptr));
        comboBox_startHour->setItemText(16, QCoreApplication::translate("Widget_Acivity", "16", nullptr));
        comboBox_startHour->setItemText(17, QCoreApplication::translate("Widget_Acivity", "17", nullptr));
        comboBox_startHour->setItemText(18, QCoreApplication::translate("Widget_Acivity", "18", nullptr));
        comboBox_startHour->setItemText(19, QCoreApplication::translate("Widget_Acivity", "19", nullptr));
        comboBox_startHour->setItemText(20, QCoreApplication::translate("Widget_Acivity", "20", nullptr));
        comboBox_startHour->setItemText(21, QCoreApplication::translate("Widget_Acivity", "21", nullptr));
        comboBox_startHour->setItemText(22, QCoreApplication::translate("Widget_Acivity", "22", nullptr));
        comboBox_startHour->setItemText(23, QCoreApplication::translate("Widget_Acivity", "23", nullptr));

        comboBox_endHour->setItemText(0, QCoreApplication::translate("Widget_Acivity", "0", nullptr));
        comboBox_endHour->setItemText(1, QCoreApplication::translate("Widget_Acivity", "1", nullptr));
        comboBox_endHour->setItemText(2, QCoreApplication::translate("Widget_Acivity", "2", nullptr));
        comboBox_endHour->setItemText(3, QCoreApplication::translate("Widget_Acivity", "3", nullptr));
        comboBox_endHour->setItemText(4, QCoreApplication::translate("Widget_Acivity", "4", nullptr));
        comboBox_endHour->setItemText(5, QCoreApplication::translate("Widget_Acivity", "5", nullptr));
        comboBox_endHour->setItemText(6, QCoreApplication::translate("Widget_Acivity", "6", nullptr));
        comboBox_endHour->setItemText(7, QCoreApplication::translate("Widget_Acivity", "7", nullptr));
        comboBox_endHour->setItemText(8, QCoreApplication::translate("Widget_Acivity", "8", nullptr));
        comboBox_endHour->setItemText(9, QCoreApplication::translate("Widget_Acivity", "9", nullptr));
        comboBox_endHour->setItemText(10, QCoreApplication::translate("Widget_Acivity", "10", nullptr));
        comboBox_endHour->setItemText(11, QCoreApplication::translate("Widget_Acivity", "11", nullptr));
        comboBox_endHour->setItemText(12, QCoreApplication::translate("Widget_Acivity", "12", nullptr));
        comboBox_endHour->setItemText(13, QCoreApplication::translate("Widget_Acivity", "13", nullptr));
        comboBox_endHour->setItemText(14, QCoreApplication::translate("Widget_Acivity", "14", nullptr));
        comboBox_endHour->setItemText(15, QCoreApplication::translate("Widget_Acivity", "15", nullptr));
        comboBox_endHour->setItemText(16, QCoreApplication::translate("Widget_Acivity", "16", nullptr));
        comboBox_endHour->setItemText(17, QCoreApplication::translate("Widget_Acivity", "17", nullptr));
        comboBox_endHour->setItemText(18, QCoreApplication::translate("Widget_Acivity", "18", nullptr));
        comboBox_endHour->setItemText(19, QCoreApplication::translate("Widget_Acivity", "19", nullptr));
        comboBox_endHour->setItemText(20, QCoreApplication::translate("Widget_Acivity", "20", nullptr));
        comboBox_endHour->setItemText(21, QCoreApplication::translate("Widget_Acivity", "21", nullptr));
        comboBox_endHour->setItemText(22, QCoreApplication::translate("Widget_Acivity", "22", nullptr));
        comboBox_endHour->setItemText(23, QCoreApplication::translate("Widget_Acivity", "23", nullptr));

        pushButton_single->setText(QCoreApplication::translate("Widget_Acivity", "\346\237\245\350\257\242\344\270\252\344\272\272\346\264\273\345\212\250", nullptr));
        pushButton_allPeople->setText(QCoreApplication::translate("Widget_Acivity", "\346\237\245\350\257\242\351\233\206\344\275\223\346\264\273\345\212\250", nullptr));
        pushButton_select->setText(QCoreApplication::translate("Widget_Acivity", "\346\237\245\350\257\242", nullptr));
        pushButton_timePaixu->setText(QCoreApplication::translate("Widget_Acivity", "\346\227\266\351\227\264\346\216\222\345\272\217", nullptr));
        pushButton_namePaixu->setText(QCoreApplication::translate("Widget_Acivity", "\345\220\215\347\247\260\346\216\222\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("Widget_Acivity", "\347\255\233\351\200\211", nullptr));
        label_2->setText(QCoreApplication::translate("Widget_Acivity", "\346\264\273\345\212\250\345\220\215\347\247\260", nullptr));
        pushButton_eventDelete->setText(QCoreApplication::translate("Widget_Acivity", "\346\264\273\345\212\250\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Acivity: public Ui_Widget_Acivity {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_ACIVITY_H
