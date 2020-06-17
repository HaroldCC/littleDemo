/*************************************************************************
> File Name       : singleLinkedList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月27日  10时12分02秒
************************************************************************/

/***** 单链表 *****/

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "linearList.h"   // ADT
#include "myExceptions.h" // 异常类
#include <sstream>        // for ostringstream

/*** 链表节点类 ***/
template <typename T>
class Node
{
public:
    T element;
    Node<T> *next;

    Node(){};
    Node(const T &element) { this->element = element; }
    Node(const T &element, Node<T> *next)
    {
        this->element = element;
        this->next = next;
    }
};

/*** 单链表类 ***/
template <typename T>
class singleLinkedList : public linearList<T>
{
private:
    void checkIndex(int index) const; // 索引异常检测

    Node<T> *firstNode; // 链表头节点指针
    int listSize;       // 链表的元素个数

public:
    /* 构造函数 */
    singleLinkedList(int initialCapacity = 10);
    singleLinkedList(const singleLinkedList<T> &);
    ~singleLinkedList();

    /* ADT */
    bool isEmpty() const { return this->listSize == 0; }
    int size() const { return this->listSize; }
    T &getElement(int index) const;
    void setElement(int index, const T &element);
    int indexOf(const T &element) const;
    void removeByIndex(int index);
    void removeByElement(const T &element);
    void add(const T &element);
    void add(int index, const T &element);
    void clear();
    void output(std::ostream &out) const;
};

// 默认构造
template <typename T>
singleLinkedList<T>::singleLinkedList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        std::ostringstream s;
        s << "初始化容量 = " << initialCapacity << "必须 > 0";
        throw illegalParameterValue(s.str());
    }
    this->firstNode = nullptr;
    this->listSize = 0;
}

// 拷贝构造
template <typename T>
singleLinkedList<T>::singleLinkedList(const singleLinkedList<T> &list)
{
    this->listSize = list.listSize;

    // list 为空
    if (this->listSize == 0)
    {
        this->firstNode = nullptr;
        return;
    }

    // list 不为空
    Node<T> *sourceNode = list.firstNode;               // 要复制链表list的节点
    this->firstNode = new Node<T>(sourceNode->element); // 要复制链表list的首元素
    sourceNode = sourceNode->next;
    Node<T> *targetNode = this->firstNode; // 当前链表 *this 的最后一个节点
    while (sourceNode != nullptr)
    { // 复制剩下的节点
        targetNode->next = new Node<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    targetNode->next = nullptr; // 尾部置为空
}

// 析构函数
template <typename T>
singleLinkedList<T>::~singleLinkedList()
{
}

template <typename T>
void singleLinkedList<T>::checkIndex(int index) const
{
    if (index < 0 || index >= this->listSize)
    {
        std::ostringstream s;
        s << "index = " << index << "size = " << this->listSize;
        throw illegalIndex(s.str());
    }
}

// 根据索引获取对应的节点，如未找到，抛异常
template <typename T>
T &singleLinkedList<T>::getElement(int index) const
{
    checkIndex(index);

    Node<T> *currentNode = this->firstNode;
    for (int i = 0; i < index; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}

// 根据索引设置元素值
template <typename T>
void singleLinkedList<T>::setElement(int index, const T &element)
{
    checkIndex(index);

    Node<T> *currentNode = this->firstNode;
    for (int i = 0; i < index; i++)
        currentNode = currentNode->next;

    currentNode->element = element;
}

// 返回给定元素的索引值，若未找到返回 -1
template <typename T>
int singleLinkedList<T>::indexOf(const T &element) const
{
    Node<T> *currentNode = this->firstNode;
    int index = 0;
    while (currentNode != nullptr && currentNode->element != element)
    {
        currentNode = currentNode->next;
        index++;
    }

    if (currentNode == nullptr)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

// 删除指定索引处的元素值，未找到元素抛异常
template <typename T>
void singleLinkedList<T>::removeByIndex(int index)
{
    checkIndex(index);

    Node<T> *deleteNode;
    if (index == 0)
    { // 删除链表中的第一个元素
        deleteNode = this->firstNode;
        this->firstNode = this->firstNode->next;
    }
    else
    {
        Node<T> *p = this->firstNode;
        for (int i = 0; i < index - 1; i++)
            p = p->next;

        deleteNode = p->next;
        p->next = p->next->next;
    }
    this->listSize--;
    delete deleteNode;
}

template <typename T>
void singleLinkedList<T>::removeByElement(const T &element)
{
    removeByIndex(indexOf(element));
}

template <typename T>
void singleLinkedList<T>::add(const T &element)
{
    add(this->listSize, element);
}

// 在指定索引处添加元素
template <typename T>
void singleLinkedList<T>::add(int index, const T &element)
{
    if (index < 0 || index > this->listSize)
    {
        std::ostringstream s;
        s << "index = " << index << "size = " << this->listSize;
        throw illegalIndex(s.str());
    }

    if (index == 0)
    { // 头部插入元素
        this->firstNode = new Node<T>(element, this->firstNode);
    }
    else
    {
        Node<T> *p = this->firstNode;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->next = new Node<T>(element, p->next);
    }
    this->listSize++;
}

template <typename T>
void singleLinkedList<T>::clear()
{
    while (this->firstNode != nullptr)
    {
        Node<T> *nextNode = this->firstNode->next;
        delete this->firstNode;
        firstNode = nextNode;
    }
    this->listSize = 0;
}

template <typename T>
void singleLinkedList<T>::output(std::ostream &out) const
{
    for (Node<T> *currentNode = this->firstNode;
         currentNode != nullptr;
         currentNode = currentNode = currentNode->next)
        out << currentNode->element << " ";
}

// 重载 << 运算符
template <typename T>
std::ostream &operator<<(std::ostream &out, const singleLinkedList<T> &list)
{
    list.output(out);
    return out;
}

#endif