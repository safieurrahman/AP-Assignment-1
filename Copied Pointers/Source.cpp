#include "stringBuffer.h"
#include <iostream>

using namespace std;

int main()
{
	StringBuffer *a = new StringBuffer();
	a->reserve(2);

	cout << "Creating a String Buffer a \n\n";
	cout << "Appending 'S' in a\n\n";

	a->append('S');

	cout << "Copying String Buffer a to String Buffer b using Copy Constructor\n\n";
	StringBuffer *b = new StringBuffer(*a);

	cout << "Character at 0 in buffer A: ";
	cout << a->charAt(0);
	cout << "\n\nCharacter at 0 in buffer B: ";
	cout << b->charAt(0) <<endl <<endl;

	//ShallowCopyTest();
	//CharToStringBufferTest();

	return 0;
}