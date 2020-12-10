/*************************************************************************
> File Name       : SingleCircularLinkedList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月11日  09时55分03秒
************************************************************************/

#ifndef __SINGLECIRCULARLINKEDLIST_H__
#define __SINGLECIRCULARLINKEDLIST_H__

#include "LinearList.h"
#include <iostream>
#include <sstream>
#include "exception.h"

template <typename T>
class SingleCircularLinkedList : public LinearList<T>
{
	friend std::ostream& operator<<(std::ostream& out, const SingleCircularLinkedList<T>& theList)
	{
		theList.output(out);
		return out;
	}

protected:
	/**
	 * @brief 链表节点
	 *
	 * @tparam T
	 */
	template <typename Type>
	struct ListNode
	{
		Type m_element;
		ListNode<Type>* m_next;

		ListNode() : m_next(nullptr) { }

		ListNode(const Type& element) : m_element(element), m_next(nullptr) { }

		ListNode(const Type& element, ListNode<Type>* next)
			: m_element(element), m_next(next) { }
	};
public:
	SingleCircularLinkedList(int initialCapacity = 10);
	SingleCircularLinkedList(const SingleCircularLinkedList<T>& theList);

	SingleCircularLinkedList(SingleCircularLinkedList<T>&& theList) noexcept
		: m_firstNode(theList.m_firstNode), m_listSize(theList.m_listSize)
	{
		theList.m_firstNode = nullptr;
		theList.m_listSize = 0;
	}

	SingleCircularLinkedList& operator=(const SingleCircularLinkedList<T>& theList);
	SingleCircularLinkedList& operator=(SingleCircularLinkedList<T>&& theList) noexcept;

	~SingleCircularLinkedList()
	{
		if (!empty())
		{
			for (int i = 0; i < static_cast<int>(size()); ++i)
			{
				ListNode<T>* nextNode = m_firstNode->m_next;
				delete m_firstNode;
				m_firstNode = nextNode;
			}
		}
		m_firstNode = nullptr;
		m_listSize = 0;
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

		iterator(ListNode<T>* theNode = nullptr) : m_node(theNode) { }

		T& operator*() const { return m_node->m_element; }
		T* operator->() const { return &m_node->m_element; }

		// 递增运算符重载
		iterator& operator++() // 前置
		{
			m_node = m_node->m_next;
			return *this;
		}

		iterator operator++(int) // 后置
		{
			iterator old = *this;
			m_node = m_node->m_next;
			return old;
		}

		// 相等运算符
		bool operator!=(const iterator rhs) const { return m_node != rhs.m_node; }
		bool operator==(const iterator rhs) const { return m_node == rhs.m_node; }

	private:
		ListNode<T>* m_node;
	};

protected:
	void check_index(int theIndex) const;
	void output(ostream& out) const override;

	ListNode<T>* m_firstNode; // 链表头
	size_t m_listSize; // 链表元素数量
};

template <typename T>
SingleCircularLinkedList<T>::SingleCircularLinkedList(int initialCapacity)
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
SingleCircularLinkedList<T>::SingleCircularLinkedList(const SingleCircularLinkedList<T>& theList)
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
	while (sourceNode != theList.m_firstNode)
	{
		targetNode->m_next = new ListNode<T>(sourceNode->m_element);
		targetNode = targetNode->m_next;
		sourceNode = sourceNode->m_next;
	}
	targetNode->m_next = m_firstNode;
}

template <typename T>
SingleCircularLinkedList<T>& SingleCircularLinkedList<T>::operator=(const SingleCircularLinkedList<T>& theList)
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
			while (sourceNode != theList.m_firstNode)
			{
				targetNode->m_next = new ListNode<T>(sourceNode->m_element);
				targetNode = targetNode->m_next;
				sourceNode = sourceNode->m_next;
			}
			targetNode->m_next = m_firstNode;
		}
	}
	return *this;
}

template <typename T>
SingleCircularLinkedList<T>& SingleCircularLinkedList<T>::operator=(SingleCircularLinkedList<T>&& theList) noexcept
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
T& SingleCircularLinkedList<T>::get(int theIndex) const
{
	check_index(theIndex);

	ListNode<T>* currentNode = m_firstNode;
	for (int i = 0; i != theIndex; ++i) { currentNode = currentNode->m_next; }
	return currentNode->m_element;
}

template <typename T>
int SingleCircularLinkedList<T>::index_of(const T& theElement) const
{
	ListNode<T>* currentNode = m_firstNode;
	for (int i = 0; i != m_listSize; ++i)
	{
		if (currentNode->m_element == theElement)
			return i;
		currentNode = currentNode->m_next;
	}

	return -1;
}

template <typename T>
void SingleCircularLinkedList<T>::erase(int theIndex)
{
	check_index(theIndex);

	ListNode<T>* deleteNode;
	if (0 == theIndex) // 删除的是头节点
	{
		// 找到链表的最后一个节点
		ListNode<T>* lastNode = m_firstNode;
		for (int i = 0; i != m_listSize - 1; ++i)
			lastNode = lastNode->m_next;

		// 记录需要删除的节点，并更新首节点的位置
		deleteNode = m_firstNode;
		m_firstNode = m_firstNode->m_next;

		// 最后节点的next指向第一个节点
		lastNode->m_next = m_firstNode;
	}
	else // 删除中间节点
	{
		// 记录被删除节点的前一个节点
		ListNode<T>* prevNode = m_firstNode;
		for (int i = 0; i != theIndex - 1; ++i)
			prevNode = prevNode->m_next;

		deleteNode = prevNode->m_next;
		prevNode->m_next = prevNode->m_next->m_next;
	}
	m_listSize--;
	delete deleteNode;
}

template <typename T>
void SingleCircularLinkedList<T>::insert(int theIndex, const T& theElement)
{
	// 索引越界检查
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}

	if (0 == theIndex) // 在头节点前插入
	{
		m_firstNode = new ListNode<T>(theElement, m_firstNode);

		// 让最后节点的next指向新添加的头节点
		ListNode<T>* lastNode = m_firstNode;
		for (int i = 0; i != m_listSize; ++i)
			lastNode = lastNode->m_next; // 获取到最后一个节点
		lastNode->m_next = m_firstNode;
	}
	else // 在中间插入
	{
		//记录插入位置的前一个节点
		ListNode<T>* prevNode = m_firstNode;
		for (int i = 0; i != theIndex - 1; ++i)
			prevNode = prevNode->m_next;

		// 创建插入节点，并是前一个节点的next指向新的节点
		prevNode->m_next = new ListNode<T>(theElement, prevNode->m_next);
	}
	m_listSize++;
}

template <typename T>
void SingleCircularLinkedList<T>::check_index(int theIndex) const
{
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}
}

template <typename T>
void SingleCircularLinkedList<T>::output(ostream& out) const
{
	ListNode<T>* currentNode = m_firstNode;
	for (int i = 0; i != m_listSize; ++i)
	{
		out << currentNode->m_element << "_" << currentNode->m_next->m_element << " ";
		currentNode = currentNode->m_next;
	}
}

#endif // __SINGLECIRCULARLINKEDLIST_H__
