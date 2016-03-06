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
	cout << "Now, if we try to check the length of buffer a, it would return: ";

	cout << a->length() << "\n\n";

	if (a->length() == 0)
		cout << "Test Passed!\n\n";
	else
		cout << "Test Failed!\n\n";
}

void CharSToStringBufferTest()
{
	char * a = new char[5];
	a[0] = 'S';
	a[1] = 'a';
	a[2] = 'f';
	a[3] = 'i';
	a[4] = 'e';

	cout << "Creating char* a with value 'Safie'\n\n";
	cout << "Creating StringBuffer b and passing a to b as parameters in constructor\n\n";
	cout << "Copying String Buffer a to String Buffer b using Copy Constructor\n\n";

	StringBuffer *b = new StringBuffer(&a, 5);

	cout << "Checking if a == nullptr \n" ;

	if (a == nullptr)
		cout << "\nTest Passed!\n\n";
	else
		cout << "\nTest Failed!\n\n";

	delete b;

}
