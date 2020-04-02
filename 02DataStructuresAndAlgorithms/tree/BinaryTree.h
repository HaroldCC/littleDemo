/*************************************************************************
> File Name       : BinaryTree.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月13日  14时01分14秒
************************************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <iostream>
#include <queue>

// 访问器，通过让用户传入指定的操作来遍历二叉树
template <typename T>
class Visitor
{
public:
    bool stop;

    /**
         *  用户在需要遍历二叉树时需要对此方法进行实现，
         * 达到用户需要的遍历操作
         */
    virtual bool visit(T element) = 0;
};

/** 
 * 二叉树
 */
template <typename T>
class BinaryTree : public Visitor<T>
{
protected: // 二叉树类需要被二叉搜索树继承，所以数据声明为protected
    int size;
    Node<T> *root; // 根节点

    /**
     * 二叉树节点类
     */
    template <typename T>
    class Node
    {
    public:
        T element;       // 存储的元素
        Node<T> *left;   // 左子节点
        Node<T> *right;  // 右子节点
        Node<T> *parent; // 父节点

        Node(T element, Node<T> parent)
        {
            this->element = element;
            this->parent = parent;
        }

        bool isLeaf()
        {
            return this->left == nullptr && this->right == nullptr;
        }

        bool hasTwoChildren()
        {
            return this->left != nullptr && this->right != nullptr;
        }
    };

    /**
     * 获取一个节点的前驱
     */
    Node<T> *predecessor(const Node<T> *node)
    {
        if (node == nullptr)
            return NULL;

        // 前驱节点在左子树当中
        Node<T> *p = node->left;
        if (p != nullptr)
        {
            while (p->right != nullptr)
                p = p->right;
            return p;
        }

        // 从父节点、祖父节点中寻找前驱节点
        while (node->parent != nullptr && node == node->parent->left)
            node = node->parent;

        return node->parent;
    }

    /**
     * 获取一个节点的后继
     */
    Node<T> *successor(const Node<T> *node)
    {
        if (node == nullptr)
            return NULL;

        Node<T> *p = node->right;
        if (p != nullptr)
        {
            while (p->left != nullptr)
                p = p->left;
            return p;
        }

        while (node->parent != nullptr && node == node->parent->right)
            node = node->parent;

        return node->parent;
    }

private:
    void preorder(const Node<T> *node, const Visitor<T> visitor);  // 前序遍历
    void inorder(const Node<T> *node, const Visitor<T> visitor);   // 中序
    void postorder(const Node<T> *node, const Visitor<T> visitor); // 后序

    int height(Node<T> *node)
    {
        if (node == nullptr)
            return 1 + std::max(height(node->left), height(node->right));
    }

public:
    BinaryTree()
    {
        this->root = nullptr;
        this->size = 0;
    }
    ~BinaryTree() {}

    void size() const { return this->size; }
    bool isEmpty() const { return this->size == 0; }
    void clear();
    bool isComplete() const; // 判断是否为完全二叉树
    int height() const;      // 求二叉树高度（使用迭代）
    int height2() const;     // 求二叉树高度（使用递归）

    void preorder(const Visitor<T> visitor);   // 前序遍历
    void inorder(const Visitor<T> visitor);    // 中序
    void postorder(const Visitor<T> visitor);  // 后续
    void levelOrder(const Visitor<T> visitor); // 层次

    //void output(std::ostream &out);
};

template <typename T>
void BinaryTree<T>::clear()
{
    while (this->root != nullptr)
    {
    }
    this->size = 0;
}

template <typename T>
bool BinaryTree<T>::isComplete() const
{
    if (this->root == nullptr)
        return false;

    std::queue<Node<T>> nodeQueue;
    nodeQueue.push(this->root);

    bool leaf = false;
    while (!nodeQueue.empty())
    {
        Node<T> *node = nodeQueue.front();
        nodeQueue.pop();

        if (leaf && !node->isLeaf())
            return false;

        if (node->left != nullptr)
            nodeQueue.push(node->left);
        else if (node->right != nullptr)
            return false;

        if (node->right != nullptr)
            nodeQueue.push(node->right);
        else
            leaf = true;
    }
    return true;
}

template <typename T>
int BinaryTree<T>::height() const
{
    if (this->root == nullptr)
        return 0;

    int height = 0;    // 二叉树高度
    int levelSize = 1; // 每一层的元素数量

    // 使用队列
    std::queue<Node<T>> nodeQueue;
    nodeQueue.push(this->root);

    while (!nodeQueue.empty())
    {
        Node<T> *node = nodeQueue.front();
        nodeQueue.pop();

        levelSize--;

        // 节点的左子节点不为空，左子节点入队
        if (node->left != nullptr)
            nodeQueue.push(node->left);

        // 节点的右子节点不为空，右子节点入队
        if (node->right != nullptr)
            nodeQueue.push(node->right);

        if (levelSize == 0) // 即将访问下一层
        {
            levelSize = nodeQueue.size();
            height++;
        }
    }
    return height;
}

template <typename T>
int BinaryTree<T>::height2() const
{
    return height(root);
}

template <typename T>
void BinaryTree<T>::preorder(const Visitor<T> visitor)
{
    if (visitor == NULL)
        return;
    preorder(this->root, visitor);
}
template <typename T>
void BinaryTree<T>::preorder(const Node<T> *node, const Visitor<T> visitor)
{
    if (node == nullptr || visitor.stop)
        return;

    visitor.stop = visitor.visit(node->element);
    preorder(node->left, visitor);
    preorder(node->right, visitor);
}

template <typename T>
void BinaryTree<T>::inorder(const Visitor<T> visitor)
{
    if (visitor == NULL)
        return;
    inorder(this->root, visitor);
}
template <typename T>
void BinaryTree<T>::inorder(const Node<T> *node, const Visitor<T> visitor)
{
    if (node == nullptr || visitor.stop)
        return;

    inorder(node->left, visitor);

    if (visitor.stop)
        return;
    visitor.stop = visitor.visit(node->element);
    inorder(node->right, visitor);
}

template <typename T>
void BinaryTree<T>::postorder(const Visitor<T> visitor)
{
    if (visitor == NULL)
        return;

    postorder(this->root, visitor);
}
template <typename T>
void BinaryTree<T>::postorder(const Node<T> *node, const Visitor<T> visitor)
{
    if (node == nullptr || visitor.stop)
        return;

    postorder(node->left, visitor);
    postorder(node->right, visitor);

    if (visitor.stop)
        return;
    visitor.stop = visitor.visit(node->element);
}

template <typename T>
void BinaryTree<T>::levelOrder(const Visitor<T> visitor)
{
    if (this->root == nullptr || visitor == NULL)
        return;

    std::queue<Node<T>> nodeQueue;
    nodeQueue.push(this->root);

    while (!nodeQueue.empty())
    {
        Node<T> *node = nodeQueue.front();
        nodeQueue.pop();

        if (visitor.visit(node->element)) // 将节点元素传给访问器
            return;                       // 如果为true，停止遍历

        if (node->left != nullptr)
            nodeQueue.push(node->left);

        if (node->right != nullptr)
            nodeQueue.push(node->right);
    }
}

// template <typename T>
// void BinaryTree<T>::output(std::ostream &out, const Node<T> *node)
// {
//     if (this->root == nullptr)
//         return;

//     out <<
// }

#endif