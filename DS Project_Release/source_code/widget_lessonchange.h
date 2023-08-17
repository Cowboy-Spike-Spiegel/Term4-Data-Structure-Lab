#ifndef WIDGET_LESSONCHANGE_H
#define WIDGET_LESSONCHANGE_H

#include <QWidget>
#include <QSqlQuery>
#include "global.h"
#include "MyVector.h"

namespace Ui {
class Widget_LessonChange;
}

class Widget_LessonChange : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_LessonChange(QWidget *parent = nullptr);
    ~Widget_LessonChange();

private:
    Ui::Widget_LessonChange *ui;
    void setUI();
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

    QSqlQuery query;
    int lessonIndex;
    int isShaHe;
    int location;
    int week;
    int index;
    Vector_int number;
    Vector_int isSelect;

signals:
    void exit_return();

private slots:
    void on_radio_xitucheng_clicked();
    void on_radio_shahe_clicked();
    void on_comboBox_location_activated(int index);
    void on_comboBox_week_activated(int index);
    void on_comboBox_index_activated(int index);
    void on_pushButton_clicked();
    void on_comboBox_Lesson_activated(int index);
};

#endif // WIDGET_LESSONCHANGE_H
