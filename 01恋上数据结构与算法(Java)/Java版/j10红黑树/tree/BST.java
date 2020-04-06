/*************************************************************************
> File Name       : BST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月13日  11时51分45秒
************************************************************************/
package j10红黑树.tree;

import java.util.Comparator;

/**
 * BST:重构后的二叉搜索树
 */
@SuppressWarnings("unchecked")
public class BST<E> extends BinaryTree<E> {

    private Comparator<E> comparator;

    /**
     * 无参构造
     * 
     */
    public BST() {
        this(null);
    }

    /**
     * 构造函数：需要比较器
     * 
     * @param comparator
     */
    public BST(Comparator<E> comparator) {
        this.comparator = comparator;
    }

    public void add(E element) {
        elementNotNullCheck(element);

        if (root == null) {
            // 添加的第一个节点
            root = creatNode(element, null);
            size++;

            // 新添加节点之后的处理
            afterAdd(root);
            return;
        }

        // 添加的不是第一个节点
        // 找到父节点
        Node<E> parent = root;
        Node<E> node = root;
        int cmp = 0;
        while (node != null) {
            cmp = compare(element, node.element);
            parent = node;
            if (cmp > 0) {
                node = node.right;
            } else if (cmp < 0) {
                node = node.left;
            } else {
                node.element = element;
                return;
            }
        }

        // 看看插入到父节点的哪个位置
        Node<E> newNode = creatNode(element, parent);
        if (cmp > 0) {
            parent.right = newNode;
        } else {
            parent.left = newNode;
        }
        size++;

        // 新添加节点之后的处理
        afterAdd(newNode);
    }

    /**
     * 添加node之后的调整
     * 
     * @param node 新添加的节点
     */
    protected void afterAdd(Node<E> node) {
    }

    /**
     * 删除node结点之后
     * 
     * @param node 被删除的节点
     */
    protected void afterRemove(Node<E> node) {

    }

    public void remove(E element) {
        remove(node(element));
    }

    private void remove(Node<E> node) {
        if (node == null)
            return;

        size--;

        if (node.hasTwoChildren()) {// 度为2的节点
            // 找到后继节点
            Node<E> s = successor(node);
            // 用后继节点的值覆盖度为2的节点的值
            node.element = s.element;
            // 删除后继节点
            node = s;
        }

        // 删除node节点（node节点的度必然为0或1）
        Node<E> replacement = node.left != null ? node.left : node.right;

        if (replacement != null) {// node是度为1的节点
            // 更改parent
            replacement.parent = node.parent;
            // 更改parent的left、right的指向
            if (node.parent == null) {// node是度为1的节点并且是根节点
                root = replacement;
            } else if (node == node.parent.left) {
                node.parent.left = replacement;
            } else if (node == node.parent.right) {
                node.parent.right = replacement;
            }

            // 删除节点之后的处理
            afterRemove(node);
        } else if (node.parent == null) {// node是叶子节点，并且是根节点
            root = null;

            // 删除节点之后的处理
            afterRemove(node);
        } else {// node是叶子节点，但不是根节点
            if (node == node.parent.left) {
                node.parent.left = null;
            } else {
                node.parent.right = null;
            }

            // 删除节点之后的处理
            afterRemove(node);
        }

    }

    private Node<E> node(E element) {
        Node<E> node = root;
        while (node != null) {
            int cmp = compare(element, node.element);
            if (cmp == 0) {
                return node;
            }

            if (cmp > 0) {
                node = node.right;
            } else {
                node = node.left;
            }
        }
        return null;
    }

    public boolean contains(E element) {
        return node(element) != null;
    }

    /**
     * 比较
     * 
     * @param element1
     * @param element2
     * @return 当返回 == 0，两数相等；当返回 > 0,element1 > element2;当返回 < 0，element1 <
     *         element2;
     */
    private int compare(E element1, E element2) {
        if (comparator != null) {
            // 如果比较器不为空，使用比较器
            return comparator.compare(element1, element2);
        }

        // 如果比较器为空，强制给出自定义数据类型的比较方法
        return ((Comparable<E>) element1).compareTo(element2);

    }

    /**
     * 传入值为空异常检测 树中不存储 null 值
     * 
     * @param element
     */
    private void elementNotNullCheck(E element) {
        if (element == null) {
            throw new IllegalArgumentException("element must not be null");
        }
    }

}