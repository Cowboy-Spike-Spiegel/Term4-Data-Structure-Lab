#ifndef WIDGET_LESSONADD_H
#define WIDGET_LESSONADD_H

#include <QWidget>
#include <QSqlQuery>
#include "global.h"

namespace Ui {
class Widget_LessonAdd;
}

class Widget_LessonAdd : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_LessonAdd(QWidget *parent = nullptr);
    ~Widget_LessonAdd();

private slots:
    void on_radio_xitucheng_clicked();
    void on_radio_shahe_clicked();
    void on_comboBox_week_activated(int index);
    void on_comboBox_index_activated(int index);
    void on_comboBox_class_activated(int index);
    void on_comboBox_location_activated(int index);
    void on_pushButton_c_clicked();

    void on_pushButton_s_clicked();

private:
    Ui::Widget_LessonAdd *ui;
    void setUI();
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

    QSqlQuery query;
    int isShaHe;
    int location;
    int week;
    int index;
    QString c;

signals:
    void exit_return();
};

#endif // WIDGET_LESSONADD_H
