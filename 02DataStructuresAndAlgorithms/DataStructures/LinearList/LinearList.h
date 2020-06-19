/*************************************************************************
> File Name       : LinearList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月17日  17时36分26秒
************************************************************************/
#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>
using std::ostream;

/* 线性表的抽象数据类型声明 */
template <typename T>
class LinearList
{
private:
public:
    virtual ~LinearList(){};
    virtual bool empty() const = 0;                             // 若表空，返回true，否则返回false
    virtual size_t size() const = 0;                            // 返回线性表中元素的个数
    virtual T &get(int theIndex) const = 0;                     // 返回索引为theIndex的元素引用
    virtual int index_of(const T &theElement) const = 0;        // 返回元素theElement第一次出现的索引
    virtual void erase(int theIndex) = 0;                       // 删除索引为theIndex的元素
    virtual void insert(int theIndex, const T &theElement) = 0; // 把theElement插入线性表中索引为theIndex的位置
    virtual void output(ostream &out) const = 0;                // 输出线性表中的内容（把线性表插入输出流out）
};

#endif
