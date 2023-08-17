/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *Sign_up;
    QPushButton *Sign_in;
    QLabel *Account;
    QLabel *Password;
    QLineEdit *Account_Line;
    QLineEdit *Password_Line;
    QLabel *Title;
    QPushButton *pushButton_link;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(500, 400);
        Widget->setStyleSheet(QString::fromUtf8(""));
        Sign_up = new QPushButton(Widget);
        Sign_up->setObjectName(QString::fromUtf8("Sign_up"));
        Sign_up->setGeometry(QRect(250, 300, 150, 50));
        Sign_up->setAutoFillBackground(false);
        Sign_up->setStyleSheet(QString::fromUtf8(""));
        Sign_in = new QPushButton(Widget);
        Sign_in->setObjectName(QString::fromUtf8("Sign_in"));
        Sign_in->setGeometry(QRect(100, 300, 150, 50));
        Sign_in->setStyleSheet(QString::fromUtf8(""));
        Account = new QLabel(Widget);
        Account->setObjectName(QString::fromUtf8("Account"));
        Account->setGeometry(QRect(60, 170, 101, 51));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        Account->setFont(font);
        Account->setStyleSheet(QString::fromUtf8(""));
        Password = new QLabel(Widget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(60, 230, 101, 51));
        Password->setFont(font);
        Password->setStyleSheet(QString::fromUtf8(""));
        Account_Line = new QLineEdit(Widget);
        Account_Line->setObjectName(QString::fromUtf8("Account_Line"));
        Account_Line->setGeometry(QRect(160, 160, 251, 51));
        Account_Line->setFont(font);
        Account_Line->setStyleSheet(QString::fromUtf8(""));
        Password_Line = new QLineEdit(Widget);
        Password_Line->setObjectName(QString::fromUtf8("Password_Line"));
        Password_Line->setGeometry(QRect(160, 230, 251, 51));
        Password_Line->setFont(font);
        Password_Line->setStyleSheet(QString::fromUtf8(""));
        Password_Line->setEchoMode(QLineEdit::Password);
        Title = new QLabel(Widget);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(50, 40, 401, 91));
        QFont font1;
        font1.setPointSize(40);
        font1.setBold(true);
        Title->setFont(font1);
        Title->setStyleSheet(QString::fromUtf8(""));
        Title->setAlignment(Qt::AlignCenter);
        pushButton_link = new QPushButton(Widget);
        pushButton_link->setObjectName(QString::fromUtf8("pushButton_link"));
        pushButton_link->setGeometry(QRect(0, 0, 131, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Sign_up->setText(QCoreApplication::translate("Widget", "Sign up", nullptr));
        Sign_in->setText(QCoreApplication::translate("Widget", "Sign in", nullptr));
        Account->setText(QCoreApplication::translate("Widget", "Account", nullptr));
        Password->setText(QCoreApplication::translate("Widget", "Password", nullptr));
        Account_Line->setText(QString());
        Title->setText(QCoreApplication::translate("Widget", "<html><head/><body><p>DS Project</p></body></html>", nullptr));
        pushButton_link->setText(QCoreApplication::translate("Widget", "link refresh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
