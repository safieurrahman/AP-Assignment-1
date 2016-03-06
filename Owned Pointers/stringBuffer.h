#pragma once
class StringBuffer {

public:

	StringBuffer();  

	~StringBuffer();          

	StringBuffer(StringBuffer&);   

	StringBuffer(char**, int);  

	char charAt(int) const;  

	int length() const;             

	void reserve(int);                 

	void append(char);                        

private:

	char* _strbuf;                               

	int _length;                                     

	int capacity;

};