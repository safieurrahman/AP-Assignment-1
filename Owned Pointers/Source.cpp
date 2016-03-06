#include "test.h"
#include <iostream>

using namespace std;

int main()
{
	StringBuffer *a = new StringBuffer();
	a->reserve(2);

	cout << "Creating a String Buffer a \n\n";

	a->append('S');

	cout << "Copying String Buffer a to String Buffer b using Copy Constructor\n\n";

	StringBuffer *b = new StringBuffer(*a);

	cout << "Length of a is: ";
	cout << a->length() << endl << endl;
	cout << "Length of b is: ";
	cout << b->length() << endl << endl;

	cout << "That clearly shows resources are owned by b now!" << endl << endl;

	//CopyTest();
	//CharSToStringBufferTest();

	return 0;
}