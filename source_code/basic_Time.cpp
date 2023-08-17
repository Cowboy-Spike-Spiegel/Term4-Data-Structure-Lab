#include "basic_Time.h"

//_____________________________________________________________________________
BigTime::BigTime(void) { obj = new int[3] ; }
BigTime::~BigTime(void) { delete[] obj ; }
int* BigTime::get(void) { return obj ; }
bool BigTime::create( int year, int month, int day )
{
    // obviously false
    if( year != 2022 || day < 1 )
        return false ;
    if( month < 1 || month > 12 )
        return false ;
    if( day < 1 || day > 31 )
        return false ;
    
    // month-day false
    if( day==31 && month!=1 && month!=3 && month!=5 && month!=7 && month!=8 && month!=10 && month!=12 )
        return false ;
    if( day==30 || day==29 )
        if( month != 2 )
            return false ;

    // evaluation
    obj[0] = year ;
    obj[1] = month ;
    obj[2] = day ;

    return true ;
}


//_____________________________________________________________________________
SmallTime::SmallTime(void) { obj = new int[3] ; }
SmallTime::~SmallTime(void) { delete[] obj ; }
int* SmallTime::get(void) { return obj ; }
bool SmallTime::create( int hour, int minute=0, int second=0 )
{
    // obviously false
    if( hour < 0 || hour > 23 )
        return false ;
    if( minute < 0 || minute > 59 )
        return false ;
    if( second < 0 || second > 59 )
        return false ;

    // evaluation
    obj[0] = hour ;
    obj[1] = minute ;
    obj[2] = second ;

    return true ;
}


//_____________________________________________________________________________
bool FullTime::create( int year, int month, int day, int hour, int minute=0, int second=0, int dayOfWeek=1, int week=1 )
{
    this->dayOfWeek = dayOfWeek;
    this->week = week;
    return
        bigTime.create(year, month, day)
        && smallTime.create(hour, minute, second) ;
}
void FullTime::create_BigTime( BigTime obj )    { bigTime = obj ; }
void FullTime::create_SmallTime( SmallTime obj )    { smallTime = obj ; }
void FullTime::create_DayOfWeek( int dayOfWeek ) { this->dayOfWeek = dayOfWeek ; }
void FullTime::create_week(int week)    { this->week = week; }
BigTime& FullTime::get_BigTime(void)    { return bigTime ; }
SmallTime& FullTime::get_SmallTime(void)    { return smallTime ; }
int& FullTime::get_DayOfWeek(void) { return dayOfWeek ; }
int& FullTime::get_Week(void)   { return week ; }
void FullTime::second_Pass() {
    smallTime.get()[2]+=10;
    if(smallTime.get()[2]>=60) {
        smallTime.get()[2]=0;
        minute_Pass();
    }
}
void FullTime::minute_Pass() {
    smallTime.get()[1]++;
    if(smallTime.get()[1]==60) {
        smallTime.get()[1]=0;
        hour_Pass();
    }
}
void FullTime::hour_Pass() {
    smallTime.get()[0]++;
    if(smallTime.get()[0]==24) {
        smallTime.get()[0]=0;
        day_Pass();
    }
}
void FullTime::day_Pass() {
    bigTime.get()[2]++;
    if(bigTime.get()[2]==32) {
        bigTime.get()[2]=1;
        month_Pass();
    }
    if(bigTime.get()[2]==31 &&
      (bigTime.get()[1]==4||bigTime.get()[1]==6||bigTime.get()[1]==9||bigTime.get()[1]==11) ) {
        bigTime.get()[1]=1;
        month_Pass();
    }
    if(bigTime.get()[1]==2) {
        if(bigTime.get()[2]==30 && (bigTime.get()[0]%4)==0) {
            bigTime.get()[2]=1;
            month_Pass();
        }
        if(bigTime.get()[2]==29 && (bigTime.get()[0]%4)!=0) {
            bigTime.get()[2]=1;
            month_Pass();
        }
    }
    if(dayOfWeek==7) {
        dayOfWeek = 1;
        week++;
    }
    else
        dayOfWeek++;
}
void FullTime::month_Pass() {
    bigTime.get()[1]++;
    if(bigTime.get()[1]==13) {
        bigTime.get()[1]=1;
        bigTime.get()[0]++;
    }
}


//_____________________________________________________________________________
BigTime& Duration_Aday::get_BigTime(void) { return bigTime ; }
SmallTime& Duration_Aday::get_StartSmallTime(void) { return start_SmallTime ; }
SmallTime& Duration_Aday::get_EndSmallTime(void) { return end_SmallTime ; }
void Duration_Aday::create_BigTime( BigTime obj )   { bigTime = obj ; }
void Duration_Aday::create_StartSmallTime( SmallTime obj )  { start_SmallTime = obj ; }
void Duration_Aday::create_EndSmallTime( SmallTime obj )    { end_SmallTime = obj ; }
bool Duration_Aday::create( int year, int month, int day,
    int s_hour, int e_hour, int s_minute=0, int e_minute=0, int s_second=0, int e_second=0 )
{
    if( bigTime.create( year, month, day )
        && start_SmallTime.create( s_hour, s_minute, s_second )
        && end_SmallTime.create( e_hour, e_minute, e_second ) )
        return true ;
    
    return false ;
}


//_____________________________________________________________________________
BigTime& Duration_Days::get_StartBigTime(void) { return start_BigTime ; }
BigTime& Duration_Days::get_EndBigTime(void) { return end_BigTime ; }
SmallTime& Duration_Days::get_StartSmallTime(void) { return start_SmallTime ; }
SmallTime& Duration_Days::get_EndSmallTime(void) { return end_SmallTime ; }
void Duration_Days::create_StartBigTime( BigTime obj )   { start_BigTime = obj ; }
void Duration_Days::create_EndBigTime( BigTime obj )   { end_BigTime = obj ; }
void Duration_Days::create_StartSmallTime( SmallTime obj )  { start_SmallTime = obj ; }
void Duration_Days::create_EndSmallTime( SmallTime obj )    { end_SmallTime = obj ; }
bool Duration_Days::create( int s_year, int e_year, int s_month, int e_month, int s_day, int e_day,
    int s_hour, int e_hour, int s_minute=0, int e_minute=0, int s_second=0, int e_second=0 )
{
    if( start_BigTime.create( s_year, s_month, s_day )
        && end_BigTime.create( e_year, e_month, e_day )
        && start_SmallTime.create( s_hour, s_minute, s_second )
        && end_SmallTime.create( e_hour, e_minute, e_second ) )
        return true ;
    
    return false ;
}
