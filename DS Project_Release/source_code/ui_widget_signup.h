/********************************************************************************
** Form generated from reading UI file 'widget_signup.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_SIGNUP_H
#define UI_WIDGET_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Signup
{
public:
    QLineEdit *lineEdit_Account;
    QLabel *label_Account;
    QLabel *label_Password;
    QLabel *label_Name;
    QLineEdit *lineEdit_Password;
    QLineEdit *lineEdit_Name;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QWidget *Widget_Signup)
    {
        if (Widget_Signup->objectName().isEmpty())
            Widget_Signup->setObjectName(QString::fromUtf8("Widget_Signup"));
        Widget_Signup->resize(500, 400);
        lineEdit_Account = new QLineEdit(Widget_Signup);
        lineEdit_Account->setObjectName(QString::fromUtf8("lineEdit_Account"));
        lineEdit_Account->setGeometry(QRect(180, 60, 251, 41));
        label_Account = new QLabel(Widget_Signup);
        label_Account->setObjectName(QString::fromUtf8("label_Account"));
        label_Account->setGeometry(QRect(80, 60, 101, 41));
        label_Password = new QLabel(Widget_Signup);
        label_Password->setObjectName(QString::fromUtf8("label_Password"));
        label_Password->setGeometry(QRect(80, 110, 101, 41));
        label_Name = new QLabel(Widget_Signup);
        label_Name->setObjectName(QString::fromUtf8("label_Name"));
        label_Name->setGeometry(QRect(80, 160, 101, 41));
        lineEdit_Password = new QLineEdit(Widget_Signup);
        lineEdit_Password->setObjectName(QString::fromUtf8("lineEdit_Password"));
        lineEdit_Password->setGeometry(QRect(180, 110, 251, 41));
        lineEdit_Name = new QLineEdit(Widget_Signup);
        lineEdit_Name->setObjectName(QString::fromUtf8("lineEdit_Name"));
        lineEdit_Name->setGeometry(QRect(180, 160, 251, 41));
        pushButton = new QPushButton(Widget_Signup);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 320, 200, 40));
        comboBox = new QComboBox(Widget_Signup);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(180, 220, 211, 41));
        label = new QLabel(Widget_Signup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 220, 101, 41));

        retranslateUi(Widget_Signup);

        QMetaObject::connectSlotsByName(Widget_Signup);
    } // setupUi

    void retranslateUi(QWidget *Widget_Signup)
    {
        Widget_Signup->setWindowTitle(QCoreApplication::translate("Widget_Signup", "Form", nullptr));
        label_Account->setText(QCoreApplication::translate("Widget_Signup", "Account", nullptr));
        label_Password->setText(QCoreApplication::translate("Widget_Signup", "Password", nullptr));
        label_Name->setText(QCoreApplication::translate("Widget_Signup", "Name", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget_Signup", "Sign Up", nullptr));
        label->setText(QCoreApplication::translate("Widget_Signup", "\351\200\211\346\213\251\347\217\255\347\272\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Signup: public Ui_Widget_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_SIGNUP_H
