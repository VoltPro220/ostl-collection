#pragma once

#ifndef _EXCEPTION_H_
#include <exception>
#define _EXCEPTION_H_
#endif // !_OUT_OF_RANGE_H_

namespace ostl
{
	class out_of_range : public std::exception
	{
	public:
		out_of_range(char* ex) : std::exception(ex) {};
	};
}
