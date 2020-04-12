/*************************************************************************
> File Name       : stack&queue.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月31日  15时04分15秒
************************************************************************/

/***** 使用list实现的栈和队列与stl默认使用的deque实现的栈和队列速度比较 *****/
#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>

#define TEST_NUM 10000 // 测试赋值的次数

// 时间测量工具类
#include <memory>
#include <chrono>

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;

public:
    Timer()
        : m_startTimePoint(std::chrono::high_resolution_clock::now()) {}

    ~Timer() { stop(); }

    void stop()
    {
        auto endTimePoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint)
                         .time_since_epoch()
                         .count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint)
                       .time_since_epoch()
                       .count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << "us (" << ms << "ms)\n";
    }
};

void test_listStack()
{
    Timer timer;
    std::stack<std::string, std::list<std::string>> str;
    char buf[10];
    for (long i = 0; i < TEST_NUM; i++)
    {
        snprintf(buf, 10, "%d", rand());
        str.push(std::string(buf));
    }
    std::cout << "listStack.size() = " << str.size() << std::endl;
    std::cout << "listStack.top() = " << str.top() << std::endl;
    str.pop();
    std::cout << "listStack.size() = " << str.size() << std::endl;
    std::cout << "listStack.top() = " << str.top() << std::endl;
}

void test_stack()
{
    Timer timer;
    std::stack<std::string> str;
    char buf[10];
    for (long i = 0; i < TEST_NUM; i++)
    {
        snprintf(buf, 10, "%d", rand());
        str.push(std::string(buf));
    }
    std::cout << "Stack.size() = " << str.size() << std::endl;
    std::cout << "Stack.top() = " << str.top() << std::endl;
    str.pop();
    std::cout << "Stack.size() = " << str.size() << std::endl;
    std::cout << "Stack.top() = " << str.top() << std::endl;
}

void test_listQueue()
{
    Timer timer;
    std::queue<std::string, std::list<std::string>> str;
    char buf[10];
    for (long i = 0; i < TEST_NUM; i++)
    {
        snprintf(buf, 10, "%d", rand());
        str.push(std::string(buf));
    }
    std::cout << "listQueue.size() = " << str.size() << std::endl;
    std::cout << "listQueue.front() = " << str.front() << std::endl;
    std::cout << "listQueue.back() = " << str.back() << std::endl;
    str.pop();
    std::cout << "listQueue.size() = " << str.size() << std::endl;
    std::cout << "listQueue.front() = " << str.front() << std::endl;
    std::cout << "listQueue.back() = " << str.back() << std::endl;
}

void test_queue()
{
    Timer timer;
    std::queue<std::string> str;
    char buf[10];
    for (long i = 0; i < TEST_NUM; i++)
    {
        snprintf(buf, 10, "%d", rand());
        str.push(std::string(buf));
    }
    std::cout << "Queue.size() = " << str.size() << std::endl;
    std::cout << "Queue.front() = " << str.front() << std::endl;
    std::cout << "Queue.back() = " << str.back() << std::endl;
    str.pop();
    std::cout << "Queue.size() = " << str.size() << std::endl;
    std::cout << "Queue.front() = " << str.front() << std::endl;
    std::cout << "Queue.back() = " << str.back() << std::endl;
}

int main()
{
    std::cout << "测试listStack......\n";
    test_listStack();
    std::cout << std::endl;

    std::cout << "测试STLstack......\n";
    test_stack();
    std::cout << std::endl;

    std::cout << "测试listQueue......\n";
    test_listQueue();
    std::cout << std::endl;

    std::cout << "测试STLqueue......\n";
    test_queue();
    std::cout << std::endl;

    system("pause");
    return 0;
}