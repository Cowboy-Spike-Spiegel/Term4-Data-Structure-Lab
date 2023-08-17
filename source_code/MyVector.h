#ifndef _MY_VECTOR
#define _MY_VECTOR

#include<string.h>
#include<iostream>

class Vector_int
{
private:
    int* obj ;
    int len ;
    int capacity ;
public:
    Vector_int(void) ;
    ~Vector_int(void) ;

    int size(void) ;
    void push( int arg ) ;
    int pop(void) ;
    void clear(void) ;
    void copy(Vector_int& vec);

    int& operator[]( int n ) const ;
} ;

class Vector_double
{
private:
    double* obj ;
    int len ;
    int capacity ;
public:
    Vector_double(void) ;
    ~Vector_double(void) ;

    int size(void) ;
    void push( double arg ) ;
    double pop(void) ;
    void clear(void) ;
    
    double& operator[]( int n ) const ;
} ;


#endif
