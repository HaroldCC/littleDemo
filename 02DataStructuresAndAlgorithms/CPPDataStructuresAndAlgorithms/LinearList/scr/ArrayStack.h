/*************************************************************************
> File Name       : ArrayStack.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月13日  14时54分28秒
************************************************************************/
#ifndef __ARRAYSTACK_H__
#define __ARRAYSTACK_H__

#include "LinearList.h"
#include "ArrayList.h"
#include "Stack.h"

/*动态数组（ArrayList）实现的栈*/
template <typename T>
class ArrayListStack : private ArrayList<T>, public Stack<T>
{
public:
	ArrayListStack(int initialCapacity = 10) : ArrayList<T>(initialCapacity) {}

	// ADT
	bool empty() const override { return ArrayList<T>::empty(); }
	size_t size() const override { return ArrayList<T>::size(); }
	void push(const T& theElement) override { ArrayList<T>::insert(ArrayList<T>::size(), theElement); }

	T& top() const override
	{
		if (ArrayList<T>::empty())throw stackEmpty();
		return ArrayList<T>::get(ArrayList<T>::size() - 1);
	}

	void pop() override
	{
		if (ArrayList<T>::empty())throw stackEmpty();
		ArrayList<T>::erase(ArrayList<T>::size() - 1);
	}
};

/****************************************************
 *使用ArrayList实现的栈性能有损耗，当向栈push元素时，
 *会调用ArrayList的insert方法，插入之前还要进行下标检查，
 *数组的动态扩容，这些在栈操作是不需要的，因此，重新实现。
 ***************************************************/

 /*数组实现的栈*/
template <typename T>
class ArrayStack : public Stack<T>
{
public:
	// 构造，析构
	explicit ArrayStack(int initialCapacity = 10);
	ArrayStack(const ArrayStack<T>& theStack);
	ArrayStack(ArrayStack<T>&& theStack) noexcept;
	ArrayStack& operator=(const ArrayStack<T>& theStack);
	ArrayStack& operator=(ArrayStack<T>&& theStack) noexcept;
	~ArrayStack() { delete[] m_element; }

	// ADT:
	bool empty() const override { return m_top == -1; }
	size_t size() const override { return m_top + 1; }
	void push(const T& theElement) override
	{
		// 将元素theElement压入栈
		if (m_top == m_arrayLength - 1)
		{
			// 空间已满，容量加倍
			expansion_capacity(m_arrayLength << 1);
		}

		// 在栈顶插入
		m_element[++m_top] = theElement;
	}

	T& top() const override
	{
		if (m_top == -1)throw stackEmpty();
		return m_element[m_top];
	}

	void pop() override
	{
		if (m_top == -1)
			throw stackEmpty();
		m_element[m_top--].~T();
	}
private:
	void expansion_capacity(int newCapacity)
	{
		if (newCapacity < 0)
		{
			throw illegalParameterValue("new capacity must be >= 0.");
		}
		T* temp = new T[newCapacity];
		std::copy(m_element, m_element + m_arrayLength, temp);
		delete m_element;
		m_element = temp;
		m_arrayLength = newCapacity;
	}
private:
	int m_top; // 当前栈顶
	int m_arrayLength; // 数组容量
	T* m_element; // 元素数组
};

template <typename T>
ArrayStack<T>::ArrayStack(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Initial capacity = " << initialCapacity << " must be > 0.";
		throw illegalParameterValue(exceptionMessage.str());
	}

	m_arrayLength = initialCapacity;
	m_element = new T[m_arrayLength];
	m_top = -1;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& theStack)
{
	m_arrayLength = theStack.m_arrayLength;
	if (m_arrayLength == 0)
	{
		m_element = nullptr;
	}
	m_top = theStack.m_top;

	m_element = new T[m_arrayLength];
	for (int i = 0; i != m_arrayLength; ++i)
	{
		m_element[i] = theStack.m_element[i];
	}
}

template <typename T>
ArrayStack<T>::ArrayStack(ArrayStack<T>&& theStack) noexcept
	: m_top(theStack.m_top), m_arrayLength(theStack.m_arrayLength), m_element(theStack.m_element)
{
	theStack.m_element = nullptr;
	theStack.m_arrayLength = 0;
	theStack.m_top = -1;
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& theStack)
{
	if (this != &theStack)
	{
		delete[]m_element;

		m_arrayLength = theStack.m_arrayLength;
		if (m_arrayLength == 0)
		{
			m_element = nullptr;
		}
		m_top = theStack.m_top;

		m_element = new T[m_arrayLength];
		for (int i = 0; i != m_arrayLength; ++i)
		{
			m_element[i] = theStack.m_element[i];
		}
	}
	return *this;
}

template <typename T>
ArrayStack<T>& ArrayStack<T>::operator=(ArrayStack<T>&& theStack) noexcept
{
	if (this != &theStack)
	{
		m_element = theStack.m_element;
		m_arrayLength = theStack.m_arrayLength;
		m_top = theStack.m_top;

		theStack.m_element = nullptr;
		theStack.m_arrayLength = 0;
		theStack.m_top = -1;
	}
	return *this;
}

#endif // __ARRAYSTACK_H__
