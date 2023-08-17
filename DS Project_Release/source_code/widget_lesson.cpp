#include "widget_lesson.h"
#include "ui_widget_lesson.h"

#include <QIcon>
#include <QDebug>
#include "global.h"
#include "kmp.h"

Widget_Lesson::Widget_Lesson(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_Lesson)
{
    // 留存状态信息
    globalLog.maintainState(QString::number(User_Number)+" lesson");

    ui->setupUi(this);
    setUI();
    setInformation();

    // 初始化
    zip = new MainWindow(this);
    sizeSelect = 0; // 未筛选，规定不能排序
}

Widget_Lesson::~Widget_Lesson()
{
    delete ui;

    // 有线程，要安全删除
    zip->deleteLater();

    // 删除必要暂存信息（课程链表）
    delete[] formatIndex;

    // 释放课程信息
    LessonPtr tmp_1 = lessons;
    LessonPtr tmp_2 = lessons->nextptr;
    for(int i=0; i < size; i++) {
        delete tmp_1;
        tmp_1 = tmp_2;
        tmp_2 = tmp_2->nextptr;
    }
    delete tmp_1;
    lessons = nullptr;
    delete[] lessonSelect;

    // 释放选修信息
    tmp_1 = lessonXuanxiu;
    tmp_2 = lessonXuanxiu->nextptr;
    for(int i=0; i < sizeXuanxiu; i++) {
        delete tmp_1;
        tmp_1 = tmp_2;
        tmp_2 = tmp_2->nextptr;
    }
    delete tmp_1;
    lessonXuanxiu = nullptr;
    delete lessonXuanxiuSelect;

    // 刷新状态
    //globalLog.maintainState(QString::number(User_Number));
}

void Widget_Lesson::closeEvent(QCloseEvent *) {
    emit exit_return();
}



