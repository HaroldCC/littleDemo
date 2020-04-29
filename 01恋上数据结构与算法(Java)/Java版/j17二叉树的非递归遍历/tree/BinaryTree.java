/*************************************************************************
> File Name       : BinaryTree.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月13日  11时30分54秒
************************************************************************/
package j17二叉树的非递归遍历.tree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

import j17二叉树的非递归遍历.printer.BinaryTreeInfo;

/**
 * BinaryTree
 */
@SuppressWarnings("unchecked")
public class BinaryTree<E> implements BinaryTreeInfo {

    protected int size;
    protected Node<E> root;// 根节点

    protected static class Node<E> {
        E element; // 存储的元素
        Node<E> left; // 左子节点
        Node<E> right; // 右子节点
        Node<E> parent; // 父节点

        public Node(E element, Node<E> parent) {
            this.element = element;
            this.parent = parent;
        }

        public boolean isLeaf() {
            return left == null && right == null;
        }

        public boolean hasTwoChildren() {
            return left != null && right != null;
        }
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void clear() {
        root = null;
        size = 0;
    }

    /**
     * 访问器：通过让用户指定需要遍历二叉树所进行的具体操作
     * 
     * @param <E>
     */
    public static abstract class Visitor<E> {
        boolean stop;

        /**
         * 
         * @param element
         * @return 如果返回true，就代表停止遍历
         */
        public abstract boolean visit(E element);
    }

    /**
     * 二叉树前序遍历：使用访问器
     * 
     * @param visitor
     */
    public void preorder(Visitor<E> visitor) {
        if (visitor == null || root == null)
            return;

        Node<E> node = root;
        Stack<Node<E>> stack = new Stack<>();
        while (true) {
            if (node != null) {
                // 访问node节点
                if (visitor.visit(node.element))
                    return;
                // 将右子节点入栈
                if (node.right != null) {
                    stack.push(node.right);
                }
                // 向左走
                node = node.left;
            } else if (stack.isEmpty()) {
                return;
            } else {
                node = stack.pop();
            }
        }
    }

    /**
     * 二叉树中序遍历：使用访问器
     * 
     * @param visitor
     */
    public void inorder(Visitor<E> visitor) {
        if (visitor == null || root == null)
            return;

        Node<E> node = root;
        Stack<Node<E>> stack = new Stack<>();

        while (true) {
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else if (stack.isEmpty()) {
                return;
            } else {
                node = stack.pop();
                // 访问node节点
                if (visitor.visit(node.element))
                    return;
                // 让右节点进行中序遍历
                node = node.right;
            }
        }
    }

    /**
     * 二叉树后序遍历：使用访问器
     * 
     * @param visitor
     */
    public void postorder(Visitor<E> visitor) {
        if (visitor == null || root == null)
            return;

        // 记录上一次弹出访问的节点
        Node<E> prev = null;
        Stack<Node<E>> stack = new Stack<>();
        stack.push(root);
        while (!stack.isEmpty()) {
            Node<E> top = stack.peek();
            if (top.isLeaf() || prev != null && prev.parent == top) {
                prev = stack.pop();
                // 访问节点
                if (visitor.visit(prev.element))
                    return;
            } else {
                if (top.right != null) {
                    stack.push(top.right);
                }
                if (top.left != null) {
                    stack.push(top.left);
                }
            }
        }
    }

    /**
     * 二叉树层次遍历：使用访问器
     * 
     * @param visitor
     */
    public void levelOrder(Visitor<E> visitor) {
        if (root == null || visitor == null)
            return;

        // 使用队列
        Queue<Node<E>> queue = new LinkedList<>();
        queue.offer(root); // 根节点入队

        while (!queue.isEmpty()) {
            Node<E> node = queue.poll();// 头节点出队

            // System.out.println(node.element); // 访问出队的二叉树节点
            if (visitor.visit(node.element))// 将节点元素传给访问器
                return;// 如果为true，停止遍历

            // 节点的左子节点不为空，左子节点入队
            if (node.left != null) {
                queue.offer(node.left);
            }

            // 节点的右子节点不为空，右子节点入队
            if (node.right != null) {
                queue.offer(node.right);
            }
        }
    }

