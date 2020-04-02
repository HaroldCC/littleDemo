#include "DoublyLinkedList.h"

int main() 
{
    LinkedList<int> list;
    list.add(20);
    //list.add(0, 10);
    list.add(30);
    //list.add(list.Size(), 40);

    list.printArray();

    //list.removeByIndex(1);

//    list.printArray();

    return 0;
}