#include "stringBuffer.h"
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
	cout << "Checking if both have same neighbouring list: ";
	cout << (a->neighbours == b->neighbours) << endl << endl;

	if (a->neighbours == b->neighbours)
		cout << "Test Passed!\n\n";
	else
		cout << "Test Failed!\n\n";

}

void RefCountDecreaseTest()
{
	StringBuffer *a = new StringBuffer();
	a->reserve(2);

	cout << "Creating a String Buffer a \n\n";

	a->append('S');

	cout << "Copying String Buffer a to String Buffer b using Copy Constructor\n\n";

	StringBuffer *b = new StringBuffer(*a);
	cout << "Checking list size: ";
	cout << b->neighbours->size() << endl;

	cout << endl << "Deleting a and checking list size: ";
	delete a;

	a = nullptr;
	cout << b->neighbours->size() << endl << endl;

	if (b->neighbours->size() == 1)
		cout << "Test Passed!\n\n";
	else
		cout << "Test Failed!\n\n";
}
