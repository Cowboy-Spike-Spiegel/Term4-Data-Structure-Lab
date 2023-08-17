#include "MyVector.h"

Vector_int::Vector_int(void)
{
    obj = new int[5] ;
    len = 0 ;
    capacity = 5 ;
}
Vector_int::~Vector_int(void) { delete[] obj ; }

int Vector_int::size(void) { return len ; }
void Vector_int::push( int arg )
{
    if( len == capacity ) {
        capacity += 5 ;
        int* temp = new int[capacity] ;
        memcpy( temp , obj , sizeof(int)*(capacity) ) ;
        delete[] obj ;
        obj = temp ;
    }

    obj[len++] = arg ;
}
int Vector_int::pop(void)
{
    if( len > 1 )
        return obj[--len] ;
    return -1 ;
}
void Vector_int::copy(Vector_int& vec)
{
    delete[] obj;
    len = vec.size();
    capacity = len;
    obj = new int[len];
    for(int i=0; i < len; i++)
        obj[i] = vec[i];
}
void Vector_int::clear(void)
{
    delete[] obj ;
    obj = new int[5] ;
    len = 0 ;
    capacity = 5 ;
}

int& Vector_int::operator[]( int n ) const
{
    if( len == 0 )  return obj[0] ;
    if( n < 0 ) return obj[0] ;
    if( n >= len )  return obj[len - 1] ;
    return obj[n] ;
}



Vector_double::Vector_double(void)
{
    obj = new double[5] ;
    len = 0 ;
    capacity = 5 ;
}
Vector_double::~Vector_double(void) { delete[] obj ; }

int Vector_double::size(void) { return len ; }
void Vector_double::push( double arg )
{
    if( len == capacity ) {
        capacity += 5 ;
        double* temp = new double[capacity] ;
        memcpy( temp , obj , sizeof(double)*capacity ) ;
        delete[] obj ;
        obj = temp ;
    }

    obj[len++] = arg ;
}
double Vector_double::pop(void)
{
    if( len > 1 )
        return obj[--len] ;
    return -1 ;
}
void Vector_double::clear(void)
{
    delete[] obj ;
    obj = new double[5] ;
    len = 0 ;
    capacity = 5 ;
}

double& Vector_double::operator[]( int n ) const
{
    if( len == 0 )  return obj[0] ;
    if( n < 0 ) return obj[0] ;
    if( n >= len )  return obj[len - 1] ;
    return obj[n] ;
}
