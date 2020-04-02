/*************************************************************************
> File Name       : stack.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月03日  10时24分22秒
************************************************************************/
package j06栈;

import j01动态数组.DynamicArray;

// * 栈方法：int size()  
// *        boolean isEmpty() 
// *        void push(E element) // 入栈
// *        E pop()             // 出栈
// *        E top()             // 获取栈顶元素

/**
 * stack:栈
 */
public class Stack<E> {
    // 栈比较类似于数组，所以这里将动态数组声明为私有
    private DynamicArray<E> list = new DynamicArray<>();

    int size() {
        return list.size();
    }

    boolean isEmpty() {
        return list.isEmpty();
    }

    public void push(E element) {
        list.add(element);
    }

    public E pop() {
        return list.remove(list.size() - 1);
    }

    public E top() {
        return list.get(list.size() - 1);
    }

    public void clear() {
        list.clear();
    }
}