/*************************************************************************
> File Name       : testHeap.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月22日  09时17分05秒
************************************************************************/

package j14堆;

import j14堆.heap.BinaryHeap;
import j14堆.printer.BinaryTrees;

public class testHeap {
    public static void main(String[] args) {
        BinaryHeap<Integer> heap = new BinaryHeap<>();
        heap.add(68);
        heap.add(72);
        heap.add(43);
        heap.add(50);
        heap.add(38);
        heap.add(10);
        heap.add(90);
        heap.add(65);
        BinaryTrees.println(heap);
        // heap.remove();
        // BinaryTrees.println(heap);
        System.out.println(heap.replace(70));
        BinaryTrees.println(heap);
    }
}