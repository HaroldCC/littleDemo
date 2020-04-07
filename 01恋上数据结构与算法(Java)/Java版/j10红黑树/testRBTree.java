/*************************************************************************
> File Name       : testBST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月10日  11时46分49秒
************************************************************************/

package j10红黑树;

import j10红黑树.tree.RedBlackTree;
import j10红黑树.printer.BinaryTrees;

/**
 * testBST
 */
public class testRBTree {
    static void test1() {
        Integer data[] = new Integer[] { //
                55, 87, 56, 74, 96, 22, 62, 20, 70, 68, 90, 50 };

        RedBlackTree<Integer> rbTree = new RedBlackTree<>();
        for (int i = 0; i < data.length; i++) {
            rbTree.add(data[i]);
            System.out.println("【" + data[i] + "】");
            BinaryTrees.println(rbTree);
            System.out.println("----------------------------------");
        }

        BinaryTrees.println(rbTree);

    }

    static void test2() {
        Integer data[] = new Integer[] { //
                55, 87, 56, 74, 96, 22, 62, 20, 70, 68, 90, 50 };

        RedBlackTree<Integer> rbTree = new RedBlackTree<>();
        for (int i = 0; i < data.length; i++) {
            rbTree.add(data[i]);
        }

        BinaryTrees.println(rbTree);

        for (int i = 0; i < data.length; i++) {
            rbTree.remove(data[i]);
            System.out.println("【" + data[i] + "】");
            BinaryTrees.println(rbTree);
            System.out.println("----------------------------------");
        }

    }

    public static void main(String[] args) {
        test1();
        test2();
    }
}