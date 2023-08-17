#include "widget_lessonchange.h"
#include "ui_widget_lessonchange.h"

#include <QIcon>
#include <QDebug>
#include <QMessageBox>

Widget_LessonChange::Widget_LessonChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_LessonChange)
{
    ui->setupUi(this);
    setUI();

    // 初始化变量
    lessonIndex = -1;
    isShaHe = -1;
    location = 0;
    week = 0;
    index = 0;
}

Widget_LessonChange::~Widget_LessonChange()
{
    delete ui;
}

void Widget_LessonChange::closeEvent(QCloseEvent *) {
    emit exit_return();
}

void Widget_LessonChange::setUI() {
    this->setWindowTitle("Lesson Change") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;

    ui->comboBox_week->addItem("星期一");
    ui->comboBox_week->addItem("星期二");
    ui->comboBox_week->addItem("星期三");
    ui->comboBox_week->addItem("星期四");
    ui->comboBox_week->addItem("星期五");
    ui->comboBox_week->addItem("星期六");
    ui->comboBox_week->addItem("星期日");

    ui->comboBox_index->addItem("上午第一节");
    ui->comboBox_index->addItem("上午第二节");
    ui->comboBox_index->addItem("下午第一节");
    ui->comboBox_index->addItem("下午第二节");

    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number) {
            ui->comboBox_Lesson->addItem(query.value(1).toString()+query.value(5).toString()+"-"+query.value(6).toString()+" 必修");
            number.push(query.value(0).toInt());
            isSelect.push(0);
        }
    }

    query.exec("select * from lesson_select");
    while(query.next()) {
        if(query.value(2).toInt() == User_Number) {
            ui->comboBox_Lesson->addItem(query.value(1).toString()+query.value(5).toString()+"-"+query.value(6).toString()+" 选修");
            number.push(query.value(0).toInt());
            isSelect.push(1);
        }
    }

    ui->comboBox_location->setCurrentIndex(-1);
    ui->comboBox_week->setCurrentIndex(-1);
    ui->comboBox_index->setCurrentIndex(-1);
    ui->comboBox_Lesson->setCurrentIndex(-1);
}

//选中信息____________________________________________________________________________________
void Widget_LessonChange::on_comboBox_Lesson_activated(int index)
{
    lessonIndex = index;
}

void Widget_LessonChange::on_radio_xitucheng_clicked()
{
    ui->comboBox_location->clear();
    isShaHe = 0;
    query.exec("select * from building_xitucheng");
    while(query.next()) {
        ui->comboBox_location->addItem(query.value(0).toString());
    }
}

void Widget_LessonChange::on_radio_shahe_clicked()
{
    ui->comboBox_location->clear();
    isShaHe = 1;
    query.exec("select * from building_shahe");
    while(query.next()) {
        ui->comboBox_location->addItem(query.value(0).toString());
    }
}

void Widget_LessonChange::on_comboBox_location_activated(int index)
{
    this->location = index+1;
}

void Widget_LessonChange::on_comboBox_week_activated(int index)
{
    this->week = index+1;
}

void Widget_LessonChange::on_comboBox_index_activated(int index)
{
    this->index = index+1;
}

void Widget_LessonChange::on_pushButton_clicked()
{
    // 判断是否选中，没有直接退出
    if(ui->comboBox_Lesson->currentIndex() == -1) {
        QMessageBox mess(QMessageBox::Information,"Warning","Event: nothing selected!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 选择课程信息
    QString command;
    if(lessonIndex == -1)
        return;
    else if(isSelect[lessonIndex] == 0)
        command = "update lesson_compulsory set ";
    else
        command = "update lesson_select set ";

    // 修改名称
    QString name = ui->line_Name->text();
    if(name != "") {
        qDebug() << command+"name = '"+name+"' where number = "+QString::number(number[lessonIndex]);
        query.exec(command+"name = '"+name+"' where number = "+QString::number(number[lessonIndex]));
    }

    // 修改名称
    QString qun = ui->line_qun->text();
    if(qun != "") {
        qDebug() << command+"qun = '"+qun+"' where number = "+QString::number(number[lessonIndex]);
        query.exec(command+"qun = '"+qun+"' where number = "+QString::number(number[lessonIndex]));
    }

    // 修改位置
    if(isShaHe != -1 && location != 0) {
        qDebug() << command+"isShaHe = "+QString::number(isShaHe)+" where number = "+QString::number(number[lessonIndex]);
        qDebug() << command+"location = "+QString::number(location)+" where number = "+QString::number(number[lessonIndex]);
        query.exec(command+"isShaHe = "+QString::number(isShaHe)+" where number = "+QString::number(number[lessonIndex]));
        query.exec(command+"location = "+QString::number(location)+" where number = "+QString::number(number[lessonIndex]));
    }

    // 修改额外信息
    QString extra = ui->lineEdit_extra->text();
    if(!extra.isEmpty()) {
        qDebug() << command+"extra = '"+extra+"' where number = "+QString::number(number[lessonIndex]);
        query.exec(command+"extra = '"+extra+"' where number = "+QString::number(number[lessonIndex]));
    }

    // 修改星期数
    if(week != 0) {
        qDebug() << command+"dayOfWeek = "+QString::number(week)+" where number = "+QString::number(number[lessonIndex]);
        query.exec(command+"dayOfWeek = "+QString::number(week)+" where number = "+QString::number(number[lessonIndex]));
    }

    // 修改节数
    if(index != 0) {
        qDebug() << command+"c_index = "+QString::number(index)+" where number = "+QString::number(number[lessonIndex]);
        query.exec(command+"c_index = "+QString::number(index)+" where number = "+QString::number(number[lessonIndex]));
    }

    // 日志 **************************************
    globalLog.writeLog("修改课程："+ui->comboBox_Lesson->currentText());

    // 初始化变量
    ui->line_Name->setText("");
    ui->radio_xitucheng->setAutoExclusive(false);
    ui->radio_xitucheng->setChecked(false);
    ui->radio_xitucheng->setAutoExclusive(true);
    ui->radio_shahe->setAutoExclusive(false);
    ui->radio_shahe->setChecked(false);
    ui->radio_shahe->setAutoExclusive(true);
    ui->comboBox_location->setCurrentIndex(-1);
    ui->comboBox_week->setCurrentIndex(-1);
    ui->comboBox_index->setCurrentIndex(-1);
    ui->comboBox_Lesson->setCurrentIndex(-1);

    lessonIndex = -1;
    isShaHe = -1;
    location = 0;
    week = 0;
    index = 0;
}




