#include "stringBuffer.h"
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

	cout << "Reference count of a is : ";
	cout << a->refcount() << endl << endl;

	cout << "Reference count of b is : ";
	cout << b->refcount() << endl << endl;

	//CopyTest();
	//RefCountDecreaseTest();
}