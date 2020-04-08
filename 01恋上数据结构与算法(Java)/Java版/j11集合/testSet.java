/*************************************************************************
> File Name       : testSet.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月08日  10时40分58秒
************************************************************************/

package j11集合;

import j11集合.set.ListSet;
import j11集合.set.Set;
import j11集合.set.rbTreeSet;
import j11集合.set.Set.Visitor;

public class testSet {
    public static void test1() {
        Set<Integer> listSet = new ListSet<>();
        listSet.add(10);
        listSet.add(11);
        listSet.add(11);
        listSet.add(12);
        listSet.add(10);

        listSet.traversal(new Visitor<Integer>() {

            @Override
            public boolean visit(Integer element) {
                System.out.println(element + " ");
                return false;
            }
        });
    }

    public static void test2() {
        Set<Integer> treeSet = new rbTreeSet<>();
        treeSet.add(12);
        treeSet.add(10);
        treeSet.add(11);
        treeSet.add(10);
        treeSet.add(11);

        treeSet.traversal(new Visitor<Integer>() {

            @Override
            public boolean visit(Integer element) {
                System.out.println(element + " ");
                return false;
            }
        });
    }

    public static void main(String[] args) {
        test2();
    }
}