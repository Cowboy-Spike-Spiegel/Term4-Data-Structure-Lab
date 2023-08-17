#include "Mythread.h"
#include <windows.h>
#include <QDebug>
#include "global.h"

MyThread::MyThread(QObject *parent)
    : QThread(parent)
{}

void MyThread::run() {
    v = 1;
    handle=true;
    QueryPerformanceFrequency(&cpuFreq);
    QueryPerformanceCounter(&starter);
    int preHour = system_Time.get_SmallTime().get()[0];
    int hour;
    while(handle) {
        QueryPerformanceCounter(&ender);
        if( (ender.QuadPart-starter.QuadPart)*v >= 277777.78 ) {
            system_Time.second_Pass();
            emit refresh();
            QueryPerformanceCounter(&starter);
        }
        hour = system_Time.get_SmallTime().get()[0];
        if(hour != preHour) {
            preHour = hour;
            emit hourPass();
        }
    }
}
