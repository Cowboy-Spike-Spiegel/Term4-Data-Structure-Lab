#ifndef WIDGET_LESSONTEST_H
#define WIDGET_LESSONTEST_H

#include <QWidget>
#include "global.h"
#include "MyVector.h"
#include <QSqlQuery>

namespace Ui {
class Widget_LessonTest;
}

class Widget_LessonTest : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_LessonTest(QWidget *parent = nullptr);
    ~Widget_LessonTest();

private:
    Ui::Widget_LessonTest *ui;
    void setUI(void);
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

    QSqlQuery query;
    int isShaHe;
    Vector_int number;
    Vector_int isSelect;

signals:
    void exit_return();
private slots:
    void on_radioButton_xitucheng_clicked();
    void on_radioButton_shahe_clicked();
    void on_pushButton_clicked();
};

#endif // WIDGET_LESSONTEST_H
