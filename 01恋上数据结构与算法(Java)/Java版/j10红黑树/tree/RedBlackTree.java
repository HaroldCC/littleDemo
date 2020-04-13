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

        // 添加的是根节点 或者 上溢到达了根节点
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
        Node<E> grand = red(parent.parent);

        // 叔父节点是红色 (上溢-LL-RR-LR-RL)
        if (isRed(uncle)) {
            black(parent);
            black(uncle);
            // 把祖父节点当作是新添加的节点
            // afterAdd(red(grand));
            afterAdd(grand);
            return;
        }

        // 叔父节点不是红色
        if (parent.isLeftChild()) { // L
            // red(grand);
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
            // red(grand);
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
    /**
     * 无replacement参数（1个参数版本）
     */
    protected void afterRemove(Node<E> node) {
        // 如果删除的节点是红色
        // 或者 用以取代删除的子节点是红色
        if (isRed(node)) {
            black(node);
            return;
        }

        Node<E> parent = node.parent;

        // 删除的是根节点
        if (parent == null)
            return;

        // 删除的是黑色叶子节点【下溢】
        // 实际被删除的node是左还是右
        boolean left = parent.left == null || node.isLeftChild();
        Node<E> sibling = left ? parent.right : parent.left;
        if (left) { // 被删除的节点在左边，兄弟节点在右边
            if (isRed(sibling)) { // 兄弟节点是红色
                black(sibling);
                red(parent);
                rotateLeft(parent);
                // 更换兄弟
                sibling = parent.right;
            }

            // 兄弟节点必然是黑色
            if (isBlack(sibling.left) && isBlack(sibling.right)) {
                // 兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
                boolean isParentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (isParentBlack) {
                    afterRemove(parent);
                }
            } else { // 兄弟节点至少有1个红色子节点，向兄弟节点借元素
                if (isBlack(sibling.right)) {
                    // 兄弟节点的左边是黑色，兄弟要先左旋转
                    rotateRight(sibling);
                    sibling = parent.right;
                }

                color(sibling, colorOf(parent));
                black(sibling.right);
                black(parent);
                rotateLeft(parent);
            }
        } else { // 被删除的节点在右边，兄弟节点在左边

            if (isRed(sibling)) { // 兄弟节点是红色
                black(sibling);
                red(parent);
                rotateRight(parent);
                // 更换兄弟
                sibling = parent.left;
            }

            // 兄弟节点必然是黑色
            if (isBlack(sibling.left) && isBlack(sibling.right)) {
                // 兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
                boolean isParentBlack = isBlack(parent);
                black(parent);
                red(sibling);
                if (isParentBlack) {
                    afterRemove(parent);
                }
            } else { // 兄弟节点至少有1个红色子节点，向兄弟节点借元素
                if (isBlack(sibling.left)) {
                    // 兄弟节点的左边是黑色，兄弟要先左旋转
                    rotateLeft(sibling);
                    sibling = parent.left;
                }

                color(sibling, colorOf(parent));
                black(sibling.left);
                black(parent);
                rotateRight(parent);
            }
        }
    }

    /**
     * 有replacement参数版本（2个参数）
     */
    // protected void afterRemove(Node<E> node, Node<E> replacement) {
    // // 如果删除的节点是红色
    // if (isRed(node))
    // return;

    // // 用以取代node的子节点是红色
    // if (isRed(replacement)) {
    // black(replacement);
    // return;
    // }

    // Node<E> parent = node.parent;

    // // 删除的是根节点
    // if (parent == null)
    // return;

    // // 删除的是黑色叶子节点【下溢】
    // // 实际被删除的node是左还是右
    // boolean left = parent.left == null || node.isLeftChild();
    // Node<E> sibling = left ? parent.right : parent.left;
    // if (left) { // 被删除的节点在左边，兄弟节点在右边
    // if (isRed(sibling)) { // 兄弟节点是红色
    // black(sibling);
    // red(parent);
    // rotateLeft(parent);
    // // 更换兄弟
    // sibling = parent.right;
    // }

    // // 兄弟节点必然是黑色
    // if (isBlack(sibling.left) && isBlack(sibling.right)) {
    // // 兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
    // boolean isParentBlack = isBlack(parent);
    // black(parent);
    // red(sibling);
    // if (isParentBlack) {
    // afterRemove(parent, null);
    // }
    // } else { // 兄弟节点至少有1个红色子节点，向兄弟节点借元素
    // if (isBlack(sibling.right)) {
    // // 兄弟节点的左边是黑色，兄弟要先左旋转
    // rotateRight(sibling);
    // sibling = parent.right;
    // }

    // color(sibling, colorOf(parent));
    // black(sibling.right);
    // rotateLeft(parent);
    // }
    // } else { // 被删除的节点在右边，兄弟节点在左边

    // if (isRed(sibling)) { // 兄弟节点是红色
    // black(sibling);
    // red(parent);
    // rotateRight(parent);
    // // 更换兄弟
    // sibling = parent.left;
    // }

    // // 兄弟节点必然是黑色
    // if (isBlack(sibling.left) && isBlack(sibling.right)) {
    // // 兄弟节点没有1个红色子节点，父节点要向下跟兄弟节点合并
    // boolean isParentBlack = isBlack(parent);
    // black(parent);
    // red(sibling);
    // if (isParentBlack) {
    // afterRemove(parent, null);
    // }
    // } else { // 兄弟节点至少有1个红色子节点，向兄弟节点借元素
    // if (isBlack(sibling.left)) {
    // // 兄弟节点的左边是黑色，兄弟要先左旋转
    // rotateLeft(sibling);
    // sibling = parent.left;
    // }

    // color(sibling, colorOf(parent));
    // black(sibling.left);
    // rotateRight(parent);
    // }
    // }
    // }

}