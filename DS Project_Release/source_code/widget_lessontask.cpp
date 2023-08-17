#include "widget_lessontask.h"
#include "ui_widget_lessontask.h"

#include <QIcon>
#include <QDebug>
#include <QMessageBox>


Widget_LessonTask::Widget_LessonTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_LessonTask)
{
    ui->setupUi(this);
    setUI();
}

Widget_LessonTask::~Widget_LessonTask()
{
    delete ui;

    number.clear();
    isSelect.clear();
}

void Widget_LessonTask::closeEvent(QCloseEvent *) {
    emit exit_return();
}

void Widget_LessonTask::setUI() {
    this->setWindowTitle("Lesson task") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;

    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number) {
            ui->comboBox->addItem(query.value(1).toString()+query.value(5).toString()+"-"+query.value(6).toString()+" 必修 ");
            number.push(query.value(0).toInt());
            isSelect.push(0);
        }
    }
    query.exec("select * from lesson_select");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number) {
            ui->comboBox->addItem(query.value(1).toString()+query.value(5).toString()+"-"+query.value(6).toString()+" 选修");
            number.push(query.value(0).toInt());
            isSelect.push(1);
        }
    }
    ui->comboBox->setCurrentIndex(-1);
}

// ______________________________________________________________________________________________
void Widget_LessonTask::on_pushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    int year = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int day = ui->dateEdit->date().day();
    int hour = ui->lineEdit_hour->text().toInt();
    int lessonIndex = ui->comboBox->currentIndex();

    // 时间非法
    if(isEnded(year, month, day, hour)) {
        QMessageBox mess(QMessageBox::Information,"Warning!","Time is not invalid!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    if(ui->comboBox->currentIndex() == -1) {
        QMessageBox mess(QMessageBox::Information,"Warning","Event: nothing selected!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    } else {
        if(name != "") {
            // 选择课程信息
            query.exec("select * from lesson_task");
            int size = query.size();
            QString command = "insert into lesson_task(number, lesson_number, isSelect, name, year, month, day, hour, all_number, commit_number) values(";
            command += QString::number(size+1)+","
                    +QString::number(number[lessonIndex])+","
                    +QString::number(isSelect[lessonIndex])+","
                    +"'"+name+"',"
                    +QString::number(year)+","+QString::number(month)+","+QString::number(day)+","+QString::number(hour)+",-1,0)";
            qDebug() << command;
            query.exec(command);

            // 日志 **************************************
            globalLog.writeLog("添加课程作业："+command);

            int count = 0;
            // 添加到学生中去（必修课）
            if(isSelect[lessonIndex] == 0) {
                // 找到课程班级
                QString c;
                query.exec("select * from lesson_compulsory limit "+QString::number(number[lessonIndex]-1)+",1");
                while(query.next()) c = query.value(9).toString();
                qDebug() << c;

                // 找到所有学生
                Vector_int student; // 自己的数组
                query.exec("select * from people");
                while(query.next()) {
                    if(query.value(5).toString() == c) {
                        student.push(query.value(0).toInt());
                        count++;
                    }
                }

                // 添加到学生的task里
                for(int i=0; i < student.size(); i++) {
                    QString cmd = "insert into "+QString::number(student[i])+"_task(number, lesson_number, isSelect, name, year, month, day, hour, isCommit) values(";
                    cmd += QString::number(size+1)+","
                            +QString::number(number[lessonIndex])+","
                            +QString::number(isSelect[lessonIndex])+","
                            +"'"+name+"',"
                            +QString::number(year)+","+QString::number(month)+","+QString::number(day)+","+QString::number(hour)+",0)";
                    qDebug() << cmd;
                    query.exec(cmd);
                }
            }

            // 添加到学生中去（选修课）
            else if(isSelect[lessonIndex] == 1) {
                // 找到所有学生
                Vector_int student;
                query.exec("select * from people");
                while(query.next())
                    if(query.value(3).toInt() == 0)  student.push(query.value(0).toInt());

                // 找选修课表
                for(int i=0; i < student.size() ; i++) {
                    query.exec("select * from "+QString::number(student[i])+"_select");
                    int flag = 0;
                    while(!flag && query.next())
                        if(query.value(0).toInt() == number[lessonIndex])   flag = 1;

                    // 添加课程表
                    if(flag == 1) {
                        count++;
                        QString cmd = "insert into "+QString::number(student[i])+"_task(number, lesson_number, isSelect, name, year, month, day, hour, isCommit) values(";
                        cmd += QString::number(size+1)+","
                                +QString::number(number[lessonIndex])+","
                                +QString::number(isSelect[lessonIndex])+","
                                +"'"+name+"',"
                                +QString::number(year)+","+QString::number(month)+","+QString::number(day)+","+QString::number(hour)+",0)";
                        qDebug() << cmd;
                        query.exec(cmd);
                    }
                }
            }

            // 更新作业总人数
            query.exec("update lesson_task set all_number = "+QString::number(count)+" where number = "+QString::number(size+1));
            qDebug() << "update lesson_task set all_number = "+QString::number(count)+" where number = "+QString::number(size+1);

            // 返回message
            QMessageBox mess(QMessageBox::Information,"Success","Event: task added!");
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
            return;

            // 清零
            ui->comboBox->setCurrentIndex(-1);
            ui->lineEdit_hour->setText("");
        } else {
            QMessageBox mess(QMessageBox::Information,"Warning","Event: name is empty!");
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
            return;
        }
    }
}

