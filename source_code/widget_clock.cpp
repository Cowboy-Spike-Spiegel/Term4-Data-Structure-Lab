#include "widget_clock.h"
#include "ui_widget_clock.h"

#include <QDebug>
#include <QMessageBox>

Widget_Clock::Widget_Clock(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Clock)
{
    ui->setupUi(this);
    setUI();
}

Widget_Clock::~Widget_Clock()
{
    delete ui;
}

void Widget_Clock::closeEvent(QCloseEvent *) {
    emit exit_return();
}

void Widget_Clock::setUI()
{
    ui->comboBox->addItem("星期一");
    ui->comboBox->addItem("星期二");
    ui->comboBox->addItem("星期三");
    ui->comboBox->addItem("星期四");
    ui->comboBox->addItem("星期五");
    ui->comboBox->addItem("星期六");
    ui->comboBox->addItem("星期日");
}

void Widget_Clock::on_pushButton_Once_clicked()
{
    QString name = ui->lineEdit_Name->text();
    QString hour = ui->lineEdit_Hour->text();
    QString year = QString::number(ui->dateEdit->date().year());
    QString month = QString::number(ui->dateEdit->date().month());
    QString day = QString::number(ui->dateEdit->date().day());
    if(isEnded(year.toInt(),month.toInt(),day.toInt(),hour.toInt()) || hour.toInt()<0 || hour.toInt()>23) {
        QMessageBox mess(QMessageBox::Information,"Error!","input invalid");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    QString cmd = "insert into "+QString::number(User_Number)+"_clock(name, year, month, day, hour)"+"values('";
    cmd += name+"'," + year+"," + month+"," + day+"," + hour+")";
    qDebug() << cmd;
    query.exec(cmd);

    QMessageBox mess(QMessageBox::Information,"Success!","Clock Added!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();

    // 日志 **************************************
    globalLog.writeLog("添加闹钟：\n"+cmd);
}


void Widget_Clock::on_pushButton_Dayly_clicked()
{
    QString name = ui->lineEdit_Name->text();
    QString hour = ui->lineEdit_Hour->text();
    if(hour.toInt()<0 || hour.toInt()>23) {
        QMessageBox mess(QMessageBox::Information,"Error!","input invalid");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
    }

    QString cmd = "insert into "+QString::number(User_Number)+"_clock_dayly(name, hour)"+"values('";
    cmd += name+"'," + hour+")";
    qDebug() << cmd;
    query.exec(cmd);

    QMessageBox mess(QMessageBox::Information,"Success!","Clock Added!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();

    // 日志 **************************************
    globalLog.writeLog("添加闹钟：\n"+cmd);
}


void Widget_Clock::on_pushButton_Weekly_clicked()
{
    QString name = ui->lineEdit_Name->text();
    QString week = QString::number(ui->comboBox->currentIndex()+1);
    QString hour = ui->lineEdit_Hour->text();
    if(hour.toInt()<0 || hour.toInt()>23) {
        QMessageBox mess(QMessageBox::Information,"Error!","input invalid");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
    }

    QString cmd = "insert into "+QString::number(User_Number)+"_clock_weekly(name, week, hour)"+"values('";
    cmd += name+"'," + week+"," + hour+")";
    qDebug() << cmd;
    query.exec(cmd);

    QMessageBox mess(QMessageBox::Information,"Success!","Clock Added!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();

    // 日志 **************************************
    globalLog.writeLog("添加闹钟：\n"+cmd);
}

