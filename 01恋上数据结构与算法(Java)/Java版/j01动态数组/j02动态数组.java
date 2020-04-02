package j01动态数组;

/*************************************************************************
> File Name       : j02动态数组.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月15日  14时07分29秒
************************************************************************/
//package Java版;

/**
 * 02动态数组: int size(); //元素数量 bool isEmpty(); // 是否为空 boolean contains(E
 * element): // 是否包含某个元素 void add(E element); // 添加元素到最后面 E get(int index);
 * //返回index位置对应的元素 E set(int index, E element); // 设置index位置的元素 void add(int
 * index, E element); // 在index位置添加元素 E remove(int index); // 删除index位置对应的元素 int
 * indexOf(E element); // 查看元素的位置 void clear(); // 清除所有元素
 */
public class j02动态数组 {

    public static void main(String[] args) {
        Arraylist mylist = new Arraylist();
        System.out.println("添加前：" + mylist);
        for (int i = 0; i < 10; i++) {
            mylist.add(i);
        }
        System.out.println("添加后：" + mylist);

        mylist.add(3, 4);
        System.out.println("在第3个位置添加4 " + mylist);

        boolean nine = mylist.contains(9);
        System.out.println("数组中是否含有数字9：" + nine);
        int nineIndex = mylist.get(9);
        System.out.println("索引为9的值为：" + nineIndex);

        boolean ten = mylist.contains(10);
        System.out.println("数组中是否含有数字10：" + ten);

        System.out.println("将索引为1的值设置为11：");
        System.out.println("设置前：" + mylist);
        int ret = mylist.set(1, 11);
        System.out.println("设置后：" + mylist);
        System.out.println("原来的元素是：" + ret);

        System.out.println("删除第五个位置的元素：");
        int remNum = mylist.remove(5);
        System.out.println("删除的值为：" + remNum);

        int sixElement = mylist.indexOf(6);
        System.out.println("查看元素6的索引为：" + sixElement);

        mylist.clear();
        System.out.println("清除元素：" + mylist);

    }
}