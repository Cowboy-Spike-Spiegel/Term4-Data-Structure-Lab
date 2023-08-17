#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "widget_signup.h"
#include "widget_desktop.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Widget_Desktop* desktop ;
    Widget_Signup* signPage ;

private:
    Ui::Widget *ui;
    bool check(QString account, QString password);
    void setUI();
    void linkDatabase();

private slots:
    void on_Sign_in_clicked();
    void on_Sign_up_clicked();
    void on_pushButton_link_clicked();
};
#endif // WIDGET_H
