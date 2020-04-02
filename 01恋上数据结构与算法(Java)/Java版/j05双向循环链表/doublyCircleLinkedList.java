/*************************************************************************
> File Name       : doublyCircleLinkedList.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月01日  13时57分34秒
************************************************************************/

package j05双向循环链表;

/**
 * doublyCircleLinkedList
 */
public class doublyCircleLinkedList<E> {

    /**
     * 属性
     */
    private int size; // 大小
    private Node<E> first;// 第一个节点
    private Node<E> last; // 最后一个节点

    private Node<E> current;// 新增的一个自由指针（可以通过指针访问链表节点）

    private static final int ELEMENT_NOT_FOUND = -1;

    /**
     * 将每一个节点封装成一个类， 每个节点包含一个元素,和指向下一个节点的指针
     * 
     * @param <E>
     */
    private static class Node<E> {
        E element;
        Node<E> prev;
        Node<E> next;

        public Node(Node<E> prev, E element, Node<E> next) {
            this.prev = prev;
            this.element = element;
            this.next = next;
        }
    }

    /**
     * 数组越界异常
     * 
     * @param index
     */
    private void outOfBound(int index) {
        throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
    }

    /**
     * 范围检查
     * 
     * @param index
     */
    private void rangeCheck(int index) {
        if (index < 0 || index >= size)
            outOfBound(index);
    }

    /**
     * add() 方法的范围检查
     * 
     * @param index
     */
    private void rangeCheckForAdd(int index) {
        // 因为在添加元素时，可以在索引为size的位置添加，即数组尾端添加元素
        if (index < 0 || index > size)
            outOfBound(index);
    }

    /**
     * 数组元素个数
     * 
     * @return
     */
    public int size() {
        return size;
    }

    /**
     * 数组是否为空
     * 
     * @return
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * 是否包含某个元素
     * 
     * @param element
     * @return
     */
    public boolean contains(E element) {
        return indexOf(element) != ELEMENT_NOT_FOUND;
    }

    /**
     * 添加元素
     * 
     * @param element
     */
    public void add(E element) {
        add(size, element);
    }

    /**
     * 获取index处对应的节点对象
     * 
     * @param index
     * @return
     */
    private Node<E> node(int index) {
        rangeCheck(index);

        // 由元素中间分界，离那个近就从哪端遍历
        if (index < (size >> 1)) {
            Node<E> node = first;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node;
        } else {
            Node<E> node = last;
            for (int i = size - 1; i > index; i--) {
                node = node.prev;
            }
            return node;
        }

    }

    /**
     * 在指定索引处添加元素
     * 
     * @param index
     * @param element
     */
    public void add(int index, E element) {

        rangeCheckForAdd(index);

        if (index == size) { // 在最后面添加元素
            Node<E> oldLast = last;
            last = new Node<>(oldLast, element, first);
            if (oldLast == null) { // 添加的第一个元素
                first = last;
                first.next = first;
                first.prev = first;
            } else {
                oldLast.next = last;
                first.prev = last;
            }

        } else {
            // 新添加节点的下一个
            Node<E> nextNode = node(index);
            Node<E> prevNode = nextNode.prev;
            Node<E> addNode = new Node<>(prevNode, element, nextNode);
            nextNode.prev = addNode;
            prevNode.next = addNode;

            if (index == 0) { // index == 0
                first = addNode;
            }
        }

        size++;
    }

    /**
     * 返回index位置对应的元素
     * 
     * @param index
     * @return
     */
    public E get(int index) {
        return node(index).element;
    }

    /**
     * 设置index处的元素
     * 
     * @param index
     * @param element
     * @return 原来的元素
     */
    public E set(int index, E element) {
        Node<E> node = node(index);
        E oldElement = node.element;
        node.element = element;
        return oldElement;
    }

    /**
     * 删除index处的值
     * 
     * @param index
     * @return 删除的值
     */
    public E remove(int index) {
        rangeCheck(index);

        // Node<E> delNode = first;
        // if (size == 1) {
        // first = null;
        // last = null;
        // } else {
        // delNode = node(index);
        // Node<E> prevNode = delNode.prev;
        // Node<E> nextNode = delNode.next;
        // prevNode.next = nextNode;
        // nextNode.prev = prevNode;

        // if (index == 0) { // index == 0
        // first = nextNode;
        // }

        // if (delNode == last) { // index == size - 1
        // last = prevNode;
        // }
        // }

        // size--;
        // return delNode.element;

        return remove(node(index));
    }

    // /**
    // * 删除指定的元素
    // *
    // * @param element
    // */
    // public void remove(E element) {
    // remove(indexOf(element));

    // }

    private E remove(Node<E> node) {
        if (size == 1) {
            first = null;
            last = null;
        } else {
            Node<E> prevNode = node.prev;
            Node<E> nextNode = node.next;
            prevNode.next = nextNode;
            nextNode.prev = prevNode;

            if (node == first) { // index == 0
                first = nextNode;
            }

            if (node == last) { // index == size - 1
                last = prevNode;
            }
        }

        size--;
        return node.element;
    }

    /**
     * 查看元素的索引值
     * 
     * @param element
     * @return 索引值
     */
    public int indexOf(E element) {
        if (element == null) {
            Node<E> node = first;
            for (int i = 0; i < size; i++) {
                if (node.element == null)
                    return i;

                node = node.next;
            }
        } else {
            Node<E> node = first;
            for (int i = 0; i < size; i++) {
                if (element.equals(node.element))
                    return i;

                node = node.next;
            }
        }
        return ELEMENT_NOT_FOUND;
    }

    /**
     * 清空所有元素
     */
    public void clear() {
        size = 0;
        first = null;
        last = null;
    }

    public void reset() {
        current = first;
    }

    public E next() {
        if (current == null)
            return null;

        current = current.next;
        return current.element;

    }

    public E remove() {
        if (current == null)
            return null;

        Node<E> next = current.next;
        E element = remove(current);

        if (size == 0) {
            current = null;
        } else {
            current = next;
        }

        return element;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("size= ").append(size).append(", [");

        Node<E> node = first;

        for (int i = 0; i < size; i++) {
            if (i != 0)
                string.append(", ");
            string.append(node.element);

            node = node.next;
        }
        string.append("]");

        return string.toString();
    }
}