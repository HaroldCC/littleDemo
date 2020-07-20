/*************************************************************************
  > File Name       : exception.h
  > Author          : Harold
  > Mail            : 2106562095@qq.com
  > Github          : www.github.com/Haroldcc
  > Created Time    : 2020��06��18��  07ʱ50��35��
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
	illegalParameterValue(const std::string& theMessage) : message(theMessage) {}
	void outputMessage() const { std::cout << this->message << std::endl; }
	~illegalParameterValue() = default;
};

class illegalIndex
{
private:
	std::string message;

public:
	illegalIndex() : message("Illegal Index.") {}
	illegalIndex(const std::string& theMessage) : message(theMessage) {}
	~illegalIndex() = default;
	void outputMessage() const { std::cout << this->message << std::endl; }
};

class matrixIndexOutOfBounds
{
public:
	matrixIndexOutOfBounds
	(std::string theMessage = "Matrix index out of bounds")
	{
		message = theMessage;
	}

	void outputMessage()const { std::cout << message << std::endl; }
private:
	std::string message;
};

// matrix size mismatch
class matrixSizeMismatch
{
public:
	matrixSizeMismatch(std::string theMessage =
		"The size of the two matrixes doesn't match")
	{
		message = theMessage;
	}

	void outputMessage()const { std::cout << message << std::endl; }
private:
	std::string message;
};

#endif
