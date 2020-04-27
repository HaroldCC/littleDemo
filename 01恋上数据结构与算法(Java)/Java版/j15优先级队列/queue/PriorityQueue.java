/*************************************************************************
> File Name       : PriorityQueue.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月27日  09时28分20秒
************************************************************************/

package j15优先级队列.queue;

import java.util.Comparator;

import j15优先级队列.heap.BinaryHeap;

/**
 * 优先级队列：使用二叉堆进行实现
 * 
 * @param <E>
 */
public class PriorityQueue<E> {
    private BinaryHeap<E> heap;

    public PriorityQueue(Comparator<E> comparator) {
        heap = new BinaryHeap<>(comparator);
    }

    public PriorityQueue() {
        this(null);
    }

    public int size() {
        return heap.size();
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }

    public void clear() {
        heap.clear();
    }

    /**
     * 入队
     * 
     * @param element
     */
    public void enQueue(E element) {
        heap.add(element);
    }

    /**
     * 出队
     * 
     * @return 出队元素
     */
    public E deQueue() {
        return heap.remove();
    }

    /**
     * 获取尾部元素
     * 
     * @return 尾部元素
     */
    public E front() {
        return heap.get();
    }
}