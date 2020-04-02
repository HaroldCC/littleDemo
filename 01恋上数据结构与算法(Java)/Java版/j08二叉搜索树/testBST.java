/*************************************************************************
> File Name       : testBST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月10日  11时46分49秒
************************************************************************/

package j08二叉搜索树;

import j08二叉搜索树.printer.BinaryTrees;
import j08二叉搜索树.BinarySearchTree.Visitor;;

/**
 * testBST
 */
public class testBST {
    static void test1() {
        Integer data[] = new Integer[] { 7, 4, 9, 2, 5, 8, 11, 3, 12, 1 };

        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        for (int i = 0; i < data.length; i++) {
            bst.add(data[i]);
        }

        BinaryTrees.println(bst);

        bst.preorder(new Visitor<Integer>() {
            public boolean visit(Integer element) {
                System.out.print(element + " ");
                return element == 2 ? true : false;
            }
        });
        System.out.println();

        bst.inorder(new Visitor<Integer>() {
            public boolean visit(Integer element) {
                System.out.print(element + " ");
                return element == 4 ? true : false;
            }
        });
        System.out.println();

        bst.postorder(new Visitor<Integer>() {
            public boolean visit(Integer element) {
                System.out.print(element + " ");
                return element == 4 ? true : false;
            }
        });
        System.out.println();

        bst.levelOrder(new Visitor<Integer>() {
            public boolean visit(Integer element) {
                System.out.print(element + " ");
                return element == 9 ? true : false;
            }
        });
        System.out.println();

        System.out.println(bst);

        System.out.println(bst.height());
        System.out.println(bst.height2());

    }

    static void test2() {
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        for (int i = 0; i < 10; i++) {
            bst.add((int) (Math.random() * 100));
        }

        BinaryTrees.println(bst);

        System.out.println(bst.isComplete());
    }

    public static void main(String[] args) {
        // test2();

        Integer data[] = new Integer[] { 91, 71, 61, 74, 18, 83, 45, 19, 40 };
        BinarySearchTree<Integer> bst = new BinarySearchTree<>();
        for (int i = 0; i < data.length; i++) {
            bst.add(data[i]);
        }

        BinaryTrees.println(bst);
        System.out.println(bst.isComplete());

        bst.remove(61);
        BinaryTrees.println(bst);
    }
}