/*************************************************************************
> File Name       : VectorList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年06月19日  20时14分24秒
************************************************************************/
#ifndef VECTORLIST_H
#define VACTORLIST_H

#include "exception.h"
#include "LinearList.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class VectorList : public LinearList<T>
{
public:
	const int ELEMENT_NOT_FOUND = -1;

private:
	std::vector<T>* m_elements; // 存储线性表元素的向量

	// 私有方法
	void check_index(int theIndex) const;     // 索引安全检查
	void expansion_capacity(int newCapacity); // 数组扩容
	void shrinkage_capacity(int oldCapacity); // 数组缩容

public:
	// 构造，复制和析构
	VectorList(int initialCapacity = 10);
	VectorList(const VectorList<T>& theVectorList);
	VectorList& operator=(const VectorList<T>& theVectorList);
	~VectorList() { delete m_elements; }

	// ADT
	bool empty() const;                             // 若表空，返回true，否则返回false
	size_t size() const;                            // 返回线性表中元素的个数
	T& get(int theIndex) const;                     // 返回索引为theIndex的元素引用
	int index_of(const T& theElement) const;        // 返回元素theElement第一次出现的索引
	void erase(int theIndex);                       // 删除索引为theIndex的元素
	void insert(int theIndex, const T& theElement); // 把theElement插入线性表中索引为theIndex的位置
	void output(std::ostream& out) const;           // 输出线性表中的内容（把线性表插入输出流out）

	// 其它
	size_t capacity() const { return m_elements->capacity(); }

	// 线性表的起始和结束位置的迭代器
	typedef typename std::vector<T>::iterator iterator;
	iterator begin() { return m_elements->begin(); }
	iterator end() { return m_elements->end(); }
};

template <typename T>
void VectorList<T>::check_index(int theIndex) const
{
	if (theIndex < 0 || theIndex >= m_elements->size())
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "theIndex = " << theIndex << " size = " << m_elements->size();
		throw illegalIndex(exceptionMessage.str());
	}
}

template <typename T>
inline void VectorList<T>::expansion_capacity(int newCapacity)
{
	if (newCapacity < 0)
		throw illegalParameterValue("new capacity must be >= 0.");
	m_elements->resize(newCapacity);
}

template <typename T>
inline void VectorList<T>::shrinkage_capacity(int oldCapacity)
{
	if (m_elements->size() < (oldCapacity / 2))
		expansion_capacity((oldCapacity >> 1));
}

template <typename T>
inline VectorList<T>::VectorList(int initialCapacity)
{
	if (initialCapacity < 0)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Initial capacity = " << initialCapacity << " must be > 0.";
		throw illegalParameterValue(exceptionMessage.str());
	}

	m_elements = new std::vector<T>;      // 创建容量为0的空向量
	m_elements->reserve(initialCapacity); // 分配容量
}

template <typename T>
inline VectorList<T>::VectorList(const VectorList<T>& theVectorList)
{
	m_elements = new std::vector<T>(*theVectorList.m_elements);
}

template <typename T>
VectorList<T>& VectorList<T>::operator=(const VectorList<T>& theVectorList)
{
	if (this != &theVectorList)
	{
		delete m_elements;
		m_elements = new std::vector<T>(*theVectorList.m_elements);
	}
	return *this;
}

template <typename T>
inline bool VectorList<T>::empty() const
{
	return m_elements->size() == 0;
}

template <typename T>
inline size_t VectorList<T>::size() const
{
	return m_elements->size();
}

template <typename T>
inline T& VectorList<T>::get(int theIndex) const
{
	check_index(theIndex);

	return (*m_elements)[theIndex];
}

template <typename T>
inline int VectorList<T>::index_of(const T& theElement) const
{
	for (int i = 0; i < size(); ++i)
	{
		if (theElement == (*m_elements)[i])
			return i;
	}
	return ELEMENT_NOT_FOUND;
}

template <typename T>
inline void VectorList<T>::erase(int theIndex)
{
	check_index(theIndex);

	m_elements->erase(begin() + theIndex);
}

template <typename T>
inline void VectorList<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > size())
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Index = " << theIndex << " size = " << size();
		throw illegalIndex(exceptionMessage.str());
	}

	m_elements->insert(begin() + theIndex, theElement);
}

template <typename T>
inline void VectorList<T>::output(std::ostream& out) const
{
	for (size_t i = 0; i < size(); ++i)
		out << (*m_elements)[i] << " ";
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const VectorList<T>& theVectorList)
{
	theVectorList.output(out);
	return out;
}

#endif
