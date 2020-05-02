/*************************************************************************
> File Name       : iteratorsCategory.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年05月02日  06时45分04秒
************************************************************************/

/***** 各种容器的迭代器的分类 *****/
#include <iterator>
#include <array>
#include <vector>
#include <list>
#include <forward_list>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

void _display_category(std::random_access_iterator_tag)
{
    std::cout << "random_access_iterator" << std::endl;
}

void _display_category(std::bidirectional_iterator_tag)
{
    std::cout << "bidirectional_iteraotr" << std::endl;
}

void _display_category(std::forward_iterator_tag)
{
    std::cout << "forward_iterator" << std::endl;
}

void _display_category(std::output_iterator_tag)
{
    std::cout << "output_iterator" << std::endl;
}

void _display_category(std::input_iterator_tag)
{
    std::cout << "input_iterator" << std::endl;
}

template <typename I>
void display_category(I itr)
{
    typename std::iterator_traits<I>::iterator_category cagy;
    _display_category(cagy);

    std::cout << "typeid(itr).name()= " << typeid(itr).name() << std::endl
              << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "\n 测试STL中的迭代器分类：\n";

    display_category(std::array<int, 10>::iterator());
    display_category(std::vector<int>::iterator());
    display_category(std::list<int>::iterator());
    display_category(std::forward_list<int>::iterator());
    display_category(std::deque<int>::iterator());

    display_category(std::set<int>::iterator());
    display_category(std::map<int, int>::iterator());
    display_category(std::multiset<int>::iterator());
    display_category(std::multimap<int, int>::iterator());
    display_category(std::unordered_set<int>::iterator());
    display_category(std::unordered_map<int, int>::iterator());
    display_category(std::unordered_multiset<int>::iterator());
    display_category(std::unordered_multimap<int, int>::iterator());

    display_category(std::istream_iterator<int>());
    display_category(std::ostream_iterator<int>(std::cout, ""));

    system("pause");
    return 0;
}
