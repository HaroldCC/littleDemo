/*************************************************************************
> File Name       : ArrayQueue.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月19日  09时42分10秒
************************************************************************/
#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <iostream>

#include "Queue.h"
#include"exception.h"

/*数组队列*/
template <typename T>
class ArrayQueue : public Queue<T>
{
	friend std::ostream& operator<<(std::ostream& out, const ArrayQueue<T>& theQueue)
	{
		for (int i = 0; i < theQueue.m_arrayLength; ++i)
		{
			out << theQueue.front() << " ";
		}
		return out;
	}

public:
	// 构造，析构
	explicit ArrayQueue(int initialCapacity = 10);
	ArrayQueue(const ArrayQueue<T>& theQueue);
	ArrayQueue(ArrayQueue<T>&& thQueue) noexcept;
	ArrayQueue& operator=(const ArrayQueue<T>& thQueue);
	ArrayQueue& operator=(ArrayQueue<T>&& theQueue) noexcept;
	~ArrayQueue() { delete[]m_queue; }

	// ADT
	bool empty() const override { return m_queueFront == m_queueBack; }
	int size() const override { return (m_queueBack - m_queueFront + m_arrayLength) % m_arrayLength; }

	T& front() const override
	{
		if (m_queueFront == m_queueBack)throw queueEmpty();
		return m_queue[(m_queueFront + 1) % m_arrayLength];
	}

	T& back() const override { if (m_queueFront == m_queueBack)throw queueEmpty(); return m_queue[m_queueBack]; }
	void pop() override;
	void push(const T& theElement) override;
private:
	int m_queueFront; // 队首
	int m_queueBack; // 队尾
	int m_arrayLength; // 队列长度
	T* m_queue; // 队列元素数组
};

template <typename T>
ArrayQueue<T>::ArrayQueue(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Initial capacity = " << initialCapacity << " must be > 0.";
		throw illegalParameterValue(exceptionMessage.str());
	}
	m_arrayLength = initialCapacity;
	m_queue = new T[m_arrayLength];
	m_queueFront = m_queueBack = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& theQueue)
{
	m_arrayLength = theQueue.m_arrayLength;
	if (m_arrayLength == 0)
	{
		m_queue = nullptr;
		m_queueFront = m_queueBack = 0;
		return;
	}

	m_queue = new T[m_arrayLength];
	for (int i = 0; i < m_arrayLength; ++i)
	{
		m_queue[i] = theQueue.m_queue[i];
	}
	m_queueFront = theQueue.m_queueFront;
	m_queueBack = theQueue.m_queueBack;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(ArrayQueue<T>&& thQueue) noexcept
	: m_queueFront(thQueue.m_queueFront), m_queueBack(thQueue.m_queueBack),
	m_arrayLength(thQueue.m_arrayLength), m_queue(thQueue.m_queue)
{
	thQueue.m_queueFront = thQueue.m_queueBack = 0;
	thQueue.m_arrayLength = 0;
	thQueue.m_queue = nullptr;
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& thQueue)
{
	if (this != &thQueue)
	{
		m_arrayLength = thQueue.m_arrayLength;
		if (m_arrayLength == 0)
		{
			m_queueFront = m_queueBack = 0;
			m_queue = nullptr;
		}

		delete[]m_queue;
		m_queue = new T[m_arrayLength];
		for (int i = 0; i < m_arrayLength; ++i)
		{
			m_queue[i] = thQueue.m_queue[i];
		}
		m_queueFront = thQueue.m_queueFront;
		m_queueBack = thQueue.m_queueBack;
	}
	return *this;
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue<T>&& theQueue) noexcept
{
	if (this != &theQueue)
	{
		m_queueFront = theQueue.m_queueFront;
		m_queueBack = theQueue.m_queueBack;
		m_arrayLength = theQueue.m_arrayLength;
		m_queue = theQueue.m_queue;

		theQueue.m_queueFront = theQueue.m_queueBack = theQueue.m_arrayLength = 0;
		theQueue.m_queue = nullptr;
	}
	return *this;
}

template <typename T>
void ArrayQueue<T>::pop()
{
	if (m_queueFront == m_queueBack)
		throw queueEmpty();

	m_queueFront = (m_queueFront + 1) % m_arrayLength;
	m_queue[m_queueFront].~T();
}

template <typename T>
void ArrayQueue<T>::push(const T& theElement)
{
	// 如果需要，增加数组长度
	if ((m_queueBack + 1) % m_arrayLength == m_queueFront)
	{
		// 加倍数组长度
		T* newQueue = new T[2 * m_arrayLength];

		// 将原数组元素复制到新数组
		int start = (m_queueFront + 1) % m_arrayLength;
		if (start < 2)
			// 没有形成环
			std::copy(m_queue + start, m_queue + start + m_arrayLength - 1, newQueue);
		else
		{
			// 队列形成环
			std::copy(m_queue + start, m_queue + m_arrayLength, newQueue);
			std::copy(m_queue, m_queue + m_queueBack + 1, newQueue + m_arrayLength - start);
		}

		// 设置新队列的首和尾的元素位置
		m_queueFront = 2 * m_arrayLength - 1;
		m_queueBack = m_arrayLength - 2;// 队列长度m_arrayLength - 1
		m_arrayLength *= 2;
		delete[]m_queue;
		m_queue = newQueue;
	}

	// 把元素theElement插入队列尾部
	m_queueBack = (m_queueBack + 1) % m_arrayLength;
	m_queue[m_queueBack] = theElement;
}
#endif // __ARRAYQUEUE_H__
