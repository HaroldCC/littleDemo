package j01动态数组;

/**
 * testDynamicArrayClass: 测试模板动态数组类
 */
public class testDynamicArrayClass {
    private int age;
    private String name;

    public testDynamicArrayClass(int age, String name) {
        this.age = age;
        this.name = name;
    }

    /**
     * 输出结果
     */
    @Override
    public String toString() {
        return "Person [age = " + age + ", name = " + name + "]";
    }

    /**
     * 对象销毁提示 （相当于C++中的析构函数）
     */
    @Override
    protected void finalize() throws Throwable {
        System.out.println("Person对象销毁");
    }

    /**
     * 判断两个对象是否相等
     */
    @Override
    public boolean equals(Object obj) {
        testDynamicArrayClass person = (testDynamicArrayClass) obj;
        if (this.age == person.age && this.name == person.name) {
            return true;
        }
        return false;
    }

}