// 初始化所有信息 *********************************************************************
void Widget_Lesson::setInformation() {
    // 当前进度
    ui->label_jindu->setText("当前进度: "+QString::number(system_Time.get_Week())+" / 16");

    // 学生不需要的功能
    if(User_IsAdmin == 0) {
        ui->pushButton_add->hide();
        ui->pushButton_change->hide();
        ui->pushButton_task->hide();
        ui->pushButton_test->hide();
    }
    // 老师不需要的功能
    else {
        ui->pushButton_send->hide();
        ui->pushButton_submit->hide();
        ui->pushButton_delete->hide();
        ui->comboBox_xuanxiu->hide();
        ui->label_xuanxiu->hide();
        ui->lineEdit_findxuanxiu->hide();
        ui->pushButton_findxuanxiu->hide();
        ui->pushButton_addxuanxiu->hide();
    }

    // 画出课程表___________________________________________________________________________________
    format = new QPushButton*[28];
    // 先画出按钮
    for(int i=0; i < 7; i++) {
        for(int j=0; j < 4; j++) {
            format[4*i+j] = new QPushButton(this);
            format[4*i+j]->setGeometry(50+150*i, 50+100*j, 150, 100);
            format[4*i+j]->setFont(QFont("Microsoft YaHei",10,75));
            format[4*i+j]->setStyleSheet("background: rgba(255,255,255,50%)");
            format[4*i+j]->show();
            connect(format[4*i+j],&QPushButton::clicked,[=]() {
                int x=this->mapFromGlobal(QCursor().pos()).x();
                int y=this->mapFromGlobal(QCursor().pos()).y();
                selectIndex = 4*((x-50)/150) + (y-50)/100;
                qDebug() << "select" << selectIndex;
                showInformation();
            });
        }
    }

    // 获得课程信息 *********************************************
    lessons = new Lesson;   // 头部，不存储信息
    lessons->nextptr = nullptr;
    size = 0;
    LessonPtr tmp = lessons;
    // 学生 ____________________________________
    if(User_IsAdmin == 0) {
        // 先找出学生班级
        QString userClass;
        query.exec("select * from people limit "+QString::number(User_Number-1)+",1");
        while(query.next())
            userClass = query.value(5).toString();
        // 找必修课程
        qDebug() << "select * from lesson_compulsory";
        query.exec("select * from lesson_compulsory");
        while(query.next()) {
            if(userClass == query.value(9).toString()) {
                tmp->nextptr = new Lesson;
                tmp->nextptr->isSelect  = 0;
                tmp->nextptr->number    = query.value(0).toInt();
                tmp->nextptr->name      = query.value(1).toString();
                tmp->nextptr->teacher   = query.value(2).toInt();
                tmp->nextptr->isShaHe   = query.value(3).toInt();
                tmp->nextptr->location  = query.value(4).toInt();
                tmp->nextptr->dayOfWeek = query.value(5).toInt();
                tmp->nextptr->index     = query.value(6).toInt();
                tmp->nextptr->qun       = query.value(7).toString();
                tmp->nextptr->extra     = query.value(8).toString();
                tmp->nextptr->nextptr   = nullptr;
                tmp = tmp->nextptr;
                size++;
            }
        }
        // 找选过的选修课程
        qDebug() << "select * from "+QString::number(User_Number)+"_select";
        query.exec("select * from "+QString::number(User_Number)+"_select");
        while(query.next()) {
            tmp->nextptr = new Lesson;
            tmp->nextptr->isSelect  = 1;
            tmp->nextptr->number    = query.value(0).toInt();
            tmp->nextptr->name      = query.value(1).toString();
            tmp->nextptr->teacher   = query.value(2).toInt();
            tmp->nextptr->isShaHe   = query.value(3).toInt();
            tmp->nextptr->location  = query.value(4).toInt();
            tmp->nextptr->dayOfWeek = query.value(5).toInt();
            tmp->nextptr->index     = query.value(6).toInt();
            tmp->nextptr->qun       = query.value(7).toString();
            tmp->nextptr->extra     = query.value(8).toString();
            tmp->nextptr->nextptr   = nullptr;
            tmp = tmp->nextptr;
            size++;
        }
    }
    // 老师 __________________________________
    else {
        // 找必修课程
        query.exec("select * from lesson_compulsory");
        while(query.next()) {
            if(User_Number == query.value(2).toInt()) {
                tmp->nextptr = new Lesson;
                tmp->nextptr->isSelect  = 0;
                tmp->nextptr->number    = query.value(0).toInt();
                tmp->nextptr->name      = query.value(1).toString();
                tmp->nextptr->teacher   = query.value(2).toInt();
                tmp->nextptr->isShaHe   = query.value(3).toInt();
                tmp->nextptr->location  = query.value(4).toInt();
                tmp->nextptr->dayOfWeek = query.value(5).toInt();
                tmp->nextptr->index     = query.value(6).toInt();
                tmp->nextptr->qun       = query.value(7).toString();
                tmp->nextptr->extra     = query.value(8).toString();
                tmp->nextptr->nextptr   = nullptr;
                tmp = tmp->nextptr;
                size++;
            }
        }
        // 找选修课程
        query.exec("select * from lesson_select");
        while(query.next()) {
            if(User_Number == query.value(2).toInt()) {
                tmp->nextptr = new Lesson;
                tmp->nextptr->isSelect  = 1;
                tmp->nextptr->number    = query.value(0).toInt();
                tmp->nextptr->name      = query.value(1).toString();
                tmp->nextptr->teacher   = query.value(2).toInt();
                tmp->nextptr->isShaHe   = query.value(3).toInt();
                tmp->nextptr->location  = query.value(4).toInt();
                tmp->nextptr->dayOfWeek = query.value(5).toInt();
                tmp->nextptr->index     = query.value(6).toInt();
                tmp->nextptr->qun       = query.value(7).toString();
                tmp->nextptr->extra     = query.value(8).toString();
                tmp->nextptr->nextptr   = nullptr;
                tmp = tmp->nextptr;
                size++;
            }
        }
    }
    // 排开课程表 （课程表信息）
    formatIndex = new int[size];
    tmp = lessons->nextptr;
    // 遍历课程信息链表，放入28个按钮中
    for(int i=0; i < size; i++) {
        this->format[4*(tmp->dayOfWeek-1)+(tmp->index-1)]->setText(tmp->name);  // 填入课程名称
        formatIndex[i] = 4*(tmp->dayOfWeek-1)+(tmp->index-1);   // 记录下标（0-27）
        tmp = tmp->nextptr;
    }

    // 生成选修课链表 ************************************************************
    lessonXuanxiu = new Lesson;   // 头部，不存储信息
    lessonXuanxiu->nextptr = nullptr;
    sizeXuanxiu = 0;
    tmp = lessonXuanxiu;
    query.exec("select * from lesson_select");
    while(query.next()) {
        tmp->nextptr = new Lesson;
        tmp->nextptr->isSelect  = 1;
        tmp->nextptr->number    = query.value(0).toInt();
        tmp->nextptr->name      = query.value(1).toString();
        tmp->nextptr->teacher   = query.value(2).toInt();
        tmp->nextptr->isShaHe   = query.value(3).toInt();
        tmp->nextptr->location  = query.value(4).toInt();
        tmp->nextptr->dayOfWeek = query.value(5).toInt();
        tmp->nextptr->index     = query.value(6).toInt();
        tmp->nextptr->qun       = query.value(7).toString();
        tmp->nextptr->extra     = query.value(8).toString();
        tmp->nextptr->nextptr   = nullptr;
        tmp = tmp->nextptr;
        sizeXuanxiu++;
    }

    // 初始化
    filePath.setPath("");   // 没有选中任何课程，为空
    // 建立指针空间
    lessonSelect = new LessonPtr[size];
    lessonXuanxiuSelect = new LessonPtr[sizeXuanxiu];

    // 顺便点击一下这个东西显示选修课程
    on_pushButton_findxuanxiu_clicked();
}


