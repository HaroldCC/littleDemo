/*************************************************************************
> File Name       : SingleLinkedList2.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月08日  19时32分39秒
************************************************************************/
#ifndef __SINGLELINKEDLIST2_H__
#define __SINGLELINKEDLIST2_H__

#include "SingleLinkedList.h"

template <typename T>
class extendSingleLinkedList : public SingleLinkedList<T>, public extendedLinearList<T>
{
	friend std::ostream& operator<<(std::ostream& out, const extendSingleLinkedList<T>& theList)
	{
		theList.output(out);
		return out;
	}

public:
	// 构造与析构
	extendSingleLinkedList(int initialCapacity = 10) : SingleLinkedList<T>(initialCapacity), m_lastNode(nullptr)
	{
	}

	extendSingleLinkedList(const extendSingleLinkedList<T>& theList)
		: SingleLinkedList<T>(theList), m_lastNode(theList.m_lastNode)
	{
	}

	extendSingleLinkedList(extendSingleLinkedList&& theList) noexcept
		: SingleLinkedList<T>(std::move(theList)), m_lastNode(theList.m_lastNode)
	{
		theList.m_lastNode = nullptr;
	}

	extendSingleLinkedList& operator=(const extendSingleLinkedList<T>& theList);
	extendSingleLinkedList& operator=(extendSingleLinkedList<T>&& theList) noexcept;

	~extendSingleLinkedList()
	{
		m_lastNode = nullptr;
	}

	// ADT
	bool empty() const override { return SingleLinkedList<T>::m_listSize == 0; }
	size_t size() const override { return SingleLinkedList<T>::m_listSize; }
	T& get(int theIndex) const override { return SingleLinkedList<T>::get(theIndex); }
	int index_of(const T& theElement) const override { return SingleLinkedList<T>::index_of(theElement); }
	void erase(int theIndex) override;
	void insert(int theIndex, const T& theElement) override;
	void clear() override
	{
		while (SingleLinkedList<T>::m_firstNode != nullptr)
		{
			ListNode<T>* nextNode = SingleLinkedList<T>::m_firstNode->m_next;
			delete SingleLinkedList<T>::m_firstNode;
			SingleLinkedList<T>::m_firstNode = nextNode;
		}
		m_lastNode = nullptr;
		SingleLinkedList<T>::m_listSize = 0;
	}
	void push_back(const T& theElement) override;

private:
	void output(ostream& out) const override { SingleLinkedList<T>::output(out); }

	ListNode<T>* m_lastNode; // 链表最后一个节点的指针
};

template <typename T>
extendSingleLinkedList<T>& extendSingleLinkedList<T>::operator=(const extendSingleLinkedList<T>& theList)
{
	if (this != &theList)
	{
		SingleLinkedList<T>::operator=(theList);
		m_lastNode = theList.m_lastNode;
	}
	return *this;
}

template <typename T>
extendSingleLinkedList<T>& extendSingleLinkedList<T>::operator=(extendSingleLinkedList<T>&& theList) noexcept
{
	if (this != &theList)
	{
		SingleLinkedList<T>().operator=(std::move(theList));
		m_lastNode = theList.m_lastNode;
		theList.m_lastNode = nullptr;
	}
	return *this;
}

template <typename T>
void extendSingleLinkedList<T>::erase(int theIndex)
{
	SingleLinkedList<T>::check_index(theIndex);

	ListNode<T>* deleteNode;
	if (0 == theIndex)
	{
		deleteNode = SingleLinkedList<T>::m_firstNode;
		SingleLinkedList<T>::m_firstNode = SingleLinkedList<T>::m_firstNode->m_next;
	}
	else
	{
		ListNode<T>* prevNode = SingleLinkedList<T>::m_firstNode;
		for (int i = 0; i != theIndex - 1; ++i)
			prevNode = prevNode->m_next;

		deleteNode = prevNode->m_next;
		prevNode->m_next = prevNode->m_next->m_next;
		if (deleteNode == m_lastNode)
			m_lastNode = prevNode;
	}
	--SingleLinkedList<T>::m_listSize;
	delete deleteNode;
}

template <typename T>
void extendSingleLinkedList<T>::insert(int theIndex, const T& theElement)
{
	if (0 > theIndex || theIndex > SingleLinkedList<T>::m_listSize)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "index = " << theIndex << " size = " << SingleLinkedList<T>::m_listSize;
		throw illegalIndex(exceptionMessage.str());
	}

	if (0 == theIndex)
	{
		SingleLinkedList<T>::m_firstNode = new ListNode<T>(theElement, SingleLinkedList<T>::m_firstNode);
		if (0 == SingleLinkedList<T>::m_listSize)
			m_lastNode = SingleLinkedList<T>::m_firstNode;
	}
	else
	{
		ListNode<T>* prevNode = SingleLinkedList<T>::m_firstNode;
		for (int i = 0; i != theIndex - 1; ++i)
			prevNode = prevNode->m_next;

		prevNode->m_next = new ListNode<T>(theElement, prevNode->m_next);
		if (SingleLinkedList<T>::m_listSize == theIndex)
			m_lastNode = prevNode->m_next;
	}
	++SingleLinkedList<T>::m_listSize;
}

template <typename T>
void extendSingleLinkedList<T>::push_back(const T& theElement)
{
	ListNode<T>* newNode = new ListNode<T>(theElement, nullptr);
	if (SingleLinkedList<T>::m_firstNode == nullptr)
		SingleLinkedList<T>::m_firstNode = m_lastNode = newNode;
	else
	{
		m_lastNode->m_next = newNode;
		m_lastNode = newNode;
	}
	++SingleLinkedList<T>::m_listSize;
}

#endif // __SINGLELINKEDLIST2_H__
