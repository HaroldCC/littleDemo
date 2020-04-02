/*************************************************************************
> File Name       : BST.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月14日  12时17分51秒
************************************************************************/
#ifndef BST_H_
#define BST_H_
#include <iostream>
#include "BinaryTree.h"

template <typename T>
class BST : public BinaryTree<T>
{
private:
    /**
     * 比较器：用于用户指定元素之间比较
     */
    template <typename T>
    class Comparator
    {
        virtual compare(const T &e1, const T &e2) = 0;
    };
    Comparator<T> comparator;

    void remove(Node<T> *node);
    Node<T> *node(const T &element); // 根据元素值获取节点
    int compare(const T &element1, const T &element2);

    void elementNotNullCheck(const T &element)
    {
        if (element == NULL)
        {
            std::cerr << "element must not be NULL" << std::endl;
        }
    }

public:
    BST() { BST(NULL); }
    BST(Comparator<T> comparator) { this->comparator = comparator; }
    ~BST() {}

    void add(const T &elelment);
    void remove(T &element);
    bool contains(const T &element);
};

template <typename T>
void BST<T>::add(const T &element)
{
    elementNotNullCheck();

    if (this->root == nullptr)
    {
        // 添加的第一个节点
        this->root = new Node<T>(element, NULL);
        this->size++;
        return;
    }

    //添加的不是第一个节点
    // 找到父节点
    Node<T> *parent = this->root;
    Node<T> *node = this->root;
    int cmp = 0;
    while (node != nullptr)
    {
        cmp = compare(element, node->element);
        parent = node;
        if (cmp > 0)
            node = node->right;
        else if (cmp < 0)
            node = node->left;
        else
        {
            node->element = element;
            return;
        }
    }

    // 看看插入到父节点的位置
    Node<T> *newNode = new Node<T>(element, parent);
    if (cmp > 0)
        parent->right = newNode;
    else
        parent->left = newNode;

    size++;
}

#endif