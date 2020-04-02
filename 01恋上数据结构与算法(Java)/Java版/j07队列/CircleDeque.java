/*************************************************************************
> File Name       : CircleDeque.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月07日  10时20分53秒
************************************************************************/

package j07队列;

/**
 * CircleDeque:循环双端队列
 */
@SuppressWarnings("unchecked")
public class CircleDeque<E> {
    private int front;
    private int size;
    private E[] elements;

    private static final int DEFAULT_CAPACITY = 10;

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
        index += front;

        if (index < 0) {
            return index + elements.length;
        }
        return index % elements.length;

        // n%m等价于n-m(m > 0 ? 0 : m)的前提条件：n < 2m
        // 当取模的两个数不是2倍关系时，可用以下公式提高效率
        // index += front;
        // return index - (index >= elements.length ? elements.length : 0);
    }

    public CircleDeque() {
        elements = (E[]) new Object[DEFAULT_CAPACITY];
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * 队尾入队
     * 
     * @param element
     */
    public void enQueueRear(E element) {
        ensureCapacity(size + 1);

        elements[index(size)] = element;
        size++;
    }

    /**
     * 队头出队
     * 
     * @return 出队元素
     */
    public E deQueueFront() {
        E frontElement = elements[front];
        elements[front] = null;
        front = index(1);
        size--;
        return frontElement;
    }

    /**
     * 队头入队
     * 
     * @param element
     */
    public void enQueueFront(E element) {
        ensureCapacity(size + 1);

        front = index(-1);
        elements[front] = element;
        size++;
    }

    /**
     * 队尾出队
     * 
     * @return 出队元素
     */
    public E deQueueRear() {
        int rearIndex = index(size - 1);
        E rear = elements[rearIndex];
        elements[rearIndex] = null;
        size--;

        return rear;
    }

    /**
     * 获取队头元素
     * 
     * @return 队头元素
     */
    public E front() {
        return elements[front];
    }

    /**
     * 获取队尾元素
     * 
     * @return 队尾元素
     */
    public E rear() {
        return elements[index(size - 1)];
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