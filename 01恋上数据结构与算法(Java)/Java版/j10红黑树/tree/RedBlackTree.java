/*************************************************************************
> File Name       : RedBlackTree.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月06日  09时05分41秒
************************************************************************/

package j10红黑树.tree;

import java.util.Comparator;

public class RedBlackTree<E> extends BBST<E> {
    private static final boolean RED = false;
    private static final boolean BLACK = true;

    public RedBlackTree() {
        this(null);
    }

    /**
     * 比较器：继承自父类
     * 
     * @param comparator
     */
    public RedBlackTree(Comparator<E> comparator) {
        super(comparator);
    }

    @Override
    protected Node<E> creatNode(E element, Node<E> parent) {
        return new RedBlackNode<>(element, parent);
    }

    /**
     * 红黑树节点类
     * 
     * @param <E>
     */
    private static class RedBlackNode<E> extends Node<E> {
        boolean color = RED;

        public RedBlackNode(E element, Node<E> parent) {
            super(element, parent);
        }

        @Override
        public String toString() {
            String str = " ";
            if (color == RED) {
                str = "R_";
            }
            return str + element.toString();
        }
    }

    /**
     * 节点染色：对红黑树的节点进行着色（将节点转换为红黑树的节点）
     * 
     * @param node  要染色的节点
     * @param color 要染的颜色
     * @return 染色后的节点
     */
    private Node<E> color(Node<E> node, boolean color) {
        if (node == null)
            return node;
        ((RedBlackNode<E>) node).color = color;
        return node;
    }

    /**
     * 染红
     * 
     * @param node 要染色的节点
     * @return 染色后的节点
     */
    private Node<E> red(Node<E> node) {
        return color(node, RED);
    }

    /**
     * 染黑
     * 
     * @param node 要染色的节点
     * @return 染色后的节点
     */
    private Node<E> black(Node<E> node) {
        return color(node, BLACK);
    }

    private boolean colorOf(Node<E> node) {
        // 红黑树空节点为黑色
        return node == null ? BLACK : ((RedBlackNode<E>) node).color;
    }

    private boolean isBlack(Node<E> node) {
        return colorOf(node) == BLACK;
    }

    private boolean isRed(Node<E> node) {
        return colorOf(node) == RED;
    }

    @Override
    protected void afterAdd(Node<E> node) {
        Node<E> parent = node.parent;

        // 添加的是根节点
        if (parent == null) {
            black(node);
            return;
        }

        // 如果父节点是黑色，直接返回
        if (isBlack(parent))
            return;

        // 叔父节点
        Node<E> uncle = parent.sibling();
        // 祖父节点
        Node<E> grand = parent.parent;
        if (isRed(uncle)) { // 叔父节点是红色 (上溢-LL-RR-LR-RL)
            black(parent);
            black(uncle);
            // 把祖父节点当作是新添加的节点
            afterAdd(red(grand));
            return;
        }

        // 叔父节点不是红色
        if (parent.isLeftChild()) { // L
            red(grand);
            if (node.isLeftChild()) { // LL
                black(parent);
                // red(grand);
                // rotateRight(grand);
            } else { // LR
                black(node);
                // red(grand);
                rotateLeft(parent);
                // rotateRight(grand);
            }
            rotateRight(grand);
        } else { // R
            red(grand);
            if (node.isLeftChild()) { // RL
                black(node);
                // red(grand);
                rotateRight(parent);
                // rotateLeft(grand);
            } else { // RR
                black(parent);
                // red(grand);
                // rotateLeft(grand);
            }
            rotateLeft(grand);
        }
    }

    @Override
    protected void afterRemove(Node<E> node) {

    }

}