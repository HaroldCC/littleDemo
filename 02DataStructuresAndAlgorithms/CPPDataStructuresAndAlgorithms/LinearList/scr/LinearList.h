/*************************************************************************
> File Name       : LinearList.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020��06��17��  17ʱ36��26��
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
	virtual bool empty() const = 0;                             // ����գ�����true�����򷵻�false
	virtual size_t size() const = 0;                            // �������Ա���Ԫ�صĸ���
	virtual T& get(int theIndex) const = 0;                     // ��������ΪtheIndex��Ԫ������
	virtual int index_of(const T& theElement) const = 0;        // ����Ԫ��theElement��һ�γ��ֵ�����
	virtual void erase(int theIndex) = 0;                       // ɾ������ΪtheIndex��Ԫ��
	virtual void insert(int theIndex, const T& theElement) = 0; // ��theElement�������Ա�������ΪtheIndex��λ��
	virtual void output(ostream& out) const = 0;                // ������Ա��е����ݣ������Ա���������out��
};

#endif
