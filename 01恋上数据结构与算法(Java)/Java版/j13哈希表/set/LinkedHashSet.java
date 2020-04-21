/*************************************************************************
> File Name       : LinkedHashSet.java
> Author          : Harold
> Mail            : 2106562095@qq.com
> Github          : www.github.com/Haroldcc
> Created Time    : 2020年04月21日  16时33分11秒
************************************************************************/
package j13哈希表.set;

import j13哈希表.map.LinkedHashMap;
import j13哈希表.map.Map;

public class LinkedHashSet<E> implements Set<E> {
    private LinkedHashMap<E, Object> map = new LinkedHashMap<>();

    @Override
    public int size() {
        return map.size();
    }

    @Override
    public boolean isEmpty() {
        return map.isEmpty();
    }

    @Override
    public void clear() {
        map.clear();
    }

    @Override
    public boolean contains(E element) {
        return map.containsKey(element);
    }

    @Override
    public void add(E element) {
        map.put(element, null);
    }

    @Override
    public void remove(E element) {
        map.remove(element);
    }

    @Override
    public void traversal(Visitor<E> visitor) {
        map.traversal(new Map.Visitor<E, Object>() {
            @Override
            public boolean visit(E key, Object value) {
                return visitor.visit(key);
            }
        });
    }

}