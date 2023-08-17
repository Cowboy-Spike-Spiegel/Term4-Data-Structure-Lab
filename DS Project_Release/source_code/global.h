#ifndef GLOBAL_H
#define GLOBAL_H

#include <windows.h>
#include <ctime>
#include <thread>
#include <QDir>
#include <QSqlDatabase>
#include "basic_Time.h"
#include "log.h"

extern FullTime system_Time;
extern LARGE_INTEGER cpuFreq;
extern LARGE_INTEGER starter;
extern LARGE_INTEGER ender;
extern double v;

extern bool handle;

extern QSqlDatabase db;
extern QDir HOME;

extern int User_Number;
extern QString User_Account;
extern int User_IsAdmin;

extern Log globalLog;


bool isEnded(int year, int month, int day, int hour);
bool isBefore(int y1, int m1, int d1, int h1, int y2, int m2, int d2, int h2);

#endif // GLOBAL_H
