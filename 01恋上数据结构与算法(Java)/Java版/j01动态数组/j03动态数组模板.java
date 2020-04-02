package j01动态数组;

/*************************************************************************
> File Name       : j03动态数组模板.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年02月16日  16时09分15秒
************************************************************************/
/**
 * j03动态数组模板
 */
public class j03动态数组模板 {
    public static void main(String[] args) {

        // java泛型只能使用对象类型
        DynamicArray<testDynamicArrayClass> persons = new DynamicArray<>();
        System.out.println(persons);
        persons.add(new testDynamicArrayClass(10, "张三"));
        persons.add(new testDynamicArrayClass(15, "李四"));
        persons.add(new testDynamicArrayClass(14, "王五"));
        persons.add(new testDynamicArrayClass(17, "赵六"));
        persons.add(new testDynamicArrayClass(19, "王麻子"));

        System.out.println(persons);

        persons.add(1, new testDynamicArrayClass(10, "张三"));
        persons.add(5, new testDynamicArrayClass(15, "李四"));
        persons.add(new testDynamicArrayClass(14, "王五"));
        persons.add(new testDynamicArrayClass(17, "赵六"));
        persons.add(new testDynamicArrayClass(19, "王麻子"));

        System.out.println(persons);

        persons.add(4, new testDynamicArrayClass(10, "张三"));
        persons.add(new testDynamicArrayClass(15, "李四"));
        persons.add(new testDynamicArrayClass(14, "王五"));
        persons.add(new testDynamicArrayClass(17, "赵六"));
        persons.add(new testDynamicArrayClass(19, "王麻子"));

        persons.add(new testDynamicArrayClass(10, "张三"));
        persons.add(new testDynamicArrayClass(15, "李四"));
        persons.add(new testDynamicArrayClass(14, "王五"));
        persons.add(new testDynamicArrayClass(17, "赵六"));
        persons.add(new testDynamicArrayClass(19, "王麻子"));

        persons.add(new testDynamicArrayClass(10, "张三"));
        persons.add(new testDynamicArrayClass(15, "李四"));
        persons.add(new testDynamicArrayClass(14, "王五"));
        persons.add(new testDynamicArrayClass(17, "赵六"));
        persons.add(new testDynamicArrayClass(19, "王麻子"));

        for (int i = 0; i < 10; i++) {
            persons.remove(0);
        }

        DynamicArray<Integer> int_array = new DynamicArray<>();
        for (int i = 0; i < 10; i++) {
            int_array.add(i);
        }

        System.out.println(int_array);

        // 由于JVM垃圾回收机制，需要提醒垃圾回收
        System.gc();
    }
}