#include <iostream>
#include <map>
#include <set>

int main()
{
    std::_Rb_tree<int, int, std::_Identity<int>,
                  std::less<int>>
        itree;
    std::cout << itree.empty() << std::endl;
    std::cout << itree.size() << std::endl;

    itree._M_insert_unique(3);
    itree._M_insert_unique(8);
    itree._M_insert_unique(5);
    itree._M_insert_unique(9);
    itree._M_insert_unique(13);
    itree._M_insert_unique(5);
    std::cout << itree.empty() << std::endl;
    std::cout << itree.size() << std::endl;
    std::cout << itree.count(5) << std::endl;

    itree._M_insert_equal(5);
    itree._M_insert_equal(5);
    std::cout << itree.size() << std::endl;
    std::cout << itree.count(5) << std::endl;

    std::cout << "ÄãºÃ" << std::endl;
    system("pause");
    return 0;
}
