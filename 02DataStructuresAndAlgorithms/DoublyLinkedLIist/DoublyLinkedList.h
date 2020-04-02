/*************************************************************************
> File Name       : DoublyLinkedList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月24日  14时47分10秒
************************************************************************/
#ifndef DOUNLY_LINKEDLIST_H_
#define DOUNLY_LINKEDLIST_H_

#include <iostream>

template <class T>
class LinkedList;

// 节点结构
template <typename T>
class Node
{
    friend class LinkedList<T>;

private:
    Node<T> *prev;
    T element;
    Node<T> *next;

    // 构造函数
    Node(const T element) : prev(nullptr), element(element), next(nullptr) {}
};

template <typename T>
class LinkedList
{
public:
    static const int DEFAULT_CAPACITY = 10;
    static const int ELEMENT_NOT_FOUND = -1;

private:
    /* 属性 */
    int m_size;
    Node<T> *head;
    Node<T> *tail;

    // 范围检测
    void outOfBound(int index);
    void rangeCheck(int index);
    void rangeCheckForAdd(int index);

    // 根据索引获取对应的元素
    Node<T> *node(int index)
    {
        rangeCheck(index);

        // 从链表中间分界，离哪一端近就从哪端遍历
        if (index < (this->m_size >> 1))
        {
            Node<T> *node = this->head;
            for (int i = 0; i < index; i++)
            {
                node = node->next;
            }
            return node;
        }
        else
        {
            Node<T> *node = this->tail;
            for (int i = this->m_size - 1; i > index; i--)
            {
                node = node->prev;
            }
            return node;
        }
    }

public:
    // 无参构造
    LinkedList()
    {
        this->m_size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    // 析构函数
    ~LinkedList();
    // 获取数组的大小
    int Size();
    // 数组是否为空
    bool isEmpty();
    // 数组是否包含某元素
    bool contains(const T element);
    // 再数组尾部添元素
    void add(const T element);
    // 根据指定索引值添加元素
    void add(const int index, const T element);
    //根据索引获取元素值
    T getVal(const int index);
    // 根据索引设置索引值
    T setVal(const int index, const T element);
    // 根据索引删除元素并返回删除的元素
    T removeByIndex(const int index);
    // 删除指定的元素
    void removeByElement(const T element);
    // 获取指定元素的索引
    int indexOf(const T element);
    // 清空数组
    void clear();
    // 打印数组中的元素
    void printArray();
};

/*** 方法声明 ***/

/* 私有方法声明 */

// 数组越界
template <typename T>
void LinkedList<T>::outOfBound(int index)
{
    std::cout << "数组索引越界"
              << "Index= " << index << ", Capacity= " << this->m_size << std::endl;
}

// 范围检查
template <typename T>
void LinkedList<T>::rangeCheck(int index)
{
    if (index < 0 || index >= this->m_size)
    {
        outOfBound(index);
    }
}

// add() 函数的范围检查:因为向数组中添加数据时，可以使得索引等于m_size，在尾部插入数据
template <typename T>
void LinkedList<T>::rangeCheckForAdd(int index)
{
    if (index < 0 || index > this->m_size)
    {
        outOfBound(index);
    }
}

/*** 公有方法声明 ***/

template <typename T>
LinkedList<T>::~LinkedList()
{
    //clear();
}

// 数组大小
template <typename T>
int LinkedList<T>::Size()
{
    return this->m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return this->m_size == 0;
}

// 是否包含某元素
template <typename T>
bool LinkedList<T>::contains(const T element)
{
    return indexOf(element) != ELEMENT_NOT_FOUND;
}

template <typename T>
void LinkedList<T>::add(const T element)
{
    add(this->m_size, element);
}

template <typename T>
void LinkedList<T>::add(const int index, const T element)
{
    rangeCheckForAdd(index);

    if (index == this->m_size) // 在最后面添加元素
    {
        Node<T> *oldTail = this->tail;
        Node<T> *addNode = new Node<T>(element);
        addNode->prev = this->tail;
        this->tail->next = addNode;
        this->tail = addNode;

        if (oldTail == nullptr) // 添加的第一个元素
        {
            this->head = this->tail;
        }
        else
        {
            oldTail->next = this->tail;
        }
    }
    else
    {
        Node<T> *nextNode = node(index);
        Node<T> *prevNode = nextNode->prev;
        Node<T> *addNode = new Node<T>(prevNode, element, nextNode);
        nextNode->prev = addNode;

        if (prevNode == nullptr) // index == 0
        {
            this->head = addNode;
            delete addNode;
        }
        else
        {
            prevNode->next = addNode;
            delete addNode;
        }
    }

    m_size++;
}

// 获取索引处的元素值
template <typename T>
T LinkedList<T>::getVal(const int index)
{
    rangeCheck(index);

    Node<T> *nodePtr = head;

    for (int i = 0; i < index; i++)
    {
        nodePtr = nodePtr->next;
    }
    return nodePtr->element;
}

// 设置指定索引处的值,将原来值返回
template <typename T>
T LinkedList<T>::setVal(int index, T element)
{
    Node<T> *nodePtr = head;
    Node<T> *oldElementPtr = nullptr;
    for (int i = 0; i <= index; i++)
    {
        nodePtr = nodePtr->next;
    }
    oldElementPtr->element = nodePtr->element;
    nodePtr->element = element;

    return oldElementPtr->element; // 将原来的值返回 ·
}

// 删除指定索引处的值并返回
template <typename T>
T LinkedList<T>::removeByIndex(int index)
{
    rangeCheck(index);

    Node<T> *delNode = head;
    Node<T> *prevNode = nullptr;

    if (index == 0)
    {
        head = delNode->next;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            prevNode = delNode;
            delNode = delNode->next;
        }
        prevNode->next = delNode->next;
    }
    m_size--;

    return delNode->element;
}

// 删除指定的值
template <typename T>
void LinkedList<T>::removeByElement(T element)
{
    remove(indexOf(element));
}

// 返回指定元素值的索引
template <typename T>
int LinkedList<T>::indexOf(const T element)
{
    if (element == NULL)
    {
        Node<T> *p = head;
        for (int i = 0; i < this->m_size; i++)
        {
            if (p->element == NULL)
                return i;

            p = p->next;
        }
    }
    else
    {
        Node<T> *p = head;
        for (int i = 0; i < this->m_size; i++)
        {
            if (element = p->element)
            {
                return i;
            }

            p = p->next;
        }
    }

    // 未找到元素
    return ELEMENT_NOT_FOUND;
}

// 清空数组
template <typename T>
void LinkedList<T>::clear()
{
    Node<T> *node = this->head;
    while (node != nullptr)
    {
        Node<T> *nextNode = node->next;
        delete node;
    }
    this->head = nullptr;
    this->tail = nullptr;
    this->m_size = 0;
}

template <typename T>
void LinkedList<T>::printArray()
{
    std::cout << "m_size= " << this->m_size << " " << std::endl;
    Node<T> *node = head;
    for (int i = 0; i < this->m_size; i++)
    {
        std::cout << node->element << ", ";
        node = node->next;
    }
    std::cout << std::endl;
}

#endif