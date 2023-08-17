/********************************************************************************
** Form generated from reading UI file 'widget_desktop.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_DESKTOP_H
#define UI_WIDGET_DESKTOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget_Desktop
{
public:
    QLabel *year;
    QLabel *month;
    QLabel *day;
    QLabel *hour;
    QLabel *minute;
    QLabel *second;
    QLabel *monthNum;
    QLabel *hourNum;
    QLabel *yearNum;
    QLabel *minuteNum;
    QLabel *dayNum;
    QLabel *secondNum;
    QLabel *Title;
    QPushButton *Button_LogOut;
    QPushButton *Button_v1;
    QPushButton *Button_v2;
    QPushButton *Button_v3;
    QPushButton *Button_v4;
    QPushButton *Button_Guide;
    QPushButton *Button_Lesson;
    QPushButton *Button_Acivity;
    QLabel *dayOfWeek;
    QPushButton *Button_Clock;

    void setupUi(QWidget *Widget_Desktop)
    {
        if (Widget_Desktop->objectName().isEmpty())
            Widget_Desktop->setObjectName(QString::fromUtf8("Widget_Desktop"));
        Widget_Desktop->resize(927, 315);
        Widget_Desktop->setStyleSheet(QString::fromUtf8(""));
        year = new QLabel(Widget_Desktop);
        year->setObjectName(QString::fromUtf8("year"));
        year->setGeometry(QRect(20, 220, 69, 20));
        year->setAlignment(Qt::AlignCenter);
        month = new QLabel(Widget_Desktop);
        month->setObjectName(QString::fromUtf8("month"));
        month->setGeometry(QRect(110, 220, 69, 20));
        month->setAlignment(Qt::AlignCenter);
        day = new QLabel(Widget_Desktop);
        day->setObjectName(QString::fromUtf8("day"));
        day->setGeometry(QRect(200, 220, 69, 20));
        day->setAlignment(Qt::AlignCenter);
        hour = new QLabel(Widget_Desktop);
        hour->setObjectName(QString::fromUtf8("hour"));
        hour->setGeometry(QRect(290, 220, 69, 20));
        hour->setAlignment(Qt::AlignCenter);
        minute = new QLabel(Widget_Desktop);
        minute->setObjectName(QString::fromUtf8("minute"));
        minute->setGeometry(QRect(370, 220, 69, 20));
        minute->setAlignment(Qt::AlignCenter);
        second = new QLabel(Widget_Desktop);
        second->setObjectName(QString::fromUtf8("second"));
        second->setGeometry(QRect(450, 220, 69, 20));
        second->setAlignment(Qt::AlignCenter);
        monthNum = new QLabel(Widget_Desktop);
        monthNum->setObjectName(QString::fromUtf8("monthNum"));
        monthNum->setGeometry(QRect(110, 170, 69, 20));
        monthNum->setAlignment(Qt::AlignCenter);
        hourNum = new QLabel(Widget_Desktop);
        hourNum->setObjectName(QString::fromUtf8("hourNum"));
        hourNum->setGeometry(QRect(290, 170, 69, 20));
        hourNum->setAlignment(Qt::AlignCenter);
        yearNum = new QLabel(Widget_Desktop);
        yearNum->setObjectName(QString::fromUtf8("yearNum"));
        yearNum->setGeometry(QRect(20, 170, 69, 20));
        yearNum->setAlignment(Qt::AlignCenter);
        minuteNum = new QLabel(Widget_Desktop);
        minuteNum->setObjectName(QString::fromUtf8("minuteNum"));
        minuteNum->setGeometry(QRect(370, 170, 69, 20));
        minuteNum->setAlignment(Qt::AlignCenter);
        dayNum = new QLabel(Widget_Desktop);
        dayNum->setObjectName(QString::fromUtf8("dayNum"));
        dayNum->setGeometry(QRect(200, 170, 69, 20));
        dayNum->setAlignment(Qt::AlignCenter);
        secondNum = new QLabel(Widget_Desktop);
        secondNum->setObjectName(QString::fromUtf8("secondNum"));
        secondNum->setGeometry(QRect(450, 170, 69, 20));
        secondNum->setAlignment(Qt::AlignCenter);
        Title = new QLabel(Widget_Desktop);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(90, 0, 200, 50));
        Title->setAlignment(Qt::AlignCenter);
        Button_LogOut = new QPushButton(Widget_Desktop);
        Button_LogOut->setObjectName(QString::fromUtf8("Button_LogOut"));
        Button_LogOut->setGeometry(QRect(0, 0, 100, 50));
        Button_v1 = new QPushButton(Widget_Desktop);
        Button_v1->setObjectName(QString::fromUtf8("Button_v1"));
        Button_v1->setGeometry(QRect(20, 280, 93, 29));
        Button_v2 = new QPushButton(Widget_Desktop);
        Button_v2->setObjectName(QString::fromUtf8("Button_v2"));
        Button_v2->setGeometry(QRect(150, 280, 93, 29));
        Button_v3 = new QPushButton(Widget_Desktop);
        Button_v3->setObjectName(QString::fromUtf8("Button_v3"));
        Button_v3->setGeometry(QRect(290, 280, 93, 29));
        Button_v4 = new QPushButton(Widget_Desktop);
        Button_v4->setObjectName(QString::fromUtf8("Button_v4"));
        Button_v4->setGeometry(QRect(430, 280, 93, 29));
        Button_Guide = new QPushButton(Widget_Desktop);
        Button_Guide->setObjectName(QString::fromUtf8("Button_Guide"));
        Button_Guide->setGeometry(QRect(590, 230, 93, 29));
        Button_Lesson = new QPushButton(Widget_Desktop);
        Button_Lesson->setObjectName(QString::fromUtf8("Button_Lesson"));
        Button_Lesson->setGeometry(QRect(710, 230, 93, 29));
        Button_Acivity = new QPushButton(Widget_Desktop);
        Button_Acivity->setObjectName(QString::fromUtf8("Button_Acivity"));
        Button_Acivity->setGeometry(QRect(830, 230, 93, 29));
        dayOfWeek = new QLabel(Widget_Desktop);
        dayOfWeek->setObjectName(QString::fromUtf8("dayOfWeek"));
        dayOfWeek->setGeometry(QRect(20, 110, 69, 20));
        dayOfWeek->setAlignment(Qt::AlignCenter);
        Button_Clock = new QPushButton(Widget_Desktop);
        Button_Clock->setObjectName(QString::fromUtf8("Button_Clock"));
        Button_Clock->setGeometry(QRect(430, 110, 93, 29));

        retranslateUi(Widget_Desktop);

        QMetaObject::connectSlotsByName(Widget_Desktop);
    } // setupUi

    void retranslateUi(QWidget *Widget_Desktop)
    {
        Widget_Desktop->setWindowTitle(QCoreApplication::translate("Widget_Desktop", "Form", nullptr));
        year->setText(QCoreApplication::translate("Widget_Desktop", "\345\271\264", nullptr));
        month->setText(QCoreApplication::translate("Widget_Desktop", "\346\234\210", nullptr));
        day->setText(QCoreApplication::translate("Widget_Desktop", "\346\227\245", nullptr));
        hour->setText(QCoreApplication::translate("Widget_Desktop", "\346\227\266", nullptr));
        minute->setText(QCoreApplication::translate("Widget_Desktop", "\345\210\206", nullptr));
        second->setText(QCoreApplication::translate("Widget_Desktop", "\347\247\222", nullptr));
        monthNum->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        hourNum->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        yearNum->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        minuteNum->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        dayNum->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        secondNum->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        Title->setText(QCoreApplication::translate("Widget_Desktop", "?", nullptr));
        Button_LogOut->setText(QCoreApplication::translate("Widget_Desktop", "Log Out", nullptr));
        Button_v1->setText(QCoreApplication::translate("Widget_Desktop", "1\345\200\215\351\200\237", nullptr));
        Button_v2->setText(QCoreApplication::translate("Widget_Desktop", "2\345\200\215\351\200\237", nullptr));
        Button_v3->setText(QCoreApplication::translate("Widget_Desktop", "0.5\345\200\215\351\200\237", nullptr));
        Button_v4->setText(QCoreApplication::translate("Widget_Desktop", "\346\232\202\345\201\234", nullptr));
        Button_Guide->setText(QCoreApplication::translate("Widget_Desktop", "Guide", nullptr));
        Button_Lesson->setText(QCoreApplication::translate("Widget_Desktop", "Lesson", nullptr));
        Button_Acivity->setText(QCoreApplication::translate("Widget_Desktop", "Acivity", nullptr));
        dayOfWeek->setText(QCoreApplication::translate("Widget_Desktop", "TextLabel", nullptr));
        Button_Clock->setText(QCoreApplication::translate("Widget_Desktop", "\346\267\273\345\212\240\351\227\271\351\222\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget_Desktop: public Ui_Widget_Desktop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_DESKTOP_H
