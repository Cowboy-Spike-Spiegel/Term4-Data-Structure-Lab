#include "widget_signup.h"
#include "ui_widget_signup.h"

#include <QIcon>
#include <QMessageBox>
#include <QDebug>

Widget_Signup::Widget_Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Signup)
{
    ui->setupUi(this);
    setUI();
}

Widget_Signup::~Widget_Signup()
{
    delete ui;
}

void Widget_Signup::closeEvent(QCloseEvent *) {
    emit exit_return();
}

void Widget_Signup::on_pushButton_clicked()
{
    // 记录4个属性
    QString account = ui->lineEdit_Account->text();
    QString password = ui->lineEdit_Password->text();
    QString name = ui->lineEdit_Name->text();
    int classIndex = ui->comboBox->currentIndex();

    if(account == "" || password == "" || name == "" || classIndex == -1) {
        QMessageBox mess(QMessageBox::Information,tr("Warning!"),tr("Something empty!"));
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }
    QString c = "202021130"+QString::number(classIndex+1);

    // 数据合法
    if(account.length() == 10 && password.length() <= 20 && !password.contains(' ')) {
        // 判断该账号有没有被注册
        int flag = 0;
        query.exec("select * from people");
        while(query.next()) {
            if(account == query.value(1).toString()) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            QMessageBox mess(QMessageBox::Information,tr("Warning!"),tr("This account exists."));
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
        }
        else {
            // 生成插入语句
            query.exec("SELECT * FROM people");
            int num = query.size()+1;
            QString str= "insert into people(number, account, password, isAdmin, name, class) values("
                        +QString::number(num)+","
                        +"'"+account+"',"
                        +"'"+password+"',"
                        +"0,"+"'"+name+"','"+c+"')";
            query.exec(str);


            // 生成用户表 _____________________________________________________________________________________________________
            // _clock
            str = "create table "+QString::number(num)+"_clock";
            str += "(name VARCHAR(255) NOT NULL, year INT NOT NULL, month INT NOT NULL, day INT NOT NULL, hour INT NOT NULL)";
            query.exec(str);
            qDebug() << str;

            // _clock_dayly
            str = "create table "+QString::number(num)+"_clock_dayly";
            str += "(name VARCHAR(255) NOT NULL, hour INT NOT NULL)";
            query.exec(str);
            qDebug() << str;

            // _clock_weekly
            str = "create table "+QString::number(num)+"_clock_weekly";
            str += "(name VARCHAR(255) NOT NULL, week INT NOT NULL, hour INT NOT NULL)";
            query.exec(str);
            qDebug() << str;

            // _once
            str = "create table "+QString::number(num)+"_once";
            str += "(name VARCHAR(255) NOT NULL, isShaHe INT NOT NULL, location INT NOT NULL, ";
            str += "year INT NOT NULL, month INT NOT NULL, day INT NOT NULL, start_hour INT NOT NULL, end_hour INT NOT NULL, label VARCHAR(255))";
            query.exec(str);
            qDebug() << str;

            // _select
            str = "create table "+QString::number(num)+"_select";
            str += "(number INT NOT NULL, name VARCHAR(255) NOT NULL, teacher INT NOT NULL, ";
            str += "isShaHe INT NOT NULL, location INT NOT NULL, dayOfWeek INT NOT NULL, c_index INT NOT NULL, qun VARCHAR(255), extra VARCHAR(255))";
            query.exec(str);
            qDebug() << str;

            // _task
            str = "create table "+QString::number(num)+"_task";
            str += "(number INT NOT NULL, lesson_number INT NOT NULL, isSelect INT NOT NULL, name VARCHAR(255) NOT NULL, ";
            str += "year INT NOT NULL, month INT NOT NULL, day INT NOT NULL, hour INT NOT NULL, isCommit INT NOT NULL)";
            query.exec(str);
            qDebug() << str;


            // 记录账号信息，方便返回signin界面显示account ________________________________________________________________________
            User_Account = account;
            QMessageBox mess(QMessageBox::Information,tr("Success!"),tr("Close for continue."));
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();

            // 日志 **************************************
            globalLog.writeLog("该用户注册成功");
        }
    }
    else {
        QMessageBox mess(QMessageBox::Information,tr("Warning!"),tr("account_Length: 10 && password_Len:[0,20] && no space!"));
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        ui->lineEdit_Account->clear();
        ui->lineEdit_Password->clear();
        ui->lineEdit_Name->clear();
        ui->lineEdit_Account->setFocus();
    }
}

void Widget_Signup::setUI() {
    this->setFixedSize(500, 400) ;
    this->setWindowTitle("Sign Up Page") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;
    this->setAutoFillBackground(true);
    QPalette p = this->palette();
    QPixmap pix(":/images/3.png");
    p.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(p);

    ui->pushButton->setFont(QFont("Consolas",12,75)) ;
    ui->pushButton->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->label_Account->setFont(QFont("Consolas",12,75)) ;
    ui->label_Account->setStyleSheet("background: rgba(255,255,255,0%)") ;
    ui->label_Password->setFont(QFont("Consolas",12,75)) ;
    ui->label_Password->setStyleSheet("background: rgba(255,255,255,0%)") ;
    ui->label_Name->setFont(QFont("Consolas",12,75)) ;
    ui->label_Name->setStyleSheet("background: rgba(255,255,255,0%)") ;
    ui->lineEdit_Account->setFont(QFont("Consolas",12,75)) ;
    ui->lineEdit_Account->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->lineEdit_Password->setFont(QFont("Consolas",12,75)) ;
    ui->lineEdit_Password->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->lineEdit_Name->setFont(QFont("Consolas",12,75)) ;
    ui->lineEdit_Name->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->label->setFont(QFont("Consolas",12,75)) ;
    ui->label->setStyleSheet("background: rgba(255,255,255,s0%)") ;
    ui->comboBox->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox->addItem("2020211301");
    ui->comboBox->addItem("2020211302");
    ui->comboBox->addItem("2020211303");
    ui->comboBox->addItem("2020211304");
    ui->comboBox->addItem("2020211305");
    ui->comboBox->setCurrentIndex(-1);
}

