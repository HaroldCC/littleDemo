/*************************************************************************
> File Name       : BinaryTreeNode.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月13日  14时57分42秒
************************************************************************/
#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_
#include <iostream>
using namespace std;
/**
 * 二叉树节点类
 */
template <typename T>
class BinaryTreeNode
{
    friend void Visit(BinaryTreeNode<T> *);
    friend void InOrder(BinaryTreeNode<T> *);
    friend void PreOrder(BinaryTreeNode<T> *);
    friend void PostOrder(BinaryTreeNode<T> *);
    friend void LevelOrder(BinaryTreeNode<T> *);

private:
    T element;
    BinaryTreeNode<T> *left;  // 左子节点
    BinaryTreeNode<T> *right; // 右子节点

public:
    BinaryTreeNode() { this->left = this->right = nullptr; }
    BinaryTreeNode(const T &element)
    {
        this->element = element;
        this->left = this->right = nullptr;
    }
    BinaryTreeNode(const T &element, BinaryTreeNode *l, BinaryTreeNode *r)
    {
        this->element = element;
        this->left = l;
        this->right = r;
    }
};

/**
 * 二叉树遍历方法
 */
template <typename T>
void Visit(BinaryTreeNode<T> *node)
{
    // 可以
    cout << node->element << " ";
}

#endif