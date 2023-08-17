#ifndef LOG_H
#define LOG_H

#include <QString>

class Log
{
public:
    Log();
    void create();  // 创建初始化（需要先初始化HOME）
    void writeLog(QString str);

    // 每次进页面保存状态
    void maintainState(QString page);
    // 正常退出时移除状态记录
    void removeState();

    // 信息跳转
    int getUserNumber() {return number;}
    void deletePage() {page = "";}
    QString getPage() {return page;}

private:
    // 从保留状态文件里取出来的东西
    int number;
    QString page;   // 看打开来的是什么界面
};

#endif // LOG_H
