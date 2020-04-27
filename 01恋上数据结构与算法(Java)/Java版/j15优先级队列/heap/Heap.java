/*************************************************************************
> File Name       : Heap.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月22日  09时17分58秒
************************************************************************/

package j15优先级队列.heap;

public interface Heap<E> {
    int size(); // 元素的数量

    boolean isEmpty(); // 是否为空

    void clear(); // 清空

    void add(E element); // 添加元素

    E get(); // 获得堆顶元素

    E remove(); // 删除堆顶元素

    E replace(E element); // 删除堆顶元素的同时插入一个新元素
}