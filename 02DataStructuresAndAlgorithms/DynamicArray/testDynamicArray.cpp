#include <iostream>
#include "DynamicArray.h"

int main()
{
    DynamicArray<int> array_int;
    std::cout << "添加数据前：" /*<< array_int*/ << std::endl;
    array_int.showArray();

    for (int i = 0; i < 10; i++)
    {
        array_int.add(i);
    }

    std::cout << "添加数据后：" /*<< array_int*/ << std::endl;
    array_int.showArray();

    if(array_int.contains(5))
    {
        std::cout << "have 5" << std::endl;
    }
    else 
    {
        std::cout << "no 5" << std::endl;
    }

    std::cout << array_int.getVal(6) << std::endl;

    std::cout << array_int.indexOf(9) << std::endl;

    array_int.add(1);
    array_int.add(1);
    array_int.add(1);
    array_int.add(1);
    array_int.add(1);
    array_int.add(1);
    array_int.add(1);

    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.add(4, 5);
    array_int.showArray();

    // array_int.add(3, 4);
    // array_int.showArray();
    
    for (int i = 0; i < 22; i++)
    {
        array_int.removeByIndex(0);
    }
    array_int.showArray();

    return 0;
}