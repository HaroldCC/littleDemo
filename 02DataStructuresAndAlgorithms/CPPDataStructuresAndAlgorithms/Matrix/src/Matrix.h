/*************************************************************************
> File Name       : Matrix.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月12日  15时31分34秒
************************************************************************/

#ifndef __MATRIX_H__
#define __MATRIX_H__

#include "exception.h"
#include <iostream>

/*矩阵*/
template <typename T>
class Matrix
{
	friend std::ostream& operator<<(std::ostream& out, const Matrix<T>& theMatrix)
	{
		int k = 0; // index into element array
		for (int i = 0; i < theMatrix.m_rows; i++)
		{
			// do row i
			for (int j = 0; j < theMatrix.m_columns; j++)
				out << theMatrix.m_element[k++] << "  ";

			// row i finished
			out << std::endl;
		}

		return out;
	}

public:
	// 构造，析构
	Matrix(int theRows = 0, int theColumns = 0);
	Matrix(const Matrix<T>& theMatrix);
	Matrix(Matrix<T>&& theMatrix) noexcept;
	Matrix<T>& operator=(const Matrix<T>& theMatrix);
	Matrix<T>& operator=(Matrix<T>&& theMatrix) noexcept;

	~Matrix()
	{
		delete[] m_element;
		m_element = nullptr;
		m_rows = m_columns = 0;
	}

	int rows() const { return m_rows; }
	int columns() const { return m_columns; }
	T& operator()(int i, int j) const; // 返回队元素element(i,j)的引用
	Matrix<T> operator+() const; // 取正
	Matrix<T> operator+(const Matrix<T>& theMatrix) const; // 矩阵加法
	Matrix<T> operator-() const; // 取负
	Matrix<T> operator-(const Matrix<T>& theMatrix) const; // 矩阵减法
	Matrix<T> operator*(const Matrix<T>& theMatrix) const; // 矩阵乘法
	Matrix<T>& operator+=(const T& theElement);
private:
	int m_rows, // 矩阵行数
		m_columns; // 矩阵列数
	T* m_element; // 数组
};

template <typename T>
Matrix<T>::Matrix(int theRows, int theColumns)
{
	//检验行数和列数的有效性
	if (m_rows < 0 || m_columns < 0)
		throw illegalParameterValue("Rows and columns must be >= 0.");
	if ((m_rows == 0 || m_columns == 0) && (m_rows != 0 || m_columns != 0))
		throw illegalParameterValue("Either both or neither rows and columns shouble be 0.");

	// 创建矩阵
	m_rows = theRows;
	m_columns = theColumns;
	m_element = new T[m_rows * m_columns];
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& theMatrix)
{
	// 创建矩阵
	m_rows = theMatrix.m_rows;
	m_columns = theMatrix.m_columns;
	m_element = new T[m_rows * m_columns];

	// 复制theMartix中的每一个元素
	std::copy(theMatrix.m_element, theMatrix.m_element + m_rows * m_columns, m_element);
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& theMatrix) noexcept
	: m_rows(theMatrix.m_rows), m_columns(theMatrix.m_columns), m_element(theMatrix.m_element)
{
	theMatrix.m_rows = 0;
	theMatrix.m_columns = 0;
	theMatrix.m_element = 0;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& theMatrix)
{
	if (this != &theMatrix)
	{
		delete[] m_element;

		m_rows = theMatrix.m_rows;
		m_columns = theMatrix.m_columns;
		m_element = new T[m_rows * m_columns];

		std::copy(theMatrix.m_element, theMatrix.m_element + m_rows * m_columns, m_element);
	}
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& theMatrix) noexcept
{
	if (this != &theMatrix)
	{
		m_rows = theMatrix.m_rows;
		m_columns = theMatrix.m_columns;
		m_element = theMatrix.m_element;

		theMatrix.m_rows = theMatrix.m_columns = 0;
		theMatrix.m_element = nullptr;
	}
	return *this;
}

template <typename T>
T& Matrix<T>::operator()(int i, int j) const
{
	if (i < 1 || i > m_rows || j < 1 || j > m_columns)
		throw matrixIndexOutOfBounds();

	// 矩阵的值存储在一维数组中
	return m_element[(i - 1) * m_columns + j - 1]; // 根据矩阵的坐标，返回映射到一维数组的值
}

template <typename T>
Matrix<T> Matrix<T>::operator+() const
{
	return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& theMatrix) const
{
	if (m_rows != theMatrix.m_rows || m_columns != theMatrix.m_columns)
		throw matrixSizeMismatch();

	Matrix<T> temp(m_rows, m_columns);
	for (int i = 0; i < m_rows * m_columns; ++i)
	{
		temp.m_element[i] = m_element[i] + theMatrix.m_element[i];
	}
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
	Matrix<T> temp(m_rows, m_columns);
	for (int i = 0; i < m_rows * m_columns; ++i)
	{
		temp.m_element[i] = -m_element[i];
	}
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& theMatrix) const
{
	if (m_rows != theMatrix.m_rows || m_columns != theMatrix.m_columns)
		throw matrixSizeMismatch();

	Matrix<T> temp(m_rows, m_columns);
	for (int i = 0; i < m_rows * m_columns; ++i)
	{
		temp.m_element[i] = m_element[i] - theMatrix.m_element[i];
	}
	return temp;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& theMatrix) const
{
	if (m_columns != theMatrix.m_rows)
		throw matrixSizeMismatch();

	Matrix<T> temp(m_rows, theMatrix.m_columns);

	// 定义矩阵*this，theMartix和temp的游标且初始化为（1，1）元素定位
	int cursorOfThis = 0, cursorOfTheMartix = 0, cursorOfTemp = 0;

	// 对所有i和j计算temp(i,j)
	for (int i = 1; i <= m_rows; ++i)
	{
		// 计算结果矩阵的第i行
		for (int j = 1; j <= theMatrix.m_columns; ++j)
		{
			// 计算temp(i,j)第一项
			T sum = m_element[cursorOfThis] * theMatrix.m_element[cursorOfTheMartix];

			// 累加其余所有项
			for (int k = 2; k <= m_columns; ++k)
			{
				++cursorOfThis; // *this中第i行的下一项
				cursorOfTheMartix += theMatrix.m_columns; // theMartix中第j列的下一项
				sum += m_element[cursorOfThis] * theMatrix.m_element[cursorOfTheMartix];
			}
			temp.m_element[cursorOfTemp++] = sum; // 存储在temp(i,j)

			// 从行的起点和下一列重新开始
			cursorOfThis -= m_columns - 1;
			cursorOfTheMartix = j;
		}
		// 从下一行和第一列重新开始
		cursorOfThis += m_columns;
		cursorOfTheMartix = 0;
	}
	return temp;
}

template <typename T>
Matrix<T>& Matrix<T>::operator+=(const T& theElement)
{
	for (int i = 0; i < m_rows * m_columns; ++i)
	{
		m_element[i] += theElement;
	}
	return *this;
}

#endif // __MATRIX_H__
