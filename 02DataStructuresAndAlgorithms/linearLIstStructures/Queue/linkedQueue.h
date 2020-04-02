/*************************************************************************
> File Name       : linkedQueue.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  13时40分44秒
************************************************************************/
#ifndef LINKEDQUEUE_H_
#define LINKEDQUEUQ_H_

#include "ADTqueue.h"
#include "myExceptions.h"
#include <sstream>

/***** 运用链表实线队列 *****/

template <typename T>
struct Node
{
    T element;
    Node<T> *next;

    Node() {}
    Node(const T &element) { this->element; }
    Node(const T &element, Node<T> *next)
    {
        this->element = element;
        this->next = next;
    }
};

template <typename T>
class linkedQueue : public ADTqueue<T>
{
private:
    Node<T> *queueFront; // 队头指针
    Node<T> *queueBack;  // 队尾指针
    int queueSize;       // 队列元素个数

public:
    linkedQueue(int initialCapacity = 10)
    {
        queueFront = nullptr;
        queueSize = 0;
    }
    ~linkedQueue();
    bool empty() const { return queueSize == 0; }
    int size() const { return queueSize; }
    T &front()
    {
        if (queueSize == 0)
        {
            throw queueEmpty();
        }
        return queueFront->element;
    }
    T &back()
    {
        if (queueSize == 0)
        {
            throw queueEmpty();
        }
        return queueBack->element;
    }
    void pop();
    void push(const T &);
};

template <typename T>
linkedQueue<T>::~linkedQueue()
{
    while (queueFront != nullptr)
    {
        Node<T> *nextNode = queueFront->next;
        delete queueFront;
        queueFront = nextNode;
    }
}

template <typename T>
void linkedQueue<T>::pop()
{
    if (queueFront == nullptr)
    {
        throw queueEmpty();
    }

    Node<T> *nextNode = queueFront->next;
    delete queueFront;
    queueFront = nextNode;
    queueSize--;
}

template <typename T>
void linkedQueue<T>::push(const T &element)
{
    // 创建新节点
    Node<T> *newNode = new Node<T>(element, nullptr);

    // 将新节点添加到队尾
    if (queueSize == 0)
        queueFront = newNode; // 队为空
    else
        queueBack->next = newNode; // 队不为空
    queueBack = newNode;

    queueSize++;
}

#endif