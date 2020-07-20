/*************************************************************************
> File Name       : Queue.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月19日  09时30分02秒
************************************************************************/
#ifndef __QUEUE_H__
#define __QUEUE_H__

/*队列抽象数据类型*/
template <typename T>
class Queue
{
public:
	virtual ~Queue() = default;
	virtual bool empty() const = 0;             // 队列是否为空
	virtual int size() const = 0;               // 队列中元素数量
	virtual T& front() const = 0;               // 返回头元素的引用
	virtual T& back() const = 0;                // 返回尾元素的引用
	virtual void pop() = 0;                     // 删除首元素
	virtual void push(const T& theElement) = 0; // 将元素theElement加入队尾
};
#endif // __QUEUE_H__
