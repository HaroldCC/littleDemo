/*************************************************************************
> File Name       : doublyLinkedList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月09日  09时39分57秒
************************************************************************/

#ifndef __DOUBLYLINKEDLIST_H__
#define __DOUBLYLINKEDLIST_H__

#include "LinearList.h"
#include "exception.h"
#include <iostream>
#include <sstream>

/*双向链表泛化实现*/
template <typename T>
class DoublyLinkedList : public extendedLinearList<T>
{
	friend std::ostream&
	operator<<(std::ostream& out, const DoublyLinkedList<T>& theList)
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
	DoublyLinkedList() : m_listSize(0), m_firstNode(nullptr), m_lastNode(nullptr) {}
	DoublyLinkedList(const DoublyLinkedList<T>& theList);

	DoublyLinkedList(DoublyLinkedList<T>&& theList) noexcept
		: m_listSize(theList.m_listSize), m_firstNode(theList.m_firstNode), m_lastNode(theList.m_lastNode)
	{
		theList.m_listSize = 0;
		theList.m_firstNode = theList.m_lastNode = nullptr;
	}

	DoublyLinkedList& operator=(const DoublyLinkedList<T>& theList);
	DoublyLinkedList& operator=(DoublyLinkedList<T>&& theList) noexcept;
	~DoublyLinkedList() { clear(); }

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
void swap(const DoublyLinkedList<T>& lhs, const DoublyLinkedList<T>& rhs)
{
	using std::swap;
	swap(lhs.m_listSize, rhs.m_listSize);
	swap(lhs.m_firstNode, rhs.m_lastNode);
	swap(lhs.m_lastNode, rhs.m_lastNode);
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& theList)
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
		ListNode<T>* sourceNode = theList.m_firstNode->_next;
		ListNode<T>* targetNode = m_firstNode;
		while (sourceNode != nullptr)
		{
			targetNode->_next = new ListNode<T>(targetNode, sourceNode->_element, targetNode->_next);
			targetNode = targetNode->_next;
			sourceNode = sourceNode->_next;
		}
		m_lastNode = targetNode;
	}
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& theList)
{
	if (this != &theList)
	{
		this->clear();

		swap(*this, theList);
	}
	return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList<T>&& theList) noexcept
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
T& DoublyLinkedList<T>::get(int theIndex) const
{
	check_index(theIndex);

	return get_node(theIndex)->_element;
}

template <typename T>
int DoublyLinkedList<T>::index_of(const T& theElement) const
{
	ListNode<T>* currentNode = m_firstNode;
	int index = 0;
	while (currentNode != nullptr && currentNode->_element != theElement)
	{
		currentNode = currentNode->_next;
		index++;
	}

	if (currentNode == nullptr)
	{
		return -1;
	}
	return index;
}

template <typename T>
void DoublyLinkedList<T>::erase(int theIndex)
{
	check_index(theIndex);

	//@step1: 首先根据索引位置或许到要删除的节点
	ListNode<T>* deleteNode = get_node(theIndex);

	//@step2:记录删除节点的前驱和后继
	ListNode<T>* prevNode = deleteNode->_prev;
	ListNode<T>* nextNode = deleteNode->_next;

	//@step3: 判断删除的节点位置
	if (prevNode == nullptr) // 删除的是第一个节点
	{
		m_firstNode = nextNode;
	}
	else
	{
		prevNode->_next = nextNode;
	}

	if (nextNode == nullptr) // 删除的是最后一个节点
	{
		m_lastNode = prevNode;
	}
	else
	{
		nextNode->_prev = prevNode;
	}

	delete deleteNode;
	--m_listSize;
}

template <typename T>
void DoublyLinkedList<T>::insert(int theIndex, const T& theElement)
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
		m_lastNode = new ListNode<T>(oldLastNode, theElement, nullptr);
		if (oldLastNode == nullptr) // 插入的第一个节点
		{
			m_firstNode = m_lastNode;
		}
		else
		{
			oldLastNode->_next = m_lastNode;
		}
	}
	else
	{
		ListNode<T>* nextNode = get_node(theIndex);
		ListNode<T>* prevNode = nextNode->_prev;
		ListNode<T>* newNode = new ListNode<T>(prevNode, theElement, nextNode);
		nextNode->_prev = newNode;

		if (prevNode == nullptr) // 添加的是第一个节点
		{
			m_firstNode = newNode;
		}
		else
		{
			prevNode->_next = newNode;
		}
	}
	++m_listSize;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
	ListNode<T>* deleteNode = m_firstNode;
	while(deleteNode != nullptr)
	{
		ListNode<T>* nextNode = deleteNode->_next;
		delete deleteNode;
		deleteNode= nextNode;
	}
	m_firstNode = m_lastNode = nullptr;
	m_listSize = 0;
}

template <typename T>
void DoublyLinkedList<T>::output(std::ostream& out) const
{
	for (ListNode<T>* currentNode = m_firstNode; currentNode != nullptr; currentNode = currentNode->_next)
		out << currentNode->_element << " ";
}

template <typename T>
void DoublyLinkedList<T>::check_index(int theIndex) const
{
	if (0 > theIndex || theIndex > m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}
}

#endif // __DOUBLYLINKEDLIST_H__
