#include "widget_guide.h"
#include "ui_widget_guide.h"

#include <QIcon>
#include <QPainter>
#include <QButtonGroup>
#include <QRadioButton>
#include <QDebug>
#include <QMessageBox>
#include "global.h"
#include "mapStack.h"


Widget_Guide::Widget_Guide(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Guide)
{
    // 留存状态信息
    globalLog.maintainState(QString::number(User_Number)+" guide");

    ui->setupUi(this);
    setUI();

    // 初始化
    speedWalk = 50;
    speedRide = 100;
    mode = 1;

    sourceIsShaHe = -1;
    source = 0;
    destIsShaHe = -1;
    destBuilding = 0;

    forLessonGuide = 0;
    restTime = 0;
    timeWeek = 0;
    timeHour = -1;
    // 设置多路径开关
    forMore = false;

    // 初始化课程选择 ______________________________________________________
    // 先找出学生班级
    QString userClass;
    query.exec("select * from people limit "+QString::number(User_Number-1)+",1");
    while(query.next())
        userClass = query.value(5).toString();
    // 先找必修课 __________________________________________________
    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        if(query.value(9).toString() == userClass) {
            ui->comboBox_lesson->addItem(query.value(0).toString()+" "+query.value(1).toString()+" "
                                         +query.value(5).toString()+"-"+query.value(6).toString()+" 必修");
        }
    }
    // 再找选修课 __________________________________________________
    query.exec("select * from "+QString::number(User_Number)+"_select");
    while(query.next()) {
        ui->comboBox_lesson->addItem(query.value(0).toString()+" "+query.value(1).toString()+" "
                                     +query.value(5).toString()+"-"+query.value(6).toString()+" 选修");
    }
    ui->comboBox_lesson->setCurrentIndex(-1);
}

Widget_Guide::~Widget_Guide()
{
    delete ui;
    // 删除所有label
    qDeleteAll(this->findChildren<QLabel* >());

    // 刷新状态
    //globalLog.maintainState(QString::number(User_Number));
}

void Widget_Guide::closeEvent(QCloseEvent *) {
    emit exit_return();
}






// 选中信息_______________________________________________________________________________________________________________
// 触发地_____________________________________________
void Widget_Guide::on_shahe_Source_clicked()
{
    ui->comboBox_Source->clear();
    sourceIsShaHe = 1;
    query.exec("select * from map_shahe");
    while(query.next()) {
        ui->comboBox_Source->addItem(query.value(0).toString());
    }
    ui->comboBox_Source->setCurrentIndex(-1);
}
void Widget_Guide::on_xitucheng_Source_clicked()
{
    ui->comboBox_Source->clear();
    sourceIsShaHe = 0;
    query.exec("select * from map_xitucheng");
    while(query.next()) {
        ui->comboBox_Source->addItem(query.value(0).toString());
    }
    ui->comboBox_Source->setCurrentIndex(-1);
}
void Widget_Guide::on_comboBox_Source_activated(int index)
{
    source = index+1;
}

// 目的地_____________________________________________
void Widget_Guide::on_shahe_Dest_clicked()
{
    ui->comboBox_Dest->clear();
    destIsShaHe = 1;
    query.exec("select * from building_shahe");
    while(query.next()) {
        ui->comboBox_Dest->addItem(query.value(0).toString());
    }
    ui->comboBox_Dest->setCurrentIndex(-1);
}
void Widget_Guide::on_xitucheng_Dest_clicked()
{
    ui->comboBox_Dest->clear();
    destIsShaHe = 0;
    query.exec("select * from building_xitucheng");
    while(query.next()) {
        ui->comboBox_Dest->addItem(query.value(0).toString());
    }
    ui->comboBox_Dest->setCurrentIndex(-1);
}
void Widget_Guide::on_comboBox_Dest_activated(int index)
{
    destBuilding = index+1;
}

void Widget_Guide::on_Mode_1_toggled() { mode = 1; }
void Widget_Guide::on_Mode_2_toggled() { mode = 2; }
void Widget_Guide::on_Mode_3_toggled() { mode = 3; }







