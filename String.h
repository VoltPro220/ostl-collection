#pragma once

#ifndef _OUT_OF_RANGE_H_
#include"out_of_range.h"
#define _OUT_OF_RANGE_H_
#endif // !_OUT_OF_RANGE_H_

#include <ostream>
#include <istream>

extern "C" const int strlen_c(const char*);
namespace ostl
{

	class string
	{
	public:

		string();

		string(const char* str);

		string(string&& other);

		~string();

		string(const string& other);

		string& operator = (const string& other);

		string operator + (const string& other);

		char& at(int index) const;

		unsigned int length() const;

		bool operator == (const string& other) const;

		bool operator != (const string& other) const;

		char& operator [] (int index) const;

		friend std::istream& operator >> (std::istream& os, ostl::string& stref);

	private:
		char* str;
		unsigned int len;
	};

	std::ostream& operator << (std::ostream& os, ostl::string& stref);
	int strlen(const ostl::string& str);
	char* c_str(const ostl::string& str);

}