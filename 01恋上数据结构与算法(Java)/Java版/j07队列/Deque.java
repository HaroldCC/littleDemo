/*************************************************************************
> File Name       : Deque.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  14时44分03秒
************************************************************************/

package j07队列;

import j03双向链表.LinkedList;

/**
 * Deque:双端队列
 */
public class Deque<E> {

    private LinkedList<E> list = new LinkedList<>();

    public int size() {
        return list.size();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    /**
     * 队尾入队
     * 
     * @param element
     */
    public void enQueueRear(E element) {
        list.add(element);
    }

    /**
     * 队尾出队
     * 
     * @return
     */
    public E deQueueRear() {
        return list.remove(0);
    }

    /**
     * 队头入队
     * 
     * @param element
     */
    public void enQueueFront(E element) {
        list.add(0, element);
    }

    /**
     * 队头出队
     * 
     * @return
     */
    public E deQueueFront() {
        return list.remove(list.size() - 1);
    }

    public E front() {
        return list.get(0);
    }

    public E rear() {
        return list.get(list.size() - 1);
    }

}