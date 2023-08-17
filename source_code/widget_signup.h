#ifndef WIDGET_SIGNUP_H
#define WIDGET_SIGNUP_H

#include <QWidget>
#include <QSqlQuery>
#include "global.h"

namespace Ui {
class Widget_Signup;
}

class Widget_Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Signup(QWidget *parent = nullptr);
    ~Widget_Signup();

private:
    Ui::Widget_Signup *ui;
    QSqlQuery query;

    void setUI();
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

signals:
    void exit_return();
private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_SIGNUP_H
