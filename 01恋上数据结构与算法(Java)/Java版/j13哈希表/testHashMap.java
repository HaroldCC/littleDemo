package j13哈希表;

import j13哈希表.map.HashMap;
import j13哈希表.map.Map;
import j13哈希表.map.Map.Visitor;

public class testHashMap {
    public static void main(String[] args) {
        Person p1 = new Person(10, 1.67f, "jack");
        Person p2 = new Person(10, 1.67f, "jack");

        Map<Object, Integer> map = new HashMap<>();

        map.put(p1, 1);
        map.put(p2, 2);
        map.put("jack", 3);
        map.put("rose", 4);
        map.put("jack", 5);
        map.put(null, 6);

        // System.out.println(map.size());
        // System.out.println(map.remove("jack"));
        // System.out.println(map.get("jack"));
        // System.out.println(map.size());

        // System.out.println(map.get("jack"));
        // System.out.println(map.get("rose"));
        // System.out.println(map.get(null));
        // System.out.println(map.get(p1));

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
}