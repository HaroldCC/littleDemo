/*************************************************************************
> File Name       : testPriorityQueue.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月27日  09时28分34秒
************************************************************************/

package j15优先级队列;

import j15优先级队列.queue.PriorityQueue;

public class testPriorityQueue {
    public static void main(String[] args) {
        PriorityQueue<Person> queue = new PriorityQueue<>();
        queue.enQueue(new Person("Jack", 2));
        queue.enQueue(new Person("Rose", 10));
        queue.enQueue(new Person("Jack", 5));
        queue.enQueue(new Person("James", 15));

        while (!queue.isEmpty()) {
            System.out.println(queue.deQueue());
        }
    }
}