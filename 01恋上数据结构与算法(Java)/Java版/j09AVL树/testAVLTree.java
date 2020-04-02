/*************************************************************************
> File Name       : testBST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月10日  11时46分49秒
************************************************************************/

package j09AVL树;

import j08二叉搜索树.printer.BinaryTrees;
import j09AVL树.tree.AVLTree;
import j09AVL树.tree.BinaryTree.Visitor;

/**
 * testBST
 */
public class testAVLTree {
    static void test1() {
        Integer data[] = new Integer[] { 85, 19, 69, 3, 7, 99, 95 };

        AVLTree<Integer> avl = new AVLTree<>();
        for (int i = 0; i < data.length; i++) {
            avl.add(data[i]);
            // System.out.println("【" + data[i] + "】");
            BinaryTrees.println(avl);
            System.out.println("-------------------------------------------------");
        }

        avl.remove(99);
        avl.remove(85);
        avl.remove(95);
        BinaryTrees.println(avl);

    }

    static void test2() {
        Integer data[] = new Integer[] {
                // 7, 4
                // 7, 4, 9
                // 7, 4, 9, 5
                // 7, 4, 9, 2
                // 7, 4, 9, 2, 8
                7, 4, 9, 2, 1 };

        AVLTree<Integer> bst = new AVLTree<>();
        for (int i = 0; i < data.length; i++) {
            bst.add(data[i]);
        }

        BinaryTrees.println(bst);
        System.out.println("----------------------------------");
        System.out.println(bst.isComplete());

        bst.inorder(new Visitor<Integer>() {

            @Override
            public boolean visit(Integer element) {
                System.out.println(element + " ");
                return element == 4 ? true : false;
            }
        });
    }

    public static void main(String[] args) {
        // test2();
        test1();
    }
}