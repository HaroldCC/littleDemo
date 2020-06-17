/*************************************************************************
> File Name       : testStack.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月03日  15时14分31秒
************************************************************************/
#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(11);
    stack.push(22);
    stack.push(33);
    stack.push(44);

    std::cout << stack.top() << std::endl;
    stack.pop();

    std::cout << stack.top() << std::endl;
    stack.pop();

    std::cout << stack.top() << std::endl;
    stack.pop();

    std::cout << stack.top() << std::endl;
    stack.pop();

    std::cout << stack.top() << std::endl;
    stack.pop();

    return 0;
}
