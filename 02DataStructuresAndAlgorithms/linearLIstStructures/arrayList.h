/*************************************************************************
> File Name       : arrayList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月26日  11时27分44秒
************************************************************************/
/***** 动态数组 *****/

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "linearList.h"
#include "myExceptions.h"
#include <iostream>
#include <sstream> // for std::ostringstream

template <typename T>
class arrayList : public linearList<T>
{
private:
    // 检测索引是否越界
    void checkIndex(int index) const;
    // 数组扩容
    void arrayListCapacityExpansion(T *&a, int oldCapacity, int newCapacity);
    // 数组缩容
    void arrayListCapacityReduce();

    T *m_elements;  // 数组元素
    int m_capacity; // 数组容量
    int m_size;     // 元素个数

public:
    // 构造函数，复制构造函数和析构函数
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T> &);
    ~arrayList()
    { /*delete[] this->m_elements;*/
        //clear();
    }

    // ADT方法
    bool isEmpty() const { return this->m_size == 0; }
    int size() const { return this->m_size; }
    T &getElement(int index) const;
    void setElement(int index, const T &element);
    int indexOf(const T &element) const;
    void removeByIndex(int index);
    void removeByElement(const T &element);
    void add(const T &element);
    void add(int index, const T &element);
    void clear();
    void output(std::ostream &out) const;

    // 其他方法
    int capacity() const { return this->m_capacity; }
};

/*** 定义 ***/

template <typename T>
void arrayList<T>::checkIndex(int index) const
{
    // 确定index在0和m_size - 1之间
    if (index < 0 || index >= this->m_size)
    {
        std::ostringstream s;
        s << "index = " << index << " size = " << this->m_size;
        throw illegalIndex(s.str());
    }
}

template <typename T>
void arrayList<T>::arrayListCapacityExpansion(T *&a, int oldCapacity, int newCapacity)
{
    if (newCapacity < 0)
    {
        throw illegalParameterValue("新容量必须 >= 0");
    }

    T *temp = new T[newCapacity];                    // 新数组
    int number = std::min(oldCapacity, newCapacity); // copy的个数
    std::copy(a, a + number, temp);
    delete[] a; // 释放不在需要的就数组
    a = temp;   // 将新的数组赋给就数组指针
}

template <typename T>
void arrayList<T>::arrayListCapacityReduce()
{
    int oldCapacity = this->m_capacity;
    int newCapacity = oldCapacity >> 1; // 容量减少为原来的一半

    // 判断当size大于等于容量的一半或者容量小于等于默认容量，不需要缩容
    if (this->m_size >= newCapacity || oldCapacity <= 10)
    {
        return;
    }

    T *newElements = new T[newCapacity];
    for (int i = 0; i < this->m_size; i++)
    {
        newElements[i] = this->m_elements[i];
    }
    delete[] m_elements;

    this->m_elements = newElements;
    this->m_capacity = newCapacity;
}

template <typename T>
arrayList<T>::arrayList(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        std::ostringstream s; // 构造新的字符串
        s << "初始容量 = " << initialCapacity << "必须 > 0!";
        throw illegalParameterValue(s.str());
    }
    this->m_capacity = initialCapacity;
    this->m_elements = new T[this->m_capacity];
    this->m_size = 0;
}

template <typename T>
arrayList<T>::arrayList(const arrayList<T> &list)
{
    this->m_capacity = list.m_capacity;
    this->m_size = list.m_size;
    this->m_elements = new T[this->m_capacity];

    // // 将数据拷贝过去（STL算法）
    // std::copy(list.element, list.element + this->m_size, this->element);

    for (int i = 0; i < this->m_size; i++)
        this->m_elements[i] = list.m_elements[i];
}

// 返回索引为index的元素，若不存在，抛出异常
template <typename T>
T &arrayList<T>::getElement(int index) const
{
    checkIndex(index);
    return this->m_elements[index];
}

// 设置指定索引处的元素值
template <typename T>
void arrayList<T>::setElement(int index, const T &element)
{
    checkIndex(index);
    this->m_elements[index] = element;
}

// 返回元素element第一次出现的索引，元素不存在，返回-1
template <typename T>
int arrayList<T>::indexOf(const T &element) const
{
    // // 使用STL算法
    // int elementIndex = (int)(std::find(this->element, this->element + this->m_size, element) - this->element);

    // if (elementIndex == this->m_size)
    // {
    //     // 未找到
    //     return -1;
    // }
    // else
    // {
    //     return elementIndex;
    // }

    // 遍历寻找元素
    for (int i = 0; i < this->m_size; i++)
        if (this->m_elements[i] == element)
            return i;

    return -1;
}

// 删除索引为 index 的元素，若元素不存在，抛出illegalIndex异常
template <typename T>
void arrayList<T>::removeByIndex(int index)
{
    checkIndex(index);

    // // STL算法
    // // 有效索引，移动其索引大于index的元素
    // std::copy(this->element + index + 1, this->element + this->m_size, this->element + index);

    for (int i = index + 1; i < this->m_size; i++)
    {
        this->m_elements[i - 1] = m_elements[i];
    }

    this->m_elements[--this->m_size].~T(); // 调用析构函数

    // 是否需要缩容
    arrayListCapacityReduce();
}

template <typename T>
void arrayList<T>::removeByElement(const T &element)
{
    removeByIndex(indexOf(element));
}

template <typename T>
void arrayList<T>::add(const T &element)
{
    add(this->m_size, element);
}

// 在索引 index 处插入元素 element
template <typename T>
void arrayList<T>::add(int index, const T &element)
{
    if (index < 0 || index > this->m_size) // 无效索引
    {
        std::ostringstream s;
        s << "index = " << index << " size = " << this->m_size;
        throw illegalIndex(s.str());
    }

    // 判断是否有足够容量’
    if (this->m_size == this->m_capacity)
    {
        int oldCapacity = this->m_capacity;
        int newCapacity = oldCapacity + (oldCapacity >> 1);

        // 数组中元素个数等于容量，再添加需要扩容
        // 这里设置每次增加的容量是之前容量的1.5倍
        arrayListCapacityExpansion(this->m_elements, oldCapacity, newCapacity);
        this->m_capacity = newCapacity;
    }

    // 将数组元素向右迁移
    for (int i = this->m_size - 1; i >= index; i--)
    {
        this->m_elements[i + 1] = this->m_elements[i];
    }
    this->m_elements[index] = element;

    this->m_size++;
}

template <typename T>
void arrayList<T>::clear()
{
    delete[] this->m_elements;
    this->m_capacity = 0;
    this->m_size = 0;
}

// 将arrayList放入输出流
template <typename T>
void arrayList<T>::output(std::ostream &out) const
{
    for (int i = 0; i < this->m_size; i++)
    {
        out << this->m_elements[i] << " ";
    }
}

// 重载 <<
template <typename T>
std::ostream &operator<<(std::ostream &out, const arrayList<T> &list)
{
    list.output(out);
    return out;
}
#endif