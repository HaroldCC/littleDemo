/*************************************************************************
> File Name       : testDoublyCircularLinkedLIst.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月12日  08时53分43秒
************************************************************************/
#pragma once
#include <iostream>

#include "include/DoublyCircularLinkedList.h"
using std::cout;
using std::endl;

extern void testArrayList();
extern void testDoublyLinkedList();
extern void testSingleCircularLinkedList();
extern void testSingleLinkedList();

void testDoublyCircularLinkedList()
{
	// 默认构造
	DoublyCircularLinkedList<int> list1;
	DoublyCircularLinkedList<int> b;
	b = list1;
	cout << list1.size() << " " << list1 << endl;

	list1.push_back(1);
	list1.push_back(4);
	list1.insert(0, 1);
	list1.insert(2, 2);
	list1.insert(3, 3);

	// 复制构造
	DoublyCircularLinkedList<int> list2(list1);
	cout << std::boolalpha << list2.empty() << " " << std::noboolalpha << list2 << endl;

	// 移动构造
	DoublyCircularLinkedList<int> list3(std::move(list2));
	cout << list3.index_of(0) << " " << list3.index_of(3) << " " << list3.index_of(4) << endl;

	// 赋值运算符
	DoublyCircularLinkedList<int> list4 = list3;
	list3 = list4;
	cout << list4.get(0) << " " << list4.get(3) << " " << list4.get(list4.size() - 1) << endl;

	// 移动赋值运算符
	DoublyCircularLinkedList<int> list5 = std::move(list4);
	list5.erase(0);
	list5.erase(list5.size() - 1);
	list5.erase(1);
	cout << list5 << endl;

	DoublyCircularLinkedList<int> list6;
	list6 = std::move(list5);
}
