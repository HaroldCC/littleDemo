/*************************************************************************
> File Name       : arrayQueue.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  10时48分43秒
************************************************************************/
#ifndef ARRAYQUEUE_H_
#define ARRAYQUEUE_H_

/***** 运用数组实现队列 *****/
#include "ADTqueue.h"
#include "./myExceptions.h"
#include <sstream>
#include <iostream>

template <typename T>
class arrayQueue : public ADTqueue<T>
{
private:
    int m_front; // 队头
    int m_back;  // 队尾
    int m_arrayLength;
    T *m_queue;

public:
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue() { delete[] m_queue; }

    bool empty() const { return m_front == m_back; }
    int size() const { return (m_back - m_front + m_arrayLength) % m_arrayLength; }
    T &front()
    {
        if (m_front == m_back)
        {
            throw queueEmpty();
        }
        return m_queue[(m_front + 1) % m_arrayLength];
    }
    T &back()
    {
        if (m_front == m_back)
        {
            throw queueEmpty();
        }
        return m_queue[(m_front + 1) % m_arrayLength];
    }
    void pop()
    {
        if (m_front == m_back)
        {
            throw queueEmpty();
        }
        m_front = (m_front + 1) % m_arrayLength;
        m_queue[m_front].~T();
    }
    void push(const T &element);

    void output(std::ostream &out) const;
};

template <typename T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        std::ostringstream s;
        s << "初始化容量 = " << initialCapacity << "必须 > 0";
        throw illegalParameterValue(s.str());
    }
    m_arrayLength = initialCapacity;
    m_queue = new T[m_arrayLength];
    m_front = 0;
    m_back = 0;
}

template <typename T>
void arrayQueue<T>::push(const T &element)
{
    if ((m_back + 1) % m_arrayLength == m_front)
    { // 当容量不够时增加容量
        T *newQueue = new T[2 * m_arrayLength];

        // 将元素拷贝至newQueue
        int start = (m_front + 1) % m_arrayLength;
        if (start < 2)
        {
            std::copy(m_queue + start, m_queue + start + m_arrayLength - 1, newQueue);
        }
        else
        {
            std::copy(m_queue + start, m_queue + m_arrayLength, newQueue);
            std::copy(m_queue, m_queue + m_back + 1, newQueue + m_arrayLength - start);
        }

        m_front = 2 * m_arrayLength - 1;
        m_back = m_arrayLength - 2; // 队列size = arrayLength - 1
        m_arrayLength *= 2;
        m_queue = newQueue;
    }
    // 将元素放在队列的后面
    m_back = (m_back + 1) % m_arrayLength;
    m_queue[m_back] = element;
}

template <typename T>
void arrayQueue<T>::output(std::ostream &out) const
{
    out << "capacity = " << this->m_arrayLength << " size = " << size()
        << " front = " << this->m_front << ", [";
    for (int i = 0; i < this->m_arrayLength; i++)
    {
        if (i != 0)
            out << ", ";

        out << this->m_queue[i];
    }
    out << "]";
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const arrayQueue<T> &queue)
{
    queue.output(out);
    return out;
}

#endif