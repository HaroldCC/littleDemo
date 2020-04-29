/*************************************************************************
> File Name       : testBST.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年03月10日  11时46分49秒
************************************************************************/

package j17二叉树的非递归遍历;

import j17二叉树的非递归遍历.printer.BinaryTrees;
import j17二叉树的非递归遍历.tree.BST;
import j17二叉树的非递归遍历.tree.BinaryTree.Visitor;

/**
 * testBST
 */
public class testBST {
    public static void main(String[] args) {
        // 创建BST
        Integer data[] = new Integer[] { 7, 4, 9, 2, 5, 8, 11 };
        BST<Integer> bst = new BST<>();
        for (int i = 0; i < data.length; i++) {
            bst.add(data[i]);
        }
        // 树状打印
        BinaryTrees.println(bst);
        // 遍历器
        StringBuilder sb = new StringBuilder();
        Visitor<Integer> visitor = new Visitor<Integer>() {
            @Override
            public boolean visit(Integer element) {
                sb.append(element).append(" ");
                return false;
            }
        };
        // 遍历
        sb.delete(0, sb.length());
        bst.preorder(visitor);
        Asserts.test(sb.toString().equals("7 4 2 5 9 8 11 "));

        sb.delete(0, sb.length());
        bst.inorder(visitor);
        Asserts.test(sb.toString().equals("2 4 5 7 8 9 11 "));

        sb.delete(0, sb.length());
        bst.postorder(visitor);
        Asserts.test(sb.toString().equals("2 5 4 8 11 9 7 "));
    }
}