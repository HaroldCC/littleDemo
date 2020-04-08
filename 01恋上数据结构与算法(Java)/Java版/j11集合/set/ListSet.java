/*************************************************************************
> File Name       : ListSet.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月08日  10时41分56秒
************************************************************************/

package j11集合.set;

import j11集合.list.*;

/**
 * 利用链表实现集合
 * 
 * @param <E>
 */
public class ListSet<E> implements Set<E> {

    private List<E> list = new LinkedList<>();

    @Override
    public int size() {
        return list.size();
    }

    @Override
    public boolean isEmpty() {
        return list.isEmpty();
    }

    @Override
    public void clear() {
        list.clear();
    }

    @Override
    public boolean contains(E element) {
        return list.contains(element);
    }

    @Override
    public void add(E element) {
        /* 法一：遇到相同元素，直接返回 */
        if (list.contains(element))
            return;
        list.add(element);

        /* 法二：遇到相同元素进行覆盖 */
        // int index = list.indexOf(element);
        // if (index != List.ELEMENT_NOT_FOUND) {
        // list.set(index, element);
        // } else {
        // list.add(element);
        // }
    }

    @Override
    public void remove(E element) {
        int index = list.indexOf(element);
        if (index != List.ELEMENT_NOT_FOUND) {
            list.remove(index);
        }
    }

    @Override
    public void traversal(Visitor<E> visitor) {
        if (visitor == null)
            return;
        int size = list.size();
        for (int i = 0; i < size; i++) {
            if (visitor.visit(list.get(i)))
                return;
        }
    }

}