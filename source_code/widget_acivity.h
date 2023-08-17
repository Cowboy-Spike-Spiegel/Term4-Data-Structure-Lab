#ifndef WIDGET_ACIVITY_H
#define WIDGET_ACIVITY_H

#include <QWidget>
#include <QSqlQuery>
#include "global.h"

typedef struct acivity
{
    QString name;
    int isShahe;
    int location;
    int year;
    int month;
    int day;
    int startHour;
    int endHour;
    QString label;

    struct acivity* nextPtr;
} Acivity, *AcivityPtr;

namespace Ui {
class Widget_Acivity;
}

class Widget_Acivity : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Acivity(QWidget *parent = nullptr);
    ~Widget_Acivity();

private:
    Ui::Widget_Acivity *ui;

    QSqlQuery query;

    // 添加活动需要的变量
    int isShaHe;
    int forPeople;

    // 活动需要的指针变量和指针数组
    AcivityPtr single;  // 个人活动链表头
    int sizeSingle;
    AcivityPtr* singleSelect;   // 个人活动指针数组（筛选结果）
    int sizeSingleSelect;

    AcivityPtr team;    // 集体活动链表头
    int sizeTeam;
    AcivityPtr* teamSelect;  // 集体活动指针数组（筛选结果）
    int sizeTeamSelect;

    int type;   // 展示模式（1-个人，2-集体）

    void quickSort_Name(AcivityPtr* array, int l, int r);
    void quickSort_Time(AcivityPtr* array, int l, int r);

    void setUI();
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

signals:
    void exit_return();

private slots:
    void on_Add_Acivity_clicked();
    void on_radio_IsShaHe_toggled();
    void on_radio_IsXiTuCheng_toggled();
    void on_radio_ForPeople_toggled();
    void on_radio_ForSingal_toggled();
    void on_pushButton_single_clicked();
    void on_pushButton_allPeople_clicked();
    void on_pushButton_select_clicked();
    void on_pushButton_timePaixu_clicked();
    void on_pushButton_namePaixu_clicked();
    void on_pushButton_eventDelete_clicked();
};

#endif // WIDGET_ACIVITY_H
