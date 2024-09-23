#include <iostream>
#include "ovector.h"

int main(const int argc, const char* const argv[])
{
	
	ostl::vector<int> v;
	v.push_back(5);
	v.push_front(4);
	v.push_front(3);
	v.push_front(2);
	v.push_front(1);

	std::cout << v << std::endl;

	return 0;
}