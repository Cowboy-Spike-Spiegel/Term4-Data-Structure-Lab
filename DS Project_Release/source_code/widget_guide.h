#ifndef WIDGET_GUIDE_H
#define WIDGET_GUIDE_H

#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QSqlQuery>
#include "MyVector.h"

namespace Ui {
class Widget_Guide;
}

class Widget_Guide : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Guide(QWidget *parent = nullptr);
    ~Widget_Guide();

private:
    Ui::Widget_Guide *ui;
    void setUI();
    void paintEvent(QPaintEvent* );
    void closeEvent(QCloseEvent *);

    QSqlQuery query;
    int speedWalk;
    int speedRide;
    int source;
    int sourceIsShaHe;
    int destBuilding;
    int destIsShaHe;
    int mode;

    int forLessonGuide; // 是否为课程导航
    int restTime;   // 时间策略，针对课程导航
    int timeWeek;   // 课程所在星期
    int timeHour;   // 课程要到达的时间（几点）

    bool forMore;   // 多路径开关

    bool becomeCloser(int subNum, double curAbscissa, double curOrdinate, double destAbscissa, double destOrdinate);
    double quick_findPath(int source, int dest, int mode, Vector_int& path, QString table);
    double findPath(int source, int dest, int mode, Vector_int& path, QString table);
    void paintPoint(Vector_int& xitucheng, Vector_int& shahe);

signals:
    void exit_return();

private slots:
    void on_Button_Search_clicked();
    void on_Mode_1_toggled();
    void on_Mode_2_toggled();
    void on_Mode_3_toggled();
    void on_shahe_Source_clicked();
    void on_xitucheng_Source_clicked();
    void on_shahe_Dest_clicked();
    void on_xitucheng_Dest_clicked();
    void on_comboBox_Source_activated(int index);
    void on_comboBox_Dest_activated(int index);
    void on_Button_Search_2_clicked();
    void on_pushButton_show_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_more_clicked();
};

#endif // WIDGET_GUIDE_H
