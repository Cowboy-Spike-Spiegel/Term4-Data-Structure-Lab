#include "kmp.h"

int kmp(char* t, int len1, char* p, int len2)
{
    int i, j;
    int next[50];
    i = 0;//指向字符串每个字符的下标
    j = -1;
    next[i] = j;//next[0]放上-1
    while (i < len2)
    {//没有到达结尾的话
        if (j == -1 || p[i] == p[j])
        {//如果是第一个字符或遇到相同的字符
            next[++i] = ++j;
        }
        else {
            j = next[j];
        }
    }
    int m, n;
    m = n = 0;
    while (m < len1 && n < len2)
    {
        if (n == -1 || t[m] == p[n])
        {
            m++;n++;
        }
        else {
            n = next[n];
        }
    }
    if (n == len2)
    {
        return 1;//匹配
    }
    else
    {
        return 0;//不匹配
    }
}
