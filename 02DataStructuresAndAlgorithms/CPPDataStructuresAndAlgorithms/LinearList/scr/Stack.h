/*************************************************************************
> File Name       : Stack.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月13日  14时43分20秒
************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

/*栈抽象数据类型*/
template <typename T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool empty() const = 0; // 栈是否为空
	virtual size_t size() const = 0; // 栈中元素个数
	virtual void push(const T& theElement) = 0; // 将元素theElement压入栈顶
	virtual T& top() const = 0; // 返回栈顶元素引用
	virtual void pop() = 0; // 删除栈顶元素
};

#endif // __STACK_H__
