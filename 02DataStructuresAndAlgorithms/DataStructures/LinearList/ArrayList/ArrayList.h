/*************************************************************************
> File Name       : ArrayList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月17日  18时43分54秒
************************************************************************/
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "./LinearList.h"

template <typename T>
class ArrayList : public LinearList<T>
{
private:
    T *element;   // 存储线性表的一维数组
    int capacity; // 数组容量
    int size;     // 数组包含的元素个数

    void check_index(int theIndex) const; // 数组索引检查，若索引无效，抛出异常

public:
    //  构造函数、拷贝构造、析构函数
    ArrayList(int initialCapacity = 10);
    ArrayList(const ArrayList<T> &);
    ~ArrayList() { delete[] element; }

    // ADT
};

ArrayList::ArrayList(/* args */)
{
}

ArrayList::~ArrayList()
{
}

#enif