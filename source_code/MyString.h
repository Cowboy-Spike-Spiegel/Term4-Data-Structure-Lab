#ifndef _STRING_H
#define _STRING_H

#include <iostream>
#include <string>
#include <string.h>

#include <QString>

// class String *******************************************
class String
{
private:
    int len ;
    char *obj ;

public:
    String  ( const char* str = NULL ) ;
    String  ( const String &str ) ;
    ~String () ;

    String& operator=( const String &str ) ;
    String  operator+( const String &str ) const ;
    String& operator+=( const String &str ) ;
    char&   operator[]( int n ) const ;
    bool    operator==( const String &str ) const ;

    friend std::istream& operator>>( std::istream& is , String& s ) ;
    friend std::ostream& operator<<( std::ostream& os , const String& s ) ;
    
    int size() const ; //字符串实际大小，不包括结束符
    const char *c_str() const ; //将string转为char *

    // QString transfer to String
    void copy(QString Qstr) ;
} ;

#endif
