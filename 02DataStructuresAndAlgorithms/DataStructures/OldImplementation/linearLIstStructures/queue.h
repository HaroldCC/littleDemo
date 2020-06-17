/*************************************************************************
> File Name       : queue.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  10时05分23秒
************************************************************************/

#ifndef QUEUE_H_
#define QUEUE_H_
#include "doublyLinkedList.h"
/***** 队列抽象数据类型 *****/
template <typename T>
class queue
{
private:
    doublyLinkedList<T> list;

public:
    ~queue() {}
    int size() { return list.size(); }
    bool empty() { return list.isEmpty(); }
    void enQueue(const T &element);
    void deQueue();
    T &front() const;
};

template <typename T>
void queue<T>::enQueue(const T &element)
{
    list.add(element);
}

template <typename T>
void queue<T>::deQueue()
{
    list.removeByIndex(0);
}

template <typename T>
T &queue<T>::front() const
{
    return list.getElement(0);
}

#endif