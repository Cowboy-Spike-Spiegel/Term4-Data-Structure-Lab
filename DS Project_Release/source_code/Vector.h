/*vector是可变大小的数组，是顺序存储结构，支持快速的随机访问，在尾部之外的位置插入和删除元素很慢*/
#ifndef VECTOR_H
#define VECTOR_H
#include<cassert>
#include<iostream>
using namespace std;
template<typename T>
class Vector
{
public:
   enum{ SPARE_CAPACITY = 5 };
   typedef T* iterator;
   typedef const T* const_iterator;
    
   //构造函数
   explicit Vector(int initsize = 0); //explicit是为了防止让一个实参的构造函数发生隐式转换
   Vector(int initsize, T value);
   Vector(iterator b, iterator e);   //接受两个迭代器创建拷贝的构造函数 ,这里的迭代器的创建是指针，见上面
   Vector(std::initializer_list<T> l);

   Vector(const Vector &rhs);
   Vector<T>& operator=(const Vector & rhs);
   ~Vector() { delete[] elem;}


   //常量成员函数，不改变类的成员,this指针为指向常量的常量指针，因为常量对象不能调用非常量数据成员，而非常量对象都可以调用
    bool empty()const  { return thesize == 0;}
    int size() const   {return thesize;}
    int capacity() const { return thecapacity; }
    iterator begin()  {return &elem[0];}
    iterator end()  {return &elem[thesize];}   
    const_iterator cbegin()const {return &elem[0];}   
    const_iterator cend() const {return &elem[thesize];}
    
    bool operator==(const Vector<T>& rhs);                                                              
    bool operator!=(const Vector<T>& rhs);

    
    void reserve(int newcapacity);
    void resize(int newsize, const T &thevalue);
    void resize(int newsize);
    void shrink_to_fit();

    T &operator[](int index);                                   
    const T &operator[](int index) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    void push_back(const T &x);
    iterator insert(iterator b, const T &value);
    void pop_back() {thesize--;}
    iterator erase(iterator b);
    void clear();

private:
    T *elem;
    int thesize;
    int thecapacity;
};

/******************************************构造函数******************************************/
template <typename T>
Vector<T>::Vector(int initsize = 0) :thesize(initsize), thecapacity(initsize + SPARE_CAPACITY)
{
    elem = new T[thecapacity];
    assert(elem != NULL);    //存储分配失败则退出;
}
template<typename T>
Vector<T>::Vector(std::initializer_list<T> l)     //列表初始化,新标准
{
    thesize = l.size();
    thecapacity = thesize + SPARE_CAPACITY;
    elem = new T[thecapacity];
    assert(elem != NULL);
    int i = 0;
    auto beg = l.begin();
    while (beg != l.end() && i != thesize)
    {
        elem[i] = *beg;
        ++i;
        ++beg;
    }
}
template <typename T>
Vector<T>::Vector(int initsize, T value) :thesize(initsize), thecapacity(initsize + SPARE_CAPACITY)
{
    elem = new T[thecapacity];
    assert(elem != NULL);    //存储分配失败则退出;
    for (int i = 0; i != thesize; ++i)
        elem[i] = value;
}
template <typename T>
Vector<T>::Vector(iterator b, iterator e)
{
    thesize = e - b;
    thecapacity = thesize + SPARE_CAPACITY;
    elem = new T[thecapacity];
    assert(elem != NULL);
    for (int i = 0; b != e&&i != thesize; ++i)
    {
        elem[i] = *b;
        ++b;
    }
}

//拷贝构造函数，接受一个容器为另一个容器的拷贝（深拷贝）
template <typename T>
Vector<T>::Vector(const Vector &rhs)
{
    thesize = rhs.thesize;
    thecapacity = rhs.thecapacity;
    elem = new T[thecapacity];
    assert(elem != NULL);
    for (int i = 0; i != thesize; ++i)
        elem[i] = rhs.elem[i];
}

//赋值运算符
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector &rhs)
{
    if (this != &rhs) //防止自赋值
    {
        delete[]elem;
        thesize = rhs.thesize;
        thecapacity = rhs.thecapacity;
        elem = new T[thecapacity];
        assert(elem != NULL);
        for (int i = 0; i != thesize; ++i)
            elem[i] = rhs.elem[i];
    }
    return *this;
}

//swap函数的实现，通常比从一个向另一个容器拷贝元素快，只是交换了两个容器内部的数据结构，元素本身没有交换。。
//交换的是相同类型的容器。

//assign，赋值函数的实现

/********************************************关系运算符**********************************/
//关系运算符的实现==，！=，> ,>=, <, <=
template<typename T>
bool Vector<T>::operator==(const Vector<T>& rhs)
{
    if (this->thesize == rhs.thesize)     //与容量没有关系
    {
        int cnt = 0;
        for (int i = 0; i != thesize; i++)
            if (this->elem[i] == rhs.elem[i])
                ++cnt;
        if (cnt == thesize)
            return true;
    }
    return false;
}
template<typename T>
bool Vector<T>::operator!=(const Vector<T>& rhs)
{
    return !(*this == rhs);
}