// 点击后显示所有信息_____________________________________________________________________________________________________
void Widget_Lesson::showInformation() {
    ui->comboBox_task_1->clear();
    ui->comboBox_task_2->clear();
    ui->textEdit_test->clear();
    zip->setFilepath("");

    // 显示所有信息____________________________________________________________________
    int flag = 0;
    LessonPtr tmp = lessons->nextptr;
    // 在链表中循环找，找到就显示，然后跳出（没找到那就遍历完了都没有显示）
    for(int i=0; !flag && i < size; i++) {
        if(formatIndex[i] == selectIndex) {
            // 显示地点
            if(tmp->isShaHe == 0) {
                query.exec("select * from building_xitucheng limit "+QString::number(tmp->location-1)+",1");
                while(query.next()) ui->label_location->setText("西土城: "+query.value(0).toString()+" "+tmp->extra);
            } else {
                query.exec("select * from building_shahe limit "+QString::number(tmp->location-1)+",1");
                while(query.next()) ui->label_location->setText("沙河: "+query.value(0).toString()+" "+tmp->extra);
            }

            // 显示群
            ui->label_qun->setText("群号: "+tmp->qun);

            // 显示考试信息
            query.exec("select * from lesson_test");
            while(query.next()) {
                if(query.value(1).toInt() == tmp->number && query.value(2).toInt() == tmp->isSelect) {
                    QString str = query.value(0).toString();
                    QSqlQuery tmpQuery;

                    // 设置信息（沙河还是西土城,以及时间）
                    if(query.value(3).toInt() == 0) {
                        tmpQuery.exec("select * from building_xitucheng limit "+QString::number(query.value(4).toInt()-1)+",1");
                        while(tmpQuery.next()) str += "\n西土城: "+tmpQuery.value(0).toString()+" "+query.value(9).toString();;
                    } else {
                        tmpQuery.exec("select * from building_shahe limit "+QString::number(query.value(4).toInt()-1)+",1");
                        while(tmpQuery.next()) str += "\n沙河: "+tmpQuery.value(0).toString()+" "+query.value(9).toString();;
                    }
                    str += "\n"+query.value(5).toString()+"."+query.value(6).toString()+"."+query.value(7).toString()+" "+query.value(8).toString();

                    ui->textEdit_test->append(str);
                }
            }

            // 添加作业信息（学生）-- 在个人表中把符合的拉出来（number,isSelect）
            if(User_IsAdmin == 0) {
                query.exec("select * from "+QString::number(User_Number)+"_task");
                while(query.next()) {
                    if(query.value(1).toInt() == tmp->number && query.value(2).toInt() == tmp->isSelect) {
                        // 生成单个作业信息 _____________________________
                        QString str = query.value(0).toString()+" "+query.value(3).toString()+" ";
                        str += query.value(4).toString()+"-"+query.value(5).toString()+"-"+query.value(6).toString()+" "+query.value(7).toString();
                        // 已交作业
                        if(query.value(8).toInt() == 1) str += " (已提交)";
                        else str += " (未提交)";

                        // 分类 ________________________________________
                        if(isEnded(query.value(4).toInt(), query.value(5).toInt(), query.value(6).toInt(), query.value(7).toInt()))
                            ui->comboBox_task_1->addItem(str);
                        else
                            ui->comboBox_task_2->addItem(str);
                    }
                }
            }
            // 添加作业信息（老师）
            else {
                query.exec("select * from lesson_task");
                while(query.next()) {
                    if(query.value(1).toInt() == tmp->number && query.value(2).toInt() == tmp->isSelect) {
                        QString str = query.value(0).toString()+" "+query.value(3).toString()+" ";
                        str += query.value(4).toString()+"-"+query.value(5).toString()+"-"+query.value(6).toString()+" "+query.value(7).toString();
                        str += " "+query.value(9).toString()+"/"+query.value(8).toString();

                        // 分类 ________________________________________
                        if(isEnded(query.value(4).toInt(), query.value(5).toInt(), query.value(6).toInt(), query.value(7).toInt()))
                            ui->comboBox_task_1->addItem(str);
                        else
                            ui->comboBox_task_2->addItem(str);
                    }
                }
            }

            // 赋值filePath
            if(tmp->isSelect == 0) {
                filePath.setPath(HOME.absolutePath()+"/files/c/"+QString::number(tmp->number));
                if(!filePath.exists()) {
                    qDebug()<<"不存在该路径";
                    filePath.mkpath(HOME.absolutePath()+"/files/c/"+QString::number(tmp->number));
                    filePath.setPath(HOME.absolutePath()+"/files/c/"+QString::number(tmp->number));
                }
            } else {
                filePath.setPath(HOME.absolutePath()+"/files/s/"+QString::number(tmp->number));
                if(!filePath.exists()) {
                    qDebug()<<"不存在该路径";
                    filePath.mkpath(HOME.absolutePath()+"/files/s/"+QString::number(tmp->number));
                    filePath.setPath(HOME.absolutePath()+"/files/s/"+QString::number(tmp->number));
                }
            }
            qDebug() << filePath.absolutePath();
            zip->setFilepath(filePath.absolutePath());

            flag = 1;
        }
        tmp = tmp->nextptr;
    }

    if(flag == 0) {
        ui->label_location->setText("上课地点：");
        ui->label_qun->setText("群号：");
    }

    // 归初始状态
    ui->comboBox_task_1->setCurrentIndex(-1);
    ui->comboBox_task_2->setCurrentIndex(-1);
}



