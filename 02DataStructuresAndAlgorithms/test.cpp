#include <iostream>
#include <functional>
#include <type_traits>

double my_divide(double x, double y)
{
	return x / y;
}

int main(int argc, char const *argv[])
{
	auto num = std::bind(my_divide, std::placeholders::_2, std::placeholders ::_1);
	std::cout << num(10, 2) << std::endl;
	std::cout << typeid(num).name() << std::endl;

	std::cout << "is_func" << std::is_function<decltype(my_divide)>::value << std::endl;
	std::cout << "is_class" << std::is_class<decltype(my_divide)>::value << std::endl;

	system("pause");

	return 0;
}
