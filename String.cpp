
#ifndef _STRING_H_
#include "String.h"
#define _STRING_H_
#endif // !_STRING_H_



ostl::string::string()
{
	this->str = nullptr;
	this->len = 0;
}

ostl::string::string(const char* str)
{
	this->len = strlen_c(str);
	this->str = new char[this->len + 1];
	for(unsigned int i = 0; i < len; i++)
		this->str[i] = str[i];
	this->str[len] = '\0';
}

ostl::string::string(ostl::string&& other)
{
	this->len = other.len;
	this->str = other.str;
	other.str = nullptr;
}

ostl::string::~string()
{
	delete[] this->str;
}

ostl::string::string(const ostl::string& other)
{
	this->len = strlen_c(other.str);
	this->str = new char[this->len + 1];

	for(int i = 0; i < len; i++)
		this->str[i] = other.str[i];

	this->str[len] = '\0';
}

ostl::string& ostl::string::operator=(const ostl::string& other)
{

	if(this->str != nullptr)
		delete[] str;


	this->len = strlen_c(other.str);
	this->str = new char[this->len + 1];

	for(int i = 0; i < this->len; i++)
		this->str[i] = other.str[i];


	this->str[len] = '\0';

	return *this;

}

ostl::string ostl::string::operator+(const ostl::string& other)
{

	ostl::string newStr;

	newStr.len = strlen_c(this->str) + strlen_c(other.str);

	newStr = new char[strlen_c(this->str) + strlen_c(other.str) + 1];

	int i = 0;
	for(; i < strlen_c(this->str); i++)
		newStr.str[i] = this->str[i];

	for(int j = 0; j < strlen_c(other.str); j++, i++)
		newStr.str[i] = other.str[j];


	newStr[strlen_c(this->str) + strlen_c(other.str)] = '\0';
	newStr[strlen_c(this->str) + strlen_c(other.str)] = '\0';

	return newStr;
}

char& ostl::string::at(int index) const
{
	if(this->len >= index || len < 0)
		throw ostl::out_of_range((char*)"Exception: Index out of range");
	return this->str[index];
}

unsigned int ostl::string::length() const
{
	return this->len;
}

bool ostl::string::operator==(const ostl::string& other) const
{
	if(this->len != other.len)
		return false;
	for(int i = 0; i < this->len; i++)
		if(this->str[i] != other.str[i])
			return false;
	return true;
}

bool ostl::string::operator!=(const ostl::string& other) const
{
	return !(this->operator==(other));
}

char& ostl::string::operator[](int index) const
{
	return this->str[index];
}

std::ostream& ostl::operator<<(std::ostream& os, ostl::string& stref)
{
	for(size_t i = 0; i < stref.length(); i++)
	{
		os << stref[i];
	}
	return os;
}

std::istream& ostl::operator>>(std::istream& is, ostl::string& stref)
{
	// прочитать строку из входного потока
	is >> stref.str;
	return is;
}

int ostl::strlen(const ostl::string& str)
{
	int count = 0;

	for(; str[count] != '\0'; count++);

	return count;
}

char* ostl::c_str(const ostl::string& str)
{
	char* c = new char[str.length()];
	for(int i = 0; i < str.length() ; i++) 
		c[i] = str.at(i);
	return c;
}
