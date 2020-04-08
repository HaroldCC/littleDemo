/*************************************************************************
> File Name       : rbTreeSet.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月08日  11时14分23秒
************************************************************************/

package j11集合.set;

import j11集合.tree.BinaryTree;
import j11集合.tree.RedBlackTree;
import java.util.Comparator;

/**
 * 使用红黑树实现集合
 * 
 * @param <E>
 */
public class rbTreeSet<E> implements Set<E> {
    private RedBlackTree<E> tree = new RedBlackTree<>();

    public rbTreeSet() {
        this(null);
    }

    /**
     * 红黑树实现的集合里面的元素必须具备可比较性
     * 
     * @param comparator
     */
    public rbTreeSet(Comparator<E> comparator) {
        tree = new RedBlackTree<>(comparator);
    }

    @Override
    public int size() {
        return tree.size();
    }

    @Override
    public boolean isEmpty() {
        return tree.isEmpty();
    }

    @Override
    public void clear() {
        tree.clear();
    }

    @Override
    public boolean contains(E element) {
        return tree.contains(element);
    }

    @Override
    public void add(E element) {
        tree.add(element);
    }

    @Override
    public void remove(E element) {
        tree.remove(element);
    }

    @Override
    public void traversal(Visitor<E> visitor) {
        tree.inorder(new BinaryTree.Visitor<E>() {
            @Override
            public boolean visit(E element) {
                return visitor.visit(element);
            }
        });
    }

}