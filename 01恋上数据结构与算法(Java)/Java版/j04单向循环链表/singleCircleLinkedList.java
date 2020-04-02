/*************************************************************************
> File Name       : singleLinkedList.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月01日  12时48分30秒
************************************************************************/

package j04单向循环链表;

/**
 * singleLinkedList
 */
public class singleCircleLinkedList<E> {
    /**
     * 属性
     */
    private int size; // 大小
    private Node<E> first;// 第一个节点

    private static final int ELEMENT_NOT_FOUND = -1;

    /**
     * 将每一个节点封装成一个类， 每个节点包含一个元素,和指向下一个节点的指针
     * 
     * @param <E>
     */
    private static class Node<E> {
        E element;
        Node<E> nextNode;

        public Node(final E element, final Node<E> nextNode) {
            this.element = element;
            this.nextNode = nextNode;
        }
    }

    /**
     * 数组越界异常
     * 
     * @param index
     */
    private void outOfBound(final int index) {
        throw new IndexOutOfBoundsException("Index: " + index + ", Size: " + size);
    }

    /**
     * 范围检查
     * 
     * @param index
     */
    private void rangeCheck(final int index) {
        if (index < 0 || index >= size)
            outOfBound(index);
    }

    /**
     * add() 方法的范围检查
     * 
     * @param index
     */
    private void rangeCheckForAdd(final int index) {
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
    public boolean contains(final E element) {
        return indexOf(element) != ELEMENT_NOT_FOUND;
    }

    /**
     * 添加元素
     * 
     * @param element
     */
    public void add(final E element) {
        add(size, element);
    }

    /**
     * 获取index处对应的节点对象
     * 
     * @param index
     * @return
     */
    private Node<E> node(final int index) {
        rangeCheck(index);

        Node<E> node = first;
        for (int i = 0; i < index; i++) {
            node = node.nextNode;
        }
        return node;
    }

    /**
     * 在指定索引处添加元素
     * 
     * @param index
     * @param element
     */
    public void add(final int index, final E element) {

        rangeCheckForAdd(index);

        // 添加元素可能为0
        if (index == 0) {
            Node<E> newfirst = new Node<E>(element, first);

            // 获取最后一个节点
            Node<E> last = (size == 0) ? newfirst : node(size - 1);
            last.nextNode = first;
            first = newfirst;
        } else {
            // 添加元素时，需要先获取上一个元素节点
            final Node<E> prevNode = node(index - 1);

            // 然后将新节点的next指向未添加前index处的值
            // 再将原index处的前一个元素的next指向添加的元素
            prevNode.nextNode = new Node<E>(element, prevNode.nextNode);
        }

        size++;
    }

    /**
     * 返回index位置对应的元素
     * 
     * @param index
     * @return
     */
    public E get(final int index) {
        return node(index).element;
    }

    /**
     * 设置index处的元素
     * 
     * @param index
     * @param element
     * @return 原来的元素
     */
    public E set(final int index, final E element) {
        final Node<E> node = node(index);
        final E oldElement = node.element;
        node.element = element;
        return oldElement;
    }

    /**
     * 删除index处的值
     * 
     * @param index
     * @return 删除的值
     */
    public E remove(final int index) {
        rangeCheck(index);

        Node<E> delNode = first;
        // 删除第0个元素
        if (index == 0) {
            if (size == 1) {
                first = null;
            } else {
                Node<E> last = node(size - 1);
                first = first.nextNode;
                last.nextNode = first;
            }
        } else {
            final Node<E> prevNode = node(index - 1);// 先获取前一个结点
            delNode = prevNode.nextNode;
            prevNode.nextNode = prevNode.nextNode.nextNode;// 让前一个结点指向运来节点的后一个节点
        }
        size--;
        return delNode.element;
    }

    /**
     * 删除指定的元素
     * 
     * @param element
     */
    public void remove(final E element) {
        remove(indexOf(element));

    }

    /**
     * 查看元素的索引值
     * 
     * @param element
     * @return 索引值
     */
    public int indexOf(final E element) {
        if (element == null) {
            Node<E> node = first;
            for (int i = 0; i < size; i++) {
                if (node.element == null)
                    return i;

                node = node.nextNode;
            }
        } else {
            Node<E> node = first;
            for (int i = 0; i < size; i++) {
                if (element.equals(node.element))
                    return i;

                node = node.nextNode;
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
    }

    @Override
    public String toString() {
        final StringBuilder string = new StringBuilder();
        string.append("size= ").append(size).append(", [");

        Node<E> node = first;

        for (int i = 0; i < size; i++) {
            if (i != 0)
                string.append(", ");
            string.append(node.element);

            node = node.nextNode;
        }
        string.append("]");

        return string.toString();
    }
}