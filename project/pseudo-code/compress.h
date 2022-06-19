#ifndef COMPRESS
#define COMPRESS
#include<stdio.h>

#define N 2
//N是设定的对于一个seed，找到几个完全匹配时决定压缩的阈值。
#define M 100
//M是一段DNA中任意seed最多可以出现几次，应该要接近LONG/seed长度n
#define LONG 1000
//LONG是数据DNA的最大长度

Function compression(m,n,o1,o2,o4);
#endif
