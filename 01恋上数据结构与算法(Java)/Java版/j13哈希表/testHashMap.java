package j13哈希表;

import j13哈希表.map.HashMap;
import j13哈希表.map.Map.Visitor;
import j13哈希表.model.Key;
import j13哈希表.model.Person;

public class testHashMap {
    static void test1() {
        Person p1 = new Person(10, 1.67f, "jack");
        Person p2 = new Person(10, 1.67f, "jack");

        HashMap<Object, Integer> map = new HashMap<>();

        for (int i = 1; i <= 19; i++) {
            map.put(new Key(i), i);
        }
        map.print();
        map.put(new Key(4), 100);
        Asserts.test(map.size() == 19);
        Asserts.test(map.get(new Key(4)) == 100);
        Asserts.test(map.get(new Key(18)) == 18);
        System.out.println(map.size());

        map.put(p1, 1);
        map.put(p2, 2);
        map.put("jack", 3);
        map.put("rose", 4);
        map.put("jack", 5);
        map.put(null, 6);

        System.out.println(map.size());
        map.print();

        System.out.println(map.size());
        System.out.println(map.remove("jack"));
        System.out.println(map.get("jack"));
        System.out.println(map.size());

        System.out.println(map.get("jack"));
        System.out.println(map.get("rose"));
        System.out.println(map.get(null));
        System.out.println(map.get(p1));

        map.traversal(new Visitor<Object, Integer>() {
            public boolean visit(Object key, Integer value) {
                System.out.println(key + "_" + value);
                return false;
            }
        });

        System.out.println(map.containsKey(p1));
        System.out.println(map.containsKey(null));
        System.out.println(map.containsValue(6));
        System.out.println(map.containsValue(1));
    }

    public static void main(String[] args) {
        Person p1 = new Person(10, 1.67f, "jack");
        Person p2 = new Person(10, 1.67f, "rose");

        p1.equals(p2);
    }
}