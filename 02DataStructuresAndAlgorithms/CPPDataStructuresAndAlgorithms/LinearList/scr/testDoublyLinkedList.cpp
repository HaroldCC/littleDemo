/*************************************************************************
> File Name       : testDoublyLinkedList.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月10日  16时15分58秒
************************************************************************/

#include "DoublyLinkedList.h"
#include <iostream>
using std::cout;
using std::endl;

extern void testSingleLinkedList();

int main(int argc, char* argv[])
{
	//testSingleLinkedList();
	
	DoublyLinkedList<int> list1;
	cout << "默认构造：" << list1 << endl;

	list1.push_back(2);
	list1.insert(0, 1);
	list1.insert(2, 3);
	list1.insert(2, 4);
	cout << list1 << endl;
	DoublyLinkedList<int> list2(list1);
	cout << list2 << endl;
	cout << "list1 = " << list1 << "\n" << "list2 = " << list2 << endl;

	DoublyLinkedList<int> list3(std::move(list2));
	cout << "list3 = " << list3 << "\n" << "list2 = " << list2 << endl;

	DoublyLinkedList<int> list4 = list3;
	cout << "list3 = " << list3 << "\n" << "list4 = " << list4 << endl;

	DoublyLinkedList<int> list5 = std::move(list4);
	cout << "list4 = " << list4 << "\n" << "list5 = " << list5 << endl;

	cout << std::boolalpha << list5.empty() << std::noboolalpha << "list5.size() = " << list5.size() << endl;

	cout << list5.get(0) << " " << list5.get(2) << " " << list5.get(list5.size() - 1) << endl;

	cout << list5.index_of(1) << " " << list5.index_of(0) << " " << list5.index_of(list5.size() - 1) << endl;

	cout << "before erase: " << list5 << endl;
	list5.erase(0);
	cout << list5 << endl;
	list5.erase(list5.size() - 1);
	cout << list5 << endl;
	list5.erase(1);
	cout << list5 << endl;

	list5.clear();
	cout << list5 << endl;
}
