#include "widget_acivity.h"
#include "ui_widget_acivity.h"

#include <QIcon>
#include <QDebug>
#include <QMessageBox>
#include "kmp.h"

// 方便计算星期数
int CaculateWeekDay(int y,int m, int d);
int CaculateWeekDay(int y,int m, int d)
{
    if(m==1||m==2) {
        m+=12;
        y--;
    }
    int iWeek=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return iWeek + 1;
}

// 计算时间是否有冲突
bool haveCrash(int start1, int end1, int start2, int end2);
bool haveCrash(int start1, int end1, int start2, int end2)
{
    if(start1 >= end2 || end1 <= start2)
        return false;
    return true;
}


Widget_Acivity::Widget_Acivity(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Acivity)
{
    // 留存状态信息
    globalLog.maintainState(QString::number(User_Number)+" acivity");

    ui->setupUi(this);
    setUI();

    // 初始化参数
    sizeSingle = 0;
    sizeTeam = 0;
    single = nullptr;
    singleSelect = nullptr;
    team = nullptr;
    teamSelect = nullptr;

    type = 0;

    isShaHe = -1;
    forPeople = -1;
}

Widget_Acivity::~Widget_Acivity()
{
    delete ui;

    // 刷新状态
    //globalLog.maintainState(QString::number(User_Number));
}

void Widget_Acivity::closeEvent(QCloseEvent *) {
    emit exit_return();
}


// 添加活动模块_______________________________________________________________________________________________________________________________

