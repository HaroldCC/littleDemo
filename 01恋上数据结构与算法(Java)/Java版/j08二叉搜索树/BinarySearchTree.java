/*************************************************************************
> File Name       : BinarySearchTree.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月09日  17时40分39秒
************************************************************************/
package j08二叉搜索树;

import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

import j08二叉搜索树.printer.BinaryTreeInfo;

/**
 * BinarySearchTree：二叉搜索树
 */
@SuppressWarnings("unchecked")
public class BinarySearchTree<E> implements BinaryTreeInfo {
    private int size;
    private Node<E> root;// 根节点

    private Comparator<E> comparator; // 比较器

    private static class Node<E> {
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
        if (visitor == null)
            return;
        preorder(root, visitor);
    }

    private void preorder(Node<E> node, Visitor<E> visitor) {
        if (node == null || visitor.stop)
            return;

        // 这里可以删掉
        // if (visitor.stop)
        // return;

        visitor.stop = visitor.visit(node.element);
        preorder(node.left, visitor);
        preorder(node.right, visitor);
    }

    /**
     * 二叉树中序遍历：使用访问器
     * 
     * @param visitor
     */
    public void inorder(Visitor<E> visitor) {
        if (visitor == null)
            return;

        inorder(root, visitor);
    }

    private void inorder(Node<E> node, Visitor<E> visitor) {
        if (node == null || visitor.stop)
            return;

        inorder(node.left, visitor);

        if (visitor.stop)
            return;
        visitor.stop = visitor.visit(node.element);
        inorder(node.right, visitor);
    }

    /**
     * 二叉树后序遍历：使用访问器
     * 
     * @param visitor
     */
    public void postorder(Visitor<E> visitor) {
        if (visitor == null)
            return;

        postorder(root, visitor);
    }

    private void postorder(Node<E> node, Visitor<E> visitor) {
        if (node == null || visitor.stop) // 这里的visitor.stop是停止下面的递归
            return;

        postorder(node.left, visitor);
        postorder(node.right, visitor);

        if (visitor.stop) // 这里的visitor.stop是停止调用visitor.visit()方法
            return;
        visitor.stop = visitor.visit(node.element);
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
     * 无参构造
     * 
     */
    public BinarySearchTree() {
        this(null);
    }

    /**
     * 构造函数：需要比较器
     * 
     * @param comparator
     */
    public BinarySearchTree(Comparator<E> comparator) {
        this.comparator = comparator;
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

    /**
     * 前驱节点
     * 
     * @param node
     * @return node的前驱节点
     */
    @SuppressWarnings("unused")
    private Node<E> predecessor(Node<E> node) {
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
    private Node<E> successor(Node<E> node) {
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

    public void add(E element) {
        elementNotNullCheck(element);

        if (root == null) {
            // 添加的第一个节点
            root = new Node<>(element, null);
            size++;
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
        Node<E> newNode = new Node<>(element, parent);
        if (cmp > 0) {
            parent.right = newNode;
        } else {
            parent.left = newNode;
        }
        size++;
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
        } else if (node.parent == null) {// node是叶子节点，并且是根节点
            root = null;
        } else {// node是叶子节点，但不是根节点
            if (node == node.parent.left) {
                node.parent.left = null;
            } else {
                node.parent.right = null;
            }
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

    // /**
    // * 前序遍历
    // */
    // public void preorderTraversal() {
    // preorderTraversal(root);
    // }

    // /**
    // * 前序遍历：递归实现
    // *
    // * @param node
    // */
    // private void preorderTraversal(Node<E> node) {
    // if (node == null)
    // return;

    // System.out.println(node.element);
    // preorderTraversal(node.left);
    // preorderTraversal(node.right);
    // }

    // /**
    // * 中序遍历
    // */
    // public void inorderTraversal() {
    // inorderTraversal(root);
    // }

    // /**
    // * 中序遍历：递归实现
    // *
    // * @param node
    // */
    // private void inorderTraversal(Node<E> node) {
    // if (node == null)
    // return;

    // inorderTraversal(node.left);
    // System.out.println(node.element);
    // inorderTraversal(node.right);
    // }

    // /**
    // * 后序遍历
    // */
    // public void postorderTraversal() {
    // postorderTraversal(root);
    // }

    // /**
    // * 后序遍历：递归实现
    // *
    // * @param node
    // */
    // private void postorderTraversal(Node<E> node) {
    // if (node == null)
    // return;

    // postorderTraversal(node.left);
    // postorderTraversal(node.right);
    // System.out.println(node.element);
    // }

    // /**
    // * 层序遍历
    // */
    // public void levelOrderTraversal() {
    // if (root == null)
    // return;

    // // 使用队列
    // Queue<Node<E>> queue = new LinkedList<>();
    // queue.offer(root); // 根节点入队

    // while (!queue.isEmpty()) {
    // Node<E> node = queue.poll();// 头节点出队

    // System.out.println(node.element); // 访问出队的二叉树节点

    // // 节点的左子节点不为空，左子节点入队
    // if (node.left != null) {
    // queue.offer(node.left);
    // }

    // // 节点的右子节点不为空，右子节点入队
    // if (node.right != null) {
    // queue.offer(node.right);
    // }
    // }
    // }

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

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        toString(root, sb, "");

        return sb.toString();
    }

    private void toString(Node<E> node, StringBuilder sb, String prefix) {
        if (node == null)
            return;

        // 中序遍历输出二叉树节点
        toString(node.left, sb, prefix + "L---");
        sb.append(prefix).append(node.element).append("\n");
        toString(node.right, sb, prefix + "R---");
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