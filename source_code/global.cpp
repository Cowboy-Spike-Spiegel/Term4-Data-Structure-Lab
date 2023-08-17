#include "global.h"

FullTime system_Time;
LARGE_INTEGER cpuFreq;
LARGE_INTEGER starter;
LARGE_INTEGER ender;

// time speed
double v;

bool handle;

QSqlDatabase db;
QDir HOME;

int User_Number;
QString User_Account;
int User_IsAdmin;

Log globalLog;


// functions
bool isEnded(int year, int month, int day, int hour) {
    int tmpY = system_Time.get_BigTime().get()[0];
    int tmpM = system_Time.get_BigTime().get()[1];
    int tmpD = system_Time.get_BigTime().get()[2];
    int tmpH = system_Time.get_SmallTime().get()[0];

    // 逐级判断
    if(year < tmpY)
        return true;
    else if(year > tmpY)
        return false;
    else {
        if(month < tmpM)
            return true;
        else if(month > tmpM)
            return false;
        else {
            if(day < tmpD)
                return true;
            else if(day > tmpD)
                return false;
            else {
                if(hour <= tmpH)
                    return true;
                else
                    return false;
            }
        }
    }
}

bool isBefore(int y1, int m1, int d1, int h1, int y2, int m2, int d2, int h2) {
    // 逐级判断
    if(y1 < y2)
        return true;
    else if(y1 > y2)
        return false;
    else {
        if(m1 < m2)
            return true;
        else if(m1 > m2)
            return false;
        else {
            if(d1 < d2)
                return true;
            else if(d1 > d2)
                return false;
            else {
                if(h1 <= h2)
                    return true;
                else
                    return false;
            }
        }
    }
}
