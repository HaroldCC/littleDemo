#include "singleLinkedList.h"

int main()
{
    LinkedList<char> list;

    list.add('h');
    list.add('h');
    list.add('h');
    list.add('h');
    list.add('h');
    list.add(1, 'a');

    list.printArray();

    return 0;
}