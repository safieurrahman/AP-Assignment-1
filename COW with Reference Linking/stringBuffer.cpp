#include "stringBuffer.h"

StringBuffer::StringBuffer()
{
	this->capacity = 0;
	this->_length = 0;
	this->_strbuf = nullptr;
	this->neighbours = new vector<StringBuffer*>();
	this->neighbours->push_back(this);
}

StringBuffer::~StringBuffer()
{
	if(this->_strbuf != nullptr)
	{
		if (neighbours->size() != 1)
		{
			for (std::vector<StringBuffer*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					neighbours = nullptr;
					break;
				}
			}

		}
		else
		{
			neighbours->clear();
			delete[] this->_strbuf;
			this->_strbuf = nullptr;
		}
	}
}

StringBuffer::StringBuffer(const StringBuffer & buff)
{
	this->capacity = buff.capacity;
	this->_length = buff.length();
	this->_strbuf = buff._strbuf;
	this->neighbours = buff.neighbours;
	this->neighbours->push_back(this);
}

StringBuffer::StringBuffer(char * str, int len)
{
	this->capacity = len;
	this->_length = len;
	this->_strbuf = new char[len];

	for (int i = 0; i < len; i++) 
	{
		this->_strbuf[i] = str[i];
	}

	this->neighbours = new vector<StringBuffer*>();
	this->neighbours->push_back(this);
}

char StringBuffer::charAt(int index) const
{
	if (index < this->_length)
		return this->_strbuf[index];
	return (char)0;
}

int StringBuffer::length() const
{
	return this->_length;
}

void StringBuffer::reserve(int size)
{
	this->capacity = size;

	if (this->_strbuf == nullptr)
	{
		this->_strbuf = new char[size];
		if (neighbours->size() != 1)
		{
			for (std::vector<StringBuffer*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					break;
				}
			}

			neighbours = new vector<StringBuffer*>();

		}
	}
	else
	{
		char * str = this->_strbuf;
		this->_strbuf = new char[size];

		for (int i = 0; i < this->_length; i++)
		{
			this->_strbuf[i] = str[i];
		}

		if (neighbours->size() != 1)
		{
			for (std::vector<StringBuffer*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					break;
				}
			}

			neighbours = new vector<StringBuffer*>();

		}
		else
			delete[] str;
	}
}

void StringBuffer::append(char to_append)
{	
	if (this->capacity > this->_length)
	{
		if (neighbours->size() != 1)
		{
			for (std::vector<StringBuffer*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
			{
				if ((*it) == this) {
					neighbours->erase(it);
					break;
				}
			}

			neighbours = new vector<StringBuffer*>();

			char * str = this->_strbuf;
			this->_strbuf = new char[this->capacity];

			for (int i = 0; i < this->_length; i++)
			{
				this->_strbuf[i] = str[i];
			}

			str = nullptr;
		}
		this->_strbuf[(this->_length)++] = to_append;
	}
	else
	{
		if (this->_length == 0)
		{
			this->_strbuf = new char[2];
			this->capacity = 2;
			this->_strbuf[(this->_length)++] = to_append;
		}
		else
		{
			char * str = this->_strbuf;
			if (neighbours->size() != 1)
			{
				for (std::vector<StringBuffer*>::iterator it = neighbours->begin(); it != neighbours->end(); ++it)
				{
					if ((*it) == this) {
						neighbours->erase(it);
						break;
					}
				}

				neighbours = new vector<StringBuffer*>();

				this->capacity = 2 * this->_length;
				this->_strbuf = new char[this->capacity];

				for (int i = 0; i < this->_length; i++)
				{
					this->_strbuf[i] = str[i];
				}

				str = nullptr;
			}
			else
				delete[] str;

			this->_strbuf[(this->_length)++] = to_append;
		}
	}
}
