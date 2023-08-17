 #include "widget_desktop.h"
#include "ui_widget_desktop.h"

#include <QDebug>
#include <QFile>
#include <QIcon>
#include <QMessageBox>
#include <MyVector.h>

Widget_Desktop::Widget_Desktop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Desktop)
{
    ui->setupUi(this);
    setUI();
    setTime();

    // thread for time counts and update
    th = new MyThread(this);
    connect(th, &MyThread::refresh, this, &Widget_Desktop::putTime);
    connect(th, &MyThread::hourPass, this, &Widget_Desktop::ring);
    th->start();

    // 根据日志进行场景还原
    globalLog.maintainState(QString::number(User_Number));
    if(!globalLog.getPage().isEmpty() && globalLog.getUserNumber() == User_Number) {
        QMessageBox msgBox;
        msgBox.setText("通知：有历史浏览记录");
        msgBox.setInformativeText("是否继续历史浏览?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        int ret = msgBox.exec();
        if(ret == QMessageBox::Ok){
            if(globalLog.getPage() == "guide") {
                on_Button_Guide_clicked();
                /*
                guide->setWindowFlags(guide->windowFlags() |Qt::Dialog);
                guide->setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体
                guide->show() ;
                */
            }
            else if(globalLog.getPage() == "lesson") {
                on_Button_Lesson_clicked();
                /*
                lesson->setWindowFlags(acivity->windowFlags() |Qt::Dialog);
                lesson->setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体
                lesson->show() ;
                */
            }
            else if(globalLog.getPage() == "acivity") {
                on_Button_Acivity_clicked();
                /*
                acivity->setWindowFlags(acivity->windowFlags() |Qt::Dialog);
                acivity->setWindowModality(Qt::ApplicationModal); //阻塞除当前窗体之外的所有的窗体
                acivity->show() ;
                */
            }
        }
    }
}

Widget_Desktop::~Widget_Desktop()
{
    delete ui;
    delete th;
    th = NULL;

    QFile tempFile(HOME.absolutePath()+"/Logs/time.log");
    tempFile.open(QIODevice::WriteOnly);

    QString str = QString::number(system_Time.get_BigTime().get()[0]);
    str += " " + QString::number(system_Time.get_BigTime().get()[1]);
    str += " " + QString::number(system_Time.get_BigTime().get()[2]);
    str += " " + QString::number(system_Time.get_SmallTime().get()[0]);
    str += " " + QString::number(system_Time.get_SmallTime().get()[1]);
    str += " " + QString::number(system_Time.get_SmallTime().get()[2]);
    str += " " + QString::number(system_Time.get_DayOfWeek());
    str += " " + QString::number(system_Time.get_Week());
    tempFile.write(str.toUtf8());
    tempFile.close();
    qDebug() << str;

    // 正常退出，删除状态
    //globalLog.removeState();
}

void Widget_Desktop::closeEvent(QCloseEvent *) {
    handle = false;
    th->exit();
    emit exit_return();
}

void Widget_Desktop::on_Button_v1_clicked()
{
    v = 1;
    QueryPerformanceCounter(&starter);
    QueryPerformanceCounter(&ender);
}

void Widget_Desktop::on_Button_v2_clicked()
{
    v = 2;
    QueryPerformanceCounter(&starter);
    QueryPerformanceCounter(&ender);
}

void Widget_Desktop::on_Button_v3_clicked()
{
    v = 0.5;
    QueryPerformanceCounter(&starter);
    QueryPerformanceCounter(&ender);
}

void Widget_Desktop::on_Button_v4_clicked()
{
    v=-1;
}

void Widget_Desktop::on_Button_Guide_clicked()
{
    guide = new Widget_Guide;
    connect(guide, &Widget_Guide::exit_return, [=](){
        delete guide;
        this->show();
    });
    guide->show();
    this->hide();
}

void Widget_Desktop::on_Button_Lesson_clicked()
{
    lesson = new Widget_Lesson;
    connect(lesson, &Widget_Lesson::exit_return, [=](){
        delete lesson;
        this->show();
    });
    lesson->show();
    this->hide();
}

void Widget_Desktop::on_Button_Acivity_clicked()
{
    acivity = new Widget_Acivity;
    connect(acivity, &Widget_Acivity::exit_return, [=](){
        delete acivity;
        this->show();
    });
    acivity->show();
    this->hide();
}

void Widget_Desktop::on_Button_Clock_clicked()
{
    clock = new Widget_Clock;
    connect(clock, &Widget_Clock::exit_return, [=](){
        delete clock;
        this->show();
    });
    clock->show();
    this->hide();
}

void Widget_Desktop::on_Button_LogOut_clicked()
{
    // 安全退出
    handle = false;
    th->exit();
    emit exit_return();
}


// ____________________________________________________________________
void Widget_Desktop::putTime() {
    ui->yearNum->setText(QString::number(system_Time.get_BigTime().get()[0]));
    ui->monthNum->setText(QString::number(system_Time.get_BigTime().get()[1]));
    ui->dayNum->setText(QString::number(system_Time.get_BigTime().get()[2]));
    ui->hourNum->setText(QString::number(system_Time.get_SmallTime().get()[0]));
    ui->minuteNum->setText(QString::number(system_Time.get_SmallTime().get()[1]));
    ui->secondNum->setText(QString::number(system_Time.get_SmallTime().get()[2]));
    if(system_Time.get_DayOfWeek()==1)      ui->dayOfWeek->setText("星期一");
    else if(system_Time.get_DayOfWeek()==2) ui->dayOfWeek->setText("星期二");
    else if(system_Time.get_DayOfWeek()==3) ui->dayOfWeek->setText("星期三");
    else if(system_Time.get_DayOfWeek()==4) ui->dayOfWeek->setText("星期四");
    else if(system_Time.get_DayOfWeek()==5) ui->dayOfWeek->setText("星期五");
    else if(system_Time.get_DayOfWeek()==6) ui->dayOfWeek->setText("星期六");
    else if(system_Time.get_DayOfWeek()==7) ui->dayOfWeek->setText("星期日");
}

// 初始化时间
void Widget_Desktop::setTime() {
    QDir tempDir(HOME.absolutePath()+"/Logs");
    if(!tempDir.exists()) {
        qDebug()<<"Logs: 不存在该路径";
        tempDir.mkpath(HOME.absolutePath()+"/Logs");
    }

    QFile tempFile(tempDir.absolutePath()+"/time.log");
    if(tempFile.open(QIODevice::ReadOnly)) {
        // 录入数据
        QByteArray array = tempFile.readAll();
        /*
        char* str = array.data();
        std::vector<int> obj ;
        for( int i=0; i < array.length() ; i++ ) {
            int tmp=0;
            while(str[i]!=' ' && str[i]!='\n' && i < array.length())
                tmp = tmp*10+(str[i++]-'0');
            obj.push_back(tmp);
        }

        // 数据数量或内容不合法，删除重开
        if(obj.size()!=8 || !system_Time.create(obj[0], obj[1], obj[2], obj[3], obj[4], obj[5], obj[6], obj[7])) {
            qDebug() << "dateFile date error";
            tempFile.close();
            tempFile.remove();
            tempFile.open(QIODevice::WriteOnly);
            tempFile.write(QString("2022 2 28 0 0 0 1\n").toUtf8());
            system_Time.create(2022, 2, 28, 0, 0, 0, 1, 1);
        }
        */
        QByteArrayList list = array.split(' ');
        // 数据数量或内容不合法，删除重开
        if(list.size()!=8 || !system_Time.create(list[0].toInt(), list[1].toInt(), list[2].toInt(), list[3].toInt(),
                                                 list[4].toInt(), list[5].toInt(), list[6].toInt(), list[7].toInt())) {
            qDebug() << "dateFile date error";
            tempFile.close();
            tempFile.remove();
            tempFile.open(QIODevice::WriteOnly);
            tempFile.write(QString("2022 2 28 0 0 0 1").toUtf8());
            system_Time.create(2022, 2, 28, 0, 0, 0, 1, 1);
        }
    }
    else {
        qDebug()<<"time File ERROR!";
        tempFile.close();
        tempFile.open(QIODevice::WriteOnly);
        tempFile.write(QString("2022 2 28 0 0 0 1").toUtf8());
        system_Time.create(2022, 2, 28, 0, 0, 0, 1, 1);
    }
    tempFile.close();
}

void Widget_Desktop::ring() {
    QSqlQuery tmp;
    QString name;
    int year = system_Time.get_BigTime().get()[0];
    int month = system_Time.get_BigTime().get()[1];
    int day = system_Time.get_BigTime().get()[2];
    int hour = system_Time.get_SmallTime().get()[0];

    // 先找单次闹钟
    query.exec("select * from "+QString::number(User_Number)+"_clock");
    while(query.next()) {
        name = query.value(0).toString();
        if(query.value(1).toInt() == year
            && query.value(2).toInt() == month
            && query.value(3).toInt() == day
            && query.value(4).toInt() == hour) {
            QMessageBox mess(QMessageBox::Information,"Clock_once","Event: "+name);
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
            tmp.exec("DELETE FROM "+QString::number(User_Number)+"_clock WHERE name = '"+name+"'");
        }
    }

    // 再找日常闹钟
    query.exec("select * from "+QString::number(User_Number)+"_clock_dayly");
    while(query.next()) {
        name = query.value(0).toString();
        if(query.value(1).toInt() == hour) {
            QMessageBox mess(QMessageBox::Information,"Clock_dayly!","Event: "+name);
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
            tmp.exec("DELETE FROM "+QString::number(User_Number)+"_clockdayly WHERE name = '"+name+"'");
        }
    }

    // 最后找周期闹钟
    query.exec("select * from "+QString::number(User_Number)+"_clock_weekly");
    while(query.next()) {
        name = query.value(0).toString();
        if(query.value(1).toInt() == system_Time.get_DayOfWeek() && query.value(2).toInt() == hour) {
            QMessageBox mess(QMessageBox::Information,"Clock_weekly!","Event: "+name);
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
            tmp.exec("DELETE FROM "+QString::number(User_Number)+"_clock_weekly WHERE name = "+name);
        }
    }
}


// 建立UI ____________________________________________________________________________________________
void Widget_Desktop::setUI() {
    if(User_IsAdmin == 1) {
        ui->Button_Clock->hide();
        ui->Button_Acivity->hide();
    }

    // layouts
    this->setFixedSize(600, 350) ;
    this->setWindowTitle("Desktop") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;

    this->setAutoFillBackground(true);
    QPalette p = this->palette();
    QPixmap pix("://images/bg.png");
    p.setBrush(QPalette::Window, QBrush(pix));
    this->setPalette(p);

    ui->Title->setText("Number: "+QString::number(User_Number));
    ui->Title->setFont(QFont("Microsoft YaHei",20,75)) ;
    ui->Title->setStyleSheet("background: rgba(255,255,255,0%)") ;

    ui->dayOfWeek->setGeometry(50, 100, 50, 50);
    ui->dayOfWeek->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_Clock->setGeometry(250, 100, 100, 50);
    ui->Button_Clock->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->yearNum->setGeometry(50, 150, 50, 50);
    ui->yearNum->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->monthNum->setGeometry(100, 150, 50, 50);
    ui->monthNum->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->dayNum->setGeometry(150, 150, 50, 50);
    ui->dayNum->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->hourNum->setGeometry(200, 150, 50, 50);
    ui->hourNum->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->minuteNum->setGeometry(250, 150, 50, 50);
    ui->minuteNum->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->secondNum->setGeometry(300, 150, 50, 50);
    ui->secondNum->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->year->setGeometry(50, 200, 50, 50);
    ui->year->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->month->setGeometry(100, 200, 50, 50);
    ui->month->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->day->setGeometry(150, 200, 50, 50);
    ui->day->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->hour->setGeometry(200, 200, 50, 50);
    ui->hour->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->minute->setGeometry(250, 200, 50, 50);
    ui->minute->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->second->setGeometry(300, 200, 50, 50);
    ui->second->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->Button_v1->setGeometry(50, 250, 75, 50);
    ui->Button_v1->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_v2->setGeometry(125, 250, 75, 50);
    ui->Button_v2->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_v3->setGeometry(200, 250, 75, 50);
    ui->Button_v3->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_v4->setGeometry(275, 250, 75, 50);
    ui->Button_v4->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->Button_LogOut->setGeometry(0, 0, 80, 40);
    ui->Button_LogOut->setFont(QFont("Microsoft YaHei",8,7)) ;
    ui->Button_LogOut->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_Guide->setGeometry(400, 100, 140, 75);
    ui->Button_Guide->setFont(QFont("Microsoft YaHei",20,75)) ;
    ui->Button_Guide->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_Lesson->setGeometry(400, 175, 140, 75);
    ui->Button_Lesson->setFont(QFont("Microsoft YaHei",20,75)) ;
    ui->Button_Lesson->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_Acivity->setGeometry(400, 250, 140, 75);
    ui->Button_Acivity->setFont(QFont("Microsoft YaHei",20,75)) ;
    ui->Button_Acivity->setStyleSheet("background: rgba(255,255,255,50%)") ;
}
