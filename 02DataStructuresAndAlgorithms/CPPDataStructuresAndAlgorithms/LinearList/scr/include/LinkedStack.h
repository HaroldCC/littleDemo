/*************************************************************************
> File Name       : LinkedStack.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020��07��15��  15ʱ15��44��
************************************************************************/
#ifndef __LINKEDSTACK_H__
#define __LINKEDSTACK_H__

#include "Stack.h"
#include "exception.h"

/*����ջ*/
template<typename T>
class LinkedStack :public Stack<T>
{
private:
	/*����ڵ�*/
	template<typename  Ty>
	struct ListNode
	{
		Ty _element;
		ListNode<Ty>* _next;

		ListNode() :_element(0), _next(nullptr) {}
		ListNode(const Ty& element) :_element(element), _next(nullptr) {}
		ListNode(const Ty& element, ListNode<Ty>* next) :_element(element), _next(next) {}
	};
public:
	// ���죬����
	LinkedStack(int initialCapacity = 10) :m_top(nullptr), m_stackSize(0) {}
	LinkedStack(const LinkedStack<T>& theStack);
	LinkedStack(LinkedStack<T>&& theStack) noexcept;
	LinkedStack& operator=(const LinkedStack<T>& theStack);
	LinkedStack& operator=(LinkedStack<T>&& theStack) noexcept;
	~LinkedStack();

	bool empty() const override { return m_stackSize == 0; }
	size_t size() const override { return m_stackSize; }
	void push(const T& theElement) override
	{
		m_top = new ListNode<T>(theElement, m_top);
		++m_stackSize;
	}
	T& top() const override
	{
		if (m_stackSize == 0)throw stackEmpty();
		return m_top->_element;
	}
	void pop() override
	{
		if (0 == m_stackSize)
			throw stackEmpty();

		ListNode<T>* nextNode = m_top->_next;
		delete m_top;
		m_top = nextNode;
		--m_stackSize;
	}
private:
	ListNode<T>* m_top; // ջ��ָ��
	int m_stackSize; // ջ��Ԫ�ظ���
};

template <typename T>
LinkedStack<T>::LinkedStack(const LinkedStack<T>& theStack)
{
	m_stackSize = theStack.m_stackSize;
	if (m_stackSize == 0)
		m_top = nullptr;

	ListNode<T>* sourceNode = theStack.m_top;
	m_top = new ListNode<T>(sourceNode->_element);
	sourceNode = sourceNode->_next;
	ListNode<T>* targetNode = m_top;
	while (sourceNode != nullptr)
	{
		targetNode->_next = new ListNode<T>(sourceNode->_element);
		sourceNode = sourceNode->_next;
		targetNode = targetNode->_next;
	}
	targetNode->_next = nullptr;
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T>&& theStack) noexcept
	:m_top(theStack.m_top), m_stackSize(theStack.m_stackSize)
{
	theStack.m_stackSize = 0;
	theStack.m_top = nullptr;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& theStack)
{
	if (this != &theStack)
	{
		delete m_top;

		m_stackSize = theStack.m_stackSize;
		if (m_stackSize == 0)
			m_top = nullptr;

		ListNode<T>* sourceNode = theStack.m_top;
		m_top = new ListNode<T>(sourceNode->_element);
		sourceNode = sourceNode->_next;
		ListNode<T>* targetNode = m_top;
		while (sourceNode != nullptr)
		{
			targetNode->_next = new ListNode<T>(sourceNode->_element);
			sourceNode = sourceNode->_next;
			targetNode = targetNode->_next;
		}
		targetNode->_next = nullptr;
	}
	return *this;
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T>&& theStack) noexcept
{
	if (this != &theStack)
	{
		delete m_top;

		m_top = theStack.m_top;
		m_stackSize = theStack.m_stackSize;

		theStack.m_top = nullptr;
		theStack.m_stackSize = 0;
	}
	return *this;
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
	while (m_top != nullptr)
	{
		ListNode<T>* nextNode = m_top->_next;
		delete m_top;
		m_top = nextNode;
	}
	m_top = nullptr;
	m_stackSize = 0;
}

#endif // __LINKEDSTACK_H__
