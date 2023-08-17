#ifndef _MAPSTACK
#define _MAPSTACK


typedef struct point
{
    int     number;
    int     index_former;
    int     subNum_1;
    int     subNum_2;
    int     subNum_3;
    int     subNum_4;
    double  data;
} Point, *PointPtr ;


// 每一组10个Point,并且用struct封装一组后进行链表的表示
typedef struct pointptrList {
    PointPtr thisArray; // 当前STRUCT的10个一组
    int size;           // 当前数量
    struct pointptrList* nextPtr;
} PointPtrList, *PointPtrListPtr;



class MapStack
{
private:
    PointPtrListPtr obj ;
    PointPtrListPtr cur ;
    int len ;
public:
    void create(int number, int subNum_1, int subNum_2, int subNum_3, int subNum_4) ;
    void burden();
    int size(void) ;
    void push(int number, int index_former, int subNum_1, int subNum_2, int subNum_3, int subNum_4, double data) ;
    Point& operator[]( int n ) const ;
} ;


#endif
