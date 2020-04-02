/*************************************************************************
> File Name       : 约瑟夫问题.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月01日  14时13分24秒
************************************************************************/
package j05双向循环链表;

/**
 * 约瑟夫问题
 */
public class 约瑟夫问题 {

    public static void main(String[] args) {
        doublyCircleLinkedList<Integer> list = new doublyCircleLinkedList<>();

        for (int i = 1; i <= 8; i++) {
            list.add(i);
        }

        System.out.println(list);

        // 指向头节点
        list.reset();

        while (!list.isEmpty()) {
            list.next();
            list.next();
            System.out.println(list.remove());
        }
    }
}