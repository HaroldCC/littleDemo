/*************************************************************************
> File Name       : BBST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月06日  15时11分52秒
************************************************************************/

package j11集合.tree;

import java.util.Comparator;

public class BBST<E> extends BST<E> {

    public BBST() {
        this(null);
    }

    /**
     * 比较器：继承自父类
     * 
     * @param comparator
     */
    public BBST(Comparator<E> comparator) {
        super(comparator);
    }

    /**
     * 左旋
     * 
     * @param node
     */
    protected void rotateLeft(Node<E> grand) {
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
    protected void rotateRight(Node<E> grand) {
        Node<E> parent = grand.left;
        Node<E> child = parent.right;
        grand.left = child;
        parent.right = grand;

        afterRotate(grand, parent, child);
    }

    protected void afterRotate(Node<E> grand, Node<E> parent, Node<E> child) {
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
    }

    protected void rotate(Node<E> r, // 子树的根节点
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

        // e-f-g
        f.left = e;
        if (e != null)
            e.parent = f;
        f.right = g;
        if (g != null)
            g.parent = f;

        // b-d-f
        d.left = b;
        d.right = f;
        b.parent = d;
        f.parent = d;
    }

}