#include <iostream>
#include "ovector.h"

int main(const int argc, const char* const argv[])
{
	srand(time(NULL));


	ostl::vector<int> v;
	v.push_front(5);
	v.push_back(6);
	v.push_front(4);
	v.push_front(2);
	v.push_front(1);
	v.insert(3, 2);

	v.reverse(10);

	std::cout << v << std::endl;

	return 0;
}