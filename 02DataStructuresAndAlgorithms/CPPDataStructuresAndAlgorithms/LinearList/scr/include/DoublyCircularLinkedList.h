/*************************************************************************
> File Name       : DoublyCircularLinkedList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月12日  08时22分18秒
************************************************************************/
#ifndef __DOUBLYCIRCULARLINKEDLIST_H__
#define __DOUBLYCIRCULARLINKEDLIST_H__

#include "LinearList.h"
#include "exception.h"
#include <iostream>
#include <sstream>

/*双向链表泛化实现*/
template <typename T>
class DoublyCircularLinkedList : public extendedLinearList<T>
{
	friend std::ostream&
	operator<<(std::ostream& out, const DoublyCircularLinkedList<T>& theList)
	{
		theList.output(out);
		return out;
	}

private:
	/*双向链表的节点类*/
	template <typename Ty>
	struct ListNode
	{
		ListNode<Ty>* _prev;
		Ty _element;
		ListNode<Ty>* _next;

		ListNode() : _prev(nullptr), _element(0), _next(nullptr) {}

		ListNode(const Ty& element) : _prev(nullptr), _element(element), _next(nullptr) {}

		ListNode(ListNode<Ty>* prev, const Ty& element, ListNode<Ty>* next) : _prev(prev), _element(element),
		                                                                      _next(next) {}
	};

public:
	DoublyCircularLinkedList() : m_listSize(0), m_firstNode(nullptr), m_lastNode(nullptr) {}
	DoublyCircularLinkedList(const DoublyCircularLinkedList<T>& theList);

	DoublyCircularLinkedList(DoublyCircularLinkedList<T>&& theList) noexcept
		: m_listSize(theList.m_listSize), m_firstNode(theList.m_firstNode), m_lastNode(theList.m_lastNode)
	{
		theList.m_listSize = 0;
		theList.m_firstNode = theList.m_lastNode = nullptr;
	}

	DoublyCircularLinkedList& operator=(const DoublyCircularLinkedList<T>& theList);
	DoublyCircularLinkedList& operator=(DoublyCircularLinkedList<T>&& theList) noexcept;
	~DoublyCircularLinkedList() { clear(); }

	bool empty() const override { return 0 == m_listSize; }
	size_t size() const override { return m_listSize; }
	T& get(int theIndex) const override;
	int index_of(const T& theElement) const override;
	void erase(int theIndex) override;
	void insert(int theIndex, const T& theElement) override;
	void clear() override;
	void push_back(const T& theElement) override { insert(m_listSize, theElement); }

private:
	void output(ostream& out) const override;
	void check_index(int theIndex) const;

	ListNode<T>* get_node(int theIndex) const
	{
		ListNode<T>* theNode;
		if (theIndex < m_listSize / 2)
		{
			// 当需要获取的节点在链表前半部分
			theNode = m_firstNode;
			for (int i = 0; i != theIndex; ++i)
				theNode = theNode->_next;
		}
		else
		{
			// 当需要查找的节点在链表后半部分
			theNode = m_lastNode;
			for (int i = m_listSize - 1; i != theIndex; --i)
				theNode = theNode->_prev;
		}
		return theNode;
	}

	int m_listSize; // 链表中元素数量
	ListNode<T>* m_firstNode; // 链表头节点
	ListNode<T>* m_lastNode; // 链表尾节点
};


template <typename T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList(const DoublyCircularLinkedList<T>& theList)
{
	if (theList.m_firstNode == nullptr)
	{
		m_listSize = 0;
		m_firstNode = m_lastNode = nullptr;
	}
	else
	{
		m_listSize = theList.m_listSize;
		m_firstNode = new ListNode<T>(theList.m_firstNode->_element);
		ListNode<T>* sourceNode = theList.m_firstNode;
		ListNode<T>* targetNode = m_firstNode;
		ListNode<T>* temp = m_firstNode;
		while (sourceNode->_next != theList.m_firstNode)
		{
			targetNode->_next = new ListNode<T>(sourceNode->_next->_element);
			targetNode = targetNode->_next;
			sourceNode = sourceNode->_next;
			targetNode->_prev = temp;
			temp = temp->_next;
		}
		m_lastNode = targetNode;
		targetNode->_next = m_firstNode;
		m_firstNode->_prev = targetNode;
	}
}

