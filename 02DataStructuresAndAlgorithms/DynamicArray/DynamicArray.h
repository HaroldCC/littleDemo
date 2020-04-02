/*************************************************************************
> File Name       : DynamicArray.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月17日  13时06分30秒
************************************************************************/
#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include <iostream>

/* 
 * 动态数组C++实现
 */
template <typename T>
class DynamicArray
{
public:
    static const int DEFAULT_CAPACITY = 10;  // 默认数组内存大小
    static const int ELEMENT_NOT_FOUND = -1; // 元素未找到

private:
    /* 
     * 属性
     */
    T *m_elements;  // 数组的首地址指针
    int m_size;     // 数组内元素的个数
    int m_capacity; // 数组的容量

    /*
     * 私有方法
     */
    // 数组越界
    void outOfBound(int index);

    // 范围检查
    void rangeCheck(int index);

    // add() 函数的范围检查:因为向数组中添加数据时，可以使得索引等于size，在尾部插入数据
    void rangeCheckForAdd(int index);

    // 确定数组容量，来决定是否进行扩容
    void ensureCapacity(int capacity);

    // 数组缩容
    void trimCapacity();

public:
    DynamicArray(int capacity);              // 有参构造函数
    DynamicArray();                          // 无参构造函数
    DynamicArray(const DynamicArray &array); // 拷贝构造函数
    //DynamicArray &operator=(const DynamicArray array); // 赋值运算符重载
    //DynamicArray &operator[](int index);               // []运算符重载
    int Size();     // 数组大小
    int Capacity(); // 数组容量
    bool isEmpty();
    bool contains(T element); // 是否包含某元素
    void add(T element);
    void add(int index, T element);
    T getVal(int index);             // 获取索引处的元素值
    T setVal(int index, T element);  // 设置指定索引处的值
    T removeByIndex(int index);      // 删除指定索引处的值并返回
    void removeByElement(T element); // 删除指定的值
    int indexOf(T element);          // 返回指定元素值的索引
    void clear();                    // 清楚数组
    ~DynamicArray();

    void showArray();

    //friend std::ostream &operator<<(std::ostream &os, const DynamicArray<T> &array);
};

#endif

/*** 方法声明 ***/

/* 私有方法声明 */

// 数组越界
template <typename T>
void DynamicArray<T>::outOfBound(int index)
{
    std::cout << "数组索引越界"
              << "Index= " << index << ", Capacity= " << this->m_capacity << std::endl;
}

// 范围检查
template <typename T>
void DynamicArray<T>::rangeCheck(int index)
{
    if (index < 0 || index >= this->m_size)
    {
        outOfBound(index);
    }
}

// add() 函数的范围检查:因为向数组中添加数据时，可以使得索引等于size，在尾部插入数据
template <typename T>
void DynamicArray<T>::rangeCheckForAdd(int index)
{
    if (index < 0 || index > this->m_size)
    {
        outOfBound(index);
    }
}

// 确定数组容量，来判断是否进行扩容
template <typename T>
void DynamicArray<T>::ensureCapacity(int capacity)
{
    int oldCapacity = this->m_capacity;

    // 当需要的容量小于原先的容量,不需要进行申请
    if (capacity <= oldCapacity)
        return;

    // 将容量扩大1.5倍
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    T *newElements = new T[newCapacity];
    for (int i = 0; i < this->m_size; i++)
    {
        newElements[i] = this->m_elements[i];
    }

    delete[] m_elements; // 释放原来的数组

    // 将原来元素的头指针指向扩容后的数组头指针
    this->m_elements = newElements;
    this->m_capacity = newCapacity;

    std::cout << oldCapacity << "扩容为" << newCapacity << ", 容量为" << this->m_capacity << std::endl;
}

// 当数组中的数据小于数组总容量的一半，对数组缩容
template <typename T>
void DynamicArray<T>::trimCapacity()
{
    int oldCapacity = this->m_capacity;
    int newCapacity = oldCapacity >> 1; // 容量缩小为原来的一半

    // 判断当size大于等于容量的一半或者容量小于等于默认容量，不需要缩容
    if (this->m_size >= newCapacity || oldCapacity <= DEFAULT_CAPACITY)
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

    std::cout << oldCapacity << "缩容为" << newCapacity << "，容量为" << this->m_capacity << std::endl;
}

