/*************************************************************************
> File Name       : AVLTree.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月01日  14时57分51秒
************************************************************************/

package j09AVL树.tree;

import java.util.Comparator;

/**
 * AVLTree： AVL树继承二叉搜索树
 */
public class AVLTree<E> extends BST<E> {

    public AVLTree() {
        this(null);
    }

    /**
     * 比较器：继承自父类
     * 
     * @param comparator
     */
    public AVLTree(Comparator<E> comparator) {
        super(comparator);
    }

    /**
     * AVL树中需要计算平衡因子，因此需要记录树的高度
     * 
     * @param <E>
     */
    private static class AVLNode<E> extends Node<E> {
        int height = 1; // 树高度

        public AVLNode(E element, Node<E> parent) {
            super(element, parent);
        }

        /**
         * 计算AVL树的平衡因子
         * 
         * @return 平衡因子
         */
        public int balanceFactor() {
            int leftHeight = left == null ? 0 : ((AVLNode<E>) left).height;
            int rightHeight = right == null ? 0 : ((AVLNode<E>) right).height;
            return leftHeight - rightHeight;
        }

        public void updateHeight() {
            int leftHeight = left == null ? 0 : ((AVLNode<E>) left).height;
            int rightHeight = right == null ? 0 : ((AVLNode<E>) right).height;
            height = 1 + Math.max(leftHeight, rightHeight);
        }

        public Node<E> tallerChild() {
            int leftHeight = left == null ? 0 : ((AVLNode<E>) left).height;
            int rightHeight = right == null ? 0 : ((AVLNode<E>) right).height;
            if (leftHeight > rightHeight)
                return left;
            if (leftHeight < rightHeight)
                return right;
            return isLeftChild() ? left : right;
        }

        @Override
        public String toString() {
            String parentString = "null";
            if (parent != null) {
                parentString = parent.element.toString();
            }
            return element + "_p(" + parentString + ")_h(" + height + ")";
        }
    }

    @Override
    protected Node<E> creatNode(E element, Node<E> parent) {
        return new AVLNode<>(element, parent);
    }

    /**
     * 判断是否平衡
     * 
     * @param node
     * @return
     */
    private boolean isBalanced(Node<E> node) {
        return Math.abs(((AVLNode<E>) node).balanceFactor()) <= 1;
    }

    private void updateHeight(Node<E> node) {
        ((AVLNode<E>) node).updateHeight();
    }

    /**
     * 恢复平衡
     * 
     * @param node 高度最低的不平衡节点
     */
    @SuppressWarnings("unused")
    private void rebalance2(Node<E> grand) {
        Node<E> parent = ((AVLNode<E>) grand).tallerChild();
        Node<E> node = ((AVLNode<E>) parent).tallerChild();

        // 旋转方向判断
        if (parent.isLeftChild()) { // 左子树
            if (node.isLeftChild()) { // LL
                rotateRight(grand);
            } else { // LR
                rotateLeft(parent);
                rotateRight(grand);
            }
        } else { // 右子树
            if (node.isLeftChild()) { // RL
                rotateRight(parent);
                rotateLeft(grand);
            } else {// RR
                rotateLeft(grand);
            }
        }
    }

    /**
     * 恢复平衡统一旋转操作
     * 
     * @param grand
     */
    private void rebalance(Node<E> grand) {
        Node<E> parent = ((AVLNode<E>) grand).tallerChild();
        Node<E> node = ((AVLNode<E>) parent).tallerChild();

        // 旋转方向判断
        if (parent.isLeftChild()) { // 左子树
            if (node.isLeftChild()) { // LL
                rotate(grand, node.left, node, node.right, parent, parent.right, grand, grand.right);
            } else { // LR
                rotate(grand, parent.left, parent, node.left, node, node.right, grand, grand.right);
            }
        } else { // 右子树
            if (node.isLeftChild()) { // RL
                rotate(grand, grand.left, grand, node.left, node, node.right, parent, parent.right);
            } else {// RR
                rotate(grand, grand.left, grand, parent.left, parent, node.left, node, node.right);
            }
        }
    }

    private void rotate(Node<E> r, // 子树的根节点
            Node<E> a, Node<E> b, Node<E> c, //
            Node<E> d, //
            Node<E> e, Node<E> f, Node<E> g) {
        // 让d成为这棵树的根节点
        d.parent = r.parent;
        if (r.isLeftChild()) {
            r.parent.left = d;
        } else if (r.isRightChild()) {
            r.parent.right = d;
        } else {
            root = d;
        }

        // a-b-c
        b.left = a;
        if (a != null)
            a.parent = b;
        b.right = c;
        if (c != null)
            c.parent = b;
        updateHeight(b);

        // e-f-g
        f.left = e;
        if (e != null)
            e.parent = f;
        f.right = g;
        if (g != null)
            g.parent = f;
        updateHeight(f);

        // b-d-f
        d.left = b;
        d.right = f;
        b.parent = d;
        f.parent = d;
        updateHeight(d);
    }

    /**
     * 左旋
     * 
     * @param node
     */
    private void rotateLeft(Node<E> grand) {
        Node<E> parent = grand.right;
        Node<E> child = parent.left;
        grand.right = child;
        parent.left = grand;

        afterRotate(grand, parent, child);

    }

    /**
     * 右旋
     * 
     * @param node
     */
    private void rotateRight(Node<E> grand) {
        Node<E> parent = grand.left;
        Node<E> child = parent.right;
        grand.left = child;
        parent.right = grand;

        afterRotate(grand, parent, child);
    }

    private void afterRotate(Node<E> grand, Node<E> parent, Node<E> child) {
        // 让parent成为子树的根节点
        parent.parent = grand.parent;
        if (grand.isLeftChild()) {
            grand.parent.left = parent;
        } else if (grand.isRightChild()) {
            grand.parent.right = parent;
        } else { // grand是根节点
            root = parent;
        }

        // 更新child的parent
        if (child != null) {
            child.parent = grand;
        }

        // 更新grand的parent
        grand.parent = parent;

        // 更新高度
        updateHeight(grand);
        updateHeight(parent);
    }

    @Override
    protected void afterAdd(Node<E> node) {
        while ((node = node.parent) != null) {
            if (isBalanced(node)) {// node是否平衡
                // 更新高度
                updateHeight(node);
            } else {
                // 恢复平衡
                rebalance(node);

                // 整棵树恢复平衡
                break;
            }
        }
    }

    @Override
    protected void afterRemove(Node<E> node) {
        while ((node = node.parent) != null) {
            if (isBalanced(node)) {// node是否平衡
                // 更新高度
                updateHeight(node);
            } else {
                // 恢复平衡
                rebalance(node);
            }
        }
    }

}