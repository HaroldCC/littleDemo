/*************************************************************************
> File Name       : BinaryHeap.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月22日  09时21分28秒
************************************************************************/

package j14堆.heap;

import java.util.Comparator;

import j14堆.printer.BinaryTreeInfo;

/**
 * 二叉堆（最大堆）
 * 
 * @param <E>
 */
@SuppressWarnings("unchecked")
public class BinaryHeap<E> extends AbstractHeap<E> implements BinaryTreeInfo {
    private E[] elements;
    private static final int DEFAULT_CAPACITY = 10;

    public BinaryHeap(E[] elements, Comparator<E> comparator) {
        super(comparator);

        if (elements == null || elements.length == 0) {
            this.elements = (E[]) new Object[DEFAULT_CAPACITY];
        } else {
            size = elements.length;
            int capacity = Math.max(elements.length, DEFAULT_CAPACITY);
            this.elements = (E[]) new Object[capacity];
            for (int i = 0; i < elements.length; i++) {
                this.elements[i] = elements[i];
            }
            heapify();
        }
    }

    public BinaryHeap(E[] elements) {
        this(elements, null);
    }

    public BinaryHeap(Comparator<E> comparator) {
        this(null, comparator);
    }

    public BinaryHeap() {
        this(null, null);
    }

    @Override
    public void clear() {
        for (int i = 0; i < size; i++) {
            elements[i] = null;
        }
        size = 0;
    }

    @Override
    public void add(E element) {
        elementNotNullCheck(element);
        ensureCapacity(size + 1);
        elements[size++] = element;
        siftUp(size - 1);
    }

    @Override
    public E get() {
        emptyCheck();
        return elements[0];
    }

    @Override
    public E remove() {
        emptyCheck();

        int lastIndex = --size;
        E topElement = elements[0];
        elements[0] = elements[lastIndex];
        elements[lastIndex] = null;

        siftDown(0);

        return topElement;
    }

    @Override
    public E replace(E element) {
        elementNotNullCheck(element);

        E root = null;
        if (size == 0) {
            elements[0] = element;
            size++;
        } else {
            root = elements[0];
            elements[0] = element;
            siftDown(0);
        }
        return root;
    }

    /**
     * 批量建堆
     */
    private void heapify() {
        // 自上而下的上滤:效率较低
        // for (int i = 1; i < size; i++) {
        // siftUp(i);
        // }

        // 自下而上的下滤
        for (int i = (size >> 1) - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    /**
     * 让index位置的元素下滤
     * 
     * @param index
     */
    private void siftDown(int index) {
        E element = elements[index];
        int half = size >> 1;
        // 第一个叶子节点的索引 == 非叶子节点的数量
        // index < 第一个叶子节点的索引
        // 必须保证index位置是非叶子节点
        while (index < half) {
            // index的节点有2种情况
            // 1、只有左子节点
            // 2、 同时有左右子节点

            // 默认为左子节点跟它进行比较
            int childIndex = (index << 1) + 1;
            E childElement = elements[childIndex];

            // 右子节点
            int rightIndex = childIndex + 1;

            // 选出左右子节点最大的那个
            if (rightIndex < size && compare(elements[rightIndex], childElement) > 0) {
                childElement = elements[childIndex = rightIndex];
            }

            if (compare(element, childElement) >= 0)
                break;

            // 将子节点存放到index位置
            elements[index] = childElement;
            // 重新设置index
            index = childIndex;
        }
        elements[index] = element;
    }

    /**
     * 让index位置的元素上滤
     * 
     * @param index
     */
    private void siftUp(int index) {
        // E element = elements[index];
        // while (index > 0) {
        // int parentIndex = (index - 1) >> 1; // 父节点的索引
        // E parentElement = elements[parentIndex];
        // if (compare(element, parentElement) <= 0)
        // return;

        // // 交换index、parentIndex位置的内容
        // E tmp = elements[index];
        // elements[index] = elements[parentIndex];
        // elements[parentIndex] = tmp;

        // // 重新赋值index
        // index = parentIndex;
        // }

        E element = elements[index];
        while (index > 0) {
            int parentIndex = (index - 1) >> 1; // 父节点的索引
            E parentElement = elements[parentIndex];
            if (compare(element, parentElement) <= 0)
                break;
            // 将父元素存储在index位置
            elements[index] = parentElement;

            // 重新赋值index
            index = parentIndex;
        }
        elements[index] = element;
    }

    /**
     * 确定数组中的容量大小，来确定是否进行扩容
     * 
     * @param capacity
     */
    private void ensureCapacity(int capacity) {
        // 将旧数组中的容量进行保存
        int oldCapacity = elements.length;
        if (capacity <= oldCapacity)
            return; // 当需要的容量小于等于原本容量时，就不需要扩容

        int newCapacity = oldCapacity + (oldCapacity >> 1);
        E[] newElements = (E[]) new Object[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;
        System.out.println(oldCapacity + "扩容为" + newCapacity + ",容量为" + elements.length);
    }

    private void emptyCheck() {
        if (size == 0) {
            throw new IndexOutOfBoundsException("Heap is empty");
        }
    }

    private void elementNotNullCheck(E element) {
        if (element == null) {
            throw new IllegalArgumentException("element must not be null");
        }
    }

    @Override
    public Object root() {
        return 0;
    }

    @Override
    public Object left(Object node) {
        int index = ((int) node << 1) + 1;
        return index >= size ? null : index;
    }

    @Override
    public Object right(Object node) {
        int index = ((int) node << 1) + 2;
        return index >= size ? null : index;
    }

    @Override
    public Object string(Object node) {
        return elements[(int) node];
    }
}