template <typename T>
DoublyCircularLinkedList<T>& DoublyCircularLinkedList<T>::operator=(const DoublyCircularLinkedList<T>& theList)
{
	if (this != &theList)
	{
		clear();

		if (theList.m_firstNode == nullptr)
		{
			m_listSize = 0;
			m_firstNode = m_lastNode = nullptr;
		}
		else
		{
			m_listSize = theList.m_listSize;
			m_firstNode = new ListNode<T>(theList.m_firstNode->_element);
			ListNode<T>* sourceNode = theList.m_firstNode;
			ListNode<T>* targetNode = m_firstNode;
			ListNode<T>* temp = m_firstNode;
			while (sourceNode->_next != theList.m_firstNode)
			{
				targetNode->_next = new ListNode<T>(sourceNode->_next->_element);
				targetNode = targetNode->_next;
				sourceNode = sourceNode->_next;
				targetNode->_prev = temp;
				temp = temp->_next;
			}
			m_lastNode = targetNode;
			targetNode->_next = m_firstNode;
			m_firstNode->_prev = targetNode;
		}
	}
	return *this;
}

template <typename T>
DoublyCircularLinkedList<T>& DoublyCircularLinkedList<T>::operator=(DoublyCircularLinkedList<T>&& theList) noexcept
{
	if (this != &theList)
	{
		this->clear();

		m_firstNode = theList.m_firstNode;
		m_lastNode = theList.m_lastNode;
		m_listSize = theList.m_listSize;

		theList.m_firstNode = theList.m_lastNode = nullptr;
		theList.m_listSize = 0;
	}
	return *this;
}

template <typename T>
T& DoublyCircularLinkedList<T>::get(int theIndex) const
{
	check_index(theIndex);

	return get_node(theIndex)->_element;
}

template <typename T>
int DoublyCircularLinkedList<T>::index_of(const T& theElement) const
{
	ListNode<T>* currentNode = m_firstNode;
	int index = 0;
	for (int i = 0; i != m_listSize; ++i)
	{
		if (theElement == currentNode->_element)
			return i;
		currentNode = currentNode->_next;
	}

	return -1;
}

template <typename T>
void DoublyCircularLinkedList<T>::erase(int theIndex)
{
	check_index(theIndex);

	//@step1: 首先根据索引位置或许到要删除的节点
	ListNode<T>* deleteNode = get_node(theIndex);

	if (m_listSize == 1) { deleteNode = m_firstNode; }
	else
	{
		//@step2:记录删除节点的前驱和后继
		ListNode<T>* prevNode = deleteNode->_prev;
		ListNode<T>* nextNode = deleteNode->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;
		//@step3: 判断删除的节点位置
		if (0 == theIndex) // 删除的是第一个节点
		{
			m_firstNode = nextNode;
		}

		if (theIndex == m_listSize - 1) // 删除的是最后一个节点
		{
			m_lastNode = prevNode;
		}
	}

	delete deleteNode;
	--m_listSize;
}

template <typename T>
void DoublyCircularLinkedList<T>::insert(int theIndex, const T& theElement)
{
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}

	if (theIndex == m_listSize) // 在后面添加元素
	{
		ListNode<T>* oldLastNode = m_lastNode;
		m_lastNode = new ListNode<T>(oldLastNode, theElement, m_firstNode);
		if (oldLastNode == nullptr) // 插入的第一个节点
		{
			m_firstNode = m_lastNode;
			m_firstNode->_next = m_firstNode;
			m_firstNode->_prev = m_firstNode;
		}
		else
		{
			oldLastNode->_next = m_lastNode;
			m_firstNode->_prev = m_lastNode;
		}
	}
	else
	{
		ListNode<T>* nextNode = get_node(theIndex);
		ListNode<T>* prevNode = nextNode->_prev;
		ListNode<T>* newNode = new ListNode<T>(prevNode, theElement, nextNode);
		nextNode->_prev = newNode;

		prevNode->_next = newNode;

		if (0 == theIndex) // 添加的是第一个节点
		{
			m_firstNode = newNode;
		}
	}
	++m_listSize;
}

template <typename T>
void DoublyCircularLinkedList<T>::clear()
{
	ListNode<T>* deleteNode = m_firstNode;
	for (int i = 0; i != m_listSize; ++i)
	{
		ListNode<T>* nextNode = deleteNode->_next;
		delete deleteNode;
		deleteNode = nextNode;
	}
	m_firstNode = m_lastNode = nullptr;
	m_listSize = 0;
}

template <typename T>
void DoublyCircularLinkedList<T>::output(std::ostream& out) const
{
	ListNode<T>* current = m_firstNode;
	for (int i = 0; i != m_listSize; ++i)
	{
		out << current->_prev->_element << "_" << current->_element << "_" << current->_next->_element << " ";
		current = current->_next;
	}
}

template <typename T>
void DoublyCircularLinkedList<T>::check_index(int theIndex) const
{
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}
}

#endif // __DOUBLYCIRCULARLINKEDLIST_H__
