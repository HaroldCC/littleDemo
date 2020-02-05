/*************************************************************************
    > File Name       : Cpp递增递减运算符重载.cpp
    > Author          : Harold
    > Mail            : 2106562095@qq.com
    > Github          : www.github.com/Haroldcc
    > Created Time    : 2020年02月05日 星期三 17时32分46秒
 ************************************************************************/

#include<iostream>
using namespace std;

class Num1
{
	private:
		int m_num1;
	public:
		Num1();
		Num1& operator++();    // 重载前置递增运算符
		Num1& operator--();    // 重载前置递减运算符
		Num1 operator++(int);     // 重载后置递增运算符
		Num1 operator--(int); // 重载后置递减运算符
		friend ostream& operator<< (ostream& os, const Num1& num);
};


Num1::Num1()
{
	m_num1 = 1;
}

Num1& Num1::operator++()
{
	m_num1++;
	return *this;
}

Num1& Num1::operator--()
{
	m_num1--;
	return *this;
}

Num1 Num1::operator++(int)
{
	Num1 temp = *this;       // 记录当前值
	m_num1++;
	return temp;
}

Num1 Num1::operator--(int)
{
	Num1 temp = *this;
	m_num1--;
	return temp;
}

ostream& operator<< (ostream& os, const Num1& n)
{
	os << n.m_num1 << endl;
	return os;
}


// 前置运算符测试
void forward_operator_test()
{
	Num1 num;
	cout << "前置运算符测试:\n"; 
	cout << "自增前 = " << num.m_num1;
	++num.m_num1;
	cout << "\t自增后 = " << num.m_num1 << endl;

}


void rear_operator_teat()
{
		Num1 num;
		cout << "后置运算符测试：\n";
		cout << "递减前 =" << num.m_num1;
		num.m_num1--;
		cout << "\t递减后 = " << num.m_num1 << endl;
}



int main(int argc,char *argv[])
{
	forward_operator_test();
	rear_operator_teat();
     
    return 0;
}
