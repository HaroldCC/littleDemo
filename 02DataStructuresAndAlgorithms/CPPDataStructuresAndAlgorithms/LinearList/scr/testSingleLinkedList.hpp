/*************************************************************************
> File Name       : testSingleLinkedList.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月08日  17时00分06秒
************************************************************************/
#pragma once

#include <iostream>
#include <numeric> // has accumulate
#include "include/SingleLinkedList.h"
#include "include/SingleLinkedList2.h"

using namespace std;

void testSingleLinkedList()
{
	// create a SingleLinkedList
	SingleLinkedList<int> y;
	cout << y << endl;
	y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << y << endl;

	// test iterator
	cout << "Output using forward iterators pre and post ++" << endl;
	for (SingleLinkedList<int>::iterator i = y.begin();
		i != y.end(); ++i)
		cout << *i << "  ";
	cout << endl;
	for (SingleLinkedList<int>::iterator i = y.begin();
		i != y.end(); ++i)
	{
		cout << *i << "  ";
		*i += 1;
	}
	cout << endl;

	cout << "Incremented by 1 list is " << y << endl;

	// try out an STL algorithm
	int sum = accumulate(y.begin(), y.end(), 0);
	cout << "The sum of the elements is " << sum << endl;

	// 测试复制构造
	SingleLinkedList<int> z(y);
	cout << z << endl;

	// 测试赋值运算符
	SingleLinkedList<int> a;
	a = z;
	SingleLinkedList<int> b;
	SingleLinkedList<int> c;
	b = c;

	SingleLinkedList<int> m = z;
	cout << m << endl;
}

void testExtendSingleLinkedList()
{
	// create an extended chain
	extendSingleLinkedList<int> y;
	y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;

	// test iterator
	cout << "Ouput using forward iterators pre and post ++" << endl;
	for (extendSingleLinkedList<int>::iterator i = y.begin();
		i != y.end(); ++i)
		cout << *i << "  ";
	cout << endl;
	for (extendSingleLinkedList<int>::iterator i = y.begin();
		i != y.end(); ++i)
	{
		cout << *i << "  ";
		*i += 1;
	}
	cout << endl;

	cout << "Incremented by 1 list is " << y << endl;

	// try out an STL algorithm
	int sum = accumulate(y.begin(), y.end(), 0);
	cout << "The sum of the elements is " << sum << endl;

	// clear the chain and do a few appends
	y.clear();
	cout << y << endl;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	cout << "Appended 3 integers, list y should be 1 2 3" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << y << endl;

	y.insert(3, 4);
	y.insert(0, 0);
	cout << "List y should be 0 1 2 3 4" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << y << endl;

	y.erase(4);
	y.erase(0);
	y.push_back(6);
	cout << "List y should be 1 2 3 6" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << y << endl;

	extendSingleLinkedList<int> z = y;
	cout << "z : " << z << endl;

	extendSingleLinkedList<int> h(std::move(z));
	cout << "move: " << h << endl;

	cout << h.get(0) << endl;
	cout << h.index_of(8) << endl;

	cout << "y = " << y << endl;
	cout << "get(y):" << y.get(1) << endl;
	cout << y.get(0) << endl;
	cout << y.get(y.size() - 1) << endl;

	cout << "index_of : \n"
		<< y.index_of(0) << endl;
	cout << y.index_of(1) << endl;
	cout << y.index_of(6) << endl;
	y.erase(0);
	cout << y << endl;
}