/* 公有方法声明 */
template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
    this->m_capacity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
    this->m_size = 0;
    this->m_elements = new T[this->m_capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray()
{
    this->m_capacity = DEFAULT_CAPACITY;
    this->m_size = 0;
    this->m_elements = new T[this->m_capacity];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    if (this->m_elements != nullptr)
    {
        delete[] this->m_elements;
        this->m_elements = nullptr;
    }

    this->m_size = 0;
}

// // 赋值运算符重载
// template <typename T>
// DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray array)
// {
//     if (this->m_elements != nullptr)
//     {
//         delete[] this->m_elements;
//     }

//     this->m_capacity = array.m_capacity;
//     this->m_size = array.m_size;
// }

// 数组大小
template <typename T>
int DynamicArray<T>::Size()
{
    return this->m_size;
}

// 数组容量
template <typename T>
int DynamicArray<T>::Capacity()
{
    return this->m_capacity;
}

template <typename T>
bool DynamicArray<T>::isEmpty()
{
    return this->m_size == 0;
}

// 是否包含某元素
template <typename T>
bool DynamicArray<T>::contains(T element)
{
    return indexOf(element) != ELEMENT_NOT_FOUND;
}

template <typename T>
void DynamicArray<T>::add(T element)
{
    add(this->m_size, element);
}

template <typename T>
void DynamicArray<T>::add(int index, T element)
{
    rangeCheckForAdd(index);

    ensureCapacity(this->m_size + 1);

    for (int i = this->m_size; i > index; i--)
    {
        this->m_elements[i] = this->m_elements[i - 1];
    }
    this->m_elements[index] = element;

    this->m_size++;
}

// 获取索引处的元素值
template <typename T>
T DynamicArray<T>::getVal(int index)
{
    rangeCheck(index);

    return this->m_elements[index];
}

// 设置指定索引处的值,将原来值返回
template <typename T>
T DynamicArray<T>::setVal(int index, T element)
{
    rangeCheck(index);

    int oldElement = this->m_elements[index];
    this->m_elements[index] = element;

    return oldElement; // 将原来的值返回 ·
}

// 删除指定索引处的值并返回
template <typename T>
T DynamicArray<T>::removeByIndex(int index)
{
    rangeCheck(index);

    T oldElement = this->m_elements[index];
    for (int i = index + 1; i < this->m_size; i++)
    {
        this->m_elements[i - 1] = this->m_elements[i];
    }
    this->m_size--;

    this->m_elements[this->m_size] = NULL;

    trimCapacity();

    return oldElement;
}

// 删除指定的值
template <typename T>
void DynamicArray<T>::removeByElement(T element)
{
    remove(indexOf(element));
}

// 返回指定元素值的索引
template <typename T>
int DynamicArray<T>::indexOf(T element)
{
    if (element != NULL)
    {
        for (int i = 0; i < this->m_size; i++)
        {
            if (this->m_elements[i] == element)
                return i;
        }
    }
    else
    {
        for (int i = 0; i < this->m_size; i++)
        {
            // 这里传入的对象需要重载“==”比较运算符
            // 或者在声明类时自定义判断声明的对象是否相同
            /** 示例一 **/
            if (this->m_elements[i] == element)
            {
                return i;
            }

            /** 示例二 **/
            // isSamr() 是声明类是自定义的判断方法
            /*if(element.isSame(elements[i]))
                return i;
            */
        }
    }

    // 未找到元素
    return ELEMENT_NOT_FOUND;
}

// 清空数组
template <typename T>
void DynamicArray<T>::clear()
{
    for (int i = 0; i < this->m_size; i++)
    {
        // 只是放对象而不释放数组的索引内存
        this->m_elements[i] = NULL;
    }
    this->m_size = 0;
}

template <typename T>
void DynamicArray<T>::showArray()
{
    std::cout << "size= " << this->m_size << " " << std::endl;
    for (int i = 0; i < this->m_size; i++)
    {
        std::cout << this->m_elements[i] << ", ";
    }
    std::cout << std::endl;
}

// /* 友元函数声明 */
// template <typename T>
// std::ostream &operator<<(std::ostream &os, const DynamicArray<T> &array)
// {
//     os << "size= " << array.Size() << ", [";
//     for (int i = 0; i < array.size; i++)
//     {
//         if (i != 0)
//         {
//             os << ", ";
//         }

//         os << array.elements[i];
//     }
//     os << "]";

//     return os;
// }