#include "MyString.h"

// QString transfer to String *****************************
void String::copy(QString Qstr)
{
    if(obj != NULL)
        delete[] obj;

    // allocate
    len = Qstr.length();
    obj = new char[this->len+1];

    // transfer QString to char*
    QByteArray ba = Qstr.toLatin1();
    char* ch = ba.data();
    for(int i=0; i < Qstr.length(); i++)
        obj[i] = ch[i];
    obj[len] = 0;
}

// construct and destruct *********************************
 String::String( const char* str )//通用构造
{
    if (!str)
    {
        len = 0 ;
        obj = new char[1] ;
        *obj = '\0' ;
    }
    else
    {
        len = strlen(str) ;
        obj = new char[len + 1] ;
        for( int i=0 ; i < len ; i++ )
            obj[i] = str[i] ;
        obj[len] = 0 ;
    }
}

String::String( const String &str ) //拷贝构造，深拷贝
{
    len = str.size() ;
    obj = new char[len + 1] ;
    for( int i=0 ; i < len ; i++ )
        obj[i] = str[i] ;
    obj[len] = 0 ;
}

String::~String()
{
    delete[] obj ;
    len = 0 ;
}

// operators **********************************************
String& String::operator=(const String &str)
{
    if (this == &str) return *this; //自我赋值

    delete[] obj ;

    len = str.size() ;
    obj = new char[len + 1];
    for( int i=0 ; i < len ; i++ )
        obj[i] = str[i] ;
    obj[len] = 0 ;

    return *this ;
}

String String::operator+( const String &str ) const
{
    String newString ;
    int tmp = len ;
    newString.len = len + str.size() ;
    newString.obj = new char[newString.len + 1];

    int i=0 ;
    for( ; i < tmp ; i++ )
        newString.obj[i] = obj[i] ;
    for( ; i-tmp < str.len ; i++ )
        newString.obj[i] = str[i] ;
    newString.obj[i] = 0 ;

    return newString ;
}

String& String::operator+=( const String &str )
{
    len += str.size() ;
    char *newdata = new char[len + 1] ;
    strcpy( newdata , obj ) ;
    strcat( newdata , str.c_str() ) ;
    delete[] obj ;
    obj = newdata ;

    return *this ;
}

char& String::operator[]( int n ) const
{
    if( len == 0 )  return obj[0] ;
    if( n < 0 ) return obj[0] ;
    if( n >= len )  return obj[len - 1] ;
    return obj[n] ;
}

bool String::operator==( const String &str ) const
{
    if ( len != str.size() )
        return false ;
    return strcmp ( obj , str.c_str() ) ? false : true ;
}

int String::size() const
{
    return len ;
}

const char *String::c_str() const
{
    return obj ;
}

std::istream& operator>>( std::istream &is , String &str )
{
    char *temp = new char[1000] ;
    is >> temp ;
    str.len = strlen(temp) ;
    str.obj = new char[str.len + 1] ;
    strcpy( str.obj , temp ) ;
    return is ;
}

std::ostream& operator<<( std::ostream &os , const String &str )
{
    os << str.obj ;
    return os ;
}
