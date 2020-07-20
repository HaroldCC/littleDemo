/*************************************************************************
> File Name       : testMatrix.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月13日  10时27分11秒
************************************************************************/
#include "Matrix.h"
#include <iostream>
using  std::cout;
using std::endl;

int main(int argc, char* argv[])
{
	try
	{
		Matrix<int> x(3, 2), y, z;
		int i, j;
		for (i = 1; i <= 3; i++)
			for (j = 1; j <= 2; j++)
				x(i, j) = 2 * i + j;
		cout << "Initialized x(i,j) = 2*i + j" << endl;
		cout << "x(3,1) = " << x(3, 1) << endl;
		cout << "x is" << endl;;
		cout << x << endl;

		y = x;
		cout << "Assigned y = x" << endl;
		cout << "y is" << endl;
		cout << y << endl;

		x += 2;
		cout << "x incremented by 2 is" << endl;
		cout << x << endl;

		z = y + x;
		cout << "y + x is" << endl;
		cout << z << endl;

		cout << "-(y + x) is" << endl;
		cout << -z << endl;

		Matrix<int> w(2, 3);
		for (i = 1; i <= 2; i++)
			for (j = 1; j <= 3; j++)
				w(i, j) = i + j;
		cout << "Initialized w(i,j) = i + j" << endl;
		cout << "w is" << endl;
		cout << w << endl;

		z = y * w;
		cout << "y:" << endl;
		cout << y << endl;
		cout << "w: " << endl;
		cout << w << endl;
		cout << "y * w is" << endl;
		cout << z << endl;
	}
	catch (...) {
		std::cerr << "An exception has occurred" << endl;
	}
}