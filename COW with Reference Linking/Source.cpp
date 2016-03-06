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

	cout << "Neighbour size of a is: ";
	cout << a->neighbours->size() << endl << endl;

	cout << "Neighbour size of b is: ";
	cout << b->neighbours->size() << endl << endl;

	//CopyTest();
	//RefCountDecreaseTest();

}