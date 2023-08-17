#include "widget_lessonadd.h"
#include "ui_widget_lessonadd.h"

#include <QMessageBox>
#include <QIcon>
#include <QDebug>

Widget_LessonAdd::Widget_LessonAdd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_LessonAdd)
{
    ui->setupUi(this);
    setUI();
}

Widget_LessonAdd::~Widget_LessonAdd()
{
    delete ui;
}

void Widget_LessonAdd::closeEvent(QCloseEvent *) {
    emit exit_return();
}

// ___________________________________________________________________________________
void Widget_LessonAdd::setUI() {
    this->setWindowTitle("Lesson Add") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;

    ui->comboBox_week->addItem("星期一");
    ui->comboBox_week->addItem("星期二");
    ui->comboBox_week->addItem("星期三");
    ui->comboBox_week->addItem("星期四");
    ui->comboBox_week->addItem("星期五");
    ui->comboBox_week->addItem("星期六");
    ui->comboBox_week->addItem("星期日");
    ui->comboBox_week->setCurrentIndex(-1);

    ui->comboBox_index->addItem("上午第一节");
    ui->comboBox_index->addItem("上午第二节");
    ui->comboBox_index->addItem("下午第一节");
    ui->comboBox_index->addItem("下午第二节");
    ui->comboBox_index->setCurrentIndex(-1);

    ui->comboBox_class->addItem("2020211301");
    ui->comboBox_class->addItem("2020211302");
    ui->comboBox_class->addItem("2020211303");
    ui->comboBox_class->addItem("2020211304");
    ui->comboBox_class->addItem("2020211305");
    ui->comboBox_class->setCurrentIndex(-1);
}

void Widget_LessonAdd::on_radio_xitucheng_clicked()
{
    ui->comboBox_location->clear();
    isShaHe = 0;
    query.exec("select * from building_xitucheng");
    while(query.next()) {
        ui->comboBox_location->addItem(query.value(0).toString());
    }
}

void Widget_LessonAdd::on_radio_shahe_clicked()
{
    ui->comboBox_location->clear();
    isShaHe = 1;
    query.exec("select * from building_shahe");
    while(query.next()) {
        ui->comboBox_location->addItem(query.value(0).toString());
    }
}
void Widget_LessonAdd::on_comboBox_location_activated(int index)
{
    this->location = index+1;
}

void Widget_LessonAdd::on_comboBox_week_activated(int index)
{
    this->week = index+1;
}

void Widget_LessonAdd::on_comboBox_index_activated(int index)
{
    this->index = index+1;
}

void Widget_LessonAdd::on_comboBox_class_activated(int index)
{
    this->c = ui->comboBox_class->currentText();
}



// *************************************************************************************************************************
// 添加必修课
void Widget_LessonAdd::on_pushButton_c_clicked()
{
    QString name = ui->line_Name->text();
    QString qun = ui->lineEdit_qun->text();
    QString extra = ui->lineEdit_extra->text();
    if(name.isEmpty() || ui->comboBox_location->currentIndex() == -1 || ui->comboBox_class->currentIndex() == -1
            || ui->comboBox_index->currentIndex() == -1 || ui->comboBox_week->currentIndex() == -1) {
        QMessageBox mess(QMessageBox::Information,"Warning!","something is empty!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 检测是否冲突 _______________________________________________________________________
    int flag = 0;
    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        // 要么学生冲突，要么我自己冲突
        if((query.value(2).toInt() == User_Number || query.value(9).toString() == c)
                && query.value(5).toInt() == week && query.value(6).toInt() == index ) {
            flag = 1;
            break;
        }
    }
    query.exec("select * from lesson_select");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number && query.value(5).toInt() == week && query.value(6).toInt() == index ) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        QMessageBox mess(QMessageBox::Information,"Error!","和已有课有冲突!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 添加必修 _____________________________________________________________________________
    query.exec("select * from lesson_compulsory");
    int size = query.size();
    QString cmd = "insert into lesson_compulsory(number, name, teacher, isShaHe, location, dayOfWeek, c_index, qun, extra, class) values(";
    cmd += QString::number(size+1)+",'"+name+"',"+ QString::number(User_Number)+","+QString::number(isShaHe)+","
            +QString::number(location)+","+QString::number(week)+","+QString::number(index)+",'"+qun+"','"+extra+"','"+c+"')";
    qDebug() << cmd;
    query.exec(cmd);

    // 日志 **************************************
    globalLog.writeLog("添加必修课：\n"+cmd);

    QMessageBox mess(QMessageBox::Information,"Success!","Added!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();

    ui->comboBox_week->setCurrentIndex(-1);
    ui->comboBox_index->setCurrentIndex(-1);
    ui->comboBox_class->setCurrentIndex(-1);
}

// 添加选修课
void Widget_LessonAdd::on_pushButton_s_clicked()
{
    QString name = ui->line_Name->text();
    QString qun = ui->lineEdit_qun->text();
    QString extra = ui->lineEdit_extra->text();
    if(name.isEmpty() || ui->comboBox_location->currentIndex() == -1
            || ui->comboBox_index->currentIndex() == -1 || ui->comboBox_week->currentIndex() == -1) {
        QMessageBox mess(QMessageBox::Information,"Warning!","something is empty!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 检测是否冲突 _______________________________________________________________________
    int flag = 0;
    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number && query.value(5).toInt() == week && query.value(6).toInt() == index ) {
            flag = 1;
            break;
        }
    }
    query.exec("select * from lesson_select");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number && query.value(5).toInt() == week && query.value(6).toInt() == index ) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        QMessageBox mess(QMessageBox::Information,"Error!","和已有课有冲突!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 添加选修 _____________________________________________________________________________
    query.exec("select * from lesson_select");
    int size = query.size();
    QString cmd = "insert into lesson_select(number, name, teacher, isShaHe, location, dayOfWeek, c_index, qun, extra) values(";
    cmd += QString::number(size+1)+",'"+name+"',"+ QString::number(User_Number)+","+QString::number(isShaHe)+","
            +QString::number(location)+","+QString::number(week)+","+QString::number(index)+",'"+qun+"','"+extra+"')";
    qDebug() << cmd;
    query.exec(cmd);

    // 日志 **************************************
    globalLog.writeLog("添加选修课：\n"+cmd);

    QMessageBox mess(QMessageBox::Information,"Success!","Added!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();

    ui->comboBox_week->setCurrentIndex(-1);
    ui->comboBox_index->setCurrentIndex(-1);
    ui->comboBox_class->setCurrentIndex(-1);
}

