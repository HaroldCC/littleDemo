/*************************************************************************
> File Name       : testBST.cpp
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月14日  13时33分43秒
************************************************************************/

/**
 * 二叉搜索树的测试
 */
#include <iostream>
#include "BinaryTree.h"
#include "BST.h"
using namespace std;

int main()
{
    BST<int> bst;

    for (int i = 0; i < 10; i++)
    {
        bst.add(i);
    }

    BinaryTree<int>::Visitor<int>(){
        bool visit(int element){
            std::cout << element << " " << std::endl;
    return element == 4 ? true : false;
}
}
;

bst.preorder();

return 0;
}