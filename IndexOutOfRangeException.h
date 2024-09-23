#pragma once
#include <exception>

namespace ostl
{
	class IndexOutOfRangeException : public std::exception
	{
	public:
		IndexOutOfRangeException(char* ex) : std::exception(ex) {};
	};
}
