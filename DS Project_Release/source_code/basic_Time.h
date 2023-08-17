 #ifndef _BASIC_TIME
#define _BASIC_TIME

#include "MyString.h"

// 时间点：年月日 
class BigTime
{
private:
    int* obj ;

public:
    BigTime(void) ;
    ~BigTime(void) ;
    int* get(void) ;
    bool create( int year, int month, int day ) ;
} ;


// 时间点：时分秒
class SmallTime
{
private:
    int* obj ;

public:
    SmallTime(void) ;
    ~SmallTime(void) ;
    int* get(void) ;
    bool create( int hour, int minute, int second ) ;
} ;


// 时间点：完整时间
class FullTime
{
private:
    BigTime bigTime ;
    SmallTime smallTime ;
    int dayOfWeek;
    int week;

public:
    bool create( int year, int month, int day, int hour, int minute, int second , int dayOfWeek, int week ) ;
    void create_BigTime( BigTime obj ) ;
    void create_SmallTime( SmallTime obj ) ;
    void create_DayOfWeek( int dayOfWeek ) ;
    void create_week(int week);
    BigTime& get_BigTime(void) ;
    SmallTime& get_SmallTime(void) ;
    int& get_DayOfWeek(void) ;
    int& get_Week(void);
    void second_Pass() ;
    void minute_Pass() ;
    void hour_Pass();
    void day_Pass();
    void month_Pass();
} ;


// 时间跨度（当日内）
class Duration_Aday
{
private:
    BigTime bigTime ;
    SmallTime start_SmallTime ;
    SmallTime end_SmallTime ;

public:
    BigTime& get_BigTime(void) ;
    SmallTime& get_StartSmallTime(void) ;
    SmallTime& get_EndSmallTime(void) ;
    void create_BigTime( BigTime obj ) ;
    void create_StartSmallTime( SmallTime obj ) ;
    void create_EndSmallTime( SmallTime obj ) ;
    virtual bool create ( int year, int month, int day,
        int s_hour, int e_hour, int s_minute, int e_minute, int s_second, int e_second ) ;
} ;


// 时间跨度（多日内）
class Duration_Days
{
private:
    BigTime start_BigTime ;
    BigTime end_BigTime ;
    SmallTime start_SmallTime ;
    SmallTime end_SmallTime ;

public:
    BigTime& get_StartBigTime(void) ;
    BigTime& get_EndBigTime(void) ;
    SmallTime& get_StartSmallTime(void) ;
    SmallTime& get_EndSmallTime(void) ;
    void create_StartBigTime( BigTime obj ) ;
    void create_EndBigTime( BigTime obj ) ;
    void create_StartSmallTime( SmallTime obj ) ;
    void create_EndSmallTime( SmallTime obj ) ;
    virtual bool create ( int s_year, int e_year, int s_month, int e_month, int s_day, int e_day,
        int s_hour, int e_hour, int s_minute, int e_minute, int s_second, int e_second ) ;
} ;


// 闹钟 
class Clock : public FullTime
{
private:
    String owner ;
public:
    void alarm(void) ;
} ;


#endif
