#ifndef WIDGET_CLOCK_H
#define WIDGET_CLOCK_H

#include <QWidget>
#include <QSqlQuery>
#include "global.h"

namespace Ui {
class Widget_Clock;
}

class Widget_Clock : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Clock(QWidget *parent = nullptr);
    ~Widget_Clock();

private:
    Ui::Widget_Clock *ui;
    void setUI();

    QSqlQuery query;

    // 重写关闭函数
    void closeEvent(QCloseEvent *);

signals:
    void exit_return();
private slots:
    void on_pushButton_Once_clicked();
    void on_pushButton_Dayly_clicked();
    void on_pushButton_Weekly_clicked();
};

#endif // WIDGET_CLOCK_H
