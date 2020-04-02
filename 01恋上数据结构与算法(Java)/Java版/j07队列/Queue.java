/*************************************************************************
> File Name       : Queue.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月03日  19时51分45秒
************************************************************************/

package j07队列;

import j03双向链表.LinkedList;

/**
 * Queue:队列
 */
public class Queue<E> {

    // 由于队列操纵数据是在首位，所以使用双向链表比较方便·
    private LinkedList<E> list = new LinkedList<>();

    public int size() {
        return list.size();
    }

    public boolean isEmpty() {
        return list.isEmpty();
    }

    /**
     * 入队
     * 
     * @param element
     */
    public void enQueue(E element) {
        list.add(element);
    }

    /**
     * 出队
     * 
     * @return 出队元素
     */
    public E deQueue() {
        return list.remove(0);
    }

    /**
     * 获取尾部元素
     * 
     * @return 尾部元素
     */
    public E front() {
        return list.get(0);
    }
}