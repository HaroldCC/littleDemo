package j01动态数组;

/************************************************************************
> File Name       : Arraylist.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月15日  14时15分15秒
************************************************************************/
//package Java版;

/**
 * Arraylist: 动态数组声明文件
 */
public class Arraylist {

    /**
     * 元素
     */
    private int size;
    private int[] elements;

    // 静态常量，用来构造默认数组的容量
    private static final int DEFAULT_CAPACITY = 10;

    /**
     * 构造函数
     */
    public Arraylist() {
        // size = 0;
        // elements = new int[size];
        this(DEFAULT_CAPACITY);
    }

    public Arraylist(int capacity) {
        // 进行判断，当传入的值小于10时，将默认大小置为10
        capacity = (capacity < DEFAULT_CAPACITY) ? DEFAULT_CAPACITY : capacity;
        elements = new int[capacity];
    }

    /**
     * 数组索引越界检查
     */
    private void outOfBound(int index) {
        // 抛出数组范围越界异常
        throw new IndexOutOfBoundsException("Index:" + index + ", Size:" + size);
    }

    private void rangeCheck(int index) {
        // 一般数组索引的值不能大于数组的size
        if (index < 0 || index >= size) {
            outOfBound(index);
        }
    }

    private void rangeCheckForAdd(int index) {
        // 但是向数组中添加值时，索引值可以等于数组size，意味着向数组尾部添加值
        if (index < 0 || index > size) {
            outOfBound(index);
        }
    }

    /**
     * 保证要有capacity的容量
     */
    private void ensureCapacity(int capacity) {
        int oldCapacity = elements.length; // 旧容量是数组的长度
        if (oldCapacity >= capacity)
            return; // 当旧容量比较大时，就不需要进行扩容操作

        // 将容量加一，但是扩容较少，会频繁操作
        // int newCapacity = oldCapacity + 1;

        // 将容量乘以1.5，因为直接乘以1.5会进行浮点数计算，耗费时间，移位操作比较快
        // 位移操作：右移1是初以2，左移一是乘以2；
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        int[] newElements = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i]; // 将旧数组中的数据拷贝到新的数组中
        }
        elements = newElements; // 将旧数组指针指向新数组块

        System.out.println(oldCapacity + "扩容为" + newCapacity);
    }

    /**
     * 元素数目
     */
    public int size() {
        return size;
    }

    /**
     * 数组是否为空
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * 是否包含某元素
     */
    public boolean contains(int element) {
        return indexOf(element) != -1;
    }

    /**
     * 添加元素
     */
    public void add(int element) {
        // elements[size++] = element;
        add(size, element);
    }

    /**
     * 获取指定位置的元素
     */
    public int get(int index) {
        // if (index < 0 || index >= size) {
        // // 如果index不在数组索引范围内，抛异常
        // throw new IndexOutOfBoundsException("Index:" + index + ", Size:" + size);
        // }
        rangeCheck(index);

        return elements[index];
    }

    /**
     * 设置指定位置的元素值
     */
    public int set(int index, int element) {
        // if (index < 0 || index >= size) {
        // // 如果index不在数组索引范围内，抛异常
        // throw new IndexOutOfBoundsException("Index:" + index + ", Size:" + size);
        // }
        rangeCheck(index);

        int old = elements[index];
        elements[index] = element;
        return old; // 替换后返回原来的元素

    }

    /**
     * 在index处添加元素
     */
    public void add(int index, int element) {
        // if (index < 0 || index > size) {
        // // 如果index不在数组索引范围内，抛异常
        // throw new IndexOutOfBoundsException("Index:" + index + ", Size:" + size);
        // }
        rangeCheckForAdd(index);

        // 扩容
        ensureCapacity(size + 1);

        for (int i = size - 1; i >= index; i--) {
            elements[i + 1] = elements[i];
        }
        elements[index] = element;
        size++;
    }

    /**
     * 删除index处对应的元素
     */
    public int remove(int index) {
        // if (index < 0 || index >= size) {
        // // 如果index不在数组索引范围内，抛异常
        // throw new IndexOutOfBoundsException("Index:" + index + ", Size:" + size);
        // }
        rangeCheck(index);

        int old = elements[index];
        for (int i = index + 1; i < size - 1; i++) {
            elements[i - 1] = elements[i];
        }
        size--;
        return old;
    }

    /**
     * 查看元素的位置
     */
    public int indexOf(int element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element)
                return i;
        }
        return -1; // 未找到返回 -1
    }

    /**
     * 清空所有元素
     */
    public void clear() {
        size = 0;
    }

    /**
     * 显示数组中的结果
     */
    @Override
    public String toString() {
        // 样式:size=3,[99, 88, 77]
        StringBuilder string = new StringBuilder();
        string.append("size=").append(size).append(", [");
        for (int i = 0; i < size; i++) {

            // 最后一个数后面不显示逗号

            // // 方法一原理：当不是最后一个元素时，在其后拼接逗号
            // string.append(elements[i]);
            // if(i != size -1)
            // {
            // string.append(",");
            // }

            // 方法二原理：只要不是第0个元素，就在前面拼接逗号
            if (i != 0) {
                string.append(", ");
            }

            string.append(elements[i]);
        }
        string.append("]");
        return string.toString();
    }
}
