/*************************************************************************
  > File Name       : exception.h
  > Author          : Harold
  > Mail            : 2106562095@qq.com
  > Github          : www.github.com/Haroldcc
  > Created Time    : 2020年06月18日  07时50分35秒
  ************************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <sstream>
#include <iostream>

class illegalParameterValue
{
private:
  std::string message;

public:
  illegalParameterValue() : message("Illegal Parameter Value.") {}
  illegalParameterValue(const std::string theMessage) : message(theMessage) {}
  void outputMessage() { std::cout << this->message << std::endl; }
  ~illegalParameterValue() {}
};

class illegalIndex
{
private:
  std::string message;

public:
  illegalIndex() : message("Illegal Index.") {}
  illegalIndex(const std::string theMessage) : message(theMessage) {}
  ~illegalIndex() {}
  void outputMessage() { std::cout << this->message << std::endl; }
};

#endif