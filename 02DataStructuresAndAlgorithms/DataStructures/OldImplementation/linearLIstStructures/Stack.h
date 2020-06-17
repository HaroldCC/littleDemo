/*************************************************************************
> File Name       : Stack.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月03日  15时00分16秒
************************************************************************/

#ifndef STACK_H_
#define STACK_H_

#include "arrayList.h"
#include <iostream>

/***** 栈 *****/

/* 栈是一种特殊的链表结构，
 * 这里直接使用数组链表提供实现
 */
template <typename T>
class Stack
{
private:
    arrayList<T> list;

public:
    ~Stack() {}
    int size() const;
    bool empty() const;
    void push(const T &element); // 入栈
    void pop();                  // 出栈
    T &top();                    // 获取栈顶元素
    void clear();

    //void output(std::ostream &out);
};

template <typename T>
int Stack<T>::size() const
{
    return list.size();
}

template <typename T>
bool Stack<T>::empty() const
{
    return list.isEmpty();
}

template <typename T>
void Stack<T>::push(const T &element)
{
    list.add(element);
}

template <typename T>
void Stack<T>::pop()
{
    list.removeByIndex(list.size() - 1);
}

template <typename T>
T &Stack<T>::top()
{
    return list.getElement(list.size() - 1);
}

template <typename T>
void Stack<T>::clear()
{
    list.clear();
}

// template <typename T>
// void output(std::ostream &out)
// {
//     list.output(out);
// }
// template <typename T>
// std::ostream &operator<<(std::ostream &out, const Stack<T> &st)
// {
//     st.output(out);

//     return out;
// }

#endif