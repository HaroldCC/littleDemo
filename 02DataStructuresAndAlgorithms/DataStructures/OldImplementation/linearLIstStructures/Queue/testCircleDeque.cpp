/*************************************************************************
> File Name       : testCircleDeque.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月07日  15时49分27秒
************************************************************************/

#include "CircleDeque.h"
#include <iostream>

using namespace std;

int main()
{
    CircleDeque<int> qu;
    //  9 8 7 6 5 4 3 2 1 101 102 103 104 105 106 107 108 109尾
    for (int i = 0; i < 10; i++)
    {
        qu.enQueueFront(i + 1);
        qu.enQueueRear(i + 100);
    }

    cout << qu << endl;

    for (int i = 0; i < 3; i++)
    {
        qu.deQueueFront();
        qu.deQueueRear();
    }

    qu.enQueueFront(11);
    qu.enQueueFront(12);
    cout << qu << endl;
    while (!qu.isEmpty())
    {
        cout << qu.deQueueFront() << endl;
    }

    return 0;
}