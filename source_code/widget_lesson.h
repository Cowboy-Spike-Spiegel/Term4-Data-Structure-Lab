#ifndef WIDGET_LESSON_H
#define WIDGET_LESSON_H

#include <QWidget>
#include <QSqlQuery>
#include <QPushButton>
#include "global.h"
#include "widget_lessonadd.h"
#include "widget_lessonchange.h"
#include "widget_lessontask.h"
#include "widget_lessontest.h"
#include "mainwindow.h"

// ________________________________________________________________________
typedef struct lesson {
    int isSelect;
    int number;
    QString name;
    int teacher;
    int isShaHe;
    int location;
    int dayOfWeek;
    int index;
    QString qun;
    QString extra;
    struct lesson* nextptr;
} Lesson, *LessonPtr;
//__________________________________________________________________________

namespace Ui {
class Widget_Lesson;
}

class Widget_Lesson : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_Lesson(QWidget *parent = nullptr);
    ~Widget_Lesson();

private:
    Ui::Widget_Lesson *ui;
    QSqlQuery query;

    // 根据选中的课程信息进行展示
    void showInformation();
    // 课程表功能 ********************************************
    QPushButton** format;   // 课程表
    int* formatIndex;   // 课程表链表对应的format下标（空间大小为size，数值范围为0-27）
    int selectIndex;    // 被选中的format下标（0-27），通过鼠标选择

    // 课程表链表
    LessonPtr lessons;
    int size;   // 课程规模
    LessonPtr* lessonSelect;// 筛选后的课程链表：直接指向相应的空间
    int sizeSelect; // 筛选过后的size

    QDir filePath;  // 当前课程表对应的文件夹

    void setInformation();  // 初始化所有信息
    void quickSort_Name(LessonPtr* array, int l, int r);
    void quickSort_Time(LessonPtr* array, int l, int r);

    // 选修课功能 *******************************************
    LessonPtr lessonXuanxiu;
    int sizeXuanxiu;   // 选修课程规模
    LessonPtr* lessonXuanxiuSelect;// 筛选后的选修课程链表：直接指向相应的空间
    int sizeXuanxiuSelect; // 筛选过后的size

    // 窗口函数 *********************************************
    void setUI();
    // 重写关闭函数
    void closeEvent(QCloseEvent *);

    Widget_LessonAdd* adder;
    Widget_LessonChange* changer;
    Widget_LessonTask* task;
    Widget_LessonTest* test;
    MainWindow* zip;

signals:
    void exit_return();

private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_change_clicked();
    void on_pushButton_task_clicked();
    void on_pushButton_test_clicked();
    void on_pushButton_send_clicked();
    void on_pushButton_submit_clicked();
    void on_lineEdit_findAll_returnPressed();
    void on_pushButton_addxuanxiu_clicked();
    void on_pushButton_findxuanxiu_clicked();
    void on_pushButton_sortByName_clicked();
    void on_pushButton_sortByTime_clicked();
    void on_pushButton_delete_clicked();
};

#endif // WIDGET_LESSON_H
