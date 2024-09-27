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

	class String
	{
	public:

		String();

		String(const char* str);

		String(String&& other);

		~String();

		String(const String& other);

		String& operator = (const String& other);

		String operator + (const String& other);

		char& at(int index) const;

		unsigned int length() const;

		bool operator == (const String& other) const;

		bool operator != (const String& other) const;

		char& operator [] (int index) const;

		friend std::istream& operator >> (std::istream& os, ostl::String& stref);

	private:
		char* str;
		unsigned int len;
	};

	std::ostream& operator << (std::ostream& os, ostl::String& stref);
	int strlen(const ostl::String& str);
	char* c_str(const ostl::String& str);

}