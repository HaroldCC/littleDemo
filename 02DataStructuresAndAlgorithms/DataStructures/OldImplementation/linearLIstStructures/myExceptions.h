/*************************************************************************
> File Name       : myExceptions.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月26日  14时32分01秒
************************************************************************/

/***** 自定义的异常 *****/
#ifndef MYEXCEPTIONS_H
#define MYEXCEPTUONS_H

#include <iostream>
#include <string>

// 非法参数
class illegalParameterValue
{
private:
    std::string message;

public:
    illegalParameterValue(std::string theMessage = "参数值非法！") : message(theMessage) {}
    void outputMessage() { std::cout << message << std::endl; }
};

// 非法输入
class illegalInputData
{
private:
    std::string message;

public:
    illegalInputData(std::string theMessage = "非法数据输入！")
    {
        message = theMessage;
    }

    void outputMessage() { std::cout << message << std::endl; }
};

// 非法索引
class illegalIndex
{
private:
    std::string message;

public:
    illegalIndex(std::string theMessage = "非法索引！") : message(theMessage) {}
    void outputMessage() { std::cout << message << std::endl; }
};

// 矩阵索引超出范围
class matrixIndexOutOfBounds
{
private:
    std::string message;

public:
    matrixIndexOutOfBounds(std::string theMessage = "矩阵索引超出范围！")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};

// 矩阵大小不匹配
class matrixSizeMismatch
{
private:
    std::string message;

public:
    matrixSizeMismatch(std::string theMessage = "矩阵大小不匹配 !")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};

// 堆栈为空
class stackEmpty
{
private:
    std::string message;

public:
    stackEmpty(std::string theMessage = "空堆栈上的无效操作!")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};

// 队列为空
class queueEmpty
{
private:
    std::string message;

public:
    queueEmpty(std::string theMessage = "空队列上的无效操作!")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};

// 哈希表已满
class hashTableFull
{
private:
    std::string message;

public:
    hashTableFull(std::string theMessage = "哈希表已满!")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};

// 边缘重量未定义
class undefinedEdgeWeight
{
private:
    std::string message;

public:
    undefinedEdgeWeight(std::string theMessage = "未定义边缘权重!")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};

// 方法未定义
class undefinedMethod
{
private:
    std::string message;

public:
    undefinedMethod(std::string theMessage = "此方法未定义!")
    {
        message = theMessage;
    }
    void outputMessage() { std::cout << message << std::endl; }
};
#endif