// 选择地点 *****************************************************************************
void Widget_Acivity::on_radio_IsShaHe_toggled()
{
    ui->comboBox->clear();
    // 添加地点编号
    isShaHe = 1;
    query.exec("select * from building_shahe");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());
    ui->comboBox->setCurrentIndex(-1);
}
void Widget_Acivity::on_radio_IsXiTuCheng_toggled()
{
    ui->comboBox->clear();
    // 添加地点编号
    isShaHe = 0;
    query.exec("select * from building_xitucheng");
    while(query.next())
        ui->comboBox->addItem(query.value(0).toString());
    ui->comboBox->setCurrentIndex(-1);
}
// 选择标签 *******************************************************************************
void Widget_Acivity::on_radio_ForPeople_toggled()
{
    forPeople = 1;
    ui->comboBox_label->clear();
    ui->comboBox_label->addItem("班会");
    ui->comboBox_label->addItem("小组作业");
    ui->comboBox_label->addItem("创新创业活动");
    ui->comboBox_label->addItem("聚餐");
    ui->comboBox_label->setCurrentIndex(-1);
}
void Widget_Acivity::on_radio_ForSingal_toggled()
{
    forPeople = 0;
    ui->comboBox_label->clear();
    ui->comboBox_label->addItem("自习");
    ui->comboBox_label->addItem("锻炼");
    ui->comboBox_label->addItem("外出");
    ui->comboBox_label->setCurrentIndex(-1);
}
// 活动添加 *********************************************************************************
void Widget_Acivity::on_Add_Acivity_clicked()
{
    QString name = ui->edit_Name->text();
    int location = ui->comboBox->currentIndex()+1;
    int year = ui->dateEdit->date().year();
    int month = ui->dateEdit->date().month();
    int day = ui->dateEdit->date().day();
    int start_Hour = ui->comboBox_startHour->currentIndex();;
    int end_Hour = ui->comboBox_endHour->currentIndex();
    QString label = ui->comboBox_label->currentText();

    if(name.isEmpty() || location == 0 || isShaHe == -1 || forPeople == -1 || start_Hour > end_Hour || isEnded(year, month, day, start_Hour)) {
        QMessageBox mess(QMessageBox::Information,"Warning!","somthing is empyt or time is invalid.");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // ************************************************************核心算法*****************************************************************
    int flag = 0;
    // 添加检测机制-1：判断是否和课程有冲突（直接看在的课程里是不是有冲突）_____________________________________________
    int weekDay = CaculateWeekDay(year, month, day);
    int left, right;    // 下界和上界（1，2，3，4，边界为0，5），针对课程节数使用，判断是否落在活动中。如果落在(left <= index <= right)，则冲突
    if(start_Hour < 8)
        left = 0;
    else if(start_Hour < 10)
        left = 1;
    else if(start_Hour < 12)
        left = 2;
    else if(start_Hour < 14)
        left = 3;
    else if(start_Hour < 16)
        left = 4;
    else    left = 5;
    if(end_Hour > 16)
        right = 5;
    else if(end_Hour > 14)
        right = 4;
    else if(end_Hour > 12)
        right = 3;
    else if(end_Hour > 10)
        right = 2;
    else if(end_Hour > 8)
        right = 1;
    else    right = 0;
    qDebug() << "left" << left << "right" << right;
    // 找必修课 ______________________________________________________
    QString userClass;
    query.exec("select * from people limit "+QString::number(User_Number-1)+",1");
    while(query.next())
        userClass = query.value(5).toString();
    query.exec("select * from lesson_compulsory");
    qDebug() << "select * from lesson_compulsory";
    while(!flag && query.next()) {
        if(query.value(8).toString() == userClass && query.value(5).toInt() == weekDay
                && left <= query.value(6).toInt() && query.value(6).toInt() <= right )
            flag = 1;
    }
    // 找选修课 ______________________________________________________
    query.exec("select * from "+QString::number(User_Number)+"_select");
    qDebug() << "select * from "+QString::number(User_Number)+"_select";
    while(!flag && query.next()) {
        if(query.value(5).toInt() == weekDay && left <= query.value(6).toInt() && query.value(6).toInt() <= right)
            flag = 1;
    }
    if(flag == 1) {
        QMessageBox mess(QMessageBox::Information,"Warning!","发生冲突.");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 添加检测机制-2：判断是否和活动有冲突（事件时间是否冲突）_____________________________________________
    // 先找集体活动
    query.exec("select * from acivity");
    qDebug() << "select * from acivity";
    while(!flag && query.next()) {
        if(query.value(3).toInt()==year && query.value(4).toInt()==month && query.value(5).toInt()==day
                && haveCrash(query.value(6).toInt(), query.value(7).toInt(), start_Hour, end_Hour))
            flag = 1;
    }
    // 再找个人活动
    query.exec("select * from "+QString::number(User_Number)+"_once");
    qDebug() << "select * from "+QString::number(User_Number)+"_once";
    while(!flag && query.next()) {
        if(query.value(3).toInt()==year && query.value(4).toInt()==month && query.value(5).toInt()==day
                && haveCrash(query.value(6).toInt(), query.value(7).toInt(), start_Hour, end_Hour))
            flag = 1;
    }
    if(flag == 1) {
        QMessageBox mess(QMessageBox::Information,"Warning!","发生冲突.");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }


    // 没有问题，添加个人活动 _________________________________________________________________________________
    if(forPeople == 0) {
        QString cmd = "insert into "+QString::number(User_Number)+"_once ";
        cmd += "(name, isShaHe, location, year, month, day, start_hour, end_hour, label) values(";
        cmd += "'" + name + "',"
            + QString::number(isShaHe) + "," + QString::number(location) + ","
            + QString::number(year) + "," + QString::number(month) + "," + QString::number(day) + ","
            + QString::number(start_Hour) + "," + QString::number(end_Hour) + ",'" + label + "')";

        qDebug() << cmd;
        query.exec(cmd);
    }
    // 添加集体活动
    else {
        QString cmd = "insert into acivity ";
        cmd += "(name, isShaHe, location, year, month, day, start_hour, end_hour, label, user) values(";
        cmd += "'" + name + "',"
            + QString::number(isShaHe) + "," + QString::number(location) + ","
            + QString::number(year) + "," + QString::number(month) + "," + QString::number(day) + ","
            + QString::number(start_Hour) + "," + QString::number(end_Hour) + ",'" + label + "'," + QString::number(User_Number)+")";

        qDebug() << cmd;
        query.exec(cmd);
    }

    QMessageBox mess(QMessageBox::Information,"Success!","acivity added.");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();
}



// 查询活动模块 _____________________________________________________________________________________________________________________________________

// 个人活动查询 ********************************************************************************************************
void Widget_Acivity::on_pushButton_single_clicked()
{
    // 初始数据处理
    ui->textEdit->clear();
    ui->comboBox_event->clear();
    type = 1;
    ui->comboBox_labelSelect->clear();
    ui->comboBox_labelSelect->addItem("自习");
    ui->comboBox_labelSelect->addItem("锻炼");
    ui->comboBox_labelSelect->addItem("外出");
    ui->comboBox_labelSelect->setCurrentIndex(-1);


    // 先进行记录的删除
    if(single != nullptr) {
        AcivityPtr tmp1 = single;
        AcivityPtr tmp2 = single->nextPtr;
        while(tmp2 != nullptr) {
            delete tmp1;
            tmp1 = tmp2;
            tmp2 = tmp2->nextPtr;
        }
        delete tmp1;

        delete[] singleSelect;  // 删除对应的指针数组
        single = nullptr;
        singleSelect = nullptr;
    }

    // 查询个人活动
    single = new Acivity;   // 先创建头部，不放信息
    single->nextPtr = nullptr;
    sizeSingle = 0;

    AcivityPtr tmp = single;
    query.exec("select * from "+QString::number(User_Number)+"_once");
    while(query.next()) {
        tmp->nextPtr = new Acivity;

        tmp->nextPtr->name      = query.value(0).toString();
        tmp->nextPtr->isShahe   = query.value(1).toInt();
        tmp->nextPtr->location  = query.value(2).toInt();
        tmp->nextPtr->year      = query.value(3).toInt();
        tmp->nextPtr->month     = query.value(4).toInt();
        tmp->nextPtr->day       = query.value(5).toInt();
        tmp->nextPtr->startHour = query.value(6).toInt();
        tmp->nextPtr->endHour   = query.value(7).toInt();
        tmp->nextPtr->label     = query.value(8).toString();

        tmp->nextPtr->nextPtr   = nullptr;
        tmp = tmp->nextPtr;
        sizeSingle++;
    }

    // 生成指针数组
    singleSelect = new AcivityPtr[sizeSingle];
    sizeSingleSelect = sizeSingle;
    tmp = single->nextPtr;
    for(int i=0; i < sizeSingleSelect; i++) {
        singleSelect[i] = tmp;
        tmp = tmp->nextPtr;

        QString address;
        if(singleSelect[i]->isShahe == 1) {
            query.exec("select * from building_shahe limit "+QString::number(singleSelect[i]->location-1)+",1");
            while(query.next()) address = "沙河："+query.value(0).toString();
        }
        else {
            query.exec("select * from building_xitucheng limit "+QString::number(singleSelect[i]->location-1)+",1");
            while(query.next()) address = "西土城："+query.value(0).toString();
        }

        // 顺便直接展示到textedit上
        ui->textEdit->append(singleSelect[i]->name+"  "+QString::number(singleSelect[i]->year)+"-"+QString::number(singleSelect[i]->month)+"-"+QString::number(singleSelect[i]->day)
                             +" "+QString::number(singleSelect[i]->startHour)+"h~"+QString::number(singleSelect[i]->endHour)+"h "
                             +"Loc: "+address+" label: "+singleSelect[i]->label);

        // 顺便展示到combox_event上
        ui->comboBox_event->addItem(singleSelect[i]->name);
    }
    ui->comboBox_event->setCurrentIndex(-1);


    globalLog.writeLog("个人活动查询");
}

// 集体活动查询 ********************************************************************************************************
void Widget_Acivity::on_pushButton_allPeople_clicked()
{
    // 初始数据处理
    ui->textEdit->clear();
    ui->comboBox_event->clear();
    type = 2;
    ui->comboBox_labelSelect->clear();
    ui->comboBox_labelSelect->addItem("班会");
    ui->comboBox_labelSelect->addItem("小组作业");
    ui->comboBox_labelSelect->addItem("创新创业活动");
    ui->comboBox_labelSelect->addItem("聚餐");
    ui->comboBox_labelSelect->setCurrentIndex(-1);

    // 先进行记录的删除
    if(team != nullptr) {
        AcivityPtr tmp1 = team;
        AcivityPtr tmp2 = team->nextPtr;
        while(tmp2 != nullptr) {
            delete tmp1;
            tmp1 = tmp2;
            tmp2 = tmp2->nextPtr;
        }
        delete tmp1;

        delete[] teamSelect;  // 删除对应的指针数组
        team = nullptr;
        teamSelect = nullptr;
    }

    // 查询个人活动
    team = new Acivity;   // 先创建头部，不放信息
    team->nextPtr = nullptr;
    sizeTeam = 0;

    AcivityPtr tmp = team;
    query.exec("select * from acivity");
    while(query.next()) {
        tmp->nextPtr = new Acivity;

        tmp->nextPtr->name      = query.value(0).toString();
        tmp->nextPtr->isShahe   = query.value(1).toInt();
        tmp->nextPtr->location  = query.value(2).toInt();
        tmp->nextPtr->year      = query.value(3).toInt();
        tmp->nextPtr->month     = query.value(4).toInt();
        tmp->nextPtr->day       = query.value(5).toInt();
        tmp->nextPtr->startHour = query.value(6).toInt();
        tmp->nextPtr->endHour   = query.value(7).toInt();
        tmp->nextPtr->label     = query.value(8).toString();

        tmp->nextPtr->nextPtr   = nullptr;
        tmp = tmp->nextPtr;
        sizeTeam++;
    }

    // 生成指针数组
    teamSelect = new AcivityPtr[sizeTeam];
    sizeTeamSelect = sizeTeam;
    tmp = team->nextPtr;
    for(int i=0; i < sizeTeamSelect; i++) {
        teamSelect[i] = tmp;
        tmp = tmp->nextPtr;

        QString address;
        if(teamSelect[i]->isShahe == 1) {
            query.exec("select * from building_shahe limit "+QString::number(teamSelect[i]->location-1)+",1");
            while(query.next()) address = "沙河："+query.value(0).toString();
        }
        else {
            query.exec("select * from building_xitucheng limit "+QString::number(teamSelect[i]->location-1)+",1");
            while(query.next()) address = "西土城："+query.value(0).toString();
        }

        // 顺便直接展示到textedit上
        ui->textEdit->append(teamSelect[i]->name+"  "+QString::number(teamSelect[i]->year)+"-"+QString::number(teamSelect[i]->month)+"-"+QString::number(teamSelect[i]->day)
                             +" "+QString::number(teamSelect[i]->startHour)+"h~"+QString::number(teamSelect[i]->endHour)+"h "
                             +"Loc: "+address+" label: "+teamSelect[i]->label);

        // 顺便展示到combox_event上
        ui->comboBox_event->addItem(teamSelect[i]->name);
    }
    ui->comboBox_event->setCurrentIndex(-1);

    globalLog.writeLog("集体活动查询");
}


// 进行字段筛选 ******************************************************************************************
void Widget_Acivity::on_pushButton_select_clicked()
{
    ui->textEdit->clear();
    QByteArray input = ui->lineEdit_select->text().toUtf8();
    ui->lineEdit_select->clear();

    // 展示个人活动
    if(type == 1) {
        if(single == nullptr)   return;

        AcivityPtr tmp = single->nextPtr;
        sizeSingleSelect = 0;
        for(int i=0; i < sizeSingle; i++) {
            QByteArray name = tmp->name.toUtf8();
            if(kmp(name.data(), name.size(), input.data(), input.size()))
                singleSelect[sizeSingleSelect++] = tmp;
            tmp = tmp->nextPtr;
        }

        // 如果有标签选择，那么进行筛选
        if(ui->comboBox_labelSelect->currentIndex() != -1) {
            QString input = ui->comboBox_labelSelect->currentText();

            int tmpSize = sizeSingleSelect;
            sizeSingleSelect = 0;
            for(int i=0; i < tmpSize; i++)  // 往前覆盖
                if(input == singleSelect[i]->label)
                    singleSelect[sizeSingleSelect++] = singleSelect[i];
        }

        for(int i=0; i < sizeSingleSelect; i++) {
            QString address;
            if(singleSelect[i]->isShahe == 1) {
                query.exec("select * from building_shahe limit "+QString::number(singleSelect[i]->location-1)+",1");
                while(query.next()) address = "沙河："+query.value(0).toString();
            }
            else {
                query.exec("select * from building_xitucheng limit "+QString::number(singleSelect[i]->location-1)+",1");
                while(query.next()) address = "西土城："+query.value(0).toString();
            }

            // 顺便直接展示到textedit上
            ui->textEdit->append(singleSelect[i]->name+"  "+QString::number(singleSelect[i]->year)+"-"+QString::number(singleSelect[i]->month)+"-"+QString::number(singleSelect[i]->day)
                                 +" "+QString::number(singleSelect[i]->startHour)+"h~"+QString::number(singleSelect[i]->endHour)+"h "
                                 +"Loc: "+address+" label: "+singleSelect[i]->label);
        }
    }

    // 展示集体活动
    else if(type == 2) {
        if(team == nullptr)   return;

        AcivityPtr tmp = team->nextPtr;
        sizeTeamSelect = 0;
        for(int i=0; i < sizeTeam; i++) {
            QByteArray name = tmp->name.toUtf8();
            if(kmp(name.data(), name.size(), input.data(), input.size()))
                teamSelect[sizeTeamSelect++] = tmp;
            tmp = tmp->nextPtr;
        }

        // 如果有标签选择，那么进行筛选
        if(ui->comboBox_labelSelect->currentIndex() != -1) {
            QString input = ui->comboBox_labelSelect->currentText();

            int tmpSize = sizeTeamSelect;
            sizeTeamSelect = 0;
            for(int i=0; i < tmpSize; i++)  // 往前覆盖
                if(input == teamSelect[i]->label)
                    teamSelect[sizeTeamSelect++] = teamSelect[i];
        }

        for(int i=0; i < sizeTeamSelect; i++) {
            QString address;
            if(teamSelect[i]->isShahe == 1) {
                query.exec("select * from building_shahe limit "+QString::number(teamSelect[i]->location-1)+",1");
                while(query.next()) address = "沙河："+query.value(0).toString();
            }
            else {
                query.exec("select * from building_xitucheng limit "+QString::number(teamSelect[i]->location-1)+",1");
                while(query.next()) address = "西土城："+query.value(0).toString();
            }

            // 顺便直接展示到textedit上
            ui->textEdit->append(teamSelect[i]->name+"  "+QString::number(teamSelect[i]->year)+"-"+QString::number(teamSelect[i]->month)+"-"+QString::number(teamSelect[i]->day)
                                 +" "+QString::number(teamSelect[i]->startHour)+"h~"+QString::number(teamSelect[i]->endHour)+"h "
                                 +"Loc: "+address+" label: "+teamSelect[i]->label);
        }
    }

    globalLog.writeLog("查询字段筛选");
}

// 活动排序 **********************************************************************************************************
void Widget_Acivity::on_pushButton_timePaixu_clicked()
{
    ui->textEdit->clear();
    if(type == 1) {
        quickSort_Time(singleSelect, 0, sizeSingleSelect-1);
        for(int i=0; i < sizeSingleSelect; i++) {
            QString address;
            if(singleSelect[i]->isShahe == 1) {
                query.exec("select * from building_shahe limit "+QString::number(singleSelect[i]->location-1)+",1");
                while(query.next()) address = "沙河："+query.value(0).toString();
            }
            else {
                query.exec("select * from building_xitucheng limit "+QString::number(singleSelect[i]->location-1)+",1");
                while(query.next()) address = "西土城："+query.value(0).toString();
            }

            // 顺便直接展示到textedit上
            ui->textEdit->append(singleSelect[i]->name+"  "+QString::number(singleSelect[i]->year)+"-"+QString::number(singleSelect[i]->month)+"-"+QString::number(singleSelect[i]->day)
                                 +" "+QString::number(singleSelect[i]->startHour)+"h~"+QString::number(singleSelect[i]->endHour)+"h "
                                 +"Loc: "+address+" label: "+singleSelect[i]->label);
        }
    }
    else if(type == 2) {
        quickSort_Time(teamSelect, 0, sizeTeamSelect-1);
        for(int i=0; i < sizeTeamSelect; i++) {
            QString address;
            if(teamSelect[i]->isShahe == 1) {
                query.exec("select * from building_shahe limit "+QString::number(teamSelect[i]->location-1)+",1");
                while(query.next()) address = "沙河："+query.value(0).toString();
            }
            else {
                query.exec("select * from building_xitucheng limit "+QString::number(teamSelect[i]->location-1)+",1");
                while(query.next()) address = "西土城："+query.value(0).toString();
            }

            // 顺便直接展示到textedit上
            ui->textEdit->append(teamSelect[i]->name+"  "+QString::number(teamSelect[i]->year)+"-"+QString::number(teamSelect[i]->month)+"-"+QString::number(teamSelect[i]->day)
                                 +" "+QString::number(teamSelect[i]->startHour)+"h~"+QString::number(teamSelect[i]->endHour)+"h "
                                 +"Loc: "+address+" label: "+teamSelect[i]->label);

        }
    }
}
void Widget_Acivity::on_pushButton_namePaixu_clicked()
{
    ui->textEdit->clear();
    if(type == 1) {
        quickSort_Name(singleSelect, 0, sizeSingleSelect-1);
        for(int i=0; i < sizeSingleSelect; i++) {
            QString address;
            if(singleSelect[i]->isShahe == 1) {
                query.exec("select * from building_shahe limit "+QString::number(singleSelect[i]->location-1)+",1");
                while(query.next()) address = "沙河："+query.value(0).toString();
            }
            else {
                query.exec("select * from building_xitucheng limit "+QString::number(singleSelect[i]->location-1)+",1");
                while(query.next()) address = "西土城："+query.value(0).toString();
            }

            // 顺便直接展示到textedit上
            ui->textEdit->append(singleSelect[i]->name+"  "+QString::number(singleSelect[i]->year)+"-"+QString::number(singleSelect[i]->month)+"-"+QString::number(singleSelect[i]->day)
                                 +" "+QString::number(singleSelect[i]->startHour)+"h~"+QString::number(singleSelect[i]->endHour)+"h "
                                 +"Loc: "+address+" label: "+singleSelect[i]->label);
        }
    }
    else if(type == 2) {
        quickSort_Name(teamSelect, 0, sizeTeamSelect-1);
        for(int i=0; i < sizeTeamSelect; i++) {
            QString address;
            if(teamSelect[i]->isShahe == 1) {
                query.exec("select * from building_shahe limit "+QString::number(teamSelect[i]->location-1)+",1");
                while(query.next()) address = "沙河："+query.value(0).toString();
            }
            else {
                query.exec("select * from building_xitucheng limit "+QString::number(teamSelect[i]->location-1)+",1");
                while(query.next()) address = "西土城："+query.value(0).toString();
            }

            // 顺便直接展示到textedit上
            ui->textEdit->append(teamSelect[i]->name+"  "+QString::number(teamSelect[i]->year)+"-"+QString::number(teamSelect[i]->month)+"-"+QString::number(teamSelect[i]->day)
                                 +" "+QString::number(teamSelect[i]->startHour)+"h~"+QString::number(teamSelect[i]->endHour)+"h "
                                 +"Loc: "+address+" label: "+teamSelect[i]->label);

        }
    }
}
// 名称快排
void Widget_Acivity::quickSort_Name(AcivityPtr* array, int l, int r)
{
    if(l >= r) return;
    int i = l;  // 从左边界起始
    int j = r;  // 从右边界起始
    AcivityPtr key = array[i]; // 最左边作为key
    while (i<j)
    {
        // 右边向左滑
        while( i < j && array[j]->name >= key->name )
        {
            j--;
        }
        array[i] = array[j];
        // 左边向右滑
        while( i < j && array[i]->name <= key->name )
        {
            i++;
        }
        array[j] = array[i];
    }
    array[i] = key; // i == j
    quickSort_Name(array,l,i-1);
    quickSort_Name(array,i+1,r);
}
// 时间快排
void Widget_Acivity::quickSort_Time(AcivityPtr* array, int l, int r)
{
    if(l >= r) return;
    int i = l;  // 从左边界起始
    int j = r;  // 从右边界起始
    AcivityPtr key = array[i]; // 最左边作为key
    while (i<j)
    {
        while( i<j && !isBefore(array[j]->year, array[j]->month, array[j]->day, array[j]->startHour,
                               key->year, key->month, key->day, key->startHour) )
        {
            j--;
        }
        array[i] = array[j];
        while( i<j && isBefore(array[i]->year, array[i]->month, array[i]->day, array[i]->startHour,
                                key->year, key->month, key->day, key->startHour) )
        {
            i++;
        }
        array[j] = array[i];
    }
    array[i] = key; // i == j
    quickSort_Time(array,l,i-1);
    quickSort_Time(array,i+1,r);
}



// 删除活动
void Widget_Acivity::on_pushButton_eventDelete_clicked()
{
    if(ui->comboBox_event->currentIndex() != -1) {
        QString name = ui->comboBox_event->currentText();
        // 删除个人活动
        if(type == 1) {
            query.exec("delete from "+QString::number(User_Number)+"_once where name = '"+name+"'");
            on_pushButton_single_clicked();
        }
        // 删除集体活动
        else if(type == 2) {
            int flag = 1;
            // 先得看能不能找到是自己的
            query.exec("select * from acivity");
            while(flag && query.next()) {
                if(query.value(0).toString() == name) {
                    flag = 0;
                    if(User_Number != query.value(9).toInt()) {
                        QMessageBox mess(QMessageBox::Information,"Warning!","Acivity created by others.");
                        mess.setWindowIcon(QIcon(":/images/02.jpg"));
                        mess.exec();
                        return;
                    }
                    query.exec("delete from acivity where name = '"+name+"'");
                    on_pushButton_allPeople_clicked();
                }
            }
        }
    }
    else {
        QMessageBox mess(QMessageBox::Information,"Warning!","Nothing Selected.");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }
    QMessageBox mess(QMessageBox::Information,"Success!","acivity deleted.");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();
}



void Widget_Acivity::setUI() {
    this->setFixedSize(1200, 800) ;
    this->setWindowTitle("Acivity") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;
    this->setStyleSheet("background-color: rgb(220, 213, 255);");

    ui->textEdit->setFont(QFont("Consolas",18,75)) ;
    ui->textEdit->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->edit_Name->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->edit_Name->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->Add_Acivity->setFont(QFont("Microsoft YaHei",15,75)) ;
    ui->Add_Acivity->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->comboBox->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_label->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->comboBox_label->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_startHour->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->comboBox_startHour->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_endHour->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->comboBox_endHour->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->pushButton_single->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_single->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_allPeople->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_allPeople->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_select->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_select->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_labelSelect->setFont(QFont("Microsoft YaHei",10,75)) ;
    ui->comboBox_labelSelect->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_namePaixu->setFont(QFont("Microsoft YaHei",10,75)) ;
    ui->pushButton_namePaixu->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->pushButton_timePaixu->setFont(QFont("Microsoft YaHei",10,75)) ;
    ui->pushButton_timePaixu->setStyleSheet("background: rgba(255,255,255,50%)") ;

}