//分配至少容纳newcapacity个的元素空间
template<typename T>
void Vector<T>::reserve(int newcapacity)
{
    if (newcapacity <= thecapacity)
    {
        if (newcapacity < thecapacity / 2)   //当新的容量很小时
        {
            T *newarray = new T[newcapacity];
            int newsize = newcapacity > thesize ? thesize : newcapacity;
            for (int i = 0; i != newsize; ++i)
                newarray[i] = elem[i];
            delete[] elem;
            elem = newarray;
            thecapacity = newcapacity;
        }
        return;
    }
    T *newarray = new T[newcapacity];
    for (int i = 0; i != thesize; ++i)
        newarray[i] = elem[i];
    delete[] elem;
    elem = newarray;
    thecapacity = newcapacity;
}

//调整它的大小，若newsize<thesize，多的元素被丢弃，若相反，添加新元素，新添进来的元素初始化为thevalue
template<typename T>
void Vector<T>::resize(int newsize, const T & thevalue)
{
    if (newsize > thesize)
    {
        if (newsize > thecapacity)
            reserve(newsize * 2 + 1);
        for (int i = thesize; i != newsize; ++i) //新添进来的元素初始化为thevalue
            elem[i] = thevalue;
    }
    else if (newsize< thesize)
    {
        if (newsize<thecapacity / 2)
            reserve(newsize);
    }
    thesize = newsize;
}
template<typename T>
void Vector<T>::resize(int newsize)    //调整它的大小，若newsize<thesize，多的元素被丢弃，若相反，添加新元素，进行值初始化
{
    resize(newsize, T());
}
template<typename T>
void Vector<T>::shrink_to_fit()        //将capacity（）减少为与size（）相同大小
{
    reserve(thesize + SPARE_CAPACITY);
}
/**************************************访问操作***************************************/
template<typename T>
T & Vector<T>::operator[](int index)
{
    if (index < 0 || index >= thesize)
    {
        cout << "下标超出范围" << endl;
        return;
    }
    return elem[index];
}
template<typename T>
const T &Vector<T>::operator[](int index) const    //返回下标不能修改
{
    if (index < 0 || index >= thesize)
    {
        cout << "下标超出范围" << endl;
        return;
    }
    return elem[index];
}
template<typename T>
T& Vector<T>::front()
{
    if (!this->empty())
        return elem[0];
}
template<typename T>
const T& Vector<T>::front() const
{
    if (!this->empty())
        return elem[0];
}
template<typename T>
T& Vector<T>::back()
{
    if (!this->empty())
        return elem[thesize - 1];
}
template<typename T>
const T& Vector<T>::back() const
{
    if (!this->empty())
        return elem[thesize - 1];
}
/******************************************插入操作*************************************/
//向容器插入元素，vector不支持push_front,但insert可以实现插入vector的任何位置，但是注意在vector除尾部之外的任何位置很慢，很耗时。。
template<typename T>
void Vector<T>::push_back(const T &x)
{
    if (thesize == thecapacity)
        reserve(2 * thecapacity);
    elem[thesize++] = x;
}
template<typename T>
T* Vector<T>::insert(iterator b, const T &value)    //返回类型为Vector<T>::iterator则出错？？
{
    if (b < this->begin() || b> this->end())  //b可以为尾后迭代器
    {
        cout << "超出范围" << endl;
        exit(0);
    }
    int num = b - elem;
    if (thesize == thecapacity)
    {
        reserve(thesize * 2);
        b = elem + num;                         //重新分配内存后原来的指针b失效了，所以此处令b指向新分配的数组中
    }
    for (iterator p = this->end(); p > b; p--)
        *p = *(p - 1);
    *b = value;
    thesize++;
    return b;
}
//删除操作
template<typename T>
T* Vector<T>::erase(iterator b)
{
    if (b < this->begin() || b >= this->end())  //确保迭代器在范围内，否则未定义，b不能为尾后迭代器
    {
        cout << "超出范围" << endl;
        exit(0);
    }
    iterator q = b + 1;
    int num = q - elem; 
    iterator p = this->end() - 1;
    for (; b < p; b++)
        *b = *(b + 1);
    thesize--;
    if (thesize <= thecapacity / 4)     //防止删除后空闲空间太大，浪费空间
    {
        reserve(thesize + SPARE_CAPACITY);
        iterator q1 = elem + num;          //重新进行内存分配后原来的指针q可能失效了
        return q1;
    }    
    return q;
}
template<typename T>
void Vector<T>::clear()
{
    thesize = 0;
}
#endif