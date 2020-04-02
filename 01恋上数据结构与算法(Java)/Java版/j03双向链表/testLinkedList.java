/*************************************************************************
> File Name       : testLinkedList.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月24日  10时51分41秒
************************************************************************/
package j03双向链表;

/**
 * testLinkedList
 */
public class testLinkedList {

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();

        list.add(11);
        list.add(0, 10);
        list.add(22);
        list.add(33);
        list.add(44);

        System.out.println(list);

        list.add(0, 55);
        list.add(list.size(), 66);

        System.out.println(list);

        list.remove(0);

        System.out.println(list);

        list.set(2, 50);
        System.out.println(list);
    }
}