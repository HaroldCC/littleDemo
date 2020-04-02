/*************************************************************************
> File Name       : testCircleQueue.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月07日  09时39分34秒
************************************************************************/

package j07队列;

/**
 * testCircleQueue
 */
public class testCircleQueue {

    public static void main(String[] args) {
        CircleQueue<Integer> qu = new CircleQueue<>();

        for (int i = 0; i < 10; i++) {
            qu.enQUeue(i);
        }

        for (int i = 0; i < 5; i++) {
            qu.deQueue();
        }

        for (int i = 15; i < 23; i++) {
            qu.enQUeue(i);
        }

        System.out.println(qu);

        while (!qu.isEmpty()) {
            System.out.println(qu.deQueue());
        }
    }
}