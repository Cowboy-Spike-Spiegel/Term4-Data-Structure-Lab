#ifndef WIDGET_DESKTOP_H
#define WIDGET_DESKTOP_H

#include <QWidget>
#include <QLabel>
#include <QSqlQuery>

#include "global.h"
#include "Mythread.h"

#include "widget_guide.h"
#include "widget_lesson.h"
#include "widget_acivity.h"
#include "widget_clock.h"

namespace Ui {
class Widget_Desktop;
}

class Widget_Desktop : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Desktop(QWidget *parent = nullptr);
    ~Widget_Desktop();

private:
    Ui::Widget_Desktop *ui;

    // time update thread
    MyThread* th;
    QSqlQuery query;

    // son pages
    Widget_Guide* guide;
    Widget_Lesson* lesson;
    Widget_Acivity* acivity;
    Widget_Clock* clock;

    void setUI();
    void setTime();
    void putTime();
    void ring();
    // 重写关闭函数(关闭handle，阻断thread)
    void closeEvent(QCloseEvent *);

signals:
    void refresh();
    void exit_return();

private slots:
    void on_Button_v1_clicked();
    void on_Button_v2_clicked();
    void on_Button_v3_clicked();
    void on_Button_v4_clicked();
    void on_Button_Guide_clicked();
    void on_Button_Lesson_clicked();
    void on_Button_Acivity_clicked();
    void on_Button_LogOut_clicked();
    void on_Button_Clock_clicked();
};

#endif // WIDGET_DESKTOP_H
