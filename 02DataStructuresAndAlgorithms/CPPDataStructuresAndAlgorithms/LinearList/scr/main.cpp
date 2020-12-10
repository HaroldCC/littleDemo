#include "testArrayList.hpp"
#include "testArrayQueue.hpp"
#include "testArrayStack.hpp"
#include "testDoublyCircularLinkedLIst.hpp"
#include "testDoublyLinkedList.hpp"
#include "testLinkedStack.hpp"
#include "testSingleCircularLinkedList.hpp"
#include "testSingleLinkedList.hpp"
#include "testVectorList.hpp"
//

int main(int argc, char* argv[])
{
	cout << "*******************************************testArrayList************************" << endl;
	testArrayList();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testArrayQueue************************" << endl;
	testArrayQueue();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testArrayStack************************" << endl;
	testArrayStack();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testDoublyCircularLinkedList************************" <<
		endl;
	testDoublyCircularLinkedList();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testDoublyLinkedList************************" << endl;
	testDoublyLinkedList();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testLinkedStack************************" << endl;
	testLinkedStack();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testSingleCircularLinkedList************************" <<
		endl;
	testSingleCircularLinkedList();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testSingleLinkedList************************" << endl;
	testSingleLinkedList();
	cout << "********************************************************************************" << endl;

	cout << "*******************************************testVectorList************************" << endl;
	testVectorList();
	cout << "********************************************************************************" << endl;

	return 0;
}