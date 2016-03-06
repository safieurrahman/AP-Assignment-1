class StringBuffer {

public:

	StringBuffer();  

	~StringBuffer();                

	StringBuffer(const StringBuffer&);             

	StringBuffer(char*, int);   

	char charAt(int) const;  

	int length() const;                           

	void reserve(int);                           

	void append(char);            

	int refcount();

private:

	int* _refcount;

	char* _strbuf;                                

	int _length;                                   

	int capacity;
};
