/*************************************************************************
> File Name       : testDeque.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月05日  14时53分52秒
************************************************************************/
package j07队列;

/**
 * testDeque
 */
public class testDeque {

    public static void main(String[] args) {
        Deque<Integer> de = new Deque<>();

        de.enQueueFront(11);
        de.enQueueFront(22);
        de.enQueueRear(33);
        de.enQueueRear(44);

        while (!de.isEmpty()) {
            System.out.println(de.deQueueFront());
        }
    }
}