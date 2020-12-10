/*************************************************************************
> File Name       :SingleLinkedList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020锟斤拷07锟斤拷08锟斤拷  10时11锟斤拷34锟斤拷
************************************************************************/

/* 锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷实锟斤拷 */
#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include "LinearList.h"
#include <iostream>
#include <sstream>
#include "exception.h"

	/**
	 * @brief 锟斤拷锟斤拷锟节碉拷
	 *
	 * @param T
	 */
template <typename Type>
struct ListNode
{
	// 锟斤拷锟捷筹拷员
	Type m_element;
	ListNode<Type>* m_next;

	// 锟斤拷锟斤拷
	ListNode() : m_next(nullptr) { }

	ListNode(const Type& element) : m_element(element), m_next(nullptr) { }

	ListNode(const Type& element, ListNode<Type>* next)
		: m_element(element), m_next(next) { }
};

template <typename T>
class SingleLinkedList : public LinearList<T>
{

	friend std::ostream& operator<<(std::ostream& out, const SingleLinkedList<T>& theList)
	{
		theList.output(out);
		return out;
	}

public:
	SingleLinkedList(int initialCapacity = 10);
	SingleLinkedList(const SingleLinkedList<T>& theList);

	SingleLinkedList(SingleLinkedList<T>&& theList) noexcept
		: m_firstNode(theList.m_firstNode), m_listSize(theList.m_listSize)
	{
		theList.m_firstNode = nullptr;
		theList.m_listSize = 0;
	}

	SingleLinkedList& operator=(const SingleLinkedList<T>& theList);
	SingleLinkedList& operator=(SingleLinkedList<T>&& theList) noexcept;

	~SingleLinkedList()
	{
		while (m_firstNode != nullptr)
		{
			ListNode<T>* nextNode = m_firstNode->m_next;
			delete m_firstNode;
			m_firstNode = nextNode;
		}
	}

	// ADT
	bool empty() const override { return m_listSize == 0; }
	size_t size() const override { return m_listSize; }
	T& get(int theIndex) const override;
	int index_of(const T& theElement) const override;
	void erase(int theIndex) override;
	void insert(int theIndex, const T& theElement) override;

	class iterator;
	iterator begin() { return iterator(m_firstNode); }
	iterator end() { return iterator(nullptr); }

public:
	class iterator
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using value_type = T;
		using difference_type = ptrdiff_t;
		using pointer = T*;
		using reference = T&;

		// 锟斤拷锟届函锟斤拷
		iterator(ListNode<T>* theNode = nullptr) : m_node(theNode) { }

		// 锟斤拷锟斤拷锟矫诧拷锟斤拷锟斤拷
		T& operator*() const { return m_node->m_element; }
		T* operator->() const { return &m_node->m_element; }

		// 锟斤拷锟斤拷锟斤拷锟接凤拷
		iterator& operator++() // 前锟斤拷
		{
			m_node = m_node->m_next;
			return *this;
		}

		iterator operator++(int) // 锟斤拷锟斤拷
		{
			iterator old = *this;
			m_node = m_node->m_next;
			return old;
		}

		// 锟斤拷燃锟斤拷锟�
		bool operator!=(const iterator rhs) const { return m_node != rhs.m_node; }
		bool operator==(const iterator rhs) const { return m_node == rhs.m_node; }

	private:
		ListNode<T>* m_node;
	};

protected:
	void check_index(int theIndex) const;
	void output(ostream& out) const override;

	ListNode<T>* m_firstNode; // 指锟斤拷锟斤拷锟斤拷锟斤拷一锟斤拷锟节碉拷锟街革拷锟�
	size_t m_listSize; // 锟斤拷锟斤拷锟斤拷元锟截的革拷锟斤拷
};

template <typename T>
SingleLinkedList<T>::SingleLinkedList(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Initial capacity = " << initialCapacity << " must be >= 0.";
		throw illegalIndex(exceptionMessage.str());
	}

	m_firstNode = nullptr;
	m_listSize = 0;
}

template <typename T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T>& theList)
{
	m_listSize = theList.m_listSize;

	if (m_listSize == 0)
	{
		m_firstNode = nullptr;
		return;
	}

	ListNode<T>* sourceNode = theList.m_firstNode;
	m_firstNode = new ListNode<T>(sourceNode->m_element);
	sourceNode = sourceNode->m_next;
	ListNode<T>* targetNode = m_firstNode;
	while (sourceNode != nullptr)
	{
		targetNode->m_next = new ListNode<T>(sourceNode->m_element);
		targetNode = targetNode->m_next;
		sourceNode = sourceNode->m_next;
	}
	targetNode->m_next = nullptr;
}

