#include "mapStack.h"

void MapStack::create(int number, int subNum_1, int subNum_2, int subNum_3, int subNum_4) {
    obj = new PointPtrList;
    cur = obj;

    cur->thisArray = new Point[10];
    cur->thisArray[0].number = number;
    cur->thisArray[0].index_former = -1;
    cur->thisArray[0].subNum_1 = subNum_1;
    cur->thisArray[0].subNum_2 = subNum_2;
    cur->thisArray[0].subNum_3 = subNum_3;
    cur->thisArray[0].subNum_4 = subNum_4;
    cur->thisArray[0].data = 0;
    cur->nextPtr = nullptr;
    cur->size = 1;
    
    len = 1;
}

void MapStack::burden() {
    cur = obj;
    PointPtrListPtr tmp;
    while( cur->nextPtr != nullptr ) {
        tmp = cur->nextPtr;
        delete[] cur->thisArray;
        cur->thisArray = nullptr;
        delete cur;
        cur = nullptr;
        cur = tmp;
    }
    delete[] cur->thisArray;
    cur->thisArray = nullptr;
    delete cur;
    cur = nullptr;

    len = 0;
    obj = nullptr;
}

int MapStack::size() { return len; }
Point& MapStack::operator[]( int n ) const {
    int line = n/10;
    PointPtrListPtr tmp = obj;
    for(int i=0; i < line; i++ )
        tmp = tmp->nextPtr;
    return tmp->thisArray[n%10];
}

void MapStack::push(int number, int index_former, int subNum_1, int subNum_2, int subNum_3, int subNum_4, double data)
{
    if(cur->size < 10) {
        cur->thisArray[cur->size].number = number;
        cur->thisArray[cur->size].index_former = index_former;
        cur->thisArray[cur->size].subNum_1 = subNum_1;
        cur->thisArray[cur->size].subNum_2 = subNum_2;
        cur->thisArray[cur->size].subNum_3 = subNum_3;
        cur->thisArray[cur->size].subNum_4 = subNum_4;
        cur->thisArray[cur->size].data = data;
        cur->size++;
    }
    else {
        // allocate new memory for new 10 Points
        cur->nextPtr = new PointPtrList;
        cur = cur->nextPtr;
        cur->thisArray = new Point[10];

        cur->thisArray[0].number = number;
        cur->thisArray[0].index_former = index_former;
        cur->thisArray[0].subNum_1 = subNum_1;
        cur->thisArray[0].subNum_2 = subNum_2;
        cur->thisArray[0].subNum_3 = subNum_3;
        cur->thisArray[0].subNum_4 = subNum_4;
        cur->thisArray[0].data = data;
        cur->nextPtr = nullptr;
        cur->size = 1;
    }

    len++;
}
