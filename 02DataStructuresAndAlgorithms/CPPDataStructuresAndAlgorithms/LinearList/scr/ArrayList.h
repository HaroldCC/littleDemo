/*************************************************************************
> File Name       : ArrayList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020��06��17��  18ʱ43��54��
************************************************************************/
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "LinearList.h"
#include "exception.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

/* ��̬����ķ���ʵ�� */
template <typename T>
class ArrayList : public LinearList<T>
{
public:
	const int ELEMENT_NOT_FOUND = -1;

private:
	T *m_elements;	   // �洢���Ա��һά����
	size_t m_capacity; // ��������
	size_t m_size;	   // ���������Ԫ�ظ���

	void check_index(int theIndex) const;	  // ����������飬��������Ч���׳��쳣
	void shrinkage_capacity(int oldCapacity); // ��������
	void expansion_capacity(int newCapacity); // ��������

public:
	//  ���캯�����������졢��������
	ArrayList(int initialCapacity = 10);
	ArrayList(const ArrayList<T> &);
	~ArrayList() { delete[] m_elements; }

	// ADT
	bool empty() const;								// ����գ�����true�����򷵻�false
	size_t size() const;							// �������Ա���Ԫ�صĸ���
	T &get(int theIndex) const;						// ��������ΪtheIndex��Ԫ������
	int index_of(const T &theElement) const;		// ����Ԫ��theElement��һ�γ��ֵ�����
	void erase(int theIndex);						// ɾ������ΪtheIndex��Ԫ��
	void insert(int theIndex, const T &theElement); // ��theElement�������Ա�������ΪtheIndex��λ��
	void output(ostream &out) const;				// ������Ա��е����ݣ������Ա���������out��

	// ��������
	size_t capacity() const;
	void clear() { m_size = 0; }

	//ArrayList����Ԫ�غ�β�������
	class iterator;
	iterator begin() { return iterator(m_elements); }
	iterator end() { return iterator(m_elements + m_size); }

	// ArrayList�ĵ���������
	class iterator
	{
	private:
		T *position; // ָ���Ԫ�ص�ָ��

	public:
		// ��C++��typedefʵ��˫�������
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;

		// ����
		iterator(T *thePosition = 0) { this->position = thePosition; }

		// �����ò�����
		T &operator*() const { return *(this->position); }
		T *operator->() const { return &*(this->position); }

		// ����������
		iterator &operator++()
		{
			++this->position;
			return *this;
		} // ǰ��
		iterator operator++(int)
		{
			iterator oldValue = *this;
			++this->position;
			return oldValue;
		} // ���

		// �������ݼ�
		iterator &operator--()
		{
			--this->position;
			return *this;
		} // ǰ��
		iterator operator--(int)
		{
			iterator oldValue = *this;
			--this->position;
			return oldValue;
		} // ���

		// �Ƿ����
		bool operator==(const iterator right) const { return this->position == right.position; }
		bool operator!=(const iterator right) const { return this->position != right.position; }
	};
};

// ˽�з���
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
	delete[] m_elements; // �ͷ�������Ŀռ�
	m_elements = temp;	 // ���������ͷָ��ָ�����ݺ������
}

template <typename T>
inline void ArrayList<T>::shrinkage_capacity(int oldCapacity)
{
	// ��������Ԫ�ظ���С��������һ��ʱ����������
	if (m_size < (oldCapacity / 2))
		// �˴���ʵ���ǵ������ݲ����ķ���������һ����С��������(��������ȥһ��)
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

	// ��theArrayList�е�Ԫ����һ����ArrayList
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

	// ʹ��theIndex�������ĺ�һ��Ԫ�ظ���theIndex����Ԫ��
	for (int i = theIndex + 1; i < m_size; ++i)
	{
		m_elements[i - 1] = m_elements[i];
	}

	// ����size��һ��������һ��T����������
	m_elements[--m_size].~T();

	shrinkage_capacity(m_capacity);
}

template <typename T>
inline void ArrayList<T>::insert(int theIndex, const T &theElement)
{
	// ���ڴ�ʱ������ֵ�����������size��
	// ���������������һ��λ�ò���Ԫ�أ�֮ǰ��check_index�����Ѿ���������
	if (theIndex < 0 || theIndex > m_size)
	{
		std::ostringstream exceptionMessage;
		exceptionMessage << "Index = " << theIndex << " size = " << m_size;
		throw illegalIndex(exceptionMessage.str());
	}

	if (m_capacity <= m_size)
	{
		// ����2��
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

// ����
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
