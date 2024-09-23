#include <iostream>
#include "ovector.h"

int main(const int argc, const char* const argv[])
{

	ostl::vector<int> v;
	v.push_front(4);
	v.push_back(5);
	v.push_front(3);
	v.pop_front();
	v.push_front(2);
	v.push_front(1);
	v.insert(3, 2);
	v.erase(0);
	v.erase(0);
	v.erase(0);

	int var;
	ostl::size_t index = 0;
	while(v.check(index++, var))
	{
		std::cout << var << std::endl;
	}

	return 0;
}