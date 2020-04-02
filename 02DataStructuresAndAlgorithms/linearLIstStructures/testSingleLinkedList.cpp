#include "linearList.h"
#include "singleLinkedList.h"
#include <iostream>

using namespace std;

int main()
{

    // test constructor
    linearList<double> *x = new singleLinkedList<double>;
    singleLinkedList<int> y, z;

    // test size
    cout << "Initial size of x, y, and z = "
         << x->size() << ", "
         << y.size() << ", "
         << z.size() << endl;

    // test isEmpty
    if (x->isEmpty())
        cout << "x is isEmpty" << endl;
    else
        cout << "x is not isEmpty" << endl;
    if (y.isEmpty())
        cout << "y is isEmpty" << endl;
    else
        cout << "y is not isEmpty" << endl;

    // test add
    y.add(0, 2);
    y.add(1, 6);
    y.add(0, 1);
    y.add(2, 4);
    y.add(3, 5);
    y.add(2, 3);
    cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
    cout << "Size of y = " << y.size() << endl;
    if (y.isEmpty())
        cout << "y is isEmpty" << endl;
    else
        cout << "y is not isEmpty" << endl;
    y.output(cout);
    cout << endl
         << "Testing overloaded <<" << endl;
    cout << y << endl;

    // test indexOf
    int index = y.indexOf(4);
    if (index < 0)
        cout << "4 not found" << endl;
    else
        cout << "The index of 4 is " << index << endl;

    index = y.indexOf(7);
    if (index < 0)
        cout << "7 not found" << endl;
    else
        cout << "The index of 7 is " << index << endl;

    // test getElement
    cout << "Element with index 0 is " << y.getElement(0) << endl;
    cout << "Element with index 3 is " << y.getElement(3) << endl;

    // test removeByIndex
    y.removeByIndex(1);
    cout << "Element 1 erased" << endl;
    cout << "The list is " << y << endl;
    y.removeByIndex(2);
    cout << "Element 2 erased" << endl;
    cout << "The list is " << y << endl;
    y.removeByIndex(0);
    cout << "Element 0 erased" << endl;
    cout << "The list is " << y << endl;

    cout << "Size of y = " << y.size() << endl;
    if (y.isEmpty())
        cout << "y is isEmpty" << endl;
    else
        cout << "y is not isEmpty" << endl;

    try
    {
        y.add(-3, 0);
    }
    catch (illegalIndex e)
    {
        cout << "Illegal index exception" << endl;
        cout << "Insert index must be between 0 and list size" << endl;
        e.outputMessage();
    }

    // test copy constructor
    singleLinkedList<int> w(y);
    y.removeByIndex(0);
    y.removeByIndex(0);
    cout << "w should be old y, new y has first 2 elements removed" << endl;
    cout << "w is " << w << endl;
    cout << "y is " << y << endl;

    // a few more inserts, just for fun
    y.add(0, 4);
    y.add(0, 5);
    y.add(0, 6);
    y.add(0, 7);
    cout << "y is " << y << endl;

    y.clear();

    return 0;
}