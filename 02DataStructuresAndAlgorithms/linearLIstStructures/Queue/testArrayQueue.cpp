/*************************************************************************
> File Name       : testArrayQueue.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  13时34分44秒
************************************************************************/
#include "arrayQueue.h"
#include <iostream>

using namespace std;

int main()
{
    arrayQueue<int> q(4);

    q.push(1);
    q.push(2);
    q.push(3);

    for (int i = 0; i < 10; i++)
    {
        q.push(i + 1);
        q.push(i + 100);
    }

    cout << q << endl;

    cout << q.back() << endl;
    q.pop();

    cout << q.back() << endl;
    q.pop();
    cout << q.back() << endl;
    q.pop();

    return 0;
}