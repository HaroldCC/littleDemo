/*************************************************************************
> File Name       : testBST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月10日  11时46分49秒
************************************************************************/

package j08二叉搜索树.二叉搜索树重构;

import j08二叉搜索树.printer.BinaryTrees;
import j08二叉搜索树.二叉搜索树重构.BinaryTree.Visitor;

/**
 * testBST
 */
public class testBST {
    static void test1() {
        Integer data[] = new Integer[] { 7, 4, 9, 2, 5, 8, 11, 3, 12, 1 };

        BST<Integer> bst = new BST<>();
        for (int i = 0; i < data.length; i++) {
            bst.add(data[i]);
        }

        BinaryTrees.println(bst);

        bst.remove(7);

        BinaryTrees.println(bst);
    }

    static void test2() {
        Integer data[] = new Integer[] {
                // 7, 4
                // 7, 4, 9
                // 7, 4, 9, 5
                // 7, 4, 9, 2
                // 7, 4, 9, 2, 8
                7, 4, 9, 2, 1 };

        BST<Integer> bst = new BST<>();
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
        test2();
        test1();
    }
}