template <typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(const SingleLinkedList<T>& theList)
{
	if (this != &theList)
	{
		delete m_firstNode;

		m_listSize = theList.m_listSize;

		if (m_listSize == 0)
		{
			m_firstNode = nullptr;
		}
		else
		{
			ListNode<T>* sourceNode = theList.m_firstNode;
			m_firstNode = new ListNode<T>(sourceNode->m_element);
			sourceNode = sourceNode->m_next;
			ListNode<T>* targetNode = m_firstNode;
			while (sourceNode != nullptr)
			{
				targetNode->m_next = new ListNode<T>(sourceNode->m_element);
				targetNode = targetNode->m_next;
				sourceNode = sourceNode->m_next;
			}
			targetNode->m_next = nullptr;
		}
	}
	return *this;
}

template <typename T>
SingleLinkedList<T>& SingleLinkedList<T>::operator=(SingleLinkedList<T>&& theList) noexcept
{
	if (this != &theList)
	{
		delete m_firstNode;
		m_firstNode = theList.m_firstNode;
		m_listSize = theList.m_listSize;

		theList.m_firstNode = nullptr;
		theList.m_listSize = 0;
	}
	return *this;
}

template <typename T>
T& SingleLinkedList<T>::get(int theIndex) const
{
	check_index(theIndex);

	ListNode<T>* currentNode = m_firstNode;
	for (int i = 0; i != theIndex; ++i) { currentNode = currentNode->m_next; }
	return currentNode->m_element;
}

template <typename T>
int SingleLinkedList<T>::index_of(const T& theElement) const
{
	ListNode<T>* currentNode = m_firstNode;
	int index = 0; // 锟斤拷前锟节碉拷锟斤拷锟斤拷
	while (currentNode != nullptr && currentNode->m_element != theElement)
	{
		// 锟斤拷锟斤拷锟斤拷一锟斤拷锟节碉拷
		currentNode = currentNode->m_next;
		index++;
	}

	// 确锟斤拷锟角凤拷锟揭碉拷
	if (currentNode == nullptr) { return -1; }
	return index;
}

template <typename T>
void SingleLinkedList<T>::erase(int theIndex)
{
	check_index(theIndex);

	ListNode<T>* deleteNode;
	if (0 == theIndex) // 删锟斤拷锟斤拷锟斤拷锟阶节碉拷
	{
		deleteNode = m_firstNode;
		m_firstNode = m_firstNode->m_next;
	}
	else // 删锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟叫的节碉拷
	{
		// 锟斤拷锟斤拷删锟斤拷锟节碉拷锟角耙伙拷锟斤拷诘锟�
		ListNode<T>* prevNode = m_firstNode;
		for (int i = 0; i != theIndex - 1; ++i)
			prevNode = prevNode->m_next;

		deleteNode = prevNode->m_next;
		prevNode->m_next = prevNode->m_next->m_next;
	}
	m_listSize--; // 锟斤拷锟斤拷元锟截革拷锟斤拷锟斤拷1
	delete deleteNode;
}

template <typename T>
void SingleLinkedList<T>::insert(int theIndex, const T& theElement)
{
	// 锟斤拷锟斤拷锟斤拷锟�
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}

	if (0 == theIndex) // 锟斤拷锟斤拷锟斤拷头锟斤拷锟斤拷锟斤拷
	{
		m_firstNode = new ListNode<T>(theElement, m_firstNode);
	}
	else // 锟斤拷锟斤拷锟斤拷锟叫硷拷锟斤拷锟�
	{
		// 锟斤拷录锟斤拷锟斤拷位锟矫碉拷前锟斤拷
		ListNode<T>* prevNode = m_firstNode;
		for (int i = 0; i != theIndex - 1; ++i)
			prevNode = prevNode->m_next;

		// 锟斤拷prevNode之锟斤拷锟斤拷锟�
		prevNode->m_next = new ListNode<T>(theElement, prevNode->m_next);
	}
	m_listSize++; // 锟斤拷锟斤拷元锟斤拷锟斤拷锟斤拷锟斤拷1
}

template <typename T>
void SingleLinkedList<T>::check_index(int theIndex) const
{
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}
}

template <typename T>
void SingleLinkedList<T>::output(ostream& out) const
{
	for (ListNode<T>* currentNode = m_firstNode; currentNode != nullptr; currentNode = currentNode->m_next)
		out << currentNode->m_element << " ";
}

#endif // __SINGLELINKEDLIST_H__
