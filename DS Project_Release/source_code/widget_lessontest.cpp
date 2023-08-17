#include "widget_lessontest.h"
#include "ui_widget_lessontest.h"

#include <QIcon>
#include <QDebug>
#include <QMessageBox>

Widget_LessonTest::Widget_LessonTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_LessonTest)
{
    ui->setupUi(this);
    setUI();
}

Widget_LessonTest::~Widget_LessonTest()
{
    delete ui;
}

void Widget_LessonTest::closeEvent(QCloseEvent *) {
    emit exit_return();
}

// ____________________________________________________________________________
void Widget_LessonTest::setUI() {
    this->setWindowTitle("Lesson test") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;

    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number) {
            ui->comboBox_lesson->addItem(query.value(1).toString()+query.value(5).toString()+"-"+query.value(6).toString()+" 必修");
            number.push(query.value(0).toInt());
            isSelect.push(0);
        }
    }

    query.exec("select * from lesson_select");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number) {
            ui->comboBox_lesson->addItem(query.value(1).toString()+query.value(5).toString()+"-"+query.value(6).toString()+" 选修");
            number.push(query.value(0).toInt());
            isSelect.push(1);
        }
    }
}

void Widget_LessonTest::on_radioButton_xitucheng_clicked()
{
    ui->comboBox_location->clear();
    isShaHe = 0;
    query.exec("select * from building_xitucheng");
    while(query.next()) {
        ui->comboBox_location->addItem(query.value(0).toString());
    }
}

void Widget_LessonTest::on_radioButton_shahe_clicked()
{
    ui->comboBox_location->clear();
    isShaHe = 1;
    query.exec("select * from building_shahe");
    while(query.next()) {
        ui->comboBox_location->addItem(query.value(0).toString());
    }
}


void Widget_LessonTest::on_pushButton_clicked()
{
    int lesson_index = ui->comboBox_lesson->currentIndex();
    int location_index = ui->comboBox_location->currentIndex();
    QString name = ui->lineEdit_name->text();
    int year = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int day = ui->dateEdit->date().day();
    QString time = ui->timeEdit->time().toString();
    QString extra = ui->lineEdit_extra->text();

    // 时间非法
    if(isEnded(year, month, day, 0)) {
        QMessageBox mess(QMessageBox::Information,"Warning!","Time is not invalid!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 没选中
    if(lesson_index==-1 || location_index==-1 || name.isEmpty()) {
        QMessageBox mess(QMessageBox::Information,"Warning!","Event: somthing not selected or empty!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    } else {
        QString cmd = "insert into lesson_test(name, lesson_number, isSelect, isShaHe, location, year, month, day, time, extra) values(";
        cmd += "'"+name+"',"
            + QString::number(number[lesson_index])+","+ QString::number(isSelect[lesson_index])+","
            + QString::number(isShaHe)+","+QString::number(location_index+1)+","
            + QString::number(year) +"," + QString::number(month)+"," + QString::number(day)+",'" + time+"','"+extra+"')";
        qDebug() << cmd;
        query.exec(cmd);

        // 日志 **************************************
        globalLog.writeLog("添加课程考试："+cmd);

        QMessageBox mess(QMessageBox::Information,"Success!","Event: test added!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    ui->comboBox_lesson->setCurrentIndex(-1);
    ui->comboBox_location->clear();
}

