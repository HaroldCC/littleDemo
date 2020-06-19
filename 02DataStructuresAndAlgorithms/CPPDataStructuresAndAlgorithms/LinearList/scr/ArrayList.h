/*************************************************************************
> File Name       : ArrayList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月17日  18时43分54秒
************************************************************************/
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "LinearList.h"
#include "exception.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

/* 动态数组的泛化实现 */
template <typename T>
class ArrayList : public LinearList<T>
{
public:
	const int ELEMENT_NOT_FOUND = -1;

private:
	T *m_elements;	   // 存储线性表的一维数组
	size_t m_capacity; // 数组容量
	size_t m_size;	   // 数组包含的元素个数

	void check_index(int theIndex) const;	  // 数组索引检查，若索引无效，抛出异常
	void shrinkage_capacity(int oldCapacity); // 数组缩容
	void expansion_capacity(int newCapacity); // 数组扩容

public:
	//  构造函数、拷贝构造、析构函数
	ArrayList(int initialCapacity = 10);
	ArrayList(const ArrayList<T> &);
	~ArrayList() { delete[] m_elements; }

	// ADT
	bool empty() const;								// 若表空，返回true，否则返回false
	size_t size() const;							// 返回线性表中元素的个数
	T &get(int theIndex) const;						// 返回索引为theIndex的元素引用
	int index_of(const T &theElement) const;		// 返回元素theElement第一次出现的索引
	void erase(int theIndex);						// 删除索引为theIndex的元素
	void insert(int theIndex, const T &theElement); // 把theElement插入线性表中索引为theIndex的位置
	void output(ostream &out) const;				// 输出线性表中的内容（把线性表插入输出流out）

	// 其它方法
	size_t capacity() const;
	void clear() { m_size = 0; }

	//ArrayList的首元素和尾后迭代器
	class iterator;
	iterator begin() { return iterator(m_elements); }
	iterator end() { return iterator(m_elements + m_size); }

	// ArrayList的迭代器定义
	class iterator
	{
	private:
		T *position; // 指向表元素的指针

	public:
		// 用C++的typedef实现双向迭代器
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;

		// 构造
		iterator(T *thePosition = 0) { this->position = thePosition; }

		// 解引用操作符
		T &operator*() const { return *(this->position); }
		T *operator->() const { return &*(this->position); }

		// 迭代器递增
		iterator &operator++()
		{
			++this->position;
			return *this;
		} // 前加
		iterator operator++(int)
		{
			iterator oldValue = *this;
			++this->position;
			return oldValue;
		} // 后加

		// 迭代器递减
		iterator &operator--()
		{
			--this->position;
			return *this;
		} // 前减
		iterator operator--(int)
		{
			iterator oldValue = *this;
			--this->position;
			return oldValue;
		} // 后减

		// 是否相等
		bool operator==(const iterator right) const { return this->position == right.position; }
		bool operator!=(const iterator right) const { return this->position != right.position; }
	};
};

// 私有方法
template <typename T>
inline void ArrayList<T>::check_index(int theIndex) const
{
	if (theIndex < 0 || theIndex >= m_size)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_size;
		throw illegalIndex(exceptionMessage.str());
	}
}

template <typename T>
inline void ArrayList<T>::expansion_capacity(int newCapacity)
{
	if (newCapacity < 0)
		throw illegalParameterValue("new capacity must be >= 0.");

	T *temp = new T[newCapacity];
	m_capacity = newCapacity;
	for (int i = 0; i < m_size; ++i)
		temp[i] = m_elements[i];
	delete[] m_elements; // 释放老数组的空间
	m_elements = temp;	 // 让老数组的头指针指向扩容后的数组
}

template <typename T>
inline void ArrayList<T>::shrinkage_capacity(int oldCapacity)
{
	// 当数组中元素个数小于容量的一半时，进行缩容
	if (m_size < (oldCapacity / 2))
		// 此处的实现是调用扩容操作的方法，传递一个较小的新容量(将容量减去一半)
		expansion_capacity(oldCapacity >> 1);
}

template <typename T>
inline ArrayList<T>::ArrayList(int initialCapacity)
{
	if (initialCapacity < 0)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Initial capacity = " << initialCapacity << " must be > 0.";
		throw illegalParameterValue(exceptionMessage.str());
	}
	m_elements = new T[initialCapacity];
	m_capacity = initialCapacity;
	m_size = 0;
}

template <typename T>
inline ArrayList<T>::ArrayList(const ArrayList<T> &theArrayList)
{
	m_elements = new T[theArrayList.m_capacity];
	m_capacity = theArrayList.m_capacity;
	m_size = theArrayList.m_size;

	// 将theArrayList中的元素逐一赋给ArrayList
	for (size_t i = 0; i < m_size; ++i)
	{
		m_elements[i] = theArrayList.m_elements[i];
	}
}

// ADT
template <typename T>
inline bool ArrayList<T>::empty() const
{
	return m_size == 0;
}

template <typename T>
inline size_t ArrayList<T>::size() const
{
	return m_size;
}

template <typename T>
inline T &ArrayList<T>::get(int theIndex) const
{
	check_index(theIndex);
	return m_elements[theIndex];
}

template <typename T>
inline int ArrayList<T>::index_of(const T &theElement) const
{
	for (int index = 0; index < m_size; ++index)
	{
		if (theElement == m_elements[index])
			return index;
	}
	return ELEMENT_NOT_FOUND;
}

template <typename T>
inline void ArrayList<T>::erase(int theIndex)
{
	check_index(theIndex);

	// 使用theIndex索引处的后一个元素覆盖theIndex处的元素
	for (int i = theIndex + 1; i < m_size; ++i)
	{
		m_elements[i - 1] = m_elements[i];
	}

	// 数组size减一，并调用一次T的析构函数
	m_elements[--m_size].~T();

	shrinkage_capacity(m_capacity);
}

template <typename T>
inline void ArrayList<T>::insert(int theIndex, const T &theElement)
{
	// 由于此时的索引值可以是数组的size，
	// 即表明向数组最后一个位置插入元素，之前的check_index方法已经不再适用
	if (theIndex < 0 || theIndex > m_size)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Index = " << theIndex << " size = " << m_size;
		throw illegalIndex(exceptionMessage.str());
	}

	if (m_capacity <= m_size)
	{
		// 扩容2倍
		expansion_capacity(m_capacity << 1);
	}

	for (int i = m_size - 1; i >= theIndex; --i)
	{
		m_elements[i + 1] = m_elements[i];
	}
	m_elements[theIndex] = theElement;

	m_size++;
}

template <typename T>
inline void ArrayList<T>::output(ostream &out) const
{
	for (size_t i = 0; i < m_size; ++i)
		out << m_elements[i] << " ";
}

// 其它
template <typename T>
inline size_t ArrayList<T>::capacity() const
{
	return m_capacity;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const ArrayList<T> &theArrayList)
{
	theArrayList.output(out);
	return out;
}
#endif
