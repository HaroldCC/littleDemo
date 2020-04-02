/*************************************************************************
> File Name       : linearList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月26日  11时02分58秒
************************************************************************/

/***** 线性表的抽象定义 *****/

#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>

template <typename T>
class linearList
{
public:
    virtual ~linearList() {}
    virtual bool isEmpty() const = 0;                         //是否为空
    virtual int size() const = 0;                             // 元素个数
    virtual T &getElement(int index) const = 0;               // 根据索引获取元素
    virtual void setElement(int index, const T &element) = 0; // 根据索引更改元素值
    virtual int indexOf(const T &element) const = 0;          //指定元素第一次出现的索引
    virtual void removeByIndex(int index) = 0;                //根据索引删除元素并返回
    virtual void removeByElement(const T &element) = 0;       // 删除指定元素
    virtual void add(const T &element) = 0;                   // 在尾部插入元素
    virtual void add(int index, const T &element) = 0;        // 在指定索引处插入元素
    virtual void clear() = 0;                                 // 清空操作
    virtual void output(std::ostream &out) const = 0;         // 插入输出流out
};

#endif