/*************************************************************************
> File Name       : Person.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月27日  09时36分28秒
************************************************************************/

package j15优先级队列;

public class Person implements Comparable<Person> {
    private String name;
    private int boneBreak;

    public Person(String name, int boneBreak) {
        this.name = name;
        this.boneBreak = boneBreak;
    }

    @Override
    public int compareTo(Person person) {
        return this.boneBreak - person.boneBreak;
    }

    @Override
    public String toString() {
        return "Person [name = " + name + ", boneBreak = " + boneBreak + "]";
    }
}