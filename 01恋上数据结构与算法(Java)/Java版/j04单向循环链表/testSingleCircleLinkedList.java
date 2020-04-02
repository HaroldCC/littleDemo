/*************************************************************************
> File Name       : testSingleCircleLinkedList.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月01日  13时00分08秒
************************************************************************/

package j04单向循环链表;

/**
 * testSingleCircleLinkedList
 */
public class testSingleCircleLinkedList {

    public static void main(String[] args) {
        singleCircleLinkedList<Integer> list = new singleCircleLinkedList<>();

        list.add(11);
        list.add(22);
        list.add(33);
        list.add(44);
        list.add(55);
        list.add(66);

        System.out.println(list);

        list.add(0, 55);
        list.add(4, 44);

        System.out.println(list);

        // list.remove(66);

        list.remove(4);
        System.out.println(list);
    }
}