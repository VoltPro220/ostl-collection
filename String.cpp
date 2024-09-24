#include "String.h"

ostl::String::String()
{
	this->str = nullptr;
	this->len = 0;
}

ostl::String::String(const char* str)
{
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	for(unsigned int i = 0; i < len; i++)
		this->str[i] = str[i];
	this->str[len] = '\0';
}

ostl::String::String(ostl::String&& other)
{
	this->len = other.len;
	this->str = other.str;
	other.str = nullptr;
}

ostl::String::~String()
{
	delete[] this->str;
}

ostl::String::String(const ostl::String& other)
{
	this->len = strlen(other.str);
	this->str = new char[this->len + 1];

	for(int i = 0; i < len; i++)
		this->str[i] = other.str[i];

	this->str[len] = '\0';
}

ostl::String& ostl::String::operator=(const ostl::String& other)
{

	if(this->str != nullptr)
		delete[] str;


	this->len = strlen(other.str);
	this->str = new char[this->len + 1];

	for(int i = 0; i < this->len; i++)
		this->str[i] = other.str[i];


	this->str[len] = '\0';

	return *this;

}

ostl::String ostl::String::operator+(const ostl::String& other)
{

	ostl::String newStr;

	newStr.len = strlen(this->str) + strlen(other.str);

	newStr = new char[strlen(this->str) + strlen(other.str) + 1];

	int i = 0;
	for(; i < strlen(this->str); i++)
		newStr.str[i] = this->str[i];

	for(int j = 0; j < strlen(other.str); j++, i++)
		newStr.str[i] = other.str[j];


	newStr[strlen(this->str) + strlen(other.str)] = '\0';

	return newStr;
}

char& ostl::String::at(int index) const
{
	if(this->len >= index || len < 0)
		throw ostl::IndexOutOfRangeException((char*)"Exception: Index out of range");
	return this->str[index];
}

unsigned int ostl::String::length() const
{
	return this->len;
}

bool ostl::String::operator==(const ostl::String& other) const
{
	if(this->len != other.len)
		return false;
	for(int i = 0; i < this->len; i++)
		if(this->str[i] != other.str[i])
			return false;
	return true;
}

bool ostl::String::operator!=(const ostl::String& other) const
{
	return !(this->operator==(other));
}

char& ostl::String::operator[](int index) const
{
	return this->str[index];
}

std::ostream& ostl::operator<<(std::ostream& os, ostl::String& stref)
{
	for(size_t i = 0; i < stref.length(); i++)
	{
		os << stref[i];
	}
	return os;
}

int ostl::strlen(const char* str)
{
	int count = 0;

	for(; str[count] != '\0' ; count++);

	return count;
}

int ostl::strlen(const ostl::String& str)
{
	int count = 0;

	for(; str[count] != '\0'; count++);

	return count;
}

char* ostl::c_str(const ostl::String& str)
{
	char* c = new char[str.length()];
	for(int i = 0; i < str.length() ; i++) 
		c[i] = str.at(i);
	return c;
}
