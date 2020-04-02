/*************************************************************************
> File Name       : CircleDeque.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月07日  13时21分25秒
************************************************************************/
#ifndef CIRCLEQUEUE_H_
#define CIRCLEDEQUE_H_
#include <iostream>
#include <sstream>
#include "./myExceptions.h"
/***** 循环双端队列 *****/
/* 利用数组进行实现
 * 双端队列：表示头部和尾部都可以进行出入队操作
 */
template <typename T>
class CircleDeque
{
private:
    int front;      // 队头
    int size;       // 队内元素个数
    T *elements;    // 实现队列的数组
    int m_capacity; // 数组容量

    // 验证数组的容量，是否需要进行数组扩容
    void ensureCapacity(int capacity);
    // 传入队列中的索引，映射到数组上获取数组上的索引
    int index(int index);

public:
    // 构造函数
    CircleDeque(int initialCapacity = 10);
    // 析构函数
    ~CircleDeque() { delete[] this->elements; }

    int Size() const { return this->size; }
    bool isEmpty() const { return this->size == 0; }
    // 队尾入队
    void enQueueRear(const T &element);
    // 队头出队
    T deQueueFront();
    // 队头入队
    void enQueueFront(const T &element);
    // 队尾出队
    T deQueueRear();
    // 获取队头
    T &head() const;
    // 获取队尾
    T &tail() const;
    // 清空队列
    void clear();

    // 输出结果
    void output(std::ostream &out) const;
};

// 验证数组的容量，是否需要进行数组扩容
template <typename T>
void CircleDeque<T>::ensureCapacity(int capacity)
{
    int oldCapacity = this->m_capacity;
    if (oldCapacity >= capacity)
    {
        return;
    }

    int newCapacity = oldCapacity + (oldCapacity >> 1);
    T *newElements = new T[newCapacity];
    for (int i = 0; i < this->size; i++)
    {
        newElements[i] = elements[index(i)];
    }
    delete[] this->elements;
    this->elements = newElements;
    this->front = 0;
    this->m_capacity = newCapacity;
}

// 传入队列中的索引，映射到数组上获取数组上的索引
template <typename T>
int CircleDeque<T>::index(int index)
{
    index += this->front;
    if (index < 0)
    {
        return index + this->m_capacity;
    }
    return index % this->m_capacity;
}

// 构造函数
template <typename T>
CircleDeque<T>::CircleDeque(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        std::ostringstream s;
        s << "初始化容量 = " << initialCapacity << "必须 > 0";
        throw illegalParameterValue(s.str());
    }
    this->front = 0;
    this->size = 0;
    this->elements = new T[initialCapacity];
    this->m_capacity = initialCapacity;
}

// 队尾入队
template <typename T>
void CircleDeque<T>::enQueueRear(const T &element)
{
    ensureCapacity(this->size + 1);

    this->elements[index(this->size)] = element;
    this->size++;
}

// 队头出队
template <typename T>
T CircleDeque<T>::deQueueFront()
{
    T frontElement = this->elements[this->front];
    this->elements[this->front] = 0;
    this->front = index(1);
    this->size--;
    return frontElement;
}

// 队头入队
template <typename T>
void CircleDeque<T>::enQueueFront(const T &element)
{
    ensureCapacity(this->size + 1);

    this->front = index(-1);
    this->elements[this->front] = element;
    this->size++;
}

// 队尾出队
template <typename T>
T CircleDeque<T>::deQueueRear()
{
    int rearIndex = index(this->size - 1);
    T rear = this->elements[rearIndex];
    this->elements[rearIndex] = 0;
    this->size--;

    return rear;
}

// 获取队头
template <typename T>
T &CircleDeque<T>::head() const
{
    return this->elements[this->front];
}

// 获取队尾
template <typename T>
T &CircleDeque<T>::tail() const
{
    return this->elements[index(this->size - 1)];
}

// 清空队列
template <typename T>
void CircleDeque<T>::clear()
{
    for (int i = 0; i < this->size; i++)
        this->elements[index(i)] = 0;
    this->size = this->front = 0;
}

// 输出结果
template <typename T>
void CircleDeque<T>::output(std::ostream &out) const
{
    out << "capacity = " << this->m_capacity << " size = " << this->size
        << " front = " << this->front << ", [";
    for (int i = 0; i < this->m_capacity; i++)
    {
        if (i != 0)
            out << ", ";

        out << this->elements[i];
    }
    out << "]";
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const CircleDeque<T> &queue)
{
    queue.output(out);
    return out;
}

#endif