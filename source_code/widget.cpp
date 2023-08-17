#include "widget.h"
#include "ui_widget.h"

#include <QProcess>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QFont>
#include <QSqlQuery>

#include "global.h"


// ____________________________________________________________
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setUI();
    linkDatabase();

    // 规定HOME路径
    HOME.setPath( qApp->applicationDirPath() );

    // 用户变量初始化
    User_Account = "";
    User_Number = 0;
    User_IsAdmin = 0;

    // 创建日志对象 _________________________________________________________
    globalLog.create();
    // 说明曾经异常退出，先直接开启desktop
    if(globalLog.getUserNumber() != 0) {
        QMessageBox msgBox;
        msgBox.setText("通知：有历史登录");
        msgBox.setInformativeText("是否继续上次登录？");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Ok){
            User_Number = globalLog.getUserNumber();
            QSqlQuery query;
            query.exec("select * from people");
            while( query.next() )
                if(User_Number == query.value(0).toInt()) {
                    User_Account = query.value(1).toString();
                    User_IsAdmin = query.value(3).toInt();
                    break;
                }

            // 验证成功，开启主界面
            this->desktop = new Widget_Desktop ;
            // close MainPage and show this
            connect(desktop, &Widget_Desktop::exit_return, [=](){
                delete desktop;
                desktop = nullptr;
                this->show();
            });
            desktop->show() ;
            this->close();

            // 日志 **************************************
            globalLog.writeLog("打开程序时进行回档操作");
        }
        else
            globalLog.deletePage();   // 不需要回档，后面的页面数据也没用
    }
}

Widget::~Widget()
{
    delete ui;
}

// SLOTS_____________________________________________________________________________
void Widget::on_Sign_in_clicked()
{
    QString account = ui->Account_Line->text() ;
    QString password = ui->Password_Line->text() ;

    // 验证成功，关联登陆界面和主界面
    if( check(account, password) )
    {
        qDebug() << User_Account;

        globalLog.create(); // 创建，便于退出登录界面后继续回档
        // 验证成功，开启主界面
        this->desktop = new Widget_Desktop ;
        // close MainPage and show this
        connect(desktop, &Widget_Desktop::exit_return, [=](){
            delete desktop;
            desktop = nullptr;
            this->show();
        });

        desktop->show() ;
        this->close();

        // 日志 **************************************
        globalLog.writeLog("登陆成功");
    }
    else
    {
       QMessageBox mess(QMessageBox::Information,tr("Warning!"),tr("Wrong account or password!"));
       mess.setWindowIcon(QIcon(":/images/02.jpg"));
       mess.exec();
    }

    // 清空输入框内容
    ui->Password_Line->clear();
    //光标定位
    ui->Password_Line->setFocus();
}

void Widget::on_Sign_up_clicked()
{
    this->signPage = new Widget_Signup;
    connect(signPage, &Widget_Signup::exit_return, [=](){
        delete signPage;
        signPage = nullptr;
        this->show();
        ui->Account_Line->setText(User_Account);
    });

    signPage->show();
    this->close();
}

void Widget::on_pushButton_link_clicked()
{
    linkDatabase();
}


// functions___________________________________________________________________________
void Widget::linkDatabase() {
    // 连接数据库
    if (QSqlDatabase::contains("QMYSQL")) {
        db = QSqlDatabase::database("QMYSQL");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL");
    }
    //db.setHostName("localhost");
    //db.setPort(3306);
    db.setHostName("ngrok2.xiaomiqiu.cn");
    db.setPort(34666);
    db.setUserName("user_ds");
    db.setPassword("password");
    db.setDatabaseName("project_ds");

    if (db.open()){
        qDebug()<<"success";
    }
    else {
        QMessageBox mess(QMessageBox::Information,"Warning!","database fail!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
    }
}

bool Widget::check(QString account, QString password)
{
    bool answer = false;
    QSqlQuery query;
    query.exec("select * from people");
    while( query.next() ) {
        if(account == query.value(1).toString())
            if(password == query.value(2).toString()) {
                User_Account = account;
                User_Number = query.value(0).toInt();
                User_IsAdmin = query.value(3).toInt();
                answer = true;
                break;
            }
    }
    return answer;
}








void Widget::setUI() {
    // title icon background
    this->setWindowTitle("DS Project") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;
    this->setAutoFillBackground(true);
    this->setFixedSize(500, 400) ;
    QPalette p = this->palette();
    QPixmap pix("://images/3.png");
    p.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(p);

    // configs
    ui->Title->setFont(QFont("Consolas",40,75)) ;
    ui->Title->setStyleSheet("background: rgba(255,255,255,0%)") ;

    ui->pushButton_link->setFont(QFont("Consolas",8,75)) ;
    ui->pushButton_link->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Sign_in->setFont(QFont("Consolas",12,75)) ;
    ui->Sign_in->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Sign_up->setFont(QFont("Consolas",12,75)) ;
    ui->Sign_up->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->Account->setFont(QFont("Consolas",12,75)) ;
    ui->Password->setFont(QFont("Consolas",12,75)) ;
    ui->Account_Line->setFont(QFont("Consolas",16,75)) ;
    ui->Account_Line->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Password_Line->setFont(QFont("Consolas",16,75)) ;
    ui->Password_Line->setStyleSheet("background: rgba(255,255,255,50%)") ;
}