// 选修课选课 *****************************************************************************************************************
void Widget_Lesson::on_pushButton_findxuanxiu_clicked()
{
    // 清空并获取信息
    ui->comboBox_xuanxiu->clear();
    QByteArray input = ui->lineEdit_findxuanxiu->text().toUtf8();
    globalLog.writeLog(ui->lineEdit_findxuanxiu->text());

    // 输入为空，直接返回所有选修 ______________________________________________________________
    if(input.isEmpty()) {
        sizeXuanxiuSelect = 0;
        LessonPtr tmp = lessonXuanxiu;    // 获得所有课程的链表数据
        for(int i=0; i < sizeXuanxiu; i++) {
            lessonXuanxiuSelect[sizeXuanxiuSelect++] = tmp->nextptr;
            ui->comboBox_xuanxiu->addItem(tmp->nextptr->name+" "+QString::number(tmp->nextptr->dayOfWeek)+"-"+QString::number(tmp->nextptr->index));
            tmp = tmp->nextptr;
        }

        // 归初始状态
        ui->comboBox_xuanxiu->setCurrentIndex(-1);

        return;
    }

    // 建立筛选链表 ____________________________________________________________________________
    sizeXuanxiuSelect = 0;
    LessonPtr tmp = lessonXuanxiu;    // 获得所有课程的链表数据
    for(int i=0; i < sizeXuanxiu; i++) {
        // 先进行名字字段筛选
        QByteArray tmpName = tmp->nextptr->name.toUtf8();
        if(kmp(tmpName.data(),tmpName.size(),input.data(),input.size())) {
            lessonXuanxiuSelect[sizeXuanxiuSelect++] = tmp->nextptr;
            ui->comboBox_xuanxiu->addItem(tmp->nextptr->name+" "+QString::number(tmp->nextptr->dayOfWeek)+"-"+QString::number(tmp->nextptr->index));
            tmp = tmp->nextptr;
            continue;
        }
        // 按序号进行筛选
        QByteArray tmpNumber = QString::number(tmp->nextptr->number).toUtf8();
        if(kmp(tmpNumber.data(),tmpNumber.size(),input.data(),input.size())) {
            lessonXuanxiuSelect[sizeXuanxiuSelect++] = tmp->nextptr;
            ui->comboBox_xuanxiu->addItem(tmp->nextptr->name+" "+QString::number(tmp->nextptr->dayOfWeek)+"-"+QString::number(tmp->nextptr->index));
            tmp = tmp->nextptr;
            continue;
        }
        tmp = tmp->nextptr;
    }

    // 归初始状态
    ui->comboBox_xuanxiu->setCurrentIndex(-1);
}

