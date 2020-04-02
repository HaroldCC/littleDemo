/*************************************************************************
> File Name       : CircleQueue.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  15时02分16秒
************************************************************************/

package j07队列;

/**
 * CircleQueue:循环队列
 */
public class CircleQueue<E> {
    private int front; // 队头索引
    private int size;
    private E[] elements;

    private static final int DEFAULT_CAPACITY = 10;

    @SuppressWarnings("unchecked")
    private void ensureCapacity(int capacity) {
        int oldCapacity = elements.length;
        if (oldCapacity >= capacity)
            return;

        int newCapacity = oldCapacity + (oldCapacity >> 1);
        E[] newElements = (E[]) new Object[newCapacity];
        for (int i = 0; i < size; i++) {
            // 取模运算获取元素在数组中的真实索引
            newElements[i] = elements[index(i)];
        }
        elements = newElements;
        front = 0; // 重置front
    }

    private int index(int index) {
        return (front + index) % elements.length;

        // // 当取模的两个数不是2倍关系时，可用以下公式提高效率
        // index += front;
        // return index - (index >= elements.length ? elements.length : 0);
    }

    @SuppressWarnings("unchecked")
    public CircleQueue() {
        elements = (E[]) new Object[DEFAULT_CAPACITY];
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public void enQUeue(E element) {
        ensureCapacity(size + 1);
        elements[index(size)] = element;
        size++;
    }

    public E deQueue() {
        E frontElement = elements[front];
        elements[front] = null;
        front = index(1);
        size--;
        return frontElement;
    }

    public E front() {
        return elements[front];
    }

    public void clear() {

        for (int i = 0; i < size; i++) {
            elements[index(i)] = null;
        }
        size = 0;
        front = 0;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("capacity = ").append(elements.length).append(" size = ").append(size).append(" front = ")
                .append(front).append(", [");
        for (int i = 0; i < elements.length; i++) {
            if (i != 0)
                string.append(", ");

            string.append(elements[i]);
        }
        string.append("]");
        return string.toString();
    }
}