// 便捷导航 ___________________________________________________________________________________________________________
void Widget_Guide::on_Button_Search_2_clicked()
{
    forLessonGuide = 1;

    // 先找出学生班级
    QString userClass;
    query.exec("select * from people limit "+QString::number(User_Number-1)+",1");
    while(query.next())
        userClass = query.value(5).toString();

    // 这种情况固定输入的是找当前时间往后数的课程，已开始的算到下周
    // 假如有输入，直接找输入的 ___________________________________________________________________________________________
    if(ui->comboBox_lesson->currentIndex() != -1) {
        // 课程序号，名称，星期数，开始小时数
        int number = ui->comboBox_lesson->currentText().split(' ').at(0).toInt();
        QString name = ui->comboBox_lesson->currentText().split(' ').at(1);
        int weekDay, hour;

        // 日志 ****************************************************
        globalLog.writeLog("find path for "+name);

        // 找必修
        if(ui->comboBox_lesson->currentText().split(' ').at(3) == "必修") {
            query.exec("select * from lesson_compulsory");
            while(query.next()) {
                if(number == query.value(0).toInt()) {
                    destIsShaHe = query.value(3).toInt();
                    destBuilding = query.value(4).toInt();
                    weekDay = query.value(5).toInt();
                    hour = 6+2*query.value(6).toInt();
                    break;
                }
            }
        }
        // 找选修
        else {
            query.exec("select * from "+QString::number(User_Number)+"_select");
            while(query.next()) {
                if(number == query.value(0).toInt()) {
                    destIsShaHe = query.value(3).toInt();
                    destBuilding = query.value(4).toInt();
                    weekDay = query.value(5).toInt();
                    hour = 6+2*query.value(6).toInt();
                    break;
                }
            }
        }

        // 找到了
        if(destBuilding != 0) {
            // 生成目的校区
            if(destIsShaHe == 1) {
                ui->shahe_Dest->toggle();
                on_shahe_Dest_clicked();
            } else {
                ui->xitucheng_Dest->toggle();
                on_xitucheng_Dest_clicked();
            }
            // 选中相应的建筑信息
            ui->comboBox_Dest->setCurrentIndex(destBuilding-1);
            // 计算出相应的剩余时间
            if(weekDay != system_Time.get_DayOfWeek())
                restTime = 1440;    // 不是一天，绝对能到，直接设成1440min
            else {
                if(hour <= system_Time.get_SmallTime().get()[0])    // 找的是下一周的，肯定能到
                    restTime = 1440;
                else
                    restTime = 60*(hour-system_Time.get_SmallTime().get()[0])-system_Time.get_SmallTime().get()[1]; // 一定大于0
            }

            timeWeek = weekDay;
            timeHour = hour;

            // 点击正常搜索
            ui->textEdit->clear();
            ui->textEdit->append("导航课程："+name); // 展示导航课程
            on_Button_Search_clicked();
        }
        else {
            QMessageBox mess(QMessageBox::Information,"Error!","Event: no lesson!");
            mess.setWindowIcon(QIcon(":/images/02.jpg"));
            mess.exec();
        }

        return;
    }


    // 没有输入，找时间最近的 ******************************************************************************************************
    // 查找课程相应的点位，进行目的地的初始化 ________________________________________________________________
    int weekDay = system_Time.get_DayOfWeek();
    int hour = system_Time.get_SmallTime().get()[0];

    // 完后找，保留这两个暂存信息和结果答案(星期数转化为mod比较，0-7,十分方便) _______________________________________
    QString ansName;   // 课程名称
    int ansIsShaHe=-1, ansLoc=0, ansWeekDay=8, ansHour=1;  // 最近课程信息

    // 搜索必修课 ____________________________________________________________________
    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        // 不是当前班级，直接跳过
        if(query.value(9).toString() != userClass)
            continue;

        // 假如当前离此时更近，那么进行更新(星期数转化为mod比较)
        QString tmpName = query.value(1).toString();
        int tmpIsShaHe = query.value(3).toInt();
        int tmpLoc = query.value(4).toInt();
        int tmpWeekDay = (query.value(5).toInt()-weekDay+7)%7;   /* 转化 0-6 */
        int tmpHour = 6+2*query.value(6).toInt();
        if(tmpWeekDay == 0 && tmpHour < hour)
            tmpWeekDay = 7; // 因为要过一周才能到

        if(tmpWeekDay < ansWeekDay || (tmpWeekDay == ansWeekDay && tmpHour < ansHour)) {
            ansName = tmpName;
            ansIsShaHe = tmpIsShaHe;
            ansLoc = tmpLoc;
            ansWeekDay = tmpWeekDay;
            ansHour = tmpHour;
        }
    }

    // 搜索选修课 ____________________________________________________________________
    query.exec("select * from "+QString::number(User_Number)+"_select");
    qDebug() << "select * from "+QString::number(User_Number)+"_select";
    while(query.next()) {
        // 假如当前离此时更近，那么进行更新(星期数转化为mod比较)
        QString tmpName = query.value(1).toString();
        int tmpIsShaHe = query.value(3).toInt();
        int tmpLoc = query.value(4).toInt();
        int tmpWeekDay = (query.value(5).toInt()-weekDay+7)%7;   /* 转化 0-6 */
        int tmpHour = 6+2*query.value(6).toInt();
        if(tmpWeekDay == 0 && tmpHour < hour)
            tmpWeekDay = 7; // 因为要过一周才能到

        if(tmpWeekDay < ansWeekDay || (tmpWeekDay == ansWeekDay && tmpHour < ansHour)) {
            ansName = tmpName;
            ansIsShaHe = tmpIsShaHe;
            ansLoc = tmpLoc;
            ansWeekDay = tmpWeekDay;
            ansHour = tmpHour;
        }
    }

    // 假如没有课程，那么就报错
    if(ansLoc == 0) {
        QMessageBox mess(QMessageBox::Information,"Error!","Event: no lesson!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
    }
    else {
        // 日志 ****************************************************
        globalLog.writeLog("find path for "+ansName);

        // 点击生成目的校区
        if(ansIsShaHe == 1) {
            ui->shahe_Dest->toggle();
            on_shahe_Dest_clicked();
        }
        else {
            ui->xitucheng_Dest->toggle();
            on_xitucheng_Dest_clicked();
        }

        // 选中相应的建筑信息
        ui->comboBox_Dest->setCurrentIndex(ansLoc-1);
        destBuilding = ansLoc;

        // 计算出相应的剩余时间
        if(ansWeekDay != 0)
            restTime = 1440;    // 不是一天，绝对能到，直接设成1440min
        else
            restTime = 60*(ansHour-system_Time.get_SmallTime().get()[0])-system_Time.get_SmallTime().get()[1];
        qDebug() << "rest: " << restTime << "min";

        timeWeek = (ansWeekDay+system_Time.get_DayOfWeek()+6)%7+1;
        timeHour = ansHour;

        // 点击正常搜索
        ui->textEdit->clear();
        ui->textEdit->append("导航课程："+ansName); // 展示导航课程
        on_Button_Search_clicked();
    }
}


