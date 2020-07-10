/*************************************************************************
> File Name       : LinearList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020��07��08��  22ʱ46��59��
************************************************************************/
#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>
using std::ostream;

/* ���Ա�ĳ��������������� */
template <typename T>
class LinearList
{
private:
public:
	virtual ~LinearList() {};
	virtual bool empty() const = 0;								// ����գ�����true�����򷵻�false
	virtual size_t size() const = 0;							// �������Ա���Ԫ�صĸ���
	virtual T& get(int theIndex) const = 0;						// ��������ΪtheIndex��Ԫ������
	virtual int index_of(const T& theElement) const = 0;		// ����Ԫ��theElement��һ�γ��ֵ�����
	virtual void erase(int theIndex) = 0;						// ɾ������ΪtheIndex��Ԫ��
	virtual void insert(int theIndex, const T& theElement) = 0; // ��theElement�������Ա�������ΪtheIndex��λ��
	virtual void output(ostream& out) const = 0;				// ������Ա��е����ݣ������Ա���������out��
};

/*���Ա����չ*/
template <typename T>
class extendedLinearList : public LinearList<T>
{
public:
	virtual ~extendedLinearList() = default;
	virtual void clear() = 0;						 // ������Ա�
	virtual void push_back(const T& theElement) = 0; // ��Ԫ��theElement�嵽��β
};
#endif
