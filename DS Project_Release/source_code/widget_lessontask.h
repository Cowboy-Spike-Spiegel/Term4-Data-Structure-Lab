#ifndef WIDGET_LESSONTASK_H
#define WIDGET_LESSONTASK_H

#include <QWidget>
#include "global.h"
#include "MyVector.h"
#include <QSqlQuery>

namespace Ui {
class Widget_LessonTask;
}

class Widget_LessonTask : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_LessonTask(QWidget *parent = nullptr);
    ~Widget_LessonTask();

private:
    Ui::Widget_LessonTask *ui;
    void setUI();
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

    QSqlQuery query;
    Vector_int number;
    Vector_int isSelect;

signals:
    void exit_return();
private slots:
    void on_pushButton_clicked();
};

#endif // WIDGET_LESSONTASK_H
