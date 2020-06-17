/*************************************************************************
> File Name       : ADTqueue.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  10时38分59秒
************************************************************************/
#ifndef ADTQUEUE_H_
#define ADTQUEUE_H_

/***** 队列的抽象数据类型 *****/

template <typename T>
class ADTqueue
{
public:
    virtual ~ADTqueue() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T &front() = 0;                  // 返回头元素的引用
    virtual T &back() = 0;                   // 返回尾元素的引用
    virtual void pop() = 0;                  // 删除首元素
    virtual void push(const T &element) = 0; // 元素入队尾
};
#endif