/*************************************************************************
> File Name       : testMap.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月08日  14时19分23秒
************************************************************************/

package j12映射;

import j12映射.map.rbTreeMap;
import j12映射.map.Map.Visitor;

public class testMap {

    static void test1() {
        rbTreeMap<String, Integer> map = new rbTreeMap<>();
        map.put("c", 2);
        map.put("a", 5);
        map.put("b", 6);
        map.put("a", 8);

        map.traversal(new Visitor<String, Integer>() {
            @Override
            public boolean visit(String key, Integer value) {
                System.out.println(key + "_" + value);
                return false;
            }
        });
    }

    public static void main(String[] args) {
        test1();
    }

}