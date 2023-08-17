#include "log.h"

#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QDebug>
#include "global.h"

Log::Log()
{}

// 创建属性，并检测曾经状态 ____________________________________________________
void Log::create()
{
    QDir tempDir(HOME.absolutePath()+"/Logs");
    if(!tempDir.exists()) {
        qDebug()<<"不存在该路径";
        tempDir.mkpath(HOME.absolutePath()+"/Logs");
    }

    QFile tempFile(tempDir.absolutePath()+"/state.log");
    // 能够成功打开
    if(tempFile.open(QIODevice::ReadOnly)) {
        // 录入数据
        QByteArray array = tempFile.readAll();
        QByteArrayList list = array.split(' ');

        number = list.at(0).toInt();
        // 没有后续数据了
        if(list.size() == 1)
            page = "";
        else
            page = list.at(1);
    }
    // 没有文件，说明正常退出
    else {
        qDebug()<<"state File ERROR!";
        number = 0;
        page = "";
    }
    tempFile.close();
}

// 每次进入页面保存状态 _________________________________________________________
void Log::maintainState(QString str)
{
    QDir tempDir(HOME.absolutePath()+"/Logs");
    if(!tempDir.exists()) {
        qDebug()<<"不存在该路径";
        tempDir.mkpath(HOME.absolutePath()+"/Logs");
    }

    // 直接以只写方式打开文件，把状态写进去
    QFile tempFile(tempDir.absolutePath()+"/state.log");
    tempFile.open(QIODevice::WriteOnly);
    tempFile.write(str.toUtf8());
    tempFile.close();
}

// 移除状态文件 _________________________________________________________________
void Log::removeState()
{
    QDir tempDir(HOME.absolutePath()+"/Logs");
    if(!tempDir.exists()) {
        qDebug()<<"不存在该路径";
        tempDir.mkpath(HOME.absolutePath()+"/Logs");
    }
    QFile tempFile(tempDir.absolutePath()+"/state.log");
    tempFile.remove();
}

// 写日志 _______________________________________________________________________
void Log::writeLog(QString str)
{
    QDir tempDir(HOME.absolutePath()+"/Logs");
    if(!tempDir.exists()) {
        qDebug()<<"不存在该路径";
        tempDir.mkpath(HOME.absolutePath()+"/Logs");
    }
    QFile tempFile(tempDir.absolutePath()+"/user.log");
    if(tempFile.open(QIODevice::ReadWrite | QIODevice::Append)) {
        QTextStream txtOutput(&tempFile);

        // 先生成时间
        QString curTime = QString::number(system_Time.get_BigTime().get()[0])
                + "-" + QString::number(system_Time.get_BigTime().get()[1])
                + "-" + QString::number(system_Time.get_BigTime().get()[2])
                + "-" + QString::number(system_Time.get_SmallTime().get()[0])
                + "-" + QString::number(system_Time.get_SmallTime().get()[1])
                + "-" + QString::number(system_Time.get_SmallTime().get()[2]);

        txtOutput.setCodec(QTextCodec::codecForName("utf-8"));
        txtOutput << curTime << "    User: " << QString::number(User_Number) << "    content: " << str << "\n";
    }
    // 没有文件，说明正常退出，无需操作
    else {
        qDebug()<< "log: File ERROR!";
    }
    tempFile.close();
}
