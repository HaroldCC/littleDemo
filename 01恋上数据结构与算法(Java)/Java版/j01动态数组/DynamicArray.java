package j01动态数组;

/*************************************************************************
 * > File Name : DynamicArray.java > Author : Harold > Mail : 2106562095@qq.com
 * > Github : www.github.com/Haroldcc > Created Time : 2020年02月16日 16时11分06秒
 ************************************************************************/
@SuppressWarnings("unchecked")
/**
 * DynamicArray:模板动态数组
 */
public class DynamicArray<E> {
    private int size; // 数组元素数量
    private E[] elements;

    private static final int DEFAULT_CAPACITY = 10;
    private static final int ELEMENT_NOT_FOUND = -1;

    /**
     * 有参构造函数
     * 
     * @param capacity
     */
    public DynamicArray(int capacity) {
        capacity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
        elements = (E[]) new Object[capacity];
    }

    /**
     * 无参构造函数
     */
    public DynamicArray() {
        // 调用有参构造函数
        this(DEFAULT_CAPACITY);
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

    /**
     * 数组是否需要缩容
     */
    private void trimCapacity() {
        // 首先获取数组的总容量
        int oldcapacity = elements.length;
        int newCapacity = oldcapacity >> 1;

        // 判断当数组元素个数大于容量的一半或者小于默认容量，不需要缩容
        if (size >= newCapacity || oldcapacity <= DEFAULT_CAPACITY)
            return;

        // 处理剩余空间较多的情况
        E[] newElements = (E[]) new Object[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;

        System.out.println(oldcapacity + "缩容为" + newCapacity);
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
     * 在指定索引处添加元素
     * 
     * @param index
     * @param element
     */
    public void add(int index, E element) {
        rangeCheckForAdd(index);

        ensureCapacity(size + 1);

        for (int i = size; i > index; i--) {
            elements[i] = elements[i - 1];
        }
        elements[index] = element;
        size++;
    }

    /**
     * 返回index位置对应的元素
     * 
     * @param index
     * @return
     */
    public E get(int index) {
        rangeCheck(index);

        return elements[index];
    }

    /**
     * 设置index处的元素
     * 
     * @param index
     * @param element
     * @return 原来的元素
     */
    public E set(int index, E element) {
        rangeCheck(index);

        E oldElement = elements[index];
        elements[index] = element;

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

        E oldElement = elements[index];
        for (int i = index + 1; i < size; i++) {
            elements[i - 1] = elements[i];
        }
        size--;

        elements[size] = null;

        // 缩容
        trimCapacity();

        return oldElement;
    }

    /**
     * 删除指定的元素
     * 
     * @param element
     */
    public void remove(E element) {
        remove(indexOf(element));

    }

    /**
     * 查看元素的索引值
     * 
     * @param element
     * @return 索引值
     */
    public int indexOf(E element) {
        // 处理存储起来的空值:由于null调用方法报错
        // 所以需要重写
        if (element == null) {
            for (int i = 0; i < size; i++) {
                // 返回为空值的索引
                if (elements[i] == null)
                    return i;
            }
        } else {
            for (int i = 0; i < size; i++) {
                // 让element调用方法，确保element为null时无法调用方法
                if (element.equals(elements[i]))
                    return i;
            }
        }

        // for (int i = 0; i < size; i++) {

        // // 由于数组索引存储的是对象的地址，所以这样的比较只是比较地址是否相等
        // // if (elements[i] == element) {
        // // return i;
        // // }
        // if (elements[i].equals(element)) {
        // return i;
        // }
        // }

        return ELEMENT_NOT_FOUND;

    }

    /**
     * 清空所有元素
     */
    public void clear() {
        // 当使用泛型时，传入的是对象，在内存中对象数组存储的是对象的指针,
        // 当根据对象数组添加新对象时，原来的对象就不再需要，需要对其进行释放内存
        for (int i = 0; i < size; i++) {
            // 此时不需要释放数组的内存，只需要将数组中存储的对象内存的地址设置为null
            // 就会释放对象本身的内存而保留数组的内存，以免再次申请，循环利用
            elements[i] = null;
        }
        size = 0;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("size= ").append(size).append(", [");

        for (int i = 0; i < size; i++) {
            if (i != 0)
                string.append(", ");
            string.append(elements[i]);
        }
        string.append("]");

        return string.toString();
    }
}
