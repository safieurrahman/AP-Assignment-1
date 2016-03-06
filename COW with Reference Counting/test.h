#include <iostream>

using namespace std;

void CopyTest()
{
	StringBuffer *a = new StringBuffer();
	a->reserve(2);

	cout << "Creating a String Buffer a \n\n";

	a->append('S');

	cout << "Copying String Buffer a to String Buffer b using Copy Constructor\n\n";

	StringBuffer *b = new StringBuffer(*a);
	cout << "Checking if both have same reference count i.e: ";
	cout << (a->refcount() == b->refcount()) << endl << endl;

	if (a->refcount() == a->refcount())
		cout << "Test Passed!\n\n";
	else
		cout << "Test Failed!\n\n";
}

void RefCountDecreaseTest()
{
	StringBuffer *a = new StringBuffer();
	a->reserve(2);

	cout << endl << endl << "Creating a String Buffer a\n\n";
	a->append('1');

	cout << "Copying String Buffer a to String Buffer b using copy constructor";

	StringBuffer * b = new StringBuffer(*a);
	cout << endl << endl << "Checking reference count: ";
	cout << b->refcount() << endl;
 
	cout << endl << "Deleting a and checking reference count: ";
	delete a;

	a = nullptr;
	cout << b->refcount() << endl;

	if (b->refcount() == 1)
		cout << "\nTest Passed!\n\n";
	else
		cout << "\nTest Failed!\n\n";
}
