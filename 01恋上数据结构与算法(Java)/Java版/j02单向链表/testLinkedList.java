package j02单向链表;

/**
 * testLinkedList
 */
public class testLinkedList {

    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(20);
        list.add(0, 10);
        list.add(30);
        list.add(list.size(), 40);

        System.out.println(list);
        list.remove(1);
        System.out.println(list);
    }
}