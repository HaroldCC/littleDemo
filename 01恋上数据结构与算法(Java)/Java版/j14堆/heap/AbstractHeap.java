/*************************************************************************
> File Name       : AbstractHeap.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月23日  09时23分53秒
************************************************************************/

package j14堆.heap;

import java.util.Comparator;

/**
 * 堆抽象类
 * 
 * @param <E>
 */
@SuppressWarnings("unchecked")
public abstract class AbstractHeap<E> implements Heap<E> {
    protected int size;
    protected Comparator<E> comparator;

    public AbstractHeap(Comparator<E> comparator) {
        this.comparator = comparator;
    }

    public AbstractHeap() {
        this(null);
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    protected int compare(E e1, E e2) {
        return comparator != null ? comparator.compare(e1, e2)//
                : ((Comparable<E>) e1).compareTo(e2);
    }

}