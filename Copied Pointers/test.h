#include "stringBuffer.h"
#include <iostream>

using namespace std;

void ShallowCopyTest() 
{
	StringBuffer *a = new StringBuffer();
	a->reserve(2);

	cout << "Creating a String Buffer a \n\n";

	a->append('S');

	cout << "Copying String Buffer a to String Buffer b using Copy Constructor\n\n";

	StringBuffer *b = new StringBuffer(*a);

	cout << "Deleting String Buffer b\n\n";
	cout << "Now, if we try to access the buffer a, it would return an exception or garbage value i.e. ";
	delete b;

	cout << a->charAt(0) << "\n\n";

	if (a->charAt(0) != '1')
		cout << "Test Passed!\n\n";
	else
		cout << "Test Failed!\n\n";
}

void CharToStringBufferTest()
{
	char * a = new char[5];
	a[0] = 'S';
	a[1] = 'a';
	a[2] = 'f';
	a[3] = 'i';
	a[4] = 'e';

	cout << "Creating char* a with value 'Safie'\n\n";
	cout << "Creating StringBuffer b and passing a to b as parameters in constructor\n\n";
	cout << "Copying String Buffer a to String Buffer b using copy constructor\n\n";

	StringBuffer *b = new StringBuffer(a, 5);

	cout << "Checking Character at [2]: ";
	cout << b->charAt(2) <<endl;

	if (b->charAt(2) == 'f')
		cout << "\nTest Passed!\n\n";
	else
		cout << "\nTest Failed!\n\n";

	delete b;
}
