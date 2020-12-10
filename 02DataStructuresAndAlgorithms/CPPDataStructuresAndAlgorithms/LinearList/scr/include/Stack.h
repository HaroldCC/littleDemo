/*************************************************************************
> File Name       : Stack.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020��07��13��  14ʱ43��20��
************************************************************************/
#ifndef __STACK_H__
#define __STACK_H__

/*ջ������������*/
template <typename T>
class Stack
{
public:
	virtual ~Stack() {}
	virtual bool empty() const = 0; // ջ�Ƿ�Ϊ��
	virtual size_t size() const = 0; // ջ��Ԫ�ظ���
	virtual void push(const T& theElement) = 0; // ��Ԫ��theElementѹ��ջ��
	virtual T& top() const = 0; // ����ջ��Ԫ������
	virtual void pop() = 0; // ɾ��ջ��Ԫ��
};

#endif // __STACK_H__
