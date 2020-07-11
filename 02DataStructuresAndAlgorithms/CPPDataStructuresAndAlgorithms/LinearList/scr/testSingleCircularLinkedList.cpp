/*************************************************************************
> File Name       : testSingleCircularLinkedList.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月11日  14时14分35秒
************************************************************************/
#include <iostream>
using std::cout;
using std::endl;
#include "SingleCircularLinkedList.h"

int main()
{
	// 默认构造
	SingleCircularLinkedList<int> list1;
	cout << "list1 = " << endl;

	// 插入
	list1.insert(0, 1);
	list1.insert(1, 2);
	list1.insert(2, 4);
	list1.insert(2, 3);

	// 拷贝构造
	SingleCircularLinkedList<int> list2(list1);
	cout << list2 << endl;

	// 移动构造
	SingleCircularLinkedList<int> list3(std::move(list2));
	// index_of()
	cout << list3 << "\n"
		<< "list3[1] = " << list3.index_of(1)
		<< " list[4] = " << list3.index_of(4) << " " << list3.index_of(0) << endl;

	// 赋值运算符
	SingleCircularLinkedList<int> list4 = list3;
	// get()
	cout << "list4[0] = " << list4.get(0) << " list4[4] = " << list4.get(list4.size() - 1);
	cout << "list4[2] = " << list4.get(2);

	// 移动赋值运算符
	SingleCircularLinkedList<int> list5 = std::move(list4);
	// empty() and erase()
	cout << std::boolalpha << list5.empty() << std::noboolalpha;
	list5.erase(0);
	list5.erase(list5.size() - 1);
	list5.erase(1);
	cout << list5.size() << " " << list5 << endl;

}
