/*************************************************************************
> File Name       : BinarySearchTree.h
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年07月20日  09时59分09秒
************************************************************************/
#ifndef __BINARYSEARCHTREE_H__
#define __BINARYSEARCHTREE_H__

/*二叉搜索树*/
template <typename T>
class BinarySearchTree
{
private:
	/*二叉树节点类*/
	template <typename Ty>
	struct TreeNode
	{
		Ty _element;		   // 节点元素值
		TreeNode<Ty>* _left;   // 左子节点
		TreeNode<Ty>* _right;  // 右子节点
		TreeNode<Ty>* _parent; // 父节点

		TreeNode(const Ty& element, const TreeNode<Ty>* parent)
			: _element(element), _left(nullptr), _right(nullptr), _parent(parent) {}
	};

public:
	BinarySearchTree() : m_size(0), m_root(nullptr) {}
	~BinarySearchTree() {}

	int size() const { return m_size; }		   // 二叉搜索树元素个数
	bool empty() const { return m_size == 0; } // 二叉搜索树是否为空
	void clear();							   // 清空树
	void add(const T& theElement);			   // 向树中添加元素
	void remove(const T& theElement);		   // 删除树中指定元素
	bool contains(const T& theElement);		   // 书中是否包含元素

private:
	/*辅助函数*/

	/**
	 * \brief 比较两个元素的大小
	 * \param ele1 元素1
	 * \param ele2 元素2
	 * \return return == 0,ele1 == ele2; return > 0, ele1 > ele2; return < 0, ele1 < ele2.
	 */
	int compare(const T& ele1, const T& ele2) {}

private:
	int m_size;			 // 二叉树中元素个数
	TreeNode<T>* m_root; // 二叉树根节点
};

template <typename T>
void BinarySearchTree<T>::add(const T& theElement)
{
	// 添加的是第一个节点
	if (m_root == nullptr)
	{
		m_root = new TreeNode<T>(theElement, nullptr);
		++m_size;
		return;
	}

	// 添加的不是第一个节点
	TreeNode<T>* node = m_root;	  // 从父节点开始进行比较，找到要插入的节点位置
	TreeNode<T>* parent = m_root; // 记录插入节点的父节点
	int cmp = 0;				  // 保存新插入节点与二叉树节点进行比较的结果
	while (node != nullptr)
	{
		cmp = compare(theElement, node->_element);
		parent = node;

		if (cmp > 0)
		{
			node = node->_right;
		}
		else if (cmp < 0)
		{
			node = node->_left;
		}
		else
		{
			return;
		}
	}

	// 看看插入到父节点的左还是右
	TreeNode<T>* newNode = new TreeNode<T>(theElement, parent);
	if (cmp > 0)
	{
		parent->_right = newNode;
	}
	else
	{
		parent->_left = newNode;
	}
	++m_size;
}

#endif // __BINARYSEARCHTREE_H__
