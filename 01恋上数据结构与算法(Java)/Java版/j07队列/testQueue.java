/*************************************************************************
> File Name       : testQueue.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月03日  20时00分41秒
************************************************************************/

package j07队列;

/**
 * testQueue
 */
public class testQueue {

    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<>();

        queue.enQueue(11);
        queue.enQueue(22);
        queue.enQueue(33);
        queue.enQueue(44);

        while (!queue.isEmpty()) {
            System.out.println(queue.deQueue());
        }
    }
}