    /**
     * 判断是否为一棵完全二叉树（使用层次遍历）
     *
     * @return 判断结果
     */
    public boolean isComplete() {
        if (root == null)
            return false;

        Queue<Node<E>> queue = new LinkedList<>();
        queue.offer(root);

        boolean leaf = false;
        while (!queue.isEmpty()) {
            Node<E> node = queue.poll();

            if (leaf && !node.isLeaf())
                return false;

            if (node.left != null) {
                queue.offer(node.left);
            } else if (node.right != null) {
                return false; // node的左为空，右不为空
            }

            if (node.right != null) {
                queue.offer(node.right);
            } else {
                // 这里包含下面两种情况：
                // (node.left == null && node.right == null)
                // (node.left != null && node.right == null)
                // 即 node.right == null
                leaf = true;
            }
        }
        return true;
    }

    /**
     * 迭代求二叉树高度（使用层次遍历）
     * 
     * @return 二叉树高度
     */
    public int height() {
        if (root == null)
            return 0;

        int height = 0; // 二叉树高度
        int levelSize = 1; // 每一层元素的数量

        // 使用队列
        Queue<Node<E>> queue = new LinkedList<>();
        queue.offer(root); // 根节点入队

        while (!queue.isEmpty()) {
            Node<E> node = queue.poll();// 头节点出队
            levelSize--;

            // 节点的左子节点不为空，左子节点入队
            if (node.left != null) {
                queue.offer(node.left);
            }

            // 节点的右子节点不为空，右子节点入队
            if (node.right != null) {
                queue.offer(node.right);
            }

            if (levelSize == 0) {// 即将访问下一层
                levelSize = queue.size();
                height++;
            }
        }
        return height;
    }

    /**
     * 递归求二叉树的高度
     * 
     * @return 二叉树高度
     */
    public int height2() {
        return height(root);
    }

    /**
     * 获取二叉树节点的高度（递归）
     * 
     * @param node
     * @return 节点的高度
     */
    private int height(Node<E> node) {
        if (node == null)
            return 0;
        return 1 + Math.max(height(node.left), height(node.right));
    }

    /**
     * 前驱节点
     * 
     * @param node
     * @return node的前驱节点
     */
    protected Node<E> predecessor(Node<E> node) {
        if (node == null)
            return null;

        // 前驱节点在左子树当中(left.right.right.right....)
        Node<E> p = node.left;
        if (p != null) {
            while (p.right != null) {
                p = p.right;
            }
            return p;
        }

        // 从父节点、祖父节点中寻找前驱节点
        while (node.parent != null && node == node.parent.left) {
            node = node.parent;
        }

        return node.parent;
    }

    /**
     * 后继节点
     * 
     * @param node
     * @return node的后继节点
     */
    protected Node<E> successor(Node<E> node) {
        if (node == null)
            return null;

        // 前驱节点在左子树当中(right.left.left.left....)
        Node<E> p = node.right;
        if (p != null) {
            while (p.left != null) {
                p = p.left;
            }
            return p;
        }

        // 从父节点、祖父节点中寻找前驱节点
        while (node.parent != null && node == node.parent.right) {
            node = node.parent;
        }

        return node.parent;
    }

    @Override
    public Object root() {
        return root;
    }

    @Override
    public Object left(Object node) {
        return ((Node<E>) node).left;
    }

    @Override
    public Object right(Object node) {
        return ((Node<E>) node).right;
    }

    @Override
    public Object string(Object node) {
        Node<E> myNode = (Node<E>) node;

        // 让每一个节点打印出其父节点
        String parentString = "null";
        if (myNode.parent != null) {
            parentString = myNode.parent.element.toString();
        }
        return myNode.element + "_P(" + parentString + ")";
    }
}