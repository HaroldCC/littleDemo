/*************************************************************************
> File Name       : testCircleDeque.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月07日  10时45分16秒
************************************************************************/

package j07队列;

/**
 * testCircleDeque
 */
public class testCircleDeque {

    public static void main(String[] args) {
        CircleDeque<Integer> qu = new CircleDeque<>();
        for (int i = 0; i < 10; i++) {
            qu.enQueueFront(i + 1);
            qu.enQueueRear(i + 100);
        }
        System.out.println(qu);

        for (int i = 0; i < 3; i++) {
            qu.deQueueFront();
            qu.deQueueRear();
        }

        qu.enQueueFront(11);
        qu.enQueueFront(12);
        System.out.println(qu);
        while (!qu.isEmpty()) {
            System.out.println(qu.deQueueFront());

        }
    }
}