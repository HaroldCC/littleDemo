/*************************************************************************
> File Name       : testLinkedQueue.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  13时59分30秒
************************************************************************/

#include "linkedQueue.h"
#include <iostream>

using namespace std;

int main()
{
    linkedQueue<int> q(4);

    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;
    q.pop();

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();

    return 0;
}