// 添加选修课程 (学生功能)
void Widget_Lesson::on_pushButton_addxuanxiu_clicked()
{
    // 没选
    if(ui->comboBox_xuanxiu->currentIndex() == -1) {
        QMessageBox mess(QMessageBox::Information,"Error!","No lesson selected!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    // 获取对应选项
    int number = lessonXuanxiuSelect[ui->comboBox_xuanxiu->currentIndex()]->number;

    // 查找该课程信息
    query.exec("select * from lesson_select limit "+QString::number(number-1)+",1");
    Lesson obj;
    while(query.next()) {
        obj.number = query.value(0).toInt();
        obj.name = query.value(1).toString();
        obj.teacher = query.value(2).toInt();
        obj.isShaHe = query.value(3).toInt();
        obj.location = query.value(4).toInt();
        obj.dayOfWeek = query.value(5).toInt();
        obj.index = query.value(6).toInt();
        obj.qun = query.value(7).toString();
    }

    // 检查是否冲突 ________________________________________________________________________
    // 先找出学生班级
    QString userClass;
    query.exec("select * from people limit "+QString::number(User_Number-1)+",1");
    while(query.next())
        userClass = query.value(5).toString();

    int flag = 0;
    // 先找必修课 __________________________________________________
    query.exec("select * from lesson_compulsory");
    while(query.next()) {
        // 重复了
        if(query.value(9).toString() == userClass && query.value(5).toInt() == obj.dayOfWeek && query.value(6).toInt() == obj.index) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        QMessageBox mess(QMessageBox::Information,"Error!","和必修课有冲突!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }
    // 再找选修课 __________________________________________________
    query.exec("select * from "+QString::number(User_Number)+"_select");
    while(query.next()) {
        // 重复了
        if(query.value(5).toInt() == obj.dayOfWeek && query.value(6).toInt() == obj.index) {
            flag = 1;
            break;
        }
    }
    if(flag == 1) {
        QMessageBox mess(QMessageBox::Information,"Error!","和选修课有冲突!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }


    // 没问题，进行添加
    QString str= "insert into "+QString::number(User_Number)+"_select(number, name, teacher, isShaHe, location, dayOfWeek, c_index, qun) values("
                +QString::number(obj.number)+","
                +"'"+obj.name+"',"
                +QString::number(obj.teacher)+","
                +QString::number(obj.isShaHe)+","
                +QString::number(obj.location)+","
                +QString::number(obj.dayOfWeek)+","
                +QString::number(obj.index)+","
                +"'"+obj.qun+"')";
    qDebug() << str ;
    query.exec(str);

    // 日志 **************************************
    globalLog.writeLog("添加课程：\n"+str);

    // 把当前课程添加到课程链表，并更新size,formatIndex,lessonSelect
    LessonPtr tmp = lessons;
    for(int i=1; i < size; i++)
        tmp = tmp->nextptr;
    tmp->nextptr->nextptr = new Lesson;  // 找到末尾链表并进行空间申请
    tmp->nextptr->nextptr->number = obj.number;
    tmp->nextptr->nextptr->name = obj.name;
    tmp->nextptr->nextptr->teacher = obj.teacher;
    tmp->nextptr->nextptr->isShaHe = obj.isShaHe;
    tmp->nextptr->nextptr->location = obj.location;
    tmp->nextptr->nextptr->dayOfWeek = obj.dayOfWeek;
    tmp->nextptr->nextptr->index = obj.index;
    tmp->nextptr->nextptr->qun = obj.qun;
    size++;

    // 先把课程表内容删除一下
    for(int i=0; i < 28; i++)
        format[i]->setText("");
    // 重新排开课程表 （课程表信息），遍历课程信息链表，放入28个按钮中
    delete[] formatIndex;
    formatIndex = new int[size];
    tmp = lessons->nextptr;
    for(int i=0; i < size; i++) {
        this->format[4*(tmp->dayOfWeek-1)+(tmp->index-1)]->setText(tmp->name);  // 填入课程名称
        formatIndex[i] = 4*(tmp->dayOfWeek-1)+(tmp->index-1);   // 记录下标（0-27）
        tmp = tmp->nextptr;
    }

    showInformation();
    // 重新生成筛选指针数组（因为筛选规模更改）
    delete[] lessonSelect;
    lessonSelect = new LessonPtr[size];
    sizeSelect = 0; // 规定不能排序

    // 更新页面
    ui->comboBox_task_1->clear();
    ui->comboBox_task_2->clear();
    ui->label_location->setText("上课地点：");
    ui->label_qun->setText("群号：");
    ui->textEdit_test->clear();
    ui->textEdit_all->clear();

    QMessageBox mess(QMessageBox::Information,"Success!","Added to my lessons!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();
}


// 删除课程
void Widget_Lesson::on_pushButton_delete_clicked()
{
    int flag = 0;
    LessonPtr tmp = lessons;
    // 在链表中循环找，找到就显示，然后跳出（没找到那就遍历完了都没有显示）
    for(int i=0; !flag && i < size; i++) {
        // 找到了，进行删除
        if(formatIndex[i] == selectIndex) {
            // 压根就是必修不能删除
            if(tmp->nextptr->isSelect == 0) {
                QMessageBox mess(QMessageBox::Information,"Error!","必修课，不要学分啦？");
                mess.setWindowIcon(QIcon(":/images/02.jpg"));
                mess.exec();
                return;
            }
            // 这里是删除和课程相关的所有东西
            else {
                // 日志 **************************************
                globalLog.writeLog("删除课程：\n"+tmp->nextptr->name);

                // 删除我的选修课
                query.exec("delete from "+QString::number(User_Number)+"_select where number = "+QString::number(tmp->nextptr->number));
                // 删除链表
                LessonPtr obj = tmp->nextptr;
                tmp->nextptr = tmp->nextptr->nextptr;
                delete obj;
                obj = nullptr;
                size--;
            }
            flag = 1;
        }
        tmp = tmp->nextptr;
    }

    // 先把课程表内容删除一下
    for(int i=0; i < 28; i++)
        format[i]->setText("");
    // 重新排开课程表 （课程表信息），遍历课程信息链表，放入28个按钮中
    delete[] formatIndex;
    formatIndex = new int[size];
    tmp = lessons->nextptr;
    for(int i=0; i < size; i++) {
        this->format[4*(tmp->dayOfWeek-1)+(tmp->index-1)]->setText(tmp->name);  // 填入课程名称
        formatIndex[i] = 4*(tmp->dayOfWeek-1)+(tmp->index-1);   // 记录下标（0-27）
        tmp = tmp->nextptr;
    }

    showInformation();
    // 重新生成筛选指针数组（因为筛选规模更改）
    delete[] lessonSelect;
    lessonSelect = new LessonPtr[size];
    sizeSelect = 0; // 规定不能排序

    // 更新页面
    ui->comboBox_task_1->clear();
    ui->comboBox_task_2->clear();
    ui->label_location->setText("上课地点：");
    ui->label_qun->setText("群号：");
    ui->textEdit_test->clear();
    ui->textEdit_all->clear();

    QMessageBox mess(QMessageBox::Information,"Success!","delete from my lessons!");
    mess.setWindowIcon(QIcon(":/images/02.jpg"));
    mess.exec();
}



// 筛选课程信息 *****************************************************************************************************************
void Widget_Lesson::on_lineEdit_findAll_returnPressed()
{
    // 清空并获取信息
    ui->textEdit_all->clear();
    QByteArray input = ui->lineEdit_findAll->text().toUtf8();
    globalLog.writeLog(ui->lineEdit_findAll->text());

    sizeSelect = 0;
    // 假如输入为空，则直接弄成全部结果
    if(input.isEmpty()) {
        LessonPtr tmp = lessons;    // 获得所有课程的链表数据
        for(int i=0; i < size; i++) {
            lessonSelect[sizeSelect++] = tmp->nextptr;
            tmp = tmp->nextptr;
        }
    }
    else {
        // 根据词语筛选，建立链表
        LessonPtr tmp = lessons;    // 获得所有课程的链表数据
        for(int i=0; i < size; i++) {
            // 先进行名字字段筛选
            QByteArray tmpName = tmp->nextptr->name.toUtf8();
            if(kmp(tmpName.data(),tmpName.size(),input.data(),input.size())) {
                lessonSelect[sizeSelect++] = tmp->nextptr;
                tmp = tmp->nextptr;
                continue;
            }
            // 按序号进行筛选
            QByteArray tmpNumber = QString::number(tmp->nextptr->number).toUtf8();
            if(kmp(tmpNumber.data(),tmpNumber.size(),input.data(),input.size())) {
                lessonSelect[sizeSelect++] = tmp->nextptr;
                tmp = tmp->nextptr;
                continue;
            }
            tmp = tmp->nextptr;
        }
    }

    // 进行展示
    ui->textEdit_all->clear();
    for(int i=0; i < sizeSelect; i++) {
        QString str = lessonSelect[i]->name;
        str += " "+QString::number(lessonSelect[i]->dayOfWeek)+"-"+QString::number(lessonSelect[i]->index);
        query.exec("select * from people limit "+QString::number(lessonSelect[i]->teacher-1)+",1");
        while(query.next()) str += " "+query.value(4).toString();
        ui->textEdit_all->append(str);
    }
}

// 名称排序触发
void Widget_Lesson::on_pushButton_sortByName_clicked()
{
    if(sizeSelect == 0) {
        QMessageBox mess(QMessageBox::Information,"Error!","没有查询历史，无法筛选。请空白按下回车");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    } else
        this->quickSort_Name(lessonSelect, 0, sizeSelect-1);

    // 进行展示
    ui->textEdit_all->clear();
    for(int i=0; i < sizeSelect; i++) {
        QString str = lessonSelect[i]->name;
        str += " "+QString::number(lessonSelect[i]->dayOfWeek)+"-"+QString::number(lessonSelect[i]->index);
        query.exec("select * from people limit "+QString::number(lessonSelect[i]->teacher-1)+",1");
        while(query.next()) str += " "+query.value(4).toString();
        ui->textEdit_all->append(str);
    }
}

//
void Widget_Lesson::on_pushButton_sortByTime_clicked()
{
    if(sizeSelect == 0) {
        QMessageBox mess(QMessageBox::Information,"Error!","没有查询历史，无法筛选。请空白按下回车");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    } else
        this->quickSort_Time(lessonSelect, 0, sizeSelect-1);

    // 进行展示
    ui->textEdit_all->clear();
    for(int i=0; i < sizeSelect; i++) {
        QString str = lessonSelect[i]->name;
        str += " "+QString::number(lessonSelect[i]->dayOfWeek)+"-"+QString::number(lessonSelect[i]->index);
        query.exec("select * from people limit "+QString::number(lessonSelect[i]->teacher-1)+",1");
        while(query.next()) str += " "+query.value(4).toString();
        ui->textEdit_all->append(str);
    }
}


// 暂时用的是qstring比较
void Widget_Lesson::quickSort_Name(LessonPtr* array, int l, int r)
{
    if(l >= r) return;
    int i = l;  // 从左边界起始
    int j = r;  // 从右边界起始
    LessonPtr key = array[i]; // 最左边作为key
    while (i<j)
    {
        // 右边向左滑
        while( i < j && array[j]->name >= key->name )
            { j--; }
        array[i] = array[j];
        // 左边向右滑
        while( i < j && array[i]->name <= key->name )
            { i++; }
        array[j] = array[i];
    }
    array[i] = key; // i == j
    quickSort_Name(array,l,i-1);
    quickSort_Name(array,i+1,r);
}

void Widget_Lesson::quickSort_Time(LessonPtr* array, int l, int r)
{
    if(l >= r) return;
    int i = l;  // 从左边界起始
    int j = r;  // 从右边界起始
    LessonPtr key = array[i]; // 最左边作为key
    while (i<j)
    {
        while( i<j && (array[j]->dayOfWeek>key->dayOfWeek || (array[j]->dayOfWeek==key->dayOfWeek && array[j]->index>key->index)) )
            { j--; }
        array[i] = array[j];
        while( i<j && (array[i]->dayOfWeek<key->dayOfWeek || (array[i]->dayOfWeek==key->dayOfWeek && array[i]->index<key->index)) )
            { i++; }
        array[j] = array[i];
    }
    array[i] = key; // i == j
    quickSort_Time(array,l,i-1);
    quickSort_Time(array,i+1,r);
}



// 作业和资料 *****************************************************************************************************************
void Widget_Lesson::on_pushButton_send_clicked()
{
    zip->show();
}
void Widget_Lesson::on_pushButton_submit_clicked()
{
    if(ui->comboBox_task_2->currentIndex() == -1 || ui->comboBox_task_2->currentText().split(' ').at(4).contains("已")) {
        QMessageBox mess(QMessageBox::Information,"Error!","No task selected!");
        mess.setWindowIcon(QIcon(":/images/02.jpg"));
        mess.exec();
        return;
    }

    zip->show();

    // 先获取编号和以及作业名称
    int number = ui->comboBox_task_2->currentText().split(' ').at(0).toInt();
    QString name = QString::number(User_Number)+"_"+ui->comboBox_task_2->currentText().split(' ').at(1);
    zip->setFilename(name); // 给文件命名

    // 日志 **************************************
    globalLog.writeLog("提交作业："+name);

    // 直接更新个人作业状态
    query.exec("update "+QString::number(User_Number)+"_task set isCommit = 1 where number = "+QString::number(number));

    // 再更新作业总数状态
    query.exec("update lesson_task set commit_number = commit_number+1 where number = "+QString::number(number));

    // 更新信息展示
    showInformation();
}



// 页面跳转槽函数______________________________________________________________________________________________
// 开启添加课程界面
void Widget_Lesson::on_pushButton_add_clicked()
{
    adder = new Widget_LessonAdd;
    connect(adder, &Widget_LessonAdd::exit_return, [=](){
        delete adder;
        adder = nullptr;
        this->show();
    });
    adder->show();
    this->hide();
}

// 开启修改课程界面
void Widget_Lesson::on_pushButton_change_clicked()
{
    changer = new Widget_LessonChange;
    connect(changer, &Widget_LessonChange::exit_return, [=](){
        delete changer;
        changer = nullptr;
        this->show();
    });
    changer->show();
    this->hide();
}

// 开启布置作业界面
void Widget_Lesson::on_pushButton_task_clicked()
{
    task = new Widget_LessonTask;
    connect(task, &Widget_LessonTask::exit_return, [=](){
        delete task;
        task = nullptr;
        this->show();
    });
    task->show();
    this->hide();
}

// 开启考试界面
void Widget_Lesson::on_pushButton_test_clicked()
{
    test = new Widget_LessonTest;
    connect(test, &Widget_LessonTest::exit_return, [=](){
        delete test;
        test = nullptr;
        this->show();
    });
    test->show();
    this->hide();
}









void Widget_Lesson::setUI() {
    this->setFixedSize(1400, 800) ;
    this->setWindowTitle("Lesson") ;
    this->setWindowIcon(QIcon(":images/02.jpg")) ;
    this->setStyleSheet("background-color:rgb(255, 244, 225);");

    ui->pushButton_add->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_add->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_change->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_change->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_task->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_task->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_test->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_test->setStyleSheet("background: rgba(180,235,255,50%)") ;

    ui->pushButton_findxuanxiu->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_findxuanxiu->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_addxuanxiu->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_addxuanxiu->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_delete->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_delete->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_send->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_send->setStyleSheet("background: rgba(180,235,255,50%)") ;
    ui->pushButton_submit->setFont(QFont("Microsoft YaHei",12,75)) ;
    ui->pushButton_submit->setStyleSheet("background: rgba(180,235,255,50%)") ;

    ui->comboBox_task_1->setFont(QFont("Consolas",12,75)) ;
    ui->comboBox_task_1->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_task_2->setFont(QFont("Consolas",12,75)) ;
    ui->comboBox_task_2->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->lineEdit_findxuanxiu->setFont(QFont("Consolas",12,75)) ;
    ui->lineEdit_findxuanxiu->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->comboBox_xuanxiu->setFont(QFont("Consolas",12,75)) ;
    ui->comboBox_xuanxiu->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->textEdit_test->setFont(QFont("Consolas",15,75)) ;
    ui->textEdit_test->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->lineEdit_findAll->setFont(QFont("Consolas",12,75)) ;
    ui->lineEdit_findAll->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->textEdit_all->setFont(QFont("Consolas",15,75)) ;
    ui->textEdit_all->setStyleSheet("background: rgba(255,255,255,50%)") ;

    ui->label_1->setFont(QFont("Consolas",8,75)) ;
    ui->label_1->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_2->setFont(QFont("Consolas",8,75)) ;
    ui->label_2->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_3->setFont(QFont("Consolas",8,75)) ;
    ui->label_3->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_4->setFont(QFont("Consolas",8,75)) ;
    ui->label_4->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_5->setFont(QFont("Consolas",8,75)) ;
    ui->label_5->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_6->setFont(QFont("Consolas",8,75)) ;
    ui->label_6->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_7->setFont(QFont("Consolas",8,75)) ;
    ui->label_7->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_task_1->setFont(QFont("Consolas",8,75)) ;
    ui->label_task_1->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_task_2->setFont(QFont("Consolas",8,75)) ;
    ui->label_task_2->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_jindu->setFont(QFont("Consolas",12,75)) ;
    ui->label_jindu->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_location->setFont(QFont("Consolas",12,75)) ;
    ui->label_location->setStyleSheet("background: rgba(255,255,255,50%)") ;
    ui->label_qun->setFont(QFont("Consolas",12,75)) ;
    ui->label_qun->setStyleSheet("background: rgba(255,255,255,50%)") ;
}
