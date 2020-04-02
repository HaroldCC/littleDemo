
/*************************************************************************
> File Name       : testQueue.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  10时29分46秒
************************************************************************/
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    queue<int> qu;
    qu.enQueue(11);
    qu.enQueue(22);
    qu.enQueue(33);

    std::cout << qu.top() << std::endl;
    qu.deQueue();

    std::cout << qu.top() << std::endl;
    qu.deQueue();

    std::cout << qu.top() << std::endl;
    qu.deQueue();

    std::cout << qu.top() << std::endl;
    qu.deQueue();

    std::cout << qu.top() << std::endl;
    qu.deQueue();

    return 0;
}