// 一般导航 ___________________________________________________________________________________________________________
void Widget_Guide::on_Button_Search_clicked()
{
    // 判断是否选中，没有直接退出
    if(ui->comboBox_Source->currentIndex() == -1 || ui->comboBox_Dest->currentIndex() == -1
        || source == 0 || destBuilding == 0) {
        QMessageBox mess(QMessageBox::Information,"Error!","Event: source or dest isn't selected!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 输出清零
    if(ui->textEdit->toPlainText().split('\n').size() != 1 && !forMore )
        ui->textEdit->clear();

    // 记录末点位信息
    bool endIsShaHe;
    int endLoc;

    // 打车45min
    // 班车信息默认沙河到本部是9，11，13，15；本部到沙河是8，10，12，14，时长45min
    // 公共汽车默认10分钟一班，8-18点都有，1h
    // 策略：不紧急的时候，优先班车，再公交，最后打车（省钱）；紧急时时间短的优先（一定是打车竞争力大），即使是到不了会迟到也一定选择打车尽早去
    Vector_int points;  // 建筑地点缓存出入口
    double ans_1 = -1;  // 西土城答案
    double ans_2 = -1;  // 沙河答案
    Vector_int path_1;  // 西土城路径
    Vector_int path_2;  // 沙河路径

    // 出发点在沙河，目的地在沙河 *****************************************************************************
    if(sourceIsShaHe == 1 && destIsShaHe == 1) {
        // 记录建筑出入口数组（沙河目的地）
        query.exec("select * from building_shahe limit "+QString::number(destBuilding-1)+",1" );
        while(query.next())
            for(int i=0; i < query.value(1).toInt(); i++)
                points.push(query.value(2+i).toInt());
        // 根据数组找最短路径（只有一个校区，使用1）
        for(int i=0; i < points.size(); i++ ) {
            double tmpAns = -1;
            Vector_int tmpPath ;
            tmpAns = quick_findPath(source, points[i], mode, tmpPath, "map_shahe");
            if(tmpAns == -1)
                tmpAns = findPath(source, points[i], mode, tmpPath, "map_shahe");
            // 更新答案
            if(ans_2 == -1 || (ans_2 != -1 && tmpAns < ans_2) ) {
                ans_2 = tmpAns;
                path_2.copy(tmpPath);
            }
        }

        // 输出答案（只有沙河）
        QString str = "沙河-";
        if(mode==1)
            str += "Distanece: "+QString::number(ans_2,'f',2)+" m\n";
        else
            str += "Time: "+QString::number(ans_2,'f',2)+" min\n";
        for(int i=path_2.size()-1; i > 0; i--)  // 逆向输出
            str += QString::number(path_2[i]) + " -> ";
        str += QString::number(path_2[0]);
        ui->textEdit->append(str);

        // 画点
        paintPoint(path_1, path_2);

        // 输出额外信息(是否能到达)
        if(forLessonGuide == 1) {
            if(mode == 1) {
                if(ans_2/speedWalk > restTime) {
                    QMessageBox mess(QMessageBox::Information,"哈哈哈!","你到不了的!");
                    mess.setWindowIcon(QIcon(":/images/02.jpg"));
                    mess.exec();
                }
            }
            else {
                if(ans_2 > restTime) {
                    QMessageBox mess(QMessageBox::Information,"哈哈哈!","你到不了的!");
                    mess.setWindowIcon(QIcon(":/images/02.jpg"));
                    mess.exec();
                }
            }
        }

        endIsShaHe = true;
        endLoc = path_2[0];
    }

    // 出发点在沙河，目的地在西土城 *****************************************************************************
    else if(sourceIsShaHe == 1 && destIsShaHe == 0) {

        // 先生成沙河路线
        ans_2 = quick_findPath(source, 1, mode, path_2, "map_shahe");
        if(ans_2 == -1)
            ans_2 = findPath(source, 1, mode, path_2, "map_shahe");

        // 记录建筑出入口数组（对于西土城）
        query.exec("select * from building_xitucheng limit "+QString::number(destBuilding-1)+",1" );
        while(query.next()) {
            for(int i=0; i < query.value(1).toInt(); i++)
                points.push(query.value(2+i).toInt());
        }
        // 根据数组找最短路径
        for(int i=0; i < points.size(); i++ ) {
            double tmpAns = -1;
            Vector_int tmpPath ;
            tmpAns = quick_findPath(41, points[i], mode, tmpPath, "map_xitucheng");
            if(tmpAns == -1)
                tmpAns = findPath(41, points[i], mode, tmpPath, "map_xitucheng");
            // 更新答案
            if(ans_1 == -1 || (ans_1 != -1 && tmpAns < ans_1) ) {
                ans_1 = tmpAns;
                path_1.copy(tmpPath);
            }
        }

        // 输出答案 ___________________________________________________
        QString str_2 = "沙河-";
        if(mode==1)
            str_2 += "Distanece: "+QString::number(ans_2,'f',2)+" m\n";
        else
            str_2 += "Time: "+QString::number(ans_2,'f',2)+" min\n";
        for(int i=path_2.size()-1; i > 0; i--)  // 逆向输出
            str_2 += QString::number(path_2[i]) + " -> ";
        str_2 += QString::number(path_2[0]);
        ui->textEdit->append(str_2);

        // ____________________________________________________________

        if(forLessonGuide == 1) {
            double xiTuChengTime, shaHeTime;
            if(mode == 1)
                xiTuChengTime = ans_1/speedWalk;
            else
                xiTuChengTime = ans_1;
            if(mode == 1)
                shaHeTime = ans_2/speedWalk;
            else
                shaHeTime = ans_2;
            // 时间充足，只需要计算上什么车，上车时间 _________________________________
            double upCarTime = 45 + xiTuChengTime;  // 只需要往前找上车时间
            if(restTime == 1440) {
                // 可能能坐校车
                if(timeHour > 8) {
                    // 班车坐不了，时间不够
                    if(upCarTime > 60)
                        ui->textEdit->append("乘坐公交："+QString::number(timeHour-2)+":"+QString::number(60-xiTuChengTime)+" 之前上车");    // 班车不行，公交可以
                    else
                        ui->textEdit->append("乘坐班车："+QString::number(timeHour-1)+"h");  // 可以乘班车坐到，优先班车
                }
                // 不能坐校车，因为时间充足，坐公交
                else
                    ui->textEdit->append("乘坐公交：6:"+QString::number(60-xiTuChengTime)+" 之前上车");
            }
            // 时间并不充足，可能会到不了 ____________________________________________
            else {
                // 先走到门口
                restTime -= shaHeTime;
                // 可坐校车（班车）-- 9, 11, 13, 15
                if(timeHour > 8) {
                    // 可赶上班车
                    if(restTime > 60) {
                        // 坐班车能赶到现场
                        if(45 + xiTuChengTime < 60)
                            ui->textEdit->append("乘坐班车："+QString::number(timeHour-1)+"h");  // 可以乘班车坐到，优先班车
                        // 赶不上，再判断公交是不是能坐上
                        else if(restTime > 60+xiTuChengTime)
                            ui->textEdit->append("乘坐公交："+QString::number(timeHour-2)+":"+QString::number(60-shaHeTime)+" 之前上车");    // 班车不行，公交可以
                        // 也赶不上，搭车子。可能迟到
                        else{
                            restTime -= 45+xiTuChengTime;
                            ui->textEdit->append("现在，快，立即过去打车！");
                        }
                    }
                    // 赶不上班车，直接打车
                    else {
                        restTime -= 45+xiTuChengTime;
                        ui->textEdit->append("现在，快，立即过去打车！");
                    }
                }
                // 不可坐校车，公交或者打车
                else {
                    if(restTime > 60+xiTuChengTime)
                        ui->textEdit->append("乘坐公交："+QString::number(timeHour-2)+":"+QString::number(60-shaHeTime)+" 之前上车");    // 班车不行，公交可以
                    // 也赶不上，搭车子。可能迟到
                    else{
                        restTime -= 45+xiTuChengTime;
                        ui->textEdit->append("现在，快，立即过去打车！");
                    }
                }
            }

            // 输出额外信息(是否能到达)
            if(restTime < 0) {
                QMessageBox mess(QMessageBox::Information,"哈哈哈!","你到不了的!");
                mess.setWindowIcon(QIcon(":/images/02.jpg"));
                mess.exec();
            }
        }

        // ____________________________________________________________
        QString str_1 = "西土城-";
        if(mode==1)
            str_1 += "Distanece: "+QString::number(ans_1,'f',2)+" m\n";
        else
            str_1 += "Time: "+QString::number(ans_1,'f',2)+" min\n";
        for(int i=path_1.size()-1; i > 0; i--)  // 逆向输出
            str_1 += QString::number(path_1[i]) + " -> ";
        str_1 += QString::number(path_1[0]);
        ui->textEdit->append(str_1);

        // 画点
        paintPoint(path_1, path_2);

        endIsShaHe = false;
        endLoc = path_1[0];
    }

    // 出发点在西土城，目的地在沙河 *****************************************************************************
    else if(sourceIsShaHe == 0 && destIsShaHe == 1) {
        double ans_1 = -1;
        double ans_2 = -1;
        Vector_int path_1;
        Vector_int path_2;

        // 先生成西土城路线
        ans_1 = quick_findPath(source, 41, mode, path_1, "map_xitucheng");
        if(ans_1 == -1)
            ans_1 = findPath(source, 41, mode, path_1, "map_xitucheng");

        // 记录建筑出入口数组
        query.exec("select * from building_shahe limit "+QString::number(destBuilding-1)+",1" );
        while(query.next()) {
            for(int i=0; i < query.value(1).toInt(); i++)
                points.push(query.value(2+i).toInt());
        }
        // 根据数组找最短路径
        for(int i=0; i < points.size(); i++ ) {
            double tmpAns = -1;
            Vector_int tmpPath ;
            tmpAns = quick_findPath(1, points[i], mode, tmpPath, "map_shahe");
            if(tmpAns == -1)
                tmpAns = findPath(1, points[i], mode, tmpPath, "map_shahe");
            // 更新答案
            if(ans_2 == -1 || (ans_2 != -1 && tmpAns < ans_2) ) {
                ans_2 = tmpAns;
                path_2.copy(tmpPath);
            }
        }

        // 输出答案
        QString str_1 = "西土城-";
        if(mode==1)
            str_1 += "Distanece: "+QString::number(ans_1,'f',2)+" m\n";
        else
            str_1 += "Time: "+QString::number(ans_1,'f',2)+" min\n";
        for(int i=path_1.size()-1; i > 0; i--)  // 逆向输出
            str_1 += QString::number(path_1[i]) + " -> ";
        str_1 += QString::number(path_1[0]);
        ui->textEdit->append(str_1);

        // ______________________________________________________________

        if(forLessonGuide == 1) {
            double xiTuChengTime, shaHeTime;
            if(mode == 1)
                xiTuChengTime = ans_1/speedWalk;
            else
                xiTuChengTime = ans_1;
            if(mode == 1)
                shaHeTime = ans_2/speedWalk;
            else
                shaHeTime = ans_2;
            // 时间充足，只需要计算上什么车，上车时间 _________________________________
            double upCarTime = 45 + shaHeTime;  // 只需要往前找上车时间
            if(restTime == 1440) {
                // 可以坐班车（校车）
                if(timeHour > 8)
                    ui->textEdit->append("乘坐班车："+QString::number(timeHour-2)+"h");  // 可以乘班车坐到，优先班车
                // 选择坐公交
                else
                    ui->textEdit->append("乘坐公交：6:"+QString::number(60-shaHeTime)+" 之前上车");
            }
            // 时间并不充足，可能会到不了 ____________________________________________
            else {
                // 先走到门口
                restTime -= xiTuChengTime;
                // 可坐校车（班车） -- 8, 10, 12, 14
                if(timeHour > 8) {
                    if(restTime > 120)
                        ui->textEdit->append("乘坐班车："+QString::number(timeHour-2)+"h");  // 可以乘班车坐到，优先班车
                    else if(restTime > 60+shaHeTime)
                        ui->textEdit->append("乘坐公交："+QString::number(timeHour-2)+":"+QString::number(60-shaHeTime)+" 之前上车");    // 班车不行，公交可以
                    else {
                        // 立即打车，并且更新restTime，有危险到不了
                        restTime -= 45+shaHeTime;
                        ui->textEdit->append("现在，快，立即过去打车！");
                    }
                }
                // 不可坐校车，直接打车
                else {
                    if(upCarTime > 60)
                        ui->textEdit->append("打车：6:"+QString::number(120-upCarTime)+" 之前上车");
                    else
                        ui->textEdit->append("打车：7:"+QString::number(60-upCarTime)+" 之前上车");
                }
            }

            // 输出额外信息(是否能到达)
            if(restTime < 0) {
                QMessageBox mess(QMessageBox::Information,"哈哈哈!","你到不了的!");
                mess.setWindowIcon(QIcon(":/images/02.jpg"));
                mess.exec();
            }

            endIsShaHe = true;
            endLoc = path_2[0];
        }

        // ______________________________________________________________
        QString str_2 = "沙河-";
        if(mode==1)
            str_2 += "Distanece: "+QString::number(ans_2,'f',2)+" m\n";
        else
            str_2 += "Time: "+QString::number(ans_2,'f',2)+" min\n";
        for(int i=path_2.size()-1; i > 0; i--)  // 逆向输出
            str_2 += QString::number(path_2[i]) + " -> ";
        str_2 += QString::number(path_2[0]);
        ui->textEdit->append(str_2);

        // 画点
        paintPoint(path_1, path_2);
    }

    // 出发点在西土城，目的地在西土城 *****************************************************************************
    else {
        // 记录建筑出入口数组（本部目的地）
        query.exec("select * from building_xitucheng limit "+QString::number(destBuilding-1)+",1" );
        while(query.next())
            for(int i=0; i < query.value(1).toInt(); i++)
                points.push(query.value(2+i).toInt());
        // 根据数组找最短路径（只有一个校区，使用1）
        for(int i=0; i < points.size(); i++ ) {
            double tmpAns = -1;
            Vector_int tmpPath ;
            tmpAns = quick_findPath(source, points[i], mode, tmpPath, "map_xitucheng");
            if(tmpAns == -1)
                tmpAns = findPath(source, points[i], mode, tmpPath, "map_xitucheng");
            // 更新答案
            if(ans_1 == -1 || (ans_1 != -1 && tmpAns < ans_1) ) {
                ans_1 = tmpAns;
                path_1.copy(tmpPath);
            }
        }

        // 输出答案（只有西土城）
        QString str = "西土城-";
        if(mode==1)
            str += "Distanece: "+QString::number(ans_1,'f',2)+" m\n";
        else
            str += "Time: "+QString::number(ans_1,'f',2)+" min\n";
        for(int i=path_1.size()-1; i > 0; i--)  // 逆向输出
            str += QString::number(path_1[i]) + " -> ";
        str += QString::number(path_1[0]);
        ui->textEdit->append(str);

        // 画点
        paintPoint(path_1, path_2);

        if(forLessonGuide == 1) {
            if(mode == 1) {
                if(ans_1/speedWalk > restTime) {
                    QMessageBox mess(QMessageBox::Information,"哈哈哈!","你到不了的!");
                    mess.setWindowIcon(QIcon(":/images/02.jpg"));
                    mess.exec();
                }
            }
            else {
                if(ans_1 > restTime) {
                    QMessageBox mess(QMessageBox::Information,"哈哈哈!","你到不了的!");
                    mess.setWindowIcon(QIcon(":/images/02.jpg"));
                    mess.exec();
                }
            }
        }

        endIsShaHe = false;
        endLoc = path_1[0];
    }

    // 录入操作
    globalLog.writeLog(ui->textEdit->toPlainText());

    // 结束操作
    path_1.clear();
    path_2.clear();

    ui->comboBox_Source->clear();
    ui->comboBox_Dest->clear();
    ui->comboBox_lesson->setCurrentIndex(-1);
    ui->xitucheng_Source->setAutoExclusive(false);
    ui->xitucheng_Source->setChecked(false);
    ui->xitucheng_Source->setAutoExclusive(true);
    ui->shahe_Source->setAutoExclusive(false);
    ui->shahe_Source->setChecked(false);
    ui->shahe_Source->setAutoExclusive(true);
    ui->xitucheng_Dest->setAutoExclusive(false);
    ui->xitucheng_Dest->setChecked(false);
    ui->xitucheng_Dest->setAutoExclusive(true);
    ui->shahe_Dest->setAutoExclusive(false);
    ui->shahe_Dest->setChecked(false);
    ui->shahe_Dest->setAutoExclusive(true);

    restTime = 0;
    timeWeek = 0;
    timeHour = 0;
    forLessonGuide = 0;

    // 多路径，记录数据
    if(forMore) {
        if(endIsShaHe) {
            ui->shahe_Source->toggle();
            on_shahe_Source_clicked();
            ui->comboBox_Source->setCurrentIndex(endLoc-1);
            on_comboBox_Source_activated(endLoc-1);
        }
        else {
            ui->xitucheng_Source->toggle();
            on_xitucheng_Source_clicked();
            ui->comboBox_Source->setCurrentIndex(endLoc-1);
            on_comboBox_Source_activated(endLoc-1);
        }
    }
    else {
        sourceIsShaHe = -1;
        source = 0;
        destIsShaHe = -1;
        destBuilding = 0;
    }
}

void Widget_Guide::on_pushButton_more_clicked()
{
    ui->textEdit->clear();
    if(forMore) {
        forMore = false;
        ui->pushButton_more->setText("多路径：关");
    }
    else {
        forMore = true;
        ui->pushButton_more->setText("多路径：开");
    }
}



// _________________________________________________________________________________________________________________________________
bool Widget_Guide::becomeCloser(int subNum, double curAbscissa, double curOrdinate, double destAbscissa, double destOrdinate) {
    double subAbscissa, subOrdinate;
    query.exec("select * from map_shahe limit "+QString::number(subNum-1)+",1");
    while (query.next()) {
        subAbscissa = query.value(2).toDouble();
        subOrdinate = query.value(3).toDouble();
    }
    if( ((subAbscissa-destAbscissa)*(subAbscissa-destAbscissa) + (subOrdinate-destOrdinate)*(subOrdinate-destOrdinate))
        < ((curAbscissa-destAbscissa)*(curAbscissa-destAbscissa) + (curOrdinate-destOrdinate)*(curOrdinate-destOrdinate)) )
        return true;
    return false;
}
// 快速寻找
double Widget_Guide::quick_findPath(int source, int dest, int mode, Vector_int& path, QString table) {
    if(dest == source) {
        path.push(source);
        return 0;
    }

    // 循环全局数据，类似于递推的全局变量 ************************************
    QString command = "select * from " + table +  " limit ";
    double ans = -1;
    double destAbscissa, destOrdinate;  // 目的地的横纵坐标
    int ansIndex = 0;                   // 记录答案所在stack下标
    int curNumber = source;             // 当前stack的number
    double* curData = new double[20];   // 记录当前stack的number对应的所有数据
    double* subData = new double[20];   // 记录当前stack的subNum对应的所有数据
    int subNum_1, subNum_2, subNum_3, subNum_4; // 四个孩子点位的编号

    // 记录答案数组，方便直接跳过已的到达的路径
    query.exec("select * from "+table);
    double* dataAns = new double[query.size()];
    for(int i=0; i < query.size(); i++)
        dataAns[i] = -1;

    // initialize stack ****************************************************************************************
    query.exec(command+QString::number(dest-1)+",1");
    while (query.next()) {
        destAbscissa = query.value(2).toDouble();
        destOrdinate = query.value(3).toDouble();
    }
    query.exec(command+QString::number(curNumber-1)+",1");
    while (query.next())
        for(int i=0; i<20; i++)
            curData[i] = query.value(i).toDouble();
    subNum_1 = (becomeCloser(curData[4], curData[2], curData[3], destAbscissa, destOrdinate)) ? curData[4] : 0 ;
    subNum_2 = (becomeCloser(curData[8], curData[2], curData[3], destAbscissa, destOrdinate)) ? curData[8] : 0 ;
    subNum_3 = (becomeCloser(curData[12], curData[2], curData[3], destAbscissa, destOrdinate)) ? curData[12] : 0 ;
    subNum_4 = (becomeCloser(curData[16], curData[2], curData[3], destAbscissa, destOrdinate)) ? curData[16] : 0 ;

    MapStack stack;
    stack.create(curNumber, subNum_1, subNum_2, subNum_3, subNum_4);
    dataAns[curNumber-1] = 0;

    // 开始查找循环，只往目的地方向查找 *********************************************************************************
    for(int i=0; i < stack.size(); i++) {
        curNumber = stack[i].number;

        // 此处为目的地，更新答案，并直接跳过 *********************************
        if(curNumber==dest) {
            if(ans == -1 || stack[i].data < ans) {
                ans = stack[i].data;
                ansIndex = i;
            }
            continue;
        }

        // 不是目的地，但是data已经超过了已经有的答案 **************************
        if(ans != -1 && stack[i].data > ans)
            continue;        

        // 查询该层stack的所有信息，便于生成子节点的plusNum ********************
        double data = stack[i].data;
        double plusNum;
        query.exec(command+QString::number(curNumber-1)+",1");
        while (query.next()) {
            for(int i=0; i<20; i++)
                curData[i] = query.value(i).toDouble();
        }

        // 开始为4个子层建立新栈，如果该节点直接与当前栈有路径直接相连，则创建（不会往回找） **********
        // ***************************************************************************
        if( stack[i].subNum_1!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = curData[6];
            else if(mode==2)
                plusNum = curData[6]*curData[7]/speedWalk;
            else {
                if(curData[5])  // only for walk
                    plusNum = curData[6]*curData[7]/speedWalk;
                else    // can ride
                    plusNum = curData[6]*curData[7]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则不入栈；否则更新节点
            if( dataAns[stack[i].subNum_1-1] == -1 || dataAns[stack[i].subNum_1-1] > data+plusNum ) {
                dataAns[stack[i].subNum_1-1] = data+plusNum;

                // 生成subNum_1的subNum字段 -- 更加靠近目的地的栈点；如果远离，则置0 (用sub存，因为cur存了该层stack的信息)
                query.exec(command+QString::number(stack[i].subNum_1-1)+",1");
                while (query.next())
                    for(int i=0; i<20; i++)
                        subData[i] = query.value(i).toDouble();
                subNum_1 = (becomeCloser(subData[4], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[4] : 0 ;
                subNum_2 = (becomeCloser(subData[8], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[8] : 0 ;
                subNum_3 = (becomeCloser(subData[12], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[12] : 0 ;
                subNum_4 = (becomeCloser(subData[16], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[16] : 0 ;

                // 压栈
                stack.push(stack[i].subNum_1, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }

        // ***************************************************************************
        if( stack[i].subNum_2!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = curData[10];
            else if(mode==2)
                plusNum = curData[10]*curData[11]/speedWalk;
            else {
                if(curData[9])  // only for walk
                    plusNum = curData[10]*curData[11]/speedWalk;
                else    // can ride
                    plusNum = curData[10]*curData[11]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则不入栈；否则更新节点
            if( dataAns[stack[i].subNum_2-1] == -1 || dataAns[stack[i].subNum_2-1] > data+plusNum ) {
                dataAns[stack[i].subNum_2-1] = data+plusNum;

                // 生成subNum_2的subNum字段 -- 更加靠近目的地的栈点；如果远离，则置0 (用sub存，因为cur存了该层stack的信息)
                query.exec(command+QString::number(stack[i].subNum_2-1)+",1");
                while (query.next())
                    for(int i=0; i<20; i++)
                        subData[i] = query.value(i).toDouble();
                subNum_1 = (becomeCloser(subData[4], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[4] : 0 ;
                subNum_2 = (becomeCloser(subData[8], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[8] : 0 ;
                subNum_3 = (becomeCloser(subData[12], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[12] : 0 ;
                subNum_4 = (becomeCloser(subData[16], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[16] : 0 ;

                // 压栈
                stack.push(stack[i].subNum_2, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }

        // ***************************************************************************
        if( stack[i].subNum_3!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = curData[14];
            else if(mode==2)
                plusNum = curData[14]*curData[15]/speedWalk;
            else {
                if(curData[13])  // only for walk
                    plusNum = curData[14]*curData[15]/speedWalk;
                else    // can ride
                    plusNum = curData[14]*curData[15]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则不入栈；否则更新节点
            if( dataAns[stack[i].subNum_3-1] == -1 || dataAns[stack[i].subNum_3-1] > data+plusNum ) {
                dataAns[stack[i].subNum_3-1] = data+plusNum;

                // 生成subNum_3的subNum字段 -- 更加靠近目的地的栈点；如果远离，则置0 (用sub存，因为cur存了该层stack的信息)
                query.exec(command+QString::number(stack[i].subNum_3-1)+",1");
                while (query.next())
                    for(int i=0; i<20; i++)
                        subData[i] = query.value(i).toDouble();
                subNum_1 = (becomeCloser(subData[4], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[4] : 0 ;
                subNum_2 = (becomeCloser(subData[8], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[8] : 0 ;
                subNum_3 = (becomeCloser(subData[12], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[12] : 0 ;
                subNum_4 = (becomeCloser(subData[16], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[16] : 0 ;

                // 压栈
                stack.push(stack[i].subNum_3, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }

        // ***************************************************************************
        if( stack[i].subNum_4!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = curData[18];
            else if(mode==2)
                plusNum = curData[18]*curData[19]/speedWalk;
            else {
                if(curData[17])  // only for walk
                    plusNum = curData[18]*curData[19]/speedWalk;
                else    // can ride
                    plusNum = curData[18]*curData[19]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则不入栈；否则更新节点
            if( dataAns[stack[i].subNum_4-1] == -1 || dataAns[stack[i].subNum_4-1] > data+plusNum ) {
                dataAns[stack[i].subNum_4-1] = data+plusNum;

                // 生成subNum_4的subNum字段 -- 更加靠近目的地的栈点；如果远离，则置0 (用sub存，因为cur存了该层stack的信息)
                query.exec(command+QString::number(stack[i].subNum_3-1)+",1");
                while (query.next())
                    for(int i=0; i<20; i++)
                        subData[i] = query.value(i).toDouble();
                subNum_1 = (becomeCloser(subData[4], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[4] : 0 ;
                subNum_2 = (becomeCloser(subData[8], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[8] : 0 ;
                subNum_3 = (becomeCloser(subData[12], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[12] : 0 ;
                subNum_4 = (becomeCloser(subData[16], subData[2], subData[3], destAbscissa, destOrdinate)) ? subData[16] : 0 ;

                // 压栈
                stack.push(stack[i].subNum_4, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }
    }
    delete[] curData;
    delete[] subData;
    delete[] dataAns;

    // 通过ansIndex生成path（ans已经生成）
    while(ansIndex != -1) {
        path.push(stack[ansIndex].number);
        ansIndex = stack[ansIndex].index_former;
    }
    stack.burden();

    return ans;
}

// 全面寻找
double Widget_Guide::findPath(int source, int dest, int mode, Vector_int& path, QString table) {
    path.clear();
    QString command = "select * from " + table +  " limit ";

    // initialize stack ****************************************************************************************
    MapStack stack;
    query.exec(command+QString::number(source-1)+",1");
    while( query.next() ) {
        stack.create(
            query.value(0).toInt(),
            query.value(4).toInt(),
            query.value(8).toInt(),
            query.value(12).toInt(),
            query.value(16).toInt());
    }
    qDebug() << "****************Normal***************";

    // 循环全局数据，类似于递推的全局变量 ************************************
    double ans = -1;
    int curNumber = source;             // 当前stack的number
    int ansIndex = 0;                   // 记录答案所在stack下标
    double* roadData = new double[12];  // 记录路径数据

    // 存放答案数组，方便直接跳栈
    query.exec("select * from "+table);
    double* dataAns = new double[query.size()];
    for(int i=0; i < query.size(); i++)
        dataAns[i] = -1;
    dataAns[source-1] = 0;  // 初始化起始答案

    // 开始查找循环，有节点可放则入栈 *********************************************************************************
    for(int i=0; i < stack.size(); i++) {
        curNumber = stack[i].number;

        // 此处为目的地，更新答案，并直接跳过 *********************************
        if(curNumber==dest) {
            if(ans == -1 || stack[i].data < ans) {
                ans = stack[i].data;
                ansIndex = i;
            }
            continue;
        }

        // 不是目的地，但是data已经超过了已经有的答案 **************************
        if(ans != -1 && stack[i].data > ans)
            continue;

        // 针对子点集查询road并生成必要数据(压栈) *****************************
        double data = stack[i].data;
        int plusNum, subNum_1, subNum_2, subNum_3, subNum_4;
        query.exec(command+QString::number(stack[i].number-1)+",1");
        while( query.next() ) {
            roadData[0] = query.value(5).toDouble();    // subNum_1 - forWalk
            roadData[1] = query.value(6).toDouble();    // subNum_1 - distance
            roadData[2] = query.value(7).toDouble();    // subNum_1 - crowd
            roadData[3] = query.value(9).toDouble();    // subNum_2 - forWalk
            roadData[4] = query.value(10).toDouble();   // subNum_2 - distance
            roadData[5] = query.value(11).toDouble();   // subNum_2 - crowd
            roadData[6] = query.value(13).toDouble();   // subNum_3 - forWalk
            roadData[7] = query.value(14).toDouble();   // subNum_3 - distance
            roadData[8] = query.value(15).toDouble();   // subNum_3 - crowd
            roadData[9] = query.value(17).toDouble();   // subNum_4 - forWalk
            roadData[10] = query.value(18).toDouble();  // subNum_4 - distance
            roadData[11] = query.value(19).toDouble();  // subNum_4 - crowd
        }

        // 开始为4个子层建立新栈，如果该节点直接与当前栈有路径直接相连，则创建（不会往回找） **********
        // ***************************************************************************
        if( stack[i].subNum_1!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = roadData[1];
            else if(mode==2)
                plusNum = roadData[1]*roadData[2]/speedWalk;
            else {
                if(roadData[0])  // only for walk
                    plusNum = roadData[1]*roadData[2]/speedWalk;
                else    // can ride
                    plusNum = roadData[1]*roadData[2]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则直接跳过；否则更新节点
            if( dataAns[stack[i].subNum_1-1] == -1 || dataAns[stack[i].subNum_1-1] > data+plusNum ) {
                dataAns[stack[i].subNum_1-1] = data+plusNum;

                // 生成subNum字段 -- 不会生成返回的栈点，因为如果该子栈里的sub字段是当前栈的number，则置0
                query.exec(command+QString::number(stack[i].subNum_1-1)+",1");
                while( query.next() ) {
                    subNum_1 = query.value(4).toInt();
                    if( subNum_1 == curNumber ) subNum_1 = 0;
                    subNum_2 = query.value(8).toInt();
                    if( subNum_2 == curNumber ) subNum_2 = 0;
                    subNum_3 = query.value(12).toInt();
                    if( subNum_3 == curNumber ) subNum_3 = 0;
                    subNum_4 = query.value(16).toInt();
                    if( subNum_4 == curNumber ) subNum_4 = 0;
                }
                // 压栈
                stack.push(stack[i].subNum_1, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }

        // ***************************************************************************
        if( stack[i].subNum_2!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = roadData[4];
            else if(mode==2)
                plusNum = roadData[4]*roadData[5]/speedWalk;
            else {
                if(roadData[3])  // only for walk
                    plusNum = roadData[4]*roadData[5]/speedWalk;
                else    // can ride
                    plusNum = roadData[4]*roadData[5]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则直接跳过；否则更新节点
            if( dataAns[stack[i].subNum_2-1] == -1 || dataAns[stack[i].subNum_2-1] > data+plusNum ) {
                dataAns[stack[i].subNum_2-1] = data+plusNum;

                // 生成subNum字段 -- 不会生成返回的栈点
                query.exec(command+QString::number(stack[i].subNum_2-1)+",1");
                while( query.next() ) {
                    subNum_1 = query.value(4).toInt();
                    if( subNum_1 == curNumber ) subNum_1 = 0;
                    subNum_2 = query.value(8).toInt();
                    if( subNum_2 == curNumber ) subNum_2 = 0;
                    subNum_3 = query.value(12).toInt();
                    if( subNum_3 == curNumber ) subNum_3 = 0;
                    subNum_4 = query.value(16).toInt();
                    if( subNum_4 == curNumber ) subNum_4 = 0;
                }
                // 压栈
                stack.push(stack[i].subNum_2, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }

        // ***************************************************************************
        if( stack[i].subNum_3!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = roadData[7];
            else if(mode==2)
                plusNum = roadData[7]*roadData[8]/speedWalk;
            else {
                if(roadData[6])  // only for walk
                    plusNum = roadData[7]*roadData[8]/speedWalk;
                else    // can ride
                    plusNum = roadData[7]*roadData[8]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则直接跳过；否则更新节点
            if( dataAns[stack[i].subNum_3-1] == -1 || dataAns[stack[i].subNum_3-1] > data+plusNum ) {
                dataAns[stack[i].subNum_3-1] = data+plusNum;

                // 生成subNum字段 -- 不会生成返回的栈点
                query.exec(command+QString::number(stack[i].subNum_3-1)+",1");
                while( query.next() ) {
                    subNum_1 = query.value(4).toInt();
                    if( subNum_1 == curNumber ) subNum_1 = 0;
                    subNum_2 = query.value(8).toInt();
                    if( subNum_2 == curNumber ) subNum_2 = 0;
                    subNum_3 = query.value(12).toInt();
                    if( subNum_3 == curNumber ) subNum_3 = 0;
                    subNum_4 = query.value(16).toInt();
                    if( subNum_4 == curNumber ) subNum_4 = 0;
                }
                // 压栈
                stack.push(stack[i].subNum_3, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }

        // ***************************************************************************
        if( stack[i].subNum_4!=0 ) {
            // 先生成data字段需要的加数
            if(mode==1)
                plusNum = roadData[10];
            else if(mode==2)
                plusNum = roadData[10]*roadData[11]/speedWalk;
            else {
                if(roadData[9])  // only for walk
                    plusNum = roadData[10]*roadData[11]/speedWalk;
                else    // can ride
                    plusNum = roadData[10]*roadData[11]/speedRide;
            }

            // 往前找点，假如节点已到达并且已经距离更短，则直接跳过；否则更新节点
            if( dataAns[stack[i].subNum_4-1] == -1 || dataAns[stack[i].subNum_4-1] > data+plusNum ) {
                dataAns[stack[i].subNum_4-1] = data+plusNum;

                // 生成subNum字段 -- 不会生成返回的栈点
                query.exec(command+QString::number(stack[i].subNum_4-1)+",1");
                while( query.next() ) {
                    subNum_1 = query.value(4).toInt();
                    if( subNum_1 == curNumber ) subNum_1 = 0;
                    subNum_2 = query.value(8).toInt();
                    if( subNum_2 == curNumber ) subNum_2 = 0;
                    subNum_3 = query.value(12).toInt();
                    if( subNum_3 == curNumber ) subNum_3 = 0;
                    subNum_4 = query.value(16).toInt();
                    if( subNum_4 == curNumber ) subNum_4 = 0;
                }
                // 压栈
                stack.push(stack[i].subNum_4, i, subNum_1, subNum_2, subNum_3, subNum_4, data+plusNum);
            }
        }
    }
    delete[] roadData;
    delete[] dataAns;

    // 通过ansIndex生成path（ans已经生成）
    while(ansIndex != -1) {
        path.push(stack[ansIndex].number);
        ansIndex = stack[ansIndex].index_former;
    }
    stack.burden();

    return ans;
}

// _____________________________________________________________________________________________
void Widget_Guide::setUI() {
    this->setFixedSize(1400, 800) ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;
    this->setStyleSheet("background-color:rgb(208, 236, 255);");

    ui->textEdit->setFont(QFont("Consolas",12,75)) ;
    ui->textEdit->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->Button_Search->setFont(QFont("Consolas",12,75)) ;
    ui->Button_Search->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Button_Search_2->setFont(QFont("Consolas",12,75)) ;
    ui->Button_Search_2->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_show->setFont(QFont("Consolas",12,75)) ;
    ui->pushButton_show->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_clear->setFont(QFont("Consolas",12,75)) ;
    ui->pushButton_clear->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_Source->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_Dest->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_lesson->setStyleSheet("background: rgba(255,255,255,50%)") ;
}

void Widget_Guide::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix_xitucheng;
    QPixmap pix_shahe;
    pix_xitucheng.load(":images/xitucheng.png");
    pix_shahe.load(":images/shahe.png");
    painter.drawPixmap(0, 0, 416, 600, pix_xitucheng);
    painter.drawPixmap(445, 0, 955, 600, pix_shahe);
}

void Widget_Guide::paintPoint(Vector_int& xitucheng, Vector_int& shahe)
{
    // 删除所有label
    if(!forMore)
        qDeleteAll(this->findChildren<QLabel* >());

    // 设定前置指令
    QString command_xitucheng = "select * from map_xitucheng limit ";
    QString command_shahe = "select * from map_shahe limit ";

    // 开始画图（1和2）
    for(int i=0; i < xitucheng.size(); i++) {
        query.exec(command_xitucheng+QString::number(xitucheng[i]-1)+",1");
        while(query.next()) {
            // 设定label的位置
            double x = query.value(2).toDouble()*416/579.6;
            double y = 600-query.value(3).toDouble()*600/837.1;

            QLabel* obj = new QLabel(this);
            obj->setText(QString::number(xitucheng[i]));
            obj->setFont(QFont("Microsoft YaHei",15,75)) ;
            obj->setAlignment(Qt::AlignCenter);
            obj->setGeometry(x, y, 20, 20);
            obj->setStyleSheet("background-color: rgb(0, 0, 0); font-size:15px; color:red");
            obj->show();
        }

    }
    for(int i=0; i < shahe.size(); i++) {
        query.exec(command_shahe+QString::number(shahe[i]-1)+",1");
        while(query.next()) {
            // 设定label的位置
            double x = query.value(2).toDouble()*955/1037.2 + 445;
            double y = 600-query.value(3).toDouble()*600/656.2;

            QLabel* obj = new QLabel(this);
            obj->setText(QString::number(shahe[i]));
            obj->setFont(QFont("Microsoft YaHei",15,75)) ;
            obj->setAlignment(Qt::AlignCenter);
            obj->setGeometry(x, y, 20, 20);
            obj->setStyleSheet("background-color: rgb(0, 0, 0); font-size:15px; color:red");
            obj->show();
        }
    }
}



// 显示所有点位
void Widget_Guide::on_pushButton_show_clicked()
{
    // 删除所有label
    qDeleteAll(this->findChildren<QLabel* >());

    // 开始画图
    query.exec("select * from map_xitucheng");
    while(query.next()) {
        // 设定label的位置
        double x = query.value(2).toDouble()*416/579.6;
        double y = 600-query.value(3).toDouble()*600/837.1;

        QLabel* obj = new QLabel(this);
        obj->setText(QString::number(query.value(0).toInt()));
        obj->setFont(QFont("Microsoft YaHei",15,75)) ;
        obj->setAlignment(Qt::AlignCenter);
        obj->setGeometry(x, y, 20, 20);
        obj->setStyleSheet("background-color: rgb(0, 0, 0); font-size:15px; color:red");
        obj->show();
    }
    query.exec("select * from map_shahe");
    while(query.next()) {
        // 设定label的位置
        double x = query.value(2).toDouble()*955/1037.2 + 445;
        double y = 600-query.value(3).toDouble()*600/656.2;

        QLabel* obj = new QLabel(this);
        obj->setText(QString::number(query.value(0).toInt()));
        obj->setFont(QFont("Microsoft YaHei",15,75)) ;
        obj->setAlignment(Qt::AlignCenter);
        obj->setGeometry(x, y, 20, 20);
        obj->setStyleSheet("background-color: rgb(0, 0, 0); font-size:15px; color:red");
        obj->show();
    }
}

void Widget_Guide::on_pushButton_clear_clicked()
{
    // 删除所有label
    qDeleteAll(this->findChildren<QLabel* >());
}

