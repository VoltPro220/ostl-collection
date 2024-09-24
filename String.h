#pragma once

#include "IndexOutOfRangeException.h"
#include <ostream>

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

	private:
		char* str;
		unsigned int len;
	};

	std::ostream& operator << (std::ostream& os, ostl::String& stref);
	int strlen(const ostl::String& str);
	char* c_str(const ostl::String& str);

}