/*************************************************************************
> File Name       : 斐波那契数列.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月14日  13时59分18秒
************************************************************************/
#include <iostream>

/**
 * 斐波那契数列 
 * E:0 1 1 2 3 5 8 13 ...... 
 * Q:求第n个数的斐波那契数是多少？
 */

using namespace std;

// 方法一:
int fib1(int n)
{
    if (n <= 1)
        return n;

    return fib1(n - 1) + fib1(n - 2);
}

// 方法二：
int fib2(int n)
{
    if (n <= 1)
        return n;

    int first = 0;
    int second = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}

int main(int argc, char const *argv[])
{
    cout << fib1(5);
    cout << endl
         << fib2(5);

    system("pause");
    